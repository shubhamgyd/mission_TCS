/*
Problem Statement
You are given an array/list 'prices' where the elements of the array represent the prices of the stock as they were yesterday and indices of the array represent minutes. Your task is to find and return the maximum profit you can make by buying and selling the stock. You can buy and sell the stock only once.
Note:
You can’t sell without buying first.
For Example:
For the given array [ 2, 100, 150, 120],
The maximum profit can be achieved by buying the stock at minute 0 when its price is Rs. 2 and selling it at minute 2 when its price is Rs. 150.
So, the output will be 148.
Input Format:
The first line contains a single integer ‘T’ denoting the number of test cases to be run. Then the test cases follow.

The first line of each test case contains a single integer ‘N’, representing the size of the array.

The second line of each test case contains ‘N’ space-separated integers representing the elements of the given array.
Output Format:
For each test case, print a single integer representing the maximum profit you can achieve. If the maximum profit is negative, print 0.

Output for each test case will be printed in a separate line.
Note :
You are not required to print anything, it has already been taken care of. Just implement the function.
Constraints:
1 <= T <= 10
2 <= N <= 10^4
1 <= ARR[i] <= 10^9

Time Limit: 1 sec.
Sample Input 1:
2
4
1 2 3 4
4
2 2 2 2
Sample Output 1:
3
0
*/

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    int n=nums.size();
    int num=nums[0];
    int mx=0;
    for(int i=1;i<n;i++)
    {
        if(nums[i]>num)
        {
            mx=max(mx,nums[i]-num);
        }
        else
        {
            num=nums[i];
        }
    }
    cout<<mx<<endl;
    return 0;
    // Time Complexity:O(n)
    // Space Complexity:O(1)
}