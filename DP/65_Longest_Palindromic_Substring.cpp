#include<bits/stdc++.h>
using namespace std;

class Solution {
    string expand(string str,int low,int high)
    {
    int len=str.length();
    while(low>=0 && high<len && (str[low]==str[high]))
    {
        low--;
        high++;
    }
    return str.substr(low+1,high-low-1);
    }
public:
    string longestPalindrome(string s) {
        if(s.length()==1)
            return s;
        string max_str="",curr_str;
        int max_len=0,curr_len;
        for(int i=0;i<s.length()-1;i++)
        {
            curr_str=expand(s,i,i);          // Expanding length by even position number 
            curr_len=curr_str.length();
            if(curr_len>max_len)
            {
                max_len=curr_len;
                max_str=curr_str;
            }
            curr_str=expand(s,i,i+1);        // Expanding length by odd position number 
            curr_len=curr_str.length();
            if(curr_len>max_len)
            {
                max_len=curr_len;
                max_str=curr_str;
            }
        }
        return max_str;
    }
};

int main()
{
    Solution obj;
    string str="nitin";
    cout<<"Longest Palindromic Substring is: "<<obj.longestPalindrome(str)<<endl;
    return 0;
}