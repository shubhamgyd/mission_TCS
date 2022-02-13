#include<bits/stdc++.h>
using namespace std;


void subsetSum(int i,int sum,vector<int>&res,vector<int>&ans)
{
    if(i==res.size())
    {
        ans.push_back(sum);
        return;
    }
    subsetSum(i+1,sum+res[i],res,ans);
    subsetSum(i+1,sum,res,ans);
}
int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(auto &i:res)
    {
        cin>>i;
    }
    vector<int>ans;
    subsetSum(0,0,res,ans);
    sort(ans.begin(),ans.end());
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    return 0;
}