#ifndef _NPC_H
#define _NPC_H

#include "action_management/action_structs.h"
#include "game-state/game_state_common.h"
#include "game-state/item.h"
#include "game-state/player.h"
#include "playerclass/class_structs.h"
#include "playerclass/class.h"
#include "npc/dialogue.h"
#include "npc/npc_battle.h"
#include "npc/npc_move.h"
#include "npc/npc_quests.h"
#include "cli/util.h"


// NPC STRUCTURE DEFINITION ---------------------------------------------------
/* A non-playable character in game */
typedef struct npc {
    /* hh is used for hashtable, as provided in uthash.h */
    /* Second hash handle is for storing npcs in specific rooms */
    UT_hash_handle hh, hh_room;

    /* NPC identifier */
    char *npc_id;

    /* short description of the NPC, <51 chars */
    char *short_desc;

    /* long description of the NPC, <301 chars */
    char *long_desc;

    /* pointer to existing convo struct; changed depending on whether
    npc has activated quest or task convo */
    convo_t *active_dialogue;

    /* pointer to an existing convo struct; for normal dialogue */
    convo_t *standard_dialogue;

    /* pointer to inventory hashtable */
    item_hash_t *inventory;

    /* pointer to an existing class struct */
    class_t *class;

    /* pointer to an existing npc_move struct */
    npc_mov_t *movement;

    /* enum indicating hostility level of the npc */
    hostility_t hostility_level;

    /* either NULL or a pointer to an existing npc_battle struct */
    npc_battle_t *npc_battle;

    /* linked list of all possible actions the player can initiate with the npc */
    list_action_t *npc_actions;

    /* pointer to a quest with dialogue */
    npc_quest_list_t *quests;

    /* pointer to a task with dialogue */
    npc_task_list_t *tasks;
    
    /* pointer to game_action hashtable */
    game_action_hash_t *actions;
} npc_t;

/* Agent: a struct of things that you can perform actions upon
 * - item: an item
 * - npc: an NPC
 */
typedef struct agent
{
   item_t *item;
   npc_t *npc;
} agent_t;

enum agent_tag {ITEMS, NPCS};

// ACTION STRUCTURE DEFINITION + BASIC FUNCTIONS ------------------------------
typedef struct game_action_effect{
    enum agent_tag agent_tag;
    agent_t *agent;
    attribute_t *attribute_to_modify;
    attribute_value_t *new_value;
    struct game_action_effect *next; //mandatory for utlist macros
} game_action_effect_t;

/* This typedef is to distinguish between game_action_effect_t
 * pointers which are used to point to the game_action_effect_t structs
 * in the traditional sense, and those which are used to enable UTLIST functionality
 * on the game_action_effect_t structs as specified in src/common/include */
typedef struct game_action_effect action_effect_list_t;


typedef struct game_action {
    UT_hash_handle hh;
    char* action_name;
    condition_list_t *conditions; //must be initialized to NULL
    action_effect_list_t *effects; //must be initialized to NULL
    char* success_str;
    char* fail_str;
} game_action_t;

/* This typedef is to distinguish between npc_t pointers which are
 * used to point to the npc_t structs in the traditional sense,
 * and those which are used to hash npc_t structs with the
 * UTHASH macros as specified in src/common/include */
typedef struct npc npc_hash_t;


// STRUCT FUNCTIONS -----------------------------------------------------------
/*
 * Initializes an npc with the given parameters.
 *
 * Parameters:
 *  npc: an npc; must point to already allocated memory
 *  npc_id: unique string ID of npc
 *  short_desc: description of npc <51 chars
 *  long_desc: description of npc <301 chars
 *  standard_dialogue: a pointer to an existing convo_t struct defining the
                       npc's conversations (non quest/task-related)
                       (see /include/npc/dialogue.h)
 *  inventory: a pointer to an existing item_hash_t struct defining the npc's
 *             inventory (see /include/game-state/item.h)
 *  class: a pointer to an existing class_t struct defining the npc's class
           (see /include/playerclass/class_structs.h)
 *  hostility_level: an enum indicating the npc's hostility level
                    (see /include/npc/npc_battle.h)
 * 
 * Returns:
 *  SUCCESS on success, FAILURE if an error occurs
 */
