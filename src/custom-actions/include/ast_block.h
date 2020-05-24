/* 
 * Functions and structs to be used in AST_block_t implementation
 */

#ifndef INCLUDE_AST_BLOCK_H
#define INCLUDE_AST_BLOCK_H

#include <stdlib.h>
#include <stdio.h>
#include "game-state/item.h"
#include "action_block.h"
#include "branch_block.h"
#include "conditional_block.h"
#include "control_block.h"

/* An enumeration type for an AST block */
typedef enum block_type {
    CONTROL, 
    BRANCH, 
    ACTION, 
    CONDITIONAL
} block_type;

/* Struct to represent the type of a block */
typedef union block {
    control_block_t *control_block;
    branch_block_t *branch_block;
    action_block_t *action_block;
    conditional_block_t *conditional_block;
} block_t;


/* Struct to contain a block, as well as its type */
typedef struct AST_block {
    block_t *block;
    enum block_type block_type;
    AST_block_t *next;
} AST_block_t;


/* 
 * Allocates an AST block in the heap. 
 * 
 * Parameters: 
 * - block: either a control, branch, action or conditional block 
 * - enum representing the type of block
 * 
 * Returns: 
 * - A block. 
 */
AST_block_t* AST_block_new(enum block_type block_type);

/* 
 * Initializes an AST block. 
 * 
 * Parameters: 
 * - AST block. Must point to already allocated memory. 
 * - block, block_type: parameters that define the block
 * 
 * Returns: 
 * - SUCCESS if success, FAILURE if error occurs
 */
int AST_block_init(AST_block_t *ast, block_t *block, enum block_type block_type);

/* 
 * Frees an AST block. 
 * 
 * Parameters: 
 * - AST block. Must point to an AST block allocated with AST_block_new. 
 * 
 * Returns: 
 * - Always returns 0. 
 */
int AST_block_free(AST_block_t *ast);

#endif /* INCLUDE_AST_BLOCK_H */
