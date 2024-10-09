/*****************************************************************************
 * Copyright (c) 2014-2024 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "../../../ride/Track.h"
#include "../../../ride/TrackPaint.h"
#include "../../../sprites.h"
#include "../../tile_element/Paint.Tunnel.h"
#include "../../tile_element/Segment.h"
#include "WoodenRollerCoaster.h"

using namespace OpenRCT2;

static constexpr TunnelGroup kTunnelGroup = TunnelGroup::Square;

enum
{
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_0 = SPR_CSG_BEGIN + 65447,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_1 = SPR_CSG_BEGIN + 65448,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_2 = SPR_CSG_BEGIN + 65449,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_3 = SPR_CSG_BEGIN + 65450,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_RIGHT_BANK_0 = SPR_CSG_BEGIN + 65451,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_RIGHT_BANK_1 = SPR_CSG_BEGIN + 65452,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_RIGHT_BANK_2 = SPR_CSG_BEGIN + 65453,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_RIGHT_BANK_3 = SPR_CSG_BEGIN + 65454,
    SPR_CLASSIC_WOODEN_RC_LEFT_BANK_0 = SPR_CSG_BEGIN + 65455,
    SPR_CLASSIC_WOODEN_RC_LEFT_BANK_1 = SPR_CSG_BEGIN + 65456,
    SPR_CLASSIC_WOODEN_RC_LEFT_BANK_2 = SPR_CSG_BEGIN + 65457,
    SPR_CLASSIC_WOODEN_RC_LEFT_BANK_3 = SPR_CSG_BEGIN + 65458,
    SPR_CLASSIC_WOODEN_RC_RIGHT_BANK_0 = SPR_CSG_BEGIN + 65459,
    SPR_CLASSIC_WOODEN_RC_RIGHT_BANK_1 = SPR_CSG_BEGIN + 65460,
    SPR_CLASSIC_WOODEN_RC_RIGHT_BANK_2 = SPR_CSG_BEGIN + 65461,
    SPR_CLASSIC_WOODEN_RC_RIGHT_BANK_3 = SPR_CSG_BEGIN + 65462,

    SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_FRONT_1 = SPR_CSG_BEGIN + 65475,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_FRONT_3 = SPR_CSG_BEGIN + 65476,

    SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_HANDRAIL_0 = SPR_CSG_BEGIN + 66203,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_HANDRAIL_1 = SPR_CSG_BEGIN + 66204,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_HANDRAIL_2 = SPR_CSG_BEGIN + 66205,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_HANDRAIL_3 = SPR_CSG_BEGIN + 66206,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_RIGHT_BANK_HANDRAIL_0 = SPR_CSG_BEGIN + 66207,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_RIGHT_BANK_HANDRAIL_1 = SPR_CSG_BEGIN + 66208,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_RIGHT_BANK_HANDRAIL_2 = SPR_CSG_BEGIN + 66209,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_RIGHT_BANK_HANDRAIL_3 = SPR_CSG_BEGIN + 66210,
    SPR_CLASSIC_WOODEN_RC_LEFT_BANK_HANDRAIL_0 = SPR_CSG_BEGIN + 66211,
    SPR_CLASSIC_WOODEN_RC_LEFT_BANK_HANDRAIL_1 = SPR_CSG_BEGIN + 66212,
    SPR_CLASSIC_WOODEN_RC_LEFT_BANK_HANDRAIL_2 = SPR_CSG_BEGIN + 66213,
    SPR_CLASSIC_WOODEN_RC_LEFT_BANK_HANDRAIL_3 = SPR_CSG_BEGIN + 66214,
    SPR_CLASSIC_WOODEN_RC_RIGHT_BANK_HANDRAIL_0 = SPR_CSG_BEGIN + 66215,
    SPR_CLASSIC_WOODEN_RC_RIGHT_BANK_HANDRAIL_1 = SPR_CSG_BEGIN + 66216,
    SPR_CLASSIC_WOODEN_RC_RIGHT_BANK_HANDRAIL_2 = SPR_CSG_BEGIN + 66217,
    SPR_CLASSIC_WOODEN_RC_RIGHT_BANK_HANDRAIL_3 = SPR_CSG_BEGIN + 66218,

    SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_FRONT_HANDRAIL_1 = SPR_CSG_BEGIN + 66231,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_FRONT_HANDRAIL_3 = SPR_CSG_BEGIN + 66232,
};

static void ClassicWoodenTwisterRCTrackFlatToLeftBank(
    PaintSession& session, const Ride& ride, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TrackElement& trackElement, SupportType supportType)
{
    static constexpr uint32_t imageIds[4][4] = {
        {
            SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_0,
            SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_HANDRAIL_0,
            0,
            0,
        },
        {
            SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_1,
            SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_HANDRAIL_1,
            SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_FRONT_1,
            SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_FRONT_HANDRAIL_1,
        },
        {
            SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_2,
            SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_HANDRAIL_2,
            0,
            0,
        },
        {
            SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_3,
            SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_HANDRAIL_3,
            SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_FRONT_3,
            SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_FRONT_HANDRAIL_3,
        },
    };

    // Straight copy from Wooden rC
    WoodenRCTrackPaint<false>(
        session, direction, imageIds[direction][0], imageIds[direction][1], { 0, 0, height },
        { { 0, 3, height }, { 32, 25, 2 } });
    if (direction == 1 || direction == 3)
    {
        WoodenRCTrackPaint<false>(
            session, direction, imageIds[direction][2], imageIds[direction][3], { 0, 0, height },
            { { 0, 26, height + 5 }, { 32, 1, 9 } });
    }
    WoodenASupportsPaintSetupRotated(
        session, supportType.wooden, WoodenSupportSubType::NeSw, direction, height, session.SupportColours);
    PaintUtilPushTunnelRotated(session, direction, height, kTunnelGroup, TunnelSubType::Flat);
    PaintUtilSetSegmentSupportHeight(session, kSegmentsAll, 0xFFFF, 0);
    PaintUtilSetGeneralSupportHeight(session, height + kDefaultGeneralSupportHeight);
}

// Stylistically, this coaster is _very_ similar to the regular Wooden Roller Coaster.
// The only difference is the degree of the banking.
// As such, all non-banked pieces are simply drawn as regular wooden roller coaster pieces.
TRACK_PAINT_FUNCTION GetTrackPaintFunctionClassicWoodenTwisterRC(int32_t trackType)
{
    if (!IsCsgLoaded())
    {
        return GetTrackPaintFunctionWoodenRC(trackType);
    }

    switch (trackType)
    {
        case TrackElemType::FlatToLeftBank:
            return ClassicWoodenTwisterRCTrackFlatToLeftBank;
        default:
            return GetTrackPaintFunctionWoodenRC(trackType);
    }
}
