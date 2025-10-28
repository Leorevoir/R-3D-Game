#pragma once

#include <R-Engine/ECS/Entity.hpp>
#include <R-Engine/Types.hpp>

namespace r {

namespace gwent {

struct Card;

struct GwentCard final {
        u32 id;
};

struct CardPanel {

        enum class Panel {
            AVAILABLE,///< left
            SELECTED  ///< right
        };

        Panel current_panel = Panel::AVAILABLE;
};

struct CardPanelChangedEvent {
        r::ecs::Entity card_entity;
        CardPanel::Panel from;
        CardPanel::Panel to;
};

struct DeckBuilderState final {

        struct PanelScroll {
                f32 target_offset = 0.f;
                f32 current_offset = 0.f;
                f32 scroll_speed = 15.f;
        };

        PanelScroll available_panel;
        PanelScroll selected_panel;
};

struct DeckStats {
        u32 total_cards = 0;
        u32 unit_cards = 0;
        u32 special_cards = 0;
        u32 hero_cards = 0;
        u32 strength = 0;
};

enum class StatType {
    TotalCountValue,
    UnitCountValue,
    SpecialCountValue,
    HeroCountValue,
    TotalCountLabel,
    UnitCountLabel,
    SpecialCountLabel,
    HeroCountLabel,
    StartGameButton,
    StrengthCountLabel,
    StrengthCountValue
};

struct StatText {
        StatType type;
};

void apply_card_stats(const Card &card_data, DeckStats &stats, const bool is_adding) noexcept;

}// namespace gwent

}// namespace r
