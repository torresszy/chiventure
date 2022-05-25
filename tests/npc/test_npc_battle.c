#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../include/battle/battle_test_utility.h"

/* Checks that npc_battle_new() properly mallocs and inits a new npc_battle
 * struct */
Test(npc_battle, new)
{
    npc_battle_t *npc_battle;

    stat_t *stats = create_enemy_stats1();
    move_t *moves = create_enemy_moves1();

    stat_changes_t *dagger_changes = stat_changes_new();
    dagger_changes->phys_atk = 20;
    dagger_changes->phys_def = 5;
    dagger_changes->hp = 0;                        
    battle_item_t *dagger = create_battle_item(1, "Dagger", "A hearty dagger sure to take your breath away... for good", dagger_changes,
                                20, true);

    npc_battle = npc_battle_new(100, stats, moves, BATTLE_AI_GREEDY, 
		                HOSTILE, 25, generate_npcbattle_test_class(), dagger,
                        NULL, NULL, NULL);

    cr_assert_not_null(npc_battle, "npc_battle_new() failed");

    cr_assert_eq(100, npc_battle->health,
                 "npc_battle_new() didn't set health");
    cr_assert_eq(stats, npc_battle->stats,
                 "npc_battle_new() didn't set stats");
    cr_assert_eq(moves, npc_battle->moves,
                 "npc_battle_new() didn't set moves");
    cr_assert_eq(BATTLE_AI_GREEDY, npc_battle->ai,
                 "npc_battle_new() didn't set ai");
    cr_assert_eq(HOSTILE, npc_battle->hostility_level,
                 "npc_battle_new() didn't set hostility_level");
    cr_assert_eq(25, npc_battle->surrender_level,
                 "npc_battle_new() didn't set surrender_level");
}

/* Checks that npc_battle_init() initialized the fields in the new npc_battle
 * struct */
Test(npc_battle, init)
{
    npc_battle_t *npc_battle;

    stat_t *stats1 = create_enemy_stats1();
    move_t *moves1 = create_enemy_moves1();
    stat_t *stats2 = create_enemy_stats2();
    move_t *moves2 = create_enemy_moves2();

    stat_changes_t *dagger_changes = stat_changes_new();
    dagger_changes->phys_atk = 20;
    dagger_changes->phys_def = 5;
    dagger_changes->hp = 0;                        
    battle_item_t *dagger = create_battle_item(1, "Dagger", "A hearty dagger sure to take your breath away... for good", dagger_changes,
                                20, true);

    npc_battle = npc_battle_new(100, stats1, moves1, BATTLE_AI_GREEDY,
                                HOSTILE, 25, generate_npcbattle_test_class(),
                                dagger, NULL, NULL, NULL);
    cr_assert_not_null(npc_battle, "npc_battle_new() failed");

    int res = npc_battle_init(npc_battle, 5, stats2, moves2, BATTLE_AI_NONE,
		                FRIENDLY, 0, generate_npcbattle_test_class(), dagger,
                        NULL, NULL, NULL);

    cr_assert_eq(res, SUCCESS, "npc_battle_init() failed");

    cr_assert_eq(5, npc_battle->health,
                 "npc_battle_init() didn't initialize health");
    cr_assert_eq(stats2, npc_battle->stats,
                 "npc_battle_init() didn't initialize stats");
    cr_assert_eq(moves2, npc_battle->moves,
                 "npc_battle_init() didn't initialize moves");
    cr_assert_eq(BATTLE_AI_NONE, npc_battle->ai,
                 "npc_battle_init() didn't initialize ai");
    cr_assert_eq(FRIENDLY, npc_battle->hostility_level,
                 "npc_battle_init() didn't initialize hostility_level");
    cr_assert_eq(0, npc_battle->surrender_level,
                 "npc_battle_init() didn't initialize surrender_level");
}


/* Checks that npc_free() frees the given npc struct from memory */
Test(npc_battle, free)
{
    npc_battle_t *npc_battle;

    stat_t *stats = create_enemy_stats1();
    move_t *moves = create_enemy_moves1();

    stat_changes_t *dagger_changes = stat_changes_new();
    dagger_changes->phys_atk = 20;
    dagger_changes->phys_def = 5;
    dagger_changes->hp = 0;                        
    battle_item_t *dagger = create_battle_item(1, "Dagger", "A hearty dagger sure to take your breath away... for good", dagger_changes,
                                20, true);

    npc_battle = npc_battle_new(100, stats, moves, BATTLE_AI_GREEDY,
                                HOSTILE, 25, generate_npcbattle_test_class(),
                                dagger, NULL, NULL, NULL);

    cr_assert_not_null(npc_battle, "npc_battle_new() failed");

    int res = npc_battle_free(npc_battle);

    cr_assert_eq(res, SUCCESS, "npc_battle_free() failed");

}


/* Checks that transfer_all_npc_items() removes items from a dead npc and
   transfers them to the room */
