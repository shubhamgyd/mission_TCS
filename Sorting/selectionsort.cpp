#include<bits/stdc++.h>
using namespace std;

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


int main()
{
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