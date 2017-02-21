#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change;

    printf("O hai! How much change is owed?\n");
    change = GetFloat();

    if (change < 0)
    {
        do
        {
            printf("How much change is owed?\n");
            change = GetFloat();
        }
        while (change <0);
    }

    float multiplied = change * 100;
    int rounded =  roundf(multiplied);

    int quarters = roundf(rounded / 25);
    int afterquarters = rounded % 25;

    int dimes = roundf(afterquarters / 10);
    int afterdimes = afterquarters % 10;

    int nickles = roundf(afterdimes / 5);
    int afternickles = afterdimes % 5;

    int pennies = afternickles;

    printf("%d\n", quarters + dimes + nickles + pennies);
}
