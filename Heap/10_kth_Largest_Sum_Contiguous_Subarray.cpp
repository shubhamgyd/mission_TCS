#include<bits/stdc++.h>
using namespace std;

int MaxSum(int arr[],int n,int k)
{
    int preSum[n+1];
    preSum[0]=0;
    preSum[1]=arr[0];
    // PreSum
    for(int i=2;i<=n;i++)
    {
        preSum[i]=preSum[i-1]+arr[i-1];
    }

    // To get the large element from the top of the queue
    priority_queue<int,vector<int>,greater<int>>pq;
    
    // For starting index to
    for(int i=1;i<=n;i++)
    {
        // Every possible contiguous subarray
        for(int j=i;j<=n;j++)
        {
            // Sum of contiguous subarray
            int sum=preSum[j]-preSum[i-1];
            pq.push(sum);
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
    }
    return pq.top();
}
/*
Time Complexity :O(n^2logk)
Space Complexity: O(k)
*/
int main()
{
    int arr[] = { 10, -10, 20, -40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 6;
    cout<<"k'th largest sum of contiguous subarray is: "<<MaxSum(arr,n,k)<<endl;
    return 0;
}