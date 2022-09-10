/*
Given an integer array, nums, return the total number of integers within nums that have an even number of digits.

Ex: Given the following nums…

nums = [1, 12, 123], return 1 (12 is the only integer with an even number of digits).
Ex: Given the following nums…

nums = [1, 32, 3492, 23], return 3.
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
    int cnt=0;
    for(auto it:nums)
    {
        int num=it;
        int digits=0;
        while(num)
        {
            digits++;
            num/=10;
        }
        if(digits%2==0) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}