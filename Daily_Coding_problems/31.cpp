/*
This question is asked by Amazon. Given two strings representing sentences, 
return the words that are not common to both strings (i.e. the words that only 
appear in one of the sentences). You may assume that each sentence is a sequence 
of words (without punctuation) correctly separated using space characters.

Ex: given the following strings...

sentence1 = "the quick", sentence2 = "brown fox", return ["the", "quick", "brown", "fox"]
sentence1 = "the tortoise beat the haire", sentence2 = "the tortoise lost to the haire", return ["beat", "to", "lost"]
sentence1 = "copper coffee pot", sentence2 = "hot coffee pot", return ["copper", "hot"]
*/

#include<bits/stdc++.h>
using namespace std;

vector<string> solve(string s1,string s2)
{
    map<string,int>mp;
    stringstream ss(s1);
    string word;
    while(ss>>word)
    {
        mp[word]++;
    }
    vector<string>res;
    stringstream str(s2);
    string S;
    while(str>>S)
    {
        if(mp.find(S)!=mp.end())
        {
            mp[S]--;
            if(mp[S]==0)
            {
                mp.erase(S);
            }
        }
        else
        {
            mp[S]++;
        }
    }
    for(auto it:mp)
    {
        res.push_back(it.first);
    }
    return res;

}



int main()
{

}