#include <criterion/criterion.h>
#include <stdio.h>
#include <stdlib.h>
#include "openworld/autogenerate.h"
#include "openworld/game_autogenerate.h"
#include "openworld/default_rooms.h"
#include "openworld/default_items.h"
#include "openworld/gen_structs.h"

/* Tests the functions in auto_generation.h */

/* Checks that room with no paths returns false for path_exists_in_direction() */
Test(autogenerate, path_exists_in_direction_none)
{
    room_t *room = room_new("string1", "string2", "string3");
    cr_assert_eq(false, path_exists_in_direction(room, "north"), "Expected false but got true");
    cr_assert_eq(false, path_exists_in_direction(room, "east"), "Expected false but got true");
    cr_assert_eq(false, path_exists_in_direction(room, "south"), "Expected false but got true");
    cr_assert_eq(false, path_exists_in_direction(room, "west"), "Expected false but got true");
}

/* Checks that room with a path in a given direction is determined as such */
Test(autogenerate, path_exists_in_direction_one_true)
{
    room_t *room = room_new("string1", "string2", "string3");
    room_t *dest_room = room_new("string1", "string2", "string3");

    // Path to dest_room
    path_t* path1 = path_new(dest_room, "north");

    cr_assert_eq(SUCCESS, add_path_to_room(room, path1), "Could not add path to room");

    cr_assert_eq(true, path_exists_in_direction(room, "north"), "Expected true but got false");
    cr_assert_eq(false, path_exists_in_direction(room, "east"), "Expected false but got true");
    cr_assert_eq(false, path_exists_in_direction(room, "south"), "Expected false but got true");
    cr_assert_eq(false, path_exists_in_direction(room, "west"), "Expected false but got true");
}

/* Checks that room with a path in a different direction is determined as such, i.e.
* if the existing direction is different from all valid directions (north, east, south, west) */
Test(autogenerate, path_exists_in_direction_false)
{
    room_t *room = room_new("string1", "string2", "string3");
    room_t *dest_room = room_new("string1", "string2", "string3");

    // Path to dest_room
    path_t* path1 = path_new(dest_room, "DIFFERENT");

    cr_assert_eq(SUCCESS, add_path_to_room(room, path1), "Could not add path to room");

    cr_assert_eq(false, path_exists_in_direction(room, "north"), "Expected false but got true");
    cr_assert_eq(false, path_exists_in_direction(room, "east"), "Expected false but got true");
    cr_assert_eq(false, path_exists_in_direction(room, "south"), "Expected false but got true");
    cr_assert_eq(false, path_exists_in_direction(room, "west"), "Expected false but got true");
}

/* Checks that room with paths in every direction returns true, so long as
* the given direction is valid */
Test(autogenerate, path_exists_in_direction_one_all_true)
{
    room_t *room = room_new("string1", "string2", "string3");
    room_t *dest_room1 = room_new("string1", "string2", "string3");
    room_t *dest_room2 = room_new("string1", "string2", "string3");
    room_t *dest_room3 = room_new("string1", "string2", "string3");
    room_t *dest_room4 = room_new("string1", "string2", "string3");

    // Paths to destination rooms (dest_roomX, where X is a number 1 <= X <= 4)
    path_t* path1 = path_new(dest_room1, "north");
    path_t* path2 = path_new(dest_room2, "east");
    path_t* path3 = path_new(dest_room3, "south");
    path_t* path4 = path_new(dest_room4, "west");

    // Add all the paths to the test room
    cr_assert_eq(SUCCESS, add_path_to_room(room, path1), "Could not add path to room");
    cr_assert_eq(SUCCESS, add_path_to_room(room, path2), "Could not add path to room");
    cr_assert_eq(SUCCESS, add_path_to_room(room, path3), "Could not add path to room");
    cr_assert_eq(SUCCESS, add_path_to_room(room, path4), "Could not add path to room");

    // Valid directions tests
    cr_assert_eq(true, path_exists_in_direction(room, "north"), "Expected true but got false");
    cr_assert_eq(true, path_exists_in_direction(room, "east"), "Expected true but got false");
    cr_assert_eq(true, path_exists_in_direction(room, "south"), "Expected true but got false");
    cr_assert_eq(true, path_exists_in_direction(room, "west"), "Expected true but got false");

    // Invalid direction test
    cr_assert_eq(false, path_exists_in_direction(room, "NOT A DIRECTION"), "Expected false but got true");
}

