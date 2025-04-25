#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int pointLetter(char letter);
int wordIteration(string word, int length);

int main(void)
{
    // Declare arrays to hold players word and score
    string words[2] = {"", ""};
    int scores[2] = {0, 0};

    // Loop to get players input
    do
    {
        words[0] = get_string("Player 1: ");
        words[1] = get_string("Player 2: ");
    }
    while (strlen(words[0]) < 1 && strlen(words[1]) < 1); // Repeat until valid input

    // Calculate scores for each player
    for (int i = 0; i < 2; i++)
    {
        scores[i] = wordIteration(words[i], strlen(words[i]));
    }

    // Compare scores to determine winner
    if (scores[0] > scores[1])
    {
        printf("Player 1 wins!\n");
    }
    else if (scores[0] < scores[1])
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Function to calculate the score of a word
int wordIteration(string word, int length)
{
    int score = 0;

    for (int i = 0; i < length; i++)
    {
        // Convert letter to uppercase to calculate score
        score += pointLetter(toupper(word[i]));
    }

    printf("Score %i\n", score);
    return score;
}

// Function to return the score of a letter
int pointLetter(char letter)
{
    switch (letter)
    {
        case 'A': case 'E': case 'I': case 'O': case 'U':
        case 'L': case 'N': case 'S': case 'T': case 'R':
            return 1;
        case 'D': case 'G':
            return 2;
        case 'B': case 'C': case 'M': case 'P':
            return 3;
        case 'F': case 'H': case 'V': case 'W': case 'Y':
            return 4;
        case 'K':
            return 5;
        case 'J': case 'X':
            return 8;
        case 'Q': case 'Z':
            return 10;
        default:
            return 0;
    }
}
