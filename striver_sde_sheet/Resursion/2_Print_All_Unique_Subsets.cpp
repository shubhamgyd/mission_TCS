/*
Problem Statement: Given an array of integers that may contain duplicates the 
task is to return all possible subsets. Return only unique subsets and they can be in any order.
*/

#include<bits/stdc++.h>
using namespace std;

void solve(int i,vector<int>&res,vector<int>&temp,set<vector<int>>&ans)
{
    if(i>=res.size())
    {
        sort(temp.begin(),temp.end());
        ans.insert(temp);
        return;
    }
    temp.push_back(res[i]);
    solve(i+1,res,temp,ans);
    temp.pop_back();
    solve(i+1,res,temp,ans);
}
// Time Complexity: O( 2^n *(k log (x) )). 2^n  for generating every subset and k* log( x)  to insert every combination of average length k in a set of size x. After this, we have to convert the set of combinations back into a list of list /vector of vectors which takes more time.
// Space Complexity:  O(2^n * k) to store every subset of average length k. Since we are initially using a set to store the answer another O(2^n *k) is also used.








// Solution 2: Optimal

// Approach: 

// In the previous method, we were taking extra time to store the unique combination 
// with the help of a set.  To make the solution efficient we will have to decide on a 
// method that will consider only the unique combinations without the help of additional 
// data structure.

class Solution {
   private:
      void findSubsets(int ind, vector < int > & nums, vector < int > & ds, vector < vector < int >> & ans) {
         ans.push_back(ds);
         for (int i = ind; i < nums.size(); i++) {
            if (i != ind && nums[i] == nums[i - 1]) continue;
            ds.push_back(nums[i]);
            findSubsets(i + 1, nums, ds, ans);
            ds.pop_back();
         }
      }
   public:
      vector < vector < int >> subsetsWithDup(vector < int > & nums) {
         vector < vector < int >> ans;
         vector < int > ds;
         sort(nums.begin(), nums.end());
         findSubsets(0, nums, ds, ans);
         return ans;
      }
};

// Time Complexity: O(2^n) for generating every subset and O(k)  to insert every subset in another data structure if the average length of every subset is k. Overall O(k * 2^n).
// Space Complexity: O(2^n * k) to store every subset of average length k. Auxiliary space is O(n)  if n is the depth of the recursion tree.


int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    set<vector<int>>ans;
    vector<int>temp;
    solve(0,res,temp,ans);
    for(auto it:ans)
    {
        cout<<"[";
        for(auto ele:it)
        {
            cout<<ele<<" ";
        }
        cout<<"]";
    }
}