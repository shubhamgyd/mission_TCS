/*
This problem was asked by Facebook.

Given three 32-bit integers x, y, and b, return x if b is 1 and y if b is 0, 
using only mathematical or bit operations. You can assume b can only be 1 or 0.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x,y,b;
    cin>>x>>y>>b;
    if(b&1)
    {
        cout<<x<<endl;
    }
    else{
        cout<<y<<endl;
    }
    return 0;
}
// Time Complexity:O(1)
// Auxiliary Complexity:(1)