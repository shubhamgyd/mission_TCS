// The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.

// For example, for arr = [2,3,4], the median is 3.
// For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
// Implement the MedianFinder class:

// MedianFinder() initializes the MedianFinder object.
// void addNum(int num) adds the integer num from the data stream to the data structure.
// double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.




#include<bits/stdc++.h>
using namespace std;



class MedianFinder {
    priority_queue<int,vector<int>,greater<int>>mnHeap;
    priority_queue<int>mxHeap;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        mnHeap=priority_queue<int,vector<int>,greater<int>>();
        mxHeap=priority_queue<int>();
    }
    
    void addNum(int num) {
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
    }
    
    double findMedian() {
        
        if(mnHeap.size()>mxHeap.size())
        {
            return (double)mnHeap.top();
        }
        else if(mxHeap.size()>mnHeap.size())
        {
            return (double)mxHeap.top();
        }
        return (double)(mnHeap.top()+mxHeap.top())/(2.0);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */