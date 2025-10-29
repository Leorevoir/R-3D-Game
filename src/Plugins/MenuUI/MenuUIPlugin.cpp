#include <Gwent/Plugins/ImagePlugin.hpp>
#include <Gwent/Plugins/MenuUIPlugin.hpp>

#include <R-Engine/Application.hpp>
#include <R-Engine/Core/Filepath.hpp>

#include <Gwent/Card/Cards.hpp>
#include <Gwent/States.hpp>

#include <Gwent/UI/DeckBuilder.hpp>
#include <Gwent/UI/Style.hpp>
#include <Gwent/UI/Text.hpp>

namespace {

/**
 * private
 */
// clang-format off

static inline const std::string get_card_path(const std::string &faction, const std::string_view &filename) noexcept
{
    return r::path::get("assets/cards/" + faction + "_" + std::string(filename) + ".jpg");
}

static const struct {
        const std::string content;
        const r::gwent::StatType type;
        const r::Color color;
        const f32 font_size = 24.f;
} g_text_elements[] = {
    {
        .content = "Total cards in deck",
        .type = r::gwent::StatType::TotalCountLabel,
        .color = {130, 115, 95, 255}
    },
    {
        .content = "0",
        .type = r::gwent::StatType::TotalCountValue,
        .color = {182, 142, 70, 255},
        .font_size = 28.f
    },
    {
        .content = "Number of Unit Cards",
        .type = r::gwent::StatType::UnitCountLabel,
        .color = {130, 115, 95, 255}
    },
    {
        .content = "0",
        .type = r::gwent::StatType::UnitCountValue,
        .color = {182, 142, 70, 255},
        .font_size = 28.f
    },
    {
        .content = "Special Cards",
        .type = r::gwent::StatType::SpecialCountLabel,
        .color = {130, 115, 95, 255}
    },
    {
        .content = "0",
        .type = r::gwent::StatType::SpecialCountValue,
        .color = {182, 142, 70, 255},
        .font_size = 28.f
    },
    {
        .content = "Total Unit Card Strength",
        .type = r::gwent::StatType::StrengthCountLabel,
        .color = {130, 115, 95, 255}
    },
    {
        .content = "0",
        .type = r::gwent::StatType::StrengthCountValue,
        .color = {182, 142, 70, 255},
        .font_size = 28.f
    },
    {
        .content = "Hero Cards",
        .type = r::gwent::StatType::HeroCountLabel,
        .color = {130, 115, 95, 255}
    },
    {
        .content = "0", 
        .type = r::gwent::StatType::HeroCountValue,
        .color = {182, 142, 70, 255},
        .font_size = 28.f
    },
    {
        .content = "Start Game",
        .type = r::gwent::StatType::StartGameButton,
        .color = {200, 180, 100, 255},
        .font_size = 42.f
    }
};

template<typename CardT>
static inline void __spawn_all_cards_impl(r::ecs::Commands &commands, CardT cards, const std::string &faction)
{
    for (const auto &card_data : cards) {

        if (card_data->row == r::gwent::Row::Leader) {
            continue;
        }

        commands.spawn(
            r::gwent::Image{
                .path = get_card_path(faction, card_data->filename)
            },
            r::gwent::Style{
                .position = {0, 0}, .size = {1, 1}
            },
            r::gwent::GwentCard{
                .id = card_data->id
            },
            r::gwent::CardPanel{
                .current_panel = r::gwent::CardPanel::Panel::AVAILABLE
            },
            r::gwent::DeckBuilderUI{}
        );
    }
}

/**
 * systems
 */

/**
 * startup
 */

static void startup_spawn_all_cards(r::ecs::Commands &commands)
{
    __spawn_all_cards_impl<decltype(r::gwent::g_special_cards)>(commands, r::gwent::g_special_cards, "special");
    __spawn_all_cards_impl<decltype(r::gwent::g_weather_cards)>(commands, r::gwent::g_weather_cards, "weather");
    __spawn_all_cards_impl<decltype(r::gwent::g_neutral_cards)>(commands, r::gwent::g_neutral_cards, "neutral");
    __spawn_all_cards_impl<decltype(r::gwent::g_realms_cards)>(commands, r::gwent::g_realms_cards, "realms");
}

static void startup_spawn_all_text(r::ecs::Commands &commands)
{
    f32 y_offset = -100.f;

    for (const auto &text_data : g_text_elements) {
        commands.spawn(
            r::gwent::Text{
                .content = text_data.content
            },
            r::gwent::Style{
                .color = text_data.color,
                .font_size = text_data.font_size
            },
            r::gwent::StatText{
                .type = text_data.type
            },
            r::gwent::TextLayout{
                .pivot = { 0.5f, 0.0f },
                .relative_position = { 0.5f, 0.5f },
                .offset = { 0.f, y_offset }
            },
            r::gwent::DeckBuilderUI{}
        );
        y_offset += text_data.font_size + 10.f;
    }
}


}// namespace

/**
 * update
 */

void menu_ui_plugin_update_systems(r::Application &app);

/**
* public
*/

void r::gwent::MenuUIPlugin::build(r::Application &app)
{
    app
        .add_events<r::gwent::CardPanelChangedEvent>()
        .insert_resource(r::gwent::DeckBuilderState{})
        .insert_resource(r::gwent::DeckStats{})
        .add_systems<startup_spawn_all_cards, startup_spawn_all_text>(r::Schedule::STARTUP);

    menu_ui_plugin_update_systems(app);
}
