/*****************************************************************************
 * Copyright (c) 2014-2020 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "WoodenRollerCoaster.hpp"

#include "../../drawing/Drawing.h"
#include "../../interface/Viewport.h"
#include "../../paint/Paint.h"
#include "../../paint/Supports.h"
#include "../../paint/tile_element/Paint.Surface.h"
#include "../../paint/tile_element/Paint.TileElement.h"
#include "../../sprites.h"
#include "../../world/Map.h"
#include "../../world/Sprite.h"
#include "../RideData.h"
#include "../TrackData.h"
#include "../TrackPaint.h"

enum {
    SPR_WOODEN_RC_FLAT_TO_LEFT_BANK_SW_NE = 23497,
    SPR_WOODEN_RC_FLAT_TO_LEFT_BANK_NW_SE = 23498,
    SPR_WOODEN_RC_FLAT_TO_LEFT_BANK_NE_SW = 23499,
    SPR_WOODEN_RC_FLAT_TO_LEFT_BANK_SE_NW = 23500,
    SPR_WOODEN_RC_FLAT_TO_RIGHT_BANK_SW_NE = 23501,
    SPR_WOODEN_RC_FLAT_TO_RIGHT_BANK_NW_SE = 23502,
    SPR_WOODEN_RC_FLAT_TO_RIGHT_BANK_NE_SW = 23503,
    SPR_WOODEN_RC_FLAT_TO_RIGHT_BANK_SE_NW = 23504,
    SPR_WOODEN_RC_LEFT_BANK_SW_NE = 23505,
    SPR_WOODEN_RC_LEFT_BANK_NW_SE = 23506,
    SPR_WOODEN_RC_LEFT_BANK_NE_SW = 23507,
    SPR_WOODEN_RC_LEFT_BANK_SE_NW = 23508,
    SPR_WOODEN_RC_25_DEG_TO_LEFT_BANK_SW_NE = 23509,
    SPR_WOODEN_RC_25_DEG_TO_LEFT_BANK_NW_SE = 23510,
    SPR_WOODEN_RC_25_DEG_TO_LEFT_BANK_NE_SW = 23511,
    SPR_WOODEN_RC_25_DEG_TO_LEFT_BANK_SE_NW = 23512,
    SPR_WOODEN_RC_25_DEG_TO_RIGHT_BANK_SW_NE = 23513,
    SPR_WOODEN_RC_25_DEG_TO_RIGHT_BANK_NW_SE = 23514,
    SPR_WOODEN_RC_25_DEG_TO_RIGHT_BANK_NE_SW = 23515,
    SPR_WOODEN_RC_25_DEG_TO_RIGHT_BANK_SE_NW = 23516,
    SPR_WOODEN_RC_LEFT_BANK_TO_25_DEG_SW_NE = 23517,
    SPR_WOODEN_RC_LEFT_BANK_TO_25_DEG_NW_SE = 23518,
    SPR_WOODEN_RC_LEFT_BANK_TO_25_DEG_NE_SW = 23519,
    SPR_WOODEN_RC_LEFT_BANK_TO_25_DEG_SE_NW = 23520,
    SPR_WOODEN_RC_RIGHT_BANK_TO_25_DEG_SW_NE = 23521,
    SPR_WOODEN_RC_RIGHT_BANK_TO_25_DEG_NW_SE = 23522,
    SPR_WOODEN_RC_RIGHT_BANK_TO_25_DEG_NE_SW = 23523,
    SPR_WOODEN_RC_RIGHT_BANK_TO_25_DEG_SE_NW = 23524,
    SPR_WOODEN_RC_RC_FLAT_TO_LEFT_BANK_FRONT_NW_SE = 23525,
    SPR_WOODEN_RC_RC_FLAT_TO_LEFT_BANK_FRONT_SE_NW = 23526,
    SPR_WOODEN_RC_RC_FLAT_TO_RIGHT_BANK_FRONT_NE_SW = 23527,
    SPR_WOODEN_RC_25_DEG_TO_LEFT_BANK_FRONT_NW_SE = 23528,
    SPR_WOODEN_RC_25_DEG_TO_LEFT_BANK_FRONT_NE_SW = 23529,
    SPR_WOODEN_RC_25_DEG_TO_RIGHT_BANK_FRONT_NW_SE = 23530,
    SPR_WOODEN_RC_25_DEG_TO_RIGHT_BANK_FRONT_NE_SW = 23531,
    SPR_WOODEN_RC_LEFT_BANK_TO_25_DEG_FRONT_NW_SE = 23532,
    SPR_WOODEN_RC_LEFT_BANK_TO_25_DEG_FRONT_NE_SW = 23533,
    SPR_WOODEN_RC_RIGHT_BANK_TO_25_DEG_FRONT_NW_SE = 23534,
    SPR_WOODEN_RC_RIGHT_BANK_TO_25_DEG_FRONT_NE_SW = 23535,
    SPR_WOODEN_RC_RC_FLAT_TO_RIGHT_BANK_FRONT_SW_NE = 23536,

    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_SW_SE_SEQ_0 = 23635,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_SW_SE_SEQ_2 = 23636,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_SW_SE_SEQ_3 = 23637,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_SW_SE_SEQ_5 = 23638,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_SW_SE_SEQ_6 = 23639,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_NW_SW_SEQ_0 = 23640,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_NW_SW_SEQ_2 = 23641,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_NW_SW_SEQ_3 = 23642,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_NW_SW_SEQ_5 = 23643,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_NW_SW_SEQ_6 = 23644,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_NE_NW_SEQ_0 = 23645,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_NE_NW_SEQ_2 = 23646,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_NE_NW_SEQ_3 = 23647,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_NE_NW_SEQ_5 = 23648,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_NE_NW_SEQ_6 = 23649,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_SE_NE_SEQ_0 = 23650,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_SE_NE_SEQ_2 = 23651,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_SE_NE_SEQ_3 = 23652,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_SE_NE_SEQ_5 = 23653,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_SE_NE_SEQ_6 = 23654,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_SW_SE_SEQ_0 = 23655,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_SW_SE_SEQ_2 = 23656,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_SW_SE_SEQ_3 = 23657,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_SW_SE_SEQ_5 = 23658,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_SW_SE_SEQ_6 = 23659,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_NE_NW_SEQ_0 = 23660,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_NE_NW_SEQ_2 = 23661,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_NE_NW_SEQ_3 = 23662,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_NE_NW_SEQ_5 = 23663,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_NE_NW_SEQ_6 = 23664,

    SPR_WOODEN_RC_FLAT_TO_LEFT_BANK_RAILS_SW_NE = 24363,
    SPR_WOODEN_RC_FLAT_TO_LEFT_BANK_RAILS_NW_SE = 24364,
    SPR_WOODEN_RC_FLAT_TO_LEFT_BANK_RAILS_NE_SW = 24365,
    SPR_WOODEN_RC_FLAT_TO_LEFT_BANK_RAILS_SE_NW = 24366,
    SPR_WOODEN_RC_FLAT_TO_RIGHT_BANK_RAILS_SW_NE = 24367,
    SPR_WOODEN_RC_FLAT_TO_RIGHT_BANK_RAILS_NW_SE = 24368,
    SPR_WOODEN_RC_FLAT_TO_RIGHT_BANK_RAILS_NE_SW = 24369,
    SPR_WOODEN_RC_FLAT_TO_RIGHT_BANK_RAILS_SE_NW = 24370,
    SPR_WOODEN_RC_LEFT_BANK_RAILS_SW_NE = 24371,
    SPR_WOODEN_RC_LEFT_BANK_RAILS_NW_SE = 24372,
    SPR_WOODEN_RC_LEFT_BANK_RAILS_NE_SW = 24373,
    SPR_WOODEN_RC_LEFT_BANK_RAILS_SE_NW = 24374,
    SPR_WOODEN_RC_25_DEG_TO_LEFT_BANK_RAILS_SW_NE = 24375,
    SPR_WOODEN_RC_25_DEG_TO_LEFT_BANK_RAILS_NW_SE = 24376,
    SPR_WOODEN_RC_25_DEG_TO_LEFT_BANK_RAILS_NE_SW = 24377,
    SPR_WOODEN_RC_25_DEG_TO_LEFT_BANK_RAILS_SE_NW = 24378,
    SPR_WOODEN_RC_25_DEG_TO_RIGHT_BANK_RAILS_SW_NE = 24379,
    SPR_WOODEN_RC_25_DEG_TO_RIGHT_BANK_RAILS_NW_SE = 24380,
    SPR_WOODEN_RC_25_DEG_TO_RIGHT_BANK_RAILS_NE_SW = 24381,
    SPR_WOODEN_RC_25_DEG_TO_RIGHT_BANK_RAILS_SE_NW = 24382,
    SPR_WOODEN_RC_LEFT_BANK_TO_25_DEG_RAILS_SW_NE = 24383,
    SPR_WOODEN_RC_LEFT_BANK_TO_25_DEG_RAILS_NW_SE = 24384,
    SPR_WOODEN_RC_LEFT_BANK_TO_25_DEG_RAILS_NE_SW = 24385,
    SPR_WOODEN_RC_LEFT_BANK_TO_25_DEG_RAILS_SE_NW = 24386,
    SPR_WOODEN_RC_RIGHT_BANK_TO_25_DEG_RAILS_SW_NE = 24387,
    SPR_WOODEN_RC_RIGHT_BANK_TO_25_DEG_RAILS_NW_SE = 24388,
    SPR_WOODEN_RC_RIGHT_BANK_TO_25_DEG_RAILS_NE_SW = 24389,
    SPR_WOODEN_RC_RIGHT_BANK_TO_25_DEG_RAILS_SE_NW = 24390,
    SPR_WOODEN_RC_RC_FLAT_TO_LEFT_BANK_RAILS_FRONT_NW_SE = 24391,
    SPR_WOODEN_RC_RC_FLAT_TO_LEFT_BANK_RAILS_FRONT_SE_NW = 24392,
    SPR_WOODEN_RC_RC_FLAT_TO_RIGHT_BANK_RAILS_FRONT_NE_SW = 24393,
    SPR_WOODEN_RC_25_DEG_TO_LEFT_BANK_RAILS_FRONT_NW_SE = 24394,
    SPR_WOODEN_RC_25_DEG_TO_LEFT_BANK_RAILS_FRONT_NE_SW = 24395,
    SPR_WOODEN_RC_25_DEG_TO_RIGHT_BANK_RAILS_FRONT_NW_SE = 24396,
    SPR_WOODEN_RC_25_DEG_TO_RIGHT_BANK_RAILS_FRONT_NE_SW = 24397,
    SPR_WOODEN_RC_LEFT_BANK_TO_25_DEG_RAILS_FRONT_NW_SE = 24398,
    SPR_WOODEN_RC_LEFT_BANK_TO_25_DEG_RAILS_FRONT_NE_SW = 24399,
    SPR_WOODEN_RC_RIGHT_BANK_TO_25_DEG_RAILS_FRONT_NW_SE = 24400,
    SPR_WOODEN_RC_RIGHT_BANK_TO_25_DEG_RAILS_FRONT_NE_SW = 24401,
    SPR_WOODEN_RC_RC_FLAT_TO_RIGHT_BANK_RAILS_FRONT_SW_NE = 24402,

    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SW_SE_SEQ_0 = 24501,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SW_SE_SEQ_2 = 24502,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SW_SE_SEQ_3 = 24503,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SW_SE_SEQ_5 = 24504,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SW_SE_SEQ_6 = 24505,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NW_SW_SEQ_0 = 24506,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NW_SW_SEQ_2 = 24507,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NW_SW_SEQ_3 = 24508,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NW_SW_SEQ_5 = 24509,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NW_SW_SEQ_6 = 24510,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NE_NW_SEQ_0 = 24511,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NE_NW_SEQ_2 = 24512,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NE_NW_SEQ_3 = 24513,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NE_NW_SEQ_5 = 24514,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NE_NW_SEQ_6 = 24515,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SE_NE_SEQ_0 = 24516,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SE_NE_SEQ_2 = 24517,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SE_NE_SEQ_3 = 24518,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SE_NE_SEQ_5 = 24519,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SE_NE_SEQ_6 = 24520,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_SW_SE_SEQ_0 = 24521,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_SW_SE_SEQ_2 = 24522,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_SW_SE_SEQ_3 = 24523,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_SW_SE_SEQ_5 = 24524,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_SW_SE_SEQ_6 = 24525,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_NE_NW_SEQ_0 = 24526,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_NE_NW_SEQ_2 = 24527,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_NE_NW_SEQ_3 = 24528,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_NE_NW_SEQ_5 = 24529,
    SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_NE_NW_SEQ_6 = 24530,
};

/** rct2: 0x008AC658 */
static void wooden_rc_track_flat_to_left_bank(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    static constexpr const uint32_t imageIds[4][4] = {
        { SPR_WOODEN_RC_FLAT_TO_LEFT_BANK_SW_NE, SPR_WOODEN_RC_FLAT_TO_LEFT_BANK_RAILS_SW_NE, 0, 0 },
        { SPR_WOODEN_RC_FLAT_TO_LEFT_BANK_NW_SE, SPR_WOODEN_RC_FLAT_TO_LEFT_BANK_RAILS_NW_SE,
          SPR_WOODEN_RC_RC_FLAT_TO_LEFT_BANK_FRONT_NW_SE, SPR_WOODEN_RC_RC_FLAT_TO_LEFT_BANK_RAILS_FRONT_NW_SE },
        { SPR_WOODEN_RC_FLAT_TO_LEFT_BANK_NE_SW, SPR_WOODEN_RC_FLAT_TO_LEFT_BANK_RAILS_NE_SW, 0, 0 },
        { SPR_WOODEN_RC_FLAT_TO_LEFT_BANK_SE_NW, SPR_WOODEN_RC_FLAT_TO_LEFT_BANK_RAILS_SE_NW,
          SPR_WOODEN_RC_RC_FLAT_TO_LEFT_BANK_FRONT_SE_NW, SPR_WOODEN_RC_RC_FLAT_TO_LEFT_BANK_RAILS_FRONT_SE_NW },
    };

    wooden_rc_track_paint<false>(
        session, imageIds[direction][0], imageIds[direction][1], direction, 0, 0, 32, 25, 2, height, 0, 3, height);
    if (direction == 1 || direction == 3)
    {
        wooden_rc_track_paint<false>(
            session, imageIds[direction][2], imageIds[direction][3], direction, 0, 0, 32, 1, 9, height, 0, 26, height + 5);
    }
    wooden_a_supports_paint_setup(session, direction & 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
    paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_FLAT);
    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 32, 0x20);
}

