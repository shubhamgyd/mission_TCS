/*
This problem was asked by Google.

Given an array of integers and a number k, where 1 <= k <= length of the array, compute the 
maximum values of each subarray of length k.

For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:

10 = max(10, 5, 2)
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)
Do this in O(n) time and O(k) space. You can modify the input array in-place and you do not 
need to store the results. You can simply print them out as you compute them.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    priority_queue<int>pq;
    unordered_map<int,int>mp;
    int i=0;
    int j=0;
    vector<int>ans;
    while(j<n)
    {
        pq.push(res[j]);
        if(j-i+1<k)
        {
            mp[res[j]]++;
            j++;
        }
        else if(j-i+1==k)
        {
            mp[res[j]]++;
            mp[res[i]]--;
            i++;
            ans.push_back(pq.top());
            while(!pq.empty() && mp[pq.top()]==0)
            {
                pq.pop();
                // i++;
            }
            j++;
        }
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
// Time Complexity:O(n)
// Space Complexity:O(k)