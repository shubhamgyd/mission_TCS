
#include<bits/stdc++.h>
using namespace std;


struct Result
{
    Result(): output1(){}
    int output1[100];
};

// int preIndex = 0;
void printPost(int in[], int pre[], int inStrt,int inEnd, map<int, int> hm,vector<int>&arr,int &preIndex,int ind)
{
	if (inStrt > inEnd) return;		
	int inIndex = hm[pre[preIndex++]];
	printPost(in, pre, inStrt, inIndex - 1, hm,arr,preIndex,ind);
	printPost(in, pre, inIndex + 1, inEnd, hm,arr,preIndex,ind);
    arr.push_back(in[inIndex]);
}


struct Result decrypt(int input1[],int input2[],int input3)
{
    int n=input3;
    vector<int>arr;
    map<int,int> mp;
    int preIndex=0;
	for (int i = 0; i < n; i++)
	{
        mp[input1[i]] = i;
    }
    int ind=0;
	printPost(input1, input2, 0, n - 1, mp,arr,preIndex,ind);
    Result nums=Result();
    for(int i=0;i<n;i++)
    {
        nums.output1[i]=arr[i];
    }
    return nums;
}

int main()
{
	int in[] = { 2,3,5,1,6 };
	int pre[] = {  1,3,2,5,6  };
	int n = sizeof(pre)/sizeof(pre[0]);
	Result arr;
	arr=decrypt(in,pre,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr.output1[i]<<" ";
    }
	return 0;
}

