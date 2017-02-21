#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("You need to give a single command line argument consisting of only alphabetical characters, try again.\n");
        return 1;
    }

    string keyword = argv[1];
    int x = strlen(keyword);

    //check to see if there are any non alphabetical characters in the keyword
    for (int i = 0; i < x; i++)
    {
        if (!isalpha(keyword[i]))
        {
            printf("Your single command line argument doesn't consist of only alphabetical characters, try again.\n");
            return 1;
        }
    }

    string text = GetString();

    for (int i = 0, j = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            //find the key for each character
            int k;
            if (isupper(keyword[j % x]))
            {
                k = keyword[j % x] - 'A';
            }
            else
            {
                k = keyword[j % x] - 'a';
            }
            //increment j here so it doesn't increment for spaces or special characters
            j++;

            //encrypt the characters
            if (isupper(text[i]))
            {
                //formula for upper case text encryption
                printf("%c", (text[i] - 'A' + k) % 26 + 'A');
            }
            else
            {
                //formula for lower case text encryption
                printf("%c", (text[i] - 'a' + k) % 26 + 'a');
            }
        }
        else
        {
            //if it's not an alphabetical character, just print it
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
