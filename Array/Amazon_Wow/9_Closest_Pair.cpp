#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());
    int dist=INT_MAX;
    for(int i=0;i<n-1;i++)
    {
        int currDist=nums[i+1]-nums[i];
        if(currDist<dist)
        {
            dist=currDist;
        }
    }
    cout<<dist<<endl;
    return 0;
}