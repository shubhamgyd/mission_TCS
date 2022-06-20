/*
Problem Statement: You are given an array of ‘N’ integers. You need to find the 
length of the longest sequence which contains the consecutive elements.
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

    // Brute Force : Sorting
    vector<int>temp=res;
    sort(temp.begin(),temp.end());
    int length=0;
    int i=0;
    while(i<n)
    {
        int j=i+1;
        while(j<n and res[j]==res[i]) j++;
        int ct=1;
        int num=res[i];
        while(j<n and res[j]==num+1)
        {
            num=res[j];
            j++;
            ct++;
        }
        length=max(length,ct);
        i=j;
    }
    cout<<length<<endl;
    // T:O(n+nlogn)
    // S:O(1)

    // Using set
    set<int>st;
    for(auto it:res) st.insert(it);
    int len=0;
    for(auto it:res)
    {
        if(!st.count(it-1))
        {
            int num=it;
            int ct=1;
            while(st.count(num+1))
            {
                num++;
                ct++;
            }
            len=max(len,ct);
        }
    }
    cout<<len<<endl;
    // Time Complexity: The time complexity of the above approach is O(N) because we traverse each consecutive subsequence only once.
    // Space Complexity: The space complexity of the above approach is O(N) because we are maintaining a HashSet.
}