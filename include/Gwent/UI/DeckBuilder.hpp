#pragma once

#include <R-Engine/Types.hpp>

namespace r {

namespace gwent {

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

struct DeckBuilderState final {

        struct PanelScroll {
                f32 target_offset = 0.f;
                f32 current_offset = 0.f;
                f32 scroll_speed = 15.f;
        };

        PanelScroll available_panel;
        PanelScroll selected_panel;
};

enum class StatType {
    TotalCountValue,
    UnitCountValue,
    SpecialCountValue,
    HeroCountValue,
    TotalCountLabel,
    UnitCountLabel,
    SpecialCountLabel,
    HeroCountLabel
};

struct StatText {
        StatType type;
};

}// namespace gwent

}// namespace r
