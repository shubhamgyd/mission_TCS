/*
This problem was asked by Google.

Given an array of strictly the characters 'R', 'G', and 'B', segregate the values 
of the array so that all the Rs come first, the Gs come second, and the Bs come last. 
You can only swap elements of the array.

Do this in linear time and in-place.

For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'],
 it should become ['R', 'R', 'R', 'G', 'G', 'B', 'B'].
*/

#include<bits/stdc++.h>
using namespace std;

void solve(vector<char>&res)
{
    vector<char>r,g,b;
    for(auto it:res)
    {
        if(it=='R')
        {
            r.push_back(it);
        }
        if(it=='G')
        {
            g.push_back(it);
        }
        if(it=='B')
        {
            b.push_back(it);
        }
    }
    vector<char>ans;
    for(auto it:r)
    {
        ans.push_back(it);
    }
    for(auto it:g)
    {
        ans.push_back(it);
    }
    for(auto it:b)
    {
        ans.push_back(it);
    }
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    return;
}
// Time Complexity:O(n)
// Space Complexity:O(n)

int main()
{
    int n;
    cin>>n;
    vector<char>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    solve(res);
    int i=0;
    int j=n-1;
    int mid=0;
    while(mid<=j)
    {
       if(res[mid]=='R')
       {
           char ch=res[mid];
           res[mid]=res[i];
           res[i]=ch;
           i++;
           mid++;
       }
       else if(res[mid]=='G')
       {
           mid++;
       }
       else if(res[mid]=='B')
       {
           char ch=res[j];
           res[j]=res[mid];
           res[mid]=ch;
           j--;
       }
    }
    cout<<endl;
    for(auto it:res)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}
// In place algo
// Time Complexity:O(n)
// Space Complexity:O(1)