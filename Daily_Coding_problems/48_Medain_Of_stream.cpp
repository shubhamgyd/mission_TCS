/*
This problem was asked by Microsoft.

Compute the running median of a sequence of numbers. 
That is, given a stream of numbers, print out the median of the list so far on each new element.

Recall that the median of an even-numbered list is the average of the two middle numbers.

For example, given the sequence [2, 1, 5, 7, 2, 0, 5], your algorithm should print out:

2
1.5
2
3.5
2
2
2
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    priority_queue<int>mx;
    priority_queue<int,vector<int>,greater<int>>mn;
    void addNum(int  num)
    {
        if(mx.empty() || mx.top()>num)
        {
            mx.push(num);
        }
        else
        {
            mn.push(num);
        }

        if(mx.size()>mn.size()+1)
        {
            mn.push(mx.top());
            mx.pop();
        }
        else if(mn.size()>mx.size()+1)
        {
            mx.push(mn.top());
            mn.pop();
        }
    }
public:
    Solution()
    {
        mx=priority_queue<int>();
        mn=priority_queue<int,vector<int>,greater<int>>();
    }
    double solve(int num)
    {
        addNum(num);
        if(mx.size()==mn.size())
        {
            double res=((double)mx.top()+(double)mn.top())/(double)2;
            return res;
        }
        else if(mx.size()>mn.size())
        {
            double res=(double)mx.top();
            return res;
        }
        else if(mn.size()>mx.size())
        {
            double res=(double)mn.top();
            return res;
        }
    }
};

int main()
{
    Solution obj;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        double ans=obj.solve(a);
        cout<<ans<<endl;
    }
    return 0;

}
// Time Complexity:O(nlogn)
// Space Complexity:O(n)