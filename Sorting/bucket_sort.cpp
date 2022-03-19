/*
Bucket sort is mainly useful when input is uniformly distributed over a range.
For example, consider the following problem. 
*/

#include<bits/stdc++.h>
using namespace std;

void BucketSort(vector<float>&res)
{
    int n=res.size();

    // Create empty bucket
    vector<float>bucket[n];

    // 2) Put array elements
    // in different buckets
    for(int i=0;i<n;i++)
    {
        int temp=n*res[i];
        bucket[temp].push_back(res[i]);
    }


    // 3) sort every bucket
    for(auto it:bucket)
    {
        sort(it.begin(),it.end());
    }


    // 4) push all bucket to the original array by sorting manner
    int ind=0;
    for(auto it:bucket)
    {
        for(auto ele:it)
        {
            res[ind++]=ele;
        }
    }


    cout<<"Array after bucket sort: "<<endl;
    for(auto it:res)
    {
        cout<<it<<" ";
    }

}

int main()
{
    vector<float>res={0.897, 0.565, 0.656, 0.1234, 0.565, 0.3434,0.565};
    BucketSort(res);
    return 0;
}