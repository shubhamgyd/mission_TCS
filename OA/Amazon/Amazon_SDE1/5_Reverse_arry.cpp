#include<bits/stdc++.h>
using namespace std;

void Reverse(int *arr,int num)
{
    int i=0;
    int j=num-1;
    while(i<j)
    {
        swap(arr[i++],arr[j--]);
    }
}

int main()
{
    int num;
    cin>>num;
    int arr[num];
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
    Reverse(arr,num);
    for(int i=0;i<num;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}