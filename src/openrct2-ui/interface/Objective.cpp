/*****************************************************************************
 * Copyright (c) 2014-2026 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "Objective.h"

#include "openrct2/localisation/Language.h"

#include <cstdint>
#include <openrct2/localisation/Formatter.h>
#include <openrct2/localisation/Formatting.h>
#include <openrct2/localisation/Localisation.Date.h>
#include <openrct2/ride/Ride.h>
#include <openrct2/ride/RideData.h>
#include <openrct2/scenario/ScenarioObjective.h>

namespace OpenRCT2::Ui
{
    static constexpr StringId kObjectiveNames[] = {
        STR_OBJECTIVE_NONE,
        STR_OBJECTIVE_GUESTS_BY,
        STR_OBJECTIVE_PARK_VALUE_BY,
        STR_OBJECTIVE_HAVE_FUN,
        STR_OBJECTIVE_BUILD_THE_BEST,
        STR_OBJECTIVE_10_ROLLERCOASTERS,
        STR_OBJECTIVE_GUESTS_AND_RATING,
        STR_OBJECTIVE_MONTHLY_RIDE_INCOME,
        STR_OBJECTIVE_10_ROLLERCOASTERS_LENGTH,
        STR_OBJECTIVE_FINISH_5_ROLLERCOASTERS,
        STR_OBJECTIVE_REPLAY_LOAN_AND_PARK_VALUE,
        STR_OBJECTIVE_MONTHLY_FOOD_INCOME,
    };

    u8string formatObjective(const Scenario::Objective& objective)
    {
        auto baseStringId = kObjectiveNames[EnumValue(objective.Type)];

        switch (objective.Type)
        {
            case Scenario::ObjectiveType::none:
            {
                return LanguageGetString(baseStringId);
            }
            case Scenario::ObjectiveType::guestsBy:
            {
                return FormatStringID(
                    baseStringId, static_cast<int32_t>(objective.NumGuests),
                    static_cast<int16_t>(DateGetTotalMonths(MONTH_OCTOBER, objective.Year)));
            }
            case Scenario::ObjectiveType::parkValueBy:
            {
                return FormatStringID(
                    baseStringId, objective.Currency, static_cast<int16_t>(DateGetTotalMonths(MONTH_OCTOBER, objective.Year)));
            }
            case Scenario::ObjectiveType::haveFun:
            {
                return LanguageGetString(baseStringId);
            }
            case Scenario::ObjectiveType::buildTheBest:
            {
                StringId rideTypeString = kStringIdNone;
                auto rideTypeId = objective.RideId;
                if (rideTypeId != kRideTypeNull && rideTypeId < RIDE_TYPE_COUNT)
                {
                    rideTypeString = GetRideTypeDescriptor(rideTypeId).Naming.Name;
                }
                return FormatStringID(baseStringId, rideTypeString);
            }
            case Scenario::ObjectiveType::tenRollercoasters:
            {
                return LanguageGetString(baseStringId);
            }
            case Scenario::ObjectiveType::guestsAndRating:
            {
                return FormatStringID(baseStringId, static_cast<int32_t>(objective.NumGuests));
            }
            case Scenario::ObjectiveType::monthlyRideIncome:
            {
                return FormatStringID(baseStringId, objective.Currency);
            }
            case Scenario::ObjectiveType::tenRollercoastersLength:
            {
                return FormatStringID(baseStringId, static_cast<int16_t>(objective.MinimumLength));
            }
            case Scenario::ObjectiveType::finishFiveRollercoasters:
            {
                return FormatStringID(baseStringId, static_cast<int32_t>(objective.MinimumExcitement));
            }
            case Scenario::ObjectiveType::repayLoanAndParkValue:
            {
                return FormatStringID(baseStringId, objective.Currency);
            }
            case Scenario::ObjectiveType::monthlyFoodIncome:
            {
                return FormatStringID(baseStringId, objective.Currency);
            }
            case Scenario::ObjectiveType::count:
            {
                return {};
            }
        }
        
        assert(false);
        return {};
    }
} // namespace OpenRCT2::Ui
