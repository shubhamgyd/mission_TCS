#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>&res,vector<int>ans)
{
    if(res.size()==0)
    {
        for(auto it:ans)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }
    vector<int>v1=ans;
    vector<int>v2=ans;
    v1.push_back(res[0]);
    res.erase(res.begin()+0);
    solve(res,v1);
    solve(res,v2);
    return;
}

int main()
{
    vector<int>res={3,1,2,4};
    int n=res.size();
    vector<int>ans;
    solve(res,ans);
    return 0;
}