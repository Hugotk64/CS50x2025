#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Function prototypes 
bool keyLength(string key);
bool keyAlphabetic(string key);
bool keyUnique(string key);

int main(int argc, string argv[])
{
    // Get key from command line
    string key = argv[1];

    // Validates Number of arguments
    if (argc != 2)
    {
        printf("Usage ./substitution key \n");
        return 1;
    }
    // Validates key
    else if (!keyLength(key) || !keyAlphabetic(key) || !keyUnique(key))
    {
        return 1;
    }
    else
    {
        // Get plaintext from user
        string plainText = get_string("plaintext: ");
        // Print ciphertext
        printf("ciphertext: ");

        // Iterate through each character in the plaintext
        for (int i = 0; i < strlen(plainText); i++)
        {
            // Check if the character is an uppercase or lowercase letter
            if (isupper(plainText[i]))
            {
                // Convert the character to uppercase and find its index in the alphabet
                printf("%c", toupper(key[plainText[i] - 'A']));
            }
            else if (islower(plainText[i]))
            {
                // Convert the character to lowercase and find its index in the alphabet
                printf("%c", tolower(key[plainText[i] - 'a']));
            }
            else
            {
                // If it's not a letter, print it as is
                printf("%c", plainText[i]);
            }
        }

        printf("\n");
    }

    return 0;
}

// Validates key length
bool keyLength(string key)
{
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }

    return true;
}

// Validates key alphabetic
bool keyAlphabetic(string key)
{
    // iterate each char in key
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters. \n");
            return false;
        }
    }
    return true;
}

// Validates key unique
bool keyUnique(string key)
{
    // Store used characters in an array
    bool used[26] = {false};

    for (int i = 0; i < strlen(key); i++)
    {
        char currentChar = toupper(key[i]); // Turn upper case
        int index = currentChar - 'A';      // Assign index

        if (used[index]) // If char is already used
        {
            printf("Key must not contain duplicated characters. \n");
            return false;
        }
        else
        {
            // Mark the character as used
            used[index] = true;
        }
    }

    return true;
}
