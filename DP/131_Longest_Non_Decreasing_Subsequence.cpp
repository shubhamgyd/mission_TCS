#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	int minInsertions(int a[], int n) 
	{ 
	    vector<int> dp(n,INT_MAX);
	    
	    for(int i = 0 ; i < n ; i++)
	    dp[ upper_bound(dp.begin(),dp.end(),a[i]) - dp.begin()] = a[i];
	    
	    return n - ( lower_bound(dp.begin(),dp.end(),INT_MAX) - dp.begin());
	} 
};