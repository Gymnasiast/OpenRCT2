/*****************************************************************************
 * Copyright (c) 2014-2023 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "../Cheats.h"
#include "../Context.h"
#include "../Editor.h"
#include "../GameState.h"
#include "../ParkImporter.h"
#include "../actions/ParkEntrancePlaceAction.h"
#include "../actions/RideCreateAction.h"
#include "../actions/TrackPlaceAction.h"
#include "../core/FileStream.h"
#include "../interface/Viewport.h"
#include "../object/DefaultObjects.h"
#include "../object/ObjectManager.h"
#include "../object/ObjectRepository.h"
#include "../rct1/RCT1.h"
#include "../rct1/Tables.h"
#include "../rct12/EntryList.h"
#include "../rct12/RCT12.h"
#include "../ride/RideData.h"
#include "../scenario/ScenarioRepository.h"
#include "../world/Entrance.h"
#include "../world/Park.h"
#include "../world/Scenery.h"
#include "../world/tile_element/EntranceElement.h"
#include "../world/tile_element/PathElement.h"
#include "../world/tile_element/Slope.h"
#include "../world/tile_element/SmallSceneryElement.h"
#include "../world/tile_element/SurfaceElement.h"
#include "../world/tile_element/TrackElement.h"
#include "../world/tile_element/WallElement.h"

using namespace OpenRCT2;

static constexpr const uint8_t kZooCoordsXYStep = 64;
// static constexpr const uint8_t ZOO_kCoordsZStep = 8;

const std::string_view ZooWalls[] = {
    "fences/zoowall/f",
    "fences/dwall/f",
    "fences/aqwall/f",
};
const std::string_view ZooEntrances[] = {
    "building/building/fgate",
    "building/building/dgate",
    "building/building/aqgate",
};
static const std::unordered_map<std::string, std::string> kFacilities = {
    { "building/building/bathroom", "rct2.ride.tlt1" },  // Small restroom
    { "building/building/fbatroom", "rct2.ride.tlt1" },  // Family restroom
    { "building/building/acbath", "rct2.ride.tlt1" },    // Aquatic restroom
    { "building/building/bgrstnd", "rct2.ride.burgb" },  // Burger Stand
    { "building/building/pizzstnd", "rct2.ride.pizzs" }, // Pizza Stand
    { "building/building/drkstnd", "rct2.ride.drnks" },  // Drinks Stand
    { "objects/other/parkmap", "rct2.ride.infok" },      // Zoo Map
    { "building/building/hdogstnd", "rct2.ride.hotds" }, // Hot Dog Stall
    { "building/building/giftcart", "rct2.ride.souvs" }, // Gift Stand
};
static const std::unordered_map<std::string, std::string> kSmallScenery = {
    { "objects/foliage/weepwill", "rct2.scenery_small.tww" }, // Weeping willow
    { "objects/other/flower5", "rct2.scenery_small.tg6" },
    { "objects/other/flower6", "rct2.scenery_small.tg4" },
    { "objects/other/flower7", "rct2.scenery_small.tg13" },
    { "objects/foliage/birch", "rct2.scenery_small.tsb" },   // Birch Tree
    { "objects/foliage/fir", "rct2.scenery_small.tns" },     // Fir Tree
    { "objects/foliage/wtrreed", "rct2.scenery_small.tbr" }, // Water Reed
};
static const std::unordered_map<std::string, std::string> kWall = {
    { "fences/postrope/f", "rct2.scenery_wall.wpf" }, // Post and Rope Fence
};

enum ZooTerrainType : uint8_t
{
    Grass,
    SavannahGrass,
    Sand,
    Dirt,
    RainforestFloor,
    BrownStone,
    GrayStone,
    Gravel,
    Snow,
    FreshWater,
    SaltWater,
    DecideousFloor,
    Waterfall,
    ConiferousFloor,
    Concrete,
    Asphalt,
    TrampledTerrain,
    Gunite,
};

struct ShapeMap
{
    uint8_t Shape;
    int8_t HeightOffset;
};

static ShapeMap GetConvertedShape(uint8_t ztShape)
{
    uint8_t shape = 0;
    int8_t heightOffset = 0;

    if (ztShape & 0b00000001)
    {
        shape |= kTileSlopeSCornerUp;
        heightOffset -= 2;
    }
    if (ztShape & 0b00000100)
        shape |= kTileSlopeECornerUp;
    if (ztShape & 0b00010000)
        shape |= kTileSlopeNCornerUp;
    if (ztShape & 0b01000000)
        shape |= kTileSlopeWCornerUp;

    if (ztShape & 0b00000010)
    {
        shape |= kTileSlopeSCornerUp | kTileSlopeDiagonalFlag;
        heightOffset -= 4;
    }
    if (ztShape & 0b00001000)
        shape |= kTileSlopeECornerUp | kTileSlopeDiagonalFlag;
    if (ztShape & 0b00100000)
        shape |= kTileSlopeNCornerUp | kTileSlopeDiagonalFlag;
    if (ztShape & 0b10000000)
        shape |= kTileSlopeWCornerUp | kTileSlopeDiagonalFlag;

    return { shape, heightOffset };

    //    switch (ztShape)
    //    {
    //        case 0b00000001:
    //            return { TILE_ELEMENT_SLOPE_S_CORNER_UP, 0 };
    //        case 0b00000100:
    //            return { TILE_ELEMENT_SLOPE_E_CORNER_UP, 0 };
    //        case 0b00010000:
    //            return { TILE_ELEMENT_SLOPE_N_CORNER_UP, 0 };
    //        case 0b01000000:
    //            return { TILE_ELEMENT_SLOPE_W_CORNER_UP, 0 };
    //        default:
    //            return { 0, 0 };
    //    }
}

#pragma pack(push, 1)
struct ZooHeader
{
    char Magic[4];
    int32_t Version;
    int32_t Language;
    int32_t Campaign;
    int32_t MapSizeX;
    int32_t MapSizeY;
    int32_t Unk18;
    int32_t Unk1C;
};

struct ZooTerrainElement
{
    int32_t Height;
    uint8_t Shape;
    ZooTerrainType Type;
    int32_t Unk;
};
static_assert(sizeof(ZooTerrainElement) == 10);

struct ZT1CoordsXYZD
{
    int32_t X;
    int32_t Y;
    int32_t Height;
    int32_t Rotation;

    constexpr uint8_t GetRCTDirection()
    {
        return Rotation / 2;
        //        switch (Rotation)
        //        {
        //            case 0:
        //                return 2;
        //            case 2:
        //                return 3;
        //            case 4:
        //                return 0;
        //            case 6:
        //                return 1;
        //        }
        //
        //        return 0;
    }

    constexpr CoordsXYZD ToCoordsXYZD()
    {
        return CoordsXYZD(
            (Y + kZooCoordsXYStep) * kCoordsXYStep / kZooCoordsXYStep,
            (X + kZooCoordsXYStep) * kCoordsXYStep / kZooCoordsXYStep, Height + (26 * kCoordsZStep), GetRCTDirection());
    }

    constexpr TileCoordsXYZD ToTileCoordsXYZD()
    {
        return TileCoordsXYZD(ToCoordsXYZD());
    }
};
static_assert(sizeof(ZT1CoordsXYZD) == 16);
#pragma pack(pop)

struct ZooTileElement
{
    std::string Id0;
    std::string Id1;
    std::string Id2;
    int32_t X;
    int32_t Y;
    int32_t Height;
    int32_t Rotation;
};

static void AppendRequiredObjects(ObjectList& objectList, ObjectType objectType, const std::vector<std::string>& objectNames)
{
    for (const auto& objectName : objectNames)
    {
        auto descriptor = ObjectEntryDescriptor(objectName);
        descriptor.Type = objectType;
        objectList.Add(descriptor);
    }
}

static std::string ReadZTString(OpenRCT2::IStream& stream)
{
    auto stringLength = stream.ReadValue<int32_t>();
    char buffer[stringLength + 1];
    if (stringLength > 0)
    {
        stream.Read(buffer, stringLength);
    }
    buffer[stringLength] = 0;
    return std::string(buffer);
}

static std::string_view GetTerrainSurfaceObject(uint8_t terrainSurface)
{
    static constexpr std::string_view map[] = {
        "rct2.terrain_surface.grass",        // Grass,
        "rct2.terrain_surface.sand_brown",   // SavannahGrass,
        "rct2.terrain_surface.sand",         // Sand,
        "rct2.terrain_surface.dirt",         // Dirt,
        "rct2.terrain_surface.grass",        // RainforestFloor,
        "rct2.terrain_surface.sand_red",     // BrownStone,
        "rct2.terrain_surface.rock",         // GrayStone,
        "rct1ll.terrain_surface.roof_grey",  // Gravel,
        "rct2.terrain_surface.ice",          // Snow,
        "rct2.terrain_surface.grass",        // FreshWater,
        "rct2.terrain_surface.rock",         // SaltWater,
        "rct2.terrain_surface.sand_red",     // DecideousFloor,
        "rct2.terrain_surface.grass",        // Waterfall,
        "rct2.terrain_surface.grass_clumps", // ConiferousFloor,
        "rct2.terrain_surface.rock",         // Concrete,
        "rct2.terrain_surface.rock",         // Asphalt,
        "rct2.terrain_surface.grass_clumps", // TrampledTerrain,
        "rct2.terrain_surface.grid_purple",  // Gunite,
    };
    return terrainSurface < std::size(map) ? map[terrainSurface] : map[0];
}

namespace ZT1
{
    class ZooImporter final : public IParkImporter
    {
    private:
        OpenRCT2::IStream* _stream;
        std::string _zooPath;
        ZooHeader _header;

        // Lists of dynamic object entries
        RCT12::EntryList _rideEntries;
        RCT12::EntryList _smallSceneryEntries;
        RCT12::EntryList _largeSceneryEntries;
        RCT12::EntryList _wallEntries;
        RCT12::EntryList _pathEntries;
        RCT12::EntryList _pathAdditionEntries;
        RCT12::EntryList _sceneryGroupEntries;
        RCT12::EntryList _waterEntry;
        RCT12::EntryList _terrainSurfaceEntries;
        RCT12::EntryList _terrainEdgeEntries;
        RCT12::EntryList _footpathSurfaceEntries;
        RCT12::EntryList _footpathRailingsEntries;

        // Lookup tables for converting from RCT1 hard coded types to the new dynamic object entries
        ObjectEntryIndex _smallSceneryTypeToEntryMap[256]{};
        ObjectEntryIndex _largeSceneryTypeToEntryMap[256]{};
        ObjectEntryIndex _wallTypeToEntryMap[256]{};
        ObjectEntryIndex _pathTypeToEntryMap[24]{};
        ObjectEntryIndex _pathAdditionTypeToEntryMap[16]{};
        ObjectEntryIndex _sceneryThemeTypeToEntryMap[24]{};
        ObjectEntryIndex _terrainSurfaceTypeToEntryMap[16]{};
        ObjectEntryIndex _terrainEdgeTypeToEntryMap[16]{};
        ObjectEntryIndex _footpathSurfaceTypeToEntryMap[32]{};
        ObjectEntryIndex _footpathRailingsTypeToEntryMap[4]{};

    public:
        ParkLoadResult Load(const u8string& path) override
        {
            return LoadSavedGame(path);
        }

        ParkLoadResult LoadSavedGame(const u8string& path, bool skipObjectCheck = false) override
        {
            auto fs = FileStream(path, FILE_MODE_OPEN);
            auto result = LoadFromStream(&fs, true, skipObjectCheck, path);
            return result;
        }

        ParkLoadResult LoadScenario(const u8string& path, bool skipObjectCheck = false) override
        {
            return LoadSavedGame(path, skipObjectCheck);
        }

        ParkLoadResult LoadFromStream(
            OpenRCT2::IStream* stream, bool isScenario, bool skipObjectCheck = false, const u8string& path = {}) override
        {
            _stream = stream;
            _zooPath = path;

            InitialiseEntryMaps();
            CreateAvailableObjectMappings();
            return ParkLoadResult(GetRequiredObjects());
        }

        void Import(GameState_t& gameState) override
        {
            _header = _stream->ReadValue<ZooHeader>();
            Initialise(gameState);

            CreateAvailableObjectMappings();

            ImportExhibits();
            _stream->Seek(sizeof(int32_t) * 4, STREAM_SEEK_CURRENT);
            ImportTerrain();
            ImportTileElements(gameState);
            ResearchItemsMakeAllResearched();
            SetEveryRideTypeInvented();
            SetEveryRideEntryInvented();
            CheatsReset();
            ClearRestrictedScenery();
        }

        void ImportExhibits()
        {
            auto numExhibits = _stream->ReadValue<int32_t>();
            for (auto i = 0; i < numExhibits; i++)
            {
                _stream->Seek(sizeof(int32_t) * 2, STREAM_SEEK_CURRENT);
                std::string name = ReadZTString(*_stream);
                _stream->Seek(66, STREAM_SEEK_CURRENT);
                auto extension = _stream->ReadValue<int32_t>();
                LOG_ERROR("%s, extension %d", name.c_str(), extension);

                if (extension == 0x10000) // TANK
                {
                    _stream->Seek(21, STREAM_SEEK_CURRENT);
                }
                else if (extension == 0x1010000) // SHOW TANK
                {
                }

                LOG_ERROR("%s", name.c_str());
            }
        }

        bool GetDetails(ScenarioIndexEntry* dst) override
        {
            *dst = {};
            return false;
            //            dst->Category = SCENARIO_CATEGORY_OTHER;
            //            dst->SourceGame = ScenarioSource::Other;
            //            dst->SourceIndex = desc.index;
            //            dst->ScenarioId = SCENARIO_ID;
            //
            //            dst->ObjectiveType
            //
            //            String::Set(dst->Name, sizeof(dst->Name), name.c_str());
            //            String::Set(dst->Details, sizeof(dst->Details), details.c_str());
            //
            //            return true;
        }

        ObjectList GetRequiredObjects()
        {
            ObjectList result;

            AppendRequiredObjects(result, ObjectType::Ride, _rideEntries);
            AppendRequiredObjects(result, ObjectType::SmallScenery, _smallSceneryEntries);
            AppendRequiredObjects(result, ObjectType::LargeScenery, _largeSceneryEntries);
            AppendRequiredObjects(result, ObjectType::Walls, _wallEntries);
            AppendRequiredObjects(result, ObjectType::Paths, _pathEntries);
            AppendRequiredObjects(result, ObjectType::PathAdditions, _pathAdditionEntries);
            AppendRequiredObjects(result, ObjectType::SceneryGroup, _sceneryGroupEntries);
            AppendRequiredObjects(
                result, ObjectType::Banners,
                std::vector<std::string>({
                    "rct2.footpath_banner.bn1",
                    "rct2.footpath_banner.bn2",
                    "rct2.footpath_banner.bn3",
                    "rct2.footpath_banner.bn4",
                    "rct2.footpath_banner.bn5",
                    "rct2.footpath_banner.bn6",
                    "rct2.footpath_banner.bn7",
                    "rct2.footpath_banner.bn8",
                    "rct2.footpath_banner.bn9",
                }));
            AppendRequiredObjects(result, ObjectType::ParkEntrance, std::vector<std::string>({ "rct2.park_entrance.pkent1" }));
            AppendRequiredObjects(result, ObjectType::Water, std::vector<std::string>({ "rct2.water.wtrcyan" }));
            AppendRequiredObjects(result, ObjectType::PeepNames, std::vector<std::string>({ "rct2.peep_names.original" }));
            AppendRequiredObjects(result, ObjectType::TerrainSurface, _terrainSurfaceEntries);
            AppendRequiredObjects(result, ObjectType::TerrainEdge, std::vector<std::string>({ "rct2.terrain_edge.rock" }));
            //            AppendRequiredObjects(result, ObjectType::TerrainEdge, _terrainEdgeEntries);
            //            AppendRequiredObjects(result, ObjectType::FootpathSurface, _footpathSurfaceEntries);
            AppendRequiredObjects(
                result, ObjectType::FootpathSurface,
                std::vector<std::string>({ "rct1.footpath_surface.tarmac", "rct1.footpath_surface.dirt",
                                           "rct1.footpath_surface.crazy_paving", "rct1.footpath_surface.tiles_brown",
                                           "rct1aa.footpath_surface.ash", "rct1aa.footpath_surface.tarmac_green",
                                           "rct1aa.footpath_surface.tarmac_brown", "rct1aa.footpath_surface.tiles_grey",
                                           "rct1aa.footpath_surface.tarmac_red", "rct1ll.footpath_surface.tiles_green",
                                           "rct1ll.footpath_surface.tiles_red", "rct1.footpath_surface.queue_blue",
                                           "rct1aa.footpath_surface.queue_red", "rct1aa.footpath_surface.queue_yellow",
                                           "rct1aa.footpath_surface.queue_green" }));
            //            AppendRequiredObjects(result, ObjectType::FootpathRailings, _footpathRailingsEntries);
            AppendRequiredObjects(
                result, ObjectType::FootpathRailings, std::vector<std::string>({ "rct2.footpath_railings.wood" }));
            RCT12AddDefaultObjects(result);
            return result;
        }

        void CreateAvailableObjectMappings()
        {
            AddDefaultEntries();
            AddAvailableEntriesFromSceneryGroups();
        }

        void AddDefaultEntries()
        {
            _rideEntries.AddRange({
                "rct2.ride.twist1", "rct2.ride.ptct1", "rct2.ride.zldb",  "rct2.ride.lfb1",  "rct2.ride.vcr",
                "rct2.ride.mgr1",   "rct2.ride.tlt1",  "rct2.ride.atm1",  "rct2.ride.faid1", "rct2.ride.infok",
                "rct2.ride.drnks",  "rct2.ride.cndyf", "rct2.ride.burgb", "rct2.ride.balln", "rct2.ride.arrt1",
                "rct2.ride.rboat",  "rct2.ride.pizzs", "rct2.ride.hotds", "rct2.ride.souvs",
            });

            // Add default scenery groups
            _sceneryGroupEntries.AddRange({
                "rct2.scenery_group.scgtrees",
                "rct2.scenery_group.scgshrub",
                "rct2.scenery_group.scggardn",
                "rct2.scenery_group.scgfence",
                "rct2.scenery_group.scgwalls",
                "rct2.scenery_group.scgpathx",
            });

            // Add default footpaths
            _footpathSurfaceEntries.AddRange(
                { "rct1.footpath_surface.tarmac", "rct1.footpath_surface.dirt", "rct1.footpath_surface.crazy_paving",
                  "rct1.footpath_surface.tiles_brown", "rct1aa.footpath_surface.ash", "rct1aa.footpath_surface.tarmac_green",
                  "rct1aa.footpath_surface.tarmac_brown", "rct1aa.footpath_surface.tiles_grey",
                  "rct1aa.footpath_surface.tarmac_red", "rct1ll.footpath_surface.tiles_green",
                  "rct1ll.footpath_surface.tiles_red", "rct1.footpath_surface.queue_blue", "rct1aa.footpath_surface.queue_red",
                  "rct1aa.footpath_surface.queue_yellow", "rct1aa.footpath_surface.queue_green" });

            _footpathRailingsEntries.AddRange({ "rct2.footpath_railings.wood", "rct1ll.footpath_railings.space",
                                                "rct1ll.footpath_railings.bamboo", "rct2.footpath_railings.concrete" });

            // Add default surfaces
            _terrainSurfaceEntries.AddRange(
                { "rct2.terrain_surface.grass", "rct2.terrain_surface.sand", "rct2.terrain_surface.dirt",
                  "rct2.terrain_surface.rock", "rct2.terrain_surface.martian", "rct2.terrain_surface.chequerboard",
                  "rct2.terrain_surface.grass_clumps", "rct2.terrain_surface.ice", "rct2.terrain_surface.grid_red",
                  "rct2.terrain_surface.grid_yellow", "rct2.terrain_surface.grid_purple", "rct2.terrain_surface.grid_green",
                  "rct2.terrain_surface.sand_red", "rct2.terrain_surface.sand_brown", "rct1aa.terrain_surface.roof_red",
                  "rct1ll.terrain_surface.roof_grey", "rct1ll.terrain_surface.rust", "rct1ll.terrain_surface.wood" });

            // Add default edges
            _terrainEdgeEntries.AddRange({ "rct2.terrain_edge.rock", "rct2.terrain_edge.wood_red",
                                           "rct2.terrain_edge.wood_black", "rct2.terrain_edge.ice", "rct1.terrain_edge.brick",
                                           "rct1.terrain_edge.iron", "rct1aa.terrain_edge.grey", "rct1aa.terrain_edge.yellow",
                                           "rct1aa.terrain_edge.red", "rct1ll.terrain_edge.purple", "rct1ll.terrain_edge.green",
                                           "rct1ll.terrain_edge.stone_brown", "rct1ll.terrain_edge.stone_grey",
                                           "rct1ll.terrain_edge.skyscraper_a", "rct1ll.terrain_edge.skyscraper_b" });
        }

        void InitialiseEntryMaps()
        {
            std::fill(std::begin(_smallSceneryTypeToEntryMap), std::end(_smallSceneryTypeToEntryMap), OBJECT_ENTRY_INDEX_NULL);
            std::fill(std::begin(_largeSceneryTypeToEntryMap), std::end(_largeSceneryTypeToEntryMap), OBJECT_ENTRY_INDEX_NULL);
            std::fill(std::begin(_wallTypeToEntryMap), std::end(_wallTypeToEntryMap), OBJECT_ENTRY_INDEX_NULL);
            std::fill(std::begin(_pathTypeToEntryMap), std::end(_pathTypeToEntryMap), OBJECT_ENTRY_INDEX_NULL);
            std::fill(std::begin(_pathAdditionTypeToEntryMap), std::end(_pathAdditionTypeToEntryMap), OBJECT_ENTRY_INDEX_NULL);
            std::fill(std::begin(_sceneryThemeTypeToEntryMap), std::end(_sceneryThemeTypeToEntryMap), OBJECT_ENTRY_INDEX_NULL);
            std::fill(
                std::begin(_terrainSurfaceTypeToEntryMap), std::end(_terrainSurfaceTypeToEntryMap), OBJECT_ENTRY_INDEX_NULL);
            std::fill(std::begin(_terrainEdgeTypeToEntryMap), std::end(_terrainEdgeTypeToEntryMap), OBJECT_ENTRY_INDEX_NULL);
            std::fill(
                std::begin(_footpathSurfaceTypeToEntryMap), std::end(_footpathSurfaceTypeToEntryMap), OBJECT_ENTRY_INDEX_NULL);
            std::fill(
                std::begin(_footpathRailingsTypeToEntryMap), std::end(_footpathRailingsTypeToEntryMap),
                OBJECT_ENTRY_INDEX_NULL);
        }

        void Initialise(GameState_t& gameState)
        {
            gameState.ScenarioFileName = "";

            // Do map initialisation, same kind of stuff done when loading scenario editor
            gameStateInitAll(gameState, { _header.MapSizeX + 2, _header.MapSizeY + 2 });
            gameState.EditorStep = EditorStep::ObjectSelection;
            gameState.ScenarioCategory = SCENARIO_CATEGORY_OTHER;
        }

        void ImportTerrain()
        {
            // gMapBaseZ = 7;

            //            assert(_stream->GetPosition() == 0x24D);
            //            _stream->SetPosition(0x24D);
            for (auto y = 0; y < _header.MapSizeY; y++)
            {
                for (auto x = 0; x < _header.MapSizeX; x++)
                {
                    auto tileElement = _stream->ReadValue<ZooTerrainElement>();
                    // Zoo Tycoon lays out its X/Y in another direction
                    //                    LOG_ERROR("X %d Y %d, type %d", x, y, tileElement.Type);
                    auto rctCoords = TileCoordsXY(y + 1, x + 1);

                    auto* surface = MapGetSurfaceElementAt(rctCoords);
                    auto height = (tileElement.Height + 13) * 2;
                    if (tileElement.Type == ZooTerrainType::FreshWater || tileElement.Type == ZooTerrainType::SaltWater)
                    {
                        surface->SetWaterHeight(height * kCoordsZStep);
                        height -= 2;
                    }

                    if (rctCoords.x == 37 && rctCoords.y == 14)
                    {
                        LOG_ERROR("shape %d", tileElement.Shape);
                    }

                    const auto shapeAndHeightOffset = GetConvertedShape(tileElement.Shape);
                    surface->SetSlope(shapeAndHeightOffset.Shape);
                    surface->BaseHeight = height + shapeAndHeightOffset.HeightOffset;
                    // TODO: fix this, based on shape.
                    surface->ClearanceHeight = height + shapeAndHeightOffset.HeightOffset;
                    const auto surfaceIndentifier = GetTerrainSurfaceObject(tileElement.Type);
                    auto entryIndex = _terrainSurfaceEntries.GetOrAddEntry(surfaceIndentifier);
                    surface->SetSurfaceObjectIndex(entryIndex);

                    surface->SetOwnership(OWNERSHIP_OWNED);
                }
            }
        }

        void ImportTileElements(GameState_t& gameState)
        {
            //            LOG_ERROR("Current position: %d", _stream->GetPosition());
            //            _stream->SetPosition(0xDE07);
            auto numElements = _stream->ReadValue<uint32_t>();

            gameState.Cheats.sandboxMode = true;
            gameState.Park.Flags |= PARK_FLAGS_NO_MONEY;

            for (uint32_t i = 0; i < numElements; i++)
            {
                std::string ids[3];

                for (uint32_t id = 0; id < 3; id++)
                {
                    ids[id] = ReadZTString(*_stream);
                }
                std::string combinedId = ids[0] + "/" + ids[1] + "/" + ids[2];
                auto restLength = _stream->ReadValue<int32_t>();
                auto savedPos = _stream->GetPosition();

                for (auto id : ZooWalls)
                {
                    if (id == combinedId)
                        ImportZooWall();
                }
                for (auto id : ZooEntrances)
                {
                    if (id == combinedId)
                    {
                        ImportZooEntrance(gameState);
                    }
                }
                if (ids[0] == "paths")
                {
                    ImportPath(combinedId);
                }
                for (auto mapping : kFacilities)
                {
                    if (mapping.first == combinedId)
                        ImportFacility(mapping.second);
                }
                for (auto mapping : kSmallScenery)
                {
                    if (mapping.first == combinedId)
                        ImportSmallScenery(mapping.second);
                }
                for (auto mapping : kWall)
                {
                    if (mapping.first == combinedId)
                        ImportWall(mapping.second);
                }

                _stream->SetPosition(savedPos);

                _stream->Seek(restLength, STREAM_SEEK_CURRENT);
                //                LOG_ERROR("%s, rest length %d", combinedId.c_str(), restLength);
            }
        }

        uint8_t GetEdgeFromDirection(Direction direction)
        {
            uint8_t ret = 0;
            switch (direction)
            {
                case 0:
                    ret = 8;
                    break;
                case 1:
                    ret = 1;
                    break;
                case 2:
                    ret = 2;
                    break;
                case 3:
                    ret = 4;
                    break;
            }

            return ret;
        }

        void ImportZooWall()
        {
            // Skip unk
            _stream->Seek(4, STREAM_SEEK_CURRENT);

            auto ztCoords = _stream->ReadValue<ZT1CoordsXYZD>();
            auto coords = ztCoords.ToCoordsXYZD();

            // Skip age(?)
            _stream->Seek(4, STREAM_SEEK_CURRENT);

            auto name = ReadZTString(*_stream);
            LOG_ERROR("Name: %s", name.c_str());

            auto* surface = MapGetSurfaceElementAt(coords);
            auto fences = surface->GetParkFences();

            fences |= GetEdgeFromDirection(coords.direction);

            //            switch (coords.direction)
            //            {
            //                case 0:
            //                    fences |= 8;
            //                    break;
            //                case 1:
            //                    fences |= 1;
            //                    break;
            //                case 2:
            //                    fences |= 2;
            //                    break;
            //                case 3:
            //                    fences |= 4;
            //                    break;
            //            }

            surface->SetParkFences(fences);
        }

        void ImportZooEntrance(GameState_t& gameState)
        {
            // Skip unk
            _stream->Seek(4, STREAM_SEEK_CURRENT);

            auto ztCoords = _stream->ReadValue<ZT1CoordsXYZD>();
            auto coords = ztCoords.ToCoordsXYZD();

            // Skip age(?)
            _stream->Seek(4, STREAM_SEEK_CURRENT);

            auto name = ReadZTString(*_stream);
            LOG_ERROR("Name: %s", name.c_str());

            gameState.Park.Name = name;

            coords.direction = DirectionReverse(coords.direction);
            auto asTileCoords = TileCoordsXYZD(coords);
            TileCoordsXYZD segmentTileCoords[3] = { asTileCoords, asTileCoords, asTileCoords };
            auto peepSpawnCoords = coords.ToTileStart();
            auto firstOwnedSquareCoords = coords.ToTileCentre();
            peepSpawnCoords.direction = DirectionReverse(peepSpawnCoords.direction);
            switch (segmentTileCoords[0].direction)
            {
                case 0:
                    segmentTileCoords[1].y -= 1;
                    segmentTileCoords[2].y += 1;
                    peepSpawnCoords.x -= kCoordsXYStep;
                    peepSpawnCoords.y += 16;
                    firstOwnedSquareCoords.x += kCoordsXYStep;
                    break;
                case 1:
                    segmentTileCoords[1].x -= 1;
                    segmentTileCoords[2].x += 1;
                    peepSpawnCoords.y -= kCoordsXYStep;
                    peepSpawnCoords.x += 16;
                    firstOwnedSquareCoords.y += kCoordsXYStep;
                    break;
                case 2:
                    segmentTileCoords[1].y += 1;
                    segmentTileCoords[2].y -= 1;
                    peepSpawnCoords.x += kCoordsXYStep;
                    peepSpawnCoords.y += 16;
                    firstOwnedSquareCoords.x -= kCoordsXYStep;
                    break;
                case 3:
                    segmentTileCoords[1].x += 1;
                    segmentTileCoords[2].x -= 1;
                    peepSpawnCoords.y += kCoordsXYStep;
                    peepSpawnCoords.x += 16;
                    firstOwnedSquareCoords.y -= kCoordsXYStep;
                    break;
            }

            //                    auto gameAction = ParkEntrancePlaceAction(coords.ToCoordsXYZD(), 0);
            //                    auto result = GameActions::Execute(&gameAction);

            //            LOG_ERROR("Placing entrance at x %d, y %d", tileCoords[0].x, tileCoords[0].y);

            for (uint32_t sequenceIndex = 0; sequenceIndex < std::size(segmentTileCoords); sequenceIndex++)
            {
                const auto& current = segmentTileCoords[sequenceIndex];
                EntranceElement* tileElement;
                auto* pathElement = MapGetPathElementAt(current);
                if (pathElement != nullptr)
                {
                    auto* baseElement = pathElement->as<TileElement>();
                    baseElement->ClearAs(TileElementType::Entrance);
                    tileElement = baseElement->AsEntrance();
                }
                else
                {
                    tileElement = TileElementInsert<EntranceElement>(current.ToCoordsXYZ(), 0b1111);
                }

                tileElement->SetEntranceType(ENTRANCE_TYPE_PARK_ENTRANCE);
                tileElement->SetSequenceIndex(sequenceIndex);
                tileElement->BaseHeight = current.z;
                tileElement->SetDirection(current.direction);
                tileElement->ClearanceHeight = current.z + 12;
                tileElement->SetSurfaceEntryIndex(0);

                if (sequenceIndex == 0)
                {
                    MapAnimationCreate(MAP_ANIMATION_TYPE_PARK_ENTRANCE, current.ToCoordsXYZ());
                }
            }

            gameState.PeepSpawns.push_back(peepSpawnCoords);
            auto* peepSpawnSurface = MapGetSurfaceElementAt(peepSpawnCoords);
            peepSpawnSurface->SetOwnership(OWNERSHIP_UNOWNED);

            gameState.Park.Entrances.push_back(segmentTileCoords[0].ToCoordsXYZD());
            gameState.SavedView = Translate3DTo2DWithZ(segmentTileCoords[0].direction, segmentTileCoords[0].ToCoordsXYZ());
            gameState.SavedViewRotation = segmentTileCoords[0].direction;
            auto* surface = MapGetSurfaceElementAt(firstOwnedSquareCoords);
            surface->SetOwnership(OWNERSHIP_OWNED);
        }

        void ImportFacility(const std::string& objectIdentifier)
        {
            // Skip unk
            _stream->Seek(4, STREAM_SEEK_CURRENT);

            auto ztCoords = _stream->ReadValue<ZT1CoordsXYZD>();
            auto coords = ztCoords.ToCoordsXYZD();

            // Skip age(?)
            _stream->Seek(4, STREAM_SEEK_CURRENT);

            auto name = ReadZTString(*_stream);
            LOG_ERROR("Name: %s", name.c_str());

            auto subtypeId = _rideEntries.GetOrAddEntry(objectIdentifier);
            // auto& objManager = GetContext()->GetObjectManager();
            // const auto* object = objManager.GetLoadedObject<RideObject>(subtypeId);

            auto rideIndex = GetNextFreeRideId();
            auto* ride = RideAllocateAtIndex(rideIndex);
            if (ride == nullptr)
            {
                LOG_ERROR("Ride not allocated!");
                return;
            }
            const auto* rideEntry = GetRideEntryByIndex(subtypeId);
            if (rideEntry == nullptr)
            {
                LOG_ERROR("Ride entry not allocated!");
                // return;
            }
            auto rideTypeId = rideEntry->GetFirstNonNullRideType();
            ride->type = rideTypeId;
            ride->subtype = subtypeId;
            ride->SetColourPreset(0);
            ride->overall_view = coords;
            ride->custom_name = name;

            for (auto& station : ride->GetStations())
            {
                station.Start.SetNull();
                station.Entrance.SetNull();
                station.Exit.SetNull();
                station.TrainAtStation = RideStation::kNoTrain;
                station.QueueTime = 0;
                station.SegmentLength = 0;
                station.QueueLength = 0;
                station.Length = 0;
                station.Height = 0;
            }

            ride->status = RideStatus::Closed;
            ride->NumTrains = 1;
            ride->ProposedNumTrains = 1;
            ride->max_trains = OpenRCT2::Limits::kMaxTrainsPerRide;
            ride->num_cars_per_train = 1;
            ride->proposed_num_cars_per_train = 1; // rideEntry->max_cars_in_train;
            ride->min_waiting_time = 10;
            ride->max_waiting_time = 60;
            ride->depart_flags = RIDE_DEPART_WAIT_FOR_MINIMUM_LENGTH | 3;
            const auto& rtd = ride->GetRideTypeDescriptor();
            const auto& operatingSettings = rtd.OperatingSettings;
            ride->operation_option = (operatingSettings.MinValue * 3 + operatingSettings.MaxValue) / 4;

            ride->lift_hill_speed = rtd.LiftData.minimum_speed;

            ride->ratings.setNull();
            for (auto i = 0; i < RCT2::ObjectLimits::MaxShopItemsPerRideEntry; i++)
            {
                ride->price[i] = rtd.DefaultPrices[i];
            }
            //            ride->price[0] = GetShopItemDescriptor(rideEntry->shop_item[0]).DefaultPrice;
            //            if (rideEntry->shop_item[1] != ShopItem::None)
            //            {
            //                ride->price[1] = GetShopItemDescriptor(rideEntry->shop_item[1]).DefaultPrice;
            //            }
            ride->value = RIDE_VALUE_UNDEFINED;
            ride->satisfaction = 255;
            ride->popularity = 255;
            ride->build_date = GetDate().GetMonthsElapsed();
            ride->music_tune_id = TUNE_ID_NULL;

            ride->breakdown_reason = 255;
            ride->upkeep_cost = kMoney64Undefined;
            ride->reliability = kRideInitialReliability;
            ride->unreliability_factor = 1;
            ride->inspection_interval = RIDE_INSPECTION_EVERY_30_MINUTES;
            ride->last_crash_type = RIDE_CRASH_TYPE_NONE;
            ride->income_per_hour = kMoney64Undefined;
            ride->profit = kMoney64Undefined;

            ride->entrance_style = OBJECT_ENTRY_INDEX_NULL;
            if (rtd.HasFlag(RtdFlag::hasEntranceAndExit))
            {
                ride->entrance_style = 0;
            }

            ride->num_circuits = 1;
            ride->mode = ride->GetDefaultMode();
            ride->MinCarsPerTrain = 1; // rideEntry->min_cars_in_train;
            ride->MaxCarsPerTrain = 1; // rideEntry->max_cars_in_train;

            //            SelectedLiftAndInverted liftState{};
            //            auto trackPlaceAction = TrackPlaceAction(
            //                rideIndex, rtd.StartTrackPiece, ride->type, coords, 0, EnumValue(RideColourScheme::main),
            //                DEFAULT_SEAT_ROTATION, liftState, false);
            //            GameActions::Execute(&trackPlaceAction);

            auto& station0 = ride->GetStation(StationIndex::FromUnderlying(0));
            station0.Start = coords;
            station0.SetBaseZ(coords.z);
            ride->status = RideStatus::Open;

            auto* trackElement = TileElementInsert<TrackElement>(coords, 0b1111);
            if (trackElement != nullptr)
            {
                trackElement->SetDirection(coords.direction);
                trackElement->SetClearanceZ(trackElement->GetBaseZ() + (4 * kCoordsZStep));
                trackElement->SetRideIndex(rideIndex);
                trackElement->SetTrackType(rtd.StartTrackPiece);
                trackElement->SetRideType(rideTypeId);
                trackElement->SetColourScheme(RideColourScheme::main);
            }
        }

        void ImportSmallScenery(const std::string& objectIdentifier)
        {
            // Skip unk
            _stream->Seek(4, STREAM_SEEK_CURRENT);

            auto ztCoords = _stream->ReadValue<ZT1CoordsXYZD>();
            auto coords = ztCoords.ToCoordsXYZD();

            // Skip age(?)
            _stream->Seek(4, STREAM_SEEK_CURRENT);

            auto name = ReadZTString(*_stream);
            LOG_ERROR("Name: %s", name.c_str());

            auto* smallSceneryElement = TileElementInsert<SmallSceneryElement>(coords, 0b1111);
            if (smallSceneryElement != nullptr)
            {
                auto entryIndex = _smallSceneryEntries.GetOrAddEntry(objectIdentifier);

                smallSceneryElement->SetDirection(coords.direction);
                smallSceneryElement->SetClearanceZ(smallSceneryElement->GetBaseZ() + (4 * kCoordsZStep));
                smallSceneryElement->SetEntryIndex(entryIndex);
            }
        }

        void ImportWall(const std::string& objectIdentifier)
        {
            // Skip unk
            _stream->Seek(4, STREAM_SEEK_CURRENT);

            auto ztCoords = _stream->ReadValue<ZT1CoordsXYZD>();
            auto coords = ztCoords.ToCoordsXYZD();

            // Skip age(?)
            _stream->Seek(4, STREAM_SEEK_CURRENT);

            auto name = ReadZTString(*_stream);
            LOG_ERROR("Name: %s", name.c_str());

            auto* wallElement = TileElementInsert<WallElement>(coords, 0b1111);
            if (wallElement != nullptr)
            {
                auto entryIndex = _wallEntries.GetOrAddEntry(objectIdentifier);

                wallElement->SetDirection(coords.direction);
                wallElement->SetClearanceZ(wallElement->GetBaseZ() + (2 * kCoordsZStep));
                wallElement->SetEntryIndex(entryIndex);
            }
        }

        void ImportPath(std::string_view combinedId)
        {
            // Skip unk
            _stream->Seek(4, STREAM_SEEK_CURRENT);

            auto ztCoords = _stream->ReadValue<ZT1CoordsXYZD>();
            auto coords = ztCoords.ToCoordsXYZD();

            // Skip age(?)
            _stream->Seek(4, STREAM_SEEK_CURRENT);

            auto name = ReadZTString(*_stream);
            LOG_ERROR("Name: %s", name.c_str());

            ObjectEntryIndex entryIndex = 0;
            if (combinedId == "paths/paths/brkpath")
            {
                entryIndex = 10;
            }
            else if (combinedId == "paths/path/dirtpath")
            {
                entryIndex = 7;
            }

            if (MapGetParkEntranceElementAt(coords, false))
                return;

            auto pathElement = TileElementInsert<PathElement>(coords, 0b1111);
            pathElement->SetSurfaceEntryIndex(entryIndex);
            pathElement->SetRailingsEntryIndex(0);

            // ZT does not save footpath edges. Autoconnect them. This will need rework once fences are imported.
            // FootpathRemoveEdgesAt(ztCoords.ToCoordsXYZD(), pathElement->as<TileElement>());
            pathElement->SetEdgesAndCorners(0b11111111);
        }

        void AddAvailableEntriesFromSceneryGroups()
        {
            for (int32_t sceneryTheme = 0; sceneryTheme <= RCT1::RCT1_SCENERY_THEME_PAGODA; sceneryTheme++)
            {
                //                if (sceneryTheme != 0 && _sceneryThemeTypeToEntryMap[sceneryTheme] == OBJECT_ENTRY_INDEX_NULL)
                //                    continue;

                auto objects = RCT1::GetSceneryObjects(sceneryTheme);
                for (auto objectName : objects)
                {
                    auto& objectRepository = OpenRCT2::GetContext()->GetObjectRepository();
                    auto foundObject = objectRepository.FindObject(objectName);
                    if (foundObject != nullptr)
                    {
                        auto objectType = foundObject->Type;
                        switch (objectType)
                        {
                            case ObjectType::SmallScenery:
                            case ObjectType::LargeScenery:
                            case ObjectType::Walls:
                            case ObjectType::Paths:
                            case ObjectType::PathAdditions:
                            {
                                RCT12::EntryList* entries = GetEntryList(objectType);

                                // Check if there are spare entries available
                                size_t maxEntries = static_cast<size_t>(getObjectEntryGroupCount(objectType));
                                if (entries != nullptr && entries->GetCount() < maxEntries)
                                {
                                    entries->GetOrAddEntry(objectName);
                                }
                                break;
                            }
                            default:
                                // This switch processes only ObjectTypes valid for scenery
                                break;
                        }
                    }
                    else
                    {
                        LOG_ERROR("Cannot find object %s", objectName);
                    }
                }
            }
        }

        RCT12::EntryList* GetEntryList(ObjectType objectType)
        {
            switch (objectType)
            {
                case ObjectType::Ride:
                    return &_rideEntries;
                case ObjectType::SmallScenery:
                    return &_smallSceneryEntries;
                case ObjectType::LargeScenery:
                    return &_largeSceneryEntries;
                case ObjectType::Walls:
                    return &_wallEntries;
                case ObjectType::Paths:
                    return &_pathEntries;
                case ObjectType::PathAdditions:
                    return &_pathAdditionEntries;
                case ObjectType::SceneryGroup:
                    return &_sceneryGroupEntries;
                case ObjectType::Water:
                    return &_waterEntry;
                default:
                    // This switch processes only ObjectType for for Entries
                    break;
            }
            return nullptr;
        }
    };
} // namespace ZT1

std::unique_ptr<IParkImporter> ParkImporter::CreateZoo()
{
    return std::make_unique<ZT1::ZooImporter>();
}
