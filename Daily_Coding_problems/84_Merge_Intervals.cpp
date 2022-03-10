/*
This problem was asked by Snapchat.

Given a list of possibly overlapping intervals, return a new list of intervals where all 
overlapping intervals have been merged.

The input list is not necessarily ordered in any way.

For example, given [(1, 3), (5, 8), (4, 10), (20, 25)], you should return 
[(1, 3), (4, 10), (20, 25)].

*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>res;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        res.push_back({a,b});
    }
    vector<vector<int>>ans;
    sort(res.begin(),res.end(),[](vector<int>a,vector<int>b){return a[0]<b[0];});

    ans.push_back(res[0]);
    for(int i=1;i<n;i++)
    {
        vector<int>vBack=ans.back();
        if(res[i][0]>vBack[1])
        {
            ans.push_back(res[i]);
        }
        else
        {
            ans.back()[1]=max(vBack[1],res[i][1]);
        }
    }
    for(auto it:ans)
    {
        cout<<it[0]<<" "<<it[1]<<endl;
    }
    return 0;
}
// Time Complexity:O(n)
// Auxilary Space: :O(n)