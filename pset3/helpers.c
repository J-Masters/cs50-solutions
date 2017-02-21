/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    //make sure n is positive
    if (n < 1)
    {
        return false;
    }

    int min = 0;
    int max = n - 1;
    int mid = (min + max) / 2;

    do
    {
        mid = (min + max) / 2;

        if (values[mid] == value)
        {
            return true;
        }
        else if (values[mid] < value)
        {
            min = mid + 1;
        }
        else
        {
            max = mid - 1;
        }
    }
    while (values[mid] != value);

    //return false if the needle isn't found
    return false;
}


/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int swap_counter = -1;

    do
    {
        swap_counter = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (values[i] > values[i + 1])
            {
                //swap if first value is higher than second value
                int k = values[i];
                values[i + 1] = values[i];
                values[i] = k;

                //add 1 to swap counter for each swap
                swap_counter = swap_counter + 1;
            }
        }
    }
    //loop until there are no swaps
    while ( swap_counter != 0);

    return;
}
