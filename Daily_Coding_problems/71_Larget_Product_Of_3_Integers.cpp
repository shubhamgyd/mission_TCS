/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Facebook.

Given a list of integers, return the largest product that can be made by
 multiplying any three integers.

For example, if the list is [-10, -10, 5, 2], we should return 500, 
since that's -10 * -10 * 5.

You can assume the list has at least three integers.
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
    sort(res.begin(),res.end());
    int first=res[0]*res[1]*res[n-1];
    int last=res[n-1]*res[n-2]*res[n-3];
    cout<<max(first,last)<<endl;
    return 0;
}
// Time Complexity:O(nlogn)
// Space Complexity:O(1)