/** rct2: 0x008AC668 */
static void wooden_rc_track_flat_to_right_bank(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    static constexpr const uint32_t imageIds[4][4] = {
        { SPR_WOODEN_RC_FLAT_TO_RIGHT_BANK_SW_NE, SPR_WOODEN_RC_FLAT_TO_RIGHT_BANK_RAILS_SW_NE,
          SPR_WOODEN_RC_RC_FLAT_TO_RIGHT_BANK_FRONT_SW_NE, SPR_WOODEN_RC_RC_FLAT_TO_RIGHT_BANK_RAILS_FRONT_SW_NE },
        { SPR_WOODEN_RC_FLAT_TO_RIGHT_BANK_NW_SE, SPR_WOODEN_RC_FLAT_TO_RIGHT_BANK_RAILS_NW_SE, 0, 0 },
        { SPR_WOODEN_RC_FLAT_TO_RIGHT_BANK_NE_SW, SPR_WOODEN_RC_FLAT_TO_RIGHT_BANK_RAILS_NE_SW,
          SPR_WOODEN_RC_RC_FLAT_TO_RIGHT_BANK_FRONT_NE_SW, SPR_WOODEN_RC_RC_FLAT_TO_RIGHT_BANK_RAILS_FRONT_NE_SW },
        { SPR_WOODEN_RC_FLAT_TO_RIGHT_BANK_SE_NW, SPR_WOODEN_RC_FLAT_TO_RIGHT_BANK_RAILS_SE_NW, 0, 0 },
    };

    wooden_rc_track_paint<false>(
        session, imageIds[direction][0], imageIds[direction][1], direction, 0, 0, 32, 25, 2, height, 0, 3, height);
    if (direction == 0 || direction == 2)
    {
        wooden_rc_track_paint<false>(
            session, imageIds[direction][2], imageIds[direction][3], direction, 0, 0, 32, 1, 9, height, 0, 26, height + 5);
    }
    wooden_a_supports_paint_setup(session, direction & 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
    paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_FLAT);
    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 32, 0x20);
}

