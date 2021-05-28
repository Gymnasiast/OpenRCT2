/*****************************************************************************
 * Copyright (c) 2014-2021 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include "../../config/Config.h"
#include "../../paint/Paint.h"
#include "../../paint/Supports.h"
#include "../../paint/tile_element/Paint.Surface.h"
#include "../../ride/Track.h"
#include "../../ride/TrackPaint.h"
#include "../../sprites.h"

#include <cstdint>

using ride_id_t = uint16_t;

enum
{
    SPR_WOODEN_RC_FLAT_TO_25_DEG_SW_NE = 23537,
    SPR_WOODEN_RC_FLAT_TO_25_DEG_NW_SE = 23538,
    SPR_WOODEN_RC_FLAT_TO_25_DEG_NE_SW = 23539,
    SPR_WOODEN_RC_FLAT_TO_25_DEG_SE_NW = 23540,
    SPR_WOODEN_RC_25_DEG_TO_FLAT_SW_NE = 23541,
    SPR_WOODEN_RC_25_DEG_TO_FLAT_NW_SE = 23542,
    SPR_WOODEN_RC_25_DEG_TO_FLAT_NE_SW = 23543,
    SPR_WOODEN_RC_25_DEG_TO_FLAT_SE_NW = 23544,
    SPR_WOODEN_RC_25_DEG_SW_NE = 23545,
    SPR_WOODEN_RC_25_DEG_NW_SE = 23546,
    SPR_WOODEN_RC_25_DEG_NE_SW = 23547,
    SPR_WOODEN_RC_25_DEG_SE_NW = 23548,
    SPR_WOODEN_RC_25_DEG_TO_60_DEG_SW_NE = 23549,
    SPR_WOODEN_RC_25_DEG_TO_60_DEG_FRONT_NW_SE = 23550,
    SPR_WOODEN_RC_25_DEG_TO_60_DEG_NW_SE = 23551,
    SPR_WOODEN_RC_25_DEG_TO_60_DEG_FRONT_NE_SW = 23552,
    SPR_WOODEN_RC_25_DEG_TO_60_DEG_NE_SW = 23553,
    SPR_WOODEN_RC_25_DEG_TO_60_DEG_SE_NW = 23554,
    SPR_WOODEN_RC_60_DEG_TO_25_DEG_SW_NE = 23555,
    SPR_WOODEN_RC_60_DEG_TO_25_DEG_FRONT_NW_SE = 23556,
    SPR_WOODEN_RC_60_DEG_TO_25_DEG_NW_SE = 23557,
    SPR_WOODEN_RC_60_DEG_TO_25_DEG_FRONT_NE_SW = 23558,
    SPR_WOODEN_RC_60_DEG_TO_25_DEG_NE_SW = 23559,
    SPR_WOODEN_RC_60_DEG_TO_25_DEG_SE_NW = 23560,
    SPR_WOODEN_RC_60_DEG_SW_NE = 23561,
    SPR_WOODEN_RC_60_DEG_CHAIN_SW_NE = 23561,
    SPR_WOODEN_RC_60_DEG_NW_SE = 23562,
    SPR_WOODEN_RC_60_DEG_CHAIN_NW_SE = 23562,
    SPR_WOODEN_RC_60_DEG_NE_SW = 23563,
    SPR_WOODEN_RC_60_DEG_CHAIN_NE_SW = 23563,
    SPR_WOODEN_RC_60_DEG_SE_NW = 23564,
    SPR_WOODEN_RC_60_DEG_CHAIN_SE_NW = 23564,
    SPR_WOODEN_RC_FLAT_TO_25_DEG_FRONT_NW_SE = 23565,
    SPR_WOODEN_RC_FLAT_TO_25_DEG_FRONT_NE_SW = 23566,
    SPR_WOODEN_RC_25_DEG_TO_FLAT_FRONT_NW_SE = 23567,
    SPR_WOODEN_RC_25_DEG_TO_FLAT_FRONT_NE_SW = 23568,
    SPR_WOODEN_RC_25_DEG_FRONT_NW_SE = 23569,
    SPR_WOODEN_RC_60_DEG_FRONT_NW_SE = 23569,
    SPR_WOODEN_RC_25_DEG_FRONT_NE_SW = 23570,
    SPR_WOODEN_RC_60_DEG_FRONT_NE_SW = 23570,
    SPR_WOODEN_RC_FLAT_TO_25_DEG_CHAIN_SW_NE = 23571,
    SPR_WOODEN_RC_FLAT_TO_25_DEG_CHAIN_NW_SE = 23572,
    SPR_WOODEN_RC_FLAT_TO_25_DEG_CHAIN_NE_SW = 23573,
    SPR_WOODEN_RC_FLAT_TO_25_DEG_CHAIN_SE_NW = 23574,
    SPR_WOODEN_RC_25_DEG_TO_FLAT_CHAIN_SW_NE = 23575,
    SPR_WOODEN_RC_25_DEG_TO_FLAT_CHAIN_NW_SE = 23576,
    SPR_WOODEN_RC_25_DEG_TO_FLAT_CHAIN_NE_SW = 23577,
    SPR_WOODEN_RC_25_DEG_TO_FLAT_CHAIN_SE_NW = 23578,
    SPR_WOODEN_RC_25_DEG_CHAIN_SW_NE = 23579,
    SPR_WOODEN_RC_25_DEG_CHAIN_NW_SE = 23580,
    SPR_WOODEN_RC_25_DEG_CHAIN_NE_SW = 23581,
    SPR_WOODEN_RC_25_DEG_CHAIN_SE_NW = 23582,

    SPR_WOODEN_RC_FLAT_TO_25_DEG_CHAIN_FRONT_NW_SE = 23599,
    SPR_WOODEN_RC_FLAT_TO_25_DEG_CHAIN_FRONT_NE_SW = 23600,
    SPR_WOODEN_RC_25_DEG_TO_FLAT_CHAIN_FRONT_NW_SE = 23601,
    SPR_WOODEN_RC_25_DEG_TO_FLAT_CHAIN_FRONT_NE_SW = 23602,
    SPR_WOODEN_RC_25_DEG_CHAIN_FRONT_NW_SE = 23603,
    SPR_WOODEN_RC_60_DEG_CHAIN_FRONT_NW_SE = 23603,
    SPR_WOODEN_RC_25_DEG_CHAIN_FRONT_NE_SW = 23604,
    SPR_WOODEN_RC_60_DEG_CHAIN_FRONT_NE_SW = 23604,
    SPR_WOODEN_RC_QUARTER_TURN_5_SW_SE_SEQ_0 = 23605,
    SPR_WOODEN_RC_QUARTER_TURN_5_SW_SE_SEQ_2 = 23606,
    SPR_WOODEN_RC_QUARTER_TURN_5_SW_SE_SEQ_3 = 23607,
    SPR_WOODEN_RC_QUARTER_TURN_5_SW_SE_SEQ_5 = 23608,
    SPR_WOODEN_RC_QUARTER_TURN_5_SW_SE_SEQ_6 = 23609,
    SPR_WOODEN_RC_QUARTER_TURN_5_NW_SW_SEQ_0 = 23610,
    SPR_WOODEN_RC_QUARTER_TURN_5_NW_SW_SEQ_2 = 23611,
    SPR_WOODEN_RC_QUARTER_TURN_5_NW_SW_SEQ_3 = 23612,
    SPR_WOODEN_RC_QUARTER_TURN_5_NW_SW_SEQ_5 = 23613,
    SPR_WOODEN_RC_QUARTER_TURN_5_NW_SW_SEQ_6 = 23614,
    SPR_WOODEN_RC_QUARTER_TURN_5_NE_NW_SEQ_0 = 23615,
    SPR_WOODEN_RC_QUARTER_TURN_5_NE_NW_SEQ_2 = 23616,
    SPR_WOODEN_RC_QUARTER_TURN_5_NE_NW_SEQ_3 = 23617,
    SPR_WOODEN_RC_QUARTER_TURN_5_NE_NW_SEQ_5 = 23618,
    SPR_WOODEN_RC_QUARTER_TURN_5_NE_NW_SEQ_6 = 23619,
    SPR_WOODEN_RC_QUARTER_TURN_5_SE_NE_SEQ_0 = 23620,
    SPR_WOODEN_RC_QUARTER_TURN_5_SE_NE_SEQ_2 = 23621,
    SPR_WOODEN_RC_QUARTER_TURN_5_SE_NE_SEQ_3 = 23622,
    SPR_WOODEN_RC_QUARTER_TURN_5_SE_NE_SEQ_5 = 23623,
    SPR_WOODEN_RC_QUARTER_TURN_5_SE_NE_SEQ_6 = 23624,
    SPR_WOODEN_RC_QUARTER_TURN_5_FRONT_SW_SE_SEQ_0 = 23625,
    SPR_WOODEN_RC_QUARTER_TURN_5_FRONT_SW_SE_SEQ_2 = 23626,
    SPR_WOODEN_RC_QUARTER_TURN_5_FRONT_SW_SE_SEQ_3 = 23627,
    SPR_WOODEN_RC_QUARTER_TURN_5_FRONT_SW_SE_SEQ_5 = 23628,
    SPR_WOODEN_RC_QUARTER_TURN_5_FRONT_SW_SE_SEQ_6 = 23629,
    SPR_WOODEN_RC_QUARTER_TURN_5_FRONT_NE_NW_SEQ_0 = 23630,
    SPR_WOODEN_RC_QUARTER_TURN_5_FRONT_NE_NW_SEQ_2 = 23631,
    SPR_WOODEN_RC_QUARTER_TURN_5_FRONT_NE_NW_SEQ_3 = 23632,
    SPR_WOODEN_RC_QUARTER_TURN_5_FRONT_NE_NW_SEQ_5 = 23633,
    SPR_WOODEN_RC_QUARTER_TURN_5_FRONT_NE_NW_SEQ_6 = 23634,


    SPR_WOODEN_RC_FLAT_CHAIN_SW_NE = 23749,
    SPR_WOODEN_RC_FLAT_CHAIN_NW_SE = 23750,
    SPR_WOODEN_RC_FLAT_CHAIN_NE_SW = 23751,
    SPR_WOODEN_RC_FLAT_CHAIN_SE_NW = 23752,
    SPR_WOODEN_RC_FLAT_SW_NE = 23753,
    SPR_WOODEN_RC_FLAT_NW_SE = 23754,
    SPR_WOODEN_RC_BRAKES_SW_NE = 23755,
    SPR_WOODEN_RC_BRAKES_NW_SE = 23756,
    SPR_WOODEN_RC_BLOCK_BRAKES_SW_NE_OPEN = 23757,
    SPR_WOODEN_RC_BLOCK_BRAKES_NW_SE_OPEN = 23758,
    SPR_WOODEN_RC_BLOCK_BRAKES_SW_NE_CLOSED = 23759,
    SPR_WOODEN_RC_BLOCK_BRAKES_NW_SE_CLOSED = 23760,

    SPR_WOODEN_RC_STATION_SW_NE = 23973,
    SPR_WOODEN_RC_STATION_NW_SE = 23974,
    
    SPR_WOODEN_RC_FLAT_TO_25_DEG_RAILS_SW_NE = 24403,
    SPR_WOODEN_RC_FLAT_TO_25_DEG_RAILS_NW_SE = 24404,
    SPR_WOODEN_RC_FLAT_TO_25_DEG_RAILS_NE_SW = 24405,
    SPR_WOODEN_RC_FLAT_TO_25_DEG_RAILS_SE_NW = 24406,
    SPR_WOODEN_RC_25_DEG_TO_FLAT_RAILS_SW_NE = 24407,
    SPR_WOODEN_RC_25_DEG_TO_FLAT_RAILS_NW_SE = 24408,
    SPR_WOODEN_RC_25_DEG_TO_FLAT_RAILS_NE_SW = 24409,
    SPR_WOODEN_RC_25_DEG_TO_FLAT_RAILS_SE_NW = 24410,
    SPR_WOODEN_RC_25_DEG_RAILS_SW_NE = 24411,
    SPR_WOODEN_RC_25_DEG_RAILS_NW_SE = 24412,
    SPR_WOODEN_RC_25_DEG_RAILS_NE_SW = 24413,
    SPR_WOODEN_RC_25_DEG_RAILS_SE_NW = 24414,
    SPR_WOODEN_RC_25_DEG_TO_60_DEG_RAILS_SW_NE = 24415,
    SPR_WOODEN_RC_25_DEG_TO_60_DEG_RAILS_FRONT_NW_SE = 24416,
    SPR_WOODEN_RC_25_DEG_TO_60_DEG_RAILS_NW_SE = 24417,
    SPR_WOODEN_RC_25_DEG_TO_60_DEG_RAILS_FRONT_NE_SW = 24418,
    SPR_WOODEN_RC_25_DEG_TO_60_DEG_RAILS_NE_SW = 24419,
    SPR_WOODEN_RC_25_DEG_TO_60_DEG_RAILS_SE_NW = 24420,
    SPR_WOODEN_RC_60_DEG_TO_25_DEG_RAILS_SW_NE = 24421,
    SPR_WOODEN_RC_60_DEG_TO_25_DEG_RAILS_FRONT_NW_SE = 24422,
    SPR_WOODEN_RC_60_DEG_TO_25_DEG_RAILS_NW_SE = 24423,
    SPR_WOODEN_RC_60_DEG_TO_25_DEG_RAILS_FRONT_NE_SW = 24424,
    SPR_WOODEN_RC_60_DEG_TO_25_DEG_RAILS_NE_SW = 24425,
    SPR_WOODEN_RC_60_DEG_TO_25_DEG_RAILS_SE_NW = 24426,
    SPR_WOODEN_RC_60_DEG_RAILS_SW_NE = 24427,
    SPR_WOODEN_RC_60_DEG_CHAIN_RAILS_SW_NE = 24427,
    SPR_WOODEN_RC_60_DEG_RAILS_NW_SE = 24428,
    SPR_WOODEN_RC_60_DEG_CHAIN_RAILS_NW_SE = 24428,
    SPR_WOODEN_RC_60_DEG_RAILS_NE_SW = 24429,
    SPR_WOODEN_RC_60_DEG_CHAIN_RAILS_NE_SW = 24429,
    SPR_WOODEN_RC_60_DEG_RAILS_SE_NW = 24430,
    SPR_WOODEN_RC_60_DEG_CHAIN_RAILS_SE_NW = 24430,
    SPR_WOODEN_RC_FLAT_TO_25_DEG_RAILS_FRONT_NW_SE = 24431,
    SPR_WOODEN_RC_FLAT_TO_25_DEG_RAILS_FRONT_NE_SW = 24432,
    SPR_WOODEN_RC_25_DEG_TO_FLAT_RAILS_FRONT_NW_SE = 24433,
    SPR_WOODEN_RC_25_DEG_TO_FLAT_RAILS_FRONT_NE_SW = 24434,
    SPR_WOODEN_RC_25_DEG_RAILS_FRONT_NW_SE = 24435,
    SPR_WOODEN_RC_60_DEG_RAILS_FRONT_NW_SE = 24435,
    SPR_WOODEN_RC_25_DEG_RAILS_FRONT_NE_SW = 24436,
    SPR_WOODEN_RC_60_DEG_RAILS_FRONT_NE_SW = 24436,
    SPR_WOODEN_RC_FLAT_TO_25_DEG_CHAIN_RAILS_SW_NE = 24437,
    SPR_WOODEN_RC_FLAT_TO_25_DEG_CHAIN_RAILS_NW_SE = 24438,
    SPR_WOODEN_RC_FLAT_TO_25_DEG_CHAIN_RAILS_NE_SW = 24439,
    SPR_WOODEN_RC_FLAT_TO_25_DEG_CHAIN_RAILS_SE_NW = 24440,
    SPR_WOODEN_RC_25_DEG_TO_FLAT_CHAIN_RAILS_SW_NE = 24441,
    SPR_WOODEN_RC_25_DEG_TO_FLAT_CHAIN_RAILS_NW_SE = 24442,
    SPR_WOODEN_RC_25_DEG_TO_FLAT_CHAIN_RAILS_NE_SW = 24443,
    SPR_WOODEN_RC_25_DEG_TO_FLAT_CHAIN_RAILS_SE_NW = 24444,
    SPR_WOODEN_RC_25_DEG_CHAIN_RAILS_SW_NE = 24445,
    SPR_WOODEN_RC_25_DEG_CHAIN_RAILS_NW_SE = 24446,
    SPR_WOODEN_RC_25_DEG_CHAIN_RAILS_NE_SW = 24447,
    SPR_WOODEN_RC_25_DEG_CHAIN_RAILS_SE_NW = 24448,

    SPR_WOODEN_RC_FLAT_TO_25_DEG_CHAIN_RAILS_FRONT_NW_SE = 24465,
    SPR_WOODEN_RC_FLAT_TO_25_DEG_CHAIN_RAILS_FRONT_NE_SW = 24466,
    SPR_WOODEN_RC_25_DEG_TO_FLAT_CHAIN_RAILS_FRONT_NW_SE = 24467,
    SPR_WOODEN_RC_25_DEG_TO_FLAT_CHAIN_RAILS_FRONT_NE_SW = 24468,
    SPR_WOODEN_RC_25_DEG_CHAIN_RAILS_FRONT_NW_SE = 24469,
    SPR_WOODEN_RC_60_DEG_CHAIN_RAILS_FRONT_NW_SE = 24469,
    SPR_WOODEN_RC_25_DEG_CHAIN_RAILS_FRONT_NE_SW = 24470,
    SPR_WOODEN_RC_60_DEG_CHAIN_RAILS_FRONT_NE_SW = 24470,
    SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_SW_SE_SEQ_0 = 24471,
    SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_SW_SE_SEQ_2 = 24472,
    SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_SW_SE_SEQ_3 = 24473,
    SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_SW_SE_SEQ_5 = 24474,
    SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_SW_SE_SEQ_6 = 24475,
    SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_NW_SW_SEQ_0 = 24476,
    SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_NW_SW_SEQ_2 = 24477,
    SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_NW_SW_SEQ_3 = 24478,
    SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_NW_SW_SEQ_5 = 24479,
    SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_NW_SW_SEQ_6 = 24480,
    SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_NE_NW_SEQ_0 = 24481,
    SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_NE_NW_SEQ_2 = 24482,
    SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_NE_NW_SEQ_3 = 24483,
    SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_NE_NW_SEQ_5 = 24484,
    SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_NE_NW_SEQ_6 = 24485,
    SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_SE_NE_SEQ_0 = 24486,
    SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_SE_NE_SEQ_2 = 24487,
    SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_SE_NE_SEQ_3 = 24488,
    SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_SE_NE_SEQ_5 = 24489,
    SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_SE_NE_SEQ_6 = 24490,
    SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_FRONT_SW_SE_SEQ_0 = 24491,
    SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_FRONT_SW_SE_SEQ_2 = 24492,
    SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_FRONT_SW_SE_SEQ_3 = 24493,
    SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_FRONT_SW_SE_SEQ_5 = 24494,
    SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_FRONT_SW_SE_SEQ_6 = 24495,
    SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_FRONT_NE_NW_SEQ_0 = 24496,
    SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_FRONT_NE_NW_SEQ_2 = 24497,
    SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_FRONT_NE_NW_SEQ_3 = 24498,
    SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_FRONT_NE_NW_SEQ_5 = 24499,
    SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_FRONT_NE_NW_SEQ_6 = 24500,

    SPR_WOODEN_RC_FLAT_CHAIN_RAILS_SW_NE = 24615,
    SPR_WOODEN_RC_FLAT_CHAIN_RAILS_NW_SE = 24616,
    SPR_WOODEN_RC_FLAT_CHAIN_RAILS_NE_SW = 24617,
    SPR_WOODEN_RC_FLAT_CHAIN_RAILS_SE_NW = 24618,
    SPR_WOODEN_RC_FLAT_RAILS_SW_NE = 24619,
    SPR_WOODEN_RC_FLAT_RAILS_NW_SE = 24620,
    SPR_WOODEN_RC_BRAKES_RAILS_SW_NE = 24621,
    SPR_WOODEN_RC_BRAKES_RAILS_NW_SE = 24622,
    SPR_WOODEN_RC_BLOCK_BRAKES_RAILS_SW_NE = 24623,
    SPR_WOODEN_RC_BLOCK_BRAKES_RAILS_NW_SE = 24624,

    SPR_WOODEN_RC_STATION_RAILS_SW_NE = 24839,
    SPR_WOODEN_RC_STATION_RAILS_NW_SE = 24840,
};

static constexpr const uint32_t _wooden_rc_block_brakes_image_ids[4][3] = {
    { SPR_WOODEN_RC_BLOCK_BRAKES_SW_NE_OPEN, SPR_WOODEN_RC_BLOCK_BRAKES_SW_NE_CLOSED, SPR_WOODEN_RC_BLOCK_BRAKES_RAILS_SW_NE },
    { SPR_WOODEN_RC_BLOCK_BRAKES_NW_SE_OPEN, SPR_WOODEN_RC_BLOCK_BRAKES_NW_SE_CLOSED, SPR_WOODEN_RC_BLOCK_BRAKES_RAILS_NW_SE },
    { SPR_WOODEN_RC_BLOCK_BRAKES_SW_NE_OPEN, SPR_WOODEN_RC_BLOCK_BRAKES_SW_NE_CLOSED, SPR_WOODEN_RC_BLOCK_BRAKES_RAILS_SW_NE },
    { SPR_WOODEN_RC_BLOCK_BRAKES_NW_SE_OPEN, SPR_WOODEN_RC_BLOCK_BRAKES_NW_SE_CLOSED, SPR_WOODEN_RC_BLOCK_BRAKES_RAILS_NW_SE },
};

struct sprite_bb_2
{
    uint32_t sprite_id_a;
    uint32_t sprite_id_b;
    CoordsXYZ offset;
    CoordsXYZ bb_offset;
    CoordsXYZ bb_size;
};

template<bool isClassic> static uint32_t wooden_rc_get_track_colour(paint_session* session)
{
    if (isClassic)
        return session->TrackColours[SCHEME_TRACK];
    else
        return (session->TrackColours[SCHEME_TRACK] & ~0xF80000) | session->TrackColours[SCHEME_SUPPORTS];
}

constexpr uint32_t wooden_rc_get_rails_colour(paint_session* session)
{
    return session->TrackColours[SCHEME_TRACK];
}

template<bool isClassic>
paint_struct* wooden_rc_track_paint(
    paint_session* session, uint32_t imageIdTrack, uint32_t imageIdRails, uint8_t direction, int8_t x_offset, int8_t y_offset,
    int16_t bound_box_length_x, int16_t bound_box_length_y, int8_t bound_box_length_z, int16_t z_offset,
    int16_t bound_box_offset_x, int16_t bound_box_offset_y, int16_t bound_box_offset_z)
{
    uint32_t imageId = imageIdTrack | wooden_rc_get_track_colour<isClassic>(session);
    uint32_t railsImageId = imageIdRails | wooden_rc_get_rails_colour(session);

    PaintAddImageAsParentRotated(
        session, direction, imageId, x_offset, y_offset, bound_box_length_x, bound_box_length_y, bound_box_length_z, z_offset,
        bound_box_offset_x, bound_box_offset_y, bound_box_offset_z);
    return PaintAddImageAsChildRotated(
        session, direction, railsImageId, x_offset, y_offset, bound_box_length_x, bound_box_length_y, bound_box_length_z,
        z_offset, bound_box_offset_x, bound_box_offset_y, bound_box_offset_z);
}

template<bool isClassic> void wooden_rc_track_paint_bb(paint_session* session, const sprite_bb_2* bb, int16_t height)
{
    if (bb->sprite_id_a == 0)
        return;

    uint32_t imageId = bb->sprite_id_a | wooden_rc_get_track_colour<isClassic>(session);
    uint32_t railsImageId = bb->sprite_id_b | wooden_rc_get_rails_colour(session);

    PaintAddImageAsParent(
        session, imageId, static_cast<int8_t>(bb->offset.x), static_cast<int8_t>(bb->offset.y), bb->bb_size.x, bb->bb_size.y,
        static_cast<int8_t>(bb->bb_size.z), height + bb->offset.z, bb->bb_offset.x, bb->bb_offset.y, height + bb->bb_offset.z);
    PaintAddImageAsChild(
        session, railsImageId, static_cast<int8_t>(bb->offset.x), static_cast<int8_t>(bb->offset.y), bb->bb_size.x,
        bb->bb_size.y, static_cast<int8_t>(bb->bb_size.z), height + bb->offset.z, bb->bb_offset.x, bb->bb_offset.y,
        height + bb->bb_offset.z);
}

/** rct2: 0x008AC568 */
template<bool isClassic>
static void wooden_rc_track_flat(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    static constexpr const uint32_t imageIds[4][2] = {
        { SPR_WOODEN_RC_FLAT_SW_NE, SPR_WOODEN_RC_FLAT_CHAIN_SW_NE },
        { SPR_WOODEN_RC_FLAT_NW_SE, SPR_WOODEN_RC_FLAT_CHAIN_NW_SE },
        { SPR_WOODEN_RC_FLAT_SW_NE, SPR_WOODEN_RC_FLAT_CHAIN_NE_SW },
        { SPR_WOODEN_RC_FLAT_NW_SE, SPR_WOODEN_RC_FLAT_CHAIN_SE_NW },
    };
    static constexpr const uint32_t railsImageIds[4][2] = {
        { SPR_WOODEN_RC_FLAT_RAILS_SW_NE, SPR_WOODEN_RC_FLAT_CHAIN_RAILS_SW_NE },
        { SPR_WOODEN_RC_FLAT_RAILS_NW_SE, SPR_WOODEN_RC_FLAT_CHAIN_RAILS_NW_SE },
        { SPR_WOODEN_RC_FLAT_RAILS_SW_NE, SPR_WOODEN_RC_FLAT_CHAIN_RAILS_NE_SW },
        { SPR_WOODEN_RC_FLAT_RAILS_NW_SE, SPR_WOODEN_RC_FLAT_CHAIN_RAILS_SE_NW },
    };

    uint8_t isChained = tileElement->AsTrack()->HasChain() ? 1 : 0;
    wooden_rc_track_paint<isClassic>(
        session, imageIds[direction][isChained], railsImageIds[direction][isChained], direction, 0, 2, 32, 25, 2, height, 0, 3,
        height);
    wooden_a_supports_paint_setup(session, direction & 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
    paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_FLAT);
    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 32, 0x20);
}

