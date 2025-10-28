#include <Gwent/Plugins/ImagePlugin.hpp>
#include <Gwent/Plugins/MenuUIPlugin.hpp>
#include <Gwent/Plugins/WindowResizePlugin.hpp>

#include <R-Engine/Application.hpp>
#include <R-Engine/Core/Filepath.hpp>
#include <R-Engine/ECS/Query.hpp>

#include <Gwent/Card/Cards.hpp>

namespace {

/**
 * private
 */
// clang-format off

static constexpr f32 g_card_width_relative = 0.12f;
static constexpr f32 g_card_aspect_ratio = 775.f / 410.f;
static constexpr u8 g_cards_per_row = 3;
static constexpr f32 g_padding_relative = 0.01f;
static constexpr r::Vec2f g_initial_offset_relative = {0.05f, 0.05f};

static inline const std::string get_card_path(const std::string &faction, const std::string_view &filename) noexcept
{
    return r::path::get("assets/cards/" + faction + "_" + std::string(filename) + ".jpg");
}

/**
 * systems
 */

static void startup_load_cards_menu(r::ecs::Commands &commands, r::ecs::Res<r::gwent::WindowSize> window_size)
{
    const f32 card_width = window_size.ptr->current.x * g_card_width_relative;
    const f32 card_height = card_width * g_card_aspect_ratio;
    const f32 padding = window_size.ptr->current.x * g_padding_relative;
    u32 card_index = 0;

    for (const auto &card_data : r::gwent::g_realms_cards) {

        if (card_data->row == r::gwent::Row::Leader) {
            continue;
        }
        
        const u8 row = card_index / g_cards_per_row;
        const u8 col = card_index % g_cards_per_row;

        const r::Vec2f position = {
            window_size.ptr->current.x * g_initial_offset_relative.x + col * (card_width + padding),
            window_size.ptr->current.y * g_initial_offset_relative.y + row * (card_height + padding)
        };

        commands.spawn(
            r::gwent::Image{
                .path = get_card_path("realms", card_data->filename)
            },
            r::gwent::Style{
                .position = position,
                .size     = {card_width, card_height}
            }
        );
        
        ++card_index;
    }
}

static void update_card_styles(r::ecs::Query<r::ecs::Ref<r::gwent::Style>> &query, r::ecs::Res<r::gwent::WindowSize> window_size) noexcept
{
    const f32 card_width = window_size.ptr->current.x * g_card_width_relative;
    const f32 card_height = card_width * g_card_aspect_ratio;
    const f32 padding = window_size.ptr->current.x * g_padding_relative;
    u32 card_index = 0;

    for (auto [style] : query) {
        
        const u8 row = card_index / g_cards_per_row;
        const u8 col = card_index % g_cards_per_row;
        const r::gwent::Style n_style = {
            .position = {
                window_size.ptr->current.x * g_initial_offset_relative.x + col * (card_width + padding),
                window_size.ptr->current.y * g_initial_offset_relative.y + row * (card_height + padding)
            },
            .size = {
                card_width, card_height
            }
        };

        *(style.ptr) = n_style;

        ++card_index;
        if (card_index >= r::gwent::g_realms_cards.size()) {
            break;
        }
    }
}

}// namespace

/**
* public
*/

void r::gwent::MenuUIPlugin::build(r::Application &app)
{
    app.add_systems<startup_load_cards_menu>(r::Schedule::STARTUP)
       .add_systems<update_card_styles>(r::Schedule::UPDATE);
}
