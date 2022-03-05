/*
You are transporting bricks on a construction site and want to work as efficiently as possible. 
The weight of each brick is given by bricks[i]. Given a wheelbarrow that can carry up to 
(not including) 5000 pounds, return then maximum number of bricks you can place in your 
wheelbarrow to transport.

Ex: Given the following bricks…

bricks = [1000, 1000, 1000, 2000], return 3.

Ex: Given the following bricks…

bricks = [1000, 200, 150, 200], return 4.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(auto &it:res)
    {
        cin>>it;
    }
    sort(res.begin(),res.end());
    int sum=0;
    int ct=0;
    for(auto it:res)
    {
        sum+=it;
        if(sum<5000)
        {
            ct++;
        }
        else
        {
            break;
        }
    }
    cout<<ct<<endl;
    return 0;
}