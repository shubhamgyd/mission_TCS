#include<bits/stdc++.h>
using namespace std;



class MedianFinder {
    priority_queue<int>pq1;
    priority_queue<int,vector<int>,greater<int>>pq2;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        pq1=priority_queue<int>();
        pq2=priority_queue<int,vector<int>,greater<int>>();
    }
    
    void addNum(int num) {
       if(pq1.empty() || pq1.top()>num)
       {
           pq1.push(num);
       }
        else
        {
            pq2.push(num);
        }
        if(pq1.size()>pq2.size()+1)
        {
            pq2.push(pq1.top());
            pq1.pop();
        }
        else if(pq2.size()>pq1.size()+1)
        {
            pq1.push(pq2.top());
            pq2.pop();
        }
    }
    
    double findMedian() {
        if(pq1.size()==pq2.size())
        {
            //cout<<pq1.top()<<" "<<pq2.top()<<endl;
            double res=double(pq1.top()+pq2.top())/2;
            return res;
        }
        else if(pq1.size()>pq2.size())
        {
            double res=pq1.top();
            return res;
        }
        else
        {
            double res=pq2.top();
            return res;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */