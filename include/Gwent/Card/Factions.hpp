#pragma once

#include <Gwent/Card/Decks.hpp>

#include <array>
#include <string_view>
#include <utility>

// clang-format off

namespace r {

namespace gwent {

struct FactionInfo final {
    const std::string_view name;
    const std::string_view description;
};

static constexpr std::array<std::pair<DeckFaction, FactionInfo>, 5> g_factions_map
{{
    {
        DeckFaction::Realms,
        {
            .name = "Northern Realms",
            .description = "Draw a card from your deck whenever you win a round."
        }
    },
    {
        DeckFaction::Nilfgaard,
        {
            .name = "Nilfgaardian Empire",
            .description = "Wins any round that ends in a draw."
        }
    },
    {
        DeckFaction::Monsters,
        {
            .name = "Monsters",
            .description = "Keeps a random Unit Card out after each round."
        }
    },
    {
        DeckFaction::Scoiatael,
        {
            .name = "Scoia'tael",
            .description = "Decides who takes first turn."
        }
    },
    {
        DeckFaction::Skellige,
        {
            .name = "Skellige",
            .description = "2 random cards from the graveyard are placed on the battlefield at the start of the third round."
        }
    }
}};

static constexpr FactionInfo find_faction_info(const DeckFaction faction) noexcept
{
    for (const auto &pair : g_factions_map) {
        if (pair.first == faction) {
            return pair.second;
        }
    }
    return FactionInfo{};
}

} // namespace gwent

} // namespace r
