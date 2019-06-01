#include "uthash.h"
#include <stdbool.h>

#ifndef INCLUDE_OBJ_H
#define INCLUDE_OBJ_H

#define MAXLEN_DATA 1024 // strings containing data
#define MAXLEN_ID 60 // ID strings for objects
#define MAX_DEPTH 20 // max search depth for accessing properties
#define MAXLEN_SEARCH ((MAXLEN_ID + 1) * MAX_DEPTH)

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

// All datatypes that can be encoded in an obj
typedef enum datatype
{
    TYPE_ERR  = -1,
    TYPE_NONE = 0,
    TYPE_BOOL = 1,
    TYPE_CHAR = 2,
    TYPE_INT  = 3,
    TYPE_STR  = 4
} datatype_t;

/* A simple object model using strings as attribute identifiers */
typedef struct obj
{
    // The identifier of the object- must be unique for the parent object
    char id[MAXLEN_ID + 1];

    // The type of the data
    datatype_t type;

    // The data associated with the object
    union
    {
        bool b;
        char c;
        char *s;
        int  i;
    } data;

    // The object's attributes (a hash table)
    struct obj *attr;
    
    // Required uthash identifier for making the hash table
    UT_hash_handle hh;

} obj_t;

/* A doubly linked list to hold a list of an object's attributes */
typedef struct attr_list
{
    // One attribute of an object
    obj_t *obj;
    
    // Next attribute in the linked list
    struct attr_list *next;

    // Previous attribute in the linked list
    struct attr_list *prev;

} attr_list_t;

/*
 * Creates a new object with identifier id
 * 
 * Parameters:
 *  - id: The id for the object
 * 
 * Returns:
 *  - The newly created and initialized object on success
 *  - NULL on error
 */
obj_t *obj_new(char *id);

/*
 * Initializes a new object with identifier id
 * 
 * Parameters:
 *  - obj: The object to initialize
 *  - id:  The id for the object
 * 
 * Returns:
 *  - EXIT_SUCCESS on successful initialization
 *  - EXIT_FAILURE otherwise
 */
int obj_init(obj_t *obj, char *id);

/*
 * Frees an object
 * 
 * Parameters:
 *  - obj: The object to initialize
 * 
 * Returns:
 *  - Always return EXIT_SUCCESS
 */
int obj_free(obj_t *obj);

/*
 * Frees all memory associated with an object
 *   Will also free all attributes
 * 
 * Parameters:
 *  - obj: The object to initialize
 * 
 * Returns:
 *  - Always return EXIT_SUCCESS
 */
int obj_free_all(obj_t *obj);

/*
 * Finds an attribute of an object (or an attribute's attribute, etc)
 *   - Uses dot notation to get attributes ("attr.sub_attr.sub_sub_attr")
 *   - "self" or "." will refer to the object itself
 *   - The search string must be shorter than the max recursion depth
 * 
 * Parameters:
 *  - obj: The object to find the attribute of
 *  - id: The id of the attribute
 *  - create: whether or not to create a new attribute if no attribute
 *      is found
 * 
 * Returns:
 *  - Returns the object if it is found or created (create = true)
 *  - Returns NULL if error or not found (create = false)
 */
obj_t *obj_get_attr(obj_t *obj, char *id, bool create);

/*
 * Lists all immediate attributes of an object
 *   - Will not do a recursive search
 * 
 * Parameters:
 *  - obj: The object to find the attributes of
 * 
 * Returns:
 *  - Returns a linked list of attributes of the objects
 *  - Returns NULL on no attributes found or failure
 */
attr_list_t *obj_list_attr(obj_t *obj);

/*
 * Adds an attribute to an object
 *   - Uses dot notation to place attributes ("attr.sub_attr.sub_sub_attr")
 *   - Will create intermediate objects if the obj does not 
 *      already have those properties
 *   - The search string must be shorter than the max recursion depth
 * 
 * Parameters:
 *  - obj: The object to add the attribute to
 *  - id: The id the attribute will have
 *  - attr: The attribute to add to the object
 * 
 * Returns:
 *  - Returns EXIT_SUCCESS if attribute successfully added
 *  - Returns EXIT_FAILURE otherwise
 */
int obj_add_attr(obj_t *obj, char *id, obj_t *attr);

/*
 * Removes an attribute from an object
 *   - Uses dot notation to place attributes ("attr.sub_attr.sub_sub_attr")
 * 
 *   - TODO- remove intermediate objects if the obj does not
 *      have any data-containing properties
 *   - The search string must be shorter than the max recursion depth
 * 
 * Parameters:
 *  - obj: The object to remove the attribute from
 *  - id: The id of the attribute to remove
 * 
 * Returns:
 *  - Returns EXIT_SUCCESS if attribute successfully removed
 *  - Returns EXIT_FAILURE otherwise
 */
int obj_remove_attr(obj_t *obj, char *id);


/*
 * Returns the type of an attribute of an object
 *   - Uses dot notation to get attributes ("attr.sub_attr.sub_sub_attr")
 *   - "self" or "." will refer to the object itself
 *   - The search string must be shorter than the max recursion depth
 * 
 * Parameters:
 *  - obj: The object to find the attribute of
 *  - id: The id of the attribute
 * 
 * Returns:
 *  - Returns the type of the object
 *  - Returns TYPE_ERR if error or not found
 */
datatype_t obj_get_type(obj_t *obj, char *id);

/*
 * These functions get an object's attribute's value for various types
 *   - Uses dot notation to place attributes ("attr.sub_attr.sub_sub_attr")
 *   - The search string must be shorter than the max recursion depth
 *   - Use obj_get_type if the target type is unknown to determine which 
 *     version to use
 * 
 * Parameters:
 *  - obj: The object to get the attribute's value from
 *  - id: The id of the attribute to get the value of
 * 
 * Returns:
 *  - Returns the value in the object if successfully found
 *  - Returns the 0 equivalent for that datatype if not found or 
 *      wrong type
 */
bool obj_get_bool(obj_t *obj, char *id);
char obj_get_char(obj_t *obj, char *id);
int obj_get_int(obj_t *obj, char *id);
char *obj_get_str(obj_t *obj, char *id);

/*
 * These functions set an object's attribute's value for various types
 *   - Uses dot notation to place attributes ("attr.sub_attr.sub_sub_attr")
 *   - Will create intermediate objects if the obj does not 
 *      already have those properties
 *   - The search string must be shorter than the max recursion depth
 * 
 * Parameters:
 *  - obj: The object to set the attribute's value of
 *  - id: The id of the attribute to set the value of
 *  - value: The value to set the attribute's value to
 * 
 * Returns:
 *  - Returns EXIT_SUCCESS if successfully set
 *  - Returns EXIT_FAILURE on failure
 */
int obj_set_bool(obj_t *obj, char *id, bool value);
int obj_set_char(obj_t *obj, char *id, char value);
int obj_set_int(obj_t *obj, char *id, int value);
int obj_set_str(obj_t *obj, char *id, char *value);

#endif /* INCLUDE_OBJ_H */