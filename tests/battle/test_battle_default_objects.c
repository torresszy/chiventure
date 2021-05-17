#include <criterion/criterion.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "battle/battle_default_objects.h"

Test(battle_default_objects, default_items) 
{
    battle_item_t *test_item = get_random_default_battle_item();
    
    cr_assert_not_null(test_item, "get_random_default_item() failed");

    int id = test_item->id; 

    cr_assert_eq(test_item->quantity, 1, "get_random_default_item() did not set quantity to 1");
    
    if (id == 1)
    {
        // STICK
        cr_assert_eq(test_item->is_weapon, false, "get_random_default_battle_item() did not set is_weapon correctly"); 
        cr_assert_eq(test_item->effectiveness_decrement, 0, "get_random_default_battle_item() did not set effectiveness_decrement correctly"); 
        cr_assert_eq(test_item->durability, 10, "get_random_default_battle_item() did not set durability correctly");   
        cr_assert_str_eq(test_item->name, "STICK", "get_random_default_battle_item() did not set name correctly");
        cr_assert_null(test_item->description, "get_random_default_battle_item() did not set description correctly");
        cr_assert_eq(test_item->battle, true, "get_random_default_battle_item() did not set durability correctly");
        cr_assert_eq(test_item->attack, 10, "get_random_default_battle_item() did not set attack correctly");
        cr_assert_eq(test_item->defense, 15, "get_random_default_battle_item() did not set defense correctly");
        cr_assert_eq(test_item->hp, 20, "get_random_default_battle_item() did not set hp correctly");
        cr_assert_null(test_item->next, "get_random_default_battle_item() did not set item->next correctly");
        cr_assert_null(test_item->prev, "get_random_default_battle_item() did not set item->prev correctly");
    }
    else if (id == 2)
    {
        // HAMMER
        cr_assert_eq(test_item->is_weapon, false, "get_random_default_battle_item() did not set is_weapon correctly"); 
        cr_assert_eq(test_item->effectiveness_decrement, 0, "get_random_default_battle_item() did not set effectiveness_decrement correctly"); 
        cr_assert_eq(test_item->durability, 20, "get_random_default_battle_item() did not set durability correctly");   
        cr_assert_str_eq(test_item->name, "HAMMER", "get_random_default_battle_item() did not set name correctly");
        cr_assert_null(test_item->description, "get_random_default_battle_item() did not set description correctly");
        cr_assert_eq(test_item->battle, true, "get_random_default_battle_item() did not set durability correctly");
        cr_assert_eq(test_item->attack, 20, "get_random_default_battle_item() did not set attack correctly");
        cr_assert_eq(test_item->defense, 25, "get_random_default_battle_item() did not set defense correctly");
        cr_assert_eq(test_item->hp, 30, "get_random_default_battle_item() did not set hp correctly");
        cr_assert_null(test_item->next, "get_random_default_battle_item() did not set item->next correctly");
        cr_assert_null(test_item->prev, "get_random_default_battle_item() did not set item->prev correctly");
    }
    else if (id == 3)
    {
        // SHIV
        cr_assert_eq(test_item->is_weapon, false, "get_random_default_battle_item() did not set is_weapon correctly"); 
        cr_assert_eq(test_item->effectiveness_decrement, 0, "get_random_default_battle_item() did not set effectiveness_decrement correctly"); 
        cr_assert_eq(test_item->durability, 30, "get_random_default_battle_item() did not set durability correctly");   
        cr_assert_str_eq(test_item->name, "SHIV", "get_random_default_battle_item() did not set name correctly");
        cr_assert_null(test_item->description, "get_random_default_battle_item() did not set description correctly");
        cr_assert_eq(test_item->battle, true, "get_random_default_battle_item() did not set durability correctly");
        cr_assert_eq(test_item->attack, 30, "get_random_default_battle_item() did not set attack correctly");
        cr_assert_eq(test_item->defense, 35, "get_random_default_battle_item() did not set defense correctly");
        cr_assert_eq(test_item->hp, 40, "get_random_default_battle_item() did not set hp correctly");
        cr_assert_null(test_item->next, "get_random_default_battle_item() did not set item->next correctly");
        cr_assert_null(test_item->prev, "get_random_default_ battle_item() did not set item->prev correctly");
    }
    else if (id == 4)
    {
        // CLUB
        cr_assert_eq(test_item->is_weapon, false, "get_random_default_battle_item() did not set is_weapon correctly"); 
        cr_assert_eq(test_item->effectiveness_decrement, 0, "get_random_default_battle_item() did not set effectiveness_decrement correctly"); 
        cr_assert_eq(test_item->durability, 40, "get_random_default_battle_item() did not set durability correctly");   
        cr_assert_str_eq(test_item->name, "CLUB", "get_random_default_battle_item() did not set name correctly");
        cr_assert_null(test_item->description, "get_random_default_battle_item() did not set description correctly");
        cr_assert_eq(test_item->battle, true, "get_random_default_battle_item() did not set durability correctly");
        cr_assert_eq(test_item->attack, 40, "get_random_default_battle_item() did not set attack correctly");
        cr_assert_eq(test_item->defense, 45, "get_random_default_battle_item() did not set defense correctly");
        cr_assert_eq(test_item->hp, 50, "get_random_default_battle_item() did not set hp correctly");
        cr_assert_null(test_item->next, "get_random_default_battle_item() did not set item->next correctly");
        cr_assert_null(test_item->prev, "get_random_default_battle_item() did not set item->prev correctly");
    }
    else if (id == 5)
    {
        // BOW & ARROW
        cr_assert_eq(test_item->is_weapon, false, "get_random_default_battle_item() did not set is_weapon correctly"); 
        cr_assert_eq(test_item->effectiveness_decrement, 0, "get_random_default_battle_item() did not set effectiveness_decrement correctly"); 
        cr_assert_eq(test_item->durability, 50, "get_random_default_battle_item() did not set durability correctly");   
        cr_assert_str_eq(test_item->name, "BOW & ARROW", "get_random_default_battle_item() did not set name correctly");
        cr_assert_null(test_item->description, "get_random_default_battle_item() did not set description correctly");
        cr_assert_eq(test_item->battle, true, "get_random_default_battle_item() did not set durability correctly");
        cr_assert_eq(test_item->attack, 50, "get_random_default_ battle_item() did not set attack correctly");
        cr_assert_eq(test_item->defense, 55, "get_random_default_battle_item() did not set defense correctly");
        cr_assert_eq(test_item->hp, 60, "get_random_default_battle_item() did not set hp correctly");
        cr_assert_null(test_item->next, "get_random_default_battle_item() did not set item->next correctly");
        cr_assert_null(test_item->prev, "get_random_default_battle_item() did not set item->prev correctly");
    }
    else if (id == 6)
    {
        // SPEAR
        cr_assert_eq(test_item->is_weapon, false, "get_random_default_battle_item() did not set is_weapon correctly"); 
        cr_assert_eq(test_item->effectiveness_decrement, 0, "get_random_default_battle_item() did not set effectiveness_decrement correctly"); 
        cr_assert_eq(test_item->durability, 60, "get_random_default_battle_item() did not set durability correctly");   
        cr_assert_str_eq(test_item->name, "SPEAR", "get_random_default_battle_item() did not set name correctly");
        cr_assert_null(test_item->description, "get_random_default_battle_item() did not set description correctly");
        cr_assert_eq(test_item->battle, true, "get_random_default_battle_item() did not set durability correctly");
        cr_assert_eq(test_item->attack, 60, "get_random_default_battle_item() did not set attack correctly");
        cr_assert_eq(test_item->defense, 65, "get_random_default_battle_item() did not set defense correctly");
        cr_assert_eq(test_item->hp, 70, "get_random_default_battle_item() did not set hp correctly");
        cr_assert_null(test_item->next, "get_random_default_battle_item() did not set item->next correctly");
        cr_assert_null(test_item->prev, "get_random_default_battle_item() did not set item->prev correctly");
    }
    else if (id == 7)
    {
        // AXE
        cr_assert_eq(test_item->is_weapon, false, "get_random_default_battle_item() did not set is_weapon correctly"); 
        cr_assert_eq(test_item->effectiveness_decrement, 0, "get_random_default_battle_item() did not set effectiveness_decrement correctly"); 
        cr_assert_eq(test_item->durability, 70, "get_random_default_battle_item() did not set durability correctly");   
        cr_assert_str_eq(test_item->name, "AXE", "get_random_default_battle_item() did not set name correctly");
        cr_assert_null(test_item->description, "get_random_default_battle_item() did not set description correctly");
        cr_assert_eq(test_item->battle, true, "get_random_default_battle_item() did not set durability correctly");
        cr_assert_eq(test_item->attack, 70, "get_random_default_battle_item() did not set attack correctly");
        cr_assert_eq(test_item->defense, 75, "get_random_default_battle_item() did not set defense correctly");
        cr_assert_eq(test_item->hp, 80, "get_random_default_battle_item() did not set hp correctly");
        cr_assert_null(test_item->next, "get_random_default_battle_item() did not set item->next correctly");
        cr_assert_null(test_item->prev, "get_random_default_battle_item() did not set item->prev correctly");
    }
    else if (id == 8)
    {
        // TRIDENT
        cr_assert_eq(test_item->is_weapon, false, "get_random_default_battle_item() did not set is_weapon correctly"); 
        cr_assert_eq(test_item->effectiveness_decrement, 0, "get_random_default_battle_item() did not set effectiveness_decrement correctly"); 
        cr_assert_eq(test_item->durability, 80, "get_random_default_battle_item() did not set durability correctly");   
        cr_assert_str_eq(test_item->name, "TRIDENT", "get_random_default_battle_item() did not set name correctly");
        cr_assert_null(test_item->description, "get_random_default_battle_item() did not set description correctly");
        cr_assert_eq(test_item->battle, true, "get_random_default_battle_item() did not set durability correctly");
        cr_assert_eq(test_item->attack, 80, "get_random_default_battle_item() did not set attack correctly");
        cr_assert_eq(test_item->defense, 85, "get_random_default_battle_item() did not set defense correctly");
        cr_assert_eq(test_item->hp, 90, "get_random_default_battle_item() did not set hp correctly");
        cr_assert_null(test_item->next, "get_random_default_battle_item() did not set item->next correctly");
        cr_assert_null(test_item->prev, "get_random_default_battle_item() did not set item->prev correctly");
    }
    else if (id == 9)
    {
        // SWORD
        cr_assert_eq(test_item->is_weapon, false, "get_random_default_battle_item() did not set is_weapon correctly"); 
        cr_assert_eq(test_item->effectiveness_decrement, 0, "get_random_default_battle_item() did not set effectiveness_decrement correctly"); 
        cr_assert_eq(test_item->durability, 90, "get_random_default_battle_item() did not set durability correctly");   
        cr_assert_str_eq(test_item->name, "SWORD", "get_random_default_battle_item() did not set name correctly");
        cr_assert_null(test_item->description, "get_random_default_battle_item() did not set description correctly");
        cr_assert_eq(test_item->battle, true, "get_random_default_battle_item() did not set durability correctly");
        cr_assert_eq(test_item->attack, 90, "get_random_default_battle_item() did not set attack correctly");
        cr_assert_eq(test_item->defense, 95, "get_random_default_battle_item() did not set defense correctly");
        cr_assert_eq(test_item->hp, 100, "get_random_default_battle_item() did not set hp correctly");
        cr_assert_null(test_item->next, "get_random_default_battle_item() did not set item->next correctly");
        cr_assert_null(test_item->prev, "get_random_default_battle_item() did not set item->prev correctly");
    }
    else if (id == 10)
    {
        // SHIELD
        cr_assert_eq(test_item->is_weapon, false, "get_random_default_battle_item() did not set is_weapon correctly"); 
        cr_assert_eq(test_item->effectiveness_decrement, 0, "get_random_default_battle_item() did not set effectiveness_decrement correctly"); 
        cr_assert_eq(test_item->durability, 100, "get_random_default_battle_item() did not set durability correctly");   
        cr_assert_str_eq(test_item->name, "SHIELD", "get_random_default_battle_item() did not set name correctly");
        cr_assert_null(test_item->description, "get_random_default_battle_item() did not set description correctly");
        cr_assert_eq(test_item->battle, true, "get_random_default_battle_item() did not set durability correctly");
        cr_assert_eq(test_item->attack, 100, "get_random_default_battle_item() did not set attack correctly");
        cr_assert_eq(test_item->defense, 105, "get_random_default_battle_item() did not set defense correctly");
        cr_assert_eq(test_item->hp, 110, "get_random_default_battle_item() did not set hp correctly");
        cr_assert_null(test_item->next, "get_random_default_battle_item() did not set item->next correctly");
        cr_assert_null(test_item->prev, "get_random_default_battle_item() did not set item->prev correctly");
    }
    else
    {
        cr_assert_fail("get_random_default_battle_item() did not set id correctly");
    }
}

