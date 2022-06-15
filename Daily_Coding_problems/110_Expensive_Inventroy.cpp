/*
You are given a list of values and a list of labels. The ith element in labels represents the label of the ith element. Similarly, the ith element in values represents the value associated with the ith element (i.e. together, an “item” could be thought of as a label and a price). Given a list of values, a list of labels, a limit, and wanted, return the sum of the most expensive items you can group such that the total number of items used is less than wanted and the number of any given label that is used is less than limit.

Ex: Given the following variables...

values = [5,4,3,2,1]
label = [1,1,2,2,3]
wanted = 3
limit = 1
return 9 (the sum of the values associated with the first, third, and fifth items).
*/


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int value[n];
    int labels[n];
    for(int i=0;i<n;i++)
    {
        cin>>value[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>labels[i];
    }
    int wanted,limit;
    cin>>wanted>>limit;
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[labels[i]]=max(mp[labels[i]],value[i]);
    }
    int sum=0;
    for(auto it:mp)
    {
        sum+=it.second;
    }
    sum*=limit;
    cout<<sum<<endl;
}
// Time Complexity:O(nlogn)
// Space Complexity:O(n)