#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int minDeletion(int arr[],int n)
	{
		sort(arr,arr+n,greater<int>());
		int ct=0;
		for(int i=1;i<n;i++)
		{
			if(arr[i-1]!=arr[i])
			{
				ct+=i;
			}
		}
		return ct;
	}
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	Solution obj;
	int arr[]={5,2,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<obj.minDeletion(arr,n)<<endl;
}