Test(battle_default_objects, default_weapon)
{
    battle_item_t *test_weapon = get_random_default_weapon();
    
    cr_assert_not_null(test_weapon, "get_random_weapon() failed");

    int id = test_weapon->id; 

    cr_assert_eq(test_weapon->quantity, 1, "get_random_weapon() did not set quantity to 1");
    
    if (id == 1)
    {
        // DAGGER
        cr_assert_eq(test_weapon->is_weapon, true, "get_random_weapon() did not set is_weapon correctly"); 
        cr_assert_eq(test_weapon->effectiveness_decrement, 2, "get_random_weapon() did not set effectiveness_decrement correctly"); 
        cr_assert_eq(test_weapon->durability, 10, "get_random_weapon() did not set durability correctly");   
        cr_assert_str_eq(test_weapon->name, "DAGGER", "get_random_weapon() did not set name correctly");
        cr_assert_null(test_weapon->description, "get_random_weapon() did not set description correctly");
        cr_assert_eq(test_weapon->battle, true, "get_random_weapon() did not set durability correctly");
        cr_assert_eq(test_weapon->attack, 10, "get_random_weapon() did not set attack correctly");
        cr_assert_eq(test_weapon->defense, 15, "get_random_weapon() did not set defense correctly");
        cr_assert_eq(test_weapon->hp, 20, "get_random_weapon() did not set hp correctly");
        cr_assert_null(test_weapon->next, "get_random_weapon() did not set item->next correctly");
        cr_assert_null(test_weapon->prev, "get_random_weapon() did not set item->prev correctly");
    }
    else if (id == 2)
    {
        // DUAL KNIVES
        cr_assert_eq(test_weapon->is_weapon, true, "get_random_weapon() did not set is_weapon correctly"); 
        cr_assert_eq(test_weapon->effectiveness_decrement, 4, "get_random_weapon() did not set effectiveness_decrement correctly"); 
        cr_assert_eq(test_weapon->durability, 20, "get_random_weapon() did not set durability correctly");   
        cr_assert_str_eq(test_weapon->name, "DUAL KNIVES", "get_random_weapon() did not set name correctly");
        cr_assert_null(test_weapon->description, "get_random_weapon() did not set description correctly");
        cr_assert_eq(test_weapon->battle, true, "get_random_weapon() did not set durability correctly");
        cr_assert_eq(test_weapon->attack, 20, "get_random_weapon() did not set attack correctly");
        cr_assert_eq(test_weapon->defense, 25, "get_random_weapon() did not set defense correctly");
        cr_assert_eq(test_weapon->hp, 30, "get_random_weapon() did not set hp correctly");
        cr_assert_null(test_weapon->next, "get_random_weapon() did not set item->next correctly");
        cr_assert_null(test_weapon->prev, "get_random_weapon() did not set item->prev correctly");
    }
    else if (id == 3)
    {
        // CROSSBOW
        cr_assert_eq(test_weapon->is_weapon, true, "get_random_weapon() did not set is_weapon correctly"); 
        cr_assert_eq(test_weapon->effectiveness_decrement, 6, "get_random_weapon() did not set effectiveness_decrement correctly"); 
        cr_assert_eq(test_weapon->durability, 30, "get_random_weapon() did not set durability correctly");   
        cr_assert_str_eq(test_weapon->name, "CROSSBOW", "get_random_weapon() did not set name correctly");
        cr_assert_null(test_weapon->description, "get_random_weapon() did not set description correctly");
        cr_assert_eq(test_weapon->battle, true, "get_random_weapon() did not set durability correctly");
        cr_assert_eq(test_weapon->attack, 30, "get_random_weapon() did not set attack correctly");
        cr_assert_eq(test_weapon->defense, 35, "get_random_weapon() did not set defense correctly");
        cr_assert_eq(test_weapon->hp, 40, "get_random_weapon() did not set hp correctly");
        cr_assert_null(test_weapon->next, "get_random_weapon() did not set item->next correctly");
        cr_assert_null(test_weapon->prev, "get_random_weapon() did not set item->prev correctly");
    }
    else if (id == 4)
    {
        // GUT BLASTER
        cr_assert_eq(test_weapon->is_weapon, true, "get_random_weapon() did not set is_weapon correctly"); 
        cr_assert_eq(test_weapon->effectiveness_decrement, 8, "get_random_weapon() did not set effectiveness_decrement correctly"); 
        cr_assert_eq(test_weapon->durability, 40, "get_random_weapon() did not set durability correctly");   
        cr_assert_str_eq(test_weapon->name, "GUT BLASTER", "get_random_weapon() did not set name correctly");
        cr_assert_null(test_weapon->description, "get_random_weapon() did not set description correctly");
        cr_assert_eq(test_weapon->battle, true, "get_random_weapon() did not set durability correctly");
        cr_assert_eq(test_weapon->attack, 40, "get_random_weapon() did not set attack correctly");
        cr_assert_eq(test_weapon->defense, 45, "get_random_weapon() did not set defense correctly");
        cr_assert_eq(test_weapon->hp, 50, "get_random_weapon() did not set hp correctly");
        cr_assert_null(test_weapon->next, "get_random_weapon() did not set item->next correctly");
        cr_assert_null(test_weapon->prev, "get_random_weapon() did not set item->prev correctly");
    }
    else if (id == 5)
    {
        // LASER GUN
        cr_assert_eq(test_weapon->is_weapon, true, "get_random_weapon() did not set is_weapon correctly"); 
        cr_assert_eq(test_weapon->effectiveness_decrement, 10, "get_random_weapon() did not set effectiveness_decrement correctly"); 
        cr_assert_eq(test_weapon->durability, 50, "get_random_weapon() did not set durability correctly");   
        cr_assert_str_eq(test_weapon->name, "LASER GUN", "get_random_weapon() did not set name correctly");
        cr_assert_null(test_weapon->description, "get_random_weapon() did not set description correctly");
        cr_assert_eq(test_weapon->battle, true, "get_random_weapon() did not set durability correctly");
        cr_assert_eq(test_weapon->attack, 50, "get_random_weapon() did not set attack correctly");
        cr_assert_eq(test_weapon->defense, 55, "get_random_weapon() did not set defense correctly");
        cr_assert_eq(test_weapon->hp, 60, "get_random_weapon() did not set hp correctly");
        cr_assert_null(test_weapon->next, "get_random_weapon() did not set item->next correctly");
        cr_assert_null(test_weapon->prev, "get_random_weapon() did not set item->prev correctly");
    }
    else if (id == 6)
    {
        // SAW DISK
        cr_assert_eq(test_weapon->is_weapon, true, "get_random_weapon() did not set is_weapon correctly"); 
        cr_assert_eq(test_weapon->effectiveness_decrement, 12, "get_random_weapon() did not set effectiveness_decrement correctly"); 
        cr_assert_eq(test_weapon->durability, 60, "get_random_weapon() did not set durability correctly");   
        cr_assert_str_eq(test_weapon->name, "SAW DISK", "get_random_weapon() did not set name correctly");
        cr_assert_null(test_weapon->description, "get_random_weapon() did not set description correctly");
        cr_assert_eq(test_weapon->battle, true, "get_random_weapon() did not set durability correctly");
        cr_assert_eq(test_weapon->attack, 60, "get_random_weapon() did not set attack correctly");
        cr_assert_eq(test_weapon->defense, 65, "get_random_weapon() did not set defense correctly");
        cr_assert_eq(test_weapon->hp, 70, "get_random_weapon() did not set hp correctly");
        cr_assert_null(test_weapon->next, "get_random_weapon() did not set item->next correctly");
        cr_assert_null(test_weapon->prev, "get_random_weapon() did not set item->prev correctly");
    }
    else if (id == 7)
    {
        // BRASS KNUCKLES
        cr_assert_eq(test_weapon->is_weapon, true, "get_random_weapon() did not set is_weapon correctly"); 
        cr_assert_eq(test_weapon->effectiveness_decrement, 14, "get_random_weapon() did not set effectiveness_decrement correctly"); 
        cr_assert_eq(test_weapon->durability, 70, "get_random_weapon() did not set durability correctly");   
        cr_assert_str_eq(test_weapon->name, "BRASS KNUCKLES", "get_random_weapon() did not set name correctly");
        cr_assert_null(test_weapon->description, "get_random_weapon() did not set description correctly");
        cr_assert_eq(test_weapon->battle, true, "get_random_weapon() did not set durability correctly");
        cr_assert_eq(test_weapon->attack, 70, "get_random_weapon() did not set attack correctly");
        cr_assert_eq(test_weapon->defense, 75, "get_random_weapon() did not set defense correctly");
        cr_assert_eq(test_weapon->hp, 80, "get_random_weapon() did not set hp correctly");
        cr_assert_null(test_weapon->next, "get_random_weapon() did not set item->next correctly");
        cr_assert_null(test_weapon->prev, "get_random_weapon() did not set item->prev correctly");
    }
    else if (id == 8)
    {
        //  KATANA
        cr_assert_eq(test_weapon->is_weapon, true, "get_random_weapon() did not set is_weapon correctly"); 
        cr_assert_eq(test_weapon->effectiveness_decrement, 16, "get_random_weapon() did not set effectiveness_decrement correctly"); 
        cr_assert_eq(test_weapon->durability, 80, "get_random_weapon() did not set durability correctly");   
        cr_assert_str_eq(test_weapon->name, "KATANA", "get_random_weapon() did not set name correctly");
        cr_assert_null(test_weapon->description, "get_random_weapon() did not set description correctly");
        cr_assert_eq(test_weapon->battle, true, "get_random_weapon() did not set durability correctly");
        cr_assert_eq(test_weapon->attack, 80, "get_random_weapon() did not set attack correctly");
        cr_assert_eq(test_weapon->defense, 85, "get_random_weapon() did not set defense correctly");
        cr_assert_eq(test_weapon->hp, 90, "get_random_weapon() did not set hp correctly");
        cr_assert_null(test_weapon->next, "get_random_weapon() did not set item->next correctly");
        cr_assert_null(test_weapon->prev, "get_random_weapon() did not set item->prev correctly");
    }
    else if (id == 9)
    {
        // TASER
        cr_assert_eq(test_weapon->is_weapon, true, "get_random_weapon() did not set is_weapon correctly"); 
        cr_assert_eq(test_weapon->effectiveness_decrement, 18, "get_random_weapon() did not set effectiveness_decrement correctly"); 
        cr_assert_eq(test_weapon->durability, 90, "get_random_weapon() did not set durability correctly");   
        cr_assert_str_eq(test_weapon->name, "TASER", "get_random_weapon() did not set name correctly");
        cr_assert_null(test_weapon->description, "get_random_weapon() did not set description correctly");
        cr_assert_eq(test_weapon->battle, true, "get_random_weapon() did not set durability correctly");
        cr_assert_eq(test_weapon->attack, 90, "get_random_weapon() did not set attack correctly");
        cr_assert_eq(test_weapon->defense, 95, "get_random_weapon() did not set defense correctly");
        cr_assert_eq(test_weapon->hp, 100, "get_random_weapon() did not set hp correctly");
        cr_assert_null(test_weapon->next, "get_random_weapon() did not set item->next correctly");
        cr_assert_null(test_weapon->prev, "get_random_weapon() did not set item->prev correctly");
    }
    else if (id == 10)
    {
        // BAZOOKA
        cr_assert_eq(test_weapon->is_weapon, true, "get_random_weapon() did not set is_weapon correctly"); 
        cr_assert_eq(test_weapon->effectiveness_decrement, 20, "get_random_weapon() did not set effectiveness_decrement correctly"); 
        cr_assert_eq(test_weapon->durability, 100, "get_random_weapon() did not set durability correctly");   
        cr_assert_str_eq(test_weapon->name, "BAZOOKA", "get_random_weapon() did not set name correctly");
        cr_assert_null(test_weapon->description, "get_random_weapon() did not set description correctly");
        cr_assert_eq(test_weapon->battle, true, "get_random_weapon() did not set durability correctly");
        cr_assert_eq(test_weapon->attack, 100, "get_random_weapon() did not set attack correctly");
        cr_assert_eq(test_weapon->defense, 105, "get_random_weapon() did not set defense correctly");
        cr_assert_eq(test_weapon->hp, 110, "get_random_weapon() did not set hp correctly");
        cr_assert_null(test_weapon->next, "get_random_weapon() did not set item->next correctly");
        cr_assert_null(test_weapon->prev, "get_random_weapon() did not set item->prev correctly");
    }
    else
    {
        cr_assert_fail("get_random_weapon() did not set id correctly");
    }
}

