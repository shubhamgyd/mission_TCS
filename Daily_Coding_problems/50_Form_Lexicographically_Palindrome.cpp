/*
This problem was asked by Quora.

Given a string, find the palindrome that can be made by 
inserting the fewest number of characters as possible anywhere 
in the word. If there is more than one palindrome of minimum length
 that can be made, return the lexicographically earliest one (the first one alphabetically).

For example, given the string "race", you should return "ecarace", 
since we can add three letters to it (which is the smallest amount to make a palindrome). There are seven other palindromes that can be made from "race" by adding three letters, but "ecarace" comes first alphabetically.

As another example, given the string "google", you should return "elgoogle".
*/

#include<bits/stdc++.h>
using namespace std;

bool isPalindrom(string str)
{
    int i=0;
    int j=str.length()-1;
    while(i<j)
    {
        if(str[i]!=str[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int main()
{
    string str;
    cin>>str;
    if(isPalindrom(str))
    {
        cout<<str<<endl;
        return 0;
    }
    int i=0;
    int j=str.length()-1;
    int n=str.length();
    int flag=0;
    string tm1="";
    string tm2="";
    while(i<n && j>=0)
    {
        tm1.push_back(str[j--]);
        tm2.push_back(str[i++]);
        string res1=tm1+str;
        string res2=str+tm2;
        bool ok1=isPalindrom(res1);
        bool ok2=isPalindrom(res2);
        if(ok1 && ok2)
        {
            if(res1<res2)
            {
                cout<<res1<<endl;
                return 0;
            }
            else
            {
                cout<<res2<<endl;
                return 0;
            }
        }
        if(ok1 && !ok2)
        {
            cout<<res1<<endl;
            return 0;
        }
        if(!ok1 && ok2)
        {
            cout<<res2<<endl;
            return 0;
        }
    }
    return 0;
}
// Time Complexity:O(n*n)
// Space Complexity:O(n)
