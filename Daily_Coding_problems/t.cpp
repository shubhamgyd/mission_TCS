// #include<bits/stdc++.h>
// using namespace std;

// int solve(int a,int d,int N)
// {
//     return (a + (N - 1) * d);
// }

// int main()
// {
//     int a,d,n;
//     cin>>a>>d>>n;
//     int ans=solve(a,d,n);
//     cout<<ans<<endl;
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;

// int MinMaxTwoArrays(int arr1[],int arr2[],int n,int m,int k)
// {
//     int x=0;
//     int y=0;
//     for(int i=0;i<n;i++)
//     {
//         if(arr1[i]>k) x++;
//     }
//     for(int i=0;i<m;i++)
//     {
//         if(arr2[i]<k) y++;
//     }
//     return max(x,y);
// }

// int main()
// {
//     int n;
//     cin>>n;
//     int arr1[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>arr1[i];
//     }
//     int m;
//     cin>>m;
//     int arr2[m];
//     for(int i=0;i<m;i++)
//     {
//         cin>>arr2[i];
//     }
//     int k;
//     cin>>k;
//     int ans=MinMaxTwoArrays(arr1,arr2,n,m,k);
//     cout<<ans<<endl;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int solve(int a,int b,int c)
{
    vector<int>arr;
    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);
    sort(arr.rbegin(),arr.rend());
    int num=0;
    num=100*arr[0]+10*arr[1]+arr[2];
    return num;
}

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int ans=solve(a,b,c);
    cout<<ans<<endl;
    return 0;
}