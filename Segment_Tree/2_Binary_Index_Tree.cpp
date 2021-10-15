#include <bits/stdc++.h>
using namespace std;
const int N=500;
int BITree[N];

class Solution
{
public:
	void Update(int index,int val,int n)
	{
		// index in BITree[] is 1 more than the index in arr[]
    	index = index + 1;
    	while(index<=n)
    	{
    		// Add val to the current node of BITree
    		BITree[index]+=val;

    		//// Update index to that of parent in update View
    		index+=index&(-index);
    	}
	}



	void ConstructBITree(int arr[],int n)
	{
		for(int i=1;i<=n;i++)
		{
			BITree[i]=0;
		}

		for(int i=0;i<n;i++)
		{
			Update(i,arr[i],n);
		}

	}

	int getSum(int k)
	{
		int sum=0;
		k+=1;
		while(k>=1)
		{
			// Add current elemet to the sum
			sum+=BITree[k];

			// Move index to parent node in getSum View
			k-=k&(-k);
		}
		return sum;
	}
};

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
   int arr[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
   int n = sizeof(arr)/sizeof(arr[0]);
   Solution obj;
   obj.ConstructBITree(arr,n);
   cout<<"Sum till given index is: "<<obj.getSum(5)<<endl;
   arr[3]+=6;
   obj.Update(3,6,n);
   cout<<"Sum till given index is: "<<obj.getSum(5)<<endl;
   cout<<"Sum till given index is: "<<obj.getSum(4)<<endl;
   return 0;
}