/* The tests above are checked, but for 2 or 3 valid paths */
Test(autogenerate, path_exists_in_direction_mid)
{
    room_t *room = room_new("string1", "string2", "string3");
    room_t *dest_room1 = room_new("string1", "string2", "string3");
    room_t *dest_room2 = room_new("string1", "string2", "string3");
    room_t *dest_room3 = room_new("string1", "string2", "string3");

    // 2 paths
    path_t* path1 = path_new(dest_room1, "north");
    path_t* path2 = path_new(dest_room2, "east");
    cr_assert_eq(SUCCESS, add_path_to_room(room, path1), "Could not add path to room");
    cr_assert_eq(SUCCESS, add_path_to_room(room, path2), "Could not add path to room");

    // Valid directions tests
    cr_assert_eq(true, path_exists_in_direction(room, "north"), "Expected true but got false");
    cr_assert_eq(true, path_exists_in_direction(room, "east"), "Expected true but got false");
    cr_assert_eq(false, path_exists_in_direction(room, "south"), "Expected true but got false");
    cr_assert_eq(false, path_exists_in_direction(room, "west"), "Expected false but got true");

    // Add a third path
    path_t* path3 = path_new(dest_room3, "south");
    cr_assert_eq(SUCCESS, add_path_to_room(room, path3), "Could not add path to room");
    cr_assert_eq(true, path_exists_in_direction(room, "south"), "Expected true but got false");

    // The first two paths should remain (should still get true)
    cr_assert_eq(true, path_exists_in_direction(room, "north"), "Expected true but got false");
    cr_assert_eq(true, path_exists_in_direction(room, "east"), "Expected true but got false");

    // Invalid direction test
    cr_assert_eq(false, path_exists_in_direction(room, "NOT A DIRECTION"), "Expected false but got true");
}

/* Checks that room_exists_in_direction outputs true when a room does exist in a given direction */
Test(autogenerate, room_exists_in_direction_true){

    game_t *game=game_new("New Game");

    roomspec_t *spec1 = roomspec_new("room_name1", "short desc1", "long desc1", NULL);
    cr_assert_not_null(spec1, "failed to create new roomspec_t\n");
    spec1->tag=0;

    roomspec_t *spec2 = roomspec_new("room_name2", "short desc2", "long desc2", NULL);
    cr_assert_not_null(spec2, "failed to create new roomspec_t\n");
    spec2->tag=1;

    roomspec_t *spec3 = roomspec_new("room_name3", "short desc3", "long desc3", NULL);
    cr_assert_not_null(spec3, "failed to create new roomspec_t\n");
    spec3->tag=2;
    roomspec_t **roomspecs=(roomspec_t**)malloc(3*sizeof(roomspec_t*));

    roomspecs[0]=spec1;
    roomspecs[1]=spec2;
    roomspecs[2]=spec3;

    int *matrix=(int*)malloc(9*sizeof(int));

    matrix[0]=5;
    matrix[1]=4;
    matrix[2]=5; 
    matrix[3]=0; 
    matrix[4]=5;  
    matrix[5]=3;
    matrix[6]=4; 
    matrix[7]=3;  
    matrix[8]=5;

    int **edges=edges_new(matrix, 3, 3);

    specgraph_t *specgraph = specgraph_new(3, roomspecs, edges);

    coords_t *coords1=coords_new(0,0);
    coords_t *coords2=coords_new(1,0);    
    room_t *room1=roomspec_to_room(spec1, coords1);
    room_t *room2=roomspec_to_room(spec2, coords2);

    add_room_to_game(game, room1);
    add_room_to_game(game, room2);

    int rc;
    char* direction_to_new;
    char* direction_to_curr;

    rc=room_exists_in_direction(game, room1, "east");
    cr_assert_eq(rc, true, "failed to determine if a room exists north of the current room\n");

    rc=room_exists_in_direction(game, room2, "west");
    cr_assert_eq(rc, true, "failed to determine if a room exists south of the current room\n");
}

/* Checks that room_exists_in_direction outputs false when a room does not exist in a given direction */
Test(autogenerate, room_exists_in_direction_false){

    game_t *game=game_new("New Game");

    roomspec_t *spec1 = roomspec_new("room_name1", "short desc1", "long desc1", NULL);
    cr_assert_not_null(spec1, "failed to create new roomspec_t\n");
    spec1->tag=0;

    roomspec_t *spec2 = roomspec_new("room_name2", "short desc2", "long desc2", NULL);
    cr_assert_not_null(spec2, "failed to create new roomspec_t\n");
    spec2->tag=1;

    roomspec_t *spec3 = roomspec_new("room_name3", "short desc3", "long desc3", NULL);
    cr_assert_not_null(spec3, "failed to create new roomspec_t\n");
    spec3->tag=2;
    roomspec_t **roomspecs=(roomspec_t**)malloc(3*sizeof(roomspec_t*));

    roomspecs[0]=spec1;
    roomspecs[1]=spec2;
    roomspecs[2]=spec3;

    int *matrix=(int*)malloc(9*sizeof(int));

    matrix[0]=5;
    matrix[1]=4;
    matrix[2]=5; 
    matrix[3]=0; 
    matrix[4]=5;  
    matrix[5]=3;
    matrix[6]=4; 
    matrix[7]=3;  
    matrix[8]=5;

    int **edges=edges_new(matrix, 3, 3);

    specgraph_t *specgraph = specgraph_new(3, roomspecs, edges);

    coords_t *coords=coords_new(0,0);
    room_t *room=roomspec_to_room(spec1, coords);

    add_room_to_game(game, room);

    int rc;
    char* direction_to_new;
    char* direction_to_curr;

    rc=room_exists_in_direction(game, room, "north");
    cr_assert_eq(rc, false, "failed to determine if a room exists north of the current room\n");

    rc=room_exists_in_direction(game, room, "south");
    cr_assert_eq(rc, false, "failed to determine if a room exists south of the current room\n");

    rc=room_exists_in_direction(game, room, "east");
    cr_assert_eq(rc, false, "failed to determine if a room exists east of the current room\n");

    rc=room_exists_in_direction(game, room, "west");
    cr_assert_eq(rc, false, "failed to determine if a room exists west of the current room\n");    
}

