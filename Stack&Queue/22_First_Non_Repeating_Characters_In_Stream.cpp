#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
		string FirstNonRepeating(string A){
		    // Code here
		    string res="";
		    queue<char>q;
		    int hash[26]={0};
		    for(int i=0;i<A.length();i++)
		    {
		        q.push(A[i]);
		        hash[A[i]-'a']++;
		        while(!q.empty())
		        {
		            if(hash[q.front()-'a']>1)
		            {
		                q.pop();
		            }
		            else
		            {
		                res+=q.front();
		                break;
		            }
		        }
		        if(q.empty())
		        {
		            res+='#';
		        }
		    }
		    return res;
		}

};