int npc_init(npc_t *npc, char *npc_id, char *short_desc, char *long_desc,
             class_t *class, npc_mov_t *movement, hostility_t hostility_level);

/*
 * Allocates a new npc in the heap.
 *
 * Parameters:
 *  npc_id: unique string ID of npc
 *  short_desc: description of npc <51 chars
 *  long_desc: description of npc <301 chars
 *  standard_dialogue: a pointer to an existing convo_t struct defining the
 *                     npc's conversations (non-quest/task-related) 
 *                     (see /include/npc/dialogue.h)
 *  inventory: a pointer to an existing item_hash_t struct defining the npc's
 *             inventory (see /include/game-state/item.h)
 *  class: a pointer to an existing class_t struct defining the npc's class
           (see /include/playerclass/class_structs.h)
 *  hostility_level: an enum indicating the npc's hostility level
                    (see /include/npc/npc_battle.h)
 *
 * Returns:
 *  pointer to allocated npc
 */
npc_t *npc_new(char *npc_id, char *short_desc, char *long_desc,
               class_t *class, npc_mov_t *movement, hostility_t hostility_level);

/*
 * Frees resources associated with an npc.
 *
 * Parameters:
 *  npc: the npc to be freed
 *
 * Returns:
 *  SUCCESS if successful, FAILURE if an error occurs
 */
int npc_free(npc_t *npc);

// "CHECK" FUNCTIONS ----------------------------------------------------------

/*
 * Checks if an npc's npc_battle struct is set correctly.
 *
 * Parameters:
 *  npc: the npc
 *
 * Returns:
 *  true if:
 *   - the npc's hostility_level is HOSTILE and its npc_battle is not NULL
 *   - the npc's hostility_level is FRIENDLY and its npc_battle is NULL
 *   - note: since CONDITIONAL FRIENDLY npcs can fight under certain
 *           circumstances, its npc_batle could be not NULL
 *  and false otherwise
 */
bool check_npc_battle(npc_t *npc);

/*
 * Checks if an item is in the NPC's inventory.
 *
 * Parameters:
 *  npc: the npc
 *  item_id: the item's ID
 *
 * Returns:
 *  true if the item is in the NPC's inventory, false otherwise
 */
bool item_in_npc_inventory(npc_t *npc, char *item_id);

/* Checks if an indefinite npc needs moved based on how long it's been in its
 * current room
 *
 * Parameters:
 *  - npc: The NPC struct
 * 
 * Returns:
 *  - true if the npc does need to be moved
 *  - false if the npc does not need to be moved,
 *      or the npc has a definite movement path
 */
bool check_if_npc_indefinite_needs_moved(npc_t *npc);

// "GET" FUNCTIONS ------------------------------------------------------------
/*
 * Gets a quest with a specific id
 * 
 * Parameters:
 * - npc: the npc
 * - quest_id: the quest's id
 * 
 * Returns:
 * - the quest if present, else NULL
*/
npc_quest_t *get_npc_quest(npc_t *npc, char *quest_id);

/*
 * Gets a task with a specific id
 * 
 * Parameters:
 * - npc: the npc
 * - task_id: the task's's id
 * 
 * Returns:
 * - the task if present, else NULL
*/
npc_task_t *get_npc_task(npc_t *npc, char *task_id);

/* 
 * Gets short description of npc.
 *
 * Parameters:
 *  npc: the npc
 *
 * Returns:
 *  short description string, NULL if npc is NULL
 */
char *get_sdesc_npc(npc_t *npc);

/* 
 * Gets long description of npc.
 *
 * Parameters:
 *  npc: the npc
 *
 * Returns:
 *  long description string, NULL if npc is NULL
 */
char *get_ldesc_npc(npc_t *npc);

