#include <stdio.h>
#include <limits.h>
// Prototype for swapping two numbers
void swap(int *, int *);

// Utility function which return the minimum number
int min(int a, int b)
{
    return (a > b) ? b : a;
}

// Call by reference function which swap two numbers
void swap(int *a, int *b)
{
    int value = *a;
    *a = *b;
    *b = value;
}

int main()
{
    // Array 1
    int array1[4] = {2, 1, 3, 4};

    // Array 2
    int array2[4] = {7, 6, 5, 8};
    
    // Keep track on min1 from array1
    int mn1 = INT_MAX;

    // Keep track on min2 from array2
    int mn2 = INT_MAX;

    // Keep track on min1 index from array1
    int ind1=0;


    // Keep track on min2 index from array2
    int ind2=0;

    // Finding minimum element from array1
    for (int i = 0; i < 4; i++)
    {
        // Updating minimum element and min index
        if(array1[i]<mn1)
        {
            mn1=array1[i];
            ind1=i;
        }
    }

    // Finding minimum element from array2
    for (int i = 0; i < 4; i++)
    {
        // Updating minimum element and min index
        if(array2[i]<mn2)
        {
            mn2=array2[i];
            ind2=i;
        }
    }
    // Swapping min1 and min2
    swap(&mn1,&mn2);

    // updating element in original array's
    array1[ind1]=mn1;
    array2[ind2]=mn2;

    printf("Output:\n");
    // Printing both array
    printf("Array1 :");
    for(int i=0;i<4;i++)
    {
        printf("%d ",array1[i]);
    }
    printf("\n");
    printf("Array2 :");
    for(int i=0;i<4;i++)
    {
        printf("%d ",array2[i]);
    }
}