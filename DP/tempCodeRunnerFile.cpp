// #include<iostream>
// using namespace std;

// void swap_three(int*, int*,int*);

// int main()
// {

//     // write your code here

//     cout<<"Enter three numbers: "<<endl;
//     // three numbers input taken by the user
//     int p1,p2,p3;
//     cout<<"var1: ";
//     cin>>p1;
//     cout<<"var2: ";
//     cin>>p2;
//     cout<<"var3: ";
//     cin>>p3;

//     // Number before swapping
//     cout<<"\nNumbers before swapping: "<<endl;
//     cout<<"var1: "<<p1<<", var2:"<<p2<<", var3:"<<p3<<endl;

    

//     // Utility function , which will swaps three numbers
//     // Here we are passing the numbers by reference
//     // means we are passing the memory addresses of values
//     swap_three(&p1,&p2,&p3);
    
//     // Numbers after swapping
//     cout<<"\nNumbers after swapping: "<<endl;
//     cout<<"var1: "<<p1<<", var2:"<<p2<<", var3:"<<p3<<endl;
// }


// // Utility function which swaps the numbes
// // This function takes the parameters in the memory referece
// void swap_three(int* p1,int* p2,int *p3)
// {
//     // write your code here

//     // here we are swapping the first and second number
//     int temp=*p2;
//     *p2=*p1;
//     *p1=temp;


//     // Here we are swapping the first and third number
//     temp=*p1;
//     *p1=*p3;
//     *p3=temp;
// }


#include <bits/stdc++.h>
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long
using namespace std;
#define endl '\n'
const int mod=1e9+7;


void DFS(int src,vector<int>adj[],vector<bool>&visited,int &ct,int &danger)
{
    if(visited[src]) return;
    visited[src]=true;
    ct+=1;
    if(ct>1)
    {
        danger*=2;
    }
    for(auto it:adj[src])
    {
        DFS(it,adj,visited,ct,danger);
    }
}

void solve()
{
    int n;
    cin>>n;
    int low=1;
    int high=1e9;
    int ans=-1;
    while(low<high)
    {
        int mid=low+(high-low)/2;
        int sum=(mid*mid);
        int temp=mid;
        int numSum=0;
        while(temp>0)
        {
            numSum+=temp%10;
            temp/=10;
        }
        sum+=numSum;
        if(sum>=n)
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid;
        }
    }
    cout<<ans<<endl;

}


signed main()
{
// #ifndef ONLINE_JUDGE
//         freopen("inputf.in", "r", stdin);
//         freopen("outputf.out", "w", stdout);
// #endif
    fast();
    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     solve();
    // }
    solve();
    return 0;
}