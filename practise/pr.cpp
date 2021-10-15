#include<bits/stdc++.h>
using namespace std;


int setBitCount(int num){
	int count = 0;
	while ( num )
	{
		if ( num & 1)
		count++;
		num >>= 1;
	}
	return count;
}

bool cmp(pair<int,int>a,pair<int,int>b)
{
	if(a.second==b.second)
	{
		return a.first<b.first;
	}
	return a.second>b.second;
}

vector<int> cardinalitySort(vector<int>nums)
{
	int n=nums.size();
	multimap< int, int > count;
	for( int i = 0 ; i < n ; ++i )
	{
		count.insert({(-1) *
			setBitCount(nums[i]), nums[i]});
	}

	vector<pair<int,int>>res;
	for(auto i : count)
	{
		res.push_back({i.second,i.first});
	}
	sort(res.begin(),res.end(),cmp);
	vector<int>ans;
	for(auto it:res)
	{
		ans.push_back(it.first);
	}
	return ans;
}

int main()
{
	
}






// #include <bits/stdc++.h>
// using namespace std;

// int stockPairs(vector<int> stockProfit, int target)
// {

// 	long N=stockProfit.size();
// 	long cntPairs = 0;
// 	unordered_map<int, int> cntFre;

// 	for (int i = 0; i < N; i++) {
// 		cntFre[stockProfit[i]]++;
// 	}

// 	for (auto it : cntFre) {
// 		int i = it.first;
// 		if (2 * i == target) {
// 			if (cntFre[i] > 1)
// 				cntPairs += 2;
// 		}

// 		else {

// 			if (cntFre[target - i]) {
// 				cntPairs += 1;
// 			}
// 		}
// 	}
// 	cntPairs = cntPairs / 2;
// 	return cntPairs;
// }

// int main()
// {
// 	int n;
// 	cin>>n;
// 	// int arr[n];
// 	vector<int>arr;
// 	for(int i=0;i<n;i++)
// 	{
// 		cin>>arr[i];
// 	}
// 	int target;
// 	cin>>target;
// 	cout <<stockPairs(arr, target);
// }
