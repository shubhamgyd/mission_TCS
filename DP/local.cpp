#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<2*n;i++)
    {
        cin>>arr[i];
    }
    int ct=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                int n1=arr[i],n2=arr[j],n3=arr[k];
                if(abs(n1-n2)+abs(n2-n3)==abs(n1-n3))
                {
                    ct++;
                }
            }
        }
    }
    cout<<ct<<endl;
    return 0;
}