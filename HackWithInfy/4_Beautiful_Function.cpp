/*
Problem Statement: Let’s define a Beautiful Function F(x) in such a way: Add 1 to the value of x, if the result of addition contains any trailing zeros then remove them all.

Example:
F(11) = 12
F(19) = 2 (20 –> 2)
F(99) = 1(100 –> 10 –> 1)

Let’s define a number to be reachable from x , if we can apply Beautiful Function some number of times (possibly zero) to x and get that number as result
Ex. 102 can be reachable from 1099 as F(F(1099)) = F(101) = 102
You are given a number N . Calculate how many numbers are reachable from N.
Input Format:
The first line contains an integer N. denoting the given number.

Constrains: 1 <= N <= 10^9
Sample Input	Sample output	Explanation
1	9	1,2,3,4,5,6,7,8,9 are reachable from 1.
Let’s Understand the problem first: In this problem you will be given a number you have to find how many numbers can be reachable from the given no using the Beautiful function.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    map<int,int>mp;
    int ct=0;
    while(!mp[n])
    {
        mp[n]++;
        n+=1;
        string str=to_string(n);
        while(str.back()=='0')
        {
            str.pop_back();
        }
        n=stoi(str);
        ct++;
        cout<<n<<" ";
    }
    cout<<endl;
    cout<<ct<<endl;
}