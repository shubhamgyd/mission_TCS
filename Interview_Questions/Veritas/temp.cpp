#include<bits/stdc++.h>
using namespace std;


long calculateAmount(vector<long>&prices)
{
    
    long ans=prices[0];
    long n=prices.size();
    priority_queue<long,vector<long>,greater<long>>pq;
    pq.push(prices[0]);
    for(long i=1;i<n;i++)
    {
        if(prices[i]<prices[i-1])
        {
            long num=max(prices[i]-pq.top(),(long)0);
            ans+=num;
        }
        else
        {
            ans+=abs(prices[i]-prices[i-1]);
        }
        pq.push(prices[i]);
    }
    return ans;
}

int main()
{
    long n;
    cin>>n;
    vector<long>nums(n);
    for(long i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    long ans=calculateAmount(nums);
    cout<<ans<<endl;
}