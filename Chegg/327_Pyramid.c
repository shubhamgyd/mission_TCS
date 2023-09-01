#include <stdio.h>

int main()
{
    // print the following pattern
    for (int i = 1; i <= 5; i++)
    {
        int num = 5;
        for (int j = 0; j < i; j++)
        {
            // print the numbers
            printf("%d ", num);
            num--;
        }
        // print extra line
        printf("\n");
    }
    return 0;
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     char string[100];         // declare a character array to store the input string
//     int i, length, count = 0; // declare integer variables for loop, length and count

//     printf("Enter a string: "); // ask the user to input a string
//     scanf("%s", string);        // read the input string using scanf

//     length = strlen(string); // find the length of the input string

//     for (i = 0; i < length; i++)
//     { // loop through each character in the string
//         // check if the character is a vowel (lowercase or uppercase)
//         if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u' ||
//             string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U')
//         {
//             count++; // if the character is a vowel, increase the count by 1
//         }
//     }

//     printf("The number of vowels in the string is: %d", count); // print the total count of vowels

//     return 0;
// }