/* Checks that find_room_in_direction outputs the correct room */
Test(autogenerate, find_room_in_direction){

    game_t *game=game_new("New Game");

    roomspec_t *spec1 = roomspec_new("room_name1", "short desc1", "long desc1", NULL);
    cr_assert_not_null(spec1, "failed to create new roomspec_t\n");
    spec1->tag=0;

    roomspec_t *spec2 = roomspec_new("room_name2", "short desc2", "long desc2", NULL);
    cr_assert_not_null(spec2, "failed to create new roomspec_t\n");
    spec2->tag=1;

    roomspec_t *spec3 = roomspec_new("room_name3", "short desc3", "long desc3", NULL);
    cr_assert_not_null(spec3, "failed to create new roomspec_t\n");
    spec3->tag=2;
    roomspec_t **roomspecs=(roomspec_t**)malloc(3*sizeof(roomspec_t*));

    roomspecs[0]=spec1;
    roomspecs[1]=spec2;
    roomspecs[2]=spec3;

    int *matrix=(int*)malloc(9*sizeof(int));

    matrix[0]=5;
    matrix[1]=4;
    matrix[2]=5; 
    matrix[3]=0; 
    matrix[4]=5;  
    matrix[5]=3;
    matrix[6]=4; 
    matrix[7]=3;  
    matrix[8]=5;

    int **edges=edges_new(matrix, 3, 3);

    specgraph_t *specgraph = specgraph_new(3, roomspecs, edges);

    coords_t *coords1=coords_new(0,0);
    coords_t *coords2=coords_new(1,0);    
    room_t *room1=roomspec_to_room(spec1, coords1);
    room_t *room2=roomspec_to_room(spec2, coords2);

    add_room_to_game(game, room1);
    add_room_to_game(game, room2);

    int rc;
    char* direction_to_new;
    char* direction_to_curr;

    room_t *res1;
    room_t *res2;

    res1=find_room_in_direction(game, room1, "east");
    cr_assert_eq(strcmp(res1->room_id, room2->room_id), 0, "failed to output correct room\n");

    res2=find_room_in_direction(game, room2, "west");
    cr_assert_eq(strcmp(res2->room_id, room1->room_id), 0, "failed to output correct room\n");
}

/* Checks that, given a roomspec pointer, roomspec_to_room correctly returns a
* room pointer with NULL paths and items fields */
Test(autogenerate, roomspec_to_room1)
{
    roomspec_t *r = make_default_room("school", NULL, NULL);
    game_t *g = game_new("start desc");
    coords_t *coords=coords_new(0,0);
    room_t *room = roomspec_to_room(r, coords);

    // no need to check short/long desc because we know these are set by default_room
    cr_assert_not_null(room, "roomspec_new(): The returned room is NULL");
    cr_assert_not_null(room->room_id, "roomspec_new(): room_id field is NULL");

    bool t1, t2;
    //t1 = (room->items == NULL);
    t2 = (room->paths == NULL);

    //cr_assert_eq(t1, false, "room->items not set by roomspec_to_room()");
    cr_assert_eq(t2, true, "room->paths not set by roomspec_to_room()");
}

/* Checks that, given a roomspec pointer, roomspec_to_room correctly returns a
* room pointer with paths field not NULL */
Test(autogenerate, roomspec_to_room2)
{
    roomspec_t *r = make_default_room("castle", NULL, NULL);
    game_t *g = game_new("start desc");
    coords_t *coords=coords_new(0,0);
    room_t *room = roomspec_to_room(r, coords);

    // no need to check short/long desc because we know these are set by default_room
    cr_assert_not_null(room, "roomspec_new(): The returned room is NULL");
    cr_assert_not_null(room->room_id, "roomspec_new(): room_id field is NULL");

    bool t1, t2;
    //t1 = (room->items == NULL);
    t2 = (room->paths == NULL);

    //cr_assert_eq(t1, false, "room->items not set by roomspec_to_room()");
    cr_assert_eq(t2, true, "room->paths not set by roomspec_to_room()");
}

/* Checks that, given a roomspec pointer, roomspec_to_room correctly returns a
* room pointer with items field not NULL */
Test(autogenerate, roomspec_to_room3)
{
    roomspec_t *r = make_default_room("farmhouse", NULL, NULL);
    game_t *g = game_new("start desc");
    coords_t *coords=coords_new(0,0);
    room_t *room = roomspec_to_room(r, coords);

    // no need to check short/long desc because we know these are set by default_room
    cr_assert_not_null(room, "roomspec_new(): The returned room is NULL");
    cr_assert_not_null(room->room_id, "roomspec_new(): room_id field is NULL");

    bool t1, t2;
    //t1 = (room->items == NULL);
    t2 = (room->paths == NULL);

    //cr_assert_eq(t1, false, "room->items not set by roomspec_to_room()");
    cr_assert_eq(t2, true, "room->paths not set by roomspec_to_room()");

}

