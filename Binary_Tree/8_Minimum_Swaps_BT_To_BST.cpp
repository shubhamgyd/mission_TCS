#include<bits/stdc++.h>
using namespace std;



/*
Basically the intuition behind this que is number of swaps required to make the array sorted
step 1: find the inorder traversal  of the given binary tree
step 2: then apply the algorithm to count the munimum number of swaps to sort the array

Below is the graph approach to count swaps
*/
void inorder(vector<int>&arr, vector<int> &v,int n, int index)
{
    if(index >= n)  return;
    inorder(arr, v, n, 2 * index + 1);
    v.push_back(arr[index]);
    inorder(arr, v, n, 2 * index + 2);
}
int minimumSwaps(vector<int>&arr, int n) {
	// Write your code here.
    //sort(arr,arr+n);
    vector<int>v;
    inorder(arr,v,n,0);
    pair<int,int>nums[n];
    for(int i=0;i<n;i++)
    {
        nums[i].first=v[i];
        nums[i].second=i;
    }
    sort(nums,nums+n);
    vector<bool>visited(n,false);
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(visited[i] || nums[i].second==i)
        {
            continue;
        }
        int cycle=0;
        int j=i;
        while(!visited[j])
        {
            visited[j]=1;
            j=nums[j].second;
            cycle++;
        }
        if(cycle>0)
        {
            count+=(cycle-1);
        }
    }
    return count;
}