#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "cli/parser.h"

int compare_list_cmds(char** str, int size, char** expected_words)
{
        tokenized_cmds* words = parse_r(str)
        tokenized_cmds* temp;
        int i = 0;
        LL_FOREACH(words,temp)
        {
            if (i < size)
            {
                if strcmp((expected_words[i], temp->cmds) == 0)
                {
                    continue;
                }
                else 
                {
                    return 0;
                }
            }
            else 
            {
                return 0;
            }
        }
        return 1;          
}

void check_comparison(char** str, int size, char** expected_words, int expected)
{
    int check = compare_list_cmds(words, size, expected_words)
    cr_assert_eq(check, expected, "got %d but expected %d");
}

Test(parse_r, check_overlap_does_not_intersect)
{
    check_circle_overlap(3.0, 4.0, 14.0, 18.0, 5.0, 8.0, 0);
}


//Tests the parsing of an empty input, which should return NULL.
//Test(parse_r, no_input_r)
/*{
    char str[] = "";
    tokenized_cmds *words = parse_r(str);
    cr_assert_null(words, "parser() should return NULL if no input");
}

//Tests the parsing of a single word.
Test(parse_r, single_r)
{
    char str[] = "LOOK";
    tokenized_cmds *words = parse_r(str);
    cr_assert_str_eq(words->cmds,"LOOK", "parse() did not create first token");
    cr_assert_null(words[1], "parse() should point to NULL for empty tokens");
    
}

//Tests the parsing of two words.
Test(parse_r, two_words_r)
{
    char str[] = "LOOK AND AT";
    tokenized_cmds/* **words = parse(str);
    cr_assert_str_eq(words[0],"LOOK", "parse() did not create first token");
    cr_assert_str_eq(words[1], "AT", "parse() did not create second token");
    cr_assert_null(words[2],"parse() should point to NULL for empty tokens");
    cr_assert_null(words[3],"parse() should point to NULL for empty tokens");
}

//Tests the parsing of an empty input, which should return NULL.
Test(parse, no_input)
{
    char str[] = "";
    char **words = parse(str);
    cr_assert_null(words, "parser() should return NULL if no input");
}*/

//Tests the parsing of a single word.
Test(parse, single)
{
    char str[] = "LOOK";
    char **words = parse(str);
    cr_assert_str_eq(words[0],"LOOK", "parse() did not create first token");
    cr_assert_null(words[1], "parse() should point to NULL for empty tokens");
    cr_assert_null(words[2], "parse() should point to NULL for empty tokens");
    cr_assert_null(words[3], "parse() should point to NULL for empty tokens");
}

//Tests the parsing of two words.
Test(parse, two_words)
{
    char str[] = "LOOK AT";
    char **words = parse(str);
    cr_assert_str_eq(words[0],"LOOK", "parse() did not create first token");
    cr_assert_str_eq(words[1], "AT", "parse() did not create second token");
    cr_assert_null(words[2],"parse() should point to NULL for empty tokens");
    cr_assert_null(words[3],"parse() should point to NULL for empty tokens");
}

//Tests the parsing of three words.
Test(parse, three_words)
{
    char str[] = "LOOK AT ME";
    char **words = parse(str);
    cr_assert_str_eq(words[0],"LOOK", "parse() did not create first token");
    cr_assert_str_eq(words[1], "AT", "parse() did not create second token");
    cr_assert_str_eq(words[2], "ME", "parse() did not create third token");
    cr_assert_null(words[3],"parse() should point to NULL for empty tokens");
}

//Tests the parsing of four words.
Test(parse, four_words)
{
    char str[] = "LOOK AT ME NOT";
    char **words = parse(str);
    cr_assert_str_eq(words[0],"LOOK", "parse() did not create first token");
    cr_assert_str_eq(words[1], "AT", "parse() did not create second token");
    cr_assert_str_eq(words[2], "ME", "parse() did not create third token");
    cr_assert_str_eq(words[3], "NOT", "parse() did not create fourth token");
}

//Tests the parsing of five words. (Having more words than 4 causes the parser to return NULL)
Test(parse, more_words)
{
    char str[] = "LOOK AT ME NOT YEAH";
    char **words = parse(str);
    cr_assert_null(words, "parser() should return NULL if more than 4 words");
}

//Tests the parsing of input with many spaces between each word.
Test(parse, many_spaces)
{
    char str[] = "LOOK    AT        ME              ";
    char **words = parse(str);
    cr_assert_str_eq(words[0],"LOOK", "parse() did not create first token");
    cr_assert_str_eq(words[1], "AT", "parse() did not create second token");
    cr_assert_str_eq(words[2], "ME", "parse() did not create third token");
    cr_assert_null(words[3],"parse() should point to NULL for empty tokens");
}
