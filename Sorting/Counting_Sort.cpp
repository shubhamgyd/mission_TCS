/*
Counting sort is a sorting technique based on keys between a specific range. 
It works by counting the number of objects having distinct key values (kind of hashing). 
Then doing some arithmetic to calculate the position of each object in the output sequence.
*/

#include<bits/stdc++.h>
using namespace std;

void CountingSort(vector<int>res)
{
    int mx=*max_element(res.begin(),res.end());
    int mn=*min_element(res.begin(),res.end());

    int n=res.size();
    int range=mx-mn+1;
    vector<int>count(range),output(n);

    // Count the freauency  of each element
    for(int i=0;i<n;i++)
    {
        count[res[i]-mn]++;
    }

    // Store count of occurrences in count[]
    for(int i=1;i<count.size();i++)
    {
        count[i]+=count[i-1];
    }

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for(int i=n-1;i>=0;i--)
    {
        output[count[res[i]-mn]-1]=res[i];
        count[res[i]-mn]--;
    }


    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for(int i=0;i<n;i++)
    {
        res[i]=output[i];
    }


    
    for(auto it:res)
    {
        cout<<it<<" ";
    }
}

/*
Time Complexity:O(n+k)
Space Complexity:O(n+k)
*/



// Stable Sort Algorithm
int main()
{
    vector<int>res={1,5,-1,4,2,10,-9};
    CountingSort(res);
    return 0;
}