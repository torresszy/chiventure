/* This file holds enums for skilltrees */
#ifndef SKILLTREES_ENUMS_H_
#define SKILLTREES_ENUMS_H_
typedef enum sid {
    // Example 1
    UNLOCK_DOOR = 1000,

    // Example 2
    DEFUSE_BOMB = 1001,

    // Example 3
    CHOP_TREE = 1002,

    // Example 4
    INNER_PEACE = 1003,
} sid_t;

/* Skill type */
typedef enum skill_type {
    // Denotes active skill
    ACTIVE,

    // Denotes passive skill
    PASSIVE

} skill_type_t;

/*Types of readers*/
typedef enum reader_type{
    READER_ATTRIBUTE,

    READER_STATISTIC
} reader_type_t;

/*Locations of readers*/
typedef enum reader_location{
    READ_PLAYER,

    READ_SINGLE_TARGET,

    READ_WORLD
} reader_location_t;

/*Enums for stat reader and comparisons*/
typedef enum comparison {
    EQUALS,

    NOT,

    GREATER,

    LESSER,

    GREATER_EQUAL,

    LESSER_EQUAL
} comparison_t;

/*Different types of stats used in stats reader*/
typedef enum reader_stats{
    SPEED,

    DEFENSE,

    STRENGTH,

    HP,

    MAX_HP,
} stats_type_t;

/* Complex skill type */
typedef enum complex_skill_type {
    //Denotes combined complex skill
    COMBINED,

    //Denotes sequential complex skill
    SEQUENTIAL,

    //Denotes a random range effect
    RANDOM_RANGE,

    //Denotes a random chance effect
    RANDOM_CHANCE,

    //Denotes a random switch effect
    RANDOM_SWITCH,
    
    //Denotes conditional complex skill
    COMPLEX_CONDITIONAL

} complex_skill_type_t;

#endif /*SKILLTREES_ENUMS_H*/