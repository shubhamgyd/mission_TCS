#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[]={1,2,3,4,5,6,7,8,8,8,9};
    int x=8;
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=0;
    //The search goes through the array from left to right, and the initial jump
    //length is n/2. At each step, the jump length will be halved: first n/4, then n/8,
    //n/16, etc., until finally the length is 1. After the jumps, either the target element
    //has been found or we know that it does not appear in the array.
    for(int b=n/2;b>=1;b/=2)
    {
        while(k+b<n && arr[k+b]<=x)
        {
            k+=b;
        }
    }
    if(arr[k]==x) cout<<"Element Found at index: "<<k<<endl;
    else cout<<"Not Found..!!"<<endl;
    //During the search, the variable b contains the current jump length. The
    //time complexity of the algorithm is O(logn), because the code in the while loop is
    //performed at most twice for each jump length.


    //Alternative way to check element is present or not
    auto j=lower_bound(arr,arr+n,x)-arr;
    if(j<n && arr[j]==x)
    {
        cout<<"Element Found at index: "<<j<<endl;
    }
    for(int i=j;i<=10;i++)
    {
        if(arr[i]==arr[i+1])
        {
            j++;
        }
        else
        {
            break;
        }
    }
    cout<<"Last position of given element is: "<<j<<'\n';

    //Alternative way to count the element 
    auto a = lower_bound(arr, arr+n, x);
    auto b = upper_bound(arr, arr+n, x);
    cout <<"Count of "<<x<<" is : "<< b-a << "\n";


    vector<int>v={5,7,7,8,8,10};
    auto pos1=lower_bound(v.begin(),v.end(),8);
    auto pos2=upper_bound(v.begin(),v.end(),2);
    cout<<*pos1;
    if(*pos1<=*pos2)
    {
        cout<<"First and last postition :";
        cout<<*pos1-1<<" "<<*pos2<<'\n';
    }
    else
    {
        cout<<" Element Not Found: ";
        cout<<-1<<" "<<-1<<'\n';
    }



    // int pos2=*pos1;
    // for(int i=*pos1;i<=v.size()-1;i++)
    // {
    //     if(v[i]==v[i+1])
    //     {
    //         pos2++;
    //     }
    //     else
    //     {
    //         break;
    //     }
    // }
    // if(pos1<=pos2)
    // {
    //     cout<<"First and last postition :";
    //     cout<<*pos1-1<<" "<<pos2<<'\n';
    // }
    // else
    // {
    //     cout<<" Element Not Found: ";
    //     cout<<-1<<" "<<-1<<'\n';
    // }
    //cout<<*pos1<<'\n';
    // vector<int>:: iterator pos1,pos2;
    // pos1=lower_bound(v.begin(),v.end(),8);
    // //pos2=upper_bound(v.begin(),v.end(),8);
    // if(pos1-v.begin() < pos2-v.begin())
    // {
    //     cout<<pos1-v.begin()<<" "<<pos2-v.begin()-1<<'\n';
    // }
    // else
    // {
    //     cout<<-1<<" "<<-1<<'\n';
    // }

    return 0;


}