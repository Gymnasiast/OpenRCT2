/*****************************************************************************
 * Copyright (c) 2014-2018 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include "../world/Footpath.h"
#include "Object.h"

class PathRailingsObject final : public Object
{
private:
    PathRailingsEntry _pathRailingsEntry = {};

public:
    explicit PathRailingsObject(const rct_object_entry& entry)
        : Object(entry)
    {
        log_info("railing2!");
    }

    PathRailingsEntry* GetPathRailingsEntry()
    {
        return &_pathRailingsEntry;
    }

    void ReadJson(IReadObjectContext* context, json_t& root) override;
    void Load() override;
    void Unload() override;

    void DrawPreview(rct_drawpixelinfo* dpi, int32_t width, int32_t height) const override;
};
