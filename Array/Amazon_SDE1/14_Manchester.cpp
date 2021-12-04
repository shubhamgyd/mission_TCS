#include<bits/stdc++.h>
using namespace std;

int* manchester(int *arr,int len)
{
   int* res=(int*)malloc(sizeof(int)*len);
   res[0]=arr[0]==0?0:1;
   for(int i=1;i<len;i++)
   {
       res[i]=arr[i]==arr[i-1]?0:1;
   }
   return res;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int* ans=manchester(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}