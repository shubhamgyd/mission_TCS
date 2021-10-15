#include<bits/stdc++.h>
using namespace std;


int Partition(int *arr,int start,int end)
{
    // { below method is very useful to avoid the worst case in quick sort , it will generate random 
    //      number between start and end so instead of end number it will take any number between range.
    // random_device rd; // obtain a random number from hardware
    // mt19937 gen(rd()); // seed the generator
    // uniform_int_distribution<> distr(start, end+1); // define the range
    // int n=distr(gen); }
    //cout<<n<<endl;
    int pivot=arr[end];
    int partitionIndex=start;    //setting partition index as starting initially
    for(int i=start;i<end;i++)
    {
        if(arr[i]<=pivot)
        {
            swap(arr[i],arr[partitionIndex]);  //swap if element is lesser than pivot
            partitionIndex++;
        }
    }
    swap(arr[partitionIndex],arr[end]); //swapping pivot with element at partition index
    return partitionIndex;
}


void QuickSort(int *arr,int start,int end)
{
    if(start<end)
    {
        int pIndex=Partition(arr,start,end); //calling for partition function to make the partiton
        QuickSort(arr,start,pIndex-1);       // Recursive call to sort left side of pivot
        QuickSort(arr,pIndex+1,end);         // Recursive call to sort right side of the pivot
    }
}

int main()
{
    //int arr[]={2,3,1,7,4,9,8,6,5};
    int x;
    cout<<" Enter number of elements want to array:";
    cin>>x;
    int arr[x];
    for(int i=0;i<x;i++)       //adding element in array
    {
        cin>>arr[i];
    }
    int n=sizeof(arr)/sizeof(arr[0]);       //size of array
    QuickSort(arr,0,n-1);
    cout<<"Sorted array by using Quick Sort: ";   //Printing the sorted array
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}