/* Function to return an item in an NPC's inventory given the item_id
 *
 * Parameters:
 *  npc: the npc
 *  item_id: the item_id of the item that you want to be returned
 *
 * Returns:
 *  a pointer to the item that matches the input item_id, or NULL if nonexistent
 */
 item_t *get_item_from_npc(npc_t *npc, char *item_id);

/*
 * Function to get a hashtable (uthash) of all items in the npc's inventory.
 *
 * Parameters:
 *  npc: the npc
 *
 * Returns:
 *  hashtable of items, the inventory
 */
item_hash_t *get_npc_inv_hash(npc_t *npc);

/*
 * Function to get a linked list (utlist) of all items in the npc's inventory.
 *
 * Parameters:
 *  npc: the npc
 *
 * Returns:
 *  linked list of pointers to items (the head element)
 */
item_list_t *get_npc_inv_list(npc_t *npc);

/*
 * Function to get an npc's npc_battle struct if it isn't NULL.
 *
 * Parameters:
 *  npc: the npc
 *
 * Returns:
 *  a pointer to the npc's npc_battle struct or NULL
 */
npc_battle_t *get_npc_battle(npc_t *npc);

/*
 * Returns the max_hp level of an npc.
 *
 * Parameters:
 *  npc: the npc
 *
 * Returns:
 *  the npc's max_hp or -1 if its npc_battle field is NULL
 */
int get_npc_max_hp(npc_t *npc);

/*
 * Returns the hp level of an npc.
 *
 * Parameters:
 *  npc: the npc
 *
 * Returns:
 *  the npc's hp or -1 if its npc_battle field is NULL
 */
int get_npc_hp(npc_t *npc);

/*
* Function to get an npc's npc_mov struct or NULL
*
* Parameters:
*  npc: the npc
*
* Returns:
* a pointer to the npc's npc_mov struct or NULL
*/
npc_mov_t *get_npc_mov(npc_t *npc);

// "SET" FUNCTIONS ------------------------------------------------------------

/* 
 * Adds the given item to the given npc.
 *
 * Parameters:
 *  npc: the npc to receive the item
 *  item: the item
 *
 * Returns:
 *  SUCCESS if successful, FAILURE if an error occurred.
 */
int add_item_to_npc(npc_t *npc, item_t *item);

/* 
 * Removes the given item from the given npc.
 * Note that the memory associated with this item is not freed
 * 
 * Parameters:
 *  npc: the npc from whom to remove the item
 *  item: the item
 * 
 * Returns:
 *  SUCCESS if successful, FAILURE if an error occurred.
 */
int remove_item_from_npc(npc_t *npc, item_t *item);

/* Removes/Deletes all items in an NPCs inventory
 * 
 * Parameters:
 *  npc: the npc whose inventory we're deleting
 *
 * Returns:
 * SUCCESS upon completion
 */
int delete_all_items_from_npc(npc_t *npc);

/* Deletes and frees all items in an NPC's inventory
 * 
 * Parameters:
 *  npc: the npc whose inventory we're deleting and freeing
 *
 * Returns:
 *  SUCCESS upon completion
 */
int free_all_items_from_npc(npc_t *npc);

/*
 * Adds the given convo to the given npc's standard_dialogue
 * 
 * Parameters:
 *  npc: the npc to receive the convo
 *  c: the convo
 * 
 * Returns:
 *  SUCCESS if successful, FAILURE if an error occurred.
 */
int add_convo_to_npc(npc_t *npc, convo_t *c); 

/*
 * Adds an npc_battle struct to a given npc.
 *
 * Parameters:
 *  npc: the npc to receive the npc_battle struct
 *  stats: a pointer to an existing stat_t struct defining the npc's battle
           stats (see /include/battle/battle_structs.h)
 *  moves: a pointer to an existing move_t struct defining the npc's battle
           moves (see /include/battle/battle_structs.h)
 *  ai: the npc's difficulty level (see /include/battle/battle_common.h)
 *  hostility_level: the npc's hostility level
 *  class_type: a pointer to an existing class_t struct defining the npc's class
           (see /include/playerclass/class_structs.h)
 *  items: An inventory of items that can be used in battle
 *  armor: a pointer to the armor an npc has
 *  accessory: a pointer to the accessory an npc has
 *  weapon: a pointer to the weapon an npc has
 * Returns:
 *  SUCCESS if successful, FAILURE if an error occurred.
 */
