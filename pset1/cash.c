//Program that asks owed change and prints the minimum number of coins with which that change can be made

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //Prompts for owed change (must be a positive float value)

    float dollars;
    do
    {
        dollars = get_float("Cash Owed: ");
    }
    while (dollars < 0);

    //Converts dollars to cents and rounds to the nearest penny (using round function declared in math.h, this reduces floating-point imprecisions)

    int cents = round(dollars * 100);
    int coins = 0;

    //Computing coins

    while (cents >= 25)
    {
        cents -= 25;
        coins++;
    }

    while (cents >= 10)
    {
        cents -= 10;
        coins++;
    }

    while (cents >= 5)
    {
        cents -= 5;
        coins++;
    }

    while (cents >= 1)
    {
        cents -= 1;
        coins++;
    }

    printf("%i\n", coins);
}
