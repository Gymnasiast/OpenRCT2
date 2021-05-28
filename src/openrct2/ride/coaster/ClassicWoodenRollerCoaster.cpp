/*****************************************************************************
 * Copyright (c) 2014-2020 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "../../drawing/Drawing.h"
#include "../../interface/Viewport.h"
#include "../../paint/Paint.h"
#include "../../paint/Supports.h"
#include "../../paint/tile_element/Paint.TileElement.h"
#include "../../sprites.h"
#include "../../world/Map.h"
#include "../../world/Sprite.h"
#include "../RideData.h"
#include "../TrackData.h"
#include "../TrackPaint.h"
#include "WoodenRollerCoaster.hpp"

enum
{
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_SW_NE = SPR_CSG_BEGIN + 64788,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_NW_SE = SPR_CSG_BEGIN + 64789,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_NE_SW = SPR_CSG_BEGIN + 64790,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_SE_NW = SPR_CSG_BEGIN + 64791,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_RIGHT_BANK_SW_NE = SPR_CSG_BEGIN + 64792,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_RIGHT_BANK_NW_SE = SPR_CSG_BEGIN + 64793,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_RIGHT_BANK_NE_SW = SPR_CSG_BEGIN + 64794,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_RIGHT_BANK_SE_NW = SPR_CSG_BEGIN + 64795,
    SPR_CLASSIC_WOODEN_RC_LEFT_BANK_SW_NE = SPR_CSG_BEGIN + 64796,
    SPR_CLASSIC_WOODEN_RC_LEFT_BANK_NW_SE = SPR_CSG_BEGIN + 64797,
    SPR_CLASSIC_WOODEN_RC_LEFT_BANK_NE_SW = SPR_CSG_BEGIN + 64798,
    SPR_CLASSIC_WOODEN_RC_LEFT_BANK_SE_NW = SPR_CSG_BEGIN + 64799,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_LEFT_BANK_SW_NE = SPR_CSG_BEGIN + 64800,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_LEFT_BANK_NW_SE = SPR_CSG_BEGIN + 64801,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_LEFT_BANK_NE_SW = SPR_CSG_BEGIN + 64802,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_LEFT_BANK_SE_NW = SPR_CSG_BEGIN + 64803,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_RIGHT_BANK_SW_NE = SPR_CSG_BEGIN + 64804,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_RIGHT_BANK_NW_SE = SPR_CSG_BEGIN + 64805,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_RIGHT_BANK_NE_SW = SPR_CSG_BEGIN + 64806,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_RIGHT_BANK_SE_NW = SPR_CSG_BEGIN + 64807,
    SPR_CLASSIC_WOODEN_RC_LEFT_BANK_TO_25_DEG_SW_NE = SPR_CSG_BEGIN + 64808,
    SPR_CLASSIC_WOODEN_RC_LEFT_BANK_TO_25_DEG_NW_SE = SPR_CSG_BEGIN + 64809,
    SPR_CLASSIC_WOODEN_RC_LEFT_BANK_TO_25_DEG_NE_SW = SPR_CSG_BEGIN + 64810,
    SPR_CLASSIC_WOODEN_RC_LEFT_BANK_TO_25_DEG_SE_NW = SPR_CSG_BEGIN + 64811,
    SPR_CLASSIC_WOODEN_RC_RIGHT_BANK_TO_25_DEG_SW_NE = SPR_CSG_BEGIN + 64812,
    SPR_CLASSIC_WOODEN_RC_RIGHT_BANK_TO_25_DEG_NW_SE = SPR_CSG_BEGIN + 64813,
    SPR_CLASSIC_WOODEN_RC_RIGHT_BANK_TO_25_DEG_NE_SW = SPR_CSG_BEGIN + 64814,
    SPR_CLASSIC_WOODEN_RC_RIGHT_BANK_TO_25_DEG_SE_NW = SPR_CSG_BEGIN + 64815,
    SPR_CLASSIC_WOODEN_RC_RC_FLAT_TO_LEFT_BANK_FRONT_NW_SE = SPR_CSG_BEGIN + 64816,
    SPR_CLASSIC_WOODEN_RC_RC_FLAT_TO_LEFT_BANK_FRONT_SE_NW = SPR_CSG_BEGIN + 64817,
    SPR_CLASSIC_WOODEN_RC_RC_FLAT_TO_RIGHT_BANK_FRONT_NE_SW = SPR_CSG_BEGIN + 64818,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_LEFT_BANK_FRONT_NW_SE = SPR_CSG_BEGIN + 64819,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_LEFT_BANK_FRONT_NE_SW = SPR_CSG_BEGIN + 64820,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_RIGHT_BANK_FRONT_NW_SE = SPR_CSG_BEGIN + 64821,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_RIGHT_BANK_FRONT_NE_SW = SPR_CSG_BEGIN + 64822,
    SPR_CLASSIC_WOODEN_RC_LEFT_BANK_TO_25_DEG_FRONT_NW_SE = SPR_CSG_BEGIN + 64823,
    SPR_CLASSIC_WOODEN_RC_LEFT_BANK_TO_25_DEG_FRONT_NE_SW = SPR_CSG_BEGIN + 64824,
    SPR_CLASSIC_WOODEN_RC_RIGHT_BANK_TO_25_DEG_FRONT_NW_SE = SPR_CSG_BEGIN + 64825,
    SPR_CLASSIC_WOODEN_RC_RIGHT_BANK_TO_25_DEG_FRONT_NE_SW = SPR_CSG_BEGIN + 64826,
    SPR_CLASSIC_WOODEN_RC_RC_FLAT_TO_RIGHT_BANK_FRONT_SW_NE = 23536,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_25_DEG_SW_NE = SPR_CSG_BEGIN + 64827,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_25_DEG_NW_SE = SPR_CSG_BEGIN + 64828,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_25_DEG_NE_SW = SPR_CSG_BEGIN + 64829,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_25_DEG_SE_NW = SPR_CSG_BEGIN + 64830,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_FLAT_SW_NE = SPR_CSG_BEGIN + 64831,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_FLAT_NW_SE = SPR_CSG_BEGIN + 64832,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_FLAT_NE_SW = SPR_CSG_BEGIN + 64833,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_FLAT_SE_NW = SPR_CSG_BEGIN + 64834,
    SPR_CLASSIC_WOODEN_RC_25_DEG_SW_NE = SPR_CSG_BEGIN + 64835,
    SPR_CLASSIC_WOODEN_RC_25_DEG_NW_SE = SPR_CSG_BEGIN + 64836,
    SPR_CLASSIC_WOODEN_RC_25_DEG_NE_SW = SPR_CSG_BEGIN + 64837,
    SPR_CLASSIC_WOODEN_RC_25_DEG_SE_NW = SPR_CSG_BEGIN + 64838,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_60_DEG_SW_NE = SPR_CSG_BEGIN + 64839,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_60_DEG_FRONT_NW_SE = SPR_CSG_BEGIN + 64840,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_60_DEG_NW_SE = SPR_CSG_BEGIN + 64841,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_60_DEG_FRONT_NE_SW = SPR_CSG_BEGIN + 64842,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_60_DEG_NE_SW = SPR_CSG_BEGIN + 64843,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_60_DEG_SE_NW = SPR_CSG_BEGIN + 64844,
    SPR_CLASSIC_WOODEN_RC_60_DEG_TO_25_DEG_SW_NE = SPR_CSG_BEGIN + 64845,
    SPR_CLASSIC_WOODEN_RC_60_DEG_TO_25_DEG_FRONT_NW_SE = SPR_CSG_BEGIN + 64846,
    SPR_CLASSIC_WOODEN_RC_60_DEG_TO_25_DEG_NW_SE = SPR_CSG_BEGIN + 64847,
    SPR_CLASSIC_WOODEN_RC_60_DEG_TO_25_DEG_FRONT_NE_SW = SPR_CSG_BEGIN + 64848,
    SPR_CLASSIC_WOODEN_RC_60_DEG_TO_25_DEG_NE_SW = SPR_CSG_BEGIN + 64849,
    SPR_CLASSIC_WOODEN_RC_60_DEG_TO_25_DEG_SE_NW = SPR_CSG_BEGIN + 64850,
    SPR_CLASSIC_WOODEN_RC_60_DEG_SW_NE = SPR_CSG_BEGIN + 64851,
    SPR_CLASSIC_WOODEN_RC_60_DEG_CHAIN_SW_NE = 23558,
    SPR_CLASSIC_WOODEN_RC_60_DEG_NW_SE = SPR_CSG_BEGIN + 64852,
    SPR_CLASSIC_WOODEN_RC_60_DEG_CHAIN_NW_SE = 23560,
    SPR_CLASSIC_WOODEN_RC_60_DEG_NE_SW = SPR_CSG_BEGIN + 64853,
    SPR_CLASSIC_WOODEN_RC_60_DEG_CHAIN_NE_SW = 23562,
    SPR_CLASSIC_WOODEN_RC_60_DEG_SE_NW = SPR_CSG_BEGIN + 64854,
    SPR_CLASSIC_WOODEN_RC_60_DEG_CHAIN_SE_NW = 23564,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_25_DEG_FRONT_NW_SE = SPR_CSG_BEGIN + 64855,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_25_DEG_FRONT_NE_SW = SPR_CSG_BEGIN + 64856,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_FLAT_FRONT_NW_SE = SPR_CSG_BEGIN + 64857,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_FLAT_FRONT_NE_SW = SPR_CSG_BEGIN + 64858,
    SPR_CLASSIC_WOODEN_RC_25_DEG_FRONT_NW_SE = 23569,
    SPR_CLASSIC_WOODEN_RC_60_DEG_FRONT_NW_SE = 23569,
    SPR_CLASSIC_WOODEN_RC_25_DEG_FRONT_NE_SW = 23570,
    SPR_CLASSIC_WOODEN_RC_60_DEG_FRONT_NE_SW = 23570,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_25_DEG_CHAIN_SW_NE = 23571,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_25_DEG_CHAIN_NW_SE = 23572,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_25_DEG_CHAIN_NE_SW = 23573,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_25_DEG_CHAIN_SE_NW = 23574,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_FLAT_CHAIN_SW_NE = 23575,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_FLAT_CHAIN_NW_SE = 23576,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_FLAT_CHAIN_NE_SW = 23577,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_FLAT_CHAIN_SE_NW = 23578,
    SPR_CLASSIC_WOODEN_RC_25_DEG_CHAIN_SW_NE = 23579,
    SPR_CLASSIC_WOODEN_RC_25_DEG_CHAIN_NW_SE = 23580,
    SPR_CLASSIC_WOODEN_RC_25_DEG_CHAIN_NE_SW = 23581,
    SPR_CLASSIC_WOODEN_RC_25_DEG_CHAIN_SE_NW = 23582,

    SPR_CLASSIC_WOODEN_RC_FLAT_TO_25_DEG_CHAIN_FRONT_NW_SE = 23599,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_25_DEG_CHAIN_FRONT_NE_SW = 23600,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_FLAT_CHAIN_FRONT_NW_SE = 23601,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_FLAT_CHAIN_FRONT_NE_SW = 23602,
    SPR_CLASSIC_WOODEN_RC_25_DEG_CHAIN_FRONT_NW_SE = 23603,
    SPR_CLASSIC_WOODEN_RC_60_DEG_CHAIN_FRONT_NW_SE = 23603,
    SPR_CLASSIC_WOODEN_RC_25_DEG_CHAIN_FRONT_NE_SW = 23604,
    SPR_CLASSIC_WOODEN_RC_60_DEG_CHAIN_FRONT_NE_SW = 23604,
    SPR_CLASSIC_WOODEN_RC_QUARTER_TURN_5_SW_SE_SEQ_0 = 23605,
    SPR_CLASSIC_WOODEN_RC_QUARTER_TURN_5_SW_SE_SEQ_2 = 23606,
    SPR_CLASSIC_WOODEN_RC_QUARTER_TURN_5_SW_SE_SEQ_3 = 23607,
    SPR_CLASSIC_WOODEN_RC_QUARTER_TURN_5_SW_SE_SEQ_5 = 23608,
    SPR_CLASSIC_WOODEN_RC_QUARTER_TURN_5_SW_SE_SEQ_6 = 23609,
    SPR_CLASSIC_WOODEN_RC_QUARTER_TURN_5_NW_SW_SEQ_0 = 23610,
    SPR_CLASSIC_WOODEN_RC_QUARTER_TURN_5_NW_SW_SEQ_2 = 23611,
    SPR_CLASSIC_WOODEN_RC_QUARTER_TURN_5_NW_SW_SEQ_3 = 23612,
    SPR_CLASSIC_WOODEN_RC_QUARTER_TURN_5_NW_SW_SEQ_5 = 23613,
    SPR_CLASSIC_WOODEN_RC_QUARTER_TURN_5_NW_SW_SEQ_6 = 23614,
    SPR_CLASSIC_WOODEN_RC_QUARTER_TURN_5_NE_NW_SEQ_0 = 23615,
    SPR_CLASSIC_WOODEN_RC_QUARTER_TURN_5_NE_NW_SEQ_2 = 23616,
    SPR_CLASSIC_WOODEN_RC_QUARTER_TURN_5_NE_NW_SEQ_3 = 23617,
    SPR_CLASSIC_WOODEN_RC_QUARTER_TURN_5_NE_NW_SEQ_5 = 23618,
    SPR_CLASSIC_WOODEN_RC_QUARTER_TURN_5_NE_NW_SEQ_6 = 23619,
    SPR_CLASSIC_WOODEN_RC_QUARTER_TURN_5_SE_NE_SEQ_0 = 23620,
    SPR_CLASSIC_WOODEN_RC_QUARTER_TURN_5_SE_NE_SEQ_2 = 23621,
    SPR_CLASSIC_WOODEN_RC_QUARTER_TURN_5_SE_NE_SEQ_3 = 23622,
    SPR_CLASSIC_WOODEN_RC_QUARTER_TURN_5_SE_NE_SEQ_5 = 23623,
    SPR_CLASSIC_WOODEN_RC_QUARTER_TURN_5_SE_NE_SEQ_6 = 23624,
    SPR_CLASSIC_WOODEN_RC_QUARTER_TURN_5_FRONT_SW_SE_SEQ_0 = 23625,
    SPR_CLASSIC_WOODEN_RC_QUARTER_TURN_5_FRONT_SW_SE_SEQ_2 = 23626,
    SPR_CLASSIC_WOODEN_RC_QUARTER_TURN_5_FRONT_SW_SE_SEQ_3 = 23627,
    SPR_CLASSIC_WOODEN_RC_QUARTER_TURN_5_FRONT_SW_SE_SEQ_5 = 23628,
    SPR_CLASSIC_WOODEN_RC_QUARTER_TURN_5_FRONT_SW_SE_SEQ_6 = 23629,
    SPR_CLASSIC_WOODEN_RC_QUARTER_TURN_5_FRONT_NE_NW_SEQ_0 = 23630,
    SPR_CLASSIC_WOODEN_RC_QUARTER_TURN_5_FRONT_NE_NW_SEQ_2 = 23631,
    SPR_CLASSIC_WOODEN_RC_QUARTER_TURN_5_FRONT_NE_NW_SEQ_3 = 23632,
    SPR_CLASSIC_WOODEN_RC_QUARTER_TURN_5_FRONT_NE_NW_SEQ_5 = 23633,
    SPR_CLASSIC_WOODEN_RC_QUARTER_TURN_5_FRONT_NE_NW_SEQ_6 = 23634,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_SW_SE_SEQ_0 = 23635,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_SW_SE_SEQ_2 = 23636,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_SW_SE_SEQ_3 = 23637,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_SW_SE_SEQ_5 = 23638,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_SW_SE_SEQ_6 = 23639,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_NW_SW_SEQ_0 = 23640,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_NW_SW_SEQ_2 = 23641,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_NW_SW_SEQ_3 = 23642,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_NW_SW_SEQ_5 = 23643,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_NW_SW_SEQ_6 = 23644,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_NE_NW_SEQ_0 = 23645,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_NE_NW_SEQ_2 = 23646,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_NE_NW_SEQ_3 = 23647,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_NE_NW_SEQ_5 = 23648,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_NE_NW_SEQ_6 = 23649,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_SE_NE_SEQ_0 = 23650,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_SE_NE_SEQ_2 = 23651,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_SE_NE_SEQ_3 = 23652,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_SE_NE_SEQ_5 = 23653,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_SE_NE_SEQ_6 = 23654,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_SW_SE_SEQ_0 = 23655,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_SW_SE_SEQ_2 = 23656,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_SW_SE_SEQ_3 = 23657,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_SW_SE_SEQ_5 = 23658,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_SW_SE_SEQ_6 = 23659,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_NE_NW_SEQ_0 = 23660,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_NE_NW_SEQ_2 = 23661,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_NE_NW_SEQ_3 = 23662,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_NE_NW_SEQ_5 = 23663,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_NE_NW_SEQ_6 = 23664,

    SPR_CLASSIC_WOODEN_RC_FLAT_CHAIN_SW_NE = SPR_CSG_BEGIN + 64979,
    SPR_CLASSIC_WOODEN_RC_FLAT_CHAIN_NW_SE = SPR_CSG_BEGIN + 64980,
    SPR_CLASSIC_WOODEN_RC_FLAT_CHAIN_NE_SW = SPR_CSG_BEGIN + 64981,
    SPR_CLASSIC_WOODEN_RC_FLAT_CHAIN_SE_NW = SPR_CSG_BEGIN + 64982,
    SPR_CLASSIC_WOODEN_RC_FLAT_SW_NE = SPR_CSG_BEGIN + 64983,
    SPR_CLASSIC_WOODEN_RC_FLAT_NW_SE = SPR_CSG_BEGIN + 64984,
    SPR_CLASSIC_WOODEN_RC_BRAKES_SW_NE = SPR_CSG_BEGIN + 64985,
    SPR_CLASSIC_WOODEN_RC_BRAKES_NW_SE = SPR_CSG_BEGIN + 64986,
    SPR_CLASSIC_WOODEN_RC_BLOCK_BRAKES_SW_NE = SPR_CSG_BEGIN + 64987,
    SPR_CLASSIC_WOODEN_RC_BLOCK_BRAKES_NW_SE = SPR_CSG_BEGIN + 64988,

    SPR_CLASSIC_WOODEN_RC_STATION_SW_NE = 23973,
    SPR_CLASSIC_WOODEN_RC_STATION_NW_SE = 23974,

    SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_RAILS_SW_NE = 24363,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_RAILS_NW_SE = 24364,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_RAILS_NE_SW = 24365,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_RAILS_SE_NW = 24366,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_RIGHT_BANK_RAILS_SW_NE = 24367,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_RIGHT_BANK_RAILS_NW_SE = 24368,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_RIGHT_BANK_RAILS_NE_SW = 24369,
    SPR_CLASSIC_WOODEN_RC_FLAT_TO_RIGHT_BANK_RAILS_SE_NW = 24370,
    SPR_CLASSIC_WOODEN_RC_LEFT_BANK_RAILS_SW_NE = 24371,
    SPR_CLASSIC_WOODEN_RC_LEFT_BANK_RAILS_NW_SE = 24372,
    SPR_CLASSIC_WOODEN_RC_LEFT_BANK_RAILS_NE_SW = 24373,
    SPR_CLASSIC_WOODEN_RC_LEFT_BANK_RAILS_SE_NW = 24374,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_LEFT_BANK_RAILS_SW_NE = 24375,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_LEFT_BANK_RAILS_NW_SE = 24376,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_LEFT_BANK_RAILS_NE_SW = 24377,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_LEFT_BANK_RAILS_SE_NW = 24378,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_RIGHT_BANK_RAILS_SW_NE = 24379,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_RIGHT_BANK_RAILS_NW_SE = 24380,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_RIGHT_BANK_RAILS_NE_SW = 24381,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_RIGHT_BANK_RAILS_SE_NW = 24382,
    SPR_CLASSIC_WOODEN_RC_LEFT_BANK_TO_25_DEG_RAILS_SW_NE = 24383,
    SPR_CLASSIC_WOODEN_RC_LEFT_BANK_TO_25_DEG_RAILS_NW_SE = 24384,
    SPR_CLASSIC_WOODEN_RC_LEFT_BANK_TO_25_DEG_RAILS_NE_SW = 24385,
    SPR_CLASSIC_WOODEN_RC_LEFT_BANK_TO_25_DEG_RAILS_SE_NW = 24386,
    SPR_CLASSIC_WOODEN_RC_RIGHT_BANK_TO_25_DEG_RAILS_SW_NE = 24387,
    SPR_CLASSIC_WOODEN_RC_RIGHT_BANK_TO_25_DEG_RAILS_NW_SE = 24388,
    SPR_CLASSIC_WOODEN_RC_RIGHT_BANK_TO_25_DEG_RAILS_NE_SW = 24389,
    SPR_CLASSIC_WOODEN_RC_RIGHT_BANK_TO_25_DEG_RAILS_SE_NW = 24390,
    SPR_CLASSIC_WOODEN_RC_RC_FLAT_TO_LEFT_BANK_RAILS_FRONT_NW_SE = 24391,
    SPR_CLASSIC_WOODEN_RC_RC_FLAT_TO_LEFT_BANK_RAILS_FRONT_SE_NW = 24392,
    SPR_CLASSIC_WOODEN_RC_RC_FLAT_TO_RIGHT_BANK_RAILS_FRONT_NE_SW = 24393,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_LEFT_BANK_RAILS_FRONT_NW_SE = 24394,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_LEFT_BANK_RAILS_FRONT_NE_SW = 24395,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_RIGHT_BANK_RAILS_FRONT_NW_SE = 24396,
    SPR_CLASSIC_WOODEN_RC_25_DEG_TO_RIGHT_BANK_RAILS_FRONT_NE_SW = 24397,
    SPR_CLASSIC_WOODEN_RC_LEFT_BANK_TO_25_DEG_RAILS_FRONT_NW_SE = 24398,
    SPR_CLASSIC_WOODEN_RC_LEFT_BANK_TO_25_DEG_RAILS_FRONT_NE_SW = 24399,
    SPR_CLASSIC_WOODEN_RC_RIGHT_BANK_TO_25_DEG_RAILS_FRONT_NW_SE = 24400,
    SPR_CLASSIC_WOODEN_RC_RIGHT_BANK_TO_25_DEG_RAILS_FRONT_NE_SW = 24401,
    SPR_CLASSIC_WOODEN_RC_RC_FLAT_TO_RIGHT_BANK_RAILS_FRONT_SW_NE = 24402,

    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SW_SE_SEQ_0 = 24501,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SW_SE_SEQ_2 = 24502,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SW_SE_SEQ_3 = 24503,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SW_SE_SEQ_5 = 24504,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SW_SE_SEQ_6 = 24505,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NW_SW_SEQ_0 = 24506,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NW_SW_SEQ_2 = 24507,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NW_SW_SEQ_3 = 24508,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NW_SW_SEQ_5 = 24509,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NW_SW_SEQ_6 = 24510,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NE_NW_SEQ_0 = 24511,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NE_NW_SEQ_2 = 24512,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NE_NW_SEQ_3 = 24513,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NE_NW_SEQ_5 = 24514,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NE_NW_SEQ_6 = 24515,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SE_NE_SEQ_0 = 24516,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SE_NE_SEQ_2 = 24517,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SE_NE_SEQ_3 = 24518,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SE_NE_SEQ_5 = 24519,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SE_NE_SEQ_6 = 24520,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_SW_SE_SEQ_0 = 24521,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_SW_SE_SEQ_2 = 24522,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_SW_SE_SEQ_3 = 24523,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_SW_SE_SEQ_5 = 24524,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_SW_SE_SEQ_6 = 24525,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_NE_NW_SEQ_0 = 24526,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_NE_NW_SEQ_2 = 24527,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_NE_NW_SEQ_3 = 24528,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_NE_NW_SEQ_5 = 24529,
    SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_NE_NW_SEQ_6 = 24530,
};

static void classic_wooden_rc_track_flat_to_left_bank(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    static constexpr const uint32_t imageIds[4][4] = {
        { SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_SW_NE, SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_RAILS_SW_NE, 0, 0 },
        { SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_NW_SE, SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_RAILS_NW_SE,
          SPR_CLASSIC_WOODEN_RC_RC_FLAT_TO_LEFT_BANK_FRONT_NW_SE,
          SPR_CLASSIC_WOODEN_RC_RC_FLAT_TO_LEFT_BANK_RAILS_FRONT_NW_SE },
        { SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_NE_SW, SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_RAILS_NE_SW, 0, 0 },
        { SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_SE_NW, SPR_CLASSIC_WOODEN_RC_FLAT_TO_LEFT_BANK_RAILS_SE_NW,
          SPR_CLASSIC_WOODEN_RC_RC_FLAT_TO_LEFT_BANK_FRONT_SE_NW,
          SPR_CLASSIC_WOODEN_RC_RC_FLAT_TO_LEFT_BANK_RAILS_FRONT_SE_NW },
    };

    wooden_rc_track_paint<true>(
        session, imageIds[direction][0], imageIds[direction][1], direction, 0, 0, 32, 25, 2, height, 0, 3, height);
    if (direction == 1 || direction == 3)
    {
        wooden_rc_track_paint<true>(
            session, imageIds[direction][2], imageIds[direction][3], direction, 0, 0, 32, 1, 9, height, 0, 26, height + 5);
    }
    wooden_a_supports_paint_setup(session, direction & 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
    paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_FLAT);
    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 32, 0x20);
}

static void classic_wooden_rc_track_flat_to_right_bank(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    static constexpr const uint32_t imageIds[4][4] = {
        { SPR_CLASSIC_WOODEN_RC_FLAT_TO_RIGHT_BANK_SW_NE, SPR_CLASSIC_WOODEN_RC_FLAT_TO_RIGHT_BANK_RAILS_SW_NE,
          SPR_CLASSIC_WOODEN_RC_RC_FLAT_TO_RIGHT_BANK_FRONT_SW_NE,
          SPR_CLASSIC_WOODEN_RC_RC_FLAT_TO_RIGHT_BANK_RAILS_FRONT_SW_NE },
        { SPR_CLASSIC_WOODEN_RC_FLAT_TO_RIGHT_BANK_NW_SE, SPR_CLASSIC_WOODEN_RC_FLAT_TO_RIGHT_BANK_RAILS_NW_SE, 0, 0 },
        { SPR_CLASSIC_WOODEN_RC_FLAT_TO_RIGHT_BANK_NE_SW, SPR_CLASSIC_WOODEN_RC_FLAT_TO_RIGHT_BANK_RAILS_NE_SW,
          SPR_CLASSIC_WOODEN_RC_RC_FLAT_TO_RIGHT_BANK_FRONT_NE_SW,
          SPR_CLASSIC_WOODEN_RC_RC_FLAT_TO_RIGHT_BANK_RAILS_FRONT_NE_SW },
        { SPR_CLASSIC_WOODEN_RC_FLAT_TO_RIGHT_BANK_SE_NW, SPR_CLASSIC_WOODEN_RC_FLAT_TO_RIGHT_BANK_RAILS_SE_NW, 0, 0 },
    };

    wooden_rc_track_paint<true>(
        session, imageIds[direction][0], imageIds[direction][1], direction, 0, 0, 32, 25, 2, height, 0, 3, height);
    if (direction == 0 || direction == 2)
    {
        wooden_rc_track_paint<true>(
            session, imageIds[direction][2], imageIds[direction][3], direction, 0, 0, 32, 1, 9, height, 0, 26, height + 5);
    }
    wooden_a_supports_paint_setup(session, direction & 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
    paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_FLAT);
    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 32, 0x20);
}

static void classic_wooden_rc_track_left_bank_to_flat(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    classic_wooden_rc_track_flat_to_right_bank(session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

static void classic_wooden_rc_track_right_bank_to_flat(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    classic_wooden_rc_track_flat_to_left_bank(session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

static void classic_wooden_rc_track_banked_right_quarter_turn_5(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    static constexpr const sprite_bb_2 imageIds[2][4][7] = {
        { {
              { SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_SW_SE_SEQ_0,
                SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SW_SE_SEQ_0,
                { 0, 0, 0 },
                { 0, 2, 0 },
                { 32, 32, 2 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_SW_SE_SEQ_2,
                SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SW_SE_SEQ_2,
                { 0, 0, 0 },
                { 0, 16, 0 },
                { 32, 16, 2 } },
              { SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_SW_SE_SEQ_3,
                SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SW_SE_SEQ_3,
                { 0, 0, 0 },
                { 0, 0, 0 },
                { 16, 16, 2 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_SW_SE_SEQ_5,
                SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SW_SE_SEQ_5,
                { 0, 0, 0 },
                { 16, 0, 0 },
                { 16, 32, 2 } },
              { SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_SW_SE_SEQ_6,
                SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SW_SE_SEQ_6,
                { 0, 0, 0 },
                { 2, 0, 0 },
                { 32, 32, 2 } },
          },
          {
              { SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_NW_SW_SEQ_0,
                SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NW_SW_SEQ_0,
                { 0, 0, 0 },
                { 2, 0, 0 },
                { 32, 32, 2 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_NW_SW_SEQ_2,
                SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NW_SW_SEQ_2,
                { 0, 0, 0 },
                { 16, 0, 0 },
                { 16, 32, 2 } },
              { SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_NW_SW_SEQ_3,
                SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NW_SW_SEQ_3,
                { 0, 0, 0 },
                { 0, 16, 0 },
                { 16, 16, 2 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_NW_SW_SEQ_5,
                SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NW_SW_SEQ_5,
                { 0, 0, 0 },
                { 0, 0, 0 },
                { 32, 16, 2 } },
              { SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_NW_SW_SEQ_6,
                SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NW_SW_SEQ_6,
                { 0, 0, 0 },
                { 0, 2, 0 },
                { 32, 27, 2 } },
          },
          {
              { SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_NE_NW_SEQ_0,
                SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NE_NW_SEQ_0,
                { 0, 0, 0 },
                { 0, 2, 0 },
                { 32, 27, 2 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_NE_NW_SEQ_2,
                SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NE_NW_SEQ_2,
                { 0, 0, 0 },
                { 0, 0, 0 },
                { 32, 16, 2 } },
              { SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_NE_NW_SEQ_3,
                SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NE_NW_SEQ_3,
                { 0, 0, 0 },
                { 16, 16, 0 },
                { 16, 16, 2 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_NE_NW_SEQ_5,
                SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NE_NW_SEQ_5,
                { 0, 0, 0 },
                { 0, 0, 0 },
                { 16, 32, 2 } },
              { SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_NE_NW_SEQ_6,
                SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_NE_NW_SEQ_6,
                { 0, 0, 0 },
                { 2, 0, 0 },
                { 27, 32, 2 } },
          },
          {
              { SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_SE_NE_SEQ_0,
                SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SE_NE_SEQ_0,
                { 0, 0, 0 },
                { 2, 0, 0 },
                { 27, 32, 2 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_SE_NE_SEQ_2,
                SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SE_NE_SEQ_2,
                { 0, 0, 0 },
                { 0, 0, 0 },
                { 16, 32, 2 } },
              { SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_SE_NE_SEQ_3,
                SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SE_NE_SEQ_3,
                { 0, 0, 0 },
                { 16, 0, 0 },
                { 16, 16, 2 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_SE_NE_SEQ_5,
                SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SE_NE_SEQ_5,
                { 0, 0, 0 },
                { 0, 16, 0 },
                { 32, 16, 2 } },
              { SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_SE_NE_SEQ_6,
                SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_SE_NE_SEQ_6,
                { 0, 0, 0 },
                { 0, 2, 0 },
                { 32, 32, 2 } },
          } },
        { {
              { SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_SW_SE_SEQ_0,
                SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_SW_SE_SEQ_0,
                { 0, 0, 0 },
                { 0, 2, 27 },
                { 32, 32, 0 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_SW_SE_SEQ_2,
                SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_SW_SE_SEQ_2,
                { 0, 0, 0 },
                { 0, 16, 27 },
                { 32, 16, 0 } },
              { SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_SW_SE_SEQ_3,
                SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_SW_SE_SEQ_3,
                { 0, 0, 0 },
                { 0, 0, 27 },
                { 16, 16, 0 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_SW_SE_SEQ_5,
                SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_SW_SE_SEQ_5,
                { 0, 0, 0 },
                { 16, 0, 27 },
                { 16, 32, 0 } },
              { SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_SW_SE_SEQ_6,
                SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_SW_SE_SEQ_6,
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
              { SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_NE_NW_SEQ_0,
                SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_NE_NW_SEQ_0,
                { 0, 0, 0 },
                { 0, 2, 27 },
                { 32, 27, 0 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_NE_NW_SEQ_2,
                SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_NE_NW_SEQ_2,
                { 0, 0, 0 },
                { 0, 0, 27 },
                { 32, 16, 0 } },
              { SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_NE_NW_SEQ_3,
                SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_NE_NW_SEQ_3,
                { 0, 0, 0 },
                { 16, 16, 27 },
                { 16, 16, 0 } },
              { 0, 0, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } },
              { SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_NE_NW_SEQ_5,
                SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_NE_NW_SEQ_5,
                { 0, 0, 0 },
                { 0, 0, 27 },
                { 16, 32, 0 } },
              { SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_FRONT_NE_NW_SEQ_6,
                SPR_CLASSIC_WOODEN_RC_BANKED_QUARTER_TURN_5_RAILS_FRONT_NE_NW_SEQ_6,
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

    wooden_rc_track_paint_bb<true>(session, &imageIds[0][direction][trackSequence], height);
    wooden_rc_track_paint_bb<true>(session, &imageIds[1][direction][trackSequence], height);
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

static void classic_wooden_rc_track_banked_left_quarter_turn_5(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    trackSequence = mapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence];
    classic_wooden_rc_track_banked_right_quarter_turn_5(
        session, rideIndex, trackSequence, (direction + 1) & 3, height, tileElement);
}

static void classic_wooden_rc_track_left_bank_to_25_deg_up(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    static constexpr const uint32_t imageIds[4][4] = {
        { SPR_CLASSIC_WOODEN_RC_LEFT_BANK_TO_25_DEG_SW_NE, SPR_CLASSIC_WOODEN_RC_LEFT_BANK_TO_25_DEG_RAILS_SW_NE, 0, 0 },
        { SPR_CLASSIC_WOODEN_RC_LEFT_BANK_TO_25_DEG_NW_SE, SPR_CLASSIC_WOODEN_RC_LEFT_BANK_TO_25_DEG_RAILS_NW_SE,
          SPR_CLASSIC_WOODEN_RC_LEFT_BANK_TO_25_DEG_FRONT_NW_SE, SPR_CLASSIC_WOODEN_RC_LEFT_BANK_TO_25_DEG_RAILS_FRONT_NW_SE },
        { SPR_CLASSIC_WOODEN_RC_LEFT_BANK_TO_25_DEG_NE_SW, SPR_CLASSIC_WOODEN_RC_LEFT_BANK_TO_25_DEG_RAILS_NE_SW,
          SPR_CLASSIC_WOODEN_RC_LEFT_BANK_TO_25_DEG_FRONT_NE_SW, SPR_CLASSIC_WOODEN_RC_LEFT_BANK_TO_25_DEG_RAILS_FRONT_NE_SW },
        { SPR_CLASSIC_WOODEN_RC_LEFT_BANK_TO_25_DEG_SE_NW, SPR_CLASSIC_WOODEN_RC_LEFT_BANK_TO_25_DEG_RAILS_SE_NW, 0, 0 },
    };

    wooden_rc_track_paint<true>(
        session, imageIds[direction][0], imageIds[direction][1], direction, 0, 0, 32, 25, 2, height, 0, 3, height);
    if (direction == 1 || direction == 2)
    {
        wooden_rc_track_paint<true>(
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

static void classic_wooden_rc_track_right_bank_to_25_deg_up(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    static constexpr const uint32_t imageIds[4][4] = {
        { SPR_CLASSIC_WOODEN_RC_RIGHT_BANK_TO_25_DEG_SW_NE, SPR_CLASSIC_WOODEN_RC_RIGHT_BANK_TO_25_DEG_RAILS_SW_NE, 0, 0 },
        { SPR_CLASSIC_WOODEN_RC_RIGHT_BANK_TO_25_DEG_NW_SE, SPR_CLASSIC_WOODEN_RC_RIGHT_BANK_TO_25_DEG_RAILS_NW_SE,
          SPR_CLASSIC_WOODEN_RC_RIGHT_BANK_TO_25_DEG_FRONT_NW_SE,
          SPR_CLASSIC_WOODEN_RC_RIGHT_BANK_TO_25_DEG_RAILS_FRONT_NW_SE },
        { SPR_CLASSIC_WOODEN_RC_RIGHT_BANK_TO_25_DEG_NE_SW, SPR_CLASSIC_WOODEN_RC_RIGHT_BANK_TO_25_DEG_RAILS_NE_SW,
          SPR_CLASSIC_WOODEN_RC_RIGHT_BANK_TO_25_DEG_FRONT_NE_SW,
          SPR_CLASSIC_WOODEN_RC_RIGHT_BANK_TO_25_DEG_RAILS_FRONT_NE_SW },
        { SPR_CLASSIC_WOODEN_RC_RIGHT_BANK_TO_25_DEG_SE_NW, SPR_CLASSIC_WOODEN_RC_RIGHT_BANK_TO_25_DEG_RAILS_SE_NW, 0, 0 },
    };

    wooden_rc_track_paint<true>(
        session, imageIds[direction][0], imageIds[direction][1], direction, 0, 0, 32, 25, 2, height, 0, 3, height);
    if (direction == 1 || direction == 2)
    {
        wooden_rc_track_paint<true>(
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

static void classic_wooden_rc_track_25_deg_up_to_left_bank(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    static constexpr const uint32_t imageIds[4][4] = {
        { SPR_CLASSIC_WOODEN_RC_25_DEG_TO_LEFT_BANK_SW_NE, SPR_CLASSIC_WOODEN_RC_25_DEG_TO_LEFT_BANK_RAILS_SW_NE, 0, 0 },
        { SPR_CLASSIC_WOODEN_RC_25_DEG_TO_LEFT_BANK_NW_SE, SPR_CLASSIC_WOODEN_RC_25_DEG_TO_LEFT_BANK_RAILS_NW_SE,
          SPR_CLASSIC_WOODEN_RC_25_DEG_TO_LEFT_BANK_FRONT_NW_SE, SPR_CLASSIC_WOODEN_RC_25_DEG_TO_LEFT_BANK_RAILS_FRONT_NW_SE },
        { SPR_CLASSIC_WOODEN_RC_25_DEG_TO_LEFT_BANK_NE_SW, SPR_CLASSIC_WOODEN_RC_25_DEG_TO_LEFT_BANK_RAILS_NE_SW,
          SPR_CLASSIC_WOODEN_RC_25_DEG_TO_LEFT_BANK_FRONT_NE_SW, SPR_CLASSIC_WOODEN_RC_25_DEG_TO_LEFT_BANK_RAILS_FRONT_NE_SW },
        { SPR_CLASSIC_WOODEN_RC_25_DEG_TO_LEFT_BANK_SE_NW, SPR_CLASSIC_WOODEN_RC_25_DEG_TO_LEFT_BANK_RAILS_SE_NW, 0, 0 },
    };

    wooden_rc_track_paint<true>(
        session, imageIds[direction][0], imageIds[direction][1], direction, 0, 0, 32, 25, 2, height, 0, 3, height);
    if (direction == 1 || direction == 2)
    {
        wooden_rc_track_paint<true>(
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

static void classic_wooden_rc_track_25_deg_up_to_right_bank(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    static constexpr const uint32_t imageIds[4][4] = {
        { SPR_CLASSIC_WOODEN_RC_25_DEG_TO_RIGHT_BANK_SW_NE, SPR_CLASSIC_WOODEN_RC_25_DEG_TO_RIGHT_BANK_RAILS_SW_NE, 0, 0 },
        { SPR_CLASSIC_WOODEN_RC_25_DEG_TO_RIGHT_BANK_NW_SE, SPR_CLASSIC_WOODEN_RC_25_DEG_TO_RIGHT_BANK_RAILS_NW_SE,
          SPR_CLASSIC_WOODEN_RC_25_DEG_TO_RIGHT_BANK_FRONT_NW_SE,
          SPR_CLASSIC_WOODEN_RC_25_DEG_TO_RIGHT_BANK_RAILS_FRONT_NW_SE },
        { SPR_CLASSIC_WOODEN_RC_25_DEG_TO_RIGHT_BANK_NE_SW, SPR_CLASSIC_WOODEN_RC_25_DEG_TO_RIGHT_BANK_RAILS_NE_SW,
          SPR_CLASSIC_WOODEN_RC_25_DEG_TO_RIGHT_BANK_FRONT_NE_SW,
          SPR_CLASSIC_WOODEN_RC_25_DEG_TO_RIGHT_BANK_RAILS_FRONT_NE_SW },
        { SPR_CLASSIC_WOODEN_RC_25_DEG_TO_RIGHT_BANK_SE_NW, SPR_CLASSIC_WOODEN_RC_25_DEG_TO_RIGHT_BANK_RAILS_SE_NW, 0, 0 },
    };

    wooden_rc_track_paint<true>(
        session, imageIds[direction][0], imageIds[direction][1], direction, 0, 0, 32, 25, 2, height, 0, 3, height);
    if (direction == 1 || direction == 2)
    {
        wooden_rc_track_paint<true>(
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

static void classic_wooden_rc_track_left_bank_to_25_deg_down(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    classic_wooden_rc_track_25_deg_up_to_right_bank(session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

static void classic_wooden_rc_track_right_bank_to_25_deg_down(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    classic_wooden_rc_track_25_deg_up_to_left_bank(session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

static void classic_wooden_rc_track_25_deg_down_to_left_bank(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    classic_wooden_rc_track_right_bank_to_25_deg_up(session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

static void classic_wooden_rc_track_25_deg_down_to_right_bank(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    classic_wooden_rc_track_left_bank_to_25_deg_up(session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

static void classic_wooden_rc_track_left_bank(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    static constexpr const uint32_t imageIds[4][2] = {
        { SPR_CLASSIC_WOODEN_RC_LEFT_BANK_SW_NE, SPR_CLASSIC_WOODEN_RC_LEFT_BANK_RAILS_SW_NE },
        { SPR_CLASSIC_WOODEN_RC_LEFT_BANK_NW_SE, SPR_CLASSIC_WOODEN_RC_LEFT_BANK_RAILS_NW_SE },
        { SPR_CLASSIC_WOODEN_RC_LEFT_BANK_NE_SW, SPR_CLASSIC_WOODEN_RC_LEFT_BANK_RAILS_NE_SW },
        { SPR_CLASSIC_WOODEN_RC_LEFT_BANK_SE_NW, SPR_CLASSIC_WOODEN_RC_LEFT_BANK_RAILS_SE_NW },
    };

    wooden_rc_track_paint<true>(
        session, imageIds[direction][0], imageIds[direction][1], direction, 0, 0, 32, 25, 2, height, 0, 3, height);
    wooden_a_supports_paint_setup(session, direction & 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
    paint_util_push_tunnel_rotated(session, direction, height, TUNNEL_SQUARE_FLAT);
    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 32, 0x20);
}

static void classic_wooden_rc_track_right_bank(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    classic_wooden_rc_track_left_bank(session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

static void classic_wooden_rc_track_left_quarter_turn_3_bank(
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23846, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24712, 0, 0, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23849, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24715, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23858, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24724, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23852, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24718, 0, 0, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23843, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24709, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23855, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24721, 0, 0, 32, 20, 0, height, 0, 6,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23845, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24711, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23848, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24714, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23857, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24723, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23851, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24717, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23842, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24708, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23854, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24720, 0, 0, 16, 16, 0, height, 16, 16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23844, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24710, 0, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23847, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24713, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23856, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24722, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23850, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24716, 0, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23841, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24707, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23853, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24719, 0, 0, 20, 32, 0, height, 6, 0,
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

static void classic_wooden_rc_track_right_quarter_turn_3_bank(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    trackSequence = mapLeftQuarterTurn3TilesToRightQuarterTurn3Tiles[trackSequence];
    classic_wooden_rc_track_left_quarter_turn_3_bank(
        session, rideIndex, trackSequence, (direction - 1) & 3, height, tileElement);
}

static void classic_wooden_rc_track_left_half_banked_helix_up_small(
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23882, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24748, 0, 0, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23885, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24751, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23894, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24760, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23888, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24754, 0, 0, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23879, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24745, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23891, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24757, 0, 0, 32, 20, 0, height, 0, 6,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23881, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24747, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23884, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24750, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23893, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24759, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23887, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24753, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23878, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24744, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23890, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24756, 0, 0, 16, 16, 0, height, 16, 16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23880, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24746, 0, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23883, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24749, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23892, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24758, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23886, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24752, 0, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23877, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24743, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23889, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24755, 0, 0, 20, 32, 0, height, 6, 0,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23879, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24745, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23891, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24757, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23882, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24748, 0, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23885, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24751, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23894, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24760, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23888, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24754, 0, 0, 20, 32, 2, height, 6, 0, height);
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23878, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24744, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23890, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24756, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 27);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23881, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24747, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23884, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24750, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23893, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24759, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23887, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24753, 0, 0, 16, 16, 2, height, 16, 0,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23877, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24743, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23889, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24755, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23880, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24746, 0, 0, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23883, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24749, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23892, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24758, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23886, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24752, 0, 0, 32, 20, 2, height, 0, 6, height);
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

static void classic_wooden_rc_track_right_half_banked_helix_up_small(
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23859, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24725, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23871, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24737, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23862, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24728, 0, 0, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23865, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24731, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23874, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24740, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23868, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24734, 0, 0, 32, 20, 2, height, 0, 6, height);
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23860, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24726, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23872, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24738, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 27);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23863, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24729, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23866, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24732, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23875, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24741, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23869, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24735, 0, 0, 16, 16, 2, height, 16, 0,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23861, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24727, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23873, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24739, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23864, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24730, 0, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23867, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24733, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23876, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24742, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23870, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24736, 0, 0, 20, 32, 2, height, 6, 0, height);
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23862, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24728, 0, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23865, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24731, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23874, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24740, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23868, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24734, 0, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23859, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24725, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23871, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24737, 0, 0, 20, 32, 0, height, 6, 0,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23863, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24729, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23866, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24732, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23875, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24741, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23869, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24735, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23860, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24726, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23872, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24738, 0, 0, 16, 16, 0, height, 16, 16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23864, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24730, 0, 0, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23867, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24733, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23876, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24742, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23870, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24736, 0, 0, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23861, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24727, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23873, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24739, 0, 0, 32, 20, 0, height, 0, 6,
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

static void classic_wooden_rc_track_left_half_banked_helix_down_small(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    if (trackSequence >= 4)
    {
        trackSequence -= 4;
        direction = (direction - 1) & 3;
    }
    trackSequence = mapLeftQuarterTurn3TilesToRightQuarterTurn3Tiles[trackSequence];
    classic_wooden_rc_track_right_half_banked_helix_up_small(
        session, rideIndex, trackSequence, (direction + 1) & 3, height, tileElement);
}

static void classic_wooden_rc_track_right_half_banked_helix_down_small(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    if (trackSequence >= 4)
    {
        trackSequence -= 4;
        direction = (direction + 1) & 3;
    }
    trackSequence = mapLeftQuarterTurn3TilesToRightQuarterTurn3Tiles[trackSequence];
    classic_wooden_rc_track_left_half_banked_helix_up_small(
        session, rideIndex, trackSequence, (direction - 1) & 3, height, tileElement);
}

static void classic_wooden_rc_track_left_half_banked_helix_up_large(
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23704, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24570, 0, 0, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23709, 0, 0, 32, 27, 2, height, 0, 2, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24575, 0, 0, 32, 27, 2, height, 0, 2, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23724, 0, 0, 32, 27, 0, height, 0, 2,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24590, 0, 0, 32, 27, 0, height, 0, 2,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23714, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24580, 0, 0, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23699, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24565, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23719, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24585, 0, 0, 32, 20, 0, height, 0, 6,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23703, 0, 0, 32, 16, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24569, 0, 0, 32, 16, 2, height, 0, 0, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23708, 0, 0, 32, 16, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24574, 0, 0, 32, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23723, 0, 0, 32, 16, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24589, 0, 0, 32, 16, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23713, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24579, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23698, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24564, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23718, 0, 0, 32, 16, 0, height, 0, 16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24584, 0, 0, 32, 16, 0, height, 0, 16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23702, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24568, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23707, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24573, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23722, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 29);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24588, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 29);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23712, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24578, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23697, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24563, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23717, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24583, 0, 0, 16, 16, 0, height, 0, 0,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23701, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24567, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23706, 0, 0, 16, 32, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24572, 0, 0, 16, 32, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23721, 0, 0, 16, 32, 0, height, 0, 0,
                        height + 33);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24587, 0, 0, 16, 32, 0, height, 0, 0,
                        height + 33);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23711, 0, 0, 16, 32, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24577, 0, 0, 16, 32, 2, height, 0, 0, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23696, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24562, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23716, 0, 0, 16, 32, 0, height, 16, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24582, 0, 0, 16, 32, 0, height, 16, 0,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23700, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24566, 0, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23705, 0, 0, 27, 32, 2, height, 2, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24571, 0, 0, 27, 32, 2, height, 2, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23720, 0, 0, 27, 32, 0, height, 2, 0,
                        height + 33);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24586, 0, 0, 27, 32, 0, height, 2, 0,
                        height + 33);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23710, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24576, 0, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23695, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24561, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23715, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24581, 0, 0, 20, 32, 0, height, 6, 0,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23699, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24565, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23719, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24585, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23704, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24570, 0, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23709, 0, 0, 27, 32, 2, height, 2, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24575, 0, 0, 27, 32, 2, height, 2, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23724, 0, 0, 27, 32, 0, height, 2, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24590, 0, 0, 27, 32, 0, height, 2, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23714, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24580, 0, 0, 20, 32, 2, height, 6, 0, height);
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23698, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24564, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23718, 0, 0, 16, 32, 0, height, 16, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24584, 0, 0, 16, 32, 0, height, 16, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23703, 0, 0, 16, 32, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24569, 0, 0, 16, 32, 2, height, 0, 0, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23708, 0, 0, 16, 32, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24574, 0, 0, 16, 32, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23723, 0, 0, 16, 32, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24589, 0, 0, 16, 32, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23713, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24579, 0, 0, 16, 32, 2, height, 16, 0,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23697, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24563, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23717, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24583, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23702, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24568, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23707, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24573, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23722, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 29);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24588, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 29);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23712, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24578, 0, 0, 16, 16, 2, height, 0, 16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23696, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24562, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23716, 0, 0, 32, 16, 0, height, 0, 16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24582, 0, 0, 32, 16, 0, height, 0, 16,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23701, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24567, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23706, 0, 0, 32, 16, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24572, 0, 0, 32, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23721, 0, 0, 32, 16, 0, height, 0, 0,
                        height + 33);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24587, 0, 0, 32, 16, 0, height, 0, 0,
                        height + 33);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23711, 0, 0, 32, 16, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24577, 0, 0, 32, 16, 2, height, 0, 0, height);
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23695, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24561, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23715, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24581, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23700, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24566, 0, 0, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23705, 0, 0, 32, 27, 2, height, 0, 2, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24571, 0, 0, 32, 27, 2, height, 0, 2, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23720, 0, 0, 32, 27, 0, height, 0, 2,
                        height + 33);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24586, 0, 0, 32, 27, 0, height, 0, 2,
                        height + 33);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23710, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24576, 0, 0, 32, 20, 2, height, 0, 6, height);
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

static void classic_wooden_rc_track_right_half_banked_helix_up_large(
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23665, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24531, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23685, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24551, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23670, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24536, 0, 0, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23675, 0, 0, 32, 27, 2, height, 0, 2, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24541, 0, 0, 32, 27, 2, height, 0, 2, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23690, 0, 0, 32, 27, 0, height, 0, 2,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24556, 0, 0, 32, 27, 0, height, 0, 2,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23680, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24546, 0, 0, 32, 20, 2, height, 0, 6, height);
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23666, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24532, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23686, 0, 0, 32, 16, 0, height, 0, 16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24552, 0, 0, 32, 16, 0, height, 0, 16,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23671, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24537, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23676, 0, 0, 32, 16, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24542, 0, 0, 32, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23691, 0, 0, 32, 16, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24557, 0, 0, 32, 16, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23681, 0, 0, 32, 16, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24547, 0, 0, 32, 16, 2, height, 0, 0, height);
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23667, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24533, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23687, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24553, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23672, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24538, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23677, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24543, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23692, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 29);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24558, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 29);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23682, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24548, 0, 0, 16, 16, 2, height, 0, 16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23668, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24534, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23688, 0, 0, 16, 32, 0, height, 16, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24554, 0, 0, 16, 32, 0, height, 16, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23673, 0, 0, 16, 32, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24539, 0, 0, 16, 32, 2, height, 0, 0, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23678, 0, 0, 16, 32, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24544, 0, 0, 16, 32, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23693, 0, 0, 16, 32, 0, height, 0, 0,
                        height + 33);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24559, 0, 0, 16, 32, 0, height, 0, 0,
                        height + 33);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23683, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24549, 0, 0, 16, 32, 2, height, 16, 0,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23669, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24535, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23689, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24555, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23674, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24540, 0, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23679, 0, 0, 27, 32, 2, height, 2, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24545, 0, 0, 27, 32, 2, height, 2, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23694, 0, 0, 27, 32, 0, height, 2, 0,
                        height + 33);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24560, 0, 0, 27, 32, 0, height, 2, 0,
                        height + 33);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23684, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24550, 0, 0, 20, 32, 2, height, 6, 0, height);
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23670, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24536, 0, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23675, 0, 0, 27, 32, 2, height, 2, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24541, 0, 0, 27, 32, 2, height, 2, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23690, 0, 0, 27, 32, 0, height, 2, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24556, 0, 0, 27, 32, 0, height, 2, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23680, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24546, 0, 0, 20, 32, 2, height, 6, 0, height);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23665, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24531, 0, 0, 20, 32, 2, height, 6, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23685, 0, 0, 20, 32, 0, height, 6, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24551, 0, 0, 20, 32, 0, height, 6, 0,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23671, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24537, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23676, 0, 0, 16, 32, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24542, 0, 0, 16, 32, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23691, 0, 0, 16, 32, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24557, 0, 0, 16, 32, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23681, 0, 0, 16, 32, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24547, 0, 0, 16, 32, 2, height, 0, 0, height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23666, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24532, 0, 0, 16, 32, 2, height, 16, 0,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23686, 0, 0, 16, 32, 0, height, 16, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24552, 0, 0, 16, 32, 0, height, 16, 0,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23672, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24538, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23677, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24543, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23692, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 29);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24558, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 29);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23682, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24548, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23667, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24533, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23687, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24553, 0, 0, 16, 16, 0, height, 0, 0,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23673, 0, 0, 32, 16, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24539, 0, 0, 32, 16, 2, height, 0, 0, height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23678, 0, 0, 32, 16, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24544, 0, 0, 32, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23693, 0, 0, 32, 16, 0, height, 0, 0,
                        height + 33);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24559, 0, 0, 32, 16, 0, height, 0, 0,
                        height + 33);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23683, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24549, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23668, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24534, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23688, 0, 0, 32, 16, 0, height, 0, 16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24554, 0, 0, 32, 16, 0, height, 0, 16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23674, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24540, 0, 0, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23679, 0, 0, 32, 27, 2, height, 0, 2, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24545, 0, 0, 32, 27, 2, height, 0, 2, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23694, 0, 0, 32, 27, 0, height, 0, 2,
                        height + 33);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24560, 0, 0, 32, 27, 0, height, 0, 2,
                        height + 33);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23684, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24550, 0, 0, 32, 20, 2, height, 0, 6, height);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23669, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24535, 0, 0, 32, 20, 2, height, 0, 6, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 23689, 0, 0, 32, 20, 0, height, 0, 6,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24555, 0, 0, 32, 20, 0, height, 0, 6,
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

static void classic_wooden_rc_track_left_half_banked_helix_down_large(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    if (trackSequence >= 7)
    {
        trackSequence -= 7;
        direction = (direction - 1) & 3;
    }
    trackSequence = mapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence];
    classic_wooden_rc_track_right_half_banked_helix_up_large(
        session, rideIndex, trackSequence, (direction + 1) & 3, height, tileElement);
}

static void classic_wooden_rc_track_right_half_banked_helix_down_large(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    if (trackSequence >= 7)
    {
        trackSequence -= 7;
        direction = (direction + 1) & 3;
    }
    trackSequence = mapLeftQuarterTurn5TilesToRightQuarterTurn5Tiles[trackSequence];
    classic_wooden_rc_track_left_half_banked_helix_up_large(
        session, rideIndex, trackSequence, (direction - 1) & 3, height, tileElement);
}

static void classic_wooden_rc_track_left_eighth_bank_to_diag(
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24185, 0, 0, 32, 32, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25051, 0, 0, 32, 32, 2, height, 0, 0, height);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24189, 0, 0, 32, 32, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25055, 0, 0, 32, 32, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24201, 0, 0, 32, 32, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25067, 0, 0, 32, 32, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24193, 0, 0, 32, 32, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25059, 0, 0, 32, 32, 2, height, 0, 0, height);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24197, 0, 0, 32, 32, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25063, 0, 0, 32, 32, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24205, 0, 0, 32, 32, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25071, 0, 0, 32, 32, 0, height, 0, 0,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24186, 0, 0, 32, 16, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25052, 0, 0, 32, 16, 2, height, 0, 0, height);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24190, 0, 0, 34, 16, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25056, 0, 0, 34, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24202, 0, 0, 32, 16, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25068, 0, 0, 32, 16, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24194, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25060, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24198, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25064, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24206, 0, 0, 32, 16, 0, height, 0, 16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25072, 0, 0, 32, 16, 0, height, 0, 16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24187, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25053, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24191, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25057, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24203, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25069, 0, 0, 16, 16, 0, height, 16, 16,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24195, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25061, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    wooden_a_supports_paint_setup(session, 5, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24199, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25065, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24207, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25073, 0, 0, 16, 16, 0, height, 0, 0,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24188, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25054, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24192, 0, 0, 16, 18, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25058, 0, 0, 16, 18, 2, height, 0, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24204, 0, 0, 16, 16, 0, height, 0, 16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25070, 0, 0, 16, 16, 0, height, 0, 16,
                        height + 27);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24196, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25062, 0, 0, 16, 16, 2, height, 0, 0, height);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24200, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25066, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24208, 0, 0, 16, 16, 0, height, 16, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25074, 0, 0, 16, 16, 0, height, 16, 0,
                        height + 27);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
    }
}

static void classic_wooden_rc_track_right_eighth_bank_to_diag(
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24161, 0, 0, 32, 32, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25027, 0, 0, 32, 32, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24177, 0, 0, 32, 32, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25043, 0, 0, 32, 32, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24165, 0, 0, 32, 32, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25031, 0, 0, 32, 32, 2, height, 0, 0, height);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24169, 0, 0, 32, 32, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25035, 0, 0, 32, 32, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24181, 0, 0, 32, 32, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25047, 0, 0, 32, 32, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24173, 0, 0, 32, 32, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25039, 0, 0, 32, 32, 2, height, 0, 0, height);
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24162, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25028, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24178, 0, 0, 32, 16, 0, height, 0, 16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25044, 0, 0, 32, 16, 0, height, 0, 16,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24166, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25032, 0, 0, 32, 16, 2, height, 0, 16,
                        height);
                    wooden_a_supports_paint_setup(session, 1, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24170, 0, 0, 34, 16, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25036, 0, 0, 34, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24182, 0, 0, 32, 16, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25048, 0, 0, 32, 16, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 0, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24174, 0, 0, 32, 16, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25040, 0, 0, 32, 16, 2, height, 0, 0, height);
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24163, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25029, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24179, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25045, 0, 0, 16, 16, 0, height, 0, 0,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 2, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24167, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25033, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    wooden_a_supports_paint_setup(session, 3, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24171, 0, 0, 28, 28, 2, height, 4, 4, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25037, 0, 0, 28, 28, 2, height, 4, 4, height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24183, 0, 0, 28, 28, 0, height, 4, 4,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25049, 0, 0, 28, 28, 0, height, 4, 4,
                        height + 27);
                    wooden_a_supports_paint_setup(session, 4, 0, height, session->TrackColours[SCHEME_SUPPORTS], nullptr);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24175, 0, 0, 16, 16, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25041, 0, 0, 16, 16, 2, height, 0, 16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24164, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25030, 0, 0, 16, 16, 2, height, 16, 0,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24180, 0, 0, 16, 16, 0, height, 16, 0,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25046, 0, 0, 16, 16, 0, height, 16, 0,
                        height + 27);
                    break;
                case 1:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24168, 0, 0, 16, 16, 2, height, 0, 0, height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25034, 0, 0, 16, 16, 2, height, 0, 0, height);
                    break;
                case 2:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24172, 0, 0, 16, 18, 2, height, 0, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25038, 0, 0, 16, 18, 2, height, 0, 16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24184, 0, 0, 16, 16, 0, height, 0, 16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25050, 0, 0, 16, 16, 0, height, 0, 16,
                        height + 27);
                    break;
                case 3:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24176, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 25042, 0, 0, 16, 16, 2, height, 16, 16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
    }
}

static void classic_wooden_rc_track_left_eighth_bank_to_orthogonal(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    trackSequence = mapLeftEighthTurnToOrthogonal[trackSequence];
    classic_wooden_rc_track_right_eighth_bank_to_diag(
        session, rideIndex, trackSequence, (direction + 2) & 3, height, tileElement);
}

static void classic_wooden_rc_track_right_eighth_bank_to_orthogonal(
    paint_session* session, ride_id_t rideIndex, uint8_t trackSequence, uint8_t direction, int32_t height,
    const TileElement* tileElement)
{
    trackSequence = mapLeftEighthTurnToOrthogonal[trackSequence];
    classic_wooden_rc_track_left_eighth_bank_to_diag(
        session, rideIndex, trackSequence, (direction + 3) & 3, height, tileElement);
}

static void classic_wooden_rc_track_diag_flat_to_left_bank(
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24080, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24946, -16, -16, 32, 32, 2, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24077, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24943, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24081, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24947, -16, -16, 32, 32, 0, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24079, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24945, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24082, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24948, -16, -16, 32, 32, 0, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24078, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24944, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
    }
}

static void classic_wooden_rc_track_diag_flat_to_right_bank(
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24086, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24952, -16, -16, 32, 32, 2, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24083, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24949, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24087, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24953, -16, -16, 32, 32, 0, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24085, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24951, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24088, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24954, -16, -16, 32, 32, 0, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24084, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24950, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
    }
}

static void classic_wooden_rc_track_diag_left_bank_to_flat(
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24084, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24950, -16, -16, 32, 32, 2, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24085, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24951, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24088, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24954, -16, -16, 32, 32, 0, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24083, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24949, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24087, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24953, -16, -16, 32, 32, 0, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24086, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24952, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
    }
}

static void classic_wooden_rc_track_diag_right_bank_to_flat(
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24078, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24944, -16, -16, 32, 32, 2, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24079, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24945, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24082, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24948, -16, -16, 32, 32, 0, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24077, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24943, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24081, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24947, -16, -16, 32, 32, 0, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24080, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24946, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
    }
}

static void classic_wooden_rc_track_diag_left_bank_to_25_deg_up(
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24104, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24970, -16, -16, 32, 32, 2, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24101, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24967, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24105, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 35);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24971, -16, -16, 32, 32, 0, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24103, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24969, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24106, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 35);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24972, -16, -16, 32, 32, 0, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24102, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24968, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
    }
}

static void classic_wooden_rc_track_diag_right_bank_to_25_deg_up(
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24110, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24976, -16, -16, 32, 32, 2, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24107, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24973, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24111, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 35);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24977, -16, -16, 32, 32, 0, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24109, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24975, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24112, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 35);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24978, -16, -16, 32, 32, 0, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24108, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24974, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
    }
}

static void classic_wooden_rc_track_diag_25_deg_up_to_left_bank(
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24092, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24958, -16, -16, 32, 32, 2, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24089, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24955, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24093, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 35);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24959, -16, -16, 32, 32, 0, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24091, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24957, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24094, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 35);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24960, -16, -16, 32, 32, 0, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24090, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24956, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 56, 0x20);
            break;
    }
}

static void classic_wooden_rc_track_diag_25_deg_up_to_right_bank(
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24098, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24964, -16, -16, 32, 32, 2, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24095, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24961, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24099, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 35);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24965, -16, -16, 32, 32, 0, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24097, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24963, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24100, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 35);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24966, -16, -16, 32, 32, 0, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24096, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24962, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 56, 0x20);
            break;
    }
}

static void classic_wooden_rc_track_diag_left_bank_to_25_deg_down(
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24096, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24962, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            break;
        case 1:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24097, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24963, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24100, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 35);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24966, -16, -16, 32, 32, 0, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24095, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24961, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24099, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 35);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24965, -16, -16, 32, 32, 0, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24098, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24964, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            break;
    }

    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 56, 0x20);
}

static void classic_wooden_rc_track_diag_right_bank_to_25_deg_down(
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24090, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24956, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            break;
        case 1:
            switch (direction)
            {
                case 0:
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24091, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24957, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24094, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 35);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24960, -16, -16, 32, 32, 0, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24089, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24955, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24093, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 35);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24959, -16, -16, 32, 32, 0, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24092, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24958, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            break;
    }

    paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
    paint_util_set_general_support_height(session, height + 56, 0x20);
}

static void classic_wooden_rc_track_diag_25_deg_down_to_left_bank(
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24108, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24974, -16, -16, 32, 32, 2, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24109, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24975, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24112, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 35);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24978, -16, -16, 32, 32, 0, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24107, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24973, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24111, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 35);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24977, -16, -16, 32, 32, 0, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24110, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24976, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
    }
}

static void classic_wooden_rc_track_diag_25_deg_down_to_right_bank(
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24102, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24968, -16, -16, 32, 32, 2, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24103, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24969, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24106, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 35);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24972, -16, -16, 32, 32, 0, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24101, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24967, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24105, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 35);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24971, -16, -16, 32, 32, 0, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24104, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24970, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 48, 0x20);
            break;
    }
}

static void classic_wooden_rc_track_diag_left_bank(
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24074, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24940, -16, -16, 32, 32, 2, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24071, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24937, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24075, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24941, -16, -16, 32, 32, 0, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24073, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24939, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24076, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24942, -16, -16, 32, 32, 0, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24072, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24938, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
    }
}

static void classic_wooden_rc_track_diag_right_bank(
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24072, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24938, -16, -16, 32, 32, 2, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24073, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24939, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24076, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24942, -16, -16, 32, 32, 0, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24071, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24937, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsParentRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24075, -16, -16, 32, 32, 0, height, -16, -16,
                        height + 27);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24941, -16, -16, 32, 32, 0, height, -16, -16,
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
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24074, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    PaintAddImageAsChildRotated(
                        session, direction, session->TrackColours[SCHEME_TRACK] | 24940, -16, -16, 32, 32, 2, height, -16, -16,
                        height);
                    break;
            }
            paint_util_set_segment_support_height(session, SEGMENTS_ALL, 0xFFFF, 0);
            paint_util_set_general_support_height(session, height + 32, 0x20);
            break;
    }
}

// Stylistically, this coaster is _very_ similar to the regular Wooden Roller Coaster.
// The only difference is to which parts the colours are applied, and the degree of the banking.
// As such, all non-banked pieces are simply drawn as regular wooden roller coaster pieces with a different paint scheme.
TRACK_PAINT_FUNCTION get_track_paint_function_classic_wooden_rc(int32_t trackType)
{
    if (!is_csg_loaded())
    {
        return get_track_paint_function_wooden_rc<true>(trackType);
    }
    
    switch (trackType)
    {
        case TrackElemType::FlatToLeftBank:
            return classic_wooden_rc_track_flat_to_left_bank;
        case TrackElemType::FlatToRightBank:
            return classic_wooden_rc_track_flat_to_right_bank;
        case TrackElemType::LeftBankToFlat:
            return classic_wooden_rc_track_left_bank_to_flat;
        case TrackElemType::RightBankToFlat:
            return classic_wooden_rc_track_right_bank_to_flat;
        case TrackElemType::BankedLeftQuarterTurn5Tiles:
            return classic_wooden_rc_track_banked_left_quarter_turn_5;
        case TrackElemType::BankedRightQuarterTurn5Tiles:
            return classic_wooden_rc_track_banked_right_quarter_turn_5;
        case TrackElemType::LeftBankToUp25:
            return classic_wooden_rc_track_left_bank_to_25_deg_up;
        case TrackElemType::RightBankToUp25:
            return classic_wooden_rc_track_right_bank_to_25_deg_up;
        case TrackElemType::Up25ToLeftBank:
            return classic_wooden_rc_track_25_deg_up_to_left_bank;
        case TrackElemType::Up25ToRightBank:
            return classic_wooden_rc_track_25_deg_up_to_right_bank;
        case TrackElemType::LeftBankToDown25:
            return classic_wooden_rc_track_left_bank_to_25_deg_down;
        case TrackElemType::RightBankToDown25:
            return classic_wooden_rc_track_right_bank_to_25_deg_down;
        case TrackElemType::Down25ToLeftBank:
            return classic_wooden_rc_track_25_deg_down_to_left_bank;
        case TrackElemType::Down25ToRightBank:
            return classic_wooden_rc_track_25_deg_down_to_right_bank;
        case TrackElemType::LeftBank:
            return classic_wooden_rc_track_left_bank;
        case TrackElemType::RightBank:
            return classic_wooden_rc_track_right_bank;
        case TrackElemType::LeftBankedQuarterTurn3Tiles:
            return classic_wooden_rc_track_left_quarter_turn_3_bank;
        case TrackElemType::RightBankedQuarterTurn3Tiles:
            return classic_wooden_rc_track_right_quarter_turn_3_bank;
        case TrackElemType::LeftHalfBankedHelixUpSmall:
            return classic_wooden_rc_track_left_half_banked_helix_up_small;
        case TrackElemType::RightHalfBankedHelixUpSmall:
            return classic_wooden_rc_track_right_half_banked_helix_up_small;
        case TrackElemType::LeftHalfBankedHelixDownSmall:
            return classic_wooden_rc_track_left_half_banked_helix_down_small;
        case TrackElemType::RightHalfBankedHelixDownSmall:
            return classic_wooden_rc_track_right_half_banked_helix_down_small;
        case TrackElemType::LeftHalfBankedHelixUpLarge:
            return classic_wooden_rc_track_left_half_banked_helix_up_large;
        case TrackElemType::RightHalfBankedHelixUpLarge:
            return classic_wooden_rc_track_right_half_banked_helix_up_large;
        case TrackElemType::LeftHalfBankedHelixDownLarge:
            return classic_wooden_rc_track_left_half_banked_helix_down_large;
        case TrackElemType::RightHalfBankedHelixDownLarge:
            return classic_wooden_rc_track_right_half_banked_helix_down_large;
        case TrackElemType::LeftEighthBankToDiag:
            return classic_wooden_rc_track_left_eighth_bank_to_diag;
        case TrackElemType::RightEighthBankToDiag:
            return classic_wooden_rc_track_right_eighth_bank_to_diag;
        case TrackElemType::LeftEighthBankToOrthogonal:
            return classic_wooden_rc_track_left_eighth_bank_to_orthogonal;
        case TrackElemType::RightEighthBankToOrthogonal:
            return classic_wooden_rc_track_right_eighth_bank_to_orthogonal;
        case TrackElemType::DiagFlatToLeftBank:
            return classic_wooden_rc_track_diag_flat_to_left_bank;
        case TrackElemType::DiagFlatToRightBank:
            return classic_wooden_rc_track_diag_flat_to_right_bank;
        case TrackElemType::DiagLeftBankToFlat:
            return classic_wooden_rc_track_diag_left_bank_to_flat;
        case TrackElemType::DiagRightBankToFlat:
            return classic_wooden_rc_track_diag_right_bank_to_flat;
        case TrackElemType::DiagLeftBankToUp25:
            return classic_wooden_rc_track_diag_left_bank_to_25_deg_up;
        case TrackElemType::DiagRightBankToUp25:
            return classic_wooden_rc_track_diag_right_bank_to_25_deg_up;
        case TrackElemType::DiagUp25ToLeftBank:
            return classic_wooden_rc_track_diag_25_deg_up_to_left_bank;
        case TrackElemType::DiagUp25ToRightBank:
            return classic_wooden_rc_track_diag_25_deg_up_to_right_bank;
        case TrackElemType::DiagLeftBankToDown25:
            return classic_wooden_rc_track_diag_left_bank_to_25_deg_down;
        case TrackElemType::DiagRightBankToDown25:
            return classic_wooden_rc_track_diag_right_bank_to_25_deg_down;
        case TrackElemType::DiagDown25ToLeftBank:
            return classic_wooden_rc_track_diag_25_deg_down_to_left_bank;
        case TrackElemType::DiagDown25ToRightBank:
            return classic_wooden_rc_track_diag_25_deg_down_to_right_bank;
        case TrackElemType::DiagLeftBank:
            return classic_wooden_rc_track_diag_left_bank;
        case TrackElemType::DiagRightBank:
            return classic_wooden_rc_track_diag_right_bank;
    }
    return get_track_paint_function_wooden_rc<true>(trackType);
}
