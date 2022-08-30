#include<bits/stdc++.h>
using namespace std;

long findMaximumSum(vector<int>&stockPrice,int k)
{
	int n=stockPrice.size();
    if(k>n)
    {
        return -1;
    }
	long pref[n];
	pref[0]=stockPrice[0];
	for(int i=1;i<n;i++)
	{
		pref[i]=pref[i-1]+stockPrice[i];
	}
	long max_sum=0;
	unordered_map<int,int>mp;
    for(int i=0;i<k;i++)
    {
		if(mp.find(stockPrice[i])==mp.end())
		{
			max_sum+=stockPrice[i];
		}
		else
		{
			max_sum=0;
			break;
		}
		mp[stockPrice[i]]++;
    }

	int j=0;
    for(int i=k;i<n;i++)
    {
		mp[stockPrice[j]]--;
		if(mp[stockPrice[j]]==0)
		{
			mp.erase(stockPrice[j]);
		}
		j++;
		if(mp.find(stockPrice[i])==mp.end() and mp.size()==k-1)
		{
			max_sum=max(max_sum,pref[i]-pref[j-1]);
		}
		mp[stockPrice[i]]++;
    }
    return max_sum==0?-1:max_sum;
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
	int k;
	cin>>k;
	int ans=findMaximumSum(nums,k);
	cout<<ans<<endl;
}