#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name = GetString();

    //print capitalized first char
    printf("%c", toupper(name[0]));

    //go through string and print capital char after any space
    for ( int i = 0, n = strlen(name); i < n; i++)
    {
        if (name[i] == ' ')
        {
            printf("%c", toupper(name[i+1]));
        }
    }
    printf("\n");
}