template<bool isClassic>
static void wooden_rc_track_station(
    paint_session* session, ride_id_t rideIndex, [[maybe_unused]] uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    static constexpr const uint32_t stationImageIds[4][2] = {
        { SPR_WOODEN_RC_STATION_SW_NE, SPR_WOODEN_RC_STATION_RAILS_SW_NE },
        { SPR_WOODEN_RC_STATION_NW_SE, SPR_WOODEN_RC_STATION_RAILS_NW_SE },
        { SPR_WOODEN_RC_STATION_SW_NE, SPR_WOODEN_RC_STATION_RAILS_SW_NE },
        { SPR_WOODEN_RC_STATION_NW_SE, SPR_WOODEN_RC_STATION_RAILS_NW_SE },
    };

    int32_t trackType = tileElement->AsTrack()->GetTrackType();
    if (trackType == TrackElemType::EndStation)
    {
        const auto brakeImg = tileElement->AsTrack()->BlockBrakeClosed() ? _wooden_rc_block_brakes_image_ids[direction][1]
                                                                         : _wooden_rc_block_brakes_image_ids[direction][0];
        wooden_rc_track_paint<isClassic>(
            session, brakeImg, _wooden_rc_block_brakes_image_ids[direction][2], direction, 0, 2, 32, 27, 2, height, 0, 2,
            height);
    }
    else
    {
        wooden_rc_track_paint<isClassic>(
            session, stationImageIds[direction][0], stationImageIds[direction][1], direction, 0, 2, 32, 27, 2, height, 0, 2,
            height);
    }
    wooden_a_supports_paint_setup(session, direction & 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
    track_paint_util_draw_station_2(session, rideIndex, direction, height, tileElement, 9, 11);
    paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_FLAT);
    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 32, 0x20);
}

/** rct2: 0x008AC578 */
template<bool isClassic>
static void wooden_rc_track_25_deg_up(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    static constexpr const uint32_t imageIds[2][4][4] = {
        {
            { SPR_WOODEN_RC_25_DEG_SW_NE, SPR_WOODEN_RC_25_DEG_RAILS_SW_NE, 0, 0 },
            { SPR_WOODEN_RC_25_DEG_NW_SE, SPR_WOODEN_RC_25_DEG_RAILS_NW_SE, SPR_WOODEN_RC_25_DEG_FRONT_NW_SE,
              SPR_WOODEN_RC_25_DEG_RAILS_FRONT_NW_SE },
            { SPR_WOODEN_RC_25_DEG_NE_SW, SPR_WOODEN_RC_25_DEG_RAILS_NE_SW, SPR_WOODEN_RC_25_DEG_FRONT_NE_SW,
              SPR_WOODEN_RC_25_DEG_RAILS_FRONT_NE_SW },
            { SPR_WOODEN_RC_25_DEG_SE_NW, SPR_WOODEN_RC_25_DEG_RAILS_SE_NW, 0, 0 },
        },
        {
            { SPR_WOODEN_RC_25_DEG_CHAIN_SW_NE, SPR_WOODEN_RC_25_DEG_CHAIN_RAILS_SW_NE, 0, 0 },
            { SPR_WOODEN_RC_25_DEG_CHAIN_NW_SE, SPR_WOODEN_RC_25_DEG_CHAIN_RAILS_NW_SE, SPR_WOODEN_RC_25_DEG_CHAIN_FRONT_NW_SE,
              SPR_WOODEN_RC_25_DEG_CHAIN_RAILS_FRONT_NW_SE },
            { SPR_WOODEN_RC_25_DEG_CHAIN_NE_SW, SPR_WOODEN_RC_25_DEG_CHAIN_RAILS_NE_SW, SPR_WOODEN_RC_25_DEG_CHAIN_FRONT_NE_SW,
              SPR_WOODEN_RC_25_DEG_CHAIN_RAILS_FRONT_NE_SW },
            { SPR_WOODEN_RC_25_DEG_CHAIN_SE_NW, SPR_WOODEN_RC_25_DEG_CHAIN_RAILS_SE_NW, 0, 0 },
        }
    };

    uint8_t isChained = tileElement->AsTrack()->HasChain() ? 1 : 0;
    wooden_rc_track_paint<isClassic>(
        session, imageIds[isChained][direction][0], imageIds[isChained][direction][1], direction, 0, 0, 32, 25, 2, height, 0, 3,
        height);
    if (direction == 1 || direction == 2)
    {
        wooden_rc_track_paint<isClassic>(
            session, imageIds[isChained][direction][2], imageIds[isChained][direction][3], direction, 0, 0, 32, 1, 9, height, 0,
            26, height + 5);
    }
    wooden_a_supports_paint_setup(
        session, direction & 1, 9 + direction, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);

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

/** rct2: 0x008AC588 */
template<bool isClassic>
static void wooden_rc_track_60_deg_up(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    static constexpr const uint32_t imageIds[4][2] = {
        { SPR_WOODEN_RC_60_DEG_SW_NE, SPR_WOODEN_RC_60_DEG_RAILS_SW_NE },
        { SPR_WOODEN_RC_60_DEG_NW_SE, SPR_WOODEN_RC_60_DEG_RAILS_NW_SE },
        { SPR_WOODEN_RC_60_DEG_NE_SW, SPR_WOODEN_RC_60_DEG_RAILS_NE_SW },
        { SPR_WOODEN_RC_60_DEG_SE_NW, SPR_WOODEN_RC_60_DEG_RAILS_SE_NW },
    };

    if (direction == 0 || direction == 3)
    {
        wooden_rc_track_paint<isClassic>(
            session, imageIds[direction][0], imageIds[direction][1], direction, 0, 0, 32, 25, 2, height, 0, 3, height);
    }
    else
    {
        session->WoodenSupportsPrependTo = wooden_rc_track_paint<isClassic>(
            session, imageIds[direction][0], imageIds[direction][1], direction, 0, 0, 2, 24, 93, height, 28, 4, height - 16);
    }
    wooden_a_supports_paint_setup(
        session, direction & 1, 21 + direction, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);

    if (direction == 0 || direction == 3)
    {
        paint_util_push_tunnel_rotated(session, direction, height - 8, TUNNEL_SQUARE_7);
    }
    else
    {
        paint_util_push_tunnel_rotated(session, direction, height + 56, TUNNEL_SQUARE_8);
    }

    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 104, 0x20);
}

