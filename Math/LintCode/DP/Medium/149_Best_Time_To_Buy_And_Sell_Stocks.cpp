/*
Description
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example
Example 1

Input: [3, 2, 3, 1, 2]
Output: 1
Explanation: You can buy at the third day and then sell it at the 4th day. The profit is 2 - 1 = 1
Example 2

Input: [1, 2, 3, 4, 5]
Output: 4
Explanation: You can buy at the 0th day and then sell it at the 4th day. The profit is 5 - 1 = 4
Example 3

Input: [5, 4, 3, 2, 1]
Output: 0
Explanation: You can do nothing and get nothing.
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int mx=prices[0];
        int sum=0;
        int n=prices.size();
        for(int i=1;i<n;i++)
        {
            if(prices[i]<mx)
            {
                mx=prices[i];
            }
            else
            {
                sum=max(sum,prices[i]-mx);
            }
        }
        return sum;
    }
};

/*
Time complexity:O(n)
Space Complexity:O(1)
*/