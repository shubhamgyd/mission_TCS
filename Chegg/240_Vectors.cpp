#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Read size of vector
    int n;
    cin >> n;
    vector<int> nums(n);
    // Read n elements of the vector
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    // get maximum number
    int maxNum = 0;
    // get index of first maximum number
    int ind = 0;
    // Iterate vector and get maximum number
    for (int i = 0; i < n; i++)
    {
        // if ith number is greater than the maxNum
        // then update the maxNum
        if (nums[i] > maxNum)
        {
            maxNum = nums[i];
            ind = i;
            break;
        }
    }
    // the number of steps required to bring the maxNum element at 1st position is it's index number
    int steps = ind;
    // Now swap all the elements from 0 to ind
    while (ind > 0)
    {
        swap(nums[ind], nums[ind - 1]);
        ind--;
    }
    // get minimum Number
    int minNum = INT_MAX;
    ind = 0;
    // Get minimum number and it's index
    for (int i = 0; i < n; i++)
    {
        if (nums[i] < minNum)
        {
            minNum = nums[i];
            ind = i;
        }
    }
    // if minimum number is not found at last index
    // then number of steps required is equal to the n - index number
    if (ind != n - 1)
    {
        steps += ((n - 1) - ind);
    }
    // Display total steps reuired to brine max num at starting and min num at the ending
    cout << steps << endl;
    return 0;
}