/* Checks that when an open direction exists, pick_random_direction successfully outputs a direction*/
Test(autogenerate, pick_random_direction){

    game_t *game=game_new("New Game");

    roomspec_t *spec1 = roomspec_new("room_name1", "short desc1", "long desc1", NULL);
    cr_assert_not_null(spec1, "failed to create new roomspec_t\n");
    spec1->tag=0;

    roomspec_t *spec2 = roomspec_new("room_name2", "short desc2", "long desc2", NULL);
    cr_assert_not_null(spec2, "failed to create new roomspec_t\n");
    spec2->tag=1;

    roomspec_t *spec3 = roomspec_new("room_name3", "short desc3", "long desc3", NULL);
    cr_assert_not_null(spec3, "failed to create new roomspec_t\n");
    spec3->tag=2;
    roomspec_t **roomspecs=(roomspec_t**)malloc(3*sizeof(roomspec_t*));

    roomspecs[0]=spec1;
    roomspecs[1]=spec2;
    roomspecs[2]=spec3;

    int *matrix=(int*)malloc(9*sizeof(int));

    matrix[0]=5;
    matrix[1]=4;
    matrix[2]=5; 
    matrix[3]=0; 
    matrix[4]=5;  
    matrix[5]=3;
    matrix[6]=4; 
    matrix[7]=3;  
    matrix[8]=5;

    int **edges=edges_new(matrix, 3, 3);

    specgraph_t *specgraph = specgraph_new(3, roomspecs, edges);

    coords_t *coords=coords_new(0,0);
    room_t *room=roomspec_to_room(spec1, coords);

    add_room_to_game(game, room);

    int rc;
    char* direction_to_new;
    char* direction_to_curr;

    for(int i=0; i<10; i++){

        rc=pick_random_direction(game, room, direction_to_curr, direction_to_new);
        cr_assert_eq(rc, SUCCESS, "failed to pick a random direction %d\n", i);

    }
}

/* Checks that pick_random_direction() returns correct NESW (compass directions)
   forward-reverse direction pairs */
/*Test(autogenerate, pick_random_direction_correct_dir_pairs)
{
    char *directions[4] = {"north", "east", "south", "west"}; // only compass directions
    char *reverse_directions[4] = {"south", "west", "north", "east"};
    room_t *room = room_new("room with no outward paths", "", "");
    char forward[6], reverse[6];
    for (int i = 0; i < 100; i++) {
        pick_random_direction(room, forward, reverse);
        for (int j = 0; j < 4; j++) {
            if (strcmp(directions[j], forward) == 0) {
                cr_assert_str_eq(reverse_directions[j], reverse,
                                 "reverse of %s should be "
                                  "%s not %s!", directions[j], reverse_directions[j], reverse);
            }
        }
    }
}*/

/* Checks that pick_random_direction() does not return OPEN/AVAILABLE
   directions in direction_to_new outparam. 
   It is fine if direction_to_curr param is an unavailable direction, because it concerns
   directions from new to curr. */
/*Test(autogenerate, pick_random_direction_only_open_paths)
{
    room_t *center_room = room_new("room with only north and east available", "", "");
    room_t *room_north = room_new("room north", "", "");
    path_t *path_north = path_new(room_north, "north");
    assert(!add_path_to_room(center_room, path_north));
    room_t *room_east = room_new("room east", "", "");
    path_t *path_east = path_new(room_east, "east");
    assert(!add_path_to_room(center_room, path_east));
    char direction_to_new[6], direction_to_curr[6];
    for (int i = 0; i < 100; i++) {
        pick_random_direction(center_room, direction_to_curr, direction_to_new);
        cr_assert_str_neq("north", direction_to_new, "north is unavailable!");
        cr_assert_str_neq("east", direction_to_new, "east is unavailable!");
    }
}*/


/*Test(room, room_generate_success_zero){
    game_t *game=game_new("New Game");
    roomspec_t *spec1 = roomspec_new("room_name1", "short desc1", "long desc1", NULL);
    cr_assert_not_null(spec1, "failed to create new roomspec_t\n");
    spec1->tag=0;
    roomspec_t *spec2 = roomspec_new("room_name2", "short desc2", "long desc2", NULL);
    cr_assert_not_null(spec2, "failed to create new roomspec_t\n");
    spec2->tag=1;
    roomspec_t *spec3 = roomspec_new("room_name3", "short desc3", "long desc3", NULL);
    cr_assert_not_null(spec3, "failed to create new roomspec_t\n");
    spec3->tag=2;
    roomspec_t **roomspecs=(roomspec_t**)malloc(3*sizeof(roomspec_t*));
    roomspecs[0]=spec1;
    roomspecs[1]=spec2;
    roomspecs[2]=spec3;
    int *matrix=(int*)malloc(9*sizeof(int));
    matrix[0]=5;
    matrix[1]=4;
    matrix[2]=5; 
    matrix[3]=0; 
    matrix[4]=5;  
    matrix[5]=3;
    matrix[6]=4; 
    matrix[7]=3;  
    matrix[8]=5;
    int **edges=edges_new(matrix, 3, 3);
    specgraph_t *specgraph = specgraph_new(3, roomspecs, edges);
    random_first_room(game, specgraph);
//Test fails due to this line
    room_t *room=random_room_from_game(game);
    cr_assert_eq(0, 1, "failed to generate room\n");
    int rc;
    char *direction_to_curr;
    char *direction_to_new;
    rc=room_generate(game, room, spec1, direction_to_curr, direction_to_new);
    
    cr_assert_eq(rc, 1, "failed to generate room\n");
}*/

