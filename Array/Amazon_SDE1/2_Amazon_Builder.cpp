#include<bits/stdc++.h>
using namespace std;

namespace Own
{
    class Solution
    {
    public:
        int solve(vector<int>&parts)
        {
            priority_queue<int,vector<int>,greater<int>>pq;
            for(auto it:parts)
            {
                pq.push(it);
            }
            int sum=0;
            while(pq.size()!=1)
            {
                int num1=pq.top();
                int num2;
                pq.pop();
                if(!pq.empty())
                {
                    num2=pq.top();
                    pq.pop();
                }
                pq.push(num1+num2);
                sum+=num1+num2;
            }
            return sum;
        }
    };
}

int combineParts(vector<int>parts)
{
    Own::Solution obj;
    int temp=obj.solve(parts);
    return temp;
}

int main()
{
    int n;
    cin>>n;
    vector<int>res;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        res.push_back(a);
    }
    cout<<combineParts(res)<<endl;
    // priority_queue<int,vector<int>,greater<int>>pq;
    // for(auto it:res)
    // {
    //     pq.push(it);
    // }
    // int sum=0;
    // while(pq.size()!=1)
    // {
    //     int num1=pq.top();
    //     int num2;
    //     pq.pop();
    //     if(!pq.empty())
    //     {
    //         num2=pq.top();
    //         pq.pop();
    //     }
    //     pq.push(num1+num2);
    //     sum+=num1+num2;
    // }
    // cout<<sum<<endl;
    return 0;

}