#include<bits/stdc++.h>
using namespace std;


vector<int> funcDistance(vector<int>inputDist,int start,int end)
{
    int n=inputDist.size();
    vector<int>temp;
    for(int i=0;i<n;i++)
    {
        temp.push_back(abs(inputDist[i]));
    }
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        if(temp[i]>=start && temp[i]<=end)
        {
            ans.push_back(temp[i]);
        }
    }
    if(ans.size()==0)
    {
        ans.push_back(-1);
    }
    return ans;
}

vector<int> solve(vector<int>res)
{
    vector<int>ans;
    map<int,int>mp;
    int n=res.size();
    for(int i=0;i<n;i++)
    {
        mp[res[i]]=i;
    }
    for(int i=0;i<n;i++)
    {
        ans.push_back(mp[i]);
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    solve(res);
}