/** rct2: 0x008AC598 */
template<bool isClassic>
static void wooden_rc_track_flat_to_25_deg_up(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    static constexpr const uint32_t imageIds[2][4][4] = {
        {
            { SPR_WOODEN_RC_FLAT_TO_25_DEG_SW_NE, SPR_WOODEN_RC_FLAT_TO_25_DEG_RAILS_SW_NE, 0, 0 },
            { SPR_WOODEN_RC_FLAT_TO_25_DEG_NW_SE, SPR_WOODEN_RC_FLAT_TO_25_DEG_RAILS_NW_SE,
              SPR_WOODEN_RC_FLAT_TO_25_DEG_FRONT_NW_SE, SPR_WOODEN_RC_FLAT_TO_25_DEG_RAILS_FRONT_NW_SE },
            { SPR_WOODEN_RC_FLAT_TO_25_DEG_NE_SW, SPR_WOODEN_RC_FLAT_TO_25_DEG_RAILS_NE_SW,
              SPR_WOODEN_RC_FLAT_TO_25_DEG_FRONT_NE_SW, SPR_WOODEN_RC_FLAT_TO_25_DEG_RAILS_FRONT_NE_SW },
            { SPR_WOODEN_RC_FLAT_TO_25_DEG_SE_NW, SPR_WOODEN_RC_FLAT_TO_25_DEG_RAILS_SE_NW, 0, 0 },
        },
        {
            { SPR_WOODEN_RC_FLAT_TO_25_DEG_CHAIN_SW_NE, SPR_WOODEN_RC_FLAT_TO_25_DEG_CHAIN_RAILS_SW_NE, 0, 0 },
            { SPR_WOODEN_RC_FLAT_TO_25_DEG_CHAIN_NW_SE, SPR_WOODEN_RC_FLAT_TO_25_DEG_CHAIN_RAILS_NW_SE,
              SPR_WOODEN_RC_FLAT_TO_25_DEG_CHAIN_FRONT_NW_SE, SPR_WOODEN_RC_FLAT_TO_25_DEG_CHAIN_RAILS_FRONT_NW_SE },
            { SPR_WOODEN_RC_FLAT_TO_25_DEG_CHAIN_NE_SW, SPR_WOODEN_RC_FLAT_TO_25_DEG_CHAIN_RAILS_NE_SW,
              SPR_WOODEN_RC_FLAT_TO_25_DEG_CHAIN_FRONT_NE_SW, SPR_WOODEN_RC_FLAT_TO_25_DEG_CHAIN_RAILS_FRONT_NE_SW },
            { SPR_WOODEN_RC_FLAT_TO_25_DEG_CHAIN_SE_NW, SPR_WOODEN_RC_FLAT_TO_25_DEG_CHAIN_RAILS_SE_NW, 0, 0 },
        }
    };

    uint8_t isChained = tileElement->AsTrack()->HasChain() ? 1 : 0;
    wooden_rc_track_paint<isClassic>(
        session, imageIds[isChained][direction][0], imageIds[isChained][direction][1], direction, 0, 0, 32, 25, 2, height, 0, 3,
        height);
    if (direction == 1 || direction == 2)
    {
        wooden_rc_track_paint<isClassic>(
            session, imageIds[isChained][direction][2], imageIds[isChained][direction][3], direction, 0, 0, 32, 1, 9, height, 0,
            26, height + 5);
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

/** rct2: 0x008AC5A8 */
template<bool isClassic>
static void wooden_rc_track_25_deg_up_to_60_deg_up(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    static constexpr const uint32_t imageIds[4][4] = {
        { SPR_WOODEN_RC_25_DEG_TO_60_DEG_SW_NE, SPR_WOODEN_RC_25_DEG_TO_60_DEG_RAILS_SW_NE, 0, 0 },
        { SPR_WOODEN_RC_25_DEG_TO_60_DEG_NW_SE, SPR_WOODEN_RC_25_DEG_TO_60_DEG_RAILS_NW_SE,
          SPR_WOODEN_RC_25_DEG_TO_60_DEG_FRONT_NW_SE, SPR_WOODEN_RC_25_DEG_TO_60_DEG_RAILS_FRONT_NW_SE },
        { SPR_WOODEN_RC_25_DEG_TO_60_DEG_NE_SW, SPR_WOODEN_RC_25_DEG_TO_60_DEG_RAILS_NE_SW,
          SPR_WOODEN_RC_25_DEG_TO_60_DEG_FRONT_NE_SW, SPR_WOODEN_RC_25_DEG_TO_60_DEG_RAILS_FRONT_NE_SW },
        { SPR_WOODEN_RC_25_DEG_TO_60_DEG_SE_NW, SPR_WOODEN_RC_25_DEG_TO_60_DEG_RAILS_SE_NW, 0, 0 },
    };

    if (direction == 0 || direction == 3)
    {
        wooden_rc_track_paint<isClassic>(
            session, imageIds[direction][0], imageIds[direction][1], direction, 0, 0, 32, 25, 2, height, 0, 3, height);
    }
    else
    {
        session->WoodenSupportsPrependTo = wooden_rc_track_paint<isClassic>(
            session, imageIds[direction][0], imageIds[direction][1], direction, 0, 0, 2, 24, 43, height, 28, 4, height + 2);
        wooden_rc_track_paint<isClassic>(
            session, imageIds[direction][2], imageIds[direction][3], direction, 0, 0, 32, 2, 43, height, 0, 4, height);
    }
    wooden_a_supports_paint_setup(
        session, direction & 1, 13 + direction, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);

    if (direction == 0 || direction == 3)
    {
        paint_util_push_tunnel_rotated(session, direction, height - 8, TUNNEL_SQUARE_7);
    }
    else
    {
        paint_util_push_tunnel_rotated(session, direction, height + 24, TUNNEL_SQUARE_8);
    }

    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 72, 0x20);
}

/** rct2: 0x008AC5B8 */
template<bool isClassic>
static void wooden_rc_track_60_deg_up_to_25_deg_up(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    static constexpr const uint32_t imageIds[4][4] = {
        { SPR_WOODEN_RC_60_DEG_TO_25_DEG_SW_NE, SPR_WOODEN_RC_60_DEG_TO_25_DEG_RAILS_SW_NE, 0, 0 },
        { SPR_WOODEN_RC_60_DEG_TO_25_DEG_NW_SE, SPR_WOODEN_RC_60_DEG_TO_25_DEG_RAILS_NW_SE,
          SPR_WOODEN_RC_60_DEG_TO_25_DEG_FRONT_NW_SE, SPR_WOODEN_RC_60_DEG_TO_25_DEG_RAILS_FRONT_NW_SE },
        { SPR_WOODEN_RC_60_DEG_TO_25_DEG_NE_SW, SPR_WOODEN_RC_60_DEG_TO_25_DEG_RAILS_NE_SW,
          SPR_WOODEN_RC_60_DEG_TO_25_DEG_FRONT_NE_SW, SPR_WOODEN_RC_60_DEG_TO_25_DEG_RAILS_FRONT_NE_SW },
        { SPR_WOODEN_RC_60_DEG_TO_25_DEG_SE_NW, SPR_WOODEN_RC_60_DEG_TO_25_DEG_RAILS_SE_NW, 0, 0 },
    };

    if (direction == 0 || direction == 3)
    {
        wooden_rc_track_paint<isClassic>(
            session, imageIds[direction][0], imageIds[direction][1], direction, 0, 0, 32, 25, 2, height, 0, 3, height);
    }
    else
    {
        session->WoodenSupportsPrependTo = wooden_rc_track_paint<isClassic>(
            session, imageIds[direction][0], imageIds[direction][1], direction, 0, 0, 24, 1, 61, height, 4, 28, height - 16);
        wooden_rc_track_paint<isClassic>(
            session, imageIds[direction][2], imageIds[direction][3], direction, 0, 0, 32, 2, 43, height, 0, 4, height);
    }
    wooden_a_supports_paint_setup(
        session, direction & 1, 17 + direction, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);

    if (direction == 0 || direction == 3)
    {
        paint_util_push_tunnel_rotated(session, direction, height - 8, TUNNEL_SQUARE_7);
    }
    else
    {
        paint_util_push_tunnel_rotated(session, direction, height + 24, TUNNEL_SQUARE_8);
    }

    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 72, 0x20);
}