/** rct2: 0x008AC678 */
static void wooden_rc_track_left_bank_to_flat(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    wooden_rc_track_flat_to_right_bank(session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

/** rct2: 0x008AC688 */
static void wooden_rc_track_right_bank_to_flat(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    wooden_rc_track_flat_to_left_bank(session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

static void wooden_rc_track_banked_right_quarter_turn_5(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    static constexpr const sprite_bb_2 imageIds[2][4][7] = {
        { {
              { SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_SW_SE_SEQ_0,
                SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SW_SE_SEQ_0,
                { 0, 0, 0 },
                { 0, 2, 0 },
                { 32, 32, 2 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_SW_SE_SEQ_2,
                SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SW_SE_SEQ_2,
                { 0, 0, 0 },
                { 0, 16, 0 },
                { 32, 16, 2 } },
              { SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_SW_SE_SEQ_3,
                SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SW_SE_SEQ_3,
                { 0, 0, 0 },
                { 0, 0, 0 },
                { 16, 16, 2 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_SW_SE_SEQ_5,
                SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SW_SE_SEQ_5,
                { 0, 0, 0 },
                { 16, 0, 0 },
                { 16, 32, 2 } },
              { SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_SW_SE_SEQ_6,
                SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SW_SE_SEQ_6,
                { 0, 0, 0 },
                { 2, 0, 0 },
                { 32, 32, 2 } },
          },
          {
              { SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_NW_SW_SEQ_0,
                SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NW_SW_SEQ_0,
                { 0, 0, 0 },
                { 2, 0, 0 },
                { 32, 32, 2 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_NW_SW_SEQ_2,
                SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NW_SW_SEQ_2,
                { 0, 0, 0 },
                { 16, 0, 0 },
                { 16, 32, 2 } },
              { SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_NW_SW_SEQ_3,
                SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NW_SW_SEQ_3,
                { 0, 0, 0 },
                { 0, 16, 0 },
                { 16, 16, 2 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_NW_SW_SEQ_5,
                SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NW_SW_SEQ_5,
                { 0, 0, 0 },
                { 0, 0, 0 },
                { 32, 16, 2 } },
              { SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_NW_SW_SEQ_6,
                SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NW_SW_SEQ_6,
                { 0, 0, 0 },
                { 0, 2, 0 },
                { 32, 27, 2 } },
          },
          {
              { SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_NE_NW_SEQ_0,
                SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NE_NW_SEQ_0,
                { 0, 0, 0 },
                { 0, 2, 0 },
                { 32, 27, 2 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_NE_NW_SEQ_2,
                SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NE_NW_SEQ_2,
                { 0, 0, 0 },
                { 0, 0, 0 },
                { 32, 16, 2 } },
              { SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_NE_NW_SEQ_3,
                SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NE_NW_SEQ_3,
                { 0, 0, 0 },
                { 16, 16, 0 },
                { 16, 16, 2 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_NE_NW_SEQ_5,
                SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NE_NW_SEQ_5,
                { 0, 0, 0 },
                { 0, 0, 0 },
                { 16, 32, 2 } },
              { SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_NE_NW_SEQ_6,
                SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NE_NW_SEQ_6,
                { 0, 0, 0 },
                { 2, 0, 0 },
                { 27, 32, 2 } },
          },
          {
              { SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_SE_NE_SEQ_0,
                SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SE_NE_SEQ_0,
                { 0, 0, 0 },
                { 2, 0, 0 },
                { 27, 32, 2 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_SE_NE_SEQ_2,
                SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SE_NE_SEQ_2,
                { 0, 0, 0 },
                { 0, 0, 0 },
                { 16, 32, 2 } },
              { SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_SE_NE_SEQ_3,
                SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SE_NE_SEQ_3,
                { 0, 0, 0 },
                { 16, 0, 0 },
                { 16, 16, 2 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_SE_NE_SEQ_5,
                SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SE_NE_SEQ_5,
                { 0, 0, 0 },
                { 0, 16, 0 },
                { 32, 16, 2 } },
              { SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_SE_NE_SEQ_6,
                SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SE_NE_SEQ_6,
                { 0, 0, 0 },
                { 0, 2, 0 },
                { 32, 32, 2 } },
          } },
        { {
              { SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_SW_SE_SEQ_0,
                SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_SW_SE_SEQ_0,
                { 0, 0, 0 },
                { 0, 2, 27 },
                { 32, 32, 0 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_SW_SE_SEQ_2,
                SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_SW_SE_SEQ_2,
                { 0, 0, 0 },
                { 0, 16, 27 },
                { 32, 16, 0 } },
              { SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_SW_SE_SEQ_3,
                SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_SW_SE_SEQ_3,
                { 0, 0, 0 },
                { 0, 0, 27 },
                { 16, 16, 0 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_SW_SE_SEQ_5,
                SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_SW_SE_SEQ_5,
                { 0, 0, 0 },
                { 16, 0, 27 },
                { 16, 32, 0 } },
              { SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_SW_SE_SEQ_6,
                SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_SW_SE_SEQ_6,
                { 0, 0, 0 },
                { 2, 0, 27 },
                { 32, 32, 0 } },
          },
          {
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
          },
          {
              { SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_NE_NW_SEQ_0,
                SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_NE_NW_SEQ_0,
                { 0, 0, 0 },
                { 0, 2, 27 },
                { 32, 27, 0 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_NE_NW_SEQ_2,
                SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_NE_NW_SEQ_2,
                { 0, 0, 0 },
                { 0, 0, 27 },
                { 32, 16, 0 } },
              { SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_NE_NW_SEQ_3,
                SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_NE_NW_SEQ_3,
                { 0, 0, 0 },
                { 16, 16, 27 },
                { 16, 16, 0 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_NE_NW_SEQ_5,
                SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_NE_NW_SEQ_5,
                { 0, 0, 0 },
                { 0, 0, 27 },
                { 16, 32, 0 } },
              { SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_NE_NW_SEQ_6,
                SPR_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_NE_NW_SEQ_6,
                { 0, 0, 0 },
                { 2, 0, 27 },
                { 27, 32, 0 } },
          },
          {
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
          } },
    };
    static int8_t supportType[4][7] = {
        { 0, -1, 4, 2, -1, 4, 1 },
        { 1, -1, 5, 3, -1, 5, 0 },
        { 0, -1, 2, 4, -1, 2, 1 },
        { 1, -1, 3, 5, -1, 3, 0 },
    };

    wooden_rc_track_paint_bb<false>(session, &imageIds[0][direction][trackSequence], height);
    wooden_rc_track_paint_bb<false>(session, &imageIds[1][direction][trackSequence], height);
    track_paint_util_right_quarter_turn_5_tiles_tunnel(session, height, direction, trackSequence, TUNNEL_SQUARE_FLAT);

    if (supportType[direction][trackSequence] != -1)
    {
        wooden_a_supports_paint_setup(
            session, supportType[direction][trackSequence], 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
    }

    int32_t blockedSegments = 0;
    switch (trackSequence)
    {
        case 0:
            blockedSegments = SEGMENTS_ALL;
            break;
        case 1:
            blockedSegments = SEGMENT_B4 | SEGMENT_C8 | SEGMENT_CC;
            break;
        case 2:
            blockedSegments = SEGMENT_BC | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4;
            break;
        case 3:
            blockedSegments = SEGMENT_B4 | SEGMENT_B8 | SEGMENT_BC | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0
                | SEGMENT_D4;
            break;
        case 4:
            blockedSegments = SEGMENT_B4 | SEGMENT_C8 | SEGMENT_CC;
            break;
        case 5:
            blockedSegments = SEGMENT_B8 | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4;
            break;
        case 6:
            blockedSegments = SEGMENT_B4 | SEGMENT_B8 | SEGMENT_BC | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC
                | SEGMENT_D0 | SEGMENT_D4;
            break;
    }
    paint_util_set_segment_support_height(session, paint_util_rotate_segments(blockedSegments, direction), 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 32, 0x20);
}

static void wooden_rc_track_banked_left_quarter_turn_5(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    trackSequence = mapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence];
    wooden_rc_track_banked_right_quarter_turn_5(session, rideIndex, trackSequence, (direction + 1) & 3, height, tileElement);
}

/** rct2: 0x008AC6B8 */
static void wooden_rc_track_left_bank_to_25_deg_up(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    static constexpr const uint32_t imageIds[4][4] = {
        { SPR_WOODEN_RC_LEFT_BANK_TO_25_DEG_SW_NE, SPR_WOODEN_RC_LEFT_BANK_TO_25_DEG_RAILS_SW_NE, 0, 0 },
        { SPR_WOODEN_RC_LEFT_BANK_TO_25_DEG_NW_SE, SPR_WOODEN_RC_LEFT_BANK_TO_25_DEG_RAILS_NW_SE,
          SPR_WOODEN_RC_LEFT_BANK_TO_25_DEG_FRONT_NW_SE, SPR_WOODEN_RC_LEFT_BANK_TO_25_DEG_RAILS_FRONT_NW_SE },
        { SPR_WOODEN_RC_LEFT_BANK_TO_25_DEG_NE_SW, SPR_WOODEN_RC_LEFT_BANK_TO_25_DEG_RAILS_NE_SW,
          SPR_WOODEN_RC_LEFT_BANK_TO_25_DEG_FRONT_NE_SW, SPR_WOODEN_RC_LEFT_BANK_TO_25_DEG_RAILS_FRONT_NE_SW },
        { SPR_WOODEN_RC_LEFT_BANK_TO_25_DEG_SE_NW, SPR_WOODEN_RC_LEFT_BANK_TO_25_DEG_RAILS_SE_NW, 0, 0 },
    };

    wooden_rc_track_paint<false>(
        session, imageIds[direction][0], imageIds[direction][1], direction, 0, 0, 32, 25, 2, height, 0, 3, height);
    if (direction == 1 || direction == 2)
    {
        wooden_rc_track_paint<false>(
            session, imageIds[direction][2], imageIds[direction][3], direction, 0, 0, 32, 1, 9, height, 0, 26, height + 5);
    }
    wooden_a_supports_paint_setup(
        session, direction & 1, 1 + direction, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
    if (direction == 0 || direction == 3)
    {
        paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_FLAT);
    }
    else
    {
        paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_8);
    }
    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 48, 0x20);
}

/** rct2: 0x008AC6C8 */
static void wooden_rc_track_right_bank_to_25_deg_up(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    static constexpr const uint32_t imageIds[4][4] = {
        { SPR_WOODEN_RC_RIGHT_BANK_TO_25_DEG_SW_NE, SPR_WOODEN_RC_RIGHT_BANK_TO_25_DEG_RAILS_SW_NE, 0, 0 },
        { SPR_WOODEN_RC_RIGHT_BANK_TO_25_DEG_NW_SE, SPR_WOODEN_RC_RIGHT_BANK_TO_25_DEG_RAILS_NW_SE,
          SPR_WOODEN_RC_RIGHT_BANK_TO_25_DEG_FRONT_NW_SE, SPR_WOODEN_RC_RIGHT_BANK_TO_25_DEG_RAILS_FRONT_NW_SE },
        { SPR_WOODEN_RC_RIGHT_BANK_TO_25_DEG_NE_SW, SPR_WOODEN_RC_RIGHT_BANK_TO_25_DEG_RAILS_NE_SW,
          SPR_WOODEN_RC_RIGHT_BANK_TO_25_DEG_FRONT_NE_SW, SPR_WOODEN_RC_RIGHT_BANK_TO_25_DEG_RAILS_FRONT_NE_SW },
        { SPR_WOODEN_RC_RIGHT_BANK_TO_25_DEG_SE_NW, SPR_WOODEN_RC_RIGHT_BANK_TO_25_DEG_RAILS_SE_NW, 0, 0 },
    };

    wooden_rc_track_paint<false>(
        session, imageIds[direction][0], imageIds[direction][1], direction, 0, 0, 32, 25, 2, height, 0, 3, height);
    if (direction == 1 || direction == 2)
    {
        wooden_rc_track_paint<false>(
            session, imageIds[direction][2], imageIds[direction][3], direction, 0, 0, 32, 1, 9, height, 0, 26, height + 5);
    }
    wooden_a_supports_paint_setup(
        session, direction & 1, 1 + direction, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
    if (direction == 0 || direction == 3)
    {
        paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_FLAT);
    }
    else
    {
        paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_8);
    }
    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 48, 0x20);
}

/** rct2: 0x008AC6D8 */
static void wooden_rc_track_25_deg_up_to_left_bank(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    static constexpr const uint32_t imageIds[4][4] = {
        { SPR_WOODEN_RC_25_DEG_TO_LEFT_BANK_SW_NE, SPR_WOODEN_RC_25_DEG_TO_LEFT_BANK_RAILS_SW_NE, 0, 0 },
        { SPR_WOODEN_RC_25_DEG_TO_LEFT_BANK_NW_SE, SPR_WOODEN_RC_25_DEG_TO_LEFT_BANK_RAILS_NW_SE,
          SPR_WOODEN_RC_25_DEG_TO_LEFT_BANK_FRONT_NW_SE, SPR_WOODEN_RC_25_DEG_TO_LEFT_BANK_RAILS_FRONT_NW_SE },
        { SPR_WOODEN_RC_25_DEG_TO_LEFT_BANK_NE_SW, SPR_WOODEN_RC_25_DEG_TO_LEFT_BANK_RAILS_NE_SW,
          SPR_WOODEN_RC_25_DEG_TO_LEFT_BANK_FRONT_NE_SW, SPR_WOODEN_RC_25_DEG_TO_LEFT_BANK_RAILS_FRONT_NE_SW },
        { SPR_WOODEN_RC_25_DEG_TO_LEFT_BANK_SE_NW, SPR_WOODEN_RC_25_DEG_TO_LEFT_BANK_RAILS_SE_NW, 0, 0 },
    };

    wooden_rc_track_paint<false>(
        session, imageIds[direction][0], imageIds[direction][1], direction, 0, 0, 32, 25, 2, height, 0, 3, height);
    if (direction == 1 || direction == 2)
    {
        wooden_rc_track_paint<false>(
            session, imageIds[direction][2], imageIds[direction][3], direction, 0, 0, 32, 1, 9, height, 0, 26, height + 5);
    }
    wooden_a_supports_paint_setup(
        session, direction & 1, 5 + direction, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
    if (direction == 0 || direction == 3)
    {
        paint_util_push_tunnel_rotated(session, direction, height - 8, TUNNEL_SQUARE_FLAT);
    }
    else
    {
        paint_util_push_tunnel_rotated(session, direction, height + 8, TUNNEL_14);
    }
    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 40, 0x20);
}

/** rct2: 0x008AC6E8 */
static void wooden_rc_track_25_deg_up_to_right_bank(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    static constexpr const uint32_t imageIds[4][4] = {
        { SPR_WOODEN_RC_25_DEG_TO_RIGHT_BANK_SW_NE, SPR_WOODEN_RC_25_DEG_TO_RIGHT_BANK_RAILS_SW_NE, 0, 0 },
        { SPR_WOODEN_RC_25_DEG_TO_RIGHT_BANK_NW_SE, SPR_WOODEN_RC_25_DEG_TO_RIGHT_BANK_RAILS_NW_SE,
          SPR_WOODEN_RC_25_DEG_TO_RIGHT_BANK_FRONT_NW_SE, SPR_WOODEN_RC_25_DEG_TO_RIGHT_BANK_RAILS_FRONT_NW_SE },
        { SPR_WOODEN_RC_25_DEG_TO_RIGHT_BANK_NE_SW, SPR_WOODEN_RC_25_DEG_TO_RIGHT_BANK_RAILS_NE_SW,
          SPR_WOODEN_RC_25_DEG_TO_RIGHT_BANK_FRONT_NE_SW, SPR_WOODEN_RC_25_DEG_TO_RIGHT_BANK_RAILS_FRONT_NE_SW },
        { SPR_WOODEN_RC_25_DEG_TO_RIGHT_BANK_SE_NW, SPR_WOODEN_RC_25_DEG_TO_RIGHT_BANK_RAILS_SE_NW, 0, 0 },
    };

    wooden_rc_track_paint<false>(
        session, imageIds[direction][0], imageIds[direction][1], direction, 0, 0, 32, 25, 2, height, 0, 3, height);
    if (direction == 1 || direction == 2)
    {
        wooden_rc_track_paint<false>(
            session, imageIds[direction][2], imageIds[direction][3], direction, 0, 0, 32, 1, 9, height, 0, 26, height + 5);
    }
    wooden_a_supports_paint_setup(
        session, direction & 1, 5 + direction, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
    if (direction == 0 || direction == 3)
    {
        paint_util_push_tunnel_rotated(session, direction, height - 8, TUNNEL_SQUARE_FLAT);
    }
    else
    {
        paint_util_push_tunnel_rotated(session, direction, height + 8, TUNNEL_14);
    }
    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 40, 0x20);
}

/** rct2: 0x008AC6F8 */
static void wooden_rc_track_left_bank_to_25_deg_down(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    wooden_rc_track_25_deg_up_to_right_bank(session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

/** rct2: 0x008AC708 */
static void wooden_rc_track_right_bank_to_25_deg_down(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    wooden_rc_track_25_deg_up_to_left_bank(session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

/** rct2: 0x008AC718 */
static void wooden_rc_track_25_deg_down_to_left_bank(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    wooden_rc_track_right_bank_to_25_deg_up(session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

/** rct2: 0x008AC728 */
static void wooden_rc_track_25_deg_down_to_right_bank(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    wooden_rc_track_left_bank_to_25_deg_up(session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

/** rct2: 0x008AC738 */
static void wooden_rc_track_left_bank(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    static constexpr const uint32_t imageIds[4][2] = {
        { SPR_WOODEN_RC_LEFT_BANK_SW_NE, SPR_WOODEN_RC_LEFT_BANK_RAILS_SW_NE },
        { SPR_WOODEN_RC_LEFT_BANK_NW_SE, SPR_WOODEN_RC_LEFT_BANK_RAILS_NW_SE },
        { SPR_WOODEN_RC_LEFT_BANK_NE_SW, SPR_WOODEN_RC_LEFT_BANK_RAILS_NE_SW },
        { SPR_WOODEN_RC_LEFT_BANK_SE_NW, SPR_WOODEN_RC_LEFT_BANK_RAILS_SE_NW },
    };

    wooden_rc_track_paint<false>(
        session, imageIds[direction][0], imageIds[direction][1], direction, 0, 0, 32, 25, 2, height, 0, 3, height);
    wooden_a_supports_paint_setup(session, direction & 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
    paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_FLAT);
    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 32, 0x20);
}

/** rct2: 0x008AC748 */
static void wooden_rc_track_right_bank(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    wooden_rc_track_left_bank(session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

/** rct2: 0x008AC808 */
static void wooden_rc_track_left_quarter_turn_3_bank(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23846, 0, 0, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24712, 0, 0, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23849, 0, 0, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24715, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23858, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24724, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23852, 0, 0, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24718, 0, 0, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23843, 0, 0, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24709, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23855, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24721, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            if (direction == 0 || direction == 3)
            {
                paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_FLAT);
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 1:
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 2:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23845, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24711, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23848, 0, 0, 16, 16, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24714, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23857, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24723, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23851, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24717, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23842, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24708, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23854, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24720, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 27);
                    break;
            }
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23844, 0, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24710, 0, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23847, 0, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24713, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23856, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24722, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23850, 0, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24716, 0, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23841, 0, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24707, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23853, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24719, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            switch (direction)
            {
                case 2:
                    paint_util_push_tunnel_right(session, height, TUNNEL_SQUARE_FLAT);
                    break;
                case 3:
                    paint_util_push_tunnel_left(session, height, TUNNEL_SQUARE_FLAT);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
    }
}

/** rct2: 0x008AC818 */
static void wooden_rc_track_right_quarter_turn_3_bank(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    trackSequence = mapLeftQuarterTurn3TilesToRightQuarterTurn3Tiles[trackSequence];
    wooden_rc_track_left_quarter_turn_3_bank(session, rideIndex, trackSequence, (direction - 1) & 3, height, tileElement);
}

/** rct2: 0x008ACAB8 */
static void wooden_rc_track_left_half_banked_helix_up_small(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23882, 0, 0, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24748, 0, 0, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23885, 0, 0, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24751, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23894, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24760, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23888, 0, 0, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24754, 0, 0, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23879, 0, 0, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24745, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23891, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24757, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            if (direction == 0 || direction == 3)
            {
                paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_FLAT);
            }
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_BC | SEGMENT_C0 | SEGMENT_D4, direction), 48, 0x20);
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 1:
            switch (direction)
            {
                case 0:
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 2:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23881, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24747, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23884, 0, 0, 16, 16, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24750, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23893, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24759, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23887, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24753, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23878, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24744, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23890, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24756, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 27);
                    break;
            }
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23880, 0, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24746, 0, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23883, 0, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24749, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23892, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24758, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23886, 0, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24752, 0, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23877, 0, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24743, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23889, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24755, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            switch (direction)
            {
                case 2:
                    paint_util_push_tunnel_right(session, height + 8, TUNNEL_SQUARE_FLAT);
                    break;
                case 3:
                    paint_util_push_tunnel_left(session, height + 8, TUNNEL_SQUARE_FLAT);
                    break;
            }
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_B8 | SEGMENT_BC | SEGMENT_CC, direction), 48, 0x20);
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 4:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23879, 0, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24745, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23891, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24757, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23882, 0, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24748, 0, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23885, 0, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24751, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23894, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24760, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23888, 0, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24754, 0, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            switch (direction)
            {
                case 0:
                    paint_util_push_tunnel_right(session, height, TUNNEL_SQUARE_FLAT);
                    break;
                case 1:
                    paint_util_push_tunnel_left(session, height, TUNNEL_SQUARE_FLAT);
                    break;
            }
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_BC | SEGMENT_C0 | SEGMENT_CC, direction), 48, 0x20);
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 5:
            switch (direction)
            {
                case 0:
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 6:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23878, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24744, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23890, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24756, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 27);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23881, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24747, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23884, 0, 0, 16, 16, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24750, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23893, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24759, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23887, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24753, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 7:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23877, 0, 0, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24743, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23889, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24755, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23880, 0, 0, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24746, 0, 0, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23883, 0, 0, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24749, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23892, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24758, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23886, 0, 0, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24752, 0, 0, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            if (direction == 0 || direction == 3)
            {
                paint_util_push_tunnel_rotated(session, direction, height + 8, TUNNEL_SQUARE_FLAT);
            }
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C0 | SEGMENT_C8, direction), 48, 0x20);
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
    }
}

/** rct2: 0x008ACAC8 */
static void wooden_rc_track_right_half_banked_helix_up_small(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23859, 0, 0, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24725, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23871, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24737, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23862, 0, 0, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24728, 0, 0, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23865, 0, 0, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24731, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23874, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24740, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23868, 0, 0, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24734, 0, 0, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            if (direction == 0 || direction == 3)
            {
                paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_FLAT);
            }
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C0 | SEGMENT_C8, direction), 48, 0x20);
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 1:
            switch (direction)
            {
                case 0:
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 2:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23860, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24726, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23872, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24738, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 27);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23863, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24729, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23866, 0, 0, 16, 16, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24732, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23875, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24741, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23869, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24735, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23861, 0, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24727, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23873, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24739, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23864, 0, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24730, 0, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23867, 0, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24733, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23876, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24742, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23870, 0, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24736, 0, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            switch (direction)
            {
                case 0:
                    paint_util_push_tunnel_right(session, height + 8, TUNNEL_SQUARE_FLAT);
                    break;
                case 1:
                    paint_util_push_tunnel_left(session, height + 8, TUNNEL_SQUARE_FLAT);
                    break;
            }
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_BC | SEGMENT_C0 | SEGMENT_CC, direction), 48, 0x20);
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 4:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23862, 0, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24728, 0, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23865, 0, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24731, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23874, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24740, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23868, 0, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24734, 0, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23859, 0, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24725, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23871, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24737, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            switch (direction)
            {
                case 2:
                    paint_util_push_tunnel_right(session, height, TUNNEL_SQUARE_FLAT);
                    break;
                case 3:
                    paint_util_push_tunnel_left(session, height, TUNNEL_SQUARE_FLAT);
                    break;
            }
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_B8 | SEGMENT_BC | SEGMENT_CC, direction), 48, 0x20);
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 5:
            switch (direction)
            {
                case 0:
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 6:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23863, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24729, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23866, 0, 0, 16, 16, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24732, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23875, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24741, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23869, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24735, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23860, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24726, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23872, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24738, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 27);
                    break;
            }
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 7:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23864, 0, 0, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24730, 0, 0, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23867, 0, 0, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24733, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23876, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24742, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23870, 0, 0, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24736, 0, 0, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23861, 0, 0, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24727, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23873, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24739, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            if (direction == 0 || direction == 3)
            {
                paint_util_push_tunnel_rotated(session, direction, height + 8, TUNNEL_SQUARE_FLAT);
            }
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_BC | SEGMENT_C0 | SEGMENT_D4, direction), 48, 0x20);
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
    }
}

