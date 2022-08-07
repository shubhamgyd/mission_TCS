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
    int dist=0;
    int i=0;
    int j=n-1;
    while(i<j)
    {
        int h=min(nums[i],nums[j]);
        dist=max(dist,j-i);
        while(nums[i]<=h and i<j) i++;
        while(nums[j]<=h and j>i) j--;
    }
    cout<<dist<<endl;
    return 0;
}