/*
Given a list of nums and a target, return all the unique combinations of nums that sum to target.

Ex: Given the following nums and target...

nums = [8, 2, 2, 4, 5, 6, 3]
target = 9
return [[2,2,5],[2,3,4],[3,6],[4,5]].
*/

#include<bits/stdc++.h>
using namespace std;

void combinationsWays(int i,int n,int target,vector<int>&res, vector<vector<int>>&combinations,vector<int>&ways,set<vector<int>>&st)
{
    if(!target)
    {
        // sort(ways.begin(),ways.end());
        st.insert(ways);
        combinations.push_back(ways);
        return;
    }

    for(int j=i;j<n and target>=res[j];j++)
    {
        ways.push_back(res[j]);
        combinationsWays(i+1,n,target-res[j],res,combinations,ways,st);
        ways.pop_back();
    }
    // return;
}

vector<vector<int>> solve(vector<int>&res,int n,int target)
{
    vector<vector<int>>combinations;
    vector<int>ways;
    set<vector<int>>st;
    combinationsWays(0,n,target,res,combinations,ways,st);
    set<vector<int>>ans;
    for(auto it:combinations)
    {
        sort(it.begin(),it.end());
        ans.insert(it);
    }
    cout<<endl;
    for(auto it:ans)
    {
        cout<<"[";
        for(auto ele:it)
        {
            cout<<ele<<",";
        }
        cout<<"]";
    }
    cout<<endl;
    sort(combinations.begin(),combinations.end());
    combinations.erase(unique(combinations.begin(),combinations.end()),combinations.end());
    return combinations;
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
    int target;
    cin>>target;
    vector<vector<int>>ans=solve(res,n,target);
    for(auto it:ans)
    {
        cout<<"[";
        for(auto ele:it)
        {
            cout<<ele<<",";
        }
        cout<<"]";
    }
    return 0;
}