/** rct2: 0x008AC5C8 */
template<bool isClassic>
static void wooden_rc_track_25_deg_up_to_flat(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    static constexpr const uint32_t imageIds[2][4][4] = {
        {
            { SPR_WOODEN_RC_25_DEG_TO_FLAT_SW_NE, SPR_WOODEN_RC_25_DEG_TO_FLAT_RAILS_SW_NE, 0, 0 },
            { SPR_WOODEN_RC_25_DEG_TO_FLAT_NW_SE, SPR_WOODEN_RC_25_DEG_TO_FLAT_RAILS_NW_SE,
              SPR_WOODEN_RC_25_DEG_TO_FLAT_FRONT_NW_SE, SPR_WOODEN_RC_25_DEG_TO_FLAT_RAILS_FRONT_NW_SE },
            { SPR_WOODEN_RC_25_DEG_TO_FLAT_NE_SW, SPR_WOODEN_RC_25_DEG_TO_FLAT_RAILS_NE_SW,
              SPR_WOODEN_RC_25_DEG_TO_FLAT_FRONT_NE_SW, SPR_WOODEN_RC_25_DEG_TO_FLAT_RAILS_FRONT_NE_SW },
            { SPR_WOODEN_RC_25_DEG_TO_FLAT_SE_NW, SPR_WOODEN_RC_25_DEG_TO_FLAT_RAILS_SE_NW, 0, 0 },
        },
        {
            { SPR_WOODEN_RC_25_DEG_TO_FLAT_CHAIN_SW_NE, SPR_WOODEN_RC_25_DEG_TO_FLAT_CHAIN_RAILS_SW_NE, 0, 0 },
            { SPR_WOODEN_RC_25_DEG_TO_FLAT_CHAIN_NW_SE, SPR_WOODEN_RC_25_DEG_TO_FLAT_CHAIN_RAILS_NW_SE,
              SPR_WOODEN_RC_25_DEG_TO_FLAT_CHAIN_FRONT_NW_SE, SPR_WOODEN_RC_25_DEG_TO_FLAT_CHAIN_RAILS_FRONT_NW_SE },
            { SPR_WOODEN_RC_25_DEG_TO_FLAT_CHAIN_NE_SW, SPR_WOODEN_RC_25_DEG_TO_FLAT_CHAIN_RAILS_NE_SW,
              SPR_WOODEN_RC_25_DEG_TO_FLAT_CHAIN_FRONT_NE_SW, SPR_WOODEN_RC_25_DEG_TO_FLAT_CHAIN_RAILS_FRONT_NE_SW },
            { SPR_WOODEN_RC_25_DEG_TO_FLAT_CHAIN_SE_NW, SPR_WOODEN_RC_25_DEG_TO_FLAT_CHAIN_RAILS_SE_NW, 0, 0 },
        }
    };

    uint8_t isChained = tileElement->AsTrack()->HasChain() ? 1 : 0;
    wooden_rc_track_paint<isClassic>(
        session, imageIds[isChained][direction][0], imageIds[isChained][direction][1], direction, 0, 0, 32, 25, 2, height, 0, 3,
        height);
    if (direction == 1 || direction == 2)
    {
        wooden_rc_track_paint<isClassic>(
            session, imageIds[isChained][direction][2], imageIds[isChained][direction][3], direction, 0, 0, 32, 1, 9, height, 0,
            26, height + 5);
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

/** rct2: 0x008AC5D8 */
template<bool isClassic>
static void wooden_rc_track_25_deg_down(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    wooden_rc_track_25_deg_up<isClassic>(session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

/** rct2: 0x008AC5E8 */
template<bool isClassic>
static void wooden_rc_track_60_deg_down(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    wooden_rc_track_60_deg_up<isClassic>(session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

/** rct2: 0x008AC5F8 */
template<bool isClassic>
static void wooden_rc_track_flat_to_25_deg_down(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    wooden_rc_track_25_deg_up_to_flat<isClassic>(session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

/** rct2: 0x008AC608 */
template<bool isClassic>
static void wooden_rc_track_25_deg_down_to_60_deg_down(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    wooden_rc_track_60_deg_up_to_25_deg_up<isClassic>(
        session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

/** rct2: 0x008AC618 */
template<bool isClassic>
static void wooden_rc_track_60_deg_down_to_25_deg_down(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    wooden_rc_track_25_deg_up_to_60_deg_up<isClassic>(
        session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

/** rct2: 0x008AC628 */
template<bool isClassic>
static void wooden_rc_track_25_deg_down_to_flat(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    wooden_rc_track_flat_to_25_deg_up<isClassic>(session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

template<bool isClassic>
static void wooden_rc_track_right_quarter_turn_5(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    static constexpr const sprite_bb_2 imageIds[2][4][7] = {
        { {
              { SPR_WOODEN_RC_QUARTER_TURN_5_SW_SE_SEQ_0,
                SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_SW_SE_SEQ_0,
                { 0, 2, 0 },
                { 0, 2, 0 },
                { 32, 32, 2 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_WOODEN_RC_QUARTER_TURN_5_SW_SE_SEQ_2,
                SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_SW_SE_SEQ_2,
                { 0, 16, 0 },
                { 0, 16, 0 },
                { 32, 16, 2 } },
              { SPR_WOODEN_RC_QUARTER_TURN_5_SW_SE_SEQ_3,
                SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_SW_SE_SEQ_3,
                { 0, 0, 0 },
                { 0, 0, 0 },
                { 16, 16, 2 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_WOODEN_RC_QUARTER_TURN_5_SW_SE_SEQ_5,
                SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_SW_SE_SEQ_5,
                { 16, 0, 0 },
                { 16, 0, 0 },
                { 16, 32, 2 } },
              { SPR_WOODEN_RC_QUARTER_TURN_5_SW_SE_SEQ_6,
                SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_SW_SE_SEQ_6,
                { 2, 0, 0 },
                { 2, 0, 0 },
                { 32, 32, 2 } },
          },
          {
              { SPR_WOODEN_RC_QUARTER_TURN_5_NW_SW_SEQ_0,
                SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_NW_SW_SEQ_0,
                { 2, 0, 0 },
                { 2, 0, 0 },
                { 32, 32, 2 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_WOODEN_RC_QUARTER_TURN_5_NW_SW_SEQ_2,
                SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_NW_SW_SEQ_2,
                { 16, 0, 0 },
                { 16, 0, 0 },
                { 16, 34, 2 } },
              { SPR_WOODEN_RC_QUARTER_TURN_5_NW_SW_SEQ_3,
                SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_NW_SW_SEQ_3,
                { 0, 16, 0 },
                { 0, 16, 0 },
                { 16, 16, 2 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_WOODEN_RC_QUARTER_TURN_5_NW_SW_SEQ_5,
                SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_NW_SW_SEQ_5,
                { 0, 0, 0 },
                { 0, 0, 0 },
                { 32, 16, 2 } },
              { SPR_WOODEN_RC_QUARTER_TURN_5_NW_SW_SEQ_6,
                SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_NW_SW_SEQ_6,
                { 0, 2, 0 },
                { 0, 2, 0 },
                { 32, 27, 2 } },
          },
          {
              { SPR_WOODEN_RC_QUARTER_TURN_5_NE_NW_SEQ_0,
                SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_NE_NW_SEQ_0,
                { 0, 2, 0 },
                { 0, 2, 0 },
                { 32, 27, 2 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_WOODEN_RC_QUARTER_TURN_5_NE_NW_SEQ_2,
                SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_NE_NW_SEQ_2,
                { 0, 0, 0 },
                { 0, 0, 0 },
                { 32, 16, 2 } },
              { SPR_WOODEN_RC_QUARTER_TURN_5_NE_NW_SEQ_3,
                SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_NE_NW_SEQ_3,
                { 16, 16, 0 },
                { 16, 16, 0 },
                { 16, 16, 2 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_WOODEN_RC_QUARTER_TURN_5_NE_NW_SEQ_5,
                SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_NE_NW_SEQ_5,
                { 0, 0, 0 },
                { 0, 0, 0 },
                { 16, 32, 2 } },
              { SPR_WOODEN_RC_QUARTER_TURN_5_NE_NW_SEQ_6,
                SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_NE_NW_SEQ_6,
                { 2, 0, 0 },
                { 2, 0, 0 },
                { 27, 32, 2 } },
          },
          {
              { SPR_WOODEN_RC_QUARTER_TURN_5_SE_NE_SEQ_0,
                SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_SE_NE_SEQ_0,
                { 2, 0, 0 },
                { 2, 0, 0 },
                { 27, 32, 2 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_WOODEN_RC_QUARTER_TURN_5_SE_NE_SEQ_2,
                SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_SE_NE_SEQ_2,
                { 0, 0, 0 },
                { 0, 0, 0 },
                { 16, 32, 2 } },
              { SPR_WOODEN_RC_QUARTER_TURN_5_SE_NE_SEQ_3,
                SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_SE_NE_SEQ_3,
                { 16, 0, 0 },
                { 16, 0, 0 },
                { 16, 16, 2 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_WOODEN_RC_QUARTER_TURN_5_SE_NE_SEQ_5,
                SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_SE_NE_SEQ_5,
                { 0, 16, 0 },
                { 0, 16, 0 },
                { 32, 16, 2 } },
              { SPR_WOODEN_RC_QUARTER_TURN_5_SE_NE_SEQ_6,
                SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_SE_NE_SEQ_6,
                { 0, 2, 0 },
                { 0, 2, 0 },
                { 32, 32, 2 } },
          } },
        { {
              { SPR_WOODEN_RC_QUARTER_TURN_5_FRONT_SW_SE_SEQ_0,
                SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_FRONT_SW_SE_SEQ_0,
                { 0, 2, 0 },
                { 0, 2, 27 },
                { 32, 32, 0 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_WOODEN_RC_QUARTER_TURN_5_FRONT_SW_SE_SEQ_2,
                SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_FRONT_SW_SE_SEQ_2,
                { 0, 16, 0 },
                { 0, 16, 27 },
                { 32, 16, 0 } },
              { SPR_WOODEN_RC_QUARTER_TURN_5_FRONT_SW_SE_SEQ_3,
                SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_FRONT_SW_SE_SEQ_3,
                { 0, 0, 0 },
                { 0, 0, 27 },
                { 16, 16, 0 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_WOODEN_RC_QUARTER_TURN_5_FRONT_SW_SE_SEQ_5,
                SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_FRONT_SW_SE_SEQ_5,
                { 16, 0, 0 },
                { 16, 0, 27 },
                { 16, 32, 0 } },
              { SPR_WOODEN_RC_QUARTER_TURN_5_FRONT_SW_SE_SEQ_6,
                SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_FRONT_SW_SE_SEQ_6,
                { 2, 0, 0 },
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
              { SPR_WOODEN_RC_QUARTER_TURN_5_FRONT_NE_NW_SEQ_0,
                SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_FRONT_NE_NW_SEQ_0,
                { 0, 2, 0 },
                { 0, 2, 27 },
                { 32, 27, 0 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_WOODEN_RC_QUARTER_TURN_5_FRONT_NE_NW_SEQ_2,
                SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_FRONT_NE_NW_SEQ_2,
                { 0, 0, 0 },
                { 0, 0, 27 },
                { 32, 16, 0 } },
              { SPR_WOODEN_RC_QUARTER_TURN_5_FRONT_NE_NW_SEQ_3,
                SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_FRONT_NE_NW_SEQ_3,
                { 16, 16, 0 },
                { 16, 16, 27 },
                { 16, 16, 0 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_WOODEN_RC_QUARTER_TURN_5_FRONT_NE_NW_SEQ_5,
                SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_FRONT_NE_NW_SEQ_5,
                { 0, 0, 0 },
                { 0, 0, 27 },
                { 16, 32, 0 } },
              { SPR_WOODEN_RC_QUARTER_TURN_5_FRONT_NE_NW_SEQ_6,
                SPR_WOODEN_RC_QUARTER_TURN_5_RAILS_FRONT_NE_NW_SEQ_6,
                { 2, 0, 0 },
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

    wooden_rc_track_paint_bb<isClassic>(session, &imageIds[0][direction][trackSequence], height);
    wooden_rc_track_paint_bb<isClassic>(session, &imageIds[1][direction][trackSequence], height);
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

template<bool isClassic>
static void wooden_rc_track_left_quarter_turn_5(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    trackSequence = mapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence];
    wooden_rc_track_right_quarter_turn_5<isClassic>(
        session, rideIndex, trackSequence, (direction + 1) & 3, height, tileElement);
}

/** rct2: 0x008AC758 */
template<bool isClassic>
static void wooden_rc_track_left_quarter_turn_5_25_deg_up(
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23781, 0, 0, 32, 27, 2, height, 0,
                        2, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24647, 0, 0, 32, 27, 2, height, 0, 2, height);
                    wooden_a_supports_paint_setup(session, 0, 9, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23786, 0, 0, 32, 27, 2, height, 0,
                        2, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24652, 0, 0, 32, 27, 2, height, 0, 2, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23812, 0, 0, 32, 27, 0, height, 0,
                        2, height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24678, 0, 0, 32, 27, 0, height, 0, 2,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 1, 10, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23791, 0, 0, 32, 27, 2, height, 0,
                        2, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24657, 0, 0, 32, 27, 2, height, 0, 2, height);
                    wooden_a_supports_paint_setup(session, 0, 11, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23796, 0, 0, 32, 27, 2, height, 0,
                        2, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24662, 0, 0, 32, 27, 2, height, 0, 2, height);
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23782, 0, 0, 32, 16, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24648, 0, 0, 32, 16, 2, height, 0, 0, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23787, 0, 0, 32, 16, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24653, 0, 0, 32, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23813, 0, 0, 32, 16, 0, height, 0,
                        0, height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24679, 0, 0, 32, 16, 0, height, 0, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23792, 0, 0, 32, 16, 2, height, 0,
                        16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24658, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23797, 0, 0, 32, 16, 2, height, 0,
                        16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24663, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23819, 0, 0, 32, 16, 0, height, 0,
                        16, height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24685, 0, 0, 32, 16, 0, height, 0, 16,
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23783, 0, 0, 16, 16, 2, height, 0,
                        16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24649, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23788, 0, 0, 16, 16, 2, height, 16,
                        16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24654, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23814, 0, 0, 16, 16, 0, height, 16,
                        16, height + 59);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24680, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 59);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23793, 0, 0, 16, 16, 2, height, 16,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24659, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23798, 0, 0, 16, 16, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24664, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23820, 0, 0, 16, 16, 0, height, 0,
                        0, height + 59);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24686, 0, 0, 16, 16, 0, height, 0, 0,
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23784, 0, 0, 16, 32, 2, height, 16,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24650, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23789, 0, 0, 16, 32, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24655, 0, 0, 16, 32, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23815, 0, 0, 16, 32, 0, height, 0,
                        0, height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24681, 0, 0, 16, 32, 0, height, 0, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23794, 0, 0, 16, 32, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24660, 0, 0, 16, 32, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23817, 0, 0, 16, 32, 0, height, 0,
                        0, height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24683, 0, 0, 16, 32, 0, height, 0, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23799, 0, 0, 16, 32, 2, height, 16,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24665, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23821, 0, 0, 16, 32, 0, height, 16,
                        0, height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24687, 0, 0, 16, 32, 0, height, 16, 0,
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23785, 0, 0, 27, 32, 2, height, 2,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24651, 0, 0, 27, 32, 2, height, 2, 0, height);
                    wooden_a_supports_paint_setup(session, 1, 12, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23790, 0, 0, 27, 32, 2, height, 2,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24656, 0, 0, 27, 32, 2, height, 2, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23816, 0, 0, 27, 32, 0, height, 2,
                        0, height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24682, 0, 0, 27, 32, 0, height, 2, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 0, 9, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23795, 0, 0, 27, 32, 2, height, 2,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24661, 0, 0, 27, 32, 2, height, 2, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23818, 0, 0, 27, 32, 0, height, 2,
                        0, height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24684, 0, 0, 27, 32, 0, height, 2, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 1, 10, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23800, 0, 0, 27, 32, 2, height, 2,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24666, 0, 0, 27, 32, 2, height, 2, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23822, 0, 0, 27, 32, 0, height, 2,
                        0, height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24688, 0, 0, 27, 32, 0, height, 2, 0,
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

/** rct2: 0x008AC768 */
template<bool isClassic>
static void wooden_rc_track_right_quarter_turn_5_25_deg_up(
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23761, 0, 0, 32, 27, 2, height, 0,
                        2, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24627, 0, 0, 32, 27, 2, height, 0, 2, height);
                    wooden_a_supports_paint_setup(session, 0, 9, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23766, 0, 0, 32, 27, 2, height, 0,
                        2, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24632, 0, 0, 32, 27, 2, height, 0, 2, height);
                    wooden_a_supports_paint_setup(session, 1, 10, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23771, 0, 0, 32, 27, 2, height, 0,
                        2, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24637, 0, 0, 32, 27, 2, height, 0, 2, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23807, 0, 0, 32, 27, 0, height, 0,
                        2, height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24673, 0, 0, 32, 27, 0, height, 0, 2,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 0, 11, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23776, 0, 0, 32, 27, 2, height, 0,
                        2, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24642, 0, 0, 32, 27, 2, height, 0, 2, height);
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23762, 0, 0, 32, 16, 2, height, 0,
                        16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24628, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23801, 0, 0, 32, 16, 0, height, 0,
                        16, height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24667, 0, 0, 32, 16, 0, height, 0, 16,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23767, 0, 0, 32, 16, 2, height, 0,
                        16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24633, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23772, 0, 0, 32, 16, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24638, 0, 0, 32, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23808, 0, 0, 32, 16, 0, height, 0,
                        0, height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24674, 0, 0, 32, 16, 0, height, 0, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23777, 0, 0, 32, 16, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24643, 0, 0, 32, 16, 2, height, 0, 0, height);
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23763, 0, 0, 16, 16, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24629, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23802, 0, 0, 16, 16, 0, height, 0,
                        0, height + 59);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24668, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 59);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23768, 0, 0, 16, 16, 2, height, 16,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24634, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23773, 0, 0, 16, 16, 2, height, 16,
                        16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24639, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23809, 0, 0, 16, 16, 0, height, 16,
                        16, height + 59);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24675, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 59);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23778, 0, 0, 16, 16, 2, height, 0,
                        16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24644, 0, 0, 16, 16, 2, height, 0, 16,
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23764, 0, 0, 16, 32, 2, height, 16,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24630, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23803, 0, 0, 16, 32, 0, height, 16,
                        0, height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24669, 0, 0, 16, 32, 0, height, 16, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23769, 0, 0, 16, 32, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24635, 0, 0, 16, 32, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23805, 0, 0, 16, 32, 0, height, 0,
                        0, height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24671, 0, 0, 16, 32, 0, height, 0, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23774, 0, 0, 16, 32, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24640, 0, 0, 16, 32, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23810, 0, 0, 16, 32, 0, height, 0,
                        0, height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24676, 0, 0, 16, 32, 0, height, 0, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23779, 0, 0, 16, 32, 2, height, 16,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24645, 0, 0, 16, 32, 2, height, 16, 0,
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23765, 0, 0, 27, 32, 2, height, 2,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24631, 0, 0, 27, 32, 2, height, 2, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23804, 0, 0, 27, 32, 0, height, 2,
                        0, height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24670, 0, 0, 27, 32, 0, height, 2, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 1, 10, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23770, 0, 0, 27, 32, 2, height, 2,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24636, 0, 0, 27, 32, 2, height, 2, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23806, 0, 0, 27, 32, 0, height, 2,
                        0, height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24672, 0, 0, 27, 32, 0, height, 2, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 0, 11, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23775, 0, 0, 27, 32, 2, height, 2,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24641, 0, 0, 27, 32, 2, height, 2, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23811, 0, 0, 27, 32, 0, height, 2,
                        0, height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24677, 0, 0, 27, 32, 0, height, 2, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 1, 12, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23780, 0, 0, 27, 32, 2, height, 2,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24646, 0, 0, 27, 32, 2, height, 2, 0, height);
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

/** rct2: 0x008AC778 */
template<bool isClassic>
static void wooden_rc_track_left_quarter_turn_5_25_deg_down(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    trackSequence = mapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence];
    wooden_rc_track_right_quarter_turn_5_25_deg_up<isClassic>(
        session, rideIndex, trackSequence, (direction + 1) & 3, height, tileElement);
}

/** rct2: 0x008AC788 */
template<bool isClassic>
static void wooden_rc_track_right_quarter_turn_5_25_deg_down(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    trackSequence = mapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence];
    wooden_rc_track_left_quarter_turn_5_25_deg_up<isClassic>(
        session, rideIndex, trackSequence, (direction - 1) & 3, height, tileElement);
}

/** rct2: 0x008AC798 */
template<bool isClassic>
static void wooden_rc_track_s_bend_left(
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23725, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24591, 0, 0, 32, 25, 2, height, 0, 3, height);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23729, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24595, 0, 0, 32, 25, 2, height, 0, 3, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23741, 0, 0, 32, 25, 0, height, 0,
                        3, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24607, 0, 0, 32, 25, 0, height, 0, 3,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23728, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24594, 0, 0, 32, 25, 2, height, 0, 3, height);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23732, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24598, 0, 0, 32, 25, 2, height, 0, 3, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23744, 0, 0, 32, 27, 0, height, 0,
                        2, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24610, 0, 0, 32, 27, 0, height, 0, 2,
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23726, 0, 0, 32, 26, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24592, 0, 0, 32, 26, 2, height, 0, 0, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23730, 0, 0, 32, 26, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24596, 0, 0, 32, 26, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23742, 0, 0, 32, 26, 0, height, 0,
                        0, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24608, 0, 0, 32, 26, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23727, 0, 0, 32, 26, 2, height, 0,
                        6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24593, 0, 0, 32, 26, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23731, 0, 0, 32, 26, 2, height, 0,
                        6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24597, 0, 0, 32, 26, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23743, 0, 0, 32, 26, 0, height, 0,
                        6, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24609, 0, 0, 32, 26, 0, height, 0, 6,
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
        case 2:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23727, 0, 0, 32, 26, 2, height, 0,
                        6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24593, 0, 0, 32, 26, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23731, 0, 0, 32, 26, 2, height, 0,
                        6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24597, 0, 0, 32, 26, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23743, 0, 0, 32, 26, 0, height, 0,
                        6, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24609, 0, 0, 32, 26, 0, height, 0, 6,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23726, 0, 0, 32, 26, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24592, 0, 0, 32, 26, 2, height, 0, 0, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23730, 0, 0, 32, 26, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24596, 0, 0, 32, 26, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23742, 0, 0, 32, 26, 0, height, 0,
                        0, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24608, 0, 0, 32, 26, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23728, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24594, 0, 0, 32, 25, 2, height, 0, 3, height);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23732, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24598, 0, 0, 32, 25, 2, height, 0, 3, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23744, 0, 0, 32, 27, 0, height, 0,
                        2, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24610, 0, 0, 32, 27, 0, height, 0, 2,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23725, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24591, 0, 0, 32, 25, 2, height, 0, 3, height);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23729, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24595, 0, 0, 32, 25, 2, height, 0, 3, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23741, 0, 0, 32, 25, 0, height, 0,
                        3, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24607, 0, 0, 32, 25, 0, height, 0, 3,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            switch (direction)
            {
                case 1:
                    paint_util_push_tunnel_right(session, height, TUNNEL_SQUARE_FLAT);
                    break;
                case 2:
                    paint_util_push_tunnel_left(session, height, TUNNEL_SQUARE_FLAT);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
    }
}

/** rct2: 0x008AC7A8 */
template<bool isClassic>
static void wooden_rc_track_s_bend_right(
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23733, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24599, 0, 0, 32, 25, 2, height, 0, 3, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23745, 0, 0, 32, 25, 0, height, 0,
                        3, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24611, 0, 0, 32, 25, 0, height, 0, 3,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23737, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24603, 0, 0, 32, 25, 2, height, 0, 3, height);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23736, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24602, 0, 0, 32, 25, 2, height, 0, 3, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23748, 0, 0, 32, 25, 0, height, 0,
                        3, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24614, 0, 0, 32, 25, 0, height, 0, 3,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23740, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24606, 0, 0, 32, 25, 2, height, 0, 3, height);
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23734, 0, 0, 32, 26, 2, height, 0,
                        6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24600, 0, 0, 32, 26, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23746, 0, 0, 32, 26, 0, height, 0,
                        6, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24612, 0, 0, 32, 26, 0, height, 0, 6,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23738, 0, 0, 32, 26, 2, height, 0,
                        6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24604, 0, 0, 32, 26, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23735, 0, 0, 32, 26, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24601, 0, 0, 32, 26, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23747, 0, 0, 32, 26, 0, height, 0,
                        0, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24613, 0, 0, 32, 26, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23739, 0, 0, 32, 26, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24605, 0, 0, 32, 26, 2, height, 0, 0, height);
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
        case 2:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23735, 0, 0, 32, 26, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24601, 0, 0, 32, 26, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23747, 0, 0, 32, 26, 0, height, 0,
                        0, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24613, 0, 0, 32, 26, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23739, 0, 0, 32, 26, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24605, 0, 0, 32, 26, 2, height, 0, 0, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23734, 0, 0, 32, 26, 2, height, 0,
                        6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24600, 0, 0, 32, 26, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23746, 0, 0, 32, 26, 0, height, 0,
                        6, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24612, 0, 0, 32, 26, 0, height, 0, 6,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23738, 0, 0, 32, 26, 2, height, 0,
                        6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24604, 0, 0, 32, 26, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23736, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24602, 0, 0, 32, 25, 2, height, 0, 3, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23748, 0, 0, 32, 25, 0, height, 0,
                        3, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24614, 0, 0, 32, 25, 0, height, 0, 3,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23740, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24606, 0, 0, 32, 25, 2, height, 0, 3, height);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23733, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24599, 0, 0, 32, 25, 2, height, 0, 3, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23745, 0, 0, 32, 25, 0, height, 0,
                        3, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24611, 0, 0, 32, 25, 0, height, 0, 3,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23737, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24603, 0, 0, 32, 25, 2, height, 0, 3, height);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            switch (direction)
            {
                case 1:
                    paint_util_push_tunnel_right(session, height, TUNNEL_SQUARE_FLAT);
                    break;
                case 2:
                    paint_util_push_tunnel_left(session, height, TUNNEL_SQUARE_FLAT);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
    }
}

/** rct2: 0x008ACE18 */
template<bool isClassic>
static void wooden_rc_track_left_vertical_loop(
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
                        session, direction, wooden_rc_get_rails_colour(session) | 23453, 0, 6, 32, 20, 3, height);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23461, 0, 6, 32, 20, 3, height);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23460, 0, 6, 32, 20, 3, height);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23468, 0, 6, 32, 20, 7, height);
                    break;
            }
            metal_a_supports_paint_setup(session, METAL_SUPPORTS_BOXED, 4, 8, height, session->TrackColours[SCHEME_SUPPORTS]);
            if (direction == 0 || direction == 3)
            {
                paint_util_push_tunnel_rotated(session, direction, height - 8, TUNNEL_SQUARE_7);
            }
            paint_util_set_segment_support_height(
                session,
                paint_util_rotate_segments(
                    SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 56, 0x20);
            break;
        case 1:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23454, 0, 0, 32, 26, 3, height);
                    metal_a_supports_paint_setup(
                        session, METAL_SUPPORTS_BOXED, 4, 20, height, session->TrackColours[SCHEME_SUPPORTS]);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23462, 0, 14, 32, 2, 63, height);
                    metal_a_supports_paint_setup(
                        session, METAL_SUPPORTS_BOXED, 4, 9, height, session->TrackColours[SCHEME_SUPPORTS]);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23459, 0, 6, 32, 26, 3, height);
                    metal_a_supports_paint_setup(
                        session, METAL_SUPPORTS_BOXED, 4, 16, height, session->TrackColours[SCHEME_SUPPORTS]);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23467, 0, 6, 32, 26, 3, height);
                    metal_a_supports_paint_setup(
                        session, METAL_SUPPORTS_BOXED, 4, 16, height, session->TrackColours[SCHEME_SUPPORTS]);
                    break;
            }
            paint_util_set_segment_support_height(
                session,
                paint_util_rotate_segments(
                    SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 72, 0x20);
            break;
        case 2:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23455, 16, 0, 5, 16, 119, height);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23463, 12, 0, 3, 16, 119, height);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23458, 10, 16, 4, 16, 119, height);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23466, 16, 16, 4, 16, 119, height);
                    break;
            }
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_D0, direction), 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 168, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23456, 0, 0, 32, 16, 3, height + 32);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23464, 0, 0, 32, 16, 3, height + 32);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23457, 0, 16, 32, 16, 3, height + 32);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23465, 0, 16, 32, 16, 3, height + 32);
                    break;
            }
            paint_util_set_segment_support_height(
                session,
                paint_util_rotate_segments(
                    SEGMENT_B4 | SEGMENT_B8 | SEGMENT_C4 | SEGMENT_C8 | SEGMENT_CC | SEGMENT_D0, direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 4:
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 5:
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 6:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23457, 0, 16, 32, 16, 3, height + 32);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23465, 0, 16, 32, 16, 3, height + 32);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23456, 0, 0, 32, 16, 3, height + 32);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23464, 0, 0, 32, 16, 3, height + 32);
                    break;
            }
            paint_util_set_segment_support_height(
                session,
                paint_util_rotate_segments(
                    SEGMENT_BC | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 7:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23458, 10, 16, 4, 16, 119, height);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23466, 16, 16, 4, 16, 119, height);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23455, 16, 0, 5, 16, 119, height);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23463, 12, 0, 3, 16, 119, height);
                    break;
            }
            paint_util_set_segment_support_height(
                session, paint_util_rotate_segments(SEGMENT_BC | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D4, direction), 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 168, 0x20);
            break;
        case 8:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23459, 0, 6, 32, 26, 3, height);
                    metal_a_supports_paint_setup(
                        session, METAL_SUPPORTS_BOXED, 4, 16, height, session->TrackColours[SCHEME_SUPPORTS]);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23467, 0, 6, 32, 26, 3, height);
                    metal_a_supports_paint_setup(
                        session, METAL_SUPPORTS_BOXED, 4, 16, height, session->TrackColours[SCHEME_SUPPORTS]);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23454, 0, 0, 32, 26, 3, height);
                    metal_a_supports_paint_setup(
                        session, METAL_SUPPORTS_BOXED, 4, 20, height, session->TrackColours[SCHEME_SUPPORTS]);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23462, 0, 14, 32, 2, 63, height);
                    metal_a_supports_paint_setup(
                        session, METAL_SUPPORTS_BOXED, 4, 9, height, session->TrackColours[SCHEME_SUPPORTS]);
                    break;
            }
            paint_util_set_segment_support_height(
                session,
                paint_util_rotate_segments(
                    SEGMENT_BC | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 72, 0x20);
            break;
        case 9:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23460, 0, 6, 32, 20, 3, height);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23468, 0, 6, 32, 20, 7, height);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23453, 0, 6, 32, 20, 3, height);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23461, 0, 6, 32, 20, 3, height);
                    break;
            }
            metal_a_supports_paint_setup(session, METAL_SUPPORTS_BOXED, 4, 8, height, session->TrackColours[SCHEME_SUPPORTS]);
            switch (direction)
            {
                case 1:
                    paint_util_push_tunnel_right(session, height - 8, TUNNEL_SQUARE_7);
                    break;
                case 2:
                    paint_util_push_tunnel_left(session, height - 8, TUNNEL_SQUARE_7);
                    break;
            }
            paint_util_set_segment_support_height(
                session,
                paint_util_rotate_segments(
                    SEGMENT_BC | SEGMENT_C0 | SEGMENT_C4 | SEGMENT_CC | SEGMENT_D0 | SEGMENT_D4, direction),
                0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 56, 0x20);
            break;
    }
}

