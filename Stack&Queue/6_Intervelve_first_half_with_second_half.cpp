#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue<int>q;
    for(int i=1;i<=10;i++)
    {
        q.push(i);
    }
    queue<int>q1;
    queue<int>pq;
    int sz=q.size()/2;
    for(int i=0;i<sz;i++)
    {
        q1.push(q.front());
        q.pop();
    }
    while(!q.empty() || !q1.empty())
    {
        pq.push(q1.front());
        q1.pop();
        pq.push(q.front());
        q.pop();
    }
    while(!pq.empty())
    {
        cout<<pq.front()<<" ";
        pq.pop();
    }
    return 0;
}