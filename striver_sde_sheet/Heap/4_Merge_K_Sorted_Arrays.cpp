/*
You have been given ‘K’ different arrays/lists, which are sorted individually (in ascending order). You need to merge all the given arrays/list such that the output array/list should be sorted in ascending order.
Input Format :
The first line of input contains an integer T, the number of test cases.

The first line of each test case contains an integer that denotes the value of K.

The next 2*K lines of each test case follow: 
The first line contains an integer ‘N’ denoting the size of the array. 

The second line contains N space-separated integers. 
Output Format :
The first and only line of output contains space-separated elements of the merged and sorted array, as described in the task.
*/

#include<bits/stdc++.h>
using namespace std;


vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    vector<int>res;
    priority_queue<int,vector<int>,greater<int>>pq;
    for(auto it:kArrays)
    {
        for(auto ele:it)
        {
            pq.push(ele);
        }
    }
    while(!pq.empty())
    {
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}
// Time Complexity: O(N Log k)
// Auxiliary Space: O(N)

int main()
{

}