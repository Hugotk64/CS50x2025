#include <cs50.h>
#include <stdio.h>

void buildPyramid(int size);
int getPyramidSize();

int main(void)
{
    int size = getPyramidSize(); // Ask user for pyramid's height
    buildPyramid(size);
}

int getPyramidSize()
{
    int size;
    // Repeat promt to user until a valid size is entered
    do
    {
        size = get_int("set how tall is the pirymind between 1 and 8: ");
    }
    while (size < 1 || size > 8);
    return size;
}

void buildPyramid(int size)
{
    // Repets for each row of pyramid
    for (int i = 1; i <= size; i++) // starts in 1 till size
    {
        // LEFT SIDE
        // Print speaces before left blocks to align pyramid to the right
        for (int lblank = 0; lblank < size - i; lblank++)
        {
            printf(" ");
        }
        // Print left-side blocks #, equal to the current row number
        for (int lblock = 0; lblock < i; lblock++)
        {
            printf("#");
        }

        // Print the gap in the pyramid
        printf("  ");

        // RIGHT SIDE
        // Print right-side blocks #, equal to the current row number
        for (int rblock = 0; rblock < i; rblock++)
        {
            printf("#");
        }

        // Moves to the next line
        printf("\n");
    }
}
