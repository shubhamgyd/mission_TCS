#include <stdio.h>

int main()
{
    // Keep track on maximum number
    int mx = 0;
    // Input intil user want
    printf("Enter sequence of positive integers (first non-positive number ends sequence): \n");
    while (1)
    {
        // Get user input
        int num;
        scanf("%d", &num);
        // If entered number is 0 or less than zero
        // break the loop
        if (num <= 0)
        {
            break;
        }
        // Else update the maximum value
        else
        {
            if (num > mx)
            {
                mx = num;
            }
        }
    }
    // Print Biggest value
    printf("Biggest value found in the secret integers is equals %d ", mx);
}