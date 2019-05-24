/*
 * Header file for wdl/yaml parsing functions and related utilities
 */

#ifndef INCLUDE_PARSE_H
#define INCLUDE_PARSE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "parser.h"


/* a doubly linked list of strings used to store the ids of objects;
 * used to check that room passages lead to valid rooms and the such
 */
typedef struct id_list
{
    char *id;
    struct id_list *prev;
    struct id_list *next;
} id_list_t;


/*
 * extract_objects()
 * extracts the a list of objects associated with an attribute of the primary object;
 * used to get a list of rooms, items, and players
 * note that this function will only return if it determines all the objects are valid
 *
 * Parameters:
 *  - obj: The document object
 *  - str: the attribute asssociated with the desired objects
 *
 * Returns:
 *  - a list of objects
 *  - null if attribute does not have associated objects, or if no such attribute exists
 */
attr_list_t *extract_objects(obj_t *obj, char *str);


/*
 * extract_ids()
 * gets the ids of a list of room, item, or player objects
 *
 * parameters:
 *  - ls: a list of rooms, items, or players
 *
 * returns:
 *  - a list of ids, more specifically, a doubly linked list of strings
 */
id_list_t *extract_ids(attr_list_t *ls);

/* Given a room id and the list of all items in a game returns
 * a list with all the items in that room */
attr_list_t* get_items_in_room(char* room_id, attr_list_t* all_items);

/*
 * get_item_actions()
 * gets a list of actions assoiciated with a given item
 *
 * parameters:
 *  - item: the item for which to get the actions
 *
 * returns:
 *  - a linked list of type-checked action attributes
 *  - a null if any of the actions are malformed
 */
attr_list_t *get_item_actions(obj_t *item);

#endif /* INCLUDE_PARSE_H */
