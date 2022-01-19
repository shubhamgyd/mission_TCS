/*
This problem was asked by Twitter.

You run an e-commerce website and want to record the last N order ids in a log. Implement a 
data structure to accomplish this, with the following API:

record(order_id): adds the order_id to the log
get_last(i): gets the ith last element from the log. i is guaranteed to be smaller than or 
equal to N.
You should be as efficient with time and space as possible.
*/


#include<bits/stdc++.h>
using namespace std;


class LogDataStructure
{
    int mxSize;
    vector<int>circularBuffer;
    int currIndex;
public:
    LogDataStructure(int n)
    {
        mxSize=n;
        circularBuffer.resize(n);
        currIndex=0;
    }

    void record(int orderId)
    {
        circularBuffer[currIndex]=orderId;
        currIndex=(currIndex+1)%mxSize;
    }
    int getLast(int i)
    {
        return circularBuffer[(currIndex-i+mxSize)%mxSize];
    }
};


int main()
{

}