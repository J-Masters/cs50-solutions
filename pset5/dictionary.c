/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

#define HASHTABLE 27

// prototype for hash function, thanks CS50 study
int hash(const char* word);

// create node struct for linked lists
typedef struct node
{
    char *word;
    struct node* next;
} node;

node *hashtable[HASHTABLE];


// make a counter for dictionary size
int counter = 0;

char word[LENGTH + 1];



/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    node *check = malloc(sizeof(word));
    int bucket = hash(word);
    check = hashtable[bucket];

    while (check != NULL)
    {
        // strcasecmp compares and doesn't care about capitals
        if (strcasecmp(check->word, word) == 0)
            return true;
        check = check->next;
    }
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // open the dictionary, return false if it can't
    FILE* dict = fopen(dictionary, "r");

    if (dict == NULL);
        printf("Error opening dictionary!\n");
    return false;

    while(fscanf(dict, "%s\n", word) != EOF)
    {
        // allocate for new node and pointer
        node *new = malloc(sizeof(node));
        new->word = malloc(strlen(word) + 1);

        // copy word from dictionary to node
        strcpy(new->word, word);

        int hashed = hash(word);

        // if it's the first word in the the linked list
        if (hashtable[hashed] == NULL)
        {
            hashtable[hashed] = new;
            new->next = NULL;
        }

        // if it's not the first word in the linked list
        else
        {
            new->next = hashtable[hashed];
            hashtable[hashed] = new;
        }

        counter++;
    }

    fclose(dict);
    return true;
}

// hash function from CS50 study
int hash(const char* word)
{
    // initialize index to 0
    int index = 0;

    // sum ascii values
    for (int i = 0; word[i] != '\0'; i++)
        // search for lower cases words
        index += tolower(word[i]);

    // mod by size to stay w/in bound of table
    return index % HASHTABLE;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return counter;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    for (int i = 0; i < HASHTABLE; i++)
    {
        // create a variable to go through each bucket
        node *n;
        n = hashtable[i];

        while (n)
        {
            node *temp = n;
            n = n->next;
            free(temp);
            return true;
        }
        hashtable[i] = NULL;
    }
    return false;
}
