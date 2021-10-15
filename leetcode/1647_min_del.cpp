#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        array<int,26>freq{};
        for(char c:s)
        {
            ++freq[c-'a'];
        }
        sort(freq.begin(),freq.end(),greater<int>());
        int take=0;
        int prev=INT_MAX;
        for(int f:freq)
        {
            if(!f || !prev)
            {
                break;
            }
            prev=min(f,prev-1);
            take+=prev;
        }
        return s.length()-take;
    }
};








// My own method

class Solution {
public:
    int minDeletions(string str) {
        map<char,int>mp;
		for(int i=0;i<str.length();i++)
		{
			mp[str[i]]++;
		}
		vector<int>v;
		for(auto it:mp)
		{
			v.push_back(it.second);
		}
		sort(v.rbegin(),v.rend());
		int ct=0;
		set<int>st;
		for(int i=0;i<v.size();i++)
		{
			if(st.find(v[i])!=st.end())
			{
				int num=v[i];
				while(st.find(num)!=st.end())
				{
					num-=1;
					ct++;
				}
                if(num!=0)
				    st.insert(num);
			}
			else
			{
				st.insert(v[i]);
			}
		}
		//cout<<"Total deletion: "<<ct<<endl;
		return ct;
    }
};