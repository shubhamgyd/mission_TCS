/*
Problem Statement: 
You are given an array of prices where prices[i] is the price of a given stock on an ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a 
different day in the future to sell that stock. Return the maximum profit 
you can achieve from this transaction. If you cannot achieve any profit, return 0.
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
    // Approach 1: Brute Force
    // Take single day and iterate over the array and find the profit corresponding
    // on that day and so on

    int mx=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(res[j]>res[i])
            {
                mx=max(mx,res[j]-res[i]);
            }
        }
    }
    cout<<mx<<endl;
    // Time Complexity:O(n*n)
    // Space Complexity:O(1)



    // Approach 2: Optimal Solution
    // ntuition: We will linearly travel the array. We can maintain a minimum from the 
    // starting of the array and compare it with every element of the array, if it is
    // greater than the minimum then take the difference and maintain it in max, otherwise 
    // update the minimum.

    // Approach:

    // Create a variable maxPro and mark it as 0.
    // Create a variable minPrice and mark it as max_value.
    // Run a for loop from 0 to n.
    // Update the minPrice at if it greater than current element of the array
    // Take the difference of the minPrice with the current element of the array and compare and maintain it in maxPro.
    // Return the maxPro.

    int num=res[0];
    int profit=0;
    for(int i=1;i<n;i++)
    {
        if(res[i]>num)
        {
            profit=max(profit,res[i]-num);
        }
        else
        {
            num=res[i];
        }
    }
    cout<<profit<<endl;

    // Time Complexity:O(n)
    // Space Complexity: O(1)
}