/** rct2: 0x008ACAD8 */
static void wooden_rc_track_left_half_banked_helix_down_small(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    if (trackSequence >= 4)
    {
        trackSequence -= 4;
        direction = (direction - 1) & 3;
    }
    trackSequence = mapLeftQuarterTurn3TilesToRightQuarterTurn3Tiles[trackSequence];
    wooden_rc_track_right_half_banked_helix_up_small(
        session, rideIndex, trackSequence, (direction + 1) & 3, height, tileElement);
}

/** rct2: 0x008ACAE8 */
static void wooden_rc_track_right_half_banked_helix_down_small(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    if (trackSequence >= 4)
    {
        trackSequence -= 4;
        direction = (direction + 1) & 3;
    }
    trackSequence = mapLeftQuarterTurn3TilesToRightQuarterTurn3Tiles[trackSequence];
    wooden_rc_track_left_half_banked_helix_up_small(
        session, rideIndex, trackSequence, (direction - 1) & 3, height, tileElement);
}

/** rct2: 0x008ACAF8 */
static void wooden_rc_track_left_half_banked_helix_up_large(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23704, 0, 0, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24570, 0, 0, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23709, 0, 0, 32, 27, 2, height, 0, 2,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24575, 0, 0, 32, 27, 2, height, 0, 2, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23724, 0, 0, 32, 27, 0, height, 0, 2,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24590, 0, 0, 32, 27, 0, height, 0, 2,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23714, 0, 0, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24580, 0, 0, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23699, 0, 0, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24565, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23719, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24585, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            if (direction == 0 || direction == 3)
            {
                paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_FLAT);
            }
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_BC | SEGMENT_C0 | SEGMENT_D4, direction), 48, 0x20);
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 1:
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_BC | SEGMENT_CC | SEGMENT_D4, direction), 48, 0x20);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 2:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23703, 0, 0, 32, 16, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24569, 0, 0, 32, 16, 2, height, 0, 0, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23708, 0, 0, 32, 16, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24574, 0, 0, 32, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23723, 0, 0, 32, 16, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24589, 0, 0, 32, 16, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23713, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24579, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23698, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24564, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23718, 0, 0, 32, 16, 0, height, 0, 16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24584, 0, 0, 32, 16, 0, height, 0, 16,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(
                session,
                paint_util_rotate_segments(
                    SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23702, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24568, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23707, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24573, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23722, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 29);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24588, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 29);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23712, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24578, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23697, 0, 0, 16, 16, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24563, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23717, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24583, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C0 | SEGMENT_C8 | SEGMENT_D0, direction), 48, 0x20);
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 4:
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_BC | SEGMENT_CC | SEGMENT_D4, direction), 48, 0x20);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 5:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23701, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24567, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23706, 0, 0, 16, 32, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24572, 0, 0, 16, 32, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23721, 0, 0, 16, 32, 0, height, 0, 0,
                        height + 33);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24587, 0, 0, 16, 32, 0, height, 0, 0,
                        height + 33);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23711, 0, 0, 16, 32, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24577, 0, 0, 16, 32, 2, height, 0, 0, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23696, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24562, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23716, 0, 0, 16, 32, 0, height, 16, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24582, 0, 0, 16, 32, 0, height, 16, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(
                session,
                paint_util_rotate_segments(
                    SEGMENT_B8 | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 6:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23700, 0, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24566, 0, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23705, 0, 0, 27, 32, 2, height, 2, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24571, 0, 0, 27, 32, 2, height, 2, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23720, 0, 0, 27, 32, 0, height, 2, 0,
                        height + 33);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24586, 0, 0, 27, 32, 0, height, 2, 0,
                        height + 33);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23710, 0, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24576, 0, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23695, 0, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24561, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23715, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24581, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            switch (direction)
            {
                case 2:
                    paint_util_push_tunnel_right(session, height + 8, TUNNEL_SQUARE_FLAT);
                    break;
                case 3:
                    paint_util_push_tunnel_left(session, height + 8, TUNNEL_SQUARE_FLAT);
                    break;
            }
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_B8 | SEGMENT_BC | SEGMENT_CC, direction), 48, 0x20);
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 7:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23699, 0, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24565, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23719, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24585, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23704, 0, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24570, 0, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23709, 0, 0, 27, 32, 2, height, 2, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24575, 0, 0, 27, 32, 2, height, 2, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23724, 0, 0, 27, 32, 0, height, 2, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24590, 0, 0, 27, 32, 0, height, 2, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23714, 0, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24580, 0, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            switch (direction)
            {
                case 0:
                    paint_util_push_tunnel_right(session, height, TUNNEL_SQUARE_FLAT);
                    break;
                case 1:
                    paint_util_push_tunnel_left(session, height, TUNNEL_SQUARE_FLAT);
                    break;
            }
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_BC | SEGMENT_C0 | SEGMENT_CC, direction), 48, 0x20);
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 8:
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C8 | SEGMENT_CC, direction), 48, 0x20);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 9:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23698, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24564, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23718, 0, 0, 16, 32, 0, height, 16, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24584, 0, 0, 16, 32, 0, height, 16, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23703, 0, 0, 16, 32, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24569, 0, 0, 16, 32, 2, height, 0, 0, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23708, 0, 0, 16, 32, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24574, 0, 0, 16, 32, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23723, 0, 0, 16, 32, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24589, 0, 0, 16, 32, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23713, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24579, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(
                session,
                paint_util_rotate_segments(
                    SEGMENT_B8 | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 10:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23697, 0, 0, 16, 16, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24563, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23717, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24583, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23702, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24568, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23707, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24573, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23722, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 29);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24588, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 29);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23712, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24578, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_BC | SEGMENT_D0 | SEGMENT_D4, direction), 48, 0x20);
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 11:
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C8 | SEGMENT_CC, direction), 48, 0x20);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 12:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23696, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24562, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23716, 0, 0, 32, 16, 0, height, 0, 16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24582, 0, 0, 32, 16, 0, height, 0, 16,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23701, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24567, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23706, 0, 0, 32, 16, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24572, 0, 0, 32, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23721, 0, 0, 32, 16, 0, height, 0, 0,
                        height + 33);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24587, 0, 0, 32, 16, 0, height, 0, 0,
                        height + 33);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23711, 0, 0, 32, 16, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24577, 0, 0, 32, 16, 2, height, 0, 0, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(
                session,
                paint_util_rotate_segments(
                    SEGMENT_BC | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 13:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23695, 0, 0, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24561, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23715, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24581, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23700, 0, 0, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24566, 0, 0, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23705, 0, 0, 32, 27, 2, height, 0, 2,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24571, 0, 0, 32, 27, 2, height, 0, 2, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23720, 0, 0, 32, 27, 0, height, 0, 2,
                        height + 33);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24586, 0, 0, 32, 27, 0, height, 0, 2,
                        height + 33);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23710, 0, 0, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24576, 0, 0, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            if (direction == 0 || direction == 3)
            {
                paint_util_push_tunnel_rotated(session, direction, height + 8, TUNNEL_SQUARE_FLAT);
            }
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C0 | SEGMENT_C8, direction), 48, 0x20);
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
    }
}

/** rct2: 0x008ACB08 */
static void wooden_rc_track_right_half_banked_helix_up_large(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23665, 0, 0, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24531, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23685, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24551, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23670, 0, 0, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24536, 0, 0, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23675, 0, 0, 32, 27, 2, height, 0, 2,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24541, 0, 0, 32, 27, 2, height, 0, 2, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23690, 0, 0, 32, 27, 0, height, 0, 2,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24556, 0, 0, 32, 27, 0, height, 0, 2,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23680, 0, 0, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24546, 0, 0, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            if (direction == 0 || direction == 3)
            {
                paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_FLAT);
            }
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C0 | SEGMENT_C8, direction), 48, 0x20);
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 1:
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C8 | SEGMENT_CC, direction), 48, 0x20);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 2:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23666, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24532, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23686, 0, 0, 32, 16, 0, height, 0, 16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24552, 0, 0, 32, 16, 0, height, 0, 16,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23671, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24537, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23676, 0, 0, 32, 16, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24542, 0, 0, 32, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23691, 0, 0, 32, 16, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24557, 0, 0, 32, 16, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23681, 0, 0, 32, 16, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24547, 0, 0, 32, 16, 2, height, 0, 0, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(
                session,
                paint_util_rotate_segments(
                    SEGMENT_BC | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23667, 0, 0, 16, 16, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24533, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23687, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24553, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23672, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24538, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23677, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24543, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23692, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 29);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24558, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 29);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23682, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24548, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_BC | SEGMENT_D0 | SEGMENT_D4, direction), 48, 0x20);
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 4:
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C8 | SEGMENT_CC, direction), 48, 0x20);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 5:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23668, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24534, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23688, 0, 0, 16, 32, 0, height, 16, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24554, 0, 0, 16, 32, 0, height, 16, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23673, 0, 0, 16, 32, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24539, 0, 0, 16, 32, 2, height, 0, 0, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23678, 0, 0, 16, 32, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24544, 0, 0, 16, 32, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23693, 0, 0, 16, 32, 0, height, 0, 0,
                        height + 33);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24559, 0, 0, 16, 32, 0, height, 0, 0,
                        height + 33);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23683, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24549, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(
                session,
                paint_util_rotate_segments(
                    SEGMENT_B8 | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 6:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23669, 0, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24535, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23689, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24555, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23674, 0, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24540, 0, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23679, 0, 0, 27, 32, 2, height, 2, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24545, 0, 0, 27, 32, 2, height, 2, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23694, 0, 0, 27, 32, 0, height, 2, 0,
                        height + 33);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24560, 0, 0, 27, 32, 0, height, 2, 0,
                        height + 33);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23684, 0, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24550, 0, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            switch (direction)
            {
                case 0:
                    paint_util_push_tunnel_right(session, height + 8, TUNNEL_SQUARE_FLAT);
                    break;
                case 1:
                    paint_util_push_tunnel_left(session, height + 8, TUNNEL_SQUARE_FLAT);
                    break;
            }
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_BC | SEGMENT_C0 | SEGMENT_CC, direction), 48, 0x20);
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 7:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23670, 0, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24536, 0, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23675, 0, 0, 27, 32, 2, height, 2, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24541, 0, 0, 27, 32, 2, height, 2, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23690, 0, 0, 27, 32, 0, height, 2, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24556, 0, 0, 27, 32, 0, height, 2, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23680, 0, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24546, 0, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23665, 0, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24531, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23685, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24551, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            switch (direction)
            {
                case 2:
                    paint_util_push_tunnel_right(session, height, TUNNEL_SQUARE_FLAT);
                    break;
                case 3:
                    paint_util_push_tunnel_left(session, height, TUNNEL_SQUARE_FLAT);
                    break;
            }
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_B8 | SEGMENT_BC | SEGMENT_CC, direction), 48, 0x20);
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 8:
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_BC | SEGMENT_CC | SEGMENT_D4, direction), 48, 0x20);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 9:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23671, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24537, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23676, 0, 0, 16, 32, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24542, 0, 0, 16, 32, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23691, 0, 0, 16, 32, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24557, 0, 0, 16, 32, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23681, 0, 0, 16, 32, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24547, 0, 0, 16, 32, 2, height, 0, 0, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23666, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24532, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23686, 0, 0, 16, 32, 0, height, 16, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24552, 0, 0, 16, 32, 0, height, 16, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(
                session,
                paint_util_rotate_segments(
                    SEGMENT_B8 | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 10:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23672, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24538, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23677, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24543, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23692, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 29);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24558, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 29);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23682, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24548, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23667, 0, 0, 16, 16, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24533, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23687, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24553, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C0 | SEGMENT_C8 | SEGMENT_D0, direction), 48, 0x20);
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 11:
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_BC | SEGMENT_CC | SEGMENT_D4, direction), 48, 0x20);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 12:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23673, 0, 0, 32, 16, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24539, 0, 0, 32, 16, 2, height, 0, 0, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23678, 0, 0, 32, 16, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24544, 0, 0, 32, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23693, 0, 0, 32, 16, 0, height, 0, 0,
                        height + 33);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24559, 0, 0, 32, 16, 0, height, 0, 0,
                        height + 33);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23683, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24549, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23668, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24534, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23688, 0, 0, 32, 16, 0, height, 0, 16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24554, 0, 0, 32, 16, 0, height, 0, 16,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(
                session,
                paint_util_rotate_segments(
                    SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 13:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23674, 0, 0, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24540, 0, 0, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23679, 0, 0, 32, 27, 2, height, 0, 2,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24545, 0, 0, 32, 27, 2, height, 0, 2, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23694, 0, 0, 32, 27, 0, height, 0, 2,
                        height + 33);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24560, 0, 0, 32, 27, 0, height, 0, 2,
                        height + 33);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23684, 0, 0, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24550, 0, 0, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23669, 0, 0, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24535, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23689, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24555, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            if (direction == 0 || direction == 3)
            {
                paint_util_push_tunnel_rotated(session, direction, height + 8, TUNNEL_SQUARE_FLAT);
            }
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_BC | SEGMENT_C0 | SEGMENT_D4, direction), 48, 0x20);
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
    }
}

/** rct2: 0x008ACB18 */
static void wooden_rc_track_left_half_banked_helix_down_large(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    if (trackSequence >= 7)
    {
        trackSequence -= 7;
        direction = (direction - 1) & 3;
    }
    trackSequence = mapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence];
    wooden_rc_track_right_half_banked_helix_up_large(
        session, rideIndex, trackSequence, (direction + 1) & 3, height, tileElement);
}

/** rct2: 0x008ACB28 */
static void wooden_rc_track_right_half_banked_helix_down_large(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    if (trackSequence >= 7)
    {
        trackSequence -= 7;
        direction = (direction + 1) & 3;
    }
    trackSequence = mapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence];
    wooden_rc_track_left_half_banked_helix_up_large(
        session, rideIndex, trackSequence, (direction - 1) & 3, height, tileElement);
}

