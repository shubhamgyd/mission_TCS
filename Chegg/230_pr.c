#include <stdio.h>
void main()
{
    // Given 2D array
    int salary[5][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9},
                        {10, 11, 12},
                        {13, 14, 15}};
    // Print elements using nested loops
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // print salary located at i,j th location
            printf("Salary[%d][%d]=%d\n", i, j, salary[i][j]);
        }
    }
}