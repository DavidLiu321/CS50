#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float input;

    // prompt user for amount of change owed, repeat if received invalid input
    do
    {
        input = get_float("Change owed: ");
    }
    while (input < 0);

    // convert dollar value to cents and round to get rid of error
    int cents = round(input * 100);
    // set beginning count of coins to 0
    int coincount = 0;

    // add number of usable quarters to coincount, decrease owed by usable quarter value
    if (cents >= 25)
    {
        coincount = coincount + ((cents - (cents % 25)) / 25);
        cents = cents % 25;
    }

    // add number of usable dimes to coincount, decrease owed by usable dime value
    if (cents >= 10)
    {
        coincount = coincount + ((cents - (cents % 10)) / 10);
        cents = cents % 10;
    }

    // add number of usable nickel to coincount, decrease owed by usable nickel value
    if (cents >= 5)
    {
        coincount = coincount + ((cents - (cents % 5)) / 5);
        cents = cents % 5;
    }
    // add number of usable pennies to coincount, decrease owed by usable penny value
    if (cents >= 1)
    {
        coincount = coincount + ((cents - (cents % 1)) / 1);
        cents = cents % 1;
    }

    printf("%i\n", floor(6.321242123));

    printf("%i\n", coincount);

}