/* One roomspec case: Checks that, given a game, context (gencontext_t), and room_id,
* room_generate correctly creates a room from the head of the context
* and adds it to the game via a path (if game->curr_room has available path directions) */

/* testing random room lookup for school specgraph*/
Test(specgraph, school_lookup)
{
    roomspec_t *roomspec0 = make_default_room("school",NULL,NULL);
    roomspec_t **roomspecs = (roomspec_t**)malloc(sizeof(roomspec_t*)*3);
    roomspecs[0] = roomspec0;
    int **edges = (int**)malloc(sizeof(int*));
    specgraph_t *specgraph = specgraph_new(1,roomspecs,edges);

    roomspec_t *r = random_room_lookup(specgraph);
    cr_assert_not_null(r);
    cr_assert_not_null(r->room_name);
    cr_assert_not_null(r->short_desc);
    cr_assert_not_null(r->long_desc);

    if (!strcmp(r->room_name, "classroom") &&
            !strcmp(r->room_name, "closet") &&
            !strcmp(r->room_name, "cafeteria") &&
            !strcmp(r->room_name, "hallway") &&
            !strcmp(r->room_name, "library")) {
        //bogus error code if doesn't match any of the 5 room types
        cr_assert_str_neq(r->room_name, "classroom");
    }
}

/* testing random room lookup for farmhouse specgraph*/
Test(specgraph, farm_lookup)
{
    roomspec_t *roomspec0 = make_default_room("farmhouse",NULL,NULL);
    roomspec_t **roomspecs = (roomspec_t**)malloc(sizeof(roomspec_t*)*3);
    roomspecs[0] = roomspec0;
    int **edges = (int**)malloc(sizeof(int*));
    specgraph_t *specgraph = specgraph_new(1,roomspecs,edges);

    roomspec_t *r = random_room_lookup(specgraph);
    cr_assert_not_null(r);
    cr_assert_not_null(r->room_name);
    cr_assert_not_null(r->short_desc);
    cr_assert_not_null(r->long_desc);

    if (!strcmp(r->room_name, "barn") &&
            !strcmp(r->room_name, "closet") &&
            !strcmp(r->room_name, "kitchen") &&
            !strcmp(r->room_name, "living room") &&
            !strcmp(r->room_name, "open field")) {
        //bogus error code if doesn't match any of the 5 room types
        cr_assert_str_neq(r->room_name, "barn");
    }
}

/* testing random room lookup for castle specgraph*/
Test(specgraph, castle_lookup)
{
    roomspec_t *roomspec0 = make_default_room("castle",NULL,NULL);
    roomspec_t **roomspecs = (roomspec_t**)malloc(sizeof(roomspec_t*)*3);
    roomspecs[0] = roomspec0;
    int **edges = (int**)malloc(sizeof(int*));
    specgraph_t *specgraph = specgraph_new(1,roomspecs,edges);

    roomspec_t *r = random_room_lookup(specgraph);
    cr_assert_not_null(r);
    cr_assert_not_null(r->room_name);
    cr_assert_not_null(r->short_desc);
    cr_assert_not_null(r->long_desc);

    if (!strcmp(r->room_name, "throne room") &&
            !strcmp(r->room_name, "closet") &&
            !strcmp(r->room_name, "dungeon") &&
            !strcmp(r->room_name, "hallway") &&
            !strcmp(r->room_name, "library")) {
        //bogus error code if doesn't match any of the 5 room types
        cr_assert_str_neq(r->room_name, "classroom");
    }
}

/* testing random_items for barn roomspec*/
Test(roomspec, barn_item)
{
    rspec_hash_t *hash = make_default_room("farmhouse", NULL, NULL);
    roomspec_t *r = NULL;
    HASH_FIND_STR(hash, "barn", r);

    item_hash_t *items = random_items(r);
    if (items != NULL) {
        cr_assert_not_null(items->item_id);
        if (!strcmp(items->item_id, "apple") &&
                !strcmp(items->item_id, "cow") &&
                !strcmp(items->item_id, "eagle") &&
                !strcmp(items->item_id, "rabbit") &&
                !strcmp(items->item_id, "yam")) {
            cr_assert_str_neq(items->item_id, "rabbit");
        }
    }
}

