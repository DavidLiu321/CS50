#include <cs50.h>
#include <stdio.h>
#include <math.h>

int cardlength(long long n);
int firstdigits(long long c, int m);

int main(void)
{
    long long cardnum;
    long long dividefactor = 10;
    long long modulofactor = 100;
    int productsdigits = 0;
    int currentdigit = 0;

    // prompt user for valid info
    do
    {
        cardnum = get_long_long("Number: ");
    }
    while (cardnum < 0);

    int first2nums = firstdigits(cardnum, 2);
    int lengthcard = cardlength(cardnum);

        // multiply every other digit by 2 and add each product together
        while ((modulofactor / 10) < cardnum)
        {
            //retrieve the desired digit
            currentdigit = round(floor((cardnum % modulofactor) / dividefactor));
            //multiple desired digit by 2
            currentdigit = currentdigit * 2;
            //if the product of the desired digit * 2 exceeds 9, add the two separate digits
            if (currentdigit > 9)
            {
                productsdigits = productsdigits + (currentdigit % 10) + (round(floor(currentdigit / 10)));
            }
            // else add the product to the sum of products
            else
            {
                productsdigits = productsdigits + currentdigit;
            }

            // increase the modulofactor and divide factor to find next digit
            modulofactor = modulofactor * 100;
            dividefactor = dividefactor * 100;
        }

        //reset modulofactor, dividefactor
        modulofactor = 10;
        dividefactor = 1;
        // find the sum of the digits not multiplied by 2
        // add every other digit starting at first digit
        while ((modulofactor / 10) < cardnum)
        {
            // find the desired digit
            currentdigit = round(floor((cardnum % modulofactor) / dividefactor));

            // add the desired digit onto the product of digits so far
            productsdigits = productsdigits + currentdigit;

            // increase the modulofactor and divide factor to find next digit
            modulofactor = modulofactor * 100;
            dividefactor = dividefactor * 100;

        }

        //check if the checksum gives a valid value
        if (productsdigits % 10 == 0)
        {
            // check if the card is an American Express card
            if ( (lengthcard == 15) && ( (first2nums == 34) || (first2nums == 37) ) )
            {
                printf("AMEX\n");
            }
            // check if card is a MasterCard
            else if ((lengthcard == 16) && ((first2nums == 51) || (first2nums == 52) || (first2nums == 53) || (first2nums == 54) || (first2nums == 55)))
            {
                printf("MASTERCARD\n");
            }
            // check if card is a Visa Card
            else if ( ((lengthcard == 16) || (lengthcard == 13)) && (firstdigits(cardnum, 1) == 4) )
            {
                printf("VISA\n");
            }
            // if none of these cards, it is invalid
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }

}

// this functions returns the number of digits in the card
int cardlength(long long n)
{
    int digitsincard = 1;
    long long carddivider = n;

    while (carddivider > 10)
    {
        digitsincard++;
        carddivider = carddivider / 10;
    }

    return digitsincard;
}

//returns first m digits in c
int firstdigits(long long c, int m)
{

    // find the factor that we should divide by
    long long divider = round(pow(10, cardlength(c)) / pow(10, m));

    // divide the cardnumber so that only 2 digits are to the left of the decimal point
    // floor the number received to get rid of numbers after decimal, then round

    int firstndigits = round(floor(c / divider));

    return firstndigits;
}
