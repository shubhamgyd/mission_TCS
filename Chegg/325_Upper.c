#include <stdio.h>

// Function which converts index into the uppercase letter
char getalphabetindex(int index)
{
    char integer = 'A' + index;
    return integer;
}

int main(void)
{
    // variable to check if user want to print upper case letter or not
    char is_uppercase;
    printf("Uppercase: ");
    scanf("%c", &is_uppercase);

    // get the index between 0-25
    int index;
    printf("Index: ");
    scanf("%d", &index);

    // get the letter at a given specified index
    char integer;
    // if upper case
    if (is_uppercase == 'y')
    {
        // get upper case letter
        integer = getalphabetindex(index);
    }
    // else if  get lower case letter
    else if (is_uppercase == 'n')
    {
        integer = 'a' + index;
    }
    // else print error
    else
    {
        printf("ERROR: Ypu did not enter 'y' or 'n'\n");
    }
    // print the appropriate char
    printf("The letter is %c\n", integer);
}