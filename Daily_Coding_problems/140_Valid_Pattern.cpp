/*
This problem was asked by Uber.

One way to unlock an Android phone is through a pattern of swipes across a 1-9 keypad.

For a pattern to be valid, it must satisfy the following:

All of its keys must be distinct.
It must not connect two keys by jumping over a third key, unless that key has already been used.
For example, 4 - 2 - 1 - 7 is a valid pattern, whereas 2 - 1 - 7 is not.
Find the total number of valid unlock patterns of length N, where 1 <= N <= 9.
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
    set<int>st,st1,st3;
    for(int i=1;i<n;i++)
    {
        st.insert(nums[i]-nums[i-1]);
        st1.insert(nums[i]/nums[i-1]);
    }
    if(st.size()==1)
    {
        int diff=nums[n-1]-nums[n-2];
        cout<<nums[n-1]+diff<<endl;
        return 0;
    }
    if(st1.size()==1)
    {
        int commonRatio=nums[n-1]/nums[n-2];
        int nth=n+1;
        int a=nums[0];
        int res=pow(commonRatio,nth-1);
        int num=a*res;
        cout<<num<<endl;
        return 0;
    }
    else
    {
        bool isFibbo=true;
        for(int i=2;i<n;i++)
        {
            if(nums[i-2]+nums[i-1]!=nums[i])
            {
                isFibbo=false;
                break;
            }
        }
        if(isFibbo)
        {
            int num=nums[n-2]+nums[n-1];
            cout<<num<<endl;
            return 0;
        }
        else
        {
            cout<<-999<<endl;
            return 0;
        }
    }
}