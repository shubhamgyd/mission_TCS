/*
This problem was asked by Apple.

Implement a queue using two stacks. Recall that a queue is a FIFO (first-in, first-out) 
data structure with the following methods: enqueue, which inserts an element into the queue, 
and dequeue, which removes it.
*/

#include<bits/stdc++.h>
using namespace std;



int main()
{
    stack<int>st1,st2;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Type: ";
        int type;
        cin>>type;
        if(type==1)
        {
            int num;
            cin>>num;
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
            st1.push(num);
            while(!st2.empty())
            {
                st1.push(st2.top());
                st2.pop();
            }
        }
        else if(type==0)
        {
            if(st1.empty())
            {
                cout<<"Stack is empty..!!!Stack underflow"<<endl;
                return 0;
            }
            int x=st1.top();
            st1.pop();
            cout<<"Popped element is : "<<x<<endl;
        }
    }
    return 0;
}