int add_battle_to_npc(npc_t *npc, stat_t *stats, move_t *moves,
                      difficulty_t ai, hostility_t hostility_level,
                      class_t *class_type, battle_item_t *items,
                      battle_equipment_t *armor,
                      battle_equipment_t *accessory, battle_equipment_t *weapon);

/*
 * Changes the hp level of the npc.
 *
 * Parameters:
 *  npc: the npc
 *  change: the positive or negative change to be made to the hp level
 *
 *  The change has a minimum value of 0
 *  The change has a maximum value of the npc's max_hp level
 *
 * Returns:
 *  the npc's new hp level
 */
int change_npc_hp(npc_t *npc, int change);

/* Moves an npc to the next room in their movement path
 *
 * Parameters:
 * npc: The NPC struct
 *
 * Returns:
 *  FAILURE: if a move does not occur, 
 *  SUCCESS: if successful move to the next room, with the only exception
 * being if an indefinite NPC has more than one room in its path, and then
 * reaches the end of its path, in which case its path direction is flipped,
 * and its time_ray for the current step in its path is reset, but it does not
 * technically change rooms.
 *
 */
int move_npc(npc_t *npc);

// HASH TABLE FUNCTIONS ---------------------------------------------------

/*
 * Deletes and frees the elements of a hashtable of NPCs.
 * Implemented with macros provided by uthash.h
 * 
 * Parameters:
 *  npcs: a hashtable of npcs to be deleted
 *
 * Returns:
 *  SUCCESS if successful, FAILURE if an error occurred.
 */
int delete_all_npcs(npc_hash_t *npcs);

/* Sets the npc's active dialogue to the proper dialogue
 * - This handles quest interaction, since NPCs can have different
 *   dialogue when giving quests or completing tasks
 * 
 * Parameters:
 * - qctx: A quest context containing a player and a hash of all quests in the game
 * - npc: An npc
 * 
 * Returns:
 * - SUCCESS on success, FAILURE if an error occurs
*/
int set_proper_dialogue(quest_ctx_t *qctx, npc_t *npc);

// Conversion FUNCTIONS ---------------------------------------------------

/*
 * converts hostility_level of an NPC to HOSTILE
 * 
 * Parameters:
 *  npc: the NPC whose hostility_level becomes HOSTILE
 *       (must point to already allocated memory)
 *
 * Returns:
 *  SUCCESS if successful, FAILURE if an error occurred.
 */
int make_npc_hostile(npc_t *npc);

/*
 * converts hostility_level of an NPC to CONDITIONAL_FRIENDLY
 * 
 * Parameters:
 *  npc: the NPC whose hostility_level becomes CONDITIONAL_FRIENDLY
 *       (must point to already allocated memory)
 *
 * Returns:
 *  SUCCESS if successful, FAILURE if an error occurred.
 */
int make_npc_cond_friendly(npc_t *npc);

/*
 * changes an NPC's hostility_level based on player's
 * tone at a conversation edge
 * ex. NEGATIVE tone makes NPC HOSTILE
 * 
 * NOTE FOR FUTURE IMPLEMENTATION:
 * when this function is called to make NPC HOSTILE,
 * it should call add_battle_to_npc() as well to
 * initialize the npc_battle_t struct in npc_t
 * and allow NPC to participate in battle
 * 
 * Parameters:
 *  npc: the NPC whose hostility_level changes
 *       (must point to already allocated memory)
 *  edge: the edge containing the tone_t struct that determines
 *        an NPC's hostility_level
 *        (must point to already allocated memory)
 *
 * Returns:
 *  SUCCESS if successful, FAILURE if an error occurred.
 */
int change_npc_hostility(npc_t *npc, edge_t *edge);


#endif /* _NPC_H */
