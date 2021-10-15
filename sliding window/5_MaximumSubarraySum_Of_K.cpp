// // In this problem we are giing to find the maximum subarray sum , which gives us the max length

// #include<bits/stdc++.h>
// using namespace std;

// // This will help , when array contains -ve elements.
// int longestSubarray(int arr[] , int n ,int k)
// {
//     unordered_map<int,int>mp;
//     int sum=0,max_len=0;
//     for(int i=0;i<n;i++)
//     {
//         sum+=arr[i];
//         if(sum==k)
//         {
//             max_len=i+1;
//         }
//         if(mp.find(sum)==mp.end())
//         {
//             mp[sum]=i;
//         }
//         if(mp.find(sum-k)!=mp.end())
//         {
//             if(max_len<(i-mp[sum-k]))
//             {
//                 max_len=i-mp[sum-k];
//             }
//         }
//     }
//     return max_len;
// }

// int main()
// {
//     int arr[]={-1,-1,1};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     int k=2;
//     int i=0,j=0;
//     int maxlen=-1;
//     int sum=0;
//     while(j<n)
//     {
//         sum+=arr[j];
//         if(sum<k)
//         {
//             j++;
//         }
//         if(sum==k)
//         {
//             maxlen=max(maxlen,j-i+1);
//             j++;
//         }
//         if(sum>k)
//         {
//             while(sum>k)
//             {
//                 sum-=arr[i];
//                 i++;
//             }
//             j++;
//         }
//     }
//     cout<<"Maximum length of the subarray is: "<<maxlen<<endl;
//     cout<<"Maximum length of the subarray is: "<<longestSubarray(arr,n,k)<<endl; 
//     //Time Complexity: O(n). 
//     //Auxiliary Space: O(n).
// }

#include<bits/stdc++.h>
using namespace std;

void Maxlen(int arr[],int n,int k)
{
	unordered_map<int,int>mp;
	int i=0;
	int mx_len=0;
	int sum=0;
	while(i<n)
	{
		sum+=arr[i];
		if(sum==k)
		{
			mx_len=i+1;
		}
		if(mp.find(sum)==mp.end())
		{
			mp[sum]=i+1;
		}
		if(mp.find(sum-k)!=mp.end())
		{
			if(mx_len<i-mp[k-sum])
			{
				mx_len=i-mp[k-sum];
			}
		}
		i++;
	}
cout<<mx_len<<endl;
}

int main()
{	
	int arr[]={1,2,4,2,5,7,6,9,1,2};
	int n=sizeof(arr)/sizeof(arr[0]);
	int k=3;
	Maxlen(arr,n,k);
	return 0;
}