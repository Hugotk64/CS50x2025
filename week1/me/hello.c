#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Ask name to user
    string name = get_string("What is your name? ");
    // Print hello message with user´s name
    printf("Hello, %s\n", name);
}