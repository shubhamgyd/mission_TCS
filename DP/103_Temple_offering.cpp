/*
Consider a devotee wishing to give offerings to temples along with a mountain range. 
The temples are located in a row at different heights. Each temple should receive at 
least one offer. If two adjacent temples are at different altitudes, then the temple that 
is higher up should receive more offerings than the one that is lower down. If two adjacent 
temples are at the same height, then their offerings relative to each other do not matter.
Given the number of temples and the heights of the temples in order, find the minimum number
of offerings to bring.

Examples:

Input  : 3
         1 2 2
Output : 4
All temples must receive at-least one offering.
Now, the second temple is at a higher altitude
compared to the first one. Thus it receives one
extra offering. 
The second temple and third temple are at the 
same height, so we do not need to modify the 
offerings. Offerings given are therefore: 1, 2,
1 giving a total of 4.

Input  : 6
         1 4 3 6 2 1
Output : 10
We can distribute the offerings in the following
way, 1, 2, 1, 3, 2, 1. The second temple has to 
receive more offerings than the first due to its 
height being higher. The fourth must receive more
than the fifth, which in turn must receive more 
than the sixth. Thus the total becomes 10.
*/

#include <bits/stdc++.h>
using namespace std;


int solve(int arr[],int n)
{
	int left[n];
	left[0]=1;
	for(int i=1;i<n;i++)
	{
		if(arr[i]>arr[i-1])
		{
			left[i]=left[i-1]+1;
		}
		else
		{
			left[i]=1;
		}
	}
	int right[n];
	right[n-1]=1;
	for(int i=n-2;i>=0;i--)
	{
		// if(i==n-1) left[i]=max(left[i],1);
		if(arr[i]>arr[i+1])
		{
			right[i]=right[i+1]+1;
		}
		else
		{
			right[i]=1;
		}

	}
	for(int i=0;i<n;i++)
	{
		cout<<left[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<right[i]<<" ";
	}
	cout<<endl;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=max(right[i],left[i]);
	}
	return sum;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<solve(arr,n)<<endl;
	return 0;
}