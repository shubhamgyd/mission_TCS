/*
Given a mapping of digits to letters (as in a phone number), and a digit string, return all 
possible letters the number could represent. You can assume each valid number in the mapping 
is a single digit.

For example if {“2”: [“a”, “b”, “c”], 3: [“d”, “e”, “f”], …} then “23” should return 
[“ad”, “ae”, “af”, “bd”, “be”, “bf”, “cd”, “ce”, “cf"].
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<char,string>mp;
    mp['1']="";
    mp['2']="abc";
    mp['3']="def";
    mp['4']="ghi";
    mp['5']="jkl";
    mp['6']="mno";
    mp['7']="pqrs";
    mp['8']="tuv";
    mp['9']="wxyz";
    mp['0']="";
    string str;
    cin>>str;
    vector<string>ans;
    vector<string>preAns;
    ans.push_back("");
    for(auto ch:str)
    {
        string letters=mp[ch];
        if(letters.length()==0)
        {
            continue;
        }
        else
        {
            for(auto it:ans)
            {
                for(int i=0;i<letters.length();i++)
                {
                    string temp= it;
                    temp.push_back(letters[i]);
                    preAns.push_back(temp);
                }
            }
            ans=preAns;
            preAns=vector<string>();
        }
    }

    for(auto it:ans)
    {
        cout<<it<<endl;
    }
}
// Time Complexity:O(n*n*n)
// Auxilary Space :O(n+n)