Test(npc_battle, transfer_all_npc_items_dead)
{
    npc_t *npc = npc_new("npc", "short", "long", NULL, NULL, true);
    stat_t *stats = create_enemy_stats1();
    move_t *moves = create_enemy_moves1();
    item_t *test_item1 = item_new("item1", "short", "long");
    item_t *test_item2 = item_new("item2", "short", "long");
    item_t *test_item3 = item_new("item3", "short", "long");
    room_t *room = room_new("test_room", "room for testing",
                            "testing if memory is correctly allocated for new rooms");

    cr_assert_not_null(npc, "npc_new() failed");
    cr_assert_not_null(test_item1, "item_new() 1 failed");
    cr_assert_not_null(test_item2, "item_new() 2 failed");
    cr_assert_not_null(test_item3, "item_new() 3 failed");
    cr_assert_not_null(room, "room_new() failed");

    stat_changes_t *dagger_changes = stat_changes_new();
    dagger_changes->phys_atk = 20;
    dagger_changes->phys_def = 5;
    dagger_changes->hp = 0;                        
    battle_item_t *dagger = npc_create_battle_item(1, "Dagger", "A hearty dagger sure to take your breath away... for good", dagger_changes,
                                20, true);

    add_battle_to_npc(npc, 0, stats, moves, BATTLE_AI_GREEDY, HOSTILE,
            25, generate_npcbattle_test_class(), dagger, NULL, NULL, NULL);
    add_item_to_npc(npc, test_item1);
    add_item_to_npc(npc, test_item2);
    add_item_to_npc(npc, test_item3);

    item_hash_t *actual = NULL;
    add_item_to_hash(&actual, test_item1);
    add_item_to_hash(&actual, test_item2);
    add_item_to_hash(&actual, test_item3);

    cr_assert_not_null(npc->npc_battle, "add_battle_to_npc() failed");
    cr_assert_not_null(npc->inventory, "add_item_to_npc() failed to add item");
    cr_assert_not_null(actual, "add_item_to_hash() failed to add items");

    int rc = transfer_all_npc_items(npc, room);

    cr_assert_eq(rc, SUCCESS, "transfer_all_npc_items() failed");
    cr_assert_eq(actual, room->items,
                 "transfer_all_npc_items() failed to add room items");
    cr_assert_null(npc->inventory,
                   "transfer_all_npc_items() failed to remove npc items");

}

/* Checks that transfer_all_npc_items() does not remove items from a living npc
   and transfer them to the room */
Test(npc_battle, transfer_all_npc_items_alive)
{
    npc_t *npc = npc_new("npc", "short", "long", NULL, NULL, true);
    stat_t *stats = create_enemy_stats1();
    move_t *moves = create_enemy_moves1();
    item_t *test_item1 = item_new("item1", "short", "long");
    item_t *test_item2 = item_new("item2", "short", "long");
    item_t *test_item3 = item_new("item3", "short", "long");
    room_t *room = room_new("test_room", "room for testing",
                            "testing if memory is correctly allocated for new rooms");

    cr_assert_not_null(npc, "npc_new() failed");
    cr_assert_not_null(test_item1, "item_new() 1 failed");
    cr_assert_not_null(test_item2, "item_new() 2 failed");
    cr_assert_not_null(test_item3, "item_new() 3 failed");
    cr_assert_not_null(room, "room_new() failed");

    stat_changes_t *dagger_changes = stat_changes_new();
    dagger_changes->phys_atk = 20;
    dagger_changes->phys_def = 5;
    dagger_changes->hp = 0;                        
    battle_item_t *dagger = create_battle_item(1, "Dagger", "A hearty dagger sure to take your breath away... for good", dagger_changes,
                                20, true);

    add_battle_to_npc(npc, 100, stats, moves, BATTLE_AI_GREEDY, HOSTILE,
            25, generate_npcbattle_test_class(), dagger, NULL, NULL, NULL);
    add_item_to_npc(npc, test_item1);
    add_item_to_npc(npc, test_item2);
    add_item_to_npc(npc, test_item3);

    item_hash_t *actual = NULL;
    add_item_to_hash(&actual, test_item1);
    add_item_to_hash(&actual, test_item2);
    add_item_to_hash(&actual, test_item3);

    cr_assert_not_null(npc->npc_battle, "add_battle_to_npc() failed");
    cr_assert_not_null(npc->inventory, "add_item_to_npc() failed to add items");
    cr_assert_not_null(actual, "add_item_to_hash() failed to add items");

    int rc = transfer_all_npc_items(npc, room);

    cr_assert_eq(rc, FAILURE, "transfer_all_npc_items() transferred items");
    cr_assert_null(room->items,
                   "transfer_all_npc_items() added room items");
    cr_assert_eq(actual, npc->inventory,
                 "transfer_all_npc_items() removed npc items");

}

/* Checks that transfer_all_npc_items() works when the npc has an empty
   inventory */
Test(npc_battle, transfer_all_npc_items_empty_inventory)
{
    npc_t *npc = npc_new("npc", "short", "long", NULL, NULL, true);
    stat_t *stats = create_enemy_stats1();
    move_t *moves = create_enemy_moves1();
    room_t *room = room_new("test_room", "room for testing",
                            "testing if memory is correctly allocated for new rooms");

    cr_assert_not_null(npc, "npc_new() failed");
    cr_assert_not_null(room, "room_new() failed");

    stat_changes_t *dagger_changes = stat_changes_new();
    dagger_changes->phys_atk = 20;
    dagger_changes->phys_def = 5;
    dagger_changes->hp = 0;                        
    battle_item_t *dagger = create_battle_item(1, "Dagger", "A hearty dagger sure to take your breath away... for good", dagger_changes,
                                20, true);

    add_battle_to_npc(npc, 0, stats, moves, BATTLE_AI_GREEDY, HOSTILE,
            25, generate_npcbattle_test_class(), dagger, NULL, NULL, NULL);

    cr_assert_not_null(npc->npc_battle, "add_battle_to_npc() failed");
    cr_assert_null(npc->inventory, "npc->inventory not NULL");

    int rc = transfer_all_npc_items(npc, room);

    cr_assert_eq(rc, SUCCESS, "transfer_all_npc_items() failed");
    cr_assert_null(room->items,
                   "transfer_all_npc_items() added room items");
    cr_assert_null(npc->inventory,
                   "transfer_all_npc_items() still has npc items");

}
