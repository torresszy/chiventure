#include "npc/npc_action.h"
#include "npc/npc_game_action.h"

//******* see npc_game_action.h *******//
npc_action_t *get_npc_action(npc_t *npc, char* action_name)
{
    //TODO
    return NULL;
}

//******* see npc_game_action.h *******//
int possible_npc_action(npc_t *npc, char* action_name)
{
    //TODO
    return 0;
}

//******* see npc_game_action.h *******//
game_action_hash_t *get_all_actions(npc_t *npc)
{
    //TODO
    return NULL;
}

//******* see npc_game_action.h *******//
int add_npc_action_condition(npc_t *npc, game_action_t *action, item_t *cond_item, attribute_t *cond_attribute, attribute_value_t cond_value)
{
    //TODO
    return 0;
}

//******* see npc_game_action.h *******//
condition_t *npc_condition_new(npc_t *npc, attribute_t *attribute, attribute_value_t new_value)
{
    //TODO
    return NULL;
}

//******* see npc_game_action.h *******//
int all_npc_conditions_met(npc_t *npc, char* action_name)
{
    //TODO
    return 0;
}

//******* see npc_game_action.h *******//
int add_npc_action_effect(game_action_t *action, npc_t *npc, attribute_t *attribute, attribute_value_t new_value)
{
    //TODO
    return 0;
}

//******* see npc_game_action.h *******//
int do_all_npc_effects(npc_t *npc, char* action_name)
{
    //TODO
    return 0;
}