#include <iostream>
using namespace std;

// Utility function which return the index of smallest greater element than v
int solve(int arr[], int i, int j, int v)
{
    // if target is lower than the ith element
    if (v <= arr[i])
    {
        return i;
    }
    //  if target is greater than the last element
    if (v > arr[j])
        return -1;

    // get index of middle element
    int mid = (i + j) / 2;

    // if target is same as the middle element
    if (arr[mid] == v)
    {
        return mid;
    }

    // if target is greater than middle element
    if (arr[mid] < v)
    {
        // either mid+1 will be the greater element
        if (mid + 1 <= j && v <= arr[mid + 1])
        {
            return mid + 1;
        }
        // of else next to mid+1
        else
        {
            return solve(arr, mid + 1, j, v);
        }
    }
    // if target is smaller than the middle element
    else
    {
        // then either mid will be the greater element than target
        if (mid - 1 >= i && v > arr[mid - 1])
        {
            return mid;
        }
        // else lies in between 0 to mid-1
        else
        {
            return solve(arr, i, mid - 1, v);
        }
    }
}

int main()
{
    // size of array
    int n;
    cin >> n;
    int arr[n];
    // input of array
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // target
    int v;
    cin >> v;
    // if target is less than 0th element of is greater than or equal to the last element
    // then no need to search in the array
    // terminate algorithm
    if (v < arr[0] or v >= arr[n - 1])
    {
        return 0;
    }
    // else get the smaller index of element, which is greater than the target
    else
    {
        // here we are searching target+1
        // because we want greater element than target so simple do target +1 and search it
        int index = solve(arr, 0, n - 1, v + 1);
        cout << index << endl;
    }
    return 0;
}