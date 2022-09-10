/*
Imagine you are shopping on Amazon.com for some good weight lifting equipment.
The equipment you want has plates of many different weights that you can combine to lift.

The listing on Amazon gives you an array, plates, that consists of n different weighted plates,
in kilograms. There are no two plates with the same weight. The element plates[i] denotes the
weight of theth plate from the top of the stack. You consider weight lifting equipment to be
good if the plate at the top is the lightest, and the plate at the bottom is the heaviest.

More formally, the equipment with array plates will be called good weight lifting equipment
if it satisfies the following conditions (assuming the index of the array starts from 1):

• plates[1]< plates[i] for all (2≤i≤n)

plates[i]<plates[n] for all (1 ≤i≤n-1)

In one move, you can swap the order of adjacent plates. Find out the
*/

// C++ program to count number of swaps required
// to sort an array when only swapping of adjacent
// elements is allowed.
#include <bits/stdc++.h>

/* This function merges two sorted arrays and returns inversion
count in the arrays.*/
int merge(int arr[], int temp[], int left, int mid, int right)
{
    int inv_count = 0;

    int i = left; /* i is index for left subarray*/
    int j = mid;  /* j is index for right subarray*/
    int k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];

            /* this is tricky -- see above explanation/
            diagram for merge()*/
            inv_count = inv_count + (mid - i);
        }
    }

    /* Copy the remaining elements of left subarray
    (if there are any) to temp*/
    while (i <= mid - 1)
        temp[k++] = arr[i++];

    /* Copy the remaining elements of right subarray
    (if there are any) to temp*/
    while (j <= right)
        temp[k++] = arr[j++];

    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

/* An auxiliary recursive function that sorts the input
array and returns the number of inversions in the
array. */
int _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left)
    {
        /* Divide the array into two parts and call
        _mergeSortAndCountInv() for each of the parts */
        mid = (right + left) / 2;

        /* Inversion count will be sum of inversions in
        left-part, right-part and number of inversions
        in merging */
        inv_count = _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);

        /*Merge the two parts*/
        inv_count += merge(arr, temp, left, mid + 1, right);
    }

    return inv_count;
}

/* This function sorts the input array and returns the
number of inversions in the array */
int countSwaps(int arr[], int n)
{
    int temp[n];
    return _mergeSort(arr, temp, 0, n - 1);
}

/* Driver program to test above functions */
int main(int argv, char **args)
{
    int arr[] = {1, 20, 6, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Number of swaps is %d \n", countSwaps(arr, n));
    return 0;
}