/** rct2: 0x008ACE28 */
template<bool isClassic>
static void wooden_rc_track_right_vertical_loop(
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
                        session, direction, wooden_rc_get_rails_colour(session) | 23484, 0, 6, 32, 20, 7, height);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23476, 0, 6, 32, 20, 3, height);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23477, 0, 6, 32, 20, 3, height);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23469, 0, 6, 32, 20, 3, height);
                    break;
            }
            metal_a_supports_paint_setup(session, METAL_SUPPORTS_BOXED, 4, 8, height, session->TrackColours[SCHEME_SUPPORTS]);
            if (direction == 0 || direction == 3)
            {
                paint_util_push_tunnel_rotated(session, direction, height - 8, TUNNEL_SQUARE_7);
            }
            paint_util_set_general_support_height(session, height + 56, 0x20);
            break;
        case 1:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23483, 0, 6, 32, 26, 3, height);
                    metal_a_supports_paint_setup(
                        session, METAL_SUPPORTS_BOXED, 4, 16, height, session->TrackColours[SCHEME_SUPPORTS]);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23475, 0, 6, 32, 26, 3, height);
                    metal_a_supports_paint_setup(
                        session, METAL_SUPPORTS_BOXED, 4, 16, height, session->TrackColours[SCHEME_SUPPORTS]);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23478, 0, 14, 32, 2, 63, height);
                    metal_a_supports_paint_setup(
                        session, METAL_SUPPORTS_BOXED, 4, 9, height, session->TrackColours[SCHEME_SUPPORTS]);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23470, 0, 0, 32, 26, 3, height);
                    metal_a_supports_paint_setup(
                        session, METAL_SUPPORTS_BOXED, 4, 20, height, session->TrackColours[SCHEME_SUPPORTS]);
                    break;
            }
            paint_util_set_general_support_height(session, height + 72, 0x20);
            break;
        case 2:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23482, 16, 16, 4, 16, 119, height);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23474, 10, 16, 4, 16, 119, height);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23479, 12, 0, 3, 16, 119, height);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23471, 16, 0, 5, 16, 119, height);
                    break;
            }
            paint_util_set_general_support_height(session, height + 168, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23481, 0, 16, 32, 16, 3, height + 32);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23473, 0, 16, 32, 16, 3, height + 32);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23480, 0, 0, 32, 16, 3, height + 32);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23472, 0, 0, 32, 16, 3, height + 32);
                    break;
            }
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 4:
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 5:
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 6:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23480, 0, 0, 32, 16, 3, height + 32);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23472, 0, 0, 32, 16, 3, height + 32);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23481, 0, 16, 32, 16, 3, height + 32);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23473, 0, 16, 32, 16, 3, height + 32);
                    break;
            }
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 7:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23479, 12, 0, 3, 16, 119, height);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23471, 16, 0, 5, 16, 119, height);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23482, 16, 16, 4, 16, 119, height);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23474, 10, 16, 4, 16, 119, height);
                    break;
            }
            paint_util_set_general_support_height(session, height + 168, 0x20);
            break;
        case 8:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23478, 0, 14, 32, 2, 63, height);
                    metal_a_supports_paint_setup(
                        session, METAL_SUPPORTS_BOXED, 4, 9, height, session->TrackColours[SCHEME_SUPPORTS]);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23470, 0, 0, 32, 26, 3, height);
                    metal_a_supports_paint_setup(
                        session, METAL_SUPPORTS_BOXED, 4, 20, height, session->TrackColours[SCHEME_SUPPORTS]);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23483, 0, 6, 32, 26, 3, height);
                    metal_a_supports_paint_setup(
                        session, METAL_SUPPORTS_BOXED, 4, 16, height, session->TrackColours[SCHEME_SUPPORTS]);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23475, 0, 6, 32, 26, 3, height);
                    metal_a_supports_paint_setup(
                        session, METAL_SUPPORTS_BOXED, 4, 16, height, session->TrackColours[SCHEME_SUPPORTS]);
                    break;
            }
            paint_util_set_general_support_height(session, height + 72, 0x20);
            break;
        case 9:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23477, 0, 6, 32, 20, 3, height);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23469, 0, 6, 32, 20, 3, height);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23484, 0, 6, 32, 20, 7, height);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 23476, 0, 6, 32, 20, 3, height);
                    break;
            }
            metal_a_supports_paint_setup(session, METAL_SUPPORTS_BOXED, 4, 8, height, session->TrackColours[SCHEME_SUPPORTS]);
            switch (direction)
            {
                case 1:
                    paint_util_push_tunnel_right(session, height - 8, TUNNEL_SQUARE_7);
                    break;
                case 2:
                    paint_util_push_tunnel_left(session, height - 8, TUNNEL_SQUARE_7);
                    break;
            }
            paint_util_set_general_support_height(session, height + 56, 0x20);
            break;
    }

    track_paint_util_right_vertical_loop_segments(session, direction, trackSequence);
}

/** rct2: 0x008AC7E8 */
template<bool isClassic>
static void wooden_rc_track_left_quarter_turn_3(
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23828, 0, 6, 32, 20, 2, height, 0,
                        6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24694, 0, 6, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23831, 0, 6, 32, 20, 2, height, 0,
                        6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24697, 0, 6, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23840, 0, 6, 32, 20, 0, height, 0,
                        6, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24706, 0, 6, 32, 20, 0, height, 0, 6,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23834, 0, 6, 32, 20, 2, height, 0,
                        6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24700, 0, 6, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23825, 0, 6, 32, 20, 2, height, 0,
                        6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24691, 0, 6, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23837, 0, 6, 32, 20, 0, height, 0,
                        6, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24703, 0, 6, 32, 20, 0, height, 0, 6,
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23827, 16, 0, 16, 16, 2, height,
                        16, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24693, 16, 0, 16, 16, 2, height, 16, 0,
                        height);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23830, 0, 0, 16, 16, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24696, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23839, 0, 0, 16, 16, 0, height, 0,
                        0, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24705, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23833, 0, 16, 16, 16, 2, height, 0,
                        16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24699, 0, 16, 16, 16, 2, height, 0, 16,
                        height);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23824, 16, 16, 16, 16, 2, height,
                        16, 16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24690, 16, 16, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23836, 16, 16, 16, 16, 0, height,
                        16, 16, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24702, 16, 16, 16, 16, 0, height, 16, 16,
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23826, 6, 0, 20, 32, 2, height, 6,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24692, 6, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23829, 6, 0, 20, 32, 2, height, 6,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24695, 6, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23838, 6, 0, 20, 32, 0, height, 6,
                        0, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24704, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23832, 6, 0, 20, 32, 2, height, 6,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24698, 6, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23823, 6, 0, 20, 32, 2, height, 6,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24689, 6, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23835, 6, 0, 20, 32, 0, height, 6,
                        0, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24701, 6, 0, 20, 32, 0, height, 6, 0,
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

/** rct2: 0x008AC7F8 */
template<bool isClassic>
static void wooden_rc_track_right_quarter_turn_3(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    trackSequence = mapLeftQuarterTurn3TilesToRightQuarterTurn3Tiles[trackSequence];
    wooden_rc_track_left_quarter_turn_3<isClassic>(session, rideIndex, trackSequence, (direction - 1) & 3, height, tileElement);
}

/** rct2: 0x008AC828 */
template<bool isClassic>
static void wooden_rc_track_left_quarter_turn_3_25_deg_up(
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23906, 0, 6, 32, 20, 2, height, 0,
                        6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24772, 0, 6, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23908, 0, 6, 32, 20, 2, height, 0,
                        6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24774, 0, 6, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23919, 0, 6, 32, 20, 0, height, 0,
                        6, height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24785, 0, 6, 32, 20, 0, height, 0, 6,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23910, 0, 6, 32, 20, 2, height, 0,
                        6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24776, 0, 6, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23904, 0, 6, 32, 20, 2, height, 0,
                        6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24770, 0, 6, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23917, 0, 6, 32, 20, 0, height, 0,
                        6, height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24783, 0, 6, 32, 20, 0, height, 0, 6,
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23905, 6, 0, 20, 32, 2, height, 6,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24771, 6, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23907, 6, 0, 20, 32, 2, height, 6,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24773, 6, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23918, 6, 0, 20, 32, 0, height, 6,
                        0, height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24784, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23909, 6, 0, 20, 32, 2, height, 6,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24775, 6, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23920, 6, 0, 20, 32, 0, height, 6,
                        0, height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24786, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23903, 6, 0, 20, 32, 2, height, 6,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24769, 6, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23916, 6, 0, 20, 32, 0, height, 6,
                        0, height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24782, 6, 0, 20, 32, 0, height, 6, 0,
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

/** rct2: 0x008AC838 */
template<bool isClassic>
static void wooden_rc_track_right_quarter_turn_3_25_deg_up(
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23895, 0, 6, 32, 20, 2, height, 0,
                        6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24761, 0, 6, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23911, 0, 6, 32, 20, 0, height, 0,
                        6, height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24777, 0, 6, 32, 20, 0, height, 0, 6,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23897, 0, 6, 32, 20, 2, height, 0,
                        6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24763, 0, 6, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23899, 0, 6, 32, 20, 2, height, 0,
                        6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24765, 0, 6, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23914, 0, 6, 32, 20, 0, height, 0,
                        6, height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24780, 0, 6, 32, 20, 0, height, 0, 6,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23901, 0, 6, 32, 20, 2, height, 0,
                        6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24767, 0, 6, 32, 20, 2, height, 0, 6, height);
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23896, 6, 0, 20, 32, 2, height, 6,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24762, 6, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23912, 6, 0, 20, 32, 0, height, 6,
                        0, height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24778, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23898, 6, 0, 20, 32, 2, height, 6,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24764, 6, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23913, 6, 0, 20, 32, 0, height, 6,
                        0, height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24779, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23900, 6, 0, 20, 32, 2, height, 6,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24766, 6, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23915, 6, 0, 20, 32, 0, height, 6,
                        0, height + 67);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24781, 6, 0, 20, 32, 0, height, 6, 0,
                        height + 67);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23902, 6, 0, 20, 32, 2, height, 6,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24768, 6, 0, 20, 32, 2, height, 6, 0, height);
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

