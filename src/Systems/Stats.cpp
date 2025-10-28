#include <Gwent/Card/Cards.hpp>
#include <Gwent/UI/DeckBuilder.hpp>

/**
* private
*/

/**
* public
*/

void r::gwent::apply_card_stats(const Card &card_data, DeckStats &stats, const bool is_adding) noexcept
{
    const i32 modifier = is_adding ? 1 : -1;

    stats.total_cards += modifier;
    stats.strength += (card_data.strength * modifier);

    if (card_data.deck == r::gwent::DeckFaction::Special) {
        stats.special_cards += modifier;
    } else {
        stats.unit_cards += modifier;
    }

    if (card_data.ability.find("hero") != std::string_view::npos) {
        stats.hero_cards += modifier;
    }
}