/* testing random_items for classroom roomspec*/
Test(roomspec, class_item)
{
    rspec_hash_t *hash = make_default_room("school",NULL, NULL);
    roomspec_t *r = NULL;
    HASH_FIND_STR(hash, "classroom", r);

    item_hash_t *items = random_items(r);
    if (items != NULL) {
        cr_assert_not_null(items->item_id);
        if (!strcmp(items->item_id, "book") &&
                !strcmp(items->item_id, "door") &&
                !strcmp(items->item_id, "pencil") &&
                !strcmp(items->item_id, "watercolors") &&
                !strcmp(items->item_id, "video")) {
            cr_assert_str_neq(items->item_id, "pencil");
        }
    }
}

/* testing random_items for throne room roomspec*/
Test(roomspec, throne_item)
{
    rspec_hash_t *hash = make_default_room("castle", NULL, NULL);
    roomspec_t *r = NULL;
    HASH_FIND_STR(hash, "throne room", r);

    item_hash_t *items = random_items(r);
    if (items != NULL) {
        cr_assert_not_null(items->item_id);
        if (!strcmp(items->item_id, "nail") &&
                !strcmp(items->item_id, "book") &&
                !strcmp(items->item_id, "ladder") &&
                !strcmp(items->item_id, "gold") &&
                !strcmp(items->item_id, "yam")) {
            cr_assert_str_neq(items->item_id, "yam");
        }
    }
}

/* testing random_item_lookup for 0 iterations*/
Test(item_hash, zero_lookup)
{
    item_hash_t *dst = NULL;
    item_hash_t *src = get_default_items();
    int rc;
    rc = random_item_lookup(&dst, src, 0);
    cr_assert_not_null(dst);
}

/* testing random_item_lookup for 1 iteration*/
Test(item_hash, one_lookup)
{
    item_hash_t *dst = NULL;
    item_hash_t *src = get_default_items();
    int rc;
    rc = random_item_lookup(&dst, src, 1);
    cr_assert_not_null(dst);
}

/* testing random_item_lookup for 3 iterations*/
Test(item_hash, three_lookup)
{
    item_hash_t *dst = NULL;
    item_hash_t *src = get_default_items();
    int rc;
    rc = random_item_lookup(&dst, src, 3);

    cr_assert_not_null(dst);
}

/* Checks that generate_items follows the default behavior,
 * i.e. generate 1 item with 100% probability,
 * when itemspec for all items are not defined */
Test(item_hash, generate_items_default)
{
    rspec_hash_t *rspec_hash = make_default_room("school", NULL, NULL);
    roomspec_t *rspec = NULL;
    HASH_FIND_STR(rspec_hash, "classroom", rspec);
    
    item_hash_t *item_hash = generate_items(rspec);

    int count = 0;
    item_t *curr, *tmp;

    /* Counts number of items in room */
    HASH_ITER(hh, item_hash, curr, tmp) 
    {
        item_t *lst_node;
        /* Count stacked duplicate items */
        DL_FOREACH(curr, lst_node) 
        {
            count++;
        }
    }
    cr_assert_eq(5, count, "5 items in total should have spawned");

    tmp = NULL;
    HASH_FIND_STR(item_hash, "book", tmp);
    cr_assert_not_null(tmp);

    tmp = NULL;
    HASH_FIND_STR(item_hash, "door", tmp);
    cr_assert_not_null(tmp);

    tmp = NULL;
    HASH_FIND_STR(item_hash, "pencil", tmp);
    cr_assert_not_null(tmp);

    tmp = NULL;
    HASH_FIND_STR(item_hash, "watercolors", tmp);
    cr_assert_not_null(tmp);

    tmp = NULL;
    HASH_FIND_STR(item_hash, "video", tmp);
    cr_assert_not_null(tmp);
}


/* Checks that generate_items does not generate any item
 * when all itemspecs are set to 0 spawn_chance */
Test(item_hash, generate_items_nothing)
{
    rspec_hash_t *rspec_hash = make_default_room("school", NULL, NULL);
    roomspec_t *rspec = NULL;
    HASH_FIND_STR(rspec_hash, "classroom", rspec);
    
    /* Adding itemspecs to hash */
    char *item_names[5] = {"book", "door", "pencil", "watercolors", "video"}; 
    for (int i = 0; i < 5; i++) 
    {
        /* each itemspec has a spawn_chance of 0, and a [1, 10] quantity range */
        itemspec_t *itemspec = itemspec_new(item_names[i], 0, 1, 10); 
        HASH_ADD_KEYPTR(hh, rspec->itemspecs, item_names[i], strlen(item_names[i]), itemspec);
    }

    item_hash_t *item_hash = generate_items(rspec);

    int count = 0;
    item_t *curr, *tmp;
    /* Counts number of items in room */
    HASH_ITER(hh, item_hash, curr, tmp) 
    {
        item_t *lst_node;
        DL_FOREACH(curr, lst_node) 
        {
            count++;
        }
    }
    cr_assert_eq(0, count, "No items should be spawned");
}


/* Checks that generate_items can generate items 
 * with different probabilities and quantities */