/** rct2: 0x008ACC78 */
static void wooden_rc_track_25_deg_up_left_banked(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (direction)
    {
        case 0:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24249, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25115, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 0, 9, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 1:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24250, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25116, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24257, 0, 0, 32, 1, 9, height, 0, 26,
                height + 5);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25123, 0, 0, 32, 1, 9, height, 0, 26, height + 5);
            wooden_a_supports_paint_setup(session, 1, 10, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 2:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24251, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25117, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24258, 0, 0, 32, 1, 9, height, 0, 26,
                height + 5);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25124, 0, 0, 32, 1, 9, height, 0, 26, height + 5);
            wooden_a_supports_paint_setup(session, 0, 11, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 3:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24252, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25118, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 1, 12, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
    }
    if (direction == 0 || direction == 3)
    {
        paint_util_push_tunnel_rotated(session, direction, height - 8, TUNNEL_SQUARE_7);
    }
    else
    {
        paint_util_push_tunnel_rotated(session, direction, height + 8, TUNNEL_SQUARE_8);
    }
    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 56, 0x20);
}

/** rct2: 0x008ACC88 */
static void wooden_rc_track_25_deg_up_right_banked(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (direction)
    {
        case 0:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24253, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25119, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 0, 9, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 1:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24254, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25120, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24259, 0, 0, 32, 1, 9, height, 0, 26,
                height + 5);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25125, 0, 0, 32, 1, 9, height, 0, 26, height + 5);
            wooden_a_supports_paint_setup(session, 1, 10, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 2:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24255, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25121, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24260, 0, 0, 32, 1, 9, height, 0, 26,
                height + 5);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25126, 0, 0, 32, 1, 9, height, 0, 26, height + 5);
            wooden_a_supports_paint_setup(session, 0, 11, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 3:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24256, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25122, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 1, 12, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
    }
    if (direction == 0 || direction == 3)
    {
        paint_util_push_tunnel_rotated(session, direction, height - 8, TUNNEL_SQUARE_7);
    }
    else
    {
        paint_util_push_tunnel_rotated(session, direction, height + 8, TUNNEL_SQUARE_8);
    }
    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 56, 0x20);
}

/** rct2: 0x008ACC98 */
static void wooden_rc_track_25_deg_down_left_banked(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    wooden_rc_track_25_deg_up_right_banked(session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

/** rct2: 0x008ACCA8 */
static void wooden_rc_track_25_deg_down_right_banked(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    wooden_rc_track_25_deg_up_left_banked(session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

/** rct2: 0x008AC998 */
static void wooden_rc_track_left_eighth_bank_to_diag(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24185, 0, 0, 32, 32, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25051, 0, 0, 32, 32, 2, height, 0, 0, height);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24189, 0, 0, 32, 32, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25055, 0, 0, 32, 32, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24201, 0, 0, 32, 32, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25067, 0, 0, 32, 32, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24193, 0, 0, 32, 32, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25059, 0, 0, 32, 32, 2, height, 0, 0, height);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24197, 0, 0, 32, 32, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25063, 0, 0, 32, 32, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24205, 0, 0, 32, 32, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25071, 0, 0, 32, 32, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            if (direction == 0 || direction == 3)
            {
                paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_FLAT);
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 1:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24186, 0, 0, 32, 16, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25052, 0, 0, 32, 16, 2, height, 0, 0, height);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24190, 0, 0, 34, 16, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25056, 0, 0, 34, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24202, 0, 0, 32, 16, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25068, 0, 0, 32, 16, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24194, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25060, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24198, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25064, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24206, 0, 0, 32, 16, 0, height, 0, 16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25072, 0, 0, 32, 16, 0, height, 0, 16,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 2:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24187, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25053, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24191, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25057, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24203, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25069, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24195, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25061, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24199, 0, 0, 16, 16, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25065, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24207, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25073, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 0:
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 4:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24188, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25054, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24192, 0, 0, 16, 18, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25058, 0, 0, 16, 18, 2, height, 0, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24204, 0, 0, 16, 16, 0, height, 0, 16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25070, 0, 0, 16, 16, 0, height, 0, 16,
                        height + 27);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24196, 0, 0, 16, 16, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25062, 0, 0, 16, 16, 2, height, 0, 0, height);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24200, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25066, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24208, 0, 0, 16, 16, 0, height, 16, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25074, 0, 0, 16, 16, 0, height, 16, 0,
                        height + 27);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
    }
}

/** rct2: 0x008AC9A8 */
static void wooden_rc_track_right_eighth_bank_to_diag(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24161, 0, 0, 32, 32, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25027, 0, 0, 32, 32, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24177, 0, 0, 32, 32, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25043, 0, 0, 32, 32, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24165, 0, 0, 32, 32, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25031, 0, 0, 32, 32, 2, height, 0, 0, height);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24169, 0, 0, 32, 32, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25035, 0, 0, 32, 32, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24181, 0, 0, 32, 32, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25047, 0, 0, 32, 32, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24173, 0, 0, 32, 32, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25039, 0, 0, 32, 32, 2, height, 0, 0, height);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            if (direction == 0 || direction == 3)
            {
                paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_FLAT);
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 1:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24162, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25028, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24178, 0, 0, 32, 16, 0, height, 0, 16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25044, 0, 0, 32, 16, 0, height, 0, 16,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24166, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25032, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24170, 0, 0, 34, 16, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25036, 0, 0, 34, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24182, 0, 0, 32, 16, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25048, 0, 0, 32, 16, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24174, 0, 0, 32, 16, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25040, 0, 0, 32, 16, 2, height, 0, 0, height);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 2:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24163, 0, 0, 16, 16, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25029, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24179, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25045, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24167, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25033, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24171, 0, 0, 28, 28, 2, height, 4, 4,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25037, 0, 0, 28, 28, 2, height, 4, 4, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24183, 0, 0, 28, 28, 0, height, 4, 4,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25049, 0, 0, 28, 28, 0, height, 4, 4,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24175, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25041, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 0:
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 4:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24164, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25030, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24180, 0, 0, 16, 16, 0, height, 16, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25046, 0, 0, 16, 16, 0, height, 16, 0,
                        height + 27);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24168, 0, 0, 16, 16, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25034, 0, 0, 16, 16, 2, height, 0, 0, height);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24172, 0, 0, 16, 18, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25038, 0, 0, 16, 18, 2, height, 0, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24184, 0, 0, 16, 16, 0, height, 0, 16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25050, 0, 0, 16, 16, 0, height, 0, 16,
                        height + 27);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24176, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25042, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
    }
}

/** rct2: 0x008AC9B8 */
static void wooden_rc_track_left_eighth_bank_to_orthogonal(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    trackSequence = mapLeftEighthTurnToOrthogonal[trackSequence];
    wooden_rc_track_right_eighth_bank_to_diag(session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

/** rct2: 0x008AC9C8 */
static void wooden_rc_track_right_eighth_bank_to_orthogonal(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    trackSequence = mapLeftEighthTurnToOrthogonal[trackSequence];
    wooden_rc_track_left_eighth_bank_to_diag(session, rideIndex, trackSequence, (direction + 3) & 3, height, tileElement);
}

/** rct2: 0x008ACA18 */
static void wooden_rc_track_diag_flat_to_left_bank(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24080, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24946, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 1:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24077, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24943, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24081, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24947, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 2:
            switch (direction)
            {
                case 0:
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24079, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24945, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24082, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24948, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24078, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24944, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
    }
}

/** rct2: 0x008AC9F8 */
static void wooden_rc_track_diag_flat_to_right_bank(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24086, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24952, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 1:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24083, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24949, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24087, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24953, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 2:
            switch (direction)
            {
                case 0:
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24085, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24951, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24088, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24954, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24084, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24950, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
    }
}

/** rct2: 0x008ACA08 */
static void wooden_rc_track_diag_left_bank_to_flat(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24084, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24950, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 1:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24085, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24951, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24088, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24954, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 2:
            switch (direction)
            {
                case 0:
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24083, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24949, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24087, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24953, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24086, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24952, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
    }
}

/** rct2: 0x008ACA28 */
static void wooden_rc_track_diag_right_bank_to_flat(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24078, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24944, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 1:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24079, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24945, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24082, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24948, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 2:
            switch (direction)
            {
                case 0:
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24077, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24943, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24081, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24947, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24080, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24946, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
    }
}

/** rct2: 0x008ACA58 */
static void wooden_rc_track_diag_left_bank_to_25_deg_up(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24104, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24970, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 1:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24101, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24967, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24105, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 35);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24971, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 35);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 2:
            switch (direction)
            {
                case 0:
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24103, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24969, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24106, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 35);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24972, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 35);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24102, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24968, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
    }
}

/** rct2: 0x008ACA68 */
static void wooden_rc_track_diag_right_bank_to_25_deg_up(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24110, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24976, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 1:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24107, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24973, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24111, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 35);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24977, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 35);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 2:
            switch (direction)
            {
                case 0:
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24109, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24975, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24112, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 35);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24978, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 35);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24108, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24974, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
    }
}

/** rct2: 0x008ACA38 */
static void wooden_rc_track_diag_25_deg_up_to_left_bank(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24092, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24958, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 56, 0x20);
            break;
        case 1:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24089, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24955, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24093, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 35);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24959, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 35);
                    wooden_b_supports_paint_setup(session, 2, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    wooden_b_supports_paint_setup(session, 3, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    wooden_b_supports_paint_setup(session, 4, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_b_supports_paint_setup(session, 5, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 56, 0x20);
            break;
        case 2:
            switch (direction)
            {
                case 0:
                    wooden_b_supports_paint_setup(session, 4, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    wooden_b_supports_paint_setup(session, 5, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24091, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24957, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24094, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 35);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24960, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 35);
                    wooden_b_supports_paint_setup(session, 2, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_b_supports_paint_setup(session, 3, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 56, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24090, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24956, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 56, 0x20);
            break;
    }
}

/** rct2: 0x008ACA48 */
static void wooden_rc_track_diag_25_deg_up_to_right_bank(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24098, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24964, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 56, 0x20);
            break;
        case 1:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24095, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24961, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24099, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 35);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24965, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 35);
                    wooden_b_supports_paint_setup(session, 2, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    wooden_b_supports_paint_setup(session, 3, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    wooden_b_supports_paint_setup(session, 4, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_b_supports_paint_setup(session, 5, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 56, 0x20);
            break;
        case 2:
            switch (direction)
            {
                case 0:
                    wooden_b_supports_paint_setup(session, 4, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    wooden_b_supports_paint_setup(session, 5, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24097, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24963, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24100, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 35);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24966, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 35);
                    wooden_b_supports_paint_setup(session, 2, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_b_supports_paint_setup(session, 3, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 56, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24096, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24962, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 56, 0x20);
            break;
    }
}

/** rct2: 0x008ACA78 */
static void wooden_rc_track_diag_left_bank_to_25_deg_down(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24096, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24962, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            break;
        case 1:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24097, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24963, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24100, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 35);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24966, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 35);
                    wooden_b_supports_paint_setup(session, 2, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    wooden_b_supports_paint_setup(session, 3, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    wooden_b_supports_paint_setup(session, 4, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_b_supports_paint_setup(session, 5, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            break;
        case 2:
            switch (direction)
            {
                case 0:
                    wooden_b_supports_paint_setup(session, 4, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    wooden_b_supports_paint_setup(session, 5, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24095, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24961, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24099, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 35);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24965, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 35);
                    wooden_b_supports_paint_setup(session, 2, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_b_supports_paint_setup(session, 3, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            break;
        case 3:
            switch (direction)
            {
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24098, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24964, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            break;
    }

    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 56, 0x20);
}

/** rct2: 0x008ACA88 */
static void wooden_rc_track_diag_right_bank_to_25_deg_down(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24090, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24956, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            break;
        case 1:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24091, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24957, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24094, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 35);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24960, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 35);
                    wooden_b_supports_paint_setup(session, 2, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    wooden_b_supports_paint_setup(session, 3, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    wooden_b_supports_paint_setup(session, 4, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_b_supports_paint_setup(session, 5, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            break;
        case 2:
            switch (direction)
            {
                case 0:
                    wooden_b_supports_paint_setup(session, 4, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    wooden_b_supports_paint_setup(session, 5, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24089, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24955, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24093, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 35);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24959, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 35);
                    wooden_b_supports_paint_setup(session, 2, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_b_supports_paint_setup(session, 3, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            break;
        case 3:
            switch (direction)
            {
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24092, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24958, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            break;
    }

    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 56, 0x20);
}

/** rct2: 0x008ACA98 */
static void wooden_rc_track_diag_25_deg_down_to_left_bank(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24108, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24974, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 1:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24109, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24975, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24112, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 35);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24978, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 35);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 2:
            switch (direction)
            {
                case 0:
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24107, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24973, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24111, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 35);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24977, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 35);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24110, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24976, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
    }
}

/** rct2: 0x008ACAA8 */
static void wooden_rc_track_diag_25_deg_down_to_right_bank(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24102, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24968, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 1:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24103, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24969, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24106, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 35);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24972, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 35);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 2:
            switch (direction)
            {
                case 0:
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24101, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24967, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24105, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 35);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24971, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 35);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24104, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24970, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
    }
}

/** rct2: 0x008AC9D8 */
static void wooden_rc_track_diag_left_bank(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24074, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24940, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 1:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24071, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24937, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24075, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24941, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 2:
            switch (direction)
            {
                case 0:
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24073, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24939, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24076, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24942, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24072, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24938, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
    }
}

/** rct2: 0x008AC9E8 */
static void wooden_rc_track_diag_right_bank(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24072, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24938, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 1:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24073, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24939, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24076, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24942, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 2:
            switch (direction)
            {
                case 0:
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24071, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24937, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24075, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24941, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24074, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24940, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
    }
}

/** rct2: 0x008ACB38 */
static void wooden_rc_track_left_bank_to_left_quarter_turn_3_25_deg_up(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23958, 0, 6, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24824, 0, 6, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23960, 0, 6, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24826, 0, 6, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23971, 0, 6, 32, 20, 0, height, 0, 6,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24837, 0, 6, 32, 20, 0, height, 0, 6,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23962, 0, 6, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24828, 0, 6, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23956, 0, 6, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24822, 0, 6, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23969, 0, 6, 32, 20, 0, height, 0, 6,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24835, 0, 6, 32, 20, 0, height, 0, 6,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            if (direction == 0 || direction == 3)
            {
                paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_FLAT);
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 64, 0x20);
            break;
        case 1:
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 2:
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23957, 6, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24823, 6, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23959, 6, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24825, 6, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23970, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24836, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23961, 6, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24827, 6, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23972, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24838, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23955, 6, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24821, 6, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23968, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24834, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            switch (direction)
            {
                case 2:
                    paint_util_push_tunnel_right(session, height, TUNNEL_SQUARE_8);
                    break;
                case 3:
                    paint_util_push_tunnel_left(session, height, TUNNEL_SQUARE_8);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 64, 0x20);
            break;
    }
}

/** rct2: 0x008ACB48 */
static void wooden_rc_track_right_bank_to_right_quarter_turn_3_25_deg_up(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23947, 0, 6, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24813, 0, 6, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23963, 0, 6, 32, 20, 0, height, 0, 6,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24829, 0, 6, 32, 20, 0, height, 0, 6,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23949, 0, 6, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24815, 0, 6, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23951, 0, 6, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24817, 0, 6, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23966, 0, 6, 32, 20, 0, height, 0, 6,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24832, 0, 6, 32, 20, 0, height, 0, 6,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23953, 0, 6, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24819, 0, 6, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            if (direction == 0 || direction == 3)
            {
                paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_FLAT);
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 64, 0x20);
            break;
        case 1:
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 2:
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23948, 6, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24814, 6, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23964, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24830, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23950, 6, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24816, 6, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23965, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24831, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23952, 6, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24818, 6, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23967, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24833, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23954, 6, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24820, 6, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            switch (direction)
            {
                case 0:
                    paint_util_push_tunnel_right(session, height, TUNNEL_SQUARE_8);
                    break;
                case 1:
                    paint_util_push_tunnel_left(session, height, TUNNEL_SQUARE_8);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 64, 0x20);
            break;
    }
}

