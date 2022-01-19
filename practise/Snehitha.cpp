#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

// bool Prime(int n)
// {
//     bool isPrime=true;
//     int i;
//     if (n == 0 || n == 1) {
//         isPrime = false;
//     }
//     else {
//         for (i = 2; i <= n / 2; ++i) {
//             if (n % i == 0) {
//                 isPrime = false;
//                 break;
//             }
//         }
//     }
//     if (isPrime)
//         return true;
//     return false;
// }

// bool cmp(pair<int,int>&a,pair<int,int>&b)
// {
//     if(a.first==b.first)
//     {
//         return b.second<a.second;
//     }
//     return a.first<b.first;
// }
// int nearestNum(int n)
// {
//     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
//     vector<pair<int,int>>res;
//     int ct=0;
//     int flag=0;
//     for(int i=n;i>=1;i--)
//     {
//         if(Prime(i))
//         {
//             ct++;
//             int diff=abs(n-i);
//             // pq.push({diff,i});
//             res.push_back({diff,i});
//             if(ct==5)
//             {
//                 flag=1;
//                 break;
//             }
//         }
//         if(flag)
//         {
//             break;
//         }
//     }
//     ct=0;
//     flag=0;
//     for(int i=n+1;i<=200000;i++)
//     {
//         if(Prime(i))
//         {
//             ct++;
//             int diff=abs(n-i);
//             // pq.push({diff,i});
//             res.push_back({diff,i});
//             if(ct==5)
//             {
//                 flag=1;
//                 break;
//             }
//         }
//         if(flag)
//         {
//             break;
//         }
//     }
//     sort(res.begin(),res.end(),cmp);
//     res.resize(5);
//     int val=res[4].second;
//     return val;

// }



static int CountTriplets(long long int a, long long  int b, long long int c)
{
    const int mod=1000000007;
    if (b < a)
        swap(a, b);
    if (c < b)
    {
        swap(c, b);
        if (b < a)
            swap(b, a);
    }
    a %= mod;
    b = (b - 1) % mod;
    c = (c - 2) % mod;
    long long int  res = (a * b);
    res %= mod;
    res *= c;
    res %= mod;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long int a,b,c;
    cin >>a>>b>>c;
    cout << CountTriplets(a,b,c)<< endl;
    return 0;
}