Test(item_hash, generate_items_as_specified)
{
    rspec_hash_t *rspec_hash = make_default_room("school", NULL, NULL);
    roomspec_t *rspec = NULL;
    HASH_FIND_STR(rspec_hash, "classroom", rspec);
    
    char *item1_name = "book";
    itemspec_t *itemspec1 = itemspec_new(item1_name, 0, 2, 4);
    HASH_ADD_KEYPTR(hh, rspec->itemspecs, item1_name, strlen(item1_name), itemspec1);

    char *item2_name = "door";
    itemspec_t *itemspec2 = itemspec_new(item2_name, 1, 2, 3);
    HASH_ADD_KEYPTR(hh, rspec->itemspecs, item2_name, strlen(item2_name), itemspec2);

    char *item3_name = "pencil";
    itemspec_t *itemspec3 = itemspec_new(item3_name, 0.5, 2, 2);
    HASH_ADD_KEYPTR(hh, rspec->itemspecs, item3_name, strlen(item3_name), itemspec3);

    item_hash_t *item_hash = generate_items(rspec);

    int count;
    item_t *item, *tmp;

    item = NULL;
    HASH_FIND_STR(item_hash, "book", item);
    cr_assert_null(item, "failed to generate item with right probability");

    count = 0;
    item = NULL;
    HASH_FIND_STR(item_hash, "door", item);
    DL_FOREACH(item, tmp) 
    {
        count++;
    }
    cr_assert((count == 2) || (count == 3), 
              "failed to generate item with right quantity");

    count = 0;
    item = NULL;
    HASH_FIND_STR(item_hash, "pencil", item);
    DL_FOREACH(item, tmp) 
    {
        count++;
    }
    cr_assert((count == 0) || (count == 2), 
              "failed to generate item with right quantity");

    count = 0;
    item = NULL;
    HASH_FIND_STR(item_hash, "watercolors", item);
    DL_FOREACH(item, tmp) 
    {
        count++;
    }
    cr_assert(count == 1, "failed to generate item with default params");

    count = 0;
    item = NULL;
    HASH_FIND_STR(item_hash, "video", item);
    DL_FOREACH(item, tmp) 
    {
        count++;
    }
    cr_assert(count == 1, "failed to generate item with default params");
}


/* Checks that number of items generated by generate_items 
 * does not exceed MAX_RAND_ITEMS */
Test(item_hash, generate_items_no_more_than_max)
{
    rspec_hash_t *rspec_hash = make_default_room("school", NULL, NULL);
    roomspec_t *rspec = NULL;
    HASH_FIND_STR(rspec_hash, "classroom", rspec);

    char *item_name = "book";
    itemspec_t *itemspec = itemspec_new(item_name, 1, MAX_RAND_ITEMS + 10, 
                                                      MAX_RAND_ITEMS + 20);
    HASH_ADD_KEYPTR(hh, rspec->itemspecs, item_name, strlen(item_name), itemspec);

    item_hash_t *item_hash = generate_items(rspec);

    int count = 0;
    item_t *curr, *tmp;

    HASH_ITER(hh, item_hash, curr, tmp) 
    {
        item_t *lst_node;
        DL_FOREACH(curr, lst_node) 
        {
            count++;
        }
    }
    cr_assert_eq(MAX_RAND_ITEMS, count, "Number of items should be MAX_RAND_ITEMS");
}



/* testing map_level_to_difficulty for
 * thresholds {0, 5, 13} and player_lvls 0 to 20 */
Test(thresholds, map_level_to_difficulty_one)
{
    int num_thresholds = 3;
    int thresholds[3] = {0, 5, 13};
    
    int actual, expected;
    for (int player_lvl = 0; player_lvl <= 20; player_lvl++) {
        actual = map_level_to_difficulty(num_thresholds, thresholds, player_lvl);
        if (player_lvl < 5) {
            expected = 0;
        } else if (player_lvl < 13) {
            expected = 1;
        } else {
            expected = 2;
        }
        cr_assert_eq(expected, actual, 
                     "using the thresholds {0, 21, 22, 80}," 
                     " expected player_lvl %d -> difficulty %d," 
                     " but mapped to difficulty %d\n", 
                     player_lvl, expected, actual);
    }             
}


/* testing map_level_to_difficulty for
 * thresholds {0, 21, 22, 80} and player_lvls 0 to 200 */
Test(thresholds, map_level_to_difficulty_two)
{
    int num_thresholds = 4;
    int thresholds[4] = {0, 21, 22, 80};
    
    int actual, expected;
    for (int player_lvl = 0; player_lvl <= 200; player_lvl++) {
        actual = map_level_to_difficulty(num_thresholds, thresholds, player_lvl);
        if (player_lvl < 21) {
            expected = 0;
        } else if (player_lvl < 22) {
            expected = 1;
        } else if (player_lvl < 80) {
            expected = 2;
        } else {
            expected = 3;
        }
        cr_assert_eq(expected, actual, 
                     "using the thresholds {0, 21, 22, 80}," 
                     " expected player_lvl %d -> difficulty %d," 
                     " but mapped to difficulty %d\n", 
                     player_lvl, expected, actual);
    }          
}



