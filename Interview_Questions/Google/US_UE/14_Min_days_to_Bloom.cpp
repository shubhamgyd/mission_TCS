/*
Given an array of roses. roses[i] means rose i will bloom on day roses[i]. 
Also given an int k, which is the minimum number of adjacent bloom roses
 required for a bouquet, and an int n, which is the number of bouquets we need. 
 Return the earliest day that we can get n bouquets of roses.

Example:
Input: roses = [1, 2, 4, 9, 3, 4, 1], k = 2, n = 2
Output: 4
Explanation:
day 1: [b, n, n, n, n, n, b]
The first and the last rose bloom.

day 2: [b, b, n, n, n, n, b]
The second rose blooms. Here the first two bloom roses make a bouquet.

day 3: [b, b, n, n, b, n, b]

day 4: [b, b, b, n, b, b, b]
Here the last three bloom roses make a bouquet, meeting the required n = 2 
bouquets of bloom roses. So return day 4.
*/


#include<bits/stdc++.h>
using namespace std;


class Solution {
    static bool Check(vector<int>&res,int mid,int k,int m)
    {
        int grow=0;
        int count=0;
        for(int i=0;i<res.size();i++)
        {
            if(res[i]<=mid)
            {
                grow++;
            }
            else
            {
                count+=grow/k;
                grow=0;
            }
        }
        // count is nothing but the number of boquets
        count+=grow/k;
        // cout<<"grow: "<<grow<<endl;
        if(count>=m)
        {
            return true;
        }
        return false;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans=-1;
        int low=1;
        int high=1e9;
        while(low<=high)
        {
            // mid is nothing but the day number 
            int mid=low+(high-low)/2;
            // cout<<"mid: "<<mid<<endl;
            if(Check(bloomDay,mid,k,m))
            {
                ans=mid;
                high=mid-1;
                // low=mid+1;
            }
            else
            {
                low=mid+1;
                // high=mid+1;
            }
        }
        return ans;
    }
};

int main()
{
    int num;
    cin>>num;
    vector<int>roses(num);
    for(int i=0;i<num;i++)
    {
        cin>>roses[i];
    }
    int k;
    cin>>k;
    int n;
    cin>>n;
    int ans=-1;
    int low=1;
    int high=num;
    while(low<=high)
    {

    }
}