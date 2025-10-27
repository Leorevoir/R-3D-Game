#pragma once

#include <array>
#include <string_view>

// clang-format off

namespace r {

namespace gwent {

struct AbilityInfo final {
    const std::string_view name;
    const std::string_view description;
};

static constexpr std::array<std::pair<std::string_view, AbilityInfo>, 44> g_abilities_map {{
    {
        "clear",
        {
            .name = "Clear Weather",
            .description = "Removes all Weather Cards (Biting Frost, Impenetrable Fog and Torrential Rain) effects."
        }
    },
    {
        "frost",
        {
            .name = "Biting Frost",
            .description = "Sets the strength of all Close Combat cards to 1 for both players."
        }
    },
    {
        "fog",
        {
            .name = "Impenetrable Fog",
            .description = "Sets the strength of all Ranged Combat cards to 1 for both players."
        }
    },
    {
        "rain",
        {
            .name = "Torrential Rain",
            .description = "Sets the strength of all Siege Combat cards to 1 for both players."
        }
    },
    {
        "storm",
        {
            .name = "Skellige Storm",
            .description = "Reduces the Strength of all Range and Siege Units to 1."
        }
    },
    {
        "hero",
        {
            .name = "Hero",
            .description = "Not affected by any Special Cards or abilities."
        }
    },
    {
        "decoy",
        {
            .name = "Decoy",
            .description = "Swap with a card on the battlefield to return it to your hand."
        }
    },
    {
        "horn",
        {
            .name = "Commander's Horn",
            .description = "Doubles the strength of all unit cards in that row. Limited to 1 per row."
        }
    },
    {
        "mardroeme",
        {
            .name = "Mardroeme",
            .description = "Triggers transformation of all Berserker cards on the same row."
        }
    },
    {
        "berserker",
        {
            .name = "Berserker",
            .description = "Transforms into a bear when a Mardroeme card is on its row."
        }
    },
    {
        "scorch",
        {
            .name = "Scorch",
            .description = "Discard after playing. Kills the strongest card(s) on the battlefield."
        }
    },
    {
        "scorch_c",
        {
            .name = "Scorch - Close Combat",
            .description = "Destroy your enemy's strongest Close Combat unit(s) if the combined strength of all his or her Close Combat units is 10 or more."
        }
    },
    {
        "scorch_r",
        {
            .name = "Scorch - Ranged",
            .description = "Destroy your enemy's strongest Ranged Combat unit(s) if the combined strength of all his or her Ranged Combat units is 10 or more."
        }
    },
    {
        "scorch_s",
        {
            .name = "Scorch - Siege",
            .description = "Destroys your enemy's strongest Siege Combat unit(s) if the combined strength of all his or her Siege Combat units is 10 or more."
        }
    },
    {
        "agile",
        {
            .name = "Agile",
            .description = "Can be placed in either the Close Combat or the Ranged Combat row. Cannot be moved once placed."
        }
    },
    {
        "muster",
        {
            .name = "Muster",
            .description = "Find any cards with the same name in your deck and play them instantly."
        }
    },
    {
        "spy",
        {
            .name = "Spy",
            .description = "Place on your opponent's battlefield (counts towards your opponent's total) and draw 2 cards from your deck."
        }
    },
    {
        "medic",
        {
            .name = "Medic",
            .description = "Choose one card from your discard pile and play it instantly (no Heroes or Special Cards)."
        }
    },
    {
        "morale",
        {
            .name = "Morale",
            .description = "Adds +1 to all units in the row (excluding itself)."
        }
    },
    {
        "bond",
        {
            .name = "Tight Bond",
            .description = "Place next to a card with the same name to double the strength of both cards."
        }
    },
    {
        "avenger",
        {
            .name = "Avenger",
            .description = "When this card is removed from the battlefield, it summons a powerful new Unit Card to take its place."
        }
    },
    {
        "avenger_kambi",
        {
            .name = "Avenger",
            .description = "When this card is removed from the battlefield, it summons a powerful new Unit Card to take its place."
        }
    },
    {
        "foltest_king",
        {
            .name = "Foltest - King",
            .description = "Pick an Impenetrable Fog card from your deck and play it instantly."
        }
    },
    {
        "foltest_lord",
        {
            .name = "Foltest - Lord",
            .description = "Clear any weather effects (resulting from Biting Frost, Torrential Rain or Impenetrable Fog cards) in play."
        }
    },
    {
        "foltest_siegemaster",
        {
            .name = "Foltest - Siegemaster",
            .description = "Doubles the strength of all your Siege units (unless a Commander's Horn is also present on that row)."
        }
    },
    {
        "foltest_steelforged",
        {
            .name = "Foltest - Steelforged",
            .description = "Destroy your enemy's strongest Siege unit(s) if the combined strength of all his or her Siege units is 10 or more."
        }
    },
    {
        "foltest_son",
        {
            .name = "Foltest - Son",
            .description = "Destroy your enemy's strongest Ranged Combat unit(s) if the combined strength of all his or her Ranged Combat units is 10 or more."
        }
    },
    {
        "emhyr_imperial",
        {
            .name = "Emhyr - Imperial",
            .description = "Pick a Torrential Rain card from your deck and play it instantly."
        }
    },
    {
        "emhyr_emperor",
        {
            .name = "Emhyr - Emperor",
            .description = "Look at 3 random cards from your opponent's hand."
        }
    },
    {
        "emhyr_whiteflame",
        {
            .name = "Emhyr - White Flame",
            .description = "Cancel your opponent's Leader Ability."
        }
    },
    {
        "emhyr_relentless",
        {
            .name = "Emhyr - Relentless",
            .description = "Draw a card from your opponent's discard pile."
        }
    },
    {
        "emhyr_invader",
        {
            .name = "Emhyr - Invader",
            .description = "Abilities that restore a unit to the battlefield restore a randomly-chosen unit. Affects both players."
        }
    },
    {
        "eredin_commander",
        {
            .name = "Eredin - Commander",
            .description = "Double the strength of all your Close Combat units (unless a Commander's horn is also present on that row)."
        }
    },
    {
        "eredin_bringer_of_death",
        {
            .name = "Eredin : Bringer of Death",
            .description = "Restore a card from your discard pile to your hand."
        }
    },
    {
        "eredin_destroyer",
        {
            .name = "Eredin - Destroyer",
            .description = "Discard 2 card and draw 1 card of your choice from your deck."
        }
    },
    {
        "eredin_king",
        {
            .name = "Eredin - King",
            .description = "Pick any weather card from your deck and play it instantly."
        }
    },
    {
        "eredin_treacherous",
        {
            .name = "Eredin - Treacherous",
            .description = "Doubles the strength of all spy cards (affects both players)."
        }
    },
    {
        "francesca_queen",
        {
            .name = "Francesca - Queen",
            .description = "Destroy your enemy's strongest Close Combat unit(s) if the combined strength of all his or her Close Combat units is 10 or more."
        }
    },
    {
        "francesca_beautiful",
        {
            .name = "Francesca - Beautiful",
            .description = "Doubles the strength of all your Ranged Combat units (unless a Commander's Horn is also present on that row)."
        }
    },
    {
        "francesca_daisy",
        {
            .name = "Francesca - Daisy",
            .description = "Draw an extra card at the beginning of the battle."
        }
    },
    {
        "francesca_pureblood",
        {
            .name = "Francesca - Pureblood",
            .description = "Pick a Biting Frost card from your deck and play it instantly."
        }
    },
    {
        "francesca_hope",
        {
            .name = "Francesca - Hope",
            .description = "Move agile units to whichever valid row maximizes their strength (don't move units already in optimal row)."
        }
    },
    {
        "crach_an_craite",
        {
            .name = "Crach an Craite",
            .description = "Shuffle all cards from each player's graveyard back into their decks."
        }
    },
    {
        "king_bran",
        {
            .name = "King Bran",
            .description = "Units only lose half their Strength in bad weather conditions."
        }
    }
}};

} // namespace gwent

} // namespace r
