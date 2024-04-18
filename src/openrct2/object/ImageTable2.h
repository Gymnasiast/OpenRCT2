/*****************************************************************************
 * Copyright (c) 2014-2022 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include "../core/JsonFwd.hpp"
#include "../drawing/ImageId.hpp"
#include "ObjectAsset.h"
#include "ResourceTable.h"

#include <optional>

struct IReadObjectContext;
struct rct_g1_element;

namespace OpenRCT2
{
    class ImageSource;

    class ImageTable2 : public ResourceTable
    {
    public:
        struct Entry
        {
            SourceKind Kind{};
            std::optional<ObjectAsset> Asset;
            std::optional<uint32_t> PathIndex;
            int32_t X{};
            int32_t Y{};
        };

    private:
        std::vector<Entry> _entries;
        ImageIndex _baseIndex = ImageIndexUndefined;
        size_t _loadedImageCount{};

        std::string _lastImageSourceKey;
        std::unique_ptr<ImageSource> _lastImageSource;

    public:
        ImageTable2();
        ~ImageTable2();

        std::vector<Entry>& GetEntries();

        /**
         * Read the entries from the given JSON into the table, but do not load anything.
         */
        void ReadFromJson(IReadObjectContext& context, const json_t& root);

        /**
         * Load all available entries from the given table.
         */
        void LoadFrom(const ImageTable2& table, size_t sourceStartIndex, size_t length);

        /**
         * Load all available entries.
         */
        ImageIndex Load();

        /**
         * Unloads all entries that are currently loaded.
         */
        void Unload();

        size_t GetCount() const;
        ImageIndex GetImage(uint32_t index) const;
        void LoadImage(std::vector<rct_g1_element>& elements, size_t index);

    private:
        static void ReadImageInfoFromJson(IReadObjectContext& context, const json_t& jImage, Entry& entry);
        void ReadEntryFromJson(IReadObjectContext& context, const json_t& jImage);
        ImageSource* GetOrLoadSource(Entry& entry);
        static std::string GetImageSourceKey(const Entry& entry);
        static std::unique_ptr<ImageSource> CreateImageSource(const Entry& entry);
    };
} // namespace OpenRCT2
