/*
Given a positive integer, num, return whether or not it forms a palindrome.
Note: You may not transform the number into a string.

Ex: Given the following num…

num = 12321, return true.
Ex: Given the following num…

num = 5393, return false.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string str=to_string(n);
    int len=str.length();
    int i=0;
    int j=len-1;
    bool isPal=true;
    while(i<j)
    {
        if(str[i]!=str[j])
        {
            isPal=false;
            break;
        }
        i++;
        j--;
    }
    if(isPal)
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
}