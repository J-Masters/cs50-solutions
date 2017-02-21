#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("You need to give me an integer as a command line argument, try again");
        return 1;
    }

    int k = atoi(argv[1]);
    string text = GetString();

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                //formula for upper case encryption
                printf("%c", (text[i] - 65 + k ) % 26 + 65);
            }
            else
            {
                //formula for lower case encryption
                printf("%c", (text[i] - 97 + k ) % 26 + 97);
            }
        }

        else
        {
            printf("%c", text[i]);
        }
    }

    printf("\n");
}
