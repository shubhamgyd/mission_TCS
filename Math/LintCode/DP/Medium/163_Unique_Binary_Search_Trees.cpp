/*
Description
Given n, how many structurally unique BSTs (binary search trees) that store values 1...n?

Example
Example 1:

Input:n = 3,
Output: 5
Explanation:there are a total of 5 unique BST's.
1           3    3       2      1
 \         /    /       / \      \
  3      2     1       1   3      2
 /      /       \                  \
2     1          2                  3
*/

// Concept of catalan number

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        // write your code here
        long long int catalan[n+1];
        catalan[0]=catalan[1]=1;
        for(int i=2;i<=n;i++)
        {
            catalan[i]=0;
            for(int j=0;j<i;j++)
            {
                catalan[i]=catalan[i]+catalan[j]*catalan[i-j-1];
            }
        }
        return catalan[n];
    }
};