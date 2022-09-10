#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    vector<int>prev(n);
    prev[0]=nums[0];
    for(int i=1;i<n;i++)
    {
        prev[i]=min(prev[i-1],nums[i]);
    }
    int diff=INT_MIN;
    int i=n-1;
    int j=n-1;
    int firstInd=n;
    int secondInd=n;
    while(i>=0 and j>=0)
    {
        if(nums[j] >= prev[i])
        {
            diff= max(diff, j-i);
            if(j<=secondInd)
            {
                secondInd=j;
                firstInd=i;
            }
            i--;
        }
        else 
            j--;
    }
    cout<<diff<<endl;
    cout<<firstInd<<" "<<secondInd<<endl;
    return 0;
}