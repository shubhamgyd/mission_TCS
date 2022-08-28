/*
This problem was asked by Palantir.

In academia, the h-index is a metric used to calculate the impact of a researcher's papers. 
It is calculated as follows:

A researcher has index h if at least h of her N papers have h citations each. 
If there are multiple h satisfying this formula, the maximum is chosen.

For example, suppose N = 5, and the respective citations of each paper are [4, 3, 0, 1, 5].
 Then the h-index would be 3, since the researcher has 3 papers with at least 3 citations.

Given a list of paper citations of a researcher, calculate their h-index.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>>citations(n);
    for(int i=0;i<n;i++)
    {
        cin>>citations[i].first;
        citations[i].second=i;
    }
    sort(citations.begin(),citations.end());
    int n = citations.size(), ans=0;
	for(int i=n-1;i>=0;i--){
		if(citations[i].first>=n-i)
			ans = n-i;
		else
			break;
	}
	cout<<ans<<endl;
    return 0;
}