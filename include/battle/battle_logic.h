#ifndef BATTLE_LOGIC_H
#define BATTLE_LOGIC_H

#include <stdio.h>
#include <stdlib.h>
#include "battle/battle_state.h"
#include "battle/battle_structs.h"
#include "battle/battle_common.h"

/*
 * Checks the targets of a move to see if they exist and are targetable
 *
 * Parameters:
 * - b: information about the battle
 * - target: name of the person
 * Returns:
 * - Returns the combatant selected
 */
combatant_t *check_target(battle_t *b, char *target);

/*
 * Determines if a battle has reached its conclusion
 *
 * Parameters:
 * - b: information about the battle
 * Returns:
 *  A battle status based on the combatants of the battle
 */
battle_status_t battle_over(battle_t *b);

/* 
 * Function detemines if the battle_player goes first
 *
 *  Parameters: 
 *  - b: information about the battle
 *  Returns:
 *  PLAYER or ENEMY which shows who goes first
 */
turn_t goes_first(battle_t *b);

/* 
 * Finds the desired battle_item to be used
 * Parameters:
 *    inventory - a battle_player or enemy's inventory
 *    id - the id number of the desired battle_item
 * Returns:
 *    Returns a pointer to the desired battle_item 
 */
battle_item_t *find_battle_item(battle_item_t *inventory, int id);

/*
 * Consumes a battle_item for the said combatant
 * Parameters:
 *  c - information about the combatant
 *  item - the battle_item to be consumed
 * Returns:
 *  Always returns 0
 */
int consume_battle_item(combatant_t *c, battle_item_t *item);

/* Uses the battle_item with the given ID on the battle_player
 * ! Currently assumes that this is a battle_item !
 *
 *  Parameters: 
 *   c - combatant information
 *   id - the number id of the battle_item
 *  Returns:
 *   SUCCESS or FAILURE
 */
int use_battle_item(combatant_t *c,int id);

/* Awards xp to the battle_player 
 * Parameters:
 *  - stats: stats of the battle_player
 *  - xp: amount of xp to be rewarded
 * Returns:
 *  Always returns 0
 */
int award_xp(stat_t *stats, double xp);

#endif
