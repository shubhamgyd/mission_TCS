/*
Given an integer array, nums, return the sum of all subarrays within nums that have an odd length.

Ex: Given the following nums…

nums = [1, 2, 3], return 12 ([1], [2], [3], [1, 2, 3] sum to 12).
Ex: Given the following nums…

nums = [3, 1, 5, 2, 4], return 58.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j+=2)
        {
            for(int k=i;k<=j;k++)
            {
                sum+=nums[k];
            }
        }
    }
    cout<<sum<<endl;


//     Consider the subarray that contains A[i],
// we can take 0,1,2..,i elements on the left,
// from A[0] to A[i],
// we have i + 1 choices.

// we can take 0,1,2..,n-1-i elements on the right,
// from A[i] to A[n-1],
// we have n - i choices.

// In total, there are k = (i + 1) * (n - i) subarrays, that contains A[i].
// And there are (k + 1) / 2 subarrays with odd length, that contains A[i].
// And there are k / 2 subarrays with even length, that contains A[i].

// A[i] will be counted ((i + 1) * (n - i) + 1) / 2 times for our question.


// Example of array [1,2,3,4,5]
// 1 2 3 4 5 subarray length 1
// 1 2 X X X subarray length 2
// X 2 3 X X subarray length 2
// X X 3 4 X subarray length 2
// X X X 4 5 subarray length 2
// 1 2 3 X X subarray length 3
// X 2 3 4 X subarray length 3
// X X 3 4 5 subarray length 3
// 1 2 3 4 X subarray length 4
// X 2 3 4 5 subarray length 4
// 1 2 3 4 5 subarray length 5

// 5 8 9 8 5 total times each index was added, k = (i + 1) * (n - i)
// 3 4 5 4 3 total times in odd length array with (k + 1) / 2
// 2 4 4 4 2 total times in even length array with k / 2s

    int res=0;
    for(int i=0;i<n;i++)
    {
        res+=((i+1)*(n-i)+1)/2*(nums[i]);
    }
    cout<<res<<endl;
}