/** rct2: 0x008ACB58 */
static void wooden_rc_track_left_quarter_turn_3_25_deg_down_to_left_bank(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23950, 0, 6, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24816, 0, 6, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23965, 0, 6, 32, 20, 0, height, 0, 6,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24831, 0, 6, 32, 20, 0, height, 0, 6,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23952, 0, 6, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24818, 0, 6, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23967, 0, 6, 32, 20, 0, height, 0, 6,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24833, 0, 6, 32, 20, 0, height, 0, 6,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23954, 0, 6, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24820, 0, 6, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23948, 0, 6, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24814, 0, 6, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23964, 0, 6, 32, 20, 0, height, 0, 6,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24830, 0, 6, 32, 20, 0, height, 0, 6,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            if (direction == 0 || direction == 3)
            {
                paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_8);
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 64, 0x20);
            break;
        case 1:
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 2:
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23949, 6, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24815, 6, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23951, 6, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24817, 6, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23966, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24832, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23953, 6, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24819, 6, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23947, 6, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24813, 6, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23963, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24829, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            switch (direction)
            {
                case 2:
                    paint_util_push_tunnel_right(session, height, TUNNEL_SQUARE_FLAT);
                    break;
                case 3:
                    paint_util_push_tunnel_left(session, height, TUNNEL_SQUARE_FLAT);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 64, 0x20);
            break;
    }
}

/** rct2: 0x008ACB68 */
static void wooden_rc_track_right_quarter_turn_3_25_deg_down_to_right_bank(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23955, 0, 6, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24821, 0, 6, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23968, 0, 6, 32, 20, 0, height, 0, 6,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24834, 0, 6, 32, 20, 0, height, 0, 6,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23957, 0, 6, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24823, 0, 6, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23959, 0, 6, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24825, 0, 6, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23970, 0, 6, 32, 20, 0, height, 0, 6,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24836, 0, 6, 32, 20, 0, height, 0, 6,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23961, 0, 6, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24827, 0, 6, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23972, 0, 6, 32, 20, 0, height, 0, 6,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24838, 0, 6, 32, 20, 0, height, 0, 6,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            if (direction == 0 || direction == 3)
            {
                paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_8);
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 64, 0x20);
            break;
        case 1:
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 2:
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23956, 6, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24822, 6, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23969, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24835, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23958, 6, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24824, 6, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23960, 6, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24826, 6, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23971, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24837, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23962, 6, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24828, 6, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            switch (direction)
            {
                case 0:
                    paint_util_push_tunnel_right(session, height, TUNNEL_SQUARE_FLAT);
                    break;
                case 1:
                    paint_util_push_tunnel_left(session, height, TUNNEL_SQUARE_FLAT);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 64, 0x20);
            break;
    }
}

/** rct2: 0x008ACCB8 */
static void wooden_rc_track_left_banked_quarter_turn_3_25_deg_up(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23932, 0, 6, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24798, 0, 6, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23934, 0, 6, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24800, 0, 6, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23945, 0, 6, 32, 20, 0, height, 0, 6,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24811, 0, 6, 32, 20, 0, height, 0, 6,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23936, 0, 6, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24802, 0, 6, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23930, 0, 6, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24796, 0, 6, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23943, 0, 6, 32, 20, 0, height, 0, 6,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24809, 0, 6, 32, 20, 0, height, 0, 6,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            if (direction == 0 || direction == 3)
            {
                paint_util_push_tunnel_rotated(session, direction, height - 8, TUNNEL_SQUARE_7);
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 72, 0x20);
            break;
        case 1:
            paint_util_set_general_support_height(session, height + 56, 0x20);
            break;
        case 2:
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 56, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23931, 6, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24797, 6, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23933, 6, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24799, 6, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23944, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24810, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23935, 6, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24801, 6, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23946, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24812, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23929, 6, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24795, 6, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23942, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24808, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            switch (direction)
            {
                case 2:
                    paint_util_push_tunnel_right(session, height + 8, TUNNEL_SQUARE_8);
                    break;
                case 3:
                    paint_util_push_tunnel_left(session, height + 8, TUNNEL_SQUARE_8);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 72, 0x20);
            break;
    }
}

/** rct2: 0x008ACCC8 */
static void wooden_rc_track_right_banked_quarter_turn_3_25_deg_up(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23921, 0, 6, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24787, 0, 6, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23937, 0, 6, 32, 20, 0, height, 0, 6,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24803, 0, 6, 32, 20, 0, height, 0, 6,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23923, 0, 6, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24789, 0, 6, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23925, 0, 6, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24791, 0, 6, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23940, 0, 6, 32, 20, 0, height, 0, 6,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24806, 0, 6, 32, 20, 0, height, 0, 6,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23927, 0, 6, 32, 20, 2, height, 0, 6,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24793, 0, 6, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            if (direction == 0 || direction == 3)
            {
                paint_util_push_tunnel_rotated(session, direction, height - 8, TUNNEL_SQUARE_7);
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 72, 0x20);
            break;
        case 1:
            paint_util_set_general_support_height(session, height + 56, 0x20);
            break;
        case 2:
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_C0 | SEGMENT_C4 | SEGMENT_D0 | SEGMENT_D4, direction), 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 56, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23922, 6, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24788, 6, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23938, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24804, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23924, 6, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24790, 6, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23939, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24805, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23926, 6, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24792, 6, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23941, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24807, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 23928, 6, 0, 20, 32, 2, height, 6, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24794, 6, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            switch (direction)
            {
                case 0:
                    paint_util_push_tunnel_right(session, height + 8, TUNNEL_SQUARE_8);
                    break;
                case 1:
                    paint_util_push_tunnel_left(session, height + 8, TUNNEL_SQUARE_8);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 72, 0x20);
            break;
    }
}

/** rct2: 0x008ACCD8 */
static void wooden_rc_track_left_banked_quarter_turn_3_25_deg_down(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    trackSequence = mapLeftQuarterTurn3TilesToRightQuarterTurn3Tiles[trackSequence];
    wooden_rc_track_right_banked_quarter_turn_3_25_deg_up(
        session, rideIndex, trackSequence, (direction + 1) & 3, height, tileElement);
}

/** rct2: 0x008ACCE8 */
static void wooden_rc_track_right_banked_quarter_turn_3_25_deg_down(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    trackSequence = mapLeftQuarterTurn3TilesToRightQuarterTurn3Tiles[trackSequence];
    wooden_rc_track_left_banked_quarter_turn_3_25_deg_up(
        session, rideIndex, trackSequence, (direction - 1) & 3, height, tileElement);
}

/** rct2: 0x008ACC38 */
static void wooden_rc_track_left_banked_quarter_turn_5_25_deg_up(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24321, 0, 0, 32, 27, 2, height, 0, 2,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25187, 0, 0, 32, 27, 2, height, 0, 2, height);
                    wooden_a_supports_paint_setup(session, 0, 9, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24326, 0, 0, 32, 27, 2, height, 0, 2,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25192, 0, 0, 32, 27, 2, height, 0, 2, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24352, 0, 0, 32, 27, 0, height, 0, 2,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25218, 0, 0, 32, 27, 0, height, 0, 2,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 1, 10, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24331, 0, 0, 32, 27, 2, height, 0, 2,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25197, 0, 0, 32, 27, 2, height, 0, 2, height);
                    wooden_a_supports_paint_setup(session, 0, 11, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24336, 0, 0, 32, 27, 2, height, 0, 2,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25202, 0, 0, 32, 27, 2, height, 0, 2, height);
                    wooden_a_supports_paint_setup(session, 1, 12, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            if (direction == 0 || direction == 3)
            {
                paint_util_push_tunnel_rotated(session, direction, height - 8, TUNNEL_SQUARE_7);
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 72, 0x20);
            break;
        case 1:
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_BC | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 72, 0x20);
            break;
        case 2:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24322, 0, 0, 32, 16, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25188, 0, 0, 32, 16, 2, height, 0, 0, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24327, 0, 0, 32, 16, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25193, 0, 0, 32, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24353, 0, 0, 32, 16, 0, height, 0, 0,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25219, 0, 0, 32, 16, 0, height, 0, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24332, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25198, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24337, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25203, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24359, 0, 0, 32, 16, 0, height, 0, 16,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25225, 0, 0, 32, 16, 0, height, 0, 16,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(
                session,
                paint_util_rotate_segments(
                    SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 72, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24323, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25189, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24328, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25194, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24354, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 59);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25220, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 59);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24333, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25199, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24338, 0, 0, 16, 16, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25204, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24360, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 59);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25226, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 59);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(
                session,
                paint_util_rotate_segments(
                    SEGMENT_B4 | SEGMENT_BC | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4,
                    direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 64, 0x20);
            break;
        case 4:
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_BC | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 72, 0x20);
            break;
        case 5:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24324, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25190, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24329, 0, 0, 16, 32, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25195, 0, 0, 16, 32, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24355, 0, 0, 16, 32, 0, height, 0, 0,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25221, 0, 0, 16, 32, 0, height, 0, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24334, 0, 0, 16, 32, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25200, 0, 0, 16, 32, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24357, 0, 0, 16, 32, 0, height, 0, 0,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25223, 0, 0, 16, 32, 0, height, 0, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24339, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25205, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24361, 0, 0, 16, 32, 0, height, 16, 0,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25227, 0, 0, 16, 32, 0, height, 16, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(
                session,
                paint_util_rotate_segments(
                    SEGMENT_B8 | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 72, 0x20);
            break;
        case 6:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24325, 0, 0, 27, 32, 2, height, 2, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25191, 0, 0, 27, 32, 2, height, 2, 0, height);
                    wooden_a_supports_paint_setup(session, 1, 12, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24330, 0, 0, 27, 32, 2, height, 2, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25196, 0, 0, 27, 32, 2, height, 2, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24356, 0, 0, 27, 32, 0, height, 2, 0,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25222, 0, 0, 27, 32, 0, height, 2, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 0, 9, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24335, 0, 0, 27, 32, 2, height, 2, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25201, 0, 0, 27, 32, 2, height, 2, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24358, 0, 0, 27, 32, 0, height, 2, 0,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25224, 0, 0, 27, 32, 0, height, 2, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 1, 10, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24340, 0, 0, 27, 32, 2, height, 2, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25206, 0, 0, 27, 32, 2, height, 2, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24362, 0, 0, 27, 32, 0, height, 2, 0,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25228, 0, 0, 27, 32, 0, height, 2, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 0, 11, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            switch (direction)
            {
                case 2:
                    paint_util_push_tunnel_right(session, height + 8, TUNNEL_SQUARE_8);
                    break;
                case 3:
                    paint_util_push_tunnel_left(session, height + 8, TUNNEL_SQUARE_8);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 72, 0x20);
            break;
    }
}

