// In this problem we are going to find the maximum element of every window of size k

#include<bits/stdc++.h>
using namespace std;

vector<int> findMax(const vector<int>&v , int k)
{
    int n=v.size();
    priority_queue<int>pq;
    unordered_map<int,int>mp;
    int i=0,j=0;
    vector<int>ans;
    while(j<n)
    {
        pq.push(v[j]);
        if(j-i+1<k)
        {
            mp[v[j]]++;
            j++;
        }
        else if(j-i+1==k)
        {
            mp[v[j]]++; // adding the current element into the list
            mp[v[i]]--; // Deleting the front element of the list
            i++; // incrementing the size of window
            ans.push_back(pq.top());  // putting into vector , if the top element of list  is greater than the current element
            while(!pq.empty()&&mp[pq.top()]==0)
            {
                pq.pop();
            }
            j++; // slide window
        }
    }
    return ans;
}

int main()
{
    vector<int>v{1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k=3;
    vector<int>vs{findMax(v,k)};
    for(auto ele:vs)
    {
        cout<<ele<<" ";
    }
    return 0;
}