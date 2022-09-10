/*
This problem was asked by PayPal.

Given a string and a number of lines k, print the string in zigzag form. 
In zigzag, characters are printed out diagonally from top left to bottom 
right until reaching the kth line, then back up to top right, and so on.

For example, given the sentence "thisisazigzag" and k = 4, you should print:

t     a     g
 h   s z   a
  i i   i z
   s     g
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int line;
    cin>>line;
    int n=str.length();
    int charsPerLine=(n+1)/line;
    int spacePerLine=n/line;
    int lineNo=1;
    // for char
    for(int i=0;i<n;i++)
    {
        // for space
        
    }
}