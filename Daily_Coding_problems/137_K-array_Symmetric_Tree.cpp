/*
A tree is symmetric if its data and shape remain unchanged when it is reflected about the root node. 
The following tree is an example:

        4
      / | \
    3   5   3
  /           \
9              9
Given a k-ary tree, determine whether it is symmetric.
*/

#include<bits/stdc++.h>
using namespace std;

int maxPairs(int input1,int input2[],int input3,int input4[])
{
  sort(input2,input2+input1);
  
}

int main()
{
  int k;
  cin>>k;
  int arr[k];
  for(int i=0;i<k;i++)
  {
    cin>>arr[i];
  }
  int n;
  cin>>n;
  int res[n];
  for(int i=0;i<n;i++)
  {
    cin>>res[i];
  }
  int ans=maxPairs(k,arr,n,res);
  cout<<ans<<endl;
  return 0;
}