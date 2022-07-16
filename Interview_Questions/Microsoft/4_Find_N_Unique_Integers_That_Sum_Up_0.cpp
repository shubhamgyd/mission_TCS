/*
Given an integer n, return any array containing n unique integers such that they add up to 0.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>res;
    int start=n/2;
    start*=-1;
    for(int i=0;i<n;i++)
    {
        if(start==0 and n%2==0){
            start++;
        } 
        else {
            res.push_back(start);
            start++;
        }
    }
    if(n%2==0){
        res.push_back(start);
    }
    for(auto it:res)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}