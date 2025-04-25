#include <cs50.h>
#include <stdio.h>

// Function declarations
void luhnsAlgorithm(long cardNumber);
bool checkSum(long cardNumber, int length);
int cardDigits(long cardNumber, int length);
int cardLength(long cardNumber);

int main(void)
{
    // Ask card number
    long cardNumber = get_long("What is the card number? ");
    luhnsAlgorithm(cardNumber);
}

// Determinates card type based on length, checksum and starting digits
void luhnsAlgorithm(long cardNumber)
{
    int length = cardLength(cardNumber);
    int digits = cardDigits(cardNumber, length);

    // Check if is valid length and valid checksum 
    if (length < 13 || length > 16 || !checkSum(cardNumber, length))
    {
        printf("INVALID\n");
    }
    // AMEX cards have 15 digits and start with 34 or 37
    else if (length == 15 && digits == 1)
    {
        printf("AMEX\n");
    }
    // Mastercard numbers have 16 digits and start with 51...55
    else if (length == 16 && digits == 2)
    {
        printf("MASTERCARD\n");
    }
    // Visa numbers starts with 4 and have 13 or 16 digits
    else if (digits == 3)
    {
        if (length == 16 || length == 13)
        {
            printf("VISA\n");
        }
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

// Validates card numbers using Luhn's algorithm
bool checkSum(long cardNumber, int length)
{
    int tempNumber = 0; // Temporarily individual digits
    int evenList = 0; // Storage digits from even position
    int oddList = 0;  // Storage digits from odd position
    int resultNumber = 0; // Final sum

    // Iterates each digit from the right
    for (int i = 1; i <= length; i++)
    {
        // If even number
        if (i % 2 == 0)
        {
            tempNumber = cardNumber % 10;          // Takes last digit
            tempNumber = tempNumber * 2;           // Multiply it by 2
            evenList = evenList * 10 + tempNumber; // Add it to even list
        }
        else // Odd position from the right
        {
            oddList = oddList * 10 + cardNumber % 10;
        }

        cardNumber = cardNumber / 10; // Remove last digit from number
    }

    // Add all digits from the evenList
    while (evenList > 0)
    {
        resultNumber += evenList % 10; // Add last digit of evenList
        evenList = evenList / 10;      // Remove last digit
    }

    //Add all digits from oddList
    while (oddList > 0)
    {
        resultNumber += oddList % 10; // Add last digit of oddList
        oddList = oddList / 10;       // Remove last digit
    }

    // Valid if ends in 0
    return resultNumber % 10 == 0;
}

// Determines the starting digit of the card to classify its type
int cardDigits(long cardNumber, int length)
{

    // Get the first two digits in card number
    while (length > 2)
    {
        cardNumber = cardNumber / 10; // Remove last digit
        length--;                     // Decrease the length
    }

    // Identify the card type based on prefix
    if (cardNumber == 34 || cardNumber == 37)
    {
        return 1; // AMEX
    }
    else if (cardNumber >= 51 && cardNumber <= 55)
    {
        return 2; // MASTERCARD
    }
    else if (cardNumber / 10 == 4)
    {
        return 3; // VISA
    }
    else
    {
        return 0; // INVALID
    }
}

// Calculate the number of digits in card number
int cardLength(long cardNumber)
{
    int count = 0;              // Count number of digits
    long tempCard = cardNumber; // Temporarily holds card number

    // Loop count digits
    while (tempCard > 0)
    {
        tempCard = tempCard / 10; // Remove last digit
        count++;                  // Increment counter
    }

    return count;
}
