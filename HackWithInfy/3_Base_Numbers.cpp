/*
Altaf has recently learned about number bases and is becoming fascinated.

Altaf learned that for bases greater than ten, new digit symbols need to be introduced, 
and that the convention is to use the first few letters of the English alphabet. 
For example, in base 16, the digits are 0123456789ABCDEF. Altaf thought that this is 
unsustainable; the English alphabet only has 26 letters, so this scheme can only work
 up to base 36. But this is no problem for Altaf, because Altaf is very creative and can 
 just invent new digit symbols when she needs them. (Altaf is very creative.)

Altaf also noticed that in base two, all positive integers start with the digit 1! However, 
this is the only base where this is true. So naturally, Altaf wonders: Given some integer N,
 how many bases b are there such that the base-b representation of N starts with a 1?

 SAMPLE INPUT :

4

6

9

11

24

SAMPLE OUTPUT :

4

7

8

14
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ct=0;
        for(int i=2;i<=n;i++)
        {
            int base=(int)(log(n)/log(i));
            int leadingD=n/(int)(pow(i,base));
            if(leadingD==1)
            {
                ct++;
            }
        }
        cout<<ct<<endl;

    }
}
// Time Complexity:O(n)
// Space Complexity:O(n)