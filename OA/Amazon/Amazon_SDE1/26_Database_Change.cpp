#include<bits/stdc++.h>
using namespace std;

vector<int> findDataLocations(vector<int>&locations,vector<int>&movedFrom,vector<int>&movedTo)
{
	int n=movedFrom.size();
	map<int,bool>mp;
	for(auto it:locations)
	{
		mp[it]=true;
	}
	for(int i=0;i<n;i++)
	{
		mp[movedFrom[i]]=false;
		mp[movedTo[i]]=true;
	}
	vector<int>ans;
	for(auto it:mp)
	{
		if(it.second==true)
		{
			ans.push_back(it.first);
		}
	}
	return ans;
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
	int m;
	cin>>m;
	vector<int>moveFrom(m),moveTo(m);
	for(int i=0;i<m;i++)
	{
		cin>>moveFrom[i];
	}
	for(int i=0;i<m;i++)
	{
		cin>>moveTo[i];
	}
	vector<int>ans=findDataLocations(nums,moveFrom,moveTo);
	for(auto it:ans)
	{
		cout<<it<<" ";
	}
	return 0;
}