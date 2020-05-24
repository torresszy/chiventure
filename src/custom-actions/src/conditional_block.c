/* 
 * Basic functions and structs for conditional blocks to be 
 * used in custom-actions implementation. 
 * 
 * Please see "conditional_block.h" for function documentation. 
 */

#include <stdlib.h>
#include <stdio.h>
#include "game-state/item.h" 
#include "../include/conditional_block.h"

/* See conditional_block.h */
conditional_block_t* conditional_block_new(enum conditional_type conditional_type, 
attribute_t* left, attribute_t* right)
{
    conditional_block_t *conditional;
    int new_conditional;

    conditional = malloc(sizeof(conditional_block_t));

    if (conditional == NULL) 
    {
        fprintf(stderr,"Could not allocate memory");
        return NULL;
    }

    new_conditional = conditional_block_init(conditional, conditional_type, left, 
    right);
    if (new_conditional != SUCCESS)
    {
        fprintf(stderr,"Could not initialize conditional_block_t");
        return NULL;
    }

    return conditional; 
}

/* See conditional_block.h */
int conditional_block_init(conditional_block_t *conditional, enum conditional_type 
conditional_type, attribute_t* left, attribute_t* right)
{
    assert(conditional != NULL);
    assert(left != NULL);
    assert(right != NULL);

    conditional->conditional_type = conditional_type;
    conditional->left = left;
    conditional->right = right;
        
    return SUCCESS; 
}

/* See conditional_block.h */
int conditional_block_free(conditional_block_t *conditional)
{
    assert(conditional != NULL);
        
    free(conditional);

    return SUCCESS; 
}
