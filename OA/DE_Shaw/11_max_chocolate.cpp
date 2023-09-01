/*
There is an array of pile of chocolates, in every iteration Ayushi chose pile with maximum number of chocolates, after that square root of chocolate remains and rest is eaten by Ayushi. After k iterations find number of chocolates remaining.

Input Format
It consist of 3 lines.
First line contain n (size of pile)
Second line contains n space separated integers
Third line contains k (no. of iteration)

Output Format:
print one integer the total sum of chocolates remaining.

Sample Input:
5
25 64 9 4 100
4

Sample Output:
29
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int k;
    cin >> k;
    priority_queue<int> pq;
    for (auto it : nums)
    {
        pq.push(it);
    }
    int cnt = 0;
    while (k--)
    {
        int num = pq.top();
        pq.pop();
        int sq = sqrt(num);
        pq.push(sq);
    }
    while (!pq.empty())
    {
        cnt += pq.top();
        pq.pop();
    }
    cout << cnt << endl;
    return 0;
}