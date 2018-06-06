#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define ALPHABET_LENGTH 26

int main(int argc, string argv[])
{
    // check if the user input one command line argument
    if (argc != 2)
    {
        printf("You did not give a non negative integer\n");
        return 1;
    }
    // turn the string type number into an integer type
    // use modulo to wrap the integer back to 1 in case the integer is greater than 26
    int k = (atoi(argv[1])) % ALPHABET_LENGTH;

    //get the string to be encoded and find its string length
    string plaintext = get_string("Plaintext: ");
    int text_length = strlen(plaintext);

    printf("ciphertext: ");
    // iterate through each letter(character) in the string given
    for (int n = 0; text_length > n; n++)
    {
        // if the current character is a letter, then roll it through the key
        if (((plaintext[n] >= 'A') && (plaintext[n] <= 'Z'))) // operates on uppercase letter
        {
            int answer_index = plaintext[n] + k;

            // if the rolled uppercase char index passes Z, reset the index to 'A' and add the difference
            if (answer_index > 'Z')
            {
                answer_index = 'A' + (answer_index - 'Z') - 1;
                printf("%c", answer_index);
            }
            // else just print the answer index
            else
            {
                printf("%c", answer_index);
            }
        }
        else if (((plaintext[n] >= 'a') && (plaintext[n]) <= 'z')) // operates on lowercase letter
        {
            int answer_index = plaintext[n] + k;

            // if the rolled uppercase char index passes z, reset the index to 'a' and add the difference
            if (answer_index > 'z')
            {
                answer_index = 'a' + (answer_index - 'z') - 1;
                printf("%c", answer_index);
            }
            // else just print the answer index
            else
            {
                printf("%c", answer_index);
            }

        }
        // if the current character is not a letter, then do not change it.
        else
        {
            printf("%c", plaintext[n]);
        }
    }
    printf("\n");

}
