#include <stdio.h>

void main()
{
    // Given array
    int a[3] = {9, 16, 99};
    // Change value at index 1
    a[1] = 20;
    int i = 0;
    // Iterate until i is less than 3
    while (i < 3)
    {
        // change value at index i
        a[i] = a[i] + i;
        // print number
        printf("%d", a[i]);
        // increment index
        i++;
    }
}