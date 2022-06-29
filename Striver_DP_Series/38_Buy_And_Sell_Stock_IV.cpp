/*
Problem Statement
You have been given an array 'PRICES' consisting of 'N' integers where PRICES[i] denotes the price of a given stock on the i-th day. You are also given an integer 'K' denoting the number of possible transactions you can make.
Your task is to find the maximum profit in at most K transactions. A valid transaction involves buying a stock and then selling it.
Note
You can’t engage in multiple transactions simultaneously, i.e. you must sell the stock before rebuying it.
For Example
Input: N = 6 , PRICES = [3, 2, 6, 5, 0, 3] and K = 2.
Output: 7

Explanation : The optimal way to get maximum profit is to buy the stock on day 2(price = 2) and sell it on day 3(price = 6) and rebuy it on day 5(price = 0) and sell it on day 6(price = 3). The maximum profit will be (6 - 2) + (3 - 0) = 7.
Input Format
The first line of input contains an integer 'T' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case contains two single-space separated integers ‘N’ and ‘K’, respectively.

The second line of each test case contains ‘N’ single space-separated integers, denoting the elements of the array 'PRICES'.
Output Format
For each test case, print a single integer denoting the maximum profit in at most K transactions.

Print the output of each test case in a separate line.
Note
You do not need to print anything; it has already been taken care of. Just implement the given function.
Constraints
1 <= T <= 100
1 <= N <= 5000
0 <= K <= N/2
0 <= ARR[i] <=10^5

Time Limit : 1 sec
Sample Input 1
2
5 2
8 5 1 3 10
4 2
10 8 6 2 
Sample Output 1
9
0
*/


// Same as previous
// we have to just instead of k=2 we need to take actual k

#include<bits/stdc++.h>
using namespace std;

int main()
{

}