Test(battle_default_objects, default_moves)
{
    move_t *test_move = get_random_default_move();

    char *name_array[] = {"SLAP", "JAB", "KICK", "HEADBUTT", "GRAPPLE", 
                          "UPPERCUT", "HAMMERFIST", "BITE", "THRASH", "THROW"};          

    int id = test_move->id;

    if (id == 1)
    {
        // SLAP
        cr_assert_str_eq(test_move->info, "SLAP", "get_random_default_move() did not set info correctly");
        cr_assert_eq(test_move->attack, true, "get_random_default_move() did not set attack correctly");
        cr_assert_eq(test_move->damage, 10, "get_random_default_move() did not set damage correctly");
        cr_assert_eq(test_move->defense, 15, "get_random_default_move() did not set defense correctly");                                            
    }        
    else if (id == 2)
    {
        // JAB
        cr_assert_str_eq(test_move->info, "JAB", "get_random_default_move() did not set info correctly");
        cr_assert_eq(test_move->attack, true, "get_random_default_move() did not set attack correctly");
        cr_assert_eq(test_move->damage, 20, "get_random_default_move() did not set damage correctly");
        cr_assert_eq(test_move->defense, 25, "get_random_default_move() did not set defense correctly");                                            
    }      
    else if (id == 3)
    {
        // KICK
        cr_assert_str_eq(test_move->info, "KICK", "get_random_default_move() did not set info correctly");
        cr_assert_eq(test_move->attack, true, "get_random_default_move() did not set attack correctly");
        cr_assert_eq(test_move->damage, 30, "get_random_default_move() did not set damage correctly");
        cr_assert_eq(test_move->defense, 35, "get_random_default_move() did not set defense correctly");                                            
    }     
    else if (id == 4)
    {
        // HEADBUTT
        cr_assert_str_eq(test_move->info, "HEADBUTT", "get_random_default_move() did not set info correctly");
        cr_assert_eq(test_move->attack, true, "get_random_default_move() did not set attack correctly");
        cr_assert_eq(test_move->damage, 40, "get_random_default_move() did not set damage correctly");
        cr_assert_eq(test_move->defense, 45, "get_random_default_move() did not set defense correctly");                                            
    }     
    else if (id == 5)
    {
        // GRAPPLE
        cr_assert_str_eq(test_move->info, "GRAPPLE", "get_random_default_move() did not set info correctly");
        cr_assert_eq(test_move->attack, true, "get_random_default_move() did not set attack correctly");
        cr_assert_eq(test_move->damage, 50, "get_random_default_move() did not set damage correctly");
        cr_assert_eq(test_move->defense, 55, "get_random_default_move() did not set defense correctly");                                            
    }     
    else if (id == 6)
    {
        // UPPERCUT
        cr_assert_str_eq(test_move->info, "UPPERCUT", "get_random_default_move() did not set info correctly");
        cr_assert_eq(test_move->attack, true, "get_random_default_move() did not set attack correctly");
        cr_assert_eq(test_move->damage, 60, "get_random_default_move() did not set damage correctly");
        cr_assert_eq(test_move->defense, 65, "get_random_default_move() did not set defense correctly");                                            
    }     
    else if (id == 7)
    {
        // HAMMERFIST
        cr_assert_str_eq(test_move->info, "HAMMERFIST", "get_random_default_move() did not set info correctly");
        cr_assert_eq(test_move->attack, true, "get_random_default_move() did not set attack correctly");
        cr_assert_eq(test_move->damage, 70, "get_random_default_move() did not set damage correctly");
        cr_assert_eq(test_move->defense, 75, "get_random_default_move() did not set defense correctly");                                            
    }     
    else if (id == 8)
    {
        // BITE
        cr_assert_str_eq(test_move->info, "BITE", "get_random_default_move() did not set info correctly");
        cr_assert_eq(test_move->attack, true, "get_random_default_move() did not set attack correctly");
        cr_assert_eq(test_move->damage, 80, "get_random_default_move() did not set damage correctly");
        cr_assert_eq(test_move->defense, 85, "get_random_default_move() did not set defense correctly");                                            
    }     
    else if (id == 9)
    {
        // THRASH
        cr_assert_str_eq(test_move->info, "THRASH", "get_random_default_move() did not set info correctly");
        cr_assert_eq(test_move->attack, true, "get_random_default_move() did not set attack correctly");
        cr_assert_eq(test_move->damage, 90, "get_random_default_move() did not set damage correctly");
        cr_assert_eq(test_move->defense, 95, "get_random_default_move() did not set defense correctly");                                            
    }     
    else if (id == 10)
    {
        // THROW
        cr_assert_str_eq(test_move->info, "THROW", "get_random_default_move() did not set info correctly");
        cr_assert_eq(test_move->attack, true, "get_random_default_move() did not set attack correctly");
        cr_assert_eq(test_move->damage, 100, "get_random_default_move() did not set damage correctly");
        cr_assert_eq(test_move->defense, 105, "get_random_default_move() did not set defense correctly");                                            
    }     
    else
    {
        cr_assert_fail("get_random_default_battle_item() did not set id correctly");
    }
}
