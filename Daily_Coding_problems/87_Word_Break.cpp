/*
This question is asked by Amazon. Given a string s and a list of words representing a
dictionary, return whether or not the entirety of s can be segmented into dictionary words.
Note: You may assume all characters in s and the dictionary are lowercase.
*/

#include<bits/stdc++.h>
using namespace std;

bool isPrefix(string str,vector<string>&res)
{
    if(find(res.begin(),res.end(),str)!=res.end())
    {
        return true;
    }
    return false;
}

bool solve(string str,vector<string>&dict)
{
    int size=str.length();
    // base case
    if(size==0)
    {
        return true;
    }
    // try all prefixes of string
    for(int i=1;i<=size;i++)
    {
        // The parameter for dictionaryContains is
        // str.substr(0, i) which is prefix (of input
        // string) of length 'i'. We first check whether
        // current prefix is in  dictionary. Then we
        // recursively check for remaining string
        // str.substr(i, size-i) which is suffix of 
        // length size-i
        if(solve(str.substr(i,size-i),dict) || isPrefix(str.substr(0,i),dict))
        {
            return true;
        }
    }

    // if we not found any of the prefix into the the dictionary,
    // then return false
    return false;
}
// Time Complexity:O(n^2*k*l+N^3)
// this is very high complexity n^2kl+n^3. where l is maximum length of word in dict and k 
// is max number of words as n^2 times stringing done so n^3 and n^time dict search done 
// so n*kl




// Optimize_DP
bool isFound(string str,vector<string>&res)
{
    unordered_set<string>uset;
    for(auto it:res)
    {
        uset.insert(it);
    }

    // base case
    if(str.length()==0) return false;

    // dp array to keep track on every index wher we found the prefix of string in set;
    int size=str.length();
    vector<bool>dp(size+1,false);
    dp[0]=true;
    for(int i=1;i<=size;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(dp[j] && uset.find(str.substr(j,i-j))!=uset.end())
            {
                dp[i]=true;
                break;
            }
        }
    }
    return dp.back();
}
// Time Complexity:O(n^3)
// N^2 is for 2 for loops and n is for for making substring
// Auxiliary Space :O(|l|) , l is the length of the dictionary
// unordered_set will check given substring is present or not in O(1) time

int main()
{
    string str="thedailybyte";
    vector<string> dictionary={"the", "daily", "byte"};
    bool isMade=solve(str,dictionary);
    if(isMade)
    {
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }
    cout<<isFound(str,dictionary)<<endl;
    return 0;
}