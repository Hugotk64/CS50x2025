#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Functions declaration
int countLetter(string sentence, int length);
int countSentence(string sentence, int length);
int countWord(string sentence, int length);
bool sentenceLength(string sentence);
bool startEndSpace(string sentence, int length);
void grade(int index);

int main(void)
{
    // Prompt user for a sentence
    string sentence = get_string("sentence; ");

    // Validate the input has content and doesn´t start or end with space
    if (sentenceLength(sentence) && startEndSpace(sentence, strlen(sentence)))
    {
        // Count letters, sentences and words
        float letters = countLetter(sentence, strlen(sentence));
        float sentences = countSentence(sentence, strlen(sentence));
        float words = countWord(sentence, strlen(sentence));

        // Calculate average number of letters per 100 words
        float L = (letters / words) * 100;
        // Calculate average number of sentences per 100 words
        float S = (sentences / words) * 100;
        // Calculate index
        float index = (0.0588 * L) - (0.296 * S) - 15.8;

        // Output grade level
        grade(round(index));
    }
    else
    {
        printf("Error \n");
    }
}

// Count alphabetic characters in the sentence
int countLetter(string sentence, int length)
{
    int count = 0;

    for (int i = 0; i < length; i++)
    {
        // Check if the char is a letter
        if (toupper(sentence[i]) >= 'A' && toupper(sentence[i]) <= 'Z')
        {
            count++;
        } // Skip the char if it is not a letter
    }

    return count;
}

// Count the number of sentences based on punctuation
int countSentence(string sentence, int length)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (sentence[i] == '.' || sentence[i] == '!' || sentence[i] == '?')
        {
            count++;
        }
    }

    return count;
}

// Count the number of words based on spaces
int countWord(string sentence, int length)
{
    int count = 1;

    for (int i = 0; i < length; i++)
    {
        if (sentence[i] == ' ')
        {
            count++;
        }
    }

    return count;
}

// Validate that there are no double spaces
bool doubleSpace(string sentence, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        if (sentence[i] == ' ' && sentence[i + 1] == ' ')
        {
            return false;
        } // else no double space
    }

    return true;
}

// Validate that the sentence has at least one character
bool sentenceLength(string sentence)
{
    return strlen(sentence) > 0;
}

// Validate that the sentence does not start or end with a space
bool startEndSpace(string sentence, int length)
{
    for (int i = 0; i < length; i++)
    {
        // Check if the first char is a space
        if (sentence[0] == ' ' && i == 0)
        {
            return false;
        }
        // Last char is a space
        else if (sentence[i] == ' ' && i == length - 1)
        {
            return false;
        }
    }
    return true;
}

// print the grade level
void grade(int index)
{
    if (1 <= index && index <= 16)
    {
        printf("Grade %i\n", index);
    }
    else if (index > 16 )
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
}
