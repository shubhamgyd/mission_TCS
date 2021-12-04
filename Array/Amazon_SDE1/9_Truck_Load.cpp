#include<bits/stdc++.h>
using namespace std;

pair<int,int>  selectPackage(int truckSpace ,int numPackage,vector<int>packageSpace)
{
    map<int,int>mp;
    int mx=INT_MIN;
    truckSpace-=30;
    vector<int>res;
    for(int i=0;i<numPackage;i++)
    {
        int v=packageSpace[i];
        int f=truckSpace-v;
        auto it=mp.find(f);
        if(it!=mp.end())
        {
            int cmx=v>truckSpace-v?v:truckSpace-v;
            if(cmx>mx)
            {
                mx=cmx;
                res.push_back(mp[truckSpace-v]);
                res.push_back(i);
            }
        }
        mp[v]=i;
    }
    if(res.size()==0)
    {
        return {-1,-1};
    }
    return {res[0],res[1]};
}

int main()
{
    int truckspace;
    cin>>truckspace;
    int n;
    cin>>n;
    vector<int>res;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        res.push_back(a);
    }
    pair<int,int>p=selectPackage(truckspace,n,res);
    cout<<p.first<<" "<<p.second<<endl;
    return 0;
}