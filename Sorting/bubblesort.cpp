#include<bits/stdc++.h>
using namespace std;

void BubbleSort(vector<int>&v,int n,int& sw)
{
    int itr=0;
    for(int i=0;i<n-1;i++)  // Outer  loop run till n-1 , coz we are comparing next adjacent element
    {
        itr++;
        int flag=0;  // FOR  array already sorted
        for(int j=0;j<n-i-1;j++) // inner loop run till unsorted element , 
                                 //it means  onward at particular position elements are sorted then no need to sort them
        {
            if(v[j]>v[j+1])
            {
                swap(v[j],v[j+1]);
                sw++;
                flag=1;
            }
        }
        if(flag==0) //shows no need to sort any more
        {
            break;
        }
    }
    cout<<itr<<endl;
}

int main()
{
// #ifndef ONLINE_JUDGE
//         freopen("inputf.in", "r", stdin);
//         freopen("outputf.out", "w", stdout);
// #endif
    vector<int>v;
    int n;
    cout<<" Enter a number: ";
    cin>>n;
    while(n--)
    {
        int a;cin>>a;
        v.push_back(a);
    }
    int sw=0;
    BubbleSort(v,v.size(),sw);
    cout<<"Sorted array by Bubble sort:";
    for(auto &ele:v)
    {
        cout<<ele<<" ";
    }
    cout<<endl;
    cout<<"Number of swaps required: "<<sw<<endl;
    return 0;
}