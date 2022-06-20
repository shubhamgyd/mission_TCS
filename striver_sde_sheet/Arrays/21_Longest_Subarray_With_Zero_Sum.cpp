/*
Problem Statement: Given an array containing both positive and negative integers,
we have to find the length of the longest subarray with the sum of all elements equal to zero.

Example 1:

Input Format: N = 6, array[] = {9, -3, 3, -1, 6, -5}

Result: 5

Explanation: The following subarrays sum to zero:
{-3, 3} , {-1, 6, -5}, {-3, 3, -1, 6, -5}
Since we require the length of the longest subarray, our answer is 5!

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        cin >> res[i];
    }

    // Solution 1: Brute Force

    //    Approach :

    //     Initialise a variable max = 0, which stores length of longest subarray with sum 0.
    //     Traverse the array from start and initialise a variable sum = 0 which stores sum of subarray starting with current index
    //     Traverse from next element of current_index up to end of the array, each time add the element to sum and check if it is equal to 0.
    //     If sum = 0, check if length of subarray so far is > max and if yes update max
    //     Now keep adding elements and repeat step 3 a.
    //     After the outer loop traverses all elements return max

    int mx=0;
    for(int i=0;i<n;i++)
    {
        int sum=res[i];
        for(int j=i+1;j<n;j++)
        {
            sum+=res[j];
            if(sum==0)
            {
                int range=j-i+1;
                mx=max(mx,range);
            }
        }
    }
    cout<<"Length: "<<mx<<endl;
    // T:O(n*n)
    // S:O(1)



    // Using Hashmap
    // Intuition:  Now let’s say we know that the sum of subarray(i, j) = S, and we also know 
    // that sum of subarray(i, x) = S where i < x < j. We can conclude that the sum of 
    // subarray(x+1, j) = 0.

    // Let us understand the above statement clearly


    // So in this problem, we’ll store the prefix sum of every element, 
    // and if we observe that 2 elements have same prefix sum, we can conclude that the 
    // 2nd part of this subarray sums to zero
    unordered_map<int,int>mp;
    mp[0]=-1;
    int sum=0;
    int longSubarrayLength=0;
    for(int i=0;i<n;i++)
    {
        sum+=res[i];
        // New sum-> push into hashmap
        if(mp.find(sum)==mp.end())
        {
            mp[sum]=i;
        }
        // if sum if already present in the hashmap
        // then find the range from current index to the index where current sum present
        // may or may not be both index same
        int range=i-mp[sum];
        longSubarrayLength=max(longSubarrayLength,range);
    }
    cout<<"Length: "<<longSubarrayLength<<endl;
    // T:O(n)
    // S :O(n)
}