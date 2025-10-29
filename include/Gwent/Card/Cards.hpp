#pragma once

#include <R-Engine/Types.hpp>

#include <Gwent/Card/Decks.hpp>
#include <Gwent/Card/Rows.hpp>

#include <array>
#include <string_view>

// clang-format off

namespace r {

namespace gwent {

struct Realms;

struct Card final {
    const std::string_view name;
    const u32 id;
    const DeckFaction deck;
    const Row row;
    const i32 strength;
    const std::string_view ability;
    const std::string_view filename;
    const u32 count;
};

static constexpr std::array<Card, 214> g_cards_map
{
    Card{
        .name = "Mysterious Elf",
        .id = 142,
        .deck = DeckFaction::Neutral,
        .row = Row::Close,
        .strength = 0,
        .ability = "hero spy",
        .filename = "mysterious_elf",
        .count = 1
    },
    Card{
        .name = "Decoy",
        .id = 1,
        .deck = DeckFaction::Special,
        .row = Row::None,
        .strength = 0,
        .ability = "decoy",
        .filename = "decoy",
        .count = 3
    },
    Card{
        .name = "Biting Frost",
        .id = 4,
        .deck = DeckFaction::Weather,
        .row = Row::None,
        .strength = 0,
        .ability = "frost",
        .filename = "frost",
        .count = 3
    },
    Card{
        .name = "Cirilla Fiona Elen Riannon",
        .id = 139,
        .deck = DeckFaction::Neutral,
        .row = Row::Close,
        .strength = 15,
        .ability = "hero",
        .filename = "ciri",
        .count = 1
    },
    Card{
        .name = "Clear Weather",
        .id = 7,
        .deck = DeckFaction::Weather,
        .row = Row::None,
        .strength = 0,
        .ability = "clear",
        .filename = "clear",
        .count = 2
    },
    Card{
        .name = "Commander \'s Horn",
        .id = 2,
        .deck = DeckFaction::Special,
        .row = Row::None,
        .strength = 0,
        .ability = "horn",
        .filename = "horn",
        .count = 3
    },
    Card{
        .name = "Dandelion",
        .id = 11,
        .deck = DeckFaction::Neutral,
        .row = Row::Close,
        .strength = 2,
        .ability = "horn",
        .filename = "dandelion",
        .count = 1
    },
    Card{
        .name = "Emiel Regis Rohellec Terzieff",
        .id = 0,
        .deck = DeckFaction::Neutral,
        .row = Row::Close,
        .strength = 5,
        .ability = "",
        .filename = "emiel",
        .count = 1
    },
    Card{
        .name = "Geralt of Rivia",
        .id = 138,
        .deck = DeckFaction::Neutral,
        .row = Row::Close,
        .strength = 15,
        .ability = "hero",
        .filename = "geralt",
        .count = 1
    },
    Card{
        .name = "Impenetrable Fog",
        .id = 5,
        .deck = DeckFaction::Weather,
        .row = Row::None,
        .strength = 0,
        .ability = "fog",
        .filename = "fog",
        .count = 3
    },
    Card{
        .name = "Scorch",
        .id = 3,
        .deck = DeckFaction::Special,
        .row = Row::None,
        .strength = 0,
        .ability = "scorch",
        .filename = "scorch",
        .count = 3
    },
    Card{
        .name = "Torrential Rain",
        .id = 6,
        .deck = DeckFaction::Weather,
        .row = Row::None,
        .strength = 0,
        .ability = "rain",
        .filename = "rain",
        .count = 2
    },
    Card{
        .name = "Triss Merigold",
        .id = 141,
        .deck = DeckFaction::Neutral,
        .row = Row::Close,
        .strength = 7,
        .ability = "hero",
        .filename = "triss",
        .count = 1
    },
    Card{
        .name = "Vesemir",
        .id = 9,
        .deck = DeckFaction::Neutral,
        .row = Row::Close,
        .strength = 6,
        .ability = "",
        .filename = "vesemir",
        .count = 1
    },
    Card{
        .name = "Villentretenmerth",
        .id = 8,
        .deck = DeckFaction::Neutral,
        .row = Row::Close,
        .strength = 7,
        .ability = "scorch_c",
        .filename = "villen",
        .count = 1
    },
    Card{
        .name = "Yennefer of Vengerberg",
        .id = 140,
        .deck = DeckFaction::Neutral,
        .row = Row::Ranged,
        .strength = 7,
        .ability = "hero medic",
        .filename = "yennefer",
        .count = 1
    },
    Card{
        .name = "Zoltan Chivay",
        .id = 10,
        .deck = DeckFaction::Neutral,
        .row = Row::Close,
        .strength = 5,
        .ability = "",
        .filename = "zoltan",
        .count = 1
    },
    Card{
        .name = "Olgierd von Everec",
        .id = 0,
        .deck = DeckFaction::Neutral,
        .row = Row::Agile,
        .strength = 6,
        .ability = "morale",
        .filename = "olgierd",
        .count = 1
    },
    Card{
        .name = "Gaunter O \'Dimm",
        .id = 0,
        .deck = DeckFaction::Neutral,
        .row = Row::Siege,
        .strength = 2,
        .ability = "muster",
        .filename = "gaunter_odimm",
        .count = 1
    },
    Card{
        .name = "Gaunter O \'Dimm - Darkness",
        .id = 0,
        .deck = DeckFaction::Neutral,
        .row = Row::Ranged,
        .strength = 4,
        .ability = "muster",
        .filename = "gaunter_odimm_darkness",
        .count = 3
    },
    Card{
        .name = "Cow",
        .id = 0,
        .deck = DeckFaction::Neutral,
        .row = Row::Ranged,
        .strength = 0,
        .ability = "avenger",
        .filename = "cow",
        .count = 1
    },
    Card{
        .name = "Bovine Defense Force",
        .id = 0,
        .deck = DeckFaction::Neutral,
        .row = Row::Close,
        .strength = 8,
        .ability = "",
        .filename = "chort",
        .count = 0
    },
    Card{
        .name = "Foltest - King of Temeria",
        .id = 5,
        .deck = DeckFaction::Realms,
        .row = Row::Leader,
        .strength = 0,
        .ability = "foltest_king",
        .filename = "foltest_silver",
        .count = 1
    },
    Card{
        .name = "Foltest - Lord Commander of the North",
        .id = 8,
        .deck = DeckFaction::Realms,
        .row = Row::Leader,
        .strength = 0,
        .ability = "foltest_lord",
        .filename = "foltest_gold",
        .count = 1
    },
    Card{
        .name = "Foltest - The Siegemaster",
        .id = 6,
        .deck = DeckFaction::Realms,
        .row = Row::Leader,
        .strength = 0,
        .ability = "foltest_siegemaster",
        .filename = "foltest_copper",
        .count = 1
    },
    Card{
        .name = "Foltest - The Steel-Forged",
        .id = 7,
        .deck = DeckFaction::Realms,
        .row = Row::Leader,
        .strength = 0,
        .ability = "foltest_steelforged",
        .filename = "foltest_bronze",
        .count = 1
    },
    Card{
        .name = "Foltest - Son of Medell",
        .id = 0,
        .deck = DeckFaction::Realms,
        .row = Row::Leader,
        .strength = 0,
        .ability = "foltest_son",
        .filename = "foltest_son_of_medell",
        .count = 1
    },
    Card{
        .name = "Ballista",
        .id = 79,
        .deck = DeckFaction::Realms,
        .row = Row::Siege,
        .strength = 6,
        .ability = "",
        .filename = "ballista",
        .count = 1
    },
    Card{
        .name = "Blue Stripes Commando",
        .id = 92,
        .deck = DeckFaction::Realms,
        .row = Row::Close,
        .strength = 4,
        .ability = "bond",
        .filename = "blue_stripes",
        .count = 3
    },
    Card{
        .name = "Catapult",
        .id = 75,
        .deck = DeckFaction::Realms,
        .row = Row::Siege,
        .strength = 8,
        .ability = "bond",
        .filename = "catapult_1",
        .count = 2
    },
    Card{
        .name = "Crinfrid Reavers Dragon Hunter",
        .id = 87,
        .deck = DeckFaction::Realms,
        .row = Row::Ranged,
        .strength = 5,
        .ability = "bond",
        .filename = "crinfrid",
        .count = 3
    },
    Card{
        .name = "Dethmold",
        .id = 76,
        .deck = DeckFaction::Realms,
        .row = Row::Ranged,
        .strength = 6,
        .ability = "",
        .filename = "dethmold",
        .count = 1
    },
    Card{
        .name = "Dun Banner Medic",
        .id = 88,
        .deck = DeckFaction::Realms,
        .row = Row::Siege,
        .strength = 5,
        .ability = "medic",
        .filename = "banner_nurse",
        .count = 1
    },
    Card{
        .name = "Esterad Thyssen",
        .id = 11,
        .deck = DeckFaction::Realms,
        .row = Row::Close,
        .strength = 10,
        .ability = "hero",
        .filename = "esterad",
        .count = 1
    },
    Card{
        .name = "John Natalis",
        .id = 10,
        .deck = DeckFaction::Realms,
        .row = Row::Close,
        .strength = 10,
        .ability = "hero",
        .filename = "natalis",
        .count = 1
    },
    Card{
        .name = "Kaedweni Siege Expert",
        .id = 98,
        .deck = DeckFaction::Realms,
        .row = Row::Siege,
        .strength = 1,
        .ability = "morale",
        .filename = "kaedwen_siege",
        .count = 1
    },
    Card{
        .name = "Kaedweni Siege Expert",
        .id = 99,
        .deck = DeckFaction::Realms,
        .row = Row::Siege,
        .strength = 1,
        .ability = "morale",
        .filename = "kaedwen_siege_1",
        .count = 1
    },
    Card{
        .name = "Kaedweni Siege Expert",
        .id = 100,
        .deck = DeckFaction::Realms,
        .row = Row::Siege,
        .strength = 1,
        .ability = "morale",
        .filename = "kaedwen_siege_2",
        .count = 1
    },
    Card{
        .name = "Keira Metz",
        .id = 84,
        .deck = DeckFaction::Realms,
        .row = Row::Ranged,
        .strength = 5,
        .ability = "",
        .filename = "keira",
        .count = 1
    },
    Card{
        .name = "Philippa Eilhart",
        .id = 12,
        .deck = DeckFaction::Realms,
        .row = Row::Ranged,
        .strength = 10,
        .ability = "hero",
        .filename = "philippa",
        .count = 1
    },
    Card{
        .name = "Poor Fucking Infantry",
        .id = 95,
        .deck = DeckFaction::Realms,
        .row = Row::Close,
        .strength = 1,
        .ability = "bond",
        .filename = "poor_infantry",
        .count = 4
    },
    Card{
        .name = "Prince Stennis",
        .id = 86,
        .deck = DeckFaction::Realms,
        .row = Row::Close,
        .strength = 5,
        .ability = "spy",
        .filename = "stennis",
        .count = 1
    },
    Card{
        .name = "Redanian Foot Soldier",
        .id = 96,
        .deck = DeckFaction::Realms,
        .row = Row::Close,
        .strength = 1,
        .ability = "",
        .filename = "redania",
        .count = 1
    },
    Card{
        .name = "Redanian Foot Soldier",
        .id = 97,
        .deck = DeckFaction::Realms,
        .row = Row::Close,
        .strength = 1,
        .ability = "",
        .filename = "redania_1",
        .count = 1
    },
    Card{
        .name = "Sheldon Skaggs",
        .id = 91,
        .deck = DeckFaction::Realms,
        .row = Row::Ranged,
        .strength = 4,
        .ability = "",
        .filename = "sheldon",
        .count = 1
    },
    Card{
        .name = "Siege Tower",
        .id = 81,
        .deck = DeckFaction::Realms,
        .row = Row::Siege,
        .strength = 6,
        .ability = "",
        .filename = "siege_tower",
        .count = 1
    },
    Card{
        .name = "Siegfried of Denesle",
        .id = 83,
        .deck = DeckFaction::Realms,
        .row = Row::Close,
        .strength = 5,
        .ability = "",
        .filename = "siegfried",
        .count = 1
    },
    Card{
        .name = "Sigismund Dijkstra",
        .id = 89,
        .deck = DeckFaction::Realms,
        .row = Row::Close,
        .strength = 4,
        .ability = "spy",
        .filename = "dijkstra",
        .count = 1
    },
    Card{
        .name = "Síle de Tansarville",
        .id = 85,
        .deck = DeckFaction::Realms,
        .row = Row::Ranged,
        .strength = 5,
        .ability = "",
        .filename = "sheala",
        .count = 1
    },
    Card{
        .name = "Thaler",
        .id = 94,
        .deck = DeckFaction::Realms,
        .row = Row::Siege,
        .strength = 1,
        .ability = "spy",
        .filename = "thaler",
        .count = 1
    },
    Card{
        .name = "Sabrina Glevissig",
        .id = 90,
        .deck = DeckFaction::Realms,
        .row = Row::Ranged,
        .strength = 4,
        .ability = "",
        .filename = "sabrina",
        .count = 1
    },
    Card{
        .name = "Vernon Roche",
        .id = 9,
        .deck = DeckFaction::Realms,
        .row = Row::Close,
        .strength = 10,
        .ability = "hero",
        .filename = "vernon",
        .count = 1
    },
    Card{
        .name = "Ves",
        .id = 82,
        .deck = DeckFaction::Realms,
        .row = Row::Close,
        .strength = 5,
        .ability = "",
        .filename = "ves",
        .count = 1
    },
    Card{
        .name = "Yarpen Zigrin",
        .id = 93,
        .deck = DeckFaction::Realms,
        .row = Row::Close,
        .strength = 2,
        .ability = "",
        .filename = "yarpen",
        .count = 1
    },
    Card{
        .name = "Trebuchet",
        .id = 77,
        .deck = DeckFaction::Realms,
        .row = Row::Siege,
        .strength = 6,
        .ability = "",
        .filename = "trebuchet",
        .count = 1
    },
    Card{
        .name = "Trebuchet",
        .id = 78,
        .deck = DeckFaction::Realms,
        .row = Row::Siege,
        .strength = 6,
        .ability = "",
        .filename = "trebuchet_1",
        .count = 1
    },
    Card{
        .name = "Emhyr var Emreis - His Imperial Majesty",
        .id = 1,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Leader,
        .strength = 0,
        .ability = "emhyr_imperial",
        .filename = "emhyr_silver",
        .count = 1
    },
    Card{
        .name = "Emhyr var Emreis - Emperor of Nilfgaard",
        .id = 2,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Leader,
        .strength = 0,
        .ability = "emhyr_emperor",
        .filename = "emhyr_copper",
        .count = 1
    },
    Card{
        .name = "Emhyr var Emreis - the White Flame",
        .id = 3,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Leader,
        .strength = 0,
        .ability = "emhyr_whiteflame",
        .filename = "emhyr_bronze",
        .count = 1
    },
    Card{
        .name = "Emhyr var Emreis - The Relentless",
        .id = 4,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Leader,
        .strength = 0,
        .ability = "emhyr_relentless",
        .filename = "emhyr_gold",
        .count = 1
    },
    Card{
        .name = "Emhyr var Emreis - Invader of the North",
        .id = 0,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Leader,
        .strength = 0,
        .ability = "emhyr_invader",
        .filename = "emhyr_invader_of_the_north",
        .count = 1
    },
    Card{
        .name = "Albrich",
        .id = 68,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Ranged,
        .strength = 2,
        .ability = "",
        .filename = "albrich",
        .count = 1
    },
    Card{
        .name = "Assire var Anahid",
        .id = 52,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Ranged,
        .strength = 6,
        .ability = "",
        .filename = "assire",
        .count = 1
    },
    Card{
        .name = "Black Infantry Archer",
        .id = 47,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Ranged,
        .strength = 10,
        .ability = "",
        .filename = "black_archer",
        .count = 1
    },
    Card{
        .name = "Black Infantry Archer",
        .id = 48,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Ranged,
        .strength = 10,
        .ability = "",
        .filename = "black_archer_1",
        .count = 1
    },
    Card{
        .name = "Cahir Mawr Dyffryn aep Ceallach",
        .id = 54,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Close,
        .strength = 6,
        .ability = "",
        .filename = "cahir",
        .count = 1
    },
    Card{
        .name = "Cynthia",
        .id = 60,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Ranged,
        .strength = 4,
        .ability = "",
        .filename = "cynthia",
        .count = 1
    },
    Card{
        .name = "Etolian Auxiliary Archers",
        .id = 72,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Ranged,
        .strength = 1,
        .ability = "medic",
        .filename = "archer_support",
        .count = 1
    },
    Card{
        .name = "Etolian Auxiliary Archers",
        .id = 73,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Ranged,
        .strength = 1,
        .ability = "medic",
        .filename = "archer_support_1",
        .count = 1
    },
    Card{
        .name = "Fringilla Vigo",
        .id = 53,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Ranged,
        .strength = 6,
        .ability = "",
        .filename = "fringilla",
        .count = 1
    },
    Card{
        .name = "Heavy Zerrikanian Fire Scorpion",
        .id = 49,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Siege,
        .strength = 10,
        .ability = "",
        .filename = "heavy_zerri",
        .count = 1
    },
    Card{
        .name = "Impera Brigade Guard",
        .id = 67,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Close,
        .strength = 3,
        .ability = "bond",
        .filename = "imperal_brigade",
        .count = 4
    },
    Card{
        .name = "Letho of Gulet",
        .id = 147,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Close,
        .strength = 10,
        .ability = "hero",
        .filename = "letho",
        .count = 1
    },
    Card{
        .name = "Menno Coehoorn",
        .id = 148,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Close,
        .strength = 10,
        .ability = "hero medic",
        .filename = "menno",
        .count = 1
    },
    Card{
        .name = "Morteisen",
        .id = 64,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Close,
        .strength = 3,
        .ability = "",
        .filename = "morteisen",
        .count = 1
    },
    Card{
        .name = "Morvran Voorhis",
        .id = 149,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Siege,
        .strength = 10,
        .ability = "hero",
        .filename = "moorvran",
        .count = 1
    },
    Card{
        .name = "Nausicaa Cavalry Rider",
        .id = 71,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Close,
        .strength = 2,
        .ability = "bond",
        .filename = "nauzicaa_2",
        .count = 3
    },
    Card{
        .name = "Puttkammer",
        .id = 66,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Ranged,
        .strength = 3,
        .ability = "",
        .filename = "puttkammer",
        .count = 1
    },
    Card{
        .name = "Rainfarn",
        .id = 61,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Close,
        .strength = 4,
        .ability = "",
        .filename = "rainfarn",
        .count = 1
    },
    Card{
        .name = "Renuald aep Matsen",
        .id = 56,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Ranged,
        .strength = 5,
        .ability = "",
        .filename = "renuald",
        .count = 1
    },
    Card{
        .name = "Rotten Mangonel",
        .id = 65,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Siege,
        .strength = 3,
        .ability = "",
        .filename = "rotten",
        .count = 1
    },
    Card{
        .name = "Shilard Fitz-Oesterlen",
        .id = 51,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Close,
        .strength = 7,
        .ability = "spy",
        .filename = "shilard",
        .count = 1
    },
    Card{
        .name = "Siege Engineer",
        .id = 55,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Siege,
        .strength = 6,
        .ability = "",
        .filename = "siege_engineer",
        .count = 1
    },
    Card{
        .name = "Siege Technician",
        .id = 74,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Siege,
        .strength = 0,
        .ability = "medic",
        .filename = "siege_support",
        .count = 1
    },
    Card{
        .name = "Stefan Skellen",
        .id = 50,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Close,
        .strength = 9,
        .ability = "spy",
        .filename = "stefan",
        .count = 1
    },
    Card{
        .name = "Sweers",
        .id = 69,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Ranged,
        .strength = 2,
        .ability = "",
        .filename = "sweers",
        .count = 1
    },
    Card{
        .name = "Tibor Eggebracht",
        .id = 150,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Ranged,
        .strength = 10,
        .ability = "hero",
        .filename = "tibor",
        .count = 1
    },
    Card{
        .name = "Vanhemar",
        .id = 62,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Ranged,
        .strength = 4,
        .ability = "",
        .filename = "vanhemar",
        .count = 1
    },
    Card{
        .name = "Vattier de Rideaux",
        .id = 63,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Close,
        .strength = 4,
        .ability = "spy",
        .filename = "vattier",
        .count = 1
    },
    Card{
        .name = "Vreemde",
        .id = 70,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Close,
        .strength = 2,
        .ability = "",
        .filename = "vreemde",
        .count = 1
    },
    Card{
        .name = "Young Emissary",
        .id = 58,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Close,
        .strength = 5,
        .ability = "bond",
        .filename = "young_emissary",
        .count = 1
    },
    Card{
        .name = "Young Emissary",
        .id = 59,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Close,
        .strength = 5,
        .ability = "bond",
        .filename = "young_emissary_1",
        .count = 1
    },
    Card{
        .name = "Zerrikanian Fire Scorpion",
        .id = 57,
        .deck = DeckFaction::Nilfgaard,
        .row = Row::Siege,
        .strength = 5,
        .ability = "",
        .filename = "zerri",
        .count = 1
    },
    Card{
        .name = "Eredin - Commander of the Red Riders",
        .id = 134,
        .deck = DeckFaction::Monsters,
        .row = Row::Leader,
        .strength = 0,
        .ability = "eredin_commander",
        .filename = "eredin_silver",
        .count = 1
    },
    Card{
        .name = "Eredin - Bringer of Death",
        .id = 136,
        .deck = DeckFaction::Monsters,
        .row = Row::Leader,
        .strength = 0,
        .ability = "eredin_bringer_of_death",
        .filename = "eredin_bronze",
        .count = 1
    },
    Card{
        .name = "Eredin - Destroyer of Worlds",
        .id = 137,
        .deck = DeckFaction::Monsters,
        .row = Row::Leader,
        .strength = 0,
        .ability = "eredin_destroyer",
        .filename = "eredin_gold",
        .count = 1
    },
    Card{
        .name = "Eredin - King of the Wild Hunt",
        .id = 135,
        .deck = DeckFaction::Monsters,
        .row = Row::Leader,
        .strength = 0,
        .ability = "eredin_king",
        .filename = "eredin_copper",
        .count = 1
    },
    Card{
        .name = "Eredin Bréacc Glas - The Treacherous",
        .id = 0,
        .deck = DeckFaction::Monsters,
        .row = Row::Leader,
        .strength = 0,
        .ability = "eredin_treacherous",
        .filename = "eredin_the_treacherous",
        .count = 1
    },
    Card{
        .name = "Arachas ",
        .id = 27,
        .deck = DeckFaction::Monsters,
        .row = Row::Close,
        .strength = 4,
        .ability = "muster",
        .filename = "arachas",
        .count = 1
    },
    Card{
        .name = "Arachas ",
        .id = 28,
        .deck = DeckFaction::Monsters,
        .row = Row::Close,
        .strength = 4,
        .ability = "muster",
        .filename = "arachas_1",
        .count = 1
    },
    Card{
        .name = "Arachas ",
        .id = 29,
        .deck = DeckFaction::Monsters,
        .row = Row::Close,
        .strength = 4,
        .ability = "muster",
        .filename = "arachas_2",
        .count = 1
    },
    Card{
        .name = "Arachas- Behemoth",
        .id = 15,
        .deck = DeckFaction::Monsters,
        .row = Row::Siege,
        .strength = 6,
        .ability = "muster",
        .filename = "arachas_behemoth",
        .count = 1
    },
    Card{
        .name = "Botchling",
        .id = 26,
        .deck = DeckFaction::Monsters,
        .row = Row::Close,
        .strength = 4,
        .ability = "",
        .filename = "poroniec",
        .count = 1
    },
    Card{
        .name = "Celaeno Harpy",
        .id = 38,
        .deck = DeckFaction::Monsters,
        .row = Row::Agile,
        .strength = 2,
        .ability = "",
        .filename = "celaeno_harpy",
        .count = 1
    },
    Card{
        .name = "Cockatrice",
        .id = 36,
        .deck = DeckFaction::Monsters,
        .row = Row::Ranged,
        .strength = 2,
        .ability = "",
        .filename = "cockatrice",
        .count = 1
    },
    Card{
        .name = "Crone - Brewess",
        .id = 16,
        .deck = DeckFaction::Monsters,
        .row = Row::Close,
        .strength = 6,
        .ability = "muster",
        .filename = "witch_velen",
        .count = 1
    },
    Card{
        .name = "Crone - Weavess",
        .id = 17,
        .deck = DeckFaction::Monsters,
        .row = Row::Close,
        .strength = 6,
        .ability = "muster",
        .filename = "witch_velen_1",
        .count = 1
    },
    Card{
        .name = "Crone - Whispess",
        .id = 18,
        .deck = DeckFaction::Monsters,
        .row = Row::Close,
        .strength = 6,
        .ability = "muster",
        .filename = "witch_velen_2",
        .count = 1
    },
    Card{
        .name = "Draug",
        .id = 143,
        .deck = DeckFaction::Monsters,
        .row = Row::Close,
        .strength = 10,
        .ability = "hero",
        .filename = "draug",
        .count = 1
    },
    Card{
        .name = "Earth Elemental",
        .id = 12,
        .deck = DeckFaction::Monsters,
        .row = Row::Siege,
        .strength = 6,
        .ability = "",
        .filename = "earth_elemental",
        .count = 1
    },
    Card{
        .name = "Endrega",
        .id = 34,
        .deck = DeckFaction::Monsters,
        .row = Row::Ranged,
        .strength = 2,
        .ability = "",
        .filename = "endrega",
        .count = 1
    },
    Card{
        .name = "Fiend",
        .id = 13,
        .deck = DeckFaction::Monsters,
        .row = Row::Close,
        .strength = 6,
        .ability = "",
        .filename = "fiend",
        .count = 1
    },
    Card{
        .name = "Fire Elemental",
        .id = 14,
        .deck = DeckFaction::Monsters,
        .row = Row::Siege,
        .strength = 6,
        .ability = "",
        .filename = "fire_elemental",
        .count = 1
    },
    Card{
        .name = "Foglet",
        .id = 39,
        .deck = DeckFaction::Monsters,
        .row = Row::Close,
        .strength = 2,
        .ability = "",
        .filename = "fogling",
        .count = 1
    },
    Card{
        .name = "Forktail",
        .id = 19,
        .deck = DeckFaction::Monsters,
        .row = Row::Close,
        .strength = 5,
        .ability = "",
        .filename = "forktail",
        .count = 1
    },
    Card{
        .name = "Frightener",
        .id = 23,
        .deck = DeckFaction::Monsters,
        .row = Row::Close,
        .strength = 5,
        .ability = "",
        .filename = "frightener",
        .count = 1
    },
    Card{
        .name = "Gargoyle",
        .id = 37,
        .deck = DeckFaction::Monsters,
        .row = Row::Ranged,
        .strength = 2,
        .ability = "",
        .filename = "gargoyle",
        .count = 1
    },
    Card{
        .name = "Ghoul",
        .id = 44,
        .deck = DeckFaction::Monsters,
        .row = Row::Close,
        .strength = 1,
        .ability = "muster",
        .filename = "ghoul",
        .count = 1
    },
    Card{
        .name = "Ghoul",
        .id = 45,
        .deck = DeckFaction::Monsters,
        .row = Row::Close,
        .strength = 1,
        .ability = "muster",
        .filename = "ghoul_1",
        .count = 1
    },
    Card{
        .name = "Ghoul",
        .id = 46,
        .deck = DeckFaction::Monsters,
        .row = Row::Close,
        .strength = 1,
        .ability = "muster",
        .filename = "ghoul_2",
        .count = 1
    },
    Card{
        .name = "Grave Hag",
        .id = 25,
        .deck = DeckFaction::Monsters,
        .row = Row::Ranged,
        .strength = 5,
        .ability = "",
        .filename = "gravehag",
        .count = 1
    },
    Card{
        .name = "Griffin",
        .id = 21,
        .deck = DeckFaction::Monsters,
        .row = Row::Close,
        .strength = 5,
        .ability = "",
        .filename = "gryffin",
        .count = 1
    },
    Card{
        .name = "Harpy",
        .id = 35,
        .deck = DeckFaction::Monsters,
        .row = Row::Agile,
        .strength = 2,
        .ability = "",
        .filename = "harpy",
        .count = 1
    },
    Card{
        .name = "Ice Giant",
        .id = 24,
        .deck = DeckFaction::Monsters,
        .row = Row::Siege,
        .strength = 5,
        .ability = "",
        .filename = "frost_giant",
        .count = 1
    },
    Card{
        .name = "Imlerith",
        .id = 144,
        .deck = DeckFaction::Monsters,
        .row = Row::Close,
        .strength = 10,
        .ability = "hero",
        .filename = "imlerith",
        .count = 1
    },
    Card{
        .name = "Kayran",
        .id = 146,
        .deck = DeckFaction::Monsters,
        .row = Row::Agile,
        .strength = 8,
        .ability = "hero morale",
        .filename = "kayran",
        .count = 1
    },
    Card{
        .name = "Leshen",
        .id = 145,
        .deck = DeckFaction::Monsters,
        .row = Row::Ranged,
        .strength = 10,
        .ability = "hero",
        .filename = "leshen",
        .count = 1
    },
    Card{
        .name = "Nekker",
        .id = 41,
        .deck = DeckFaction::Monsters,
        .row = Row::Close,
        .strength = 2,
        .ability = "muster",
        .filename = "nekker",
        .count = 1
    },
    Card{
        .name = "Nekker",
        .id = 42,
        .deck = DeckFaction::Monsters,
        .row = Row::Close,
        .strength = 2,
        .ability = "muster",
        .filename = "nekker_1",
        .count = 1
    },
    Card{
        .name = "Nekker",
        .id = 43,
        .deck = DeckFaction::Monsters,
        .row = Row::Close,
        .strength = 2,
        .ability = "muster",
        .filename = "nekker_2",
        .count = 1
    },
    Card{
        .name = "Plague Maiden",
        .id = 20,
        .deck = DeckFaction::Monsters,
        .row = Row::Close,
        .strength = 5,
        .ability = "",
        .filename = "mighty_maiden",
        .count = 1
    },
    Card{
        .name = "Vampire - Bruxa",
        .id = 33,
        .deck = DeckFaction::Monsters,
        .row = Row::Close,
        .strength = 4,
        .ability = "muster",
        .filename = "bruxa",
        .count = 1
    },
    Card{
        .name = "Vampire - Ekimmara",
        .id = 30,
        .deck = DeckFaction::Monsters,
        .row = Row::Close,
        .strength = 4,
        .ability = "muster",
        .filename = "ekkima",
        .count = 1
    },
    Card{
        .name = "Vampire - Fleder",
        .id = 31,
        .deck = DeckFaction::Monsters,
        .row = Row::Close,
        .strength = 4,
        .ability = "muster",
        .filename = "fleder",
        .count = 1
    },
    Card{
        .name = "Vampire - Garkain",
        .id = 32,
        .deck = DeckFaction::Monsters,
        .row = Row::Close,
        .strength = 4,
        .ability = "muster",
        .filename = "garkain",
        .count = 1
    },
    Card{
        .name = "Vampire - Katakan",
        .id = 0,
        .deck = DeckFaction::Monsters,
        .row = Row::Close,
        .strength = 5,
        .ability = "muster",
        .filename = "katakan",
        .count = 1
    },
    Card{
        .name = "Werewolf",
        .id = 22,
        .deck = DeckFaction::Monsters,
        .row = Row::Close,
        .strength = 5,
        .ability = "",
        .filename = "werewolf",
        .count = 1
    },
    Card{
        .name = "Wyvern",
        .id = 40,
        .deck = DeckFaction::Monsters,
        .row = Row::Ranged,
        .strength = 2,
        .ability = "",
        .filename = "wyvern",
        .count = 1
    },
    Card{
        .name = "Toad",
        .id = 0,
        .deck = DeckFaction::Monsters,
        .row = Row::Ranged,
        .strength = 7,
        .ability = "scorch_r",
        .filename = "toad",
        .count = 1
    },
    Card{
        .name = "Francesca Findabair - Queen of Dol Blathanna",
        .id = 13,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Leader,
        .strength = 0,
        .ability = "francesca_queen",
        .filename = "francesca_silver",
        .count = 1
    },
    Card{
        .name = "Francesca Findabair - the Beautiful",
        .id = 14,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Leader,
        .strength = 0,
        .ability = "francesca_beautiful",
        .filename = "francesca_gold",
        .count = 1
    },
    Card{
        .name = "Francesca Findabair - Daisy of the Valley",
        .id = 15,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Leader,
        .strength = 0,
        .ability = "francesca_daisy",
        .filename = "francesca_copper",
        .count = 1
    },
    Card{
        .name = "Francesca Findabair - Pureblood Elf",
        .id = 16,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Leader,
        .strength = 0,
        .ability = "francesca_pureblood",
        .filename = "francesca_bronze",
        .count = 1
    },
    Card{
        .name = "Francesca Findabair - Hope of the Aen Seidhe",
        .id = 0,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Leader,
        .strength = 0,
        .ability = "francesca_hope",
        .filename = "francesca_hope_of_the_aen_seidhe",
        .count = 1
    },
    Card{
        .name = "Ciaran aep Easnillien",
        .id = 122,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Agile,
        .strength = 3,
        .ability = "",
        .filename = "ciaran",
        .count = 1
    },
    Card{
        .name = "Barclay Els",
        .id = 106,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Agile,
        .strength = 6,
        .ability = "",
        .filename = "barclay",
        .count = 1
    },
    Card{
        .name = "Dennis Cranmer",
        .id = 102,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Close,
        .strength = 6,
        .ability = "",
        .filename = "dennis",
        .count = 1
    },
    Card{
        .name = "Dol Blathanna Archer",
        .id = 121,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Ranged,
        .strength = 4,
        .ability = "",
        .filename = "dol_archer",
        .count = 1
    },
    Card{
        .name = "Dol Blathanna Scout",
        .id = 107,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Agile,
        .strength = 6,
        .ability = "",
        .filename = "dol_infantry",
        .count = 1
    },
    Card{
        .name = "Dol Blathanna Scout",
        .id = 108,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Agile,
        .strength = 6,
        .ability = "",
        .filename = "dol_infantry_1",
        .count = 1
    },
    Card{
        .name = "Dol Blathanna Scout",
        .id = 109,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Agile,
        .strength = 6,
        .ability = "",
        .filename = "dol_infantry_2",
        .count = 1
    },
    Card{
        .name = "Dwarven Skirmisher",
        .id = 123,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Close,
        .strength = 3,
        .ability = "muster",
        .filename = "dwarf",
        .count = 1
    },
    Card{
        .name = "Dwarven Skirmisher",
        .id = 124,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Close,
        .strength = 3,
        .ability = "muster",
        .filename = "dwarf_1",
        .count = 1
    },
    Card{
        .name = "Dwarven Skirmisher",
        .id = 125,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Close,
        .strength = 3,
        .ability = "muster",
        .filename = "dwarf_2",
        .count = 1
    },
    Card{
        .name = "Eithné",
        .id = 17,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Ranged,
        .strength = 10,
        .ability = "hero",
        .filename = "eithne",
        .count = 1
    },
    Card{
        .name = "Elven Skirmisher",
        .id = 127,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Ranged,
        .strength = 2,
        .ability = "muster",
        .filename = "elf_skirmisher",
        .count = 1
    },
    Card{
        .name = "Elven Skirmisher",
        .id = 128,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Ranged,
        .strength = 2,
        .ability = "muster",
        .filename = "elf_skirmisher_1",
        .count = 1
    },
    Card{
        .name = "Elven Skirmisher",
        .id = 129,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Ranged,
        .strength = 2,
        .ability = "muster",
        .filename = "elf_skirmisher_2",
        .count = 1
    },
    Card{
        .name = "Filavandrel aen Fidhail",
        .id = 104,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Agile,
        .strength = 6,
        .ability = "",
        .filename = "filavandrel",
        .count = 1
    },
    Card{
        .name = "Havekar Healer",
        .id = 131,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Ranged,
        .strength = 0,
        .ability = "medic",
        .filename = "havekar_nurse",
        .count = 1
    },
    Card{
        .name = "Havekar Healer",
        .id = 132,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Ranged,
        .strength = 0,
        .ability = "medic",
        .filename = "havekar_nurse_1",
        .count = 1
    },
    Card{
        .name = "Havekar Healer",
        .id = 133,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Ranged,
        .strength = 0,
        .ability = "medic",
        .filename = "havekar_nurse_2",
        .count = 1
    },
    Card{
        .name = "Havekar Smuggler",
        .id = 110,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Close,
        .strength = 5,
        .ability = "muster",
        .filename = "havekar_support",
        .count = 1
    },
    Card{
        .name = "Havekar Smuggler",
        .id = 111,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Close,
        .strength = 5,
        .ability = "muster",
        .filename = "havekar_support_1",
        .count = 1
    },
    Card{
        .name = "Havekar Smuggler",
        .id = 112,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Close,
        .strength = 5,
        .ability = "muster",
        .filename = "havekar_support_2",
        .count = 1
    },
    Card{
        .name = "Ida Emean aep Sivney",
        .id = 103,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Ranged,
        .strength = 6,
        .ability = "",
        .filename = "ida",
        .count = 1
    },
    Card{
        .name = "Iorveth",
        .id = 20,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Ranged,
        .strength = 10,
        .ability = "hero",
        .filename = "iorveth",
        .count = 1
    },
    Card{
        .name = "Isengrim Faoiltiarna",
        .id = 19,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Close,
        .strength = 10,
        .ability = "hero morale",
        .filename = "isengrim",
        .count = 1
    },
    Card{
        .name = "Mahakaman Defender",
        .id = 115,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Close,
        .strength = 5,
        .ability = "",
        .filename = "mahakam",
        .count = 1
    },
    Card{
        .name = "Mahakaman Defender",
        .id = 116,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Close,
        .strength = 5,
        .ability = "",
        .filename = "mahakam_1",
        .count = 1
    },
    Card{
        .name = "Mahakaman Defender",
        .id = 117,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Close,
        .strength = 5,
        .ability = "",
        .filename = "mahakam_2",
        .count = 1
    },
    Card{
        .name = "Mahakaman Defender",
        .id = 118,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Close,
        .strength = 5,
        .ability = "",
        .filename = "mahakam_3",
        .count = 1
    },
    Card{
        .name = "Mahakaman Defender",
        .id = 119,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Close,
        .strength = 5,
        .ability = "",
        .filename = "mahakam_4",
        .count = 1
    },
    Card{
        .name = "Milva",
        .id = 101,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Ranged,
        .strength = 10,
        .ability = "morale",
        .filename = "milva",
        .count = 1
    },
    Card{
        .name = "Riordain",
        .id = 130,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Ranged,
        .strength = 1,
        .ability = "",
        .filename = "riordain",
        .count = 1
    },
    Card{
        .name = "Saesenthessis",
        .id = 18,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Ranged,
        .strength = 10,
        .ability = "hero",
        .filename = "saskia",
        .count = 1
    },
    Card{
        .name = "Toruviel",
        .id = 126,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Ranged,
        .strength = 2,
        .ability = "",
        .filename = "toruviel",
        .count = 1
    },
    Card{
        .name = "Vrihedd Brigade Recruit",
        .id = 120,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Ranged,
        .strength = 4,
        .ability = "",
        .filename = "vrihedd_cadet",
        .count = 1
    },
    Card{
        .name = "Vrihedd Brigade Veteran",
        .id = 113,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Agile,
        .strength = 5,
        .ability = "",
        .filename = "vrihedd_brigade",
        .count = 1
    },
    Card{
        .name = "Vrihedd Brigade Veteran",
        .id = 114,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Agile,
        .strength = 5,
        .ability = "",
        .filename = "vrihedd_brigade_1",
        .count = 1
    },
    Card{
        .name = "Yaevinn",
        .id = 105,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Agile,
        .strength = 6,
        .ability = "",
        .filename = "yaevinn",
        .count = 1
    },
    Card{
        .name = "Berserker",
        .id = 0,
        .deck = DeckFaction::Skellige,
        .row = Row::Close,
        .strength = 4,
        .ability = "berserker",
        .filename = "berserker",
        .count = 1
    },
    Card{
        .name = "Birna Bran",
        .id = 0,
        .deck = DeckFaction::Skellige,
        .row = Row::Close,
        .strength = 2,
        .ability = "medic",
        .filename = "birna",
        .count = 1
    },
    Card{
        .name = "Blueboy Lugos",
        .id = 0,
        .deck = DeckFaction::Skellige,
        .row = Row::Close,
        .strength = 6,
        .ability = "",
        .filename = "blueboy",
        .count = 1
    },
    Card{
        .name = "Cerys",
        .id = 0,
        .deck = DeckFaction::Skellige,
        .row = Row::Close,
        .strength = 10,
        .ability = "hero muster",
        .filename = "cerys",
        .count = 1
    },
    Card{
        .name = "Clan Brokva Archer",
        .id = 0,
        .deck = DeckFaction::Skellige,
        .row = Row::Ranged,
        .strength = 6,
        .ability = "",
        .filename = "brokva_archer",
        .count = 2
    },
    Card{
        .name = "Clan Dimun Pirate",
        .id = 0,
        .deck = DeckFaction::Skellige,
        .row = Row::Ranged,
        .strength = 6,
        .ability = "scorch",
        .filename = "dimun_pirate",
        .count = 1
    },
    Card{
        .name = "Cerys - Clan Drummond Shield Maiden",
        .id = 0,
        .deck = DeckFaction::Skellige,
        .row = Row::Close,
        .strength = 4,
        .ability = "bond",
        .filename = "shield_maiden",
        .count = 1
    },
    Card{
        .name = "Cerys - Clan Drummond Shield Maiden",
        .id = 0,
        .deck = DeckFaction::Skellige,
        .row = Row::Close,
        .strength = 4,
        .ability = "bond",
        .filename = "shield_maiden_1",
        .count = 1
    },
    Card{
        .name = "Cerys - Clan Drummond Shield Maiden",
        .id = 0,
        .deck = DeckFaction::Skellige,
        .row = Row::Close,
        .strength = 4,
        .ability = "bond",
        .filename = "shield_maiden_2",
        .count = 1
    },
    Card{
        .name = "Clan Heymaey Skald",
        .id = 0,
        .deck = DeckFaction::Skellige,
        .row = Row::Close,
        .strength = 4,
        .ability = "",
        .filename = "heymaey",
        .count = 1
    },
    Card{
        .name = "Clan Tordarroch Armorsmith",
        .id = 0,
        .deck = DeckFaction::Skellige,
        .row = Row::Close,
        .strength = 4,
        .ability = "",
        .filename = "tordarroch",
        .count = 1
    },
    Card{
        .name = "Clan an Craite Warrior",
        .id = 0,
        .deck = DeckFaction::Skellige,
        .row = Row::Close,
        .strength = 6,
        .ability = "bond",
        .filename = "craite_warrior",
        .count = 3
    },
    Card{
        .name = "Donar an Hindar",
        .id = 0,
        .deck = DeckFaction::Skellige,
        .row = Row::Close,
        .strength = 4,
        .ability = "",
        .filename = "donar",
        .count = 1
    },
    Card{
        .name = "Draig Bon-Dhu",
        .id = 0,
        .deck = DeckFaction::Skellige,
        .row = Row::Siege,
        .strength = 2,
        .ability = "horn",
        .filename = "draig",
        .count = 1
    },
    Card{
        .name = "Ermion",
        .id = 0,
        .deck = DeckFaction::Skellige,
        .row = Row::Ranged,
        .strength = 8,
        .ability = "hero mardroeme",
        .filename = "ermion",
        .count = 1
    },
    Card{
        .name = "Hemdall",
        .id = 0,
        .deck = DeckFaction::Skellige,
        .row = Row::Close,
        .strength = 11,
        .ability = "hero",
        .filename = "hemdall",
        .count = 0
    },
    Card{
        .name = "Hjalmar",
        .id = 0,
        .deck = DeckFaction::Skellige,
        .row = Row::Ranged,
        .strength = 10,
        .ability = "hero",
        .filename = "hjalmar",
        .count = 1
    },
    Card{
        .name = "Holger Blackhand",
        .id = 0,
        .deck = DeckFaction::Skellige,
        .row = Row::Siege,
        .strength = 4,
        .ability = "",
        .filename = "holger",
        .count = 1
    },
    Card{
        .name = "Kambi",
        .id = 0,
        .deck = DeckFaction::Skellige,
        .row = Row::Close,
        .strength = 0,
        .ability = "avenger_kambi",
        .filename = "kambi",
        .count = 1
    },
    Card{
        .name = "Light Longship",
        .id = 0,
        .deck = DeckFaction::Skellige,
        .row = Row::Ranged,
        .strength = 4,
        .ability = "muster",
        .filename = "light_longship",
        .count = 3
    },
    Card{
        .name = "Madman Lugos",
        .id = 0,
        .deck = DeckFaction::Skellige,
        .row = Row::Close,
        .strength = 6,
        .ability = "",
        .filename = "madmad_lugos",
        .count = 1
    },
    Card{
        .name = "Mardroeme",
        .id = 0,
        .deck = DeckFaction::Special,
        .row = Row::None,
        .strength = 0,
        .ability = "mardroeme",
        .filename = "mardroeme",
        .count = 3
    },
    Card{
        .name = "Olaf",
        .id = 0,
        .deck = DeckFaction::Skellige,
        .row = Row::Agile,
        .strength = 12,
        .ability = "morale",
        .filename = "olaf",
        .count = 1
    },
    Card{
        .name = "Skellige Storm",
        .id = 0,
        .deck = DeckFaction::Weather,
        .row = Row::None,
        .strength = 0,
        .ability = "rain fog",
        .filename = "storm",
        .count = 3
    },
    Card{
        .name = "Svanrige",
        .id = 0,
        .deck = DeckFaction::Skellige,
        .row = Row::Close,
        .strength = 4,
        .ability = "",
        .filename = "svanrige",
        .count = 1
    },
    Card{
        .name = "Transformed Vildkaarl",
        .id = 0,
        .deck = DeckFaction::Skellige,
        .row = Row::Close,
        .strength = 14,
        .ability = "morale",
        .filename = "vildkaarl",
        .count = 0
    },
    Card{
        .name = "Transformed Young Vildkaarl",
        .id = 0,
        .deck = DeckFaction::Skellige,
        .row = Row::Ranged,
        .strength = 8,
        .ability = "bond",
        .filename = "young_vildkaarl",
        .count = 0
    },
    Card{
        .name = "Udalryk",
        .id = 0,
        .deck = DeckFaction::Skellige,
        .row = Row::Close,
        .strength = 4,
        .ability = "",
        .filename = "udalryk",
        .count = 1
    },
    Card{
        .name = "War Longship",
        .id = 0,
        .deck = DeckFaction::Skellige,
        .row = Row::Siege,
        .strength = 6,
        .ability = "bond",
        .filename = "war_longship",
        .count = 2
    },
    Card{
        .name = "Young Berserker",
        .id = 0,
        .deck = DeckFaction::Skellige,
        .row = Row::Ranged,
        .strength = 2,
        .ability = "berserker",
        .filename = "young_berserker",
        .count = 3
    },
    Card{
        .name = "Crach an Craite",
        .id = 0,
        .deck = DeckFaction::Skellige,
        .row = Row::Leader,
        .strength = 0,
        .ability = "crach_an_craite",
        .filename = "crach_an_craite",
        .count = 0
    },
    Card{
        .name = "King Bran",
        .id = 0,
        .deck = DeckFaction::Skellige,
        .row = Row::Leader,
        .strength = 0,
        .ability = "king_bran",
        .filename = "king_bran",
        .count = 0
    },
    Card{
        .name = "Schirru",
        .id = 0,
        .deck = DeckFaction::Scoiatael,
        .row = Row::Siege,
        .strength = 8,
        .ability = "scorch_s",
        .filename = "schirru",
        .count = 1
    }
};

// clang-format on

static constexpr inline Card find_card(const u32 id) noexcept
{
    for (const auto &card : g_cards_map) {
        if (card.id == id) {
            return card;
        }
    }
    return Card{};
}

static constexpr inline Card find_card(const std::string_view &name) noexcept
{
    for (const auto &card : g_cards_map) {
        if (card.name == name) {
            return card;
        }
    }
    return Card{};
}

namespace {

static constexpr inline std::size_t _count_by_faction(const DeckFaction faction) noexcept
{
    std::size_t cnt = 0;

    for (const auto &c : g_cards_map) {
        if (c.deck == faction)
            ++cnt;
    }
    return cnt;
}

template<std::size_t N>
static constexpr inline std::array<const Card *, N> _collect_by_faction(const DeckFaction faction) noexcept
{
    std::array<const Card *, N> out{};
    std::size_t i = 0;

    for (const auto &c : g_cards_map) {
        if (c.deck == faction) {
            out[i++] = &c;
        }
    }
    return out;
}

}// namespace

template<DeckFaction F>
struct faction_cards final {
        static constexpr std::size_t size = _count_by_faction(F);
        static constexpr auto value = _collect_by_faction<size>(F);
};

static constexpr auto &g_neutral_cards = faction_cards<DeckFaction::Neutral>::value;
static constexpr auto &g_monsters_cards = faction_cards<DeckFaction::Monsters>::value;
static constexpr auto &g_scoiatael_cards = faction_cards<DeckFaction::Scoiatael>::value;
static constexpr auto &g_skellige_cards = faction_cards<DeckFaction::Skellige>::value;
static constexpr auto &g_special_cards = faction_cards<DeckFaction::Special>::value;
static constexpr auto &g_weather_cards = faction_cards<DeckFaction::Weather>::value;
static constexpr auto &g_realms_cards = faction_cards<DeckFaction::Realms>::value;
static constexpr auto &g_nilfgaard_cards = faction_cards<DeckFaction::Nilfgaard>::value;

}// namespace gwent

}// namespace r
