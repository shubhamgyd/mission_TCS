/*
The distance between 2 binary strings is the sum of their lengths after removing the 
common prefix. For example: the common prefix of 1011000 and 1011110 is 1011 so the 
distance is len("000") + len("110") = 3 + 3 = 6.

Given a list of binary strings, pick a pair that gives you maximum distance among all
 possible pair and return that distance.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<string>list(n);
    for(int i=0;i<n;i++)
    {
        cin>>list[i];
    }

    // Brute Force
    // Just compare each string with every other
    // remove the prfix and and count max distance of each pair
    // t:O(n^2)
    // s:O(1)


    // Optimal Solution
    
}