/** rct2: 0x008AC848 */
template<bool isClassic>
static void wooden_rc_track_left_quarter_turn_3_25_deg_down(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    trackSequence = mapLeftQuarterTurn3TilesToRightQuarterTurn3Tiles[trackSequence];
    wooden_rc_track_right_quarter_turn_3_25_deg_up<isClassic>(
        session, rideIndex, trackSequence, (direction + 1) & 3, height, tileElement);
}

/** rct2: 0x008AC858 */
template<bool isClassic>
static void wooden_rc_track_right_quarter_turn_3_25_deg_down(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    trackSequence = mapLeftQuarterTurn3TilesToRightQuarterTurn3Tiles[trackSequence];
    wooden_rc_track_left_quarter_turn_3_25_deg_up<isClassic>(
        session, rideIndex, trackSequence, (direction - 1) & 3, height, tileElement);
}

/** rct2: 0x008ACB98 */
template<bool isClassic>
static void wooden_rc_track_left_quarter_turn_1_60_deg_up(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (direction)
    {
        case 0:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24209, 0, 0, 28, 28, 3, height, 2, 2,
                height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25075, 0, 0, 28, 28, 3, height, 2, 2, height);
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24217, 0, 0, 28, 28, 1, height, 2, 2,
                height + 99);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25083, 0, 0, 28, 28, 1, height, 2, 2, height + 99);
            break;
        case 1:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24210, 0, 0, 28, 28, 3, height, 2, 2,
                height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25076, 0, 0, 28, 28, 3, height, 2, 2, height);
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24218, 0, 0, 28, 28, 1, height, 2, 2,
                height + 99);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25084, 0, 0, 28, 28, 1, height, 2, 2, height + 99);
            break;
        case 2:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24211, 0, 0, 28, 28, 3, height, 2, 2,
                height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25077, 0, 0, 28, 28, 3, height, 2, 2, height);
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24219, 0, 0, 28, 28, 1, height, 2, 2,
                height + 99);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25085, 0, 0, 28, 28, 1, height, 2, 2, height + 99);
            break;
        case 3:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24212, 0, 0, 28, 28, 3, height, 2, 2,
                height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25078, 0, 0, 28, 28, 3, height, 2, 2, height);
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24220, 0, 0, 28, 28, 1, height, 2, 2,
                height + 99);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25086, 0, 0, 28, 28, 1, height, 2, 2, height + 99);
            break;
    }
    track_paint_util_left_quarter_turn_1_tile_tunnel(session, direction, height, -8, TUNNEL_SQUARE_7, +56, TUNNEL_SQUARE_8);
    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 104, 0x20);
}

/** rct2: 0x008ACB78 */
template<bool isClassic>
static void wooden_rc_track_right_quarter_turn_1_60_deg_up(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (direction)
    {
        case 0:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24213, 0, 0, 28, 28, 3, height, 2, 2,
                height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25079, 0, 0, 28, 28, 3, height, 2, 2, height);
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24221, 0, 0, 28, 28, 1, height, 2, 2,
                height + 99);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25087, 0, 0, 28, 28, 1, height, 2, 2, height + 99);
            break;
        case 1:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24214, 0, 0, 28, 28, 3, height, 2, 2,
                height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25080, 0, 0, 28, 28, 3, height, 2, 2, height);
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24222, 0, 0, 28, 28, 1, height, 2, 2,
                height + 99);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25088, 0, 0, 28, 28, 1, height, 2, 2, height + 99);
            break;
        case 2:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24215, 0, 0, 28, 28, 3, height, 2, 2,
                height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25081, 0, 0, 28, 28, 3, height, 2, 2, height);
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24223, 0, 0, 28, 28, 1, height, 2, 2,
                height + 99);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25089, 0, 0, 28, 28, 1, height, 2, 2, height + 99);
            break;
        case 3:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24216, 0, 0, 28, 28, 3, height, 2, 2,
                height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25082, 0, 0, 28, 28, 3, height, 2, 2, height);
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24224, 0, 0, 28, 28, 1, height, 2, 2,
                height + 99);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 25090, 0, 0, 28, 28, 1, height, 2, 2, height + 99);
            break;
    }
    track_paint_util_right_quarter_turn_1_tile_tunnel(session, direction, height, -8, TUNNEL_SQUARE_7, +56, TUNNEL_SQUARE_8);
    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 104, 0x20);
}

/** rct2: 0x008ACB88 */
template<bool isClassic>
static void wooden_rc_track_left_quarter_turn_1_60_deg_down(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    wooden_rc_track_right_quarter_turn_1_60_deg_up<isClassic>(
        session, rideIndex, trackSequence, (direction + 1) & 3, height, tileElement);
}

/** rct2: 0x008ACBA8 */
template<bool isClassic>
static void wooden_rc_track_right_quarter_turn_1_60_deg_down(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    wooden_rc_track_left_quarter_turn_1_60_deg_up<isClassic>(
        session, rideIndex, trackSequence, (direction - 1) & 3, height, tileElement);
}

/** rct2: 0x008AC868 */
template<bool isClassic>
static void wooden_rc_track_brakes(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    static constexpr const uint32_t imageIds[4][2] = {
        { SPR_WOODEN_RC_BRAKES_SW_NE, SPR_WOODEN_RC_BRAKES_RAILS_SW_NE },
        { SPR_WOODEN_RC_BRAKES_NW_SE, SPR_WOODEN_RC_BRAKES_RAILS_NW_SE },
        { SPR_WOODEN_RC_BRAKES_SW_NE, SPR_WOODEN_RC_BRAKES_RAILS_SW_NE },
        { SPR_WOODEN_RC_BRAKES_NW_SE, SPR_WOODEN_RC_BRAKES_RAILS_NW_SE },
    };

    wooden_rc_track_paint<isClassic>(
        session, imageIds[direction][0], imageIds[direction][1], direction, 0, 2, 32, 25, 2, height, 0, 3, height);
    wooden_a_supports_paint_setup(session, direction & 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
    paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_FLAT);
    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 32, 0x20);
}

/** rct2: 0x008AC878 */
template<bool isClassic>
static void wooden_rc_track_on_ride_photo(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (direction)
    {
        case 0:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23753, 0, 2, 32, 25, 2, height, 0, 3,
                height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 24619, 0, 2, 32, 25, 2, height, 0, 3, height);
            break;
        case 1:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23754, 0, 2, 32, 25, 2, height, 0, 3,
                height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 24620, 0, 2, 32, 25, 2, height, 0, 3, height);
            break;
        case 2:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23753, 0, 2, 32, 25, 2, height, 0, 3,
                height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 24619, 0, 2, 32, 25, 2, height, 0, 3, height);
            break;
        case 3:
            PaintAddImageAsParentRotated(
                session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23754, 0, 2, 32, 25, 2, height, 0, 3,
                height);
            PaintAddImageAsChildRotated(
                session, direction, wooden_rc_get_rails_colour(session) | 24620, 0, 2, 32, 25, 2, height, 0, 3, height);
            break;
    }
    wooden_a_supports_paint_setup(session, direction & 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
    track_paint_util_onride_photo_small_paint(session, direction, height + 16, tileElement);
    paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_INVERTED_9);
    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 48, 0x20);
}

/** rct2: 0x008ACE08 */
template<bool isClassic>
static void wooden_rc_track_water_splash(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    const bool transparent = gConfigGeneral.transparent_water || (session->ViewFlags & VIEWPORT_FLAG_UNDERGROUND_INSIDE);
    const uint32_t waterOverlay = transparent ? SPR_WATER_OVERLAY : SPR_RCT1_WATER_OVERLAY;

    switch (trackSequence)
    {
        case 0:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23989, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24855, 0, 0, 32, 25, 2, height, 0, 3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x61000000 | SPR_WATER_MASK, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x00000000 | waterOverlay, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 23997, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 24863, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23993, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24859, 0, 0, 32, 25, 2, height, 0, 3, height);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23990, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24856, 0, 0, 32, 25, 2, height, 0, 3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x61000000 | SPR_WATER_MASK, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x00000000 | waterOverlay, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 23998, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 24864, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23994, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24860, 0, 0, 32, 25, 2, height, 0, 3, height);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23987, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24853, 0, 0, 32, 25, 2, height, 0, 3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x61000000 | SPR_WATER_MASK, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x00000000 | waterOverlay, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 23995, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 24861, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23991, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24857, 0, 0, 32, 25, 2, height, 0, 3, height);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23988, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24854, 0, 0, 32, 25, 2, height, 0, 3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x61000000 | SPR_WATER_MASK, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x00000000 | waterOverlay, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 23996, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 24862, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23992, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24858, 0, 0, 32, 25, 2, height, 0, 3, height);
                    break;
            }
            wooden_a_supports_paint_setup(session, direction & 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            paint_util_push_tunnel_rotated(session, direction, height + 16, TUNNEL_SQUARE_FLAT);
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 1:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23977, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24843, 0, 0, 32, 25, 2, height, 0, 3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x61000000 | SPR_WATER_MASK, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x00000000 | waterOverlay, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 23985, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 24851, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23981, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24847, 0, 0, 32, 25, 2, height, 0, 3, height);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23978, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24844, 0, 0, 32, 25, 2, height, 0, 3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x61000000 | SPR_WATER_MASK, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x00000000 | waterOverlay, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 23986, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 24852, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23982, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24848, 0, 0, 32, 25, 2, height, 0, 3, height);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23975, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24841, 0, 0, 32, 25, 2, height, 0, 3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x61000000 | SPR_WATER_MASK, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x00000000 | waterOverlay, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 23983, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 24849, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23979, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24845, 0, 0, 32, 25, 2, height, 0, 3, height);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23976, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24842, 0, 0, 32, 25, 2, height, 0, 3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x61000000 | SPR_WATER_MASK, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x00000000 | waterOverlay, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 23984, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 24850, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23980, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24846, 0, 0, 32, 25, 2, height, 0, 3, height);
                    break;
            }
            wooden_a_supports_paint_setup(session, direction & 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 2:
            switch (direction)
            {
                case 0:
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23999, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24865, 0, 0, 32, 25, 2, height, 0, 3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x61000000 | SPR_WATER_MASK, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x00000000 | waterOverlay, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 24003, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 24869, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24001, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24867, 0, 0, 32, 25, 2, height, 0, 3, height);
                    break;
                case 1:
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24000, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24866, 0, 0, 32, 25, 2, height, 0, 3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x61000000 | SPR_WATER_MASK, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x00000000 | waterOverlay, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 24004, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 24870, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24002, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24868, 0, 0, 32, 25, 2, height, 0, 3, height);
                    break;
            }
            wooden_a_supports_paint_setup(session, direction & 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23975, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24841, 0, 0, 32, 25, 2, height, 0, 3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x61000000 | SPR_WATER_MASK, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x00000000 | waterOverlay, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 23983, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 24849, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23979, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24845, 0, 0, 32, 25, 2, height, 0, 3, height);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23976, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24842, 0, 0, 32, 25, 2, height, 0, 3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x61000000 | SPR_WATER_MASK, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x00000000 | waterOverlay, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 23984, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 24850, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23980, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24846, 0, 0, 32, 25, 2, height, 0, 3, height);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23977, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24843, 0, 0, 32, 25, 2, height, 0, 3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x61000000 | SPR_WATER_MASK, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x00000000 | waterOverlay, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 23985, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 24851, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23981, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24847, 0, 0, 32, 25, 2, height, 0, 3, height);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23978, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24844, 0, 0, 32, 25, 2, height, 0, 3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x61000000 | SPR_WATER_MASK, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x00000000 | waterOverlay, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 23986, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 24852, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23982, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24848, 0, 0, 32, 25, 2, height, 0, 3, height);
                    break;
            }
            wooden_a_supports_paint_setup(session, direction & 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 4:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23987, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24853, 0, 0, 32, 25, 2, height, 0, 3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x61000000 | SPR_WATER_MASK, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x00000000 | waterOverlay, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 23995, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 24861, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23991, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24857, 0, 0, 32, 25, 2, height, 0, 3, height);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23988, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24854, 0, 0, 32, 25, 2, height, 0, 3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x61000000 | SPR_WATER_MASK, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x00000000 | waterOverlay, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 23996, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 24862, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23992, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24858, 0, 0, 32, 25, 2, height, 0, 3, height);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23989, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24855, 0, 0, 32, 25, 2, height, 0, 3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x61000000 | SPR_WATER_MASK, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x00000000 | waterOverlay, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 23997, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 24863, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23993, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24859, 0, 0, 32, 25, 2, height, 0, 3, height);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23990, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24856, 0, 0, 32, 25, 2, height, 0, 3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x61000000 | SPR_WATER_MASK, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, 0x00000000 | waterOverlay, 0, 0, 32, 25, 2, height + 16, 0, 3, height + 16);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 23998, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_SUPPORTS] | 24864, 0, 0, 32, 25, 2, height, 0, 3,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 23994, 0, 0, 32, 25, 2, height, 0,
                        3, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24860, 0, 0, 32, 25, 2, height, 0, 3, height);
                    break;
            }
            wooden_a_supports_paint_setup(session, direction & 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
            paint_util_push_tunnel_rotated(session, direction, height + 16, TUNNEL_SQUARE_FLAT);
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
    }
}

/** rct2: 0x008AC958 */
template<bool isClassic>
static void wooden_rc_track_left_eighth_to_diag(
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24137, 0, 0, 32, 32, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25003, 0, 0, 32, 32, 2, height, 0, 0, height);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24141, 0, 0, 32, 32, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25007, 0, 0, 32, 32, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24153, 0, 0, 32, 32, 0, height, 0,
                        0, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25019, 0, 0, 32, 32, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24145, 0, 0, 32, 32, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25011, 0, 0, 32, 32, 2, height, 0, 0, height);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24149, 0, 0, 32, 32, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25015, 0, 0, 32, 32, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24157, 0, 0, 32, 32, 0, height, 0,
                        0, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25023, 0, 0, 32, 32, 0, height, 0, 0,
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24138, 0, 0, 32, 16, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25004, 0, 0, 32, 16, 2, height, 0, 0, height);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24142, 0, 0, 34, 16, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25008, 0, 0, 34, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24154, 0, 0, 32, 16, 0, height, 0,
                        0, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25020, 0, 0, 32, 16, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24146, 0, 0, 32, 16, 2, height, 0,
                        16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25012, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24150, 0, 0, 32, 16, 2, height, 0,
                        16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25016, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24158, 0, 0, 32, 16, 0, height, 0,
                        16, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25024, 0, 0, 32, 16, 0, height, 0, 16,
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24139, 0, 0, 16, 16, 2, height, 0,
                        16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25005, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24143, 0, 0, 16, 16, 2, height, 16,
                        16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25009, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24155, 0, 0, 16, 16, 0, height, 16,
                        16, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25021, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24147, 0, 0, 16, 16, 2, height, 16,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25013, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24151, 0, 0, 16, 16, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25017, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24159, 0, 0, 16, 16, 0, height, 0,
                        0, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25025, 0, 0, 16, 16, 0, height, 0, 0,
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24140, 0, 0, 16, 16, 2, height, 16,
                        16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25006, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24144, 0, 0, 16, 18, 2, height, 0,
                        16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25010, 0, 0, 16, 18, 2, height, 0, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24156, 0, 0, 16, 16, 0, height, 0,
                        16, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25022, 0, 0, 16, 16, 0, height, 0, 16,
                        height + 27);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24148, 0, 0, 16, 16, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25014, 0, 0, 16, 16, 2, height, 0, 0, height);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24152, 0, 0, 16, 16, 2, height, 16,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25018, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24160, 0, 0, 16, 16, 0, height, 16,
                        0, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25026, 0, 0, 16, 16, 0, height, 16, 0,
                        height + 27);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
    }
}

