#include<bits/stdc++.h>
using namespace std;


vector<int> NGE(vector<int>&arr, int n)
{
    stack<pair<int,int>> s;
    vector<int>res(n);
    s.push({arr[0],0});
    for (int i = 1; i < n; i++) {
 
        if (s.empty()) {
            s.push({arr[i],i});
            continue;
        }
        while (s.empty() == false && s.top().first <arr[i]) {
            res[s.top().second]=i;
            s.pop();
        }
        s.push({arr[i],i});
    }
    while (s.empty() == false) {
        res[s.top().second]=-1;
        s.pop();
    }
    return res;
}

vector<int> PGE(vector<int>&arr, int n)
{

    stack<pair<int,int>> s;
    s.push({arr[0],0});
    vector<int>res;
    res.push_back(-1);
    for (int i = 1; i < n; i++) {
        while (s.empty() == false && s.top().first <=arr[i]) s.pop();
        if(s.empty())
        {
            res.push_back(-1);
        }
        else
        {
            res.push_back(s.top().second);
        }
        s.push({arr[i],i});
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    vector<int>ans=NGE(nums,n);
    vector<int>ans1=PGE(nums,n);
    // for(auto it:ans)
    // {
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    // for(auto it:ans1)
    // {
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        int left=ans[i];
        int right=ans1[i];
        if(left==-1 and right==-1)
        {
            res[i]=0;
        }
        else if(left!=-1 and right==-1)
        {
            int range=abs(i-left);
            range*=2;
            res[i]=range;
        }
        else if(left==-1 and right!=-1)
        {
            int range=abs(i-right);
            range*=2;
            res[i]=range;
        }
        else
        {
            int dis1=abs(i-left);
            dis1*=2;
            int dis2=abs(i-right);
            dis2*=2;
            res[i]=min(dis1,dis2);
        }
    }
    for(auto it:res)
    {
        cout<<it<<" ";
    }
    return 0;
}