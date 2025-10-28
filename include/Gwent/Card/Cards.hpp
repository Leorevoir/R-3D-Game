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

static constexpr std::array<Card, 313> g_cards_map
{
    Card{"Mysterious Elf", 142, DeckFaction::Neutral, Row::Close, 0, "hero spy", "mysterious_elf", 1},
    Card{"Decoy", 1, DeckFaction::Special, Row::None, 0, "decoy", "decoy", 3},
    Card{"Biting Frost", 4, DeckFaction::Weather, Row::None, 0, "frost", "frost", 3},
    Card{"Cirilla Fiona Elen Riannon", 139, DeckFaction::Neutral, Row::Close, 15, "hero", "ciri", 1},
    Card{"Clear Weather", 7, DeckFaction::Weather, Row::None, 0, "clear", "clear", 2},
    Card{"Commander's Horn", 2, DeckFaction::Special, Row::None, 0, "horn", "horn", 3},
    Card{"Dandelion", 11, DeckFaction::Neutral, Row::Close, 2, "horn", "dandelion", 1},
    Card{"Emiel Regis Rohellec Terzieff", 0, DeckFaction::Neutral, Row::Close, 5, "", "emiel", 1},
    Card{"Geralt of Rivia", 138, DeckFaction::Neutral, Row::Close, 15, "hero", "geralt", 1},
    Card{"Impenetrable Fog", 5, DeckFaction::Weather, Row::None, 0, "fog", "fog", 3},
    Card{"Scorch", 3, DeckFaction::Special, Row::None, 0, "scorch", "scorch", 3},
    Card{"Torrential Rain", 6, DeckFaction::Weather, Row::None, 0, "rain", "rain", 2},
    Card{"Triss Merigold", 141, DeckFaction::Neutral, Row::Close, 7, "hero", "triss", 1},
    Card{"Vesemir", 9, DeckFaction::Neutral, Row::Close, 6, "", "vesemir", 1},
    Card{"Villentretenmerth", 8, DeckFaction::Neutral, Row::Close, 7, "scorch_c", "villen", 1},
    Card{"Yennefer of Vengerberg", 140, DeckFaction::Neutral, Row::Ranged, 7, "hero medic", "yennefer", 1},
    Card{"Zoltan Chivay", 10, DeckFaction::Neutral, Row::Close, 5, "", "zoltan", 1},
    Card{"Olgierd von Everec", 0, DeckFaction::Neutral, Row::Agile, 6, "morale", "olgierd", 1},
    Card{"Gaunter O'Dimm", 0, DeckFaction::Neutral, Row::Siege, 2, "muster", "gaunter_odimm", 1},
    Card{"Gaunter O'Dimm - Darkness", 0, DeckFaction::Neutral, Row::Ranged, 4, "muster", "gaunter_odimm_darkness", 3},
    Card{"Cow", 0, DeckFaction::Neutral, Row::Ranged, 0, "avenger", "cow", 1},
    Card{"Bovine Defense Force", 0, DeckFaction::Neutral, Row::Close, 8, "", "chort", 0},
    Card{"Foltest - King of Temeria", 5, DeckFaction::Realms, Row::Leader, 0, "foltest_king", "foltest_silver", 1},
    Card{"Foltest - Lord Commander of the North", 8, DeckFaction::Realms, Row::Leader, 0, "foltest_lord", "foltest_gold", 1},
    Card{"Foltest - The Siegemaster", 6, DeckFaction::Realms, Row::Leader, 0, "foltest_siegemaster", "foltest_copper", 1},
    Card{"Foltest - The Steel-Forged", 7, DeckFaction::Realms, Row::Leader, 0, "foltest_steelforged", "foltest_bronze", 1},
    Card{"Foltest - Son of Medell", 0, DeckFaction::Realms, Row::Leader, 0, "foltest_son", "foltest_son_of_medell", 1},
    Card{"Ballista", 79, DeckFaction::Realms, Row::Siege, 6, "", "ballista", 1},
    Card{"Blue Stripes Commando", 92, DeckFaction::Realms, Row::Close, 4, "bond", "blue_stripes", 3},
    Card{"Catapult", 75, DeckFaction::Realms, Row::Siege, 8, "bond", "catapult_1", 2},
    Card{"Crinfrid Reavers Dragon Hunter", 87, DeckFaction::Realms, Row::Ranged, 5, "bond", "crinfrid", 3},
    Card{"Dethmold", 76, DeckFaction::Realms, Row::Ranged, 6, "", "dethmold", 1},
    Card{"Dun Banner Medic", 88, DeckFaction::Realms, Row::Siege, 5, "medic", "banner_nurse", 1},
    Card{"Esterad Thyssen", 11, DeckFaction::Realms, Row::Close, 10, "hero", "esterad", 1},
    Card{"John Natalis", 10, DeckFaction::Realms, Row::Close, 10, "hero", "natalis", 1},
    Card{"Kaedweni Siege Expert", 98, DeckFaction::Realms, Row::Siege, 1, "morale", "kaedwen_siege", 1},
    Card{"Kaedweni Siege Expert", 99, DeckFaction::Realms, Row::Siege, 1, "morale", "kaedwen_siege_1", 1},
    Card{"Kaedweni Siege Expert", 100, DeckFaction::Realms, Row::Siege, 1, "morale", "kaedwen_siege_2", 1},
    Card{"Keira Metz", 84, DeckFaction::Realms, Row::Ranged, 5, "", "keira", 1},
    Card{"Philippa Eilhart", 12, DeckFaction::Realms, Row::Ranged, 10, "hero", "philippa", 1},
    Card{"Poor Fucking Infantry", 95, DeckFaction::Realms, Row::Close, 1, "bond", "poor_infantry", 4},
    Card{"Prince Stennis", 86, DeckFaction::Realms, Row::Close, 5, "spy", "stennis", 1},
    Card{"Redanian Foot Soldier", 96, DeckFaction::Realms, Row::Close, 1, "", "redania", 1},
    Card{"Redanian Foot Soldier", 97, DeckFaction::Realms, Row::Close, 1, "", "redania_1", 1},
    Card{"Sheldon Skaggs", 91, DeckFaction::Realms, Row::Ranged, 4, "", "sheldon", 1},
    Card{"Siege Tower", 81, DeckFaction::Realms, Row::Siege, 6, "", "siege_tower", 1},
    Card{"Siegfried of Denesle", 83, DeckFaction::Realms, Row::Close, 5, "", "siegfried", 1},
    Card{"Sigismund Dijkstra", 89, DeckFaction::Realms, Row::Close, 4, "spy", "dijkstra", 1},
    Card{"Síle de Tansarville", 85, DeckFaction::Realms, Row::Ranged, 5, "", "sheala", 1},
    Card{"Thaler", 94, DeckFaction::Realms, Row::Siege, 1, "spy", "thaler", 1},
    Card{"Sabrina Glevissig", 90, DeckFaction::Realms, Row::Ranged, 4, "", "sabrina", 1},
    Card{"Vernon Roche", 9, DeckFaction::Realms, Row::Close, 10, "hero", "vernon", 1},
    Card{"Ves", 82, DeckFaction::Realms, Row::Close, 5, "", "ves", 1},
    Card{"Yarpen Zigrin", 93, DeckFaction::Realms, Row::Close, 2, "", "yarpen", 1},
    Card{"Trebuchet", 77, DeckFaction::Realms, Row::Siege, 6, "", "trebuchet", 1},
    Card{"Trebuchet", 78, DeckFaction::Realms, Row::Siege, 6, "", "trebuchet_1", 1},
    Card{"Emhyr var Emreis - His Imperial Majesty", 1, DeckFaction::Nilfgaard, Row::Leader, 0, "emhyr_imperial", "emhyr_silver", 1},
    Card{"Emhyr var Emreis - Emperor of Nilfgaard", 2, DeckFaction::Nilfgaard, Row::Leader, 0, "emhyr_emperor", "emhyr_copper", 1},
    Card{"Emhyr var Emreis - the White Flame", 3, DeckFaction::Nilfgaard, Row::Leader, 0, "emhyr_whiteflame", "emhyr_bronze", 1},
    Card{"Emhyr var Emreis - The Relentless", 4, DeckFaction::Nilfgaard, Row::Leader, 0, "emhyr_relentless", "emhyr_gold", 1},
    Card{"Emhyr var Emreis - Invader of the North", 0, DeckFaction::Nilfgaard, Row::Leader, 0, "emhyr_invader", "emhyr_invader_of_the_north", 1},
    Card{"Albrich", 68, DeckFaction::Nilfgaard, Row::Ranged, 2, "", "albrich", 1},
    Card{"Assire var Anahid", 52, DeckFaction::Nilfgaard, Row::Ranged, 6, "", "assire", 1},
    Card{"Black Infantry Archer", 47, DeckFaction::Nilfgaard, Row::Ranged, 10, "", "black_archer", 1},
    Card{"Black Infantry Archer", 48, DeckFaction::Nilfgaard, Row::Ranged, 10, "", "black_archer_1", 1},
    Card{"Cahir Mawr Dyffryn aep Ceallach", 54, DeckFaction::Nilfgaard, Row::Close, 6, "", "cahir", 1},
    Card{"Cynthia", 60, DeckFaction::Nilfgaard, Row::Ranged, 4, "", "cynthia", 1},
    Card{"Etolian Auxiliary Archers", 72, DeckFaction::Nilfgaard, Row::Ranged, 1, "medic", "archer_support", 1},
    Card{"Etolian Auxiliary Archers", 73, DeckFaction::Nilfgaard, Row::Ranged, 1, "medic", "archer_support_1", 1},
    Card{"Fringilla Vigo", 53, DeckFaction::Nilfgaard, Row::Ranged, 6, "", "fringilla", 1},
    Card{"Heavy Zerrikanian Fire Scorpion", 49, DeckFaction::Nilfgaard, Row::Siege, 10, "", "heavy_zerri", 1},
    Card{"Impera Brigade Guard", 67, DeckFaction::Nilfgaard, Row::Close, 3, "bond", "imperal_brigade", 4},
    Card{"Letho of Gulet", 147, DeckFaction::Nilfgaard, Row::Close, 10, "hero", "letho", 1},
    Card{"Menno Coehoorn", 148, DeckFaction::Nilfgaard, Row::Close, 10, "hero medic", "menno", 1},
    Card{"Morteisen", 64, DeckFaction::Nilfgaard, Row::Close, 3, "", "morteisen", 1},
    Card{"Morvran Voorhis", 149, DeckFaction::Nilfgaard, Row::Siege, 10, "hero", "moorvran", 1},
    Card{"Nausicaa Cavalry Rider", 71, DeckFaction::Nilfgaard, Row::Close, 2, "bond", "nauzicaa_2", 3},
    Card{"Puttkammer", 66, DeckFaction::Nilfgaard, Row::Ranged, 3, "", "puttkammer", 1},
    Card{"Rainfarn", 61, DeckFaction::Nilfgaard, Row::Close, 4, "", "rainfarn", 1},
    Card{"Renuald aep Matsen", 56, DeckFaction::Nilfgaard, Row::Ranged, 5, "", "renuald", 1},
    Card{"Rotten Mangonel", 65, DeckFaction::Nilfgaard, Row::Siege, 3, "", "rotten", 1},
    Card{"Shilard Fitz-Oesterlen", 51, DeckFaction::Nilfgaard, Row::Close, 7, "spy", "shilard", 1},
    Card{"Siege Engineer", 55, DeckFaction::Nilfgaard, Row::Siege, 6, "", "siege_engineer", 1},
    Card{"Siege Technician", 74, DeckFaction::Nilfgaard, Row::Siege, 0, "medic", "siege_support", 1},
    Card{"Stefan Skellen", 50, DeckFaction::Nilfgaard, Row::Close, 9, "spy", "stefan", 1},
    Card{"Sweers", 69, DeckFaction::Nilfgaard, Row::Ranged, 2, "", "sweers", 1},
    Card{"Tibor Eggebracht", 150, DeckFaction::Nilfgaard, Row::Ranged, 10, "hero", "tibor", 1},
    Card{"Vanhemar", 62, DeckFaction::Nilfgaard, Row::Ranged, 4, "", "vanhemar", 1},
    Card{"Vattier de Rideaux", 63, DeckFaction::Nilfgaard, Row::Close, 4, "spy", "vattier", 1},
    Card{"Vreemde", 70, DeckFaction::Nilfgaard, Row::Close, 2, "", "vreemde", 1},
    Card{"Young Emissary", 58, DeckFaction::Nilfgaard, Row::Close, 5, "bond", "young_emissary", 1},
    Card{"Young Emissary", 59, DeckFaction::Nilfgaard, Row::Close, 5, "bond", "young_emissary_1", 1},
    Card{"Zerrikanian Fire Scorpion", 57, DeckFaction::Nilfgaard, Row::Siege, 5, "", "zerri", 1},
    Card{"Eredin - Commander of the Red Riders", 134, DeckFaction::Monsters, Row::Leader, 0, "eredin_commander", "eredin_silver", 1},
    Card{"Eredin - Bringer of Death", 136, DeckFaction::Monsters, Row::Leader, 0, "eredin_bringer_of_death", "eredin_bronze", 1},
    Card{"Eredin - Destroyer of Worlds", 137, DeckFaction::Monsters, Row::Leader, 0, "eredin_destroyer", "eredin_gold", 1},
    Card{"Eredin - King of the Wild Hunt", 135, DeckFaction::Monsters, Row::Leader, 0, "eredin_king", "eredin_copper", 1},
    Card{"Eredin Bréacc Glas - The Treacherous", 0, DeckFaction::Monsters, Row::Leader, 0, "eredin_treacherous", "eredin_the_treacherous", 1},
    Card{"Arachas", 27, DeckFaction::Monsters, Row::Close, 4, "muster", "arachas", 1},
    Card{"Arachas", 28, DeckFaction::Monsters, Row::Close, 4, "muster", "arachas_1", 1},
    Card{"Arachas", 29, DeckFaction::Monsters, Row::Close, 4, "muster", "arachas_2", 1},
    Card{"Arachas- Behemoth", 15, DeckFaction::Monsters, Row::Siege, 6, "muster", "arachas_behemoth", 1},
    Card{"Botchling", 26, DeckFaction::Monsters, Row::Close, 4, "", "poroniec", 1},
    Card{"Celaeno Harpy", 38, DeckFaction::Monsters, Row::Agile, 2, "", "celaeno_harpy", 1},
    Card{"Cockatrice", 36, DeckFaction::Monsters, Row::Ranged, 2, "", "cockatrice", 1},
    Card{"Crone - Brewess", 16, DeckFaction::Monsters, Row::Close, 6, "muster", "witch_velen", 1},
    Card{"Crone - Weavess", 17, DeckFaction::Monsters, Row::Close, 6, "muster", "witch_velen_1", 1},
    Card{"Crone - Whispess", 18, DeckFaction::Monsters, Row::Close, 6, "muster", "witch_velen_2", 1},
    Card{"Draug", 143, DeckFaction::Monsters, Row::Close, 10, "hero", "draug", 1},
    Card{"Earth Elemental", 12, DeckFaction::Monsters, Row::Siege, 6, "", "earth_elemental", 1},
    Card{"Endrega", 34, DeckFaction::Monsters, Row::Ranged, 2, "", "endrega", 1},
    Card{"Fiend", 13, DeckFaction::Monsters, Row::Close, 6, "", "fiend", 1},
    Card{"Fire Elemental", 14, DeckFaction::Monsters, Row::Siege, 6, "", "fire_elemental", 1},
    Card{"Foglet", 39, DeckFaction::Monsters, Row::Close, 2, "", "fogling", 1},
    Card{"Forktail", 19, DeckFaction::Monsters, Row::Close, 5, "", "forktail", 1},
    Card{"Frightener", 23, DeckFaction::Monsters, Row::Close, 5, "", "frightener", 1},
    Card{"Gargoyle", 37, DeckFaction::Monsters, Row::Ranged, 2, "", "gargoyle", 1},
    Card{"Ghoul", 44, DeckFaction::Monsters, Row::Close, 1, "muster", "ghoul", 1},
    Card{"Ghoul", 45, DeckFaction::Monsters, Row::Close, 1, "muster", "ghoul_1", 1},
    Card{"Ghoul", 46, DeckFaction::Monsters, Row::Close, 1, "muster", "ghoul_2", 1},
    Card{"Grave Hag", 25, DeckFaction::Monsters, Row::Ranged, 5, "", "gravehag", 1},
    Card{"Griffin", 21, DeckFaction::Monsters, Row::Close, 5, "", "gryffin", 1},
    Card{"Harpy", 35, DeckFaction::Monsters, Row::Agile, 2, "", "harpy", 1},
    Card{"Ice Giant", 24, DeckFaction::Monsters, Row::Siege, 5, "", "frost_giant", 1},
    Card{"Imlerith", 144, DeckFaction::Monsters, Row::Close, 10, "hero", "imlerith", 1},
    Card{"Kayran", 146, DeckFaction::Monsters, Row::Agile, 8, "hero morale", "kayran", 1},
    Card{"Leshen", 145, DeckFaction::Monsters, Row::Ranged, 10, "hero", "leshen", 1},
    Card{"Nekker", 41, DeckFaction::Monsters, Row::Close, 2, "muster", "nekker", 1},
    Card{"Nekker", 42, DeckFaction::Monsters, Row::Close, 2, "muster", "nekker_1", 1},
    Card{"Nekker", 43, DeckFaction::Monsters, Row::Close, 2, "muster", "nekker_2", 1},
    Card{"Plague Maiden", 20, DeckFaction::Monsters, Row::Close, 5, "", "mighty_maiden", 1},
    Card{"Vampire - Bruxa", 33, DeckFaction::Monsters, Row::Close, 4, "muster", "bruxa", 1},
    Card{"Vampire - Ekimmara", 30, DeckFaction::Monsters, Row::Close, 4, "muster", "ekkima", 1},
    Card{"Vampire - Fleder", 31, DeckFaction::Monsters, Row::Close, 4, "muster", "fleder", 1},
    Card{"Vampire - Garkain", 32, DeckFaction::Monsters, Row::Close, 4, "muster", "garkain", 1},
    Card{"Vampire - Katakan", 0, DeckFaction::Monsters, Row::Close, 5, "muster", "katakan", 1},
    Card{"Werewolf", 22, DeckFaction::Monsters, Row::Close, 5, "", "werewolf", 1},
    Card{"Wyvern", 40, DeckFaction::Monsters, Row::Ranged, 2, "", "wyvern", 1},
    Card{"Toad", 0, DeckFaction::Monsters, Row::Ranged, 7, "scorch_r", "toad", 1},
    Card{"Francesca Findabair - Queen of Dol Blathanna", 13, DeckFaction::Scoiatael, Row::Leader, 0, "francesca_queen", "francesca_silver", 1},
    Card{"Francesca Findabair - the Beautiful", 14, DeckFaction::Scoiatael, Row::Leader, 0, "francesca_beautiful", "francesca_gold", 1},
    Card{"Francesca Findabair - Daisy of the Valley", 15, DeckFaction::Scoiatael, Row::Leader, 0, "francesca_daisy", "francesca_copper", 1},
    Card{"Francesca Findabair - Pureblood Elf", 16, DeckFaction::Scoiatael, Row::Leader, 0, "francesca_pureblood", "francesca_bronze", 1},
    Card{"Francesca Findabair - Hope of the Aen Seidhe", 0, DeckFaction::Scoiatael, Row::Leader, 0, "francesca_hope", "francesca_hope_of_the_aen_seidhe", 1},
    Card{"Ciaran aep Easnillien", 122, DeckFaction::Scoiatael, Row::Agile, 3, "", "ciaran", 1},
    Card{"Barclay Els", 106, DeckFaction::Scoiatael, Row::Agile, 6, "", "barclay", 1},
    Card{"Dennis Cranmer", 102, DeckFaction::Scoiatael, Row::Close, 6, "", "dennis", 1},
    Card{"Dol Blathanna Archer", 121, DeckFaction::Scoiatael, Row::Ranged, 4, "", "dol_archer", 1},
    Card{"Dol Blathanna Scout", 107, DeckFaction::Scoiatael, Row::Agile, 6, "", "dol_infantry", 1},
    Card{"Dol Blathanna Scout", 108, DeckFaction::Scoiatael, Row::Agile, 6, "", "dol_infantry_1", 1},
    Card{"Dol Blathanna Scout", 109, DeckFaction::Scoiatael, Row::Agile, 6, "", "dol_infantry_2", 1},
    Card{"Dwarven Skirmisher", 123, DeckFaction::Scoiatael, Row::Close, 3, "muster", "dwarf", 1},
    Card{"Dwarven Skirmisher", 124, DeckFaction::Scoiatael, Row::Close, 3, "muster", "dwarf_1", 1},
    Card{"Dwarven Skirmisher", 125, DeckFaction::Scoiatael, Row::Close, 3, "muster", "dwarf_2", 1},
    Card{"Eithné", 17, DeckFaction::Scoiatael, Row::Ranged, 10, "hero", "eithne", 1},
    Card{"Elven Skirmisher", 127, DeckFaction::Scoiatael, Row::Ranged, 2, "muster", "elf_skirmisher", 1},
    Card{"Elven Skirmisher", 128, DeckFaction::Scoiatael, Row::Ranged, 2, "muster", "elf_skirmisher_1", 1},
    Card{"Elven Skirmisher", 129, DeckFaction::Scoiatael, Row::Ranged, 2, "muster", "elf_skirmisher_2", 1},
    Card{"Filavandrel aen Fidhail", 104, DeckFaction::Scoiatael, Row::Agile, 6, "", "filavandrel", 1},
    Card{"Havekar Healer", 131, DeckFaction::Scoiatael, Row::Ranged, 0, "medic", "havekar_nurse", 1},
    Card{"Havekar Healer", 132, DeckFaction::Scoiatael, Row::Ranged, 0, "medic", "havekar_nurse_1", 1},
    Card{"Havekar Healer", 133, DeckFaction::Scoiatael, Row::Ranged, 0, "medic", "havekar_nurse_2", 1},
    Card{"Havekar Smuggler", 110, DeckFaction::Scoiatael, Row::Close, 5, "muster", "havekar_support", 1},
    Card{"Havekar Smuggler", 111, DeckFaction::Scoiatael, Row::Close, 5, "muster", "havekar_support_1", 1},
    Card{"Havekar Smuggler", 112, DeckFaction::Scoiatael, Row::Close, 5, "muster", "havekar_support_2", 1},
    Card{"Ida Emean aep Sivney", 103, DeckFaction::Scoiatael, Row::Ranged, 6, "", "ida", 1},
    Card{"Iorveth", 20, DeckFaction::Scoiatael, Row::Ranged, 10, "hero", "iorveth", 1},
    Card{"Isengrim Faoiltiarna", 19, DeckFaction::Scoiatael, Row::Close, 10, "hero morale", "isengrim", 1},
    Card{"Mahakaman Defender", 115, DeckFaction::Scoiatael, Row::Close, 5, "", "mahakam", 1},
    Card{"Mahakaman Defender", 116, DeckFaction::Scoiatael, Row::Close, 5, "", "mahakam_1", 1},
    Card{"Mahakaman Defender", 117, DeckFaction::Scoiatael, Row::Close, 5, "", "mahakam_2", 1},
    Card{"Mahakaman Defender", 118, DeckFaction::Scoiatael, Row::Close, 5, "", "mahakam_3", 1},
    Card{"Mahakaman Defender", 119, DeckFaction::Scoiatael, Row::Close, 5, "", "mahakam_4", 1},
    Card{"Milva", 101, DeckFaction::Scoiatael, Row::Ranged, 10, "morale", "milva", 1},
    Card{"Riordain", 130, DeckFaction::Scoiatael, Row::Ranged, 1, "", "riordain", 1},
    Card{"Saesenthessis", 18, DeckFaction::Scoiatael, Row::Ranged, 10, "hero", "saskia", 1},
    Card{"Toruviel", 126, DeckFaction::Scoiatael, Row::Ranged, 2, "", "toruviel", 1},
    Card{"Vrihedd Brigade Recruit", 120, DeckFaction::Scoiatael, Row::Ranged, 4, "", "vrihedd_cadet", 1},
    Card{"Vrihedd Brigade Veteran", 113, DeckFaction::Scoiatael, Row::Agile, 5, "", "vrihedd_brigade", 1},
    Card{"Vrihedd Brigade Veteran", 114, DeckFaction::Scoiatael, Row::Agile, 5, "", "vrihedd_brigade_1", 1},
    Card{"Yaevinn", 105, DeckFaction::Scoiatael, Row::Agile, 6, "", "yaevinn", 1},
    Card{"Berserker", 0, DeckFaction::Skellige, Row::Close, 4, "berserker", "berserker", 1},
    Card{"Birna Bran", 0, DeckFaction::Skellige, Row::Close, 2, "medic", "birna", 1},
    Card{"Blueboy Lugos", 0, DeckFaction::Skellige, Row::Close, 6, "", "blueboy", 1},
    Card{"Cerys", 0, DeckFaction::Skellige, Row::Close, 10, "hero muster", "cerys", 1},
    Card{"Clan Brokva Archer", 0, DeckFaction::Skellige, Row::Ranged, 6, "", "brokva_archer", 2},
    Card{"Clan Dimun Pirate", 0, DeckFaction::Skellige, Row::Ranged, 6, "scorch", "dimun_pirate", 1},
    Card{"Clan Drummond Shield Maiden", 0, DeckFaction::Skellige, Row::Close, 4, "bond", "shield_maiden", 1},
    Card{"Clan Drummond Shield Maiden", 0, DeckFaction::Skellige, Row::Close, 4, "bond", "shield_maiden_1", 1},
    Card{"Clan Drummond Shield Maiden", 0, DeckFaction::Skellige, Row::Close, 4, "bond", "shield_maiden_2", 1},
    Card{"Clan Heymaey Skald", 0, DeckFaction::Skellige, Row::Close, 4, "", "heymaey", 1},
    Card{"Clan Tordarroch Armorsmith", 0, DeckFaction::Skellige, Row::Close, 4, "", "tordarroch", 1},
    Card{"Clan an Craite Warrior", 0, DeckFaction::Skellige, Row::Close, 6, "bond", "craite_warrior", 3},
    Card{"Donar an Hindar", 0, DeckFaction::Skellige, Row::Close, 4, "", "donar", 1},
    Card{"Draig Bon-Dhu", 0, DeckFaction::Skellige, Row::Siege, 2, "horn", "draig", 1},
    Card{"Ermion", 0, DeckFaction::Skellige, Row::Ranged, 8, "hero mardroeme", "ermion", 1},
    Card{"Hemdall", 0, DeckFaction::Skellige, Row::Close, 11, "hero", "hemdall", 0},
    Card{"Hjalmar", 0, DeckFaction::Skellige, Row::Ranged, 10, "hero", "hjalmar", 1},
    Card{"Holger Blackhand", 0, DeckFaction::Skellige, Row::Siege, 4, "", "holger", 1},
    Card{"Kambi", 0, DeckFaction::Skellige, Row::Close, 0, "avenger_kambi", "kambi", 1},
    Card{"Light Longship", 0, DeckFaction::Skellige, Row::Ranged, 4, "muster", "light_longship", 3},
    Card{"Madman Lugos", 0, DeckFaction::Skellige, Row::Close, 6, "", "madmad_lugos", 1},
    Card{"Mardroeme", 0, DeckFaction::Special, Row::None, 0, "mardroeme", "mardroeme", 3},
    Card{"Olaf", 0, DeckFaction::Skellige, Row::Agile, 12, "morale", "olaf", 1},
    Card{"Skellige Storm", 0, DeckFaction::Weather, Row::None, 0, "rain fog", "storm", 3},
    Card{"Svanrige", 0, DeckFaction::Skellige, Row::Close, 4, "", "svanrige", 1},
    Card{"Transformed Vildkaarl", 0, DeckFaction::Skellige, Row::Close, 14, "morale", "vildkaarl", 0},
    Card{"Transformed Young Vildkaarl", 0, DeckFaction::Skellige, Row::Ranged, 8, "bond", "young_vildkaarl", 0},
    Card{"Udalryk", 0, DeckFaction::Skellige, Row::Close, 4, "", "udalryk", 1},
    Card{"War Longship", 0, DeckFaction::Skellige, Row::Siege, 6, "bond", "war_longship", 2},
    Card{"Young Berserker", 0, DeckFaction::Skellige, Row::Ranged, 2, "berserker", "young_berserker", 3},
    Card{"Crach an Craite", 0, DeckFaction::Skellige, Row::Leader, 0, "crach_an_craite", "crach_an_craite", 0},
    Card{"King Bran", 0, DeckFaction::Skellige, Row::Leader, 0, "king_bran", "king_bran", 0},
    Card{"Schirru", 0, DeckFaction::Scoiatael, Row::Siege, 8, "scorch_s", "schirru", 1},
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

static constexpr auto &g_realms_cards = faction_cards<DeckFaction::Realms>::value;
static_assert(faction_cards<DeckFaction::Realms>::size > 0);

}// namespace gwent

}// namespace r
