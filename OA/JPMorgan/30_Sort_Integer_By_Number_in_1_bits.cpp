/*
You are given an integer array arr. Sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.

Return the array after sorting it.



Example 1:

Input: arr = [0,1,2,3,4,5,6,7,8]
Output: [0,1,2,4,8,3,5,6,7]
Explantion: [0] is the only integer with 0 bits.
[1,2,4,8] all have 1 bit.
[3,5,6] have 2 bits.
[7] has 3 bits.
The sorted array by bits is [0,1,2,4,8,3,5,6,7]
Example 2:

Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
Output: [1,2,4,8,16,32,64,128,256,512,1024]
Explantion: All integers have 1 bit in the binary representation, you should just sort them in ascending order.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        int n = arr.size();
        vector<pair<int, int>> arr1;
        for (int num : arr)
        {
            int cnt = __builtin_popcount(num);
            arr1.push_back({cnt, num});
        }
        sort(begin(arr1), end(arr1));
        vector<int> ans;
        for (auto it : arr1)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};

static int numberof1s(int a)
{
    int count = 0;
    while (a)
    {
        a = a & (a - 1);
        count++;
    }
    return count;
}
static bool compare(int a, int b)
{
    int p = numberof1s(a);
    int q = numberof1s(b);
    if (p == q)
    {
        return (a <= b);
    }
    else
    {
        return (p < q);
    }
}
vector<int> sortByBits(vector<int> &arr)
{
    sort(arr.begin(), arr.end(), compare);
    return arr;
}