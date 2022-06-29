/*
Problem Statement: Given an array print all the sum of the subset generated from it, in the increasing order.
*/

#include<bits/stdc++.h>
using namespace std;


// Using Backtracking
void subsetsUtil(vector<int>& A, vector<int>& res,int index,int sum) 
{ 
    res.push_back(sum); 
    for (int i = index; i < A.size(); i++) { 
  
        // include the A[i] in subset. 
        sum+=A[i]; 
  
        // move onto the next element. 
        subsetsUtil(A, res, i + 1,sum); 
  
        // exclude the A[i] from subset and triggers 
        // backtracking. 
        sum-=A[i];
    } 
  
    return; 
} 
// Time Complexity: Exponential



void solve(int i, int n,vector<int>&res,vector<int>&temp,int sum)
{
    if(i>=n)
    {
        temp.push_back(sum);
        return;
    }
    solve(i+1,n,res,temp,sum+res[i]);
    solve(i+1,n,res,temp,sum);
}
// Time Complexity: O(2^n)+O(2^n log(2^n)). Each index has two ways. You can either pick it up or not pick it. So for n index time complexity for O(2^n) and for sorting it will take (2^n log(2^n)).
// Space Complexity: O(2^n) for storing subset sums, since 2^n subsets can be generated for an array of size n.

int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    vector<int>temp;
    int sum=0;
    solve(0,n,res,temp,sum);
    sort(temp.begin(),temp.end());
    for(auto it:temp)
    {
        cout<<it<<" ";
    }
    vector<int>a;
    int s=0;
    cout<<endl;
    subsetsUtil(res,a,0,s);
    sort(a.begin(),a.end());
    for(auto it:a)
    {
        cout<<it<<" ";
    }

}