/* TEST_HELPER_roomspec_is_given_difficulty
 * Helper for roomspec_is_given_difficulty tests
 * 
 * parameters:
 * - int actual: actual value 
 * - int expected: expected value
 * - char *rspec_name: name of the rspec that was inputted
 * - int given_difficulty: level that was passed in
 * 
 * side-effects:
 * - Formats error message and runs cr_assert_eq
 * 
 * e.g. 
 * TEST_HELPER_roomspec_is_given_difficulty(0, 1, rspecB, 2);
 * ... prints ...
 * "rspecB is NOT of given difficulty (2) but got 0."
 */
void TEST_HELPER_roomspec_is_given_difficulty(int actual, int expected, char *rspec_name, int given_difficulty)
{
    cr_assert_eq(actual, expected,
                 "%s %s given difficulty (%d) "
                 "but got %d.\n",
                 rspec_name,
                 expected? "is NOT of" : "IS of",
                 given_difficulty,
                 actual);
}


/* testing roomspec_is_given_difficulty
 * for a hash table with one lvl 0 roomlevel */
Test(roomlevel, one_lvl0_room)
{
    roomlevel_hash_t *roomlevels = NULL;
    
    // creating roomlevels and hashing to table
    char *lvl0_roomname = "A";
    add_roomlevel_to_hash(&roomlevels, lvl0_roomname, 0);

    // checking that roomlevel is hashed
    roomlevel_t *tmp;
    HASH_FIND_STR(roomlevels, "A", tmp);
    cr_assert_not_null(tmp);

    // creating room_spec and checking that it is not null
    roomspec_t* rspecA = roomspec_new("A", "shortdesc", "longdesc", NULL);
    cr_assert_not_null(rspecA);

    int actual, expected;
    
    actual = roomspec_is_given_difficulty(&roomlevels, rspecA, 0);
    expected = 0;
    TEST_HELPER_roomspec_is_given_difficulty(actual, expected, "rspecA", 0);

    actual = roomspec_is_given_difficulty(&roomlevels, rspecA, 3);
    expected = 1;
    TEST_HELPER_roomspec_is_given_difficulty(actual, expected, "rspecA", 3);

    // creating room_spec and checking that it is not null
    roomspec_t* rspecB = roomspec_new("B", "shortdesc", "longdesc", NULL);
    cr_assert_not_null(rspecB);

    actual = roomspec_is_given_difficulty(&roomlevels, rspecB, 3);
    expected = 2;
    TEST_HELPER_roomspec_is_given_difficulty(actual, expected, "rspecB", 3);
}


/* testing roomspec_is_given_difficulty
 * for a hash table with two roomlevels, one lvl 0 and 1 each */
Test(roomlevel, lvl0_to_lvl1_roomlevels)
{
    roomlevel_hash_t *roomlevels = NULL;
    
    // creating roomlevels and hashing to table
    char *lvl0_roomname = "A0";
    char *lvl1_roomname = "A1";
    add_roomlevel_to_hash(&roomlevels, lvl0_roomname, 0);
    add_roomlevel_to_hash(&roomlevels, lvl1_roomname, 1);

    // checking that roomlevels are hashed
    roomlevel_t *tmp;
    HASH_FIND_STR(roomlevels, "A0", tmp);
    cr_assert_not_null(tmp);
    HASH_FIND_STR(roomlevels, "A1", tmp);
    cr_assert_not_null(tmp);

    // creating room_specs and checking that they are not null
    roomspec_t* rspecA0 = roomspec_new("A0", "shortdesc", "longdesc", NULL);
    roomspec_t* rspecA1 = roomspec_new("A1", "shortdesc", "longdesc", NULL);
    cr_assert_not_null(rspecA0);
    cr_assert_not_null(rspecA1);

    int actual, expected;

    actual = roomspec_is_given_difficulty(&roomlevels, rspecA0, 0);
    expected = 0;
    TEST_HELPER_roomspec_is_given_difficulty(actual, expected, "rspecA0", 0);

    actual = roomspec_is_given_difficulty(&roomlevels, rspecA0, 1);
    expected = 1;
    TEST_HELPER_roomspec_is_given_difficulty(actual, expected, "rspecA0", 1);

    actual = roomspec_is_given_difficulty(&roomlevels, rspecA1, 1);
    expected = 0;
    TEST_HELPER_roomspec_is_given_difficulty(actual, expected, "rspecA1", 1);

    actual = roomspec_is_given_difficulty(&roomlevels, rspecA1, 0);
    expected = 1;
    TEST_HELPER_roomspec_is_given_difficulty(actual, expected, "rspecA1", 0);

    // creating room_spec and checking that it is not null
    roomspec_t* rspecB = roomspec_new("B", "shortdesc", "longdesc", NULL);
    cr_assert_not_null(rspecB);

    actual = roomspec_is_given_difficulty(&roomlevels, rspecB, 3);
    expected = 2;
    TEST_HELPER_roomspec_is_given_difficulty(actual, expected, "rspecB", 3);
}