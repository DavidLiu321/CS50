#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

bool all_alphabet(string s);

int key_change;
int answer_index;

int main(int argc, string argv[])
{
    // if not given 2 cmd line arguments or keyword contains non alphabet letter, exit
    if ((argc != 2) || (!(all_alphabet(argv[1]))))
    {
        printf("You didn't give a keyword composed of only letters!\n");
        return 1;
    }

    string key = argv[1];
    int key_length = strlen(key);

    // retrieve the text to be encrypted from user and find its stringlength
    string plaintext = get_string("plaintext: ");
    int text_length = strlen(plaintext);

    printf("ciphertext: ");

    // iterate through each character of the plaintext
    for (int p = 0, k = 0; p < text_length; p++)
    {
        // use modulo to reset key character index if it reaches key_length
        k = k % key_length;

        // set the level of index change for encryption
        if (isupper(key[k]))
        {
            key_change = key[k] - 'A';
            answer_index = plaintext[p] + key_change;
        }
        else
        {
            key_change = key[k] - 'a';
            answer_index = plaintext[p] + key_change;
        }

        // if the character is an alphabetical letter, roll it through the key, else print out the non-alphabetical character
        if (isupper(plaintext[p])) //execute if current plaintext letter is uppercase
        {
            // if the changed index exceeds 'Z', wrap the index around back to 'A'
            if (answer_index > 'Z')
            {
                answer_index = 'A' + answer_index - ('Z' + 1);
                printf("%c", answer_index);
            }
            else
            {
                printf("%c", answer_index);
            }
            k++;
        }
        //execute if current plaintext letter is lowercase
        else if (islower(plaintext[p]))
        {
            // if the changed index exceeds 'z', wrap the index around back to 'a'
            if (answer_index > 'z')
            {
                answer_index = 'a' + answer_index - ('z' + 1);
                printf("%c", answer_index);
            }
            else
            {
                printf("%c", answer_index);
            }
            k++;
        }
        //print out the current plaintext character if current plaintext letter is not alphabetical
        else
        {
            printf("%c", plaintext[p]);
        }
    }

    printf("\n");
}

// this function makes sure every char in the key is an alphabetical letter
bool all_alphabet(string s)
{
    int arg_length = strlen(s);
    for (int n = 0; n < arg_length; n++)
    {
        if (!(isupper(s[n])) && !(islower(s[n])))
        {
            return false;
        }
    }
    return true;
}
