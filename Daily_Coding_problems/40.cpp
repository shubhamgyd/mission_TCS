/*
This problem was asked by Palantir.

Write an algorithm to justify text. Given a sequence of words and an integer line 
length k, return a list of strings which represents each line, fully justified.

More specifically, you should have as many words as possible in each line. There 
should be at least one space between each word. Pad extra spaces when necessary 
so that each line has exactly length k. Spaces should be distributed as equally 
as possible, with the extra spaces, if any, distributed starting from the left.

If you can only fit one word on a line, then you should pad the right-hand side 
with spaces.

Each word is guaranteed not to be longer than k.

For example, given the list of words ["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"] and k = 16, you should return the following:

["the  quick brown", # 1 extra space on the left
"fox  jumps  over", # 2 extra spaces distributed evenly
"the   lazy   dog"] # 4 extra spaces distributed evenly
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<string>res;
    for(int i=0;i<n;i++)
    {
        string str;
        getline(cin,str);
        res.push_back(str);
    }
    int k;
    cin>>k;
    vector<string>ans;
    for(int i=0;i<n;i++)
    {
        ans.push_back(res[i]);
        stringstream ss(res[i]);
        string word;
        int ct=0;
        while(ss>>word)
        {
            ct+=word.length();
            ct+=1;
        }
        ct--;
        int rem=k-ct;
        string put="# "+to_string(rem)+"extra space on the left";
        string put1="# "+to_string(rem)+"extra space on the right";
        string put2="# "+to_string(rem)+"extra spaces distrubuted evenly";
        if(i==0)
        {
            
            ans.push_back(put);
        }
        else if(i==n-1)
        {
            ans.push_back(put1);
        }
        else
        {
            ans.push_back(put2);
        }
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}