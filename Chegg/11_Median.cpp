#include<bits/stdc++.h>
using namespace std;

// Utility function which return the median of the array
double list_median(vector<int>&arr)
{
    // for finding median we need sorted elements
    // sort the array of elements
    sort(arr.begin(),arr.end());
    int n=arr.size();                         // size of the array

    // if size of array is odd , then media is the middle element
    if(n%2==1)
    {
        return (double)arr[n/2];              // type cast from int to double and retrurn it
    }

    // if size of array is even
    else
    {
        // first middle
        double middle1=(double)arr[n/2];   

        // second middle      
        double middle2=(double)arr[n/2-1];      

        // mean of middle1 and middle2, which is the median of the array 
        double median=(middle1+middle2)/(2.0);   

        // return the median 
        return median;
    }
}

int main()
{
    cout<<"Enter number of elements: ";
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    double median=list_median(arr);
    cout<<"Median of array is: ";
    cout<<median<<endl;
    return 0;

}

/*
Time Complexity(worst case):O(nlogn)
where n is the length of array. Because if array is not aorted then we need to sort it,
it takes nlogn time to sort the elements.

Space Compexity:O(1)

*/