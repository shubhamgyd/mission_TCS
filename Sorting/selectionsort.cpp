#include<bits/stdc++.h>
using namespace std;

// It will find the smallest element from the array and then sort it with the current element
void SelectionSort(vector<int>&v,int n,int& swaps)
{
    for(int i=0;i<n-1;i++)
    {
        int iMin=i;
        for(int j=i+1;j<n;j++)
        {
            if(v[j]<v[iMin])
            {
                iMin=j;
            }
        }
        swaps++;
        int temp=v[i];
        v[i]=v[iMin];
        v[iMin]=temp;
    }
}

int* sele(int *array,int len)
{
    int x=0,y=0;
    for(x=0;x<len-1;x++)
    {
        int index_of_min=x;
        for(y=x+1;y<len;y++)
        {
            if(array[index_of_min]>array[y])
            {
                index_of_min=y;
            }
        }
        int temp=array[x];
        array[x]=array[index_of_min];
        array[index_of_min]=temp;
    }
    
    return array;
}


int main()
{
    int arr[5]={5,4,3,2,1};
    sele(arr,5);
    vector<int>v;
    int n;
    cout<<" Enter a number: ";
    cin>>n;
    while(n--)
    {
        int a;cin>>a;
        v.push_back(a);
    }
    int swaps=0;
    SelectionSort(v,v.size(),swaps);
    cout<<"Sorted array by Selection Sort:";
    for(auto ele:v)
    {
        cout<<ele<<" ";
    }
    cout<<"\nNumber of swaps required: "<<swaps<<endl;
    return 0;
}