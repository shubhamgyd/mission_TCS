#include<bits/stdc++.h>
using namespace std;


struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};


class Solution 
{
    // bool myCmp(Job arr1,Job arr2)
    // {
    //     return arr1.profit>arr2.profit;
    // }
    public:
    static bool myCmp(Job arr1,Job arr2)
    {
        return arr1.profit>arr2.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code her
        sort(arr,arr+n,myCmp);
        bool done[n]={0};
        int day=0;
        int profit=0;
        for(int i=0;i<n;i++)
        {
            for(int j=min(n,arr[i].dead-1);j>=0;j--)
            {
                if(done[j]==false)
                {
                    day+=1;
                    profit+=arr[i].profit;
                    done[j]=true;
                    break;
                }
            }
        }
        vector<int>v;
        v.push_back(day);
        v.push_back(profit);
        return v;
    } 
};