/** rct2: 0x008ACC48 */
static void wooden_rc_track_right_banked_quarter_turn_5_25_deg_up(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24301, 0, 0, 32, 27, 2, height, 0, 2,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25167, 0, 0, 32, 27, 2, height, 0, 2, height);
                    wooden_a_supports_paint_setup(session, 0, 9, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24306, 0, 0, 32, 27, 2, height, 0, 2,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25172, 0, 0, 32, 27, 2, height, 0, 2, height);
                    wooden_a_supports_paint_setup(session, 1, 10, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24311, 0, 0, 32, 27, 2, height, 0, 2,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25177, 0, 0, 32, 27, 2, height, 0, 2, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24347, 0, 0, 32, 27, 0, height, 0, 2,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25213, 0, 0, 32, 27, 0, height, 0, 2,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 0, 11, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24316, 0, 0, 32, 27, 2, height, 0, 2,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25182, 0, 0, 32, 27, 2, height, 0, 2, height);
                    wooden_a_supports_paint_setup(session, 1, 12, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            if (direction == 0 || direction == 3)
            {
                paint_util_push_tunnel_rotated(session, direction, height - 8, TUNNEL_SQUARE_7);
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 72, 0x20);
            break;
        case 1:
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 72, 0x20);
            break;
        case 2:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24302, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25168, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24341, 0, 0, 32, 16, 0, height, 0, 16,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25207, 0, 0, 32, 16, 0, height, 0, 16,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24307, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25173, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24312, 0, 0, 32, 16, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25178, 0, 0, 32, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24348, 0, 0, 32, 16, 0, height, 0, 0,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25214, 0, 0, 32, 16, 0, height, 0, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24317, 0, 0, 32, 16, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25183, 0, 0, 32, 16, 2, height, 0, 0, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(
                session,
                paint_util_rotate_segments(
                    SEGMENT_BC | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 72, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24303, 0, 0, 16, 16, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25169, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24342, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 59);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25208, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 59);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24308, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25174, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24313, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25179, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24349, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 59);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25215, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 59);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24318, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25184, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(
                session,
                paint_util_rotate_segments(
                    SEGMENT_B4 | SEGMENT_B8 | SEGMENT_BC | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4,
                    direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 64, 0x20);
            break;
        case 4:
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B4 | SEGMENT_C8 | SEGMENT_CC, direction), 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 72, 0x20);
            break;
        case 5:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24304, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25170, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24343, 0, 0, 16, 32, 0, height, 16, 0,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25209, 0, 0, 16, 32, 0, height, 16, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24309, 0, 0, 16, 32, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25175, 0, 0, 16, 32, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24345, 0, 0, 16, 32, 0, height, 0, 0,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25211, 0, 0, 16, 32, 0, height, 0, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24314, 0, 0, 16, 32, 2, height, 0, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25180, 0, 0, 16, 32, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24350, 0, 0, 16, 32, 0, height, 0, 0,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25216, 0, 0, 16, 32, 0, height, 0, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24319, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25185, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(
                session,
                paint_util_rotate_segments(
                    SEGMENT_B8 | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 72, 0x20);
            break;
        case 6:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24305, 0, 0, 27, 32, 2, height, 2, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25171, 0, 0, 27, 32, 2, height, 2, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24344, 0, 0, 27, 32, 0, height, 2, 0,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25210, 0, 0, 27, 32, 0, height, 2, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 1, 10, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24310, 0, 0, 27, 32, 2, height, 2, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25176, 0, 0, 27, 32, 2, height, 2, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24346, 0, 0, 27, 32, 0, height, 2, 0,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25212, 0, 0, 27, 32, 0, height, 2, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 0, 11, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24315, 0, 0, 27, 32, 2, height, 2, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25181, 0, 0, 27, 32, 2, height, 2, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24351, 0, 0, 27, 32, 0, height, 2, 0,
                        height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25217, 0, 0, 27, 32, 0, height, 2, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 1, 12, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<false>(session) | 24320, 0, 0, 27, 32, 2, height, 2, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25186, 0, 0, 27, 32, 2, height, 2, 0, height);
                    wooden_a_supports_paint_setup(session, 0, 9, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            switch (direction)
            {
                case 0:
                    paint_util_push_tunnel_right(session, height + 8, TUNNEL_SQUARE_8);
                    break;
                case 1:
                    paint_util_push_tunnel_left(session, height + 8, TUNNEL_SQUARE_8);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 72, 0x20);
            break;
    }
}

/** rct2: 0x008ACC58 */
static void wooden_rc_track_left_banked_quarter_turn_5_25_deg_down(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    trackSequence = mapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence];
    wooden_rc_track_right_banked_quarter_turn_5_25_deg_up(
        session, rideIndex, trackSequence, (direction + 1) & 3, height, tileElement);
}

/** rct2: 0x008ACC68 */
static void wooden_rc_track_right_banked_quarter_turn_5_25_deg_down(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    trackSequence = mapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence];
    wooden_rc_track_left_banked_quarter_turn_5_25_deg_up(
        session, rideIndex, trackSequence, (direction - 1) & 3, height, tileElement);
}

/** rct2: 0x008ACCF8 */
static void wooden_rc_track_25_deg_up_to_left_banked_25_deg_up(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (direction)
    {
        case 0:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24261, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25127, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 0, 9, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 1:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24262, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25128, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 1, 10, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 2:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24263, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25129, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 0, 11, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 3:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24264, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25130, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 1, 12, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
    }
    if (direction == 0 || direction == 3)
    {
        paint_util_push_tunnel_rotated(session, direction, height - 8, TUNNEL_SQUARE_7);
    }
    else
    {
        paint_util_push_tunnel_rotated(session, direction, height + 8, TUNNEL_SQUARE_8);
    }
    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 56, 0x20);
}

/** rct2: 0x008ACD08 */
static void wooden_rc_track_25_deg_up_to_right_banked_25_deg_up(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (direction)
    {
        case 0:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24265, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25131, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 0, 9, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 1:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24266, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25132, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 1, 10, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 2:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24267, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25133, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 0, 11, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 3:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24268, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25134, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 1, 12, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
    }
    if (direction == 0 || direction == 3)
    {
        paint_util_push_tunnel_rotated(session, direction, height - 8, TUNNEL_SQUARE_7);
    }
    else
    {
        paint_util_push_tunnel_rotated(session, direction, height + 8, TUNNEL_SQUARE_8);
    }
    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 56, 0x20);
}

/** rct2: 0x008ACD18 */
static void wooden_rc_track_left_banked_25_deg_up_to_25_deg_up(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (direction)
    {
        case 0:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24269, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25135, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 0, 9, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 1:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24270, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25136, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 1, 10, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 2:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24271, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25137, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 0, 11, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 3:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24272, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25138, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 1, 12, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
    }
    if (direction == 0 || direction == 3)
    {
        paint_util_push_tunnel_rotated(session, direction, height - 8, TUNNEL_SQUARE_7);
    }
    else
    {
        paint_util_push_tunnel_rotated(session, direction, height + 8, TUNNEL_SQUARE_8);
    }
    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 56, 0x20);
}

/** rct2: 0x008ACD28 */
static void wooden_rc_track_right_banked_25_deg_up_to_25_deg_up(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (direction)
    {
        case 0:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24273, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25139, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 0, 9, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 1:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24274, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25140, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 1, 10, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 2:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24275, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25141, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 0, 11, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 3:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24276, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25142, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 1, 12, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
    }
    if (direction == 0 || direction == 3)
    {
        paint_util_push_tunnel_rotated(session, direction, height - 8, TUNNEL_SQUARE_7);
    }
    else
    {
        paint_util_push_tunnel_rotated(session, direction, height + 8, TUNNEL_SQUARE_8);
    }
    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 56, 0x20);
}

/** rct2: 0x008ACD38 */
static void wooden_rc_track_25_deg_down_to_left_banked_25_deg_down(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    wooden_rc_track_right_banked_25_deg_up_to_25_deg_up(
        session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

/** rct2: 0x008ACD48 */
static void wooden_rc_track_25_deg_down_to_right_banked_25_deg_down(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    wooden_rc_track_left_banked_25_deg_up_to_25_deg_up(
        session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

/** rct2: 0x008ACD58 */
static void wooden_rc_track_left_banked_25_deg_down_to_25_deg_down(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    wooden_rc_track_25_deg_up_to_right_banked_25_deg_up(
        session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

/** rct2: 0x008ACD68 */
static void wooden_rc_track_right_banked_25_deg_down_to_25_deg_down(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    wooden_rc_track_25_deg_up_to_left_banked_25_deg_up(
        session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

/** rct2: 0x008ACD78 */
static void wooden_rc_track_left_banked_flat_to_left_banked_25_deg_up(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (direction)
    {
        case 0:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24277, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25143, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 0, 1, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 1:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24278, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25144, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24293, 0, 0, 32, 1, 9, height, 0, 26,
                height + 5);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25159, 0, 0, 32, 1, 9, height, 0, 26, height + 5);
            wooden_a_supports_paint_setup(session, 1, 2, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 2:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24279, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25145, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24294, 0, 0, 32, 1, 9, height, 0, 26,
                height + 5);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25160, 0, 0, 32, 1, 9, height, 0, 26, height + 5);
            wooden_a_supports_paint_setup(session, 0, 3, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 3:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24280, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25146, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 1, 4, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
    }
    if (direction == 0 || direction == 3)
    {
        paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_FLAT);
    }
    else
    {
        paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_8);
    }
    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 48, 0x20);
}

/** rct2: 0x008ACD88 */
static void wooden_rc_track_right_banked_flat_to_right_banked_25_deg_up(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (direction)
    {
        case 0:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24281, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25147, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 0, 1, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 1:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24282, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25148, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24295, 0, 0, 32, 1, 9, height, 0, 26,
                height + 5);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25161, 0, 0, 32, 1, 9, height, 0, 26, height + 5);
            wooden_a_supports_paint_setup(session, 1, 2, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 2:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24283, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25149, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24296, 0, 0, 32, 1, 9, height, 0, 26,
                height + 5);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25162, 0, 0, 32, 1, 9, height, 0, 26, height + 5);
            wooden_a_supports_paint_setup(session, 0, 3, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 3:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24284, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25150, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 1, 4, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
    }
    if (direction == 0 || direction == 3)
    {
        paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_FLAT);
    }
    else
    {
        paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_8);
    }
    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 48, 0x20);
}

/** rct2: 0x008ACD98 */
static void wooden_rc_track_left_banked_25_deg_up_to_left_banked_flat(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (direction)
    {
        case 0:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24285, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25151, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 0, 5, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 1:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24286, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25152, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24297, 0, 0, 32, 1, 9, height, 0, 26,
                height + 5);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25163, 0, 0, 32, 1, 9, height, 0, 26, height + 5);
            wooden_a_supports_paint_setup(session, 1, 6, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 2:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24287, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25153, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24298, 0, 0, 32, 1, 9, height, 0, 26,
                height + 5);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25164, 0, 0, 32, 1, 9, height, 0, 26, height + 5);
            wooden_a_supports_paint_setup(session, 0, 7, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 3:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24288, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25154, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 1, 8, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
    }
    if (direction == 0 || direction == 3)
    {
        paint_util_push_tunnel_rotated(session, direction, height - 8, TUNNEL_SQUARE_FLAT);
    }
    else
    {
        paint_util_push_tunnel_rotated(session, direction, height + 8, TUNNEL_14);
    }
    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 40, 0x20);
}

/** rct2: 0x008ACDA8 */
static void wooden_rc_track_right_banked_25_deg_up_to_right_banked_flat(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (direction)
    {
        case 0:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24289, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25155, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 0, 5, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 1:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24290, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25156, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24299, 0, 0, 32, 1, 9, height, 0, 26,
                height + 5);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25165, 0, 0, 32, 1, 9, height, 0, 26, height + 5);
            wooden_a_supports_paint_setup(session, 1, 6, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 2:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24291, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25157, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24300, 0, 0, 32, 1, 9, height, 0, 26,
                height + 5);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25166, 0, 0, 32, 1, 9, height, 0, 26, height + 5);
            wooden_a_supports_paint_setup(session, 0, 7, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 3:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24292, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25158, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 1, 8, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
    }
    if (direction == 0 || direction == 3)
    {
        paint_util_push_tunnel_rotated(session, direction, height - 8, TUNNEL_SQUARE_FLAT);
    }
    else
    {
        paint_util_push_tunnel_rotated(session, direction, height + 8, TUNNEL_14);
    }
    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 40, 0x20);
}

/** rct2: 0x008ACDB8 */
static void wooden_rc_track_left_banked_flat_to_left_banked_25_deg_down(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    wooden_rc_track_right_banked_25_deg_up_to_right_banked_flat(
        session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

/** rct2: 0x008ACDC8 */
static void wooden_rc_track_right_banked_flat_to_right_banked_25_deg_down(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    wooden_rc_track_left_banked_25_deg_up_to_left_banked_flat(
        session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

/** rct2: 0x008ACDD8 */
static void wooden_rc_track_left_banked_25_deg_down_to_left_banked_flat(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    wooden_rc_track_right_banked_flat_to_right_banked_25_deg_up(
        session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

/** rct2: 0x008ACDE8 */
static void wooden_rc_track_right_banked_25_deg_down_to_right_banked_flat(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    wooden_rc_track_left_banked_flat_to_left_banked_25_deg_up(
        session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

/** rct2: 0x008ACBB8 */
static void wooden_rc_track_flat_to_left_banked_25_deg_up(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (direction)
    {
        case 0:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24225, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25091, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 0, 1, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 1:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24226, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25092, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24241, 0, 0, 32, 1, 9, height, 0, 26,
                height + 5);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25107, 0, 0, 32, 1, 9, height, 0, 26, height + 5);
            wooden_a_supports_paint_setup(session, 1, 2, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 2:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24227, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25093, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24242, 0, 0, 32, 1, 9, height, 0, 26,
                height + 5);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25108, 0, 0, 32, 1, 9, height, 0, 26, height + 5);
            wooden_a_supports_paint_setup(session, 0, 3, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 3:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24228, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25094, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 1, 4, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
    }
    if (direction == 0 || direction == 3)
    {
        paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_FLAT);
    }
    else
    {
        paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_8);
    }
    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 48, 0x20);
}

/** rct2: 0x008ACBC8 */
static void wooden_rc_track_flat_to_right_banked_25_deg_up(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (direction)
    {
        case 0:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24229, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25095, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 0, 1, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 1:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24230, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25096, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24243, 0, 0, 32, 1, 9, height, 0, 26,
                height + 5);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25109, 0, 0, 32, 1, 9, height, 0, 26, height + 5);
            wooden_a_supports_paint_setup(session, 1, 2, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 2:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24231, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25097, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24244, 0, 0, 32, 1, 9, height, 0, 26,
                height + 5);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25110, 0, 0, 32, 1, 9, height, 0, 26, height + 5);
            wooden_a_supports_paint_setup(session, 0, 3, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 3:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24232, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25098, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 1, 4, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
    }
    if (direction == 0 || direction == 3)
    {
        paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_FLAT);
    }
    else
    {
        paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_8);
    }
    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 48, 0x20);
}

