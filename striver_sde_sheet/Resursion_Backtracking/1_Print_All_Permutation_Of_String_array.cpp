/*
Problem Statement: Given an array arr of distinct integers, print all permutations of String/Array.

Examples:

Example 1: 

Input: arr = [1, 2, 3]

Output: 
[
  [1, 2, 3],
  [1, 3, 2],
  [2, 1, 3],
  [2, 3, 1],
  [3, 1, 2],
  [3, 2, 1]
]

Explanation: Given an array, return all the possible permutations.

Example 2:

Input: arr = [0, 1]

Output:
[
  [0, 1],
  [1, 0]
]

Explanation: Given an array, return all the possible permutations.
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    void dfs(int pos,vector<int>&nums,vector<vector<int>>&res)
    {
        if(pos>=nums.size())
        {
            res.push_back(nums);
            return;
        }
        for(int i=pos;i<nums.size();i++)
        {
            swap(nums[i],nums[pos]);
            dfs(pos+1,nums,res);
            swap(nums[i],nums[pos]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // vector<vector<int>>res;
        // do
        // {
        //     res.push_back(nums);
        // }while(next_permutation(nums.begin(),nums.end()));
        // return res;
        
        vector<vector<int>>res;
        dfs(0,nums,res);
        return res;
    }
};



/*

    Time Complexity: O(N*N!).
    Space Complexity: O(N).

    Where N is the length of the input string.

*/



// Swaping two alphabets in a string.
void swap(string &s, int i, int j) {
    char te = s[i];
    s[i] = s[j];
    s[j] = te;
}

void findPermutationsHelper(string &s, int i, int j, vector <string> &ans) {
    if (i >= j) {
        // Storing the string in the vector ans.
        string permutation = "";

        for (int k = 0; k < s.length(); k++) {
            permutation += (s[k]);
        }

        ans.push_back(permutation);
        return;
    }

    // Fixing a character at index i and then swapping with characters from index i to j and by this way building up permutation strings.
    for (int k = i; k <= j; k++) {
        swap(s, i, k);

        findPermutationsHelper(s, i + 1, j, ans);

        swap(s, i, k);
    }

}

vector <string> findPermutations(string &s) {
    // Declaring a vector of string to store all the possible permutations of the string.
    vector <string> ans;

    // Calling the user defined function which stores all the possible permutations of the string in the vector ans.
    findPermutationsHelper(s, 0, s.length() - 1, ans);

    return ans;
}