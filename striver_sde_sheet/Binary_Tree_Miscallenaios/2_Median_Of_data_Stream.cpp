#include<bits/stdc++.h>
using namespace std;

vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
    priority_queue<int,vector<int>,greater<int>>mnHeap;
    priority_queue<int>mxHeap;
    vector<int>ans;
    for(auto it:arr)
    {
        int num=it;
        if(mxHeap.empty() or mxHeap.top()>num)
        {
            mxHeap.push(num);
        }
        else
        {
            mnHeap.push(num);
        }
        if(mxHeap.size()>mnHeap.size()+1)
        {
            mnHeap.push(mxHeap.top());
            mxHeap.pop();
        }
        else if(mnHeap.size()>mxHeap.size()+1)
        {
            mxHeap.push(mnHeap.top());
            mnHeap.pop();
        }
        if(mnHeap.size()>mxHeap.size())
        {
            ans.push_back(mnHeap.top());
        }
        else if(mxHeap.size()>mnHeap.size())
        {
           ans.push_back(mxHeap.top());
        }
        else ans.push_back((mnHeap.top()+mxHeap.top())/2);
    }
    return ans;
}