/** rct2: 0x008ACBD8 */
static void wooden_rc_track_left_banked_25_deg_up_to_flat(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (direction)
    {
        case 0:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24233, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25099, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 0, 5, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 1:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24234, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25100, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24245, 0, 0, 32, 1, 9, height, 0, 26,
                height + 5);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25111, 0, 0, 32, 1, 9, height, 0, 26, height + 5);
            wooden_a_supports_paint_setup(session, 1, 6, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 2:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24235, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25101, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24246, 0, 0, 32, 1, 9, height, 0, 26,
                height + 5);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25112, 0, 0, 32, 1, 9, height, 0, 26, height + 5);
            wooden_a_supports_paint_setup(session, 0, 7, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 3:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24236, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25102, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 1, 8, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
    }
    if (direction == 0 || direction == 3)
    {
        paint_util_push_tunnel_rotated(session, direction, height - 8, TUNNEL_SQUARE_FLAT);
    }
    else
    {
        paint_util_push_tunnel_rotated(session, direction, height + 8, TUNNEL_14);
    }
    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 40, 0x20);
}

/** rct2: 0x008ACBE8 */
static void wooden_rc_track_right_banked_25_deg_up_to_flat(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (direction)
    {
        case 0:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24237, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25103, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 0, 5, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 1:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24238, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25104, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24247, 0, 0, 32, 1, 9, height, 0, 26,
                height + 5);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25113, 0, 0, 32, 1, 9, height, 0, 26, height + 5);
            wooden_a_supports_paint_setup(session, 1, 6, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 2:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24239, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25105, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24248, 0, 0, 32, 1, 9, height, 0, 26,
                height + 5);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25114, 0, 0, 32, 1, 9, height, 0, 26, height + 5);
            wooden_a_supports_paint_setup(session, 0, 7, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
        case 3:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<false>(session) | 24240, 0, 0, 32, 25, 2, height, 0, 3, height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25106, 0, 0, 32, 25, 2, height, 0, 3, height);
            wooden_a_supports_paint_setup(session, 1, 8, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            break;
    }
    if (direction == 0 || direction == 3)
    {
        paint_util_push_tunnel_rotated(session, direction, height - 8, TUNNEL_SQUARE_FLAT);
    }
    else
    {
        paint_util_push_tunnel_rotated(session, direction, height + 8, TUNNEL_14);
    }
    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 40, 0x20);
}

/** rct2: 0x008ACBF8 */
static void wooden_rc_track_flat_to_left_banked_25_deg_down(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    wooden_rc_track_right_banked_25_deg_up_to_flat(session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

/** rct2: 0x008ACC08 */
static void wooden_rc_track_flat_to_right_banked_25_deg_down(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    wooden_rc_track_left_banked_25_deg_up_to_flat(session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

/** rct2: 0x008ACC18 */
static void wooden_rc_track_left_banked_25_deg_down_to_flat(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    wooden_rc_track_flat_to_right_banked_25_deg_up(session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

/** rct2: 0x008ACC28 */
static void wooden_rc_track_right_banked_25_deg_down_to_flat(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    wooden_rc_track_flat_to_left_banked_25_deg_up(session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

TRACK_PAINT_FUNCTION get_track_paint_function_wooden_rc(int32_t trackType)
{
    switch (trackType)
    {
        case TrackElemType::FlatToLeftBank:
            return wooden_rc_track_flat_to_left_bank;
        case TrackElemType::FlatToRightBank:
            return wooden_rc_track_flat_to_right_bank;
        case TrackElemType::LeftBankToFlat:
            return wooden_rc_track_left_bank_to_flat;
        case TrackElemType::RightBankToFlat:
            return wooden_rc_track_right_bank_to_flat;
        case TrackElemType::BankedLeftQuarterTurn5Tiles:
            return wooden_rc_track_banked_left_quarter_turn_5;
        case TrackElemType::BankedRightQuarterTurn5Tiles:
            return wooden_rc_track_banked_right_quarter_turn_5;
        case TrackElemType::LeftBankToUp25:
            return wooden_rc_track_left_bank_to_25_deg_up;
        case TrackElemType::RightBankToUp25:
            return wooden_rc_track_right_bank_to_25_deg_up;
        case TrackElemType::Up25ToLeftBank:
            return wooden_rc_track_25_deg_up_to_left_bank;
        case TrackElemType::Up25ToRightBank:
            return wooden_rc_track_25_deg_up_to_right_bank;
        case TrackElemType::LeftBankToDown25:
            return wooden_rc_track_left_bank_to_25_deg_down;
        case TrackElemType::RightBankToDown25:
            return wooden_rc_track_right_bank_to_25_deg_down;
        case TrackElemType::Down25ToLeftBank:
            return wooden_rc_track_25_deg_down_to_left_bank;
        case TrackElemType::Down25ToRightBank:
            return wooden_rc_track_25_deg_down_to_right_bank;
        case TrackElemType::LeftBank:
            return wooden_rc_track_left_bank;
        case TrackElemType::RightBank:
            return wooden_rc_track_right_bank;
        case TrackElemType::LeftBankedQuarterTurn3Tiles:
            return wooden_rc_track_left_quarter_turn_3_bank;
        case TrackElemType::RightBankedQuarterTurn3Tiles:
            return wooden_rc_track_right_quarter_turn_3_bank;
        case TrackElemType::LeftHalfBankedHelixUpSmall:
            return wooden_rc_track_left_half_banked_helix_up_small;
        case TrackElemType::RightHalfBankedHelixUpSmall:
            return wooden_rc_track_right_half_banked_helix_up_small;
        case TrackElemType::LeftHalfBankedHelixDownSmall:
            return wooden_rc_track_left_half_banked_helix_down_small;
        case TrackElemType::RightHalfBankedHelixDownSmall:
            return wooden_rc_track_right_half_banked_helix_down_small;
        case TrackElemType::LeftHalfBankedHelixUpLarge:
            return wooden_rc_track_left_half_banked_helix_up_large;
        case TrackElemType::RightHalfBankedHelixUpLarge:
            return wooden_rc_track_right_half_banked_helix_up_large;
        case TrackElemType::LeftHalfBankedHelixDownLarge:
            return wooden_rc_track_left_half_banked_helix_down_large;
        case TrackElemType::RightHalfBankedHelixDownLarge:
            return wooden_rc_track_right_half_banked_helix_down_large;
        case TrackElemType::Up25LeftBanked:
            return wooden_rc_track_25_deg_up_left_banked;
        case TrackElemType::Up25RightBanked:
            return wooden_rc_track_25_deg_up_right_banked;
        case TrackElemType::Down25LeftBanked:
            return wooden_rc_track_25_deg_down_left_banked;
        case TrackElemType::Down25RightBanked:
            return wooden_rc_track_25_deg_down_right_banked;
        case TrackElemType::LeftEighthBankToDiag:
            return wooden_rc_track_left_eighth_bank_to_diag;
        case TrackElemType::RightEighthBankToDiag:
            return wooden_rc_track_right_eighth_bank_to_diag;
        case TrackElemType::LeftEighthBankToOrthogonal:
            return wooden_rc_track_left_eighth_bank_to_orthogonal;
        case TrackElemType::RightEighthBankToOrthogonal:
            return wooden_rc_track_right_eighth_bank_to_orthogonal;
        case TrackElemType::DiagFlatToLeftBank:
            return wooden_rc_track_diag_flat_to_left_bank;
        case TrackElemType::DiagFlatToRightBank:
            return wooden_rc_track_diag_flat_to_right_bank;
        case TrackElemType::DiagLeftBankToFlat:
            return wooden_rc_track_diag_left_bank_to_flat;
        case TrackElemType::DiagRightBankToFlat:
            return wooden_rc_track_diag_right_bank_to_flat;
        case TrackElemType::DiagLeftBankToUp25:
            return wooden_rc_track_diag_left_bank_to_25_deg_up;
        case TrackElemType::DiagRightBankToUp25:
            return wooden_rc_track_diag_right_bank_to_25_deg_up;
        case TrackElemType::DiagUp25ToLeftBank:
            return wooden_rc_track_diag_25_deg_up_to_left_bank;
        case TrackElemType::DiagUp25ToRightBank:
            return wooden_rc_track_diag_25_deg_up_to_right_bank;
        case TrackElemType::DiagLeftBankToDown25:
            return wooden_rc_track_diag_left_bank_to_25_deg_down;
        case TrackElemType::DiagRightBankToDown25:
            return wooden_rc_track_diag_right_bank_to_25_deg_down;
        case TrackElemType::DiagDown25ToLeftBank:
            return wooden_rc_track_diag_25_deg_down_to_left_bank;
        case TrackElemType::DiagDown25ToRightBank:
            return wooden_rc_track_diag_25_deg_down_to_right_bank;
        case TrackElemType::DiagLeftBank:
            return wooden_rc_track_diag_left_bank;
        case TrackElemType::DiagRightBank:
            return wooden_rc_track_diag_right_bank;
        case TrackElemType::LeftBankToLeftQuarterTurn3TilesUp25:
            return wooden_rc_track_left_bank_to_left_quarter_turn_3_25_deg_up;
        case TrackElemType::RightBankToRightQuarterTurn3TilesUp25:
            return wooden_rc_track_right_bank_to_right_quarter_turn_3_25_deg_up;
        case TrackElemType::LeftQuarterTurn3TilesDown25ToLeftBank:
            return wooden_rc_track_left_quarter_turn_3_25_deg_down_to_left_bank;
        case TrackElemType::RightQuarterTurn3TilesDown25ToRightBank:
            return wooden_rc_track_right_quarter_turn_3_25_deg_down_to_right_bank;
        case TrackElemType::LeftBankedQuarterTurn3TileUp25:
            return wooden_rc_track_left_banked_quarter_turn_3_25_deg_up;
        case TrackElemType::RightBankedQuarterTurn3TileUp25:
            return wooden_rc_track_right_banked_quarter_turn_3_25_deg_up;
        case TrackElemType::LeftBankedQuarterTurn3TileDown25:
            return wooden_rc_track_left_banked_quarter_turn_3_25_deg_down;
        case TrackElemType::RightBankedQuarterTurn3TileDown25:
            return wooden_rc_track_right_banked_quarter_turn_3_25_deg_down;
        case TrackElemType::LeftBankedQuarterTurn5TileUp25:
            return wooden_rc_track_left_banked_quarter_turn_5_25_deg_up;
        case TrackElemType::RightBankedQuarterTurn5TileUp25:
            return wooden_rc_track_right_banked_quarter_turn_5_25_deg_up;
        case TrackElemType::LeftBankedQuarterTurn5TileDown25:
            return wooden_rc_track_left_banked_quarter_turn_5_25_deg_down;
        case TrackElemType::RightBankedQuarterTurn5TileDown25:
            return wooden_rc_track_right_banked_quarter_turn_5_25_deg_down;
        case TrackElemType::Up25ToLeftBankedUp25:
            return wooden_rc_track_25_deg_up_to_left_banked_25_deg_up;
        case TrackElemType::Up25ToRightBankedUp25:
            return wooden_rc_track_25_deg_up_to_right_banked_25_deg_up;
        case TrackElemType::LeftBankedUp25ToUp25:
            return wooden_rc_track_left_banked_25_deg_up_to_25_deg_up;
        case TrackElemType::RightBankedUp25ToUp25:
            return wooden_rc_track_right_banked_25_deg_up_to_25_deg_up;
        case TrackElemType::Down25ToLeftBankedDown25:
            return wooden_rc_track_25_deg_down_to_left_banked_25_deg_down;
        case TrackElemType::Down25ToRightBankedDown25:
            return wooden_rc_track_25_deg_down_to_right_banked_25_deg_down;
        case TrackElemType::LeftBankedDown25ToDown25:
            return wooden_rc_track_left_banked_25_deg_down_to_25_deg_down;
        case TrackElemType::RightBankedDown25ToDown25:
            return wooden_rc_track_right_banked_25_deg_down_to_25_deg_down;
        case TrackElemType::LeftBankedFlatToLeftBankedUp25:
            return wooden_rc_track_left_banked_flat_to_left_banked_25_deg_up;
        case TrackElemType::RightBankedFlatToRightBankedUp25:
            return wooden_rc_track_right_banked_flat_to_right_banked_25_deg_up;
        case TrackElemType::LeftBankedUp25ToLeftBankedFlat:
            return wooden_rc_track_left_banked_25_deg_up_to_left_banked_flat;
        case TrackElemType::RightBankedUp25ToRightBankedFlat:
            return wooden_rc_track_right_banked_25_deg_up_to_right_banked_flat;
        case TrackElemType::LeftBankedFlatToLeftBankedDown25:
            return wooden_rc_track_left_banked_flat_to_left_banked_25_deg_down;
        case TrackElemType::RightBankedFlatToRightBankedDown25:
            return wooden_rc_track_right_banked_flat_to_right_banked_25_deg_down;
        case TrackElemType::LeftBankedDown25ToLeftBankedFlat:
            return wooden_rc_track_left_banked_25_deg_down_to_left_banked_flat;
        case TrackElemType::RightBankedDown25ToRightBankedFlat:
            return wooden_rc_track_right_banked_25_deg_down_to_right_banked_flat;
        case TrackElemType::FlatToLeftBankedUp25:
            return wooden_rc_track_flat_to_left_banked_25_deg_up;
        case TrackElemType::FlatToRightBankedUp25:
            return wooden_rc_track_flat_to_right_banked_25_deg_up;
        case TrackElemType::LeftBankedUp25ToFlat:
            return wooden_rc_track_left_banked_25_deg_up_to_flat;
        case TrackElemType::RightBankedUp25ToFlat:
            return wooden_rc_track_right_banked_25_deg_up_to_flat;
        case TrackElemType::FlatToLeftBankedDown25:
            return wooden_rc_track_flat_to_left_banked_25_deg_down;
        case TrackElemType::FlatToRightBankedDown25:
            return wooden_rc_track_flat_to_right_banked_25_deg_down;
        case TrackElemType::LeftBankedDown25ToFlat:
            return wooden_rc_track_left_banked_25_deg_down_to_flat;
        case TrackElemType::RightBankedDown25ToFlat:
            return wooden_rc_track_right_banked_25_deg_down_to_flat;
    }
    return get_track_paint_function_wooden_rc<false>(trackType);
}
