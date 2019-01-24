/*****************************************************************************
 * Copyright (c) 2014-2018 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "PathRailingsObject.h"

#include "../core/IStream.hpp"
#include "../core/Json.hpp"
#include "../drawing/Drawing.h"
#include "../localisation/Language.h"
#include "../world/Footpath.h"

void PathRailingsObject::Load()
{
    GetStringTable().Sort();
    _pathRailingsEntry.string_idx = language_allocate_object_string(GetName());

    uint32_t imagesOffset = gfx_object_allocate_images(GetImageTable().GetImages(), GetImageTable().GetCount());
    _pathRailingsEntry.bridge_image = imagesOffset + 36;
    _pathRailingsEntry.preview = imagesOffset + 0;
    _pathRailingsEntry.railings_image = imagesOffset;
}

void PathRailingsObject::Unload()
{
    language_free_object_string(_pathRailingsEntry.string_idx);
    gfx_object_free_images(_pathRailingsEntry.railings_image, GetImageTable().GetCount());

    _pathRailingsEntry.string_idx = 0;
    _pathRailingsEntry.bridge_image = 0;
}

void PathRailingsObject::DrawPreview(rct_drawpixelinfo* dpi, int32_t width, int32_t height) const
{
    int32_t x = width / 2;
    int32_t y = height / 2;
    // gfx_draw_sprite(dpi, _pathRailingsEntry.preview, x - 49, y - 17, 0);

    if (_pathRailingsEntry.support_type == RailingEntrySupportType::Pole)
    {
        gfx_draw_sprite(dpi, _pathRailingsEntry.bridge_image + 5, { x, y - 17 }, 0);
        gfx_draw_sprite(dpi, _pathRailingsEntry.railings_image + 1, { x + 4, y - 14 }, 0);
        gfx_draw_sprite(dpi, _pathRailingsEntry.railings_image + 1, { x + 27, y - 2 }, 0);
    }
    else
    {
        gfx_draw_sprite(dpi, _pathRailingsEntry.bridge_image + 49, { x, y - 17 }, 0);
        gfx_draw_sprite(dpi, _pathRailingsEntry.railings_image + 1, { x + 4, y - 14 }, 0);
        gfx_draw_sprite(dpi, _pathRailingsEntry.railings_image + 1, { x + 27, y - 3 }, 0);
    }
}

static RailingEntrySupportType ParseSupportType(const std::string& s)
{
    if (s == "pole")
        return RailingEntrySupportType::Pole;
    else /* if (s == "box") */
        return RailingEntrySupportType::Box;
}

void PathRailingsObject::ReadJson(IReadObjectContext* context, json_t& root)
{
    auto properties = root["properties"];
    _pathRailingsEntry.support_type = ParseSupportType(Json::GetString(properties["supportType"]));
    _pathRailingsEntry.scrolling_mode = Json::GetNumber<uint8_t>(properties["scrollingMode"]);

    // Flags
    _pathRailingsEntry.flags = Json::GetFlags<uint8_t>(
        properties,
        {
            { "hasSupportImages", RAILING_ENTRY_FLAG_HAS_SUPPORT_BASE_SPRITE },
            { "hasElevatedPathImages", RAILING_ENTRY_FLAG_DRAW_PATH_OVER_SUPPORTS },
        });

    PopulateTablesFromJson(context, root);
}
