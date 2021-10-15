/*
Given a string 's'. The task is to find the smallest window length that contains all the characters 
of the given string at least one time.
For eg. A = “aabcbcdbca”, then the result would be 4 as of the smallest window will be “dbca”.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string findSubString(string str)
    {
        // Your code goes here   
        int i=0;
        int startIndex=-1;
        int mx_len=INT_MAX;
        int hash1[256]={0};
        int dict_char=0;
        for(int i=0;i<str.length();i++)
        {
            if(hash1[str[i]]==0)
            {
                hash1[str[i]]++;
                dict_char++;
            }
        }
        int hash2[256]={0};
        int cnt=0;
        for(int j=0;j<str.length();j++)
        {
            hash2[str[j]]++;
            if(hash2[str[j]]==1)  cnt++;
            if(cnt==dict_char)
            {
                while(hash2[str[i]]>hash1[str[i]])
                {
                    hash2[str[i]]--;
                    i++;
                }
                int len=j-i+1;
                if(len<mx_len)
                {
                    startIndex=i;
                    mx_len=len;
                }
            }
        }
        return str.substr(i,mx_len-1);
    }
};

int main()
{
    string str;
    cin>>str;
    Solution obj;
    string ss=obj.findSubString(str);
    cout<<ss<<endl;

    cout<<"Minimum length of distinct characters is: "<<ss.length()<<endl;
    return 0;
}