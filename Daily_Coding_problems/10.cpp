/*
This question is asked by Facebook. Given a string, return whether or not it forms a palindrome 
ignoring case and non-alphabetical characters.
Note: a palindrome is a sequence of characters that reads the same forwards and backwards.

Ex: Given the following strings...

"level", return true
"algorithm", return false
"A man, a plan, a canal: Panama.", return true

*/


#include<bits/stdc++.h>
using namespace std;


int main()
{
    string str;
    cin>>str;
    string ans="";
    for(auto it:str)
    {
        if(isalpha(it))
        {
            ans.push_back(it);
        }
    }
    int i=0,j=ans.length()-1;
    while(i<=j)
    {
        if(ans[i]!=ans[j])
        {
            cout<<"No"<<endl;
            return 0;
        }
        i++;
        j--;
    }
    cout<<"Yes"<<endl;
    return 0;
}
// Time complexity:O(n)
// Space complexity :O(n)