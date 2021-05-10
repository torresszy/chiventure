#ifndef QUESTS_STRUCTS_H
#define QUESTS_STRUCTS_H

// REMEMBER TO INCLUDE ANY ADDITIONAL RELEVANT FILES (NPC)
#include "game-state/item.h"
#include "common/common.h"
#include "common/utlist.h"
#include "npc/npc.h"

/*
 * This struct represents a passive mission.
 * 
 * A passive mission is one that the player does not
 * manually explore chiventure to acquire.
 *
 * Components:
 *  xp: integer list of xp milestones
 *  levels: integer list of level milestones
 *  health: integer list of health milestones
 */
typedef struct passive_mission{
    int *xp;
    int *levels;
    int *health;
} passive_mission_t;

/*
 * This struct represents an active mission.
 * 
 * An active mission is one that the player
 * has to explore chiventure to acquire. 
 *
 * Components:
 *  item_to_collect: an item to collect
 *  npc_to_meet: an npc to meet
 *  npc_to_kill: an npc to kill
 *  room_to_visit: a room to visit
 */
typedef struct active_mission {
    item_t *item_to_collect;
    npc_t *npc_to_meet;
    npc_t *npc_to_kill;
    room_t *room_to_visit;
} active_mission_t;

/*
 * This union represents a mission.
 * 
 * Components:
 *  a_mission: an active mission
 *  p_mission: a passive mission
 *
 */
typedef union mission {
    active_mission_t *a_mission;
    passive_mission_t *p_mission;
} mission_t;

/* 
 * This struct represents an achievement.
 * 
 * Components:
 *  mission: mission to be completed
 *  completed: bool for if achievement is completed
 */
typedef struct achievement {
    mission_t *mission;
    bool completed;     //0 is not completed, 1 is completed
} achievement_t;

/* 
 * This is a linked list struct of achievements.
 * 
 * Components:
 *  achievement: achievement in linked list
 *  next: rest of linked list of achievements
 */
typedef struct achievement_llist {
    achievement_t *achievement;
    struct achievement_llist *next;
} achievement_llist_t;

/* 
 * This struct represents a reward for completing a quest.
 *
 * Components:
 *  xp: an xp amount gained
 *  item: an item gained
 */
typedef struct reward{
   int xp;
   item_t *item;
} reward_t;

/*
 * This struct represents a skill requirement for a quest.
 *
 * Components:
 *  hp: health points 
 *  level: a number of levels gained
 */
typedef struct stat_req{
    int hp;
    int level;
} stat_req_t;

/* 
 * This is the hashable struct for a quest 
 * Elements:
 * quest_id: the id of the quest
 * achievement_list: linked list struct holding a list of
 *                   achievements that make up a quest
 * reward: reward of the quest is either experience, an item, or both
 * stat_req: stat requirement for the quest
 * status: -1: failed quest
 *          0: quest has not been started
 *          1: quest has been started but not completed
 *          2: quest has been completed
 */
typedef struct quest  {
    UT_hash_handle hh;
    long int quest_id;
    achievement_llist_t *achievement_list;
    reward_t *reward;
    stat_req_t *stat_req;
    int status;  
} quest_t;

/*
 * This typedef distinguishes between quest_t pointers
 * which are used to point to quest_t structs in the 
 * traditional sense and those which are used to hash
 * quest_t structs with the UTHASH macros as specified
 * in include/common
 */
typedef struct quest quest_hash_t;


#endif