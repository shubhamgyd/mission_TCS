#include <stdio.h>

int main()
{
    // User input of integer
    printf("Enter number in range(1 to 4): ");
    int level;
    scanf("%d",&level);
    // Switch case to display student level
    switch(level)
    {
        // if 1 then show Freshman
        case 1:
            printf("Level of student: Freshman");
            break;
        // if 2 then show Sophomore
        case 2:
            printf("Level of student: Sophomore");
            break;
        // if 3 show Junior
        case 3:
            printf("Level of student: Junior");
            break;
        // if 4 then show Senior
        case 4:
            printf("Level of student: Senior");
            break;
        // desfault show invalid entry
        default:
            printf("Invalid Entry");
    }
    return 0;
}