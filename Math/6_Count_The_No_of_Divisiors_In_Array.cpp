#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }

    vector<int>cnt(10000,0);
    for(int i=0;i<n;i++)
    {
        cnt[res[i]]++;
    }
    vector<int>ans(10000,0);
    for(int i=1;i<10000;i++)
    {
        for(int j=2*i;j<10000;j+=i)
        {
            ans[i]+=cnt[j];
        }
    }

    int totalCount=0;
    for(int i=0;i<n;i++)
    {
        totalCount+=ans[res[i]];
    }
    cout<<totalCount<<endl;


}
// Time Complexity:O(nlogn)