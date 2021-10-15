/*
Counting sort is a linear time sorting algorithm that sort in O(n+k) time when elements are in the 
range from 1 to k.

What if the elements are in the range from 1 to n2? 
We can’t use counting sort because counting sort will take O(n2) which is worse than 
comparison-based sorting algorithms. Can we sort such an array in linear time? 

Radix Sort is the answer. The idea of Radix Sort is to do digit by digit sort starting from 
least significant digit to most significant digit. Radix sort uses counting sort as a subroutine 
to sort.
*/


#include<bits/stdc++.h>
using namespace std;

void CountSort(vector<int>&res,int exp)
{
    int mx=*max_element(res.begin(),res.end());
    int mn=*min_element(res.begin(),res.end());

    int n=res.size();
    int range=mx-mn+1;
    vector<int>count(range),output(n);

    // Store count of occurrences in count[]
    for(int i=0;i<n;i++)
    {
        count[(res[i]/exp)%10]++;
    }

    
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for(int i=1;i<count.size();i++)
    {
        count[i]+=count[i-1];
    }



    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for(int i=n-1;i>=0;i--)
    {
        output[count[(res[i]/exp)%10]-1]=res[i];
        count[(res[i]/exp)%10]--;
    }


    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for(int i=0;i<n;i++)
    {
        res[i]=output[i];
    }
}

void RedixSort(vector<int>&res)
{
    // get max element from the array 
    int temp=*max_element(res.begin(),res.end());


    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for(int exp=1;temp/exp>0;exp*=10)
    {
        cout<<"Exp: "<<exp<<endl;
        CountSort(res,exp);
    }

    // Sorted array after redix sort
    for(auto it:res)
    {
        cout<<it<<" ";
    }
}

int main()
{
    vector<int>res={4,1,20,2,9,9,1};
    RedixSort(res);
    return 0;
}