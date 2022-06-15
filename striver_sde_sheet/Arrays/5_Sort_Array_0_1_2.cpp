/*
Problem Statement: Given an array consisting of only 0s, 1s and 2s. 
Write a program to in-place sort the array without using inbuilt sort functions. 
( Expected: Single pass-O(N) and constant space)
*/


#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }

    /*
    Solution 1: Sorting ( even if it is not the expected solution here but it can be considered as one of the approach ). Since the array contains only 3 integers, 0, 1, and 2. 
    Simply sorting the array would arrange the elements in increasing order.
    Time Complexity: O(N*logN)
    Space Complexity: O(1)

    Solution 2: Keeping count of values
    Intuition: Since in this case there are only 3 distinct values in the array so it’s easy 
    to maintain the count of all, Like the count of 0, 1, and 2. 
    This can be followed by overwriting the array based on the frequency(count) of the values.

    Approach: 
    Take 3 variables to maintain the count of 0, 1 and 2.
    Travel the array once and increment the corresponding counting variables
    ( let’s consider count_0 = a, count_1 = b, count_2 = c )
    In 2nd traversal of array, we will now over write the first ‘a’ indices / positions in array with ’0’, the next ‘b’ with ‘1’ and the remaining ‘c’ with ‘2’.
    Time Complexity: O(N) + O(N)
    Space Complexity: O(1)
    */

    // Approach 3: Brute force
    // 1st Pass: Push all zeros into array
    // 2nd Pass: Push all ones into array
    // 3rd Pass: Push all twos into array
    vector<int>ans;
    
    // 1st pass
    for(auto it:res)
    {
        if(it==0) ans.push_back(it);
    }
    
    // 2nd pass
    for(auto it:res)
    {
        if(it==1) ans.push_back(it);
    }

    // 3rd pass
    for(auto it:res)
    {
        if(it==2) ans.push_back(it);
    }

    // final ans
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    // Time Complexity:O(n)
    // Space Complexity:O(n)


    // Appraoch 4: 3-pointer
    int start=0;
    int mid=0;
    int last=n-1;
    while(mid<=last)
    {
        if(res[mid]==0)
        {
            swap(res[mid],res[start]);
            start++;
            mid++;
        }
        else if(res[mid]==1)
        {
            mid++;
        }
        else if(res[mid]==2)
        {
            swap(res[mid],res[last]);
            mid++;
            last--;
        }
    }
    cout<<endl;
    for(auto it:res)
    {
        cout<<it<<" ";
    }
    // Time Complexity:O(n)
    // Space Complexity:O(1)
    return 0;

}