/** rct2: 0x008AC968 */
template<bool isClassic>
static void wooden_rc_track_right_eighth_to_diag(
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24113, 0, 0, 32, 32, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24979, 0, 0, 32, 32, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24129, 0, 0, 32, 32, 0, height, 0,
                        0, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24995, 0, 0, 32, 32, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24117, 0, 0, 32, 32, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24983, 0, 0, 32, 32, 2, height, 0, 0, height);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24121, 0, 0, 32, 32, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24987, 0, 0, 32, 32, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24133, 0, 0, 32, 32, 0, height, 0,
                        0, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24999, 0, 0, 32, 32, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24125, 0, 0, 32, 32, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24991, 0, 0, 32, 32, 2, height, 0, 0, height);
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24114, 0, 0, 32, 16, 2, height, 0,
                        16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24980, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24130, 0, 0, 32, 16, 0, height, 0,
                        16, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24996, 0, 0, 32, 16, 0, height, 0, 16,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24118, 0, 0, 32, 16, 2, height, 0,
                        16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24984, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24122, 0, 0, 34, 16, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24988, 0, 0, 34, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24134, 0, 0, 32, 16, 0, height, 0,
                        0, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25000, 0, 0, 32, 16, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24126, 0, 0, 32, 16, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24992, 0, 0, 32, 16, 2, height, 0, 0, height);
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24115, 0, 0, 16, 16, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24981, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24131, 0, 0, 16, 16, 0, height, 0,
                        0, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24997, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24119, 0, 0, 16, 16, 2, height, 16,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24985, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24123, 0, 0, 28, 28, 2, height, 4,
                        4, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24989, 0, 0, 28, 28, 2, height, 4, 4, height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24135, 0, 0, 28, 28, 0, height, 4,
                        4, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25001, 0, 0, 28, 28, 0, height, 4, 4,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24127, 0, 0, 16, 16, 2, height, 0,
                        16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24993, 0, 0, 16, 16, 2, height, 0, 16,
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24116, 0, 0, 16, 16, 2, height, 16,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24982, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24132, 0, 0, 16, 16, 0, height, 16,
                        0, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24998, 0, 0, 16, 16, 0, height, 16, 0,
                        height + 27);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24120, 0, 0, 16, 16, 2, height, 0,
                        0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24986, 0, 0, 16, 16, 2, height, 0, 0, height);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24124, 0, 0, 16, 18, 2, height, 0,
                        16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24990, 0, 0, 16, 18, 2, height, 0, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24136, 0, 0, 16, 16, 0, height, 0,
                        16, height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 25002, 0, 0, 16, 16, 0, height, 0, 16,
                        height + 27);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24128, 0, 0, 16, 16, 2, height, 16,
                        16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24994, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
    }
}

/** rct2: 0x008AC978 */
template<bool isClassic>
static void wooden_rc_track_left_eighth_to_orthogonal(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    trackSequence = mapLeftEighthTurnToOrthogonal[trackSequence];
    wooden_rc_track_right_eighth_to_diag<isClassic>(
        session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

/** rct2: 0x008AC988 */
template<bool isClassic>
static void wooden_rc_track_right_eighth_to_orthogonal(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    trackSequence = mapLeftEighthTurnToOrthogonal[trackSequence];
    wooden_rc_track_left_eighth_to_diag<isClassic>(session, rideIndex, trackSequence, (direction + 3) & 3, height, tileElement);
}

/** rct2: 0x008AC888 */
template<bool isClassic>
static void wooden_rc_track_diag_flat(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            if (tileElement->AsTrack()->HasChain())
            {
                switch (direction)
                {
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24050, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24916, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        break;
                }
            }
            else
            {
                switch (direction)
                {
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24008, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24874, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        break;
                }
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 1:
            if (tileElement->AsTrack()->HasChain())
            {
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24047, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24913, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24051, -16, -16, 32, 32, 0,
                            height, -16, -16, height + 27);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24917, -16, -16, 32, 32, 0, height, -16,
                            -16, height + 27);
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
            }
            else
            {
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24005, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24871, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24009, -16, -16, 32, 32, 0,
                            height, -16, -16, height + 27);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24875, -16, -16, 32, 32, 0, height, -16,
                            -16, height + 27);
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
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 2:
            if (tileElement->AsTrack()->HasChain())
            {
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
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24049, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24915, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24052, -16, -16, 32, 32, 0,
                            height, -16, -16, height + 27);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24918, -16, -16, 32, 32, 0, height, -16,
                            -16, height + 27);
                        wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 3:
                        wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                }
            }
            else
            {
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
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24007, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24873, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24010, -16, -16, 32, 32, 0,
                            height, -16, -16, height + 27);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24876, -16, -16, 32, 32, 0, height, -16,
                            -16, height + 27);
                        wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 3:
                        wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                }
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
        case 3:
            if (tileElement->AsTrack()->HasChain())
            {
                switch (direction)
                {
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24048, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24914, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        break;
                }
            }
            else
            {
                switch (direction)
                {
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24006, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24872, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        break;
                }
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
    }
}

/** rct2: 0x008AC8B8 */
template<bool isClassic>
static void wooden_rc_track_diag_25_deg_up(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            if (tileElement->AsTrack()->HasChain())
            {
                switch (direction)
                {
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24068, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24934, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        break;
                }
            }
            else
            {
                switch (direction)
                {
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24026, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24892, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        break;
                }
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 56, 0x20);
            break;
        case 1:
            if (tileElement->AsTrack()->HasChain())
            {
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24065, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24931, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24069, -16, -16, 32, 32, 0,
                            height, -16, -16, height + 43);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24935, -16, -16, 32, 32, 0, height, -16,
                            -16, height + 43);
                        wooden_b_supports_paint_setup(
                            session, 2, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 1:
                        wooden_b_supports_paint_setup(
                            session, 3, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 2:
                        wooden_b_supports_paint_setup(
                            session, 4, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 3:
                        wooden_b_supports_paint_setup(
                            session, 5, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                }
            }
            else
            {
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24023, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24889, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24027, -16, -16, 32, 32, 0,
                            height, -16, -16, height + 43);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24893, -16, -16, 32, 32, 0, height, -16,
                            -16, height + 43);
                        wooden_b_supports_paint_setup(
                            session, 2, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 1:
                        wooden_b_supports_paint_setup(
                            session, 3, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 2:
                        wooden_b_supports_paint_setup(
                            session, 4, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 3:
                        wooden_b_supports_paint_setup(
                            session, 5, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                }
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 56, 0x20);
            break;
        case 2:
            if (tileElement->AsTrack()->HasChain())
            {
                switch (direction)
                {
                    case 0:
                        wooden_b_supports_paint_setup(
                            session, 4, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 1:
                        wooden_b_supports_paint_setup(
                            session, 5, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24067, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24933, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24070, -16, -16, 32, 32, 0,
                            height, -16, -16, height + 43);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24936, -16, -16, 32, 32, 0, height, -16,
                            -16, height + 43);
                        wooden_b_supports_paint_setup(
                            session, 2, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 3:
                        wooden_b_supports_paint_setup(
                            session, 3, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                }
            }
            else
            {
                switch (direction)
                {
                    case 0:
                        wooden_b_supports_paint_setup(
                            session, 4, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 1:
                        wooden_b_supports_paint_setup(
                            session, 5, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24025, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24891, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24028, -16, -16, 32, 32, 0,
                            height, -16, -16, height + 43);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24894, -16, -16, 32, 32, 0, height, -16,
                            -16, height + 43);
                        wooden_b_supports_paint_setup(
                            session, 2, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 3:
                        wooden_b_supports_paint_setup(
                            session, 3, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                }
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 56, 0x20);
            break;
        case 3:
            if (tileElement->AsTrack()->HasChain())
            {
                switch (direction)
                {
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24066, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24932, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        break;
                }
            }
            else
            {
                switch (direction)
                {
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24024, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24890, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        break;
                }
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 56, 0x20);
            break;
    }
}

/** rct2: 0x008AC8E8 */
template<bool isClassic>
static void wooden_rc_track_diag_60_deg_up(
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24044, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24910, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 104, 0x20);
            break;
        case 1:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24041, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24907, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24045, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 91);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24911, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 91);
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
            paint_util_set_general_support_height(session, height + 104, 0x20);
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24043, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24909, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24046, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 91);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24912, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 91);
                    wooden_b_supports_paint_setup(session, 2, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_b_supports_paint_setup(session, 3, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 104, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24042, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24908, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 104, 0x20);
            break;
    }
}

/** rct2: 0x008AC898 */
template<bool isClassic>
static void wooden_rc_track_diag_flat_to_25_deg_up(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            if (tileElement->AsTrack()->HasChain())
            {
                switch (direction)
                {
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24056, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24922, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        break;
                }
            }
            else
            {
                switch (direction)
                {
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24014, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24880, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        break;
                }
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 1:
            if (tileElement->AsTrack()->HasChain())
            {
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24053, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24919, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24057, -16, -16, 32, 32, 0,
                            height, -16, -16, height + 35);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24923, -16, -16, 32, 32, 0, height, -16,
                            -16, height + 35);
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
            }
            else
            {
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24011, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24877, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24015, -16, -16, 32, 32, 0,
                            height, -16, -16, height + 35);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24881, -16, -16, 32, 32, 0, height, -16,
                            -16, height + 35);
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
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 2:
            if (tileElement->AsTrack()->HasChain())
            {
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
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24055, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24921, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24058, -16, -16, 32, 32, 0,
                            height, -16, -16, height + 35);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24924, -16, -16, 32, 32, 0, height, -16,
                            -16, height + 35);
                        wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 3:
                        wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                }
            }
            else
            {
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
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24013, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24879, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24016, -16, -16, 32, 32, 0,
                            height, -16, -16, height + 35);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24882, -16, -16, 32, 32, 0, height, -16,
                            -16, height + 35);
                        wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 3:
                        wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                }
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 3:
            if (tileElement->AsTrack()->HasChain())
            {
                switch (direction)
                {
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24054, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24920, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        break;
                }
            }
            else
            {
                switch (direction)
                {
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24012, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24878, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        break;
                }
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
    }
}

/** rct2: 0x008AC8C8 */
template<bool isClassic>
static void wooden_rc_track_diag_25_deg_up_to_60_deg_up(
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24032, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24898, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 72, 0x20);
            break;
        case 1:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24029, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24895, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24033, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 59);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24899, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 59);
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
            paint_util_set_general_support_height(session, height + 72, 0x20);
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24031, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24897, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24034, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 59);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24900, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 59);
                    wooden_b_supports_paint_setup(session, 2, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_b_supports_paint_setup(session, 3, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 72, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24030, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24896, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 72, 0x20);
            break;
    }
}

/** rct2: 0x008AC8D8 */
template<bool isClassic>
static void wooden_rc_track_diag_60_deg_up_to_25_deg_up(
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24038, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24904, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 72, 0x20);
            break;
        case 1:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24035, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24901, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24039, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 59);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24905, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 59);
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
            paint_util_set_general_support_height(session, height + 72, 0x20);
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24037, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24903, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24040, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 59);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24906, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 59);
                    wooden_b_supports_paint_setup(session, 2, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_b_supports_paint_setup(session, 3, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 72, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24036, -16, -16, 16, 16, 2, height,
                        0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24902, -16, -16, 16, 16, 2, height, 0, 0,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 72, 0x20);
            break;
    }
}

/** rct2: 0x008AC8A8 */
template<bool isClassic>
static void wooden_rc_track_diag_25_deg_up_to_flat(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            if (tileElement->AsTrack()->HasChain())
            {
                switch (direction)
                {
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24062, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24928, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        break;
                }
            }
            else
            {
                switch (direction)
                {
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24020, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24886, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        break;
                }
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 56, 0x20);
            break;
        case 1:
            if (tileElement->AsTrack()->HasChain())
            {
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24059, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24925, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24063, -16, -16, 32, 32, 0,
                            height, -16, -16, height + 35);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24929, -16, -16, 32, 32, 0, height, -16,
                            -16, height + 35);
                        wooden_b_supports_paint_setup(
                            session, 2, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 1:
                        wooden_b_supports_paint_setup(
                            session, 3, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 2:
                        wooden_b_supports_paint_setup(
                            session, 4, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 3:
                        wooden_b_supports_paint_setup(
                            session, 5, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                }
            }
            else
            {
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24017, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24883, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24021, -16, -16, 32, 32, 0,
                            height, -16, -16, height + 35);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24887, -16, -16, 32, 32, 0, height, -16,
                            -16, height + 35);
                        wooden_b_supports_paint_setup(
                            session, 2, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 1:
                        wooden_b_supports_paint_setup(
                            session, 3, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 2:
                        wooden_b_supports_paint_setup(
                            session, 4, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 3:
                        wooden_b_supports_paint_setup(
                            session, 5, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                }
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 56, 0x20);
            break;
        case 2:
            if (tileElement->AsTrack()->HasChain())
            {
                switch (direction)
                {
                    case 0:
                        wooden_b_supports_paint_setup(
                            session, 4, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 1:
                        wooden_b_supports_paint_setup(
                            session, 5, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24061, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24927, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24064, -16, -16, 32, 32, 0,
                            height, -16, -16, height + 35);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24930, -16, -16, 32, 32, 0, height, -16,
                            -16, height + 35);
                        wooden_b_supports_paint_setup(
                            session, 2, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 3:
                        wooden_b_supports_paint_setup(
                            session, 3, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                }
            }
            else
            {
                switch (direction)
                {
                    case 0:
                        wooden_b_supports_paint_setup(
                            session, 4, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 1:
                        wooden_b_supports_paint_setup(
                            session, 5, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24019, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24885, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24022, -16, -16, 32, 32, 0,
                            height, -16, -16, height + 35);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24888, -16, -16, 32, 32, 0, height, -16,
                            -16, height + 35);
                        wooden_b_supports_paint_setup(
                            session, 2, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 3:
                        wooden_b_supports_paint_setup(
                            session, 3, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                }
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 56, 0x20);
            break;
        case 3:
            if (tileElement->AsTrack()->HasChain())
            {
                switch (direction)
                {
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24060, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24926, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        break;
                }
            }
            else
            {
                switch (direction)
                {
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24018, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24884, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        break;
                }
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 56, 0x20);
            break;
    }
}

/** rct2: 0x008AC918 */
template<bool isClassic>
static void wooden_rc_track_diag_25_deg_down(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            if (tileElement->AsTrack()->HasChain())
            {
                switch (direction)
                {
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24066, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24932, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        break;
                }
            }
            else
            {
                switch (direction)
                {
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24024, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24890, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        break;
                }
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 56, 0x20);
            break;
        case 1:
            if (tileElement->AsTrack()->HasChain())
            {
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24067, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24933, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24070, -16, -16, 32, 32, 0,
                            height, -16, -16, height + 43);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24936, -16, -16, 32, 32, 0, height, -16,
                            -16, height + 43);
                        wooden_b_supports_paint_setup(
                            session, 2, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 1:
                        wooden_b_supports_paint_setup(
                            session, 3, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 2:
                        wooden_b_supports_paint_setup(
                            session, 4, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 3:
                        wooden_b_supports_paint_setup(
                            session, 5, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                }
            }
            else
            {
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24025, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24891, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24028, -16, -16, 32, 32, 0,
                            height, -16, -16, height + 43);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24894, -16, -16, 32, 32, 0, height, -16,
                            -16, height + 43);
                        wooden_b_supports_paint_setup(
                            session, 2, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 1:
                        wooden_b_supports_paint_setup(
                            session, 3, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 2:
                        wooden_b_supports_paint_setup(
                            session, 4, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 3:
                        wooden_b_supports_paint_setup(
                            session, 5, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                }
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 56, 0x20);
            break;
        case 2:
            if (tileElement->AsTrack()->HasChain())
            {
                switch (direction)
                {
                    case 0:
                        wooden_b_supports_paint_setup(
                            session, 4, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 1:
                        wooden_b_supports_paint_setup(
                            session, 5, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24065, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24931, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24069, -16, -16, 32, 32, 0,
                            height, -16, -16, height + 43);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24935, -16, -16, 32, 32, 0, height, -16,
                            -16, height + 43);
                        wooden_b_supports_paint_setup(
                            session, 2, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 3:
                        wooden_b_supports_paint_setup(
                            session, 3, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                }
            }
            else
            {
                switch (direction)
                {
                    case 0:
                        wooden_b_supports_paint_setup(
                            session, 4, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 1:
                        wooden_b_supports_paint_setup(
                            session, 5, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24023, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24889, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24027, -16, -16, 32, 32, 0,
                            height, -16, -16, height + 43);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24893, -16, -16, 32, 32, 0, height, -16,
                            -16, height + 43);
                        wooden_b_supports_paint_setup(
                            session, 2, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 3:
                        wooden_b_supports_paint_setup(
                            session, 3, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                }
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 56, 0x20);
            break;
        case 3:
            if (tileElement->AsTrack()->HasChain())
            {
                switch (direction)
                {
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24068, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24934, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        break;
                }
            }
            else
            {
                switch (direction)
                {
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24026, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24892, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        break;
                }
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 56, 0x20);
            break;
    }
}

/** rct2: 0x008AC948 */
template<bool isClassic>
static void wooden_rc_track_diag_60_deg_down(
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24042, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24908, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 104, 0x20);
            break;
        case 1:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24043, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24909, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24046, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 91);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24912, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 91);
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
            paint_util_set_general_support_height(session, height + 104, 0x20);
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24041, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24907, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24045, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 91);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24911, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 91);
                    wooden_b_supports_paint_setup(session, 2, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_b_supports_paint_setup(session, 3, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 104, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24044, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24910, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 104, 0x20);
            break;
    }
}

/** rct2: 0x008AC8F8 */
template<bool isClassic>
static void wooden_rc_track_diag_flat_to_25_deg_down(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            if (tileElement->AsTrack()->HasChain())
            {
                switch (direction)
                {
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24060, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24926, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        break;
                }
            }
            else
            {
                switch (direction)
                {
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24018, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24884, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        break;
                }
            }
            break;
        case 1:
            if (tileElement->AsTrack()->HasChain())
            {
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24061, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24927, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24064, -16, -16, 32, 32, 0,
                            height, -16, -16, height + 35);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24930, -16, -16, 32, 32, 0, height, -16,
                            -16, height + 35);
                        wooden_b_supports_paint_setup(
                            session, 2, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 1:
                        wooden_b_supports_paint_setup(
                            session, 3, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 2:
                        wooden_b_supports_paint_setup(
                            session, 4, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 3:
                        wooden_b_supports_paint_setup(
                            session, 5, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                }
            }
            else
            {
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24019, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24885, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24022, -16, -16, 32, 32, 0,
                            height, -16, -16, height + 35);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24888, -16, -16, 32, 32, 0, height, -16,
                            -16, height + 35);
                        wooden_b_supports_paint_setup(
                            session, 2, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 1:
                        wooden_b_supports_paint_setup(
                            session, 3, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 2:
                        wooden_b_supports_paint_setup(
                            session, 4, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 3:
                        wooden_b_supports_paint_setup(
                            session, 5, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                }
            }
            break;
        case 2:
            if (tileElement->AsTrack()->HasChain())
            {
                switch (direction)
                {
                    case 0:
                        wooden_b_supports_paint_setup(
                            session, 4, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 1:
                        wooden_b_supports_paint_setup(
                            session, 5, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24059, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24925, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24063, -16, -16, 32, 32, 0,
                            height, -16, -16, height + 35);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24929, -16, -16, 32, 32, 0, height, -16,
                            -16, height + 35);
                        wooden_b_supports_paint_setup(
                            session, 2, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 3:
                        wooden_b_supports_paint_setup(
                            session, 3, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                }
            }
            else
            {
                switch (direction)
                {
                    case 0:
                        wooden_b_supports_paint_setup(
                            session, 4, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 1:
                        wooden_b_supports_paint_setup(
                            session, 5, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 2:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24017, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24883, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24021, -16, -16, 32, 32, 0,
                            height, -16, -16, height + 35);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24887, -16, -16, 32, 32, 0, height, -16,
                            -16, height + 35);
                        wooden_b_supports_paint_setup(
                            session, 2, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 3:
                        wooden_b_supports_paint_setup(
                            session, 3, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                }
            }
            break;
        case 3:
            if (tileElement->AsTrack()->HasChain())
            {
                switch (direction)
                {
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24062, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24928, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        break;
                }
            }
            else
            {
                switch (direction)
                {
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24020, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24886, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        break;
                }
            }
            break;
    }

    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 56, 0x20);
}

/** rct2: 0x008AC928 */
template<bool isClassic>
static void wooden_rc_track_diag_25_deg_down_to_60_deg_down(
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24036, -16, -16, 16, 16, 2, height,
                        0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24902, -16, -16, 16, 16, 2, height, 0, 0,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 72, 0x20);
            break;
        case 1:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24037, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24903, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24040, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 59);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24906, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 59);
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
            paint_util_set_general_support_height(session, height + 72, 0x20);
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24035, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24901, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24039, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 59);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24905, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 59);
                    wooden_b_supports_paint_setup(session, 2, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_b_supports_paint_setup(session, 3, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 72, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24038, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24904, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 72, 0x20);
            break;
    }
}

/** rct2: 0x008AC938 */
template<bool isClassic>
static void wooden_rc_track_diag_60_deg_down_to_25_deg_down(
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24030, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24896, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 72, 0x20);
            break;
        case 1:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24031, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24897, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24034, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 59);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24900, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 59);
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
            paint_util_set_general_support_height(session, height + 72, 0x20);
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
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24029, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24895, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24033, -16, -16, 32, 32, 0, height,
                        -16, -16, height + 59);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24899, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 59);
                    wooden_b_supports_paint_setup(session, 2, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    wooden_b_supports_paint_setup(session, 3, 0, height + 16, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 72, 0x20);
            break;
        case 3:
            switch (direction)
            {
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24032, -16, -16, 32, 32, 2, height,
                        -16, -16, height);
                    PaintAddImageAsChildRotated(
                        session, direction, wooden_rc_get_rails_colour(session) | 24898, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 72, 0x20);
            break;
    }
}

/** rct2: 0x008AC908 */
template<bool isClassic>
static void wooden_rc_track_diag_25_deg_down_to_flat(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    switch (trackSequence)
    {
        case 0:
            if (tileElement->AsTrack()->HasChain())
            {
                switch (direction)
                {
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24054, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24920, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        break;
                }
            }
            else
            {
                switch (direction)
                {
                    case 3:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24012, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24878, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        break;
                }
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 1:
            if (tileElement->AsTrack()->HasChain())
            {
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24055, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24921, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24058, -16, -16, 32, 32, 0,
                            height, -16, -16, height + 35);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24924, -16, -16, 32, 32, 0, height, -16,
                            -16, height + 35);
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
            }
            else
            {
                switch (direction)
                {
                    case 0:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24013, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24879, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24016, -16, -16, 32, 32, 0,
                            height, -16, -16, height + 35);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24882, -16, -16, 32, 32, 0, height, -16,
                            -16, height + 35);
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
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 2:
            if (tileElement->AsTrack()->HasChain())
            {
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
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24053, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24919, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24057, -16, -16, 32, 32, 0,
                            height, -16, -16, height + 35);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24923, -16, -16, 32, 32, 0, height, -16,
                            -16, height + 35);
                        wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 3:
                        wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                }
            }
            else
            {
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
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24011, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24877, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24015, -16, -16, 32, 32, 0,
                            height, -16, -16, height + 35);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24881, -16, -16, 32, 32, 0, height, -16,
                            -16, height + 35);
                        wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                    case 3:
                        wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                        break;
                }
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
        case 3:
            if (tileElement->AsTrack()->HasChain())
            {
                switch (direction)
                {
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24056, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24922, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        break;
                }
            }
            else
            {
                switch (direction)
                {
                    case 1:
                        PaintAddImageAsParentRotated(
                            session, direction, wooden_rc_get_track_colour<isClassic>(session) | 24014, -16, -16, 32, 32, 2,
                            height, -16, -16, height);
                        PaintAddImageAsChildRotated(
                            session, direction, wooden_rc_get_rails_colour(session) | 24880, -16, -16, 32, 32, 2, height, -16,
                            -16, height);
                        break;
                }
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
    }
}

/** rct2: 0x008ACDF8 */
template<bool isClassic>
static void wooden_rc_track_block_brakes(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    const auto brakeImg = tileElement->AsTrack()->BlockBrakeClosed() ? _wooden_rc_block_brakes_image_ids[direction][1]
                                                                     : _wooden_rc_block_brakes_image_ids[direction][0];
    wooden_rc_track_paint<isClassic>(
        session, brakeImg, _wooden_rc_block_brakes_image_ids[direction][2], direction, 0, 2, 32, 25, 2, height, 0, 3, height);
    wooden_a_supports_paint_setup(session, direction & 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
    paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_FLAT);
    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 32, 0x20);
}

template<bool isClassic>
static void wooden_rc_track_booster(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    static constexpr const uint32_t imageIds[4] = {
        SPR_G2_WOODEN_RC_BOOSTER_SW_NE,
        SPR_G2_WOODEN_RC_BOOSTER_NW_SE,
        SPR_G2_WOODEN_RC_BOOSTER_SW_NE,
        SPR_G2_WOODEN_RC_BOOSTER_NW_SE,
    };
    static constexpr const uint32_t railsImageIds[4] = {
        SPR_WOODEN_RC_FLAT_CHAIN_RAILS_SW_NE,
        SPR_WOODEN_RC_FLAT_CHAIN_RAILS_NW_SE,
        SPR_WOODEN_RC_FLAT_CHAIN_RAILS_NE_SW,
        SPR_WOODEN_RC_FLAT_CHAIN_RAILS_SE_NW,
    };

    wooden_rc_track_paint<isClassic>(
        session, imageIds[direction], railsImageIds[direction], direction, 0, 2, 32, 25, 2, height, 0, 3, height);
    wooden_a_supports_paint_setup(session, direction & 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
    paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_FLAT);
    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 32, 0x20);
}

template<bool isClassic> TRACK_PAINT_FUNCTION get_track_paint_function_wooden_rc(int32_t trackType)
{
    switch (trackType)
    {
        case TrackElemType::Flat:
            return wooden_rc_track_flat<isClassic>;
        case TrackElemType::EndStation:
        case TrackElemType::BeginStation:
        case TrackElemType::MiddleStation:
            return wooden_rc_track_station<isClassic>;
        case TrackElemType::Up25:
            return wooden_rc_track_25_deg_up<isClassic>;
        case TrackElemType::Up60:
            return wooden_rc_track_60_deg_up<isClassic>;
        case TrackElemType::FlatToUp25:
            return wooden_rc_track_flat_to_25_deg_up<isClassic>;
        case TrackElemType::Up25ToUp60:
            return wooden_rc_track_25_deg_up_to_60_deg_up<isClassic>;
        case TrackElemType::Up60ToUp25:
            return wooden_rc_track_60_deg_up_to_25_deg_up<isClassic>;
        case TrackElemType::Up25ToFlat:
            return wooden_rc_track_25_deg_up_to_flat<isClassic>;
        case TrackElemType::Down25:
            return wooden_rc_track_25_deg_down<isClassic>;
        case TrackElemType::Down60:
            return wooden_rc_track_60_deg_down<isClassic>;
        case TrackElemType::FlatToDown25:
            return wooden_rc_track_flat_to_25_deg_down<isClassic>;
        case TrackElemType::Down25ToDown60:
            return wooden_rc_track_25_deg_down_to_60_deg_down<isClassic>;
        case TrackElemType::Down60ToDown25:
            return wooden_rc_track_60_deg_down_to_25_deg_down<isClassic>;
        case TrackElemType::Down25ToFlat:
            return wooden_rc_track_25_deg_down_to_flat<isClassic>;
        case TrackElemType::LeftQuarterTurn5Tiles:
            return wooden_rc_track_left_quarter_turn_5<isClassic>;
        case TrackElemType::RightQuarterTurn5Tiles:
            return wooden_rc_track_right_quarter_turn_5<isClassic>;
        case TrackElemType::LeftQuarterTurn5TilesUp25:
            return wooden_rc_track_left_quarter_turn_5_25_deg_up<isClassic>;
        case TrackElemType::RightQuarterTurn5TilesUp25:
            return wooden_rc_track_right_quarter_turn_5_25_deg_up<isClassic>;
        case TrackElemType::LeftQuarterTurn5TilesDown25:
            return wooden_rc_track_left_quarter_turn_5_25_deg_down<isClassic>;
        case TrackElemType::RightQuarterTurn5TilesDown25:
            return wooden_rc_track_right_quarter_turn_5_25_deg_down<isClassic>;
        case TrackElemType::SBendLeft:
            return wooden_rc_track_s_bend_left<isClassic>;
        case TrackElemType::SBendRight:
            return wooden_rc_track_s_bend_right<isClassic>;
        case TrackElemType::LeftVerticalLoop:
            return wooden_rc_track_left_vertical_loop<isClassic>;
        case TrackElemType::RightVerticalLoop:
            return wooden_rc_track_right_vertical_loop<isClassic>;
        case TrackElemType::LeftQuarterTurn3Tiles:
            return wooden_rc_track_left_quarter_turn_3<isClassic>;
        case TrackElemType::RightQuarterTurn3Tiles:
            return wooden_rc_track_right_quarter_turn_3<isClassic>;
        case TrackElemType::LeftQuarterTurn3TilesUp25:
            return wooden_rc_track_left_quarter_turn_3_25_deg_up<isClassic>;
        case TrackElemType::RightQuarterTurn3TilesUp25:
            return wooden_rc_track_right_quarter_turn_3_25_deg_up<isClassic>;
        case TrackElemType::LeftQuarterTurn3TilesDown25:
            return wooden_rc_track_left_quarter_turn_3_25_deg_down<isClassic>;
        case TrackElemType::RightQuarterTurn3TilesDown25:
            return wooden_rc_track_right_quarter_turn_3_25_deg_down<isClassic>;
        case TrackElemType::Brakes:
            return wooden_rc_track_brakes<isClassic>;
        case TrackElemType::OnRidePhoto:
            return wooden_rc_track_on_ride_photo<isClassic>;
        case TrackElemType::Watersplash:
            return wooden_rc_track_water_splash<isClassic>;
        case TrackElemType::LeftEighthToDiag:
            return wooden_rc_track_left_eighth_to_diag<isClassic>;
        case TrackElemType::RightEighthToDiag:
            return wooden_rc_track_right_eighth_to_diag<isClassic>;
        case TrackElemType::LeftEighthToOrthogonal:
            return wooden_rc_track_left_eighth_to_orthogonal<isClassic>;
        case TrackElemType::RightEighthToOrthogonal:
            return wooden_rc_track_right_eighth_to_orthogonal<isClassic>;
        case TrackElemType::DiagFlat:
            return wooden_rc_track_diag_flat<isClassic>;
        case TrackElemType::DiagUp25:
            return wooden_rc_track_diag_25_deg_up<isClassic>;
        case TrackElemType::DiagUp60:
            return wooden_rc_track_diag_60_deg_up<isClassic>;
        case TrackElemType::DiagFlatToUp25:
            return wooden_rc_track_diag_flat_to_25_deg_up<isClassic>;
        case TrackElemType::DiagUp25ToUp60:
            return wooden_rc_track_diag_25_deg_up_to_60_deg_up<isClassic>;
        case TrackElemType::DiagUp60ToUp25:
            return wooden_rc_track_diag_60_deg_up_to_25_deg_up<isClassic>;
        case TrackElemType::DiagUp25ToFlat:
            return wooden_rc_track_diag_25_deg_up_to_flat<isClassic>;
        case TrackElemType::DiagDown25:
            return wooden_rc_track_diag_25_deg_down<isClassic>;
        case TrackElemType::DiagDown60:
            return wooden_rc_track_diag_60_deg_down<isClassic>;
        case TrackElemType::DiagFlatToDown25:
            return wooden_rc_track_diag_flat_to_25_deg_down<isClassic>;
        case TrackElemType::DiagDown25ToDown60:
            return wooden_rc_track_diag_25_deg_down_to_60_deg_down<isClassic>;
        case TrackElemType::DiagDown60ToDown25:
            return wooden_rc_track_diag_60_deg_down_to_25_deg_down<isClassic>;
        case TrackElemType::DiagDown25ToFlat:
            return wooden_rc_track_diag_25_deg_down_to_flat<isClassic>;
        case TrackElemType::LeftQuarterTurn1TileUp60:
            return wooden_rc_track_left_quarter_turn_1_60_deg_up<isClassic>;
        case TrackElemType::RightQuarterTurn1TileUp60:
            return wooden_rc_track_right_quarter_turn_1_60_deg_up<isClassic>;
        case TrackElemType::LeftQuarterTurn1TileDown60:
            return wooden_rc_track_left_quarter_turn_1_60_deg_down<isClassic>;
        case TrackElemType::RightQuarterTurn1TileDown60:
            return wooden_rc_track_right_quarter_turn_1_60_deg_down<isClassic>;
        case TrackElemType::BlockBrakes:
            return wooden_rc_track_block_brakes<isClassic>;
        case TrackElemType::Booster:
            return wooden_rc_track_booster<isClassic>;
    }
    
    return nullptr;
}
