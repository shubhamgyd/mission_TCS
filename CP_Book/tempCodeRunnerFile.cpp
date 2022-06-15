#include<bits/stdc++.h>
using namespace std;

bool isSorted(int a[], int n) 
{ 
    while ( --n > 1 ) 
        if (a[n] < a[n-1]) 
            return false; 
    return true; 
} 
  

void shuffle(int a[], int n) 
{ 
    for (int i=0; i < n; i++) 
        swap(a[i], a[rand()%n]); 
} 

int bogosort(int a[], int n) 
{ 

    int ct=0;
    while ( !isSorted(a, n) ) 
    {
        ++ct;
        shuffle(a, n); 
    }
    return ct;
} 
int maxOperations(int *list,int n)
{
    return bogosort(list,n);
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
    int ans=maxOperations(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<ans<<endl;
}


// int main()
// {
//     string parent;
//     string sub;
//     cin>>parent>>sub;
//     transform(parent.begin(),parent.end(),parent.begin(),::tolower);
//     transform(sub.begin(),sub.end(),sub.begin(),::tolower);
//     int count=0;
//     int n=parent.length();
//     int m=sub.length();
//     for(int i=0;i<n-m;i++)
//     {
//         string str=parent.substr(i,m);
//         if(str==sub)
//         {
//             count++;
//         }
//     }
//     cout<<count<<endl;
//     return 0;

// }