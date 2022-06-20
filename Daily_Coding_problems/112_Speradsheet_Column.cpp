/*
Given a positive integer n, return its corresponding column title in an excel spreadsheet.

Ex: Given the following values for n...

n = 1, return “A”.
n = 2, return “B”.
n = 3, return “C”.
n = 26, return “Z”. 
n = 27, return “AA”. 
n = 28, return “AB”. 
*/

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    char ch[101];
    string str="";
    int i=0;
    while(n>0)
    {
        int rem=n%26;
        if(rem==0)
        {
            ch[i++]='Z';
            str.push_back('Z');
            n=(n/26)-1;
        }
        else
        {
            ch[i++]=(rem-1)+'A';
            str.push_back((rem-1)+'A');
            n/=26;
        }
    }
    
    reverse(str.begin(),str.end());
    cout<<str<<endl;
    return 0;
}
// Time Complexity:O(n/26)
// Space Complexity:O(n/26)