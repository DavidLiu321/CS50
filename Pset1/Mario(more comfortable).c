#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // receive desired height of pyramid from user
    int rows;
    do
    {
        rows = get_int("Height: ");
    }
    while (rows < 0 || rows > 23);

    // repeat over the number of rows given
    for (int r = 0; r < rows; r++)
    {
        // print out number of spaces needed based on current row number
        for (int s = 0; s < (rows - (r + 1)); s++)
        {
            printf(" ");
        }

        // print out number of hashtags needed on left side based on current row number
        for (int h = 0; h < (r + 1); h++)
        {
            printf("#");
        }

        // print out the gap between the two pyramid halves
        printf("  ");

        // print out number of hashtags needed on right side based on current row number
        for (int h = 0; h < (r + 1); h++)
        {
            printf("#");
        }

        // repeat process on a new line
        printf("\n");
    }
}
