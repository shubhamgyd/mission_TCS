/*
A board of length m and width n is given, we need to break this board into m*n 
squares such that cost of breaking is minimum. cutting cost for each edge will be 
given for the board. In short, we need to choose such a sequence of cutting such that
 cost is minimized. 
 */

#include<bits/stdc++.h>
using namespace std;

int MinCost(int X[],int Y[],int m,int n)
{
    sort(X,X+m,greater<int>());
    sort(Y,Y+n,greater<int>());
    int vert=1;
    int horz=1;
    int cost=0;
    int i=0;
    int j=0;
    while(i<m && j<n)
    {
        if(X[i]>Y[j])
        {
            cost+=X[i]*vert;
            horz++;
            i++;
        }
        else
        {
            cost+=Y[j]*horz;
            vert++;
            j++;
        }
    }

    int total=0;
    while(i<m)
    {
        total+=X[i++];
    }
    cost+=total*vert;

    total=0;
    while(j<n)
    {
        total+=Y[j++];
    }
    cost+=total*horz;

    return cost;
}

int main()
{
    int m=6;
    int n=4;
    int X[m-1]={1,2,3,4,5};
    int Y[n-1]={1,2,3};
    // int m = 6, n = 4;
    // int X[m-1] = {2, 1, 3, 1, 4};
    // int Y[n-1] = {4, 1, 2};
    cout<<MinCost(X,Y,m-1,n-1);
    return 0;
}