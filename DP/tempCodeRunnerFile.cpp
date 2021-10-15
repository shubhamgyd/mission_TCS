// #include<bits/stdc++.h>
// using namespace std;

// void solve(int n,int m,vector<vector<int>>res,map<int,int>&mp)
// {
//     for(int i=0;i<n;i++)
//     {
//         int val=0;
//         for(int j=0;j<m;j++)
//         {
//             val+=res[i][j];
//         }
//         mp[val]++;
//     }

//     for(int i=0;i<n;i++)
//     {
//         int val=0;
//         for(int j=0;j<m;j++)
//         {
//             val+=res[j][i];
//         }
//         mp[val]++;
//     }
// }

// int main()
// {
//     int n,m;
//     cin>>n>>m;
//     vector<vector<int>>res(n,vector<int>(m));
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             cin>>res[i][j];
//         }
//     }
//     int q;
//     cin>>q;
//     int s;
//     cin>>s;
//     map<int,int>mp;
//     solve(n,m,res,mp);
//     vector<pair<int,int>>qer;
//     for(int i=0;i<q;i++)
//     {
//         int l,r;
//         cin>>l>>r;
//         qer.push_back({l,r});
//     }
//     for(int i=0;i<q;i++)
//     {
//         auto p=qer[i];
//         int l=p.first;
//         int r=p.second;
//         int sum=0;
//         for(int i=l;i<=r;i++)
//         {
//             if(mp.find(i)!=mp.end())
//             {
//                 sum+=mp[i];
//             }
//         }
//         cout<<sum<<" ";
//     }
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mmat = 11, mod = 1e9 + 7;

struct Mat
{
    int a[mmat][mmat];
    Mat(bool emp = 0)
    {
        memset(a, 0, sizeof a);
        if (emp)
            for (int i = 0; i < mmat; i++)
                a[i][i] = 1;
    }
    int *operator[](int i)
    {
        return a[i];
    }
    Mat operator+(Mat &b)
    {
        Mat ret;
        for (int i = 0; i < mmat; i++)
            for (int j = 0; j < mmat; j++)
                ret[i][j] = a[i][j] + b[i][j];
        return ret;
    }
    Mat operator*(Mat &b)
    {
        Mat ret;
        for (int k = 0; k < mmat; k++)
            for (int i = 0; i < mmat; i++)
                for (int j = 0; j < mmat; j++)
                    ret[i][j] = (ret[i][j] + (ll)a[i][k] * b[k][j]) % mod;
        return ret;
    }
};
Mat operator^(Mat a, ll b)
{
    Mat ret(1);
    for (; b; b >>= 1, a = a * a)
        if (b & 1)
            ret = ret * a;
    return ret;
}
int rev(int x)
{
    int ans = 1;
    for (int b = mod - 2; b; b >>= 1, x = (ll)x * x % mod)
        if (b & 1)
            ans = (ll)ans * x % mod;
    return ans;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    Mat trans;
    for (int i = 0; i < mmat; i++)
        for (int j = i + 1; j <= i + 6; j++)
            trans[i][j % mmat] = rev(6);

    ll n;
    cin >> n;
    Mat la = trans ^ n / 2, ra = trans ^ n - n / 2;
    int ans = 0;
    for (int i = 0; i < mmat; i++)
        ans = (ans + (ll)la[0][i] * ra[0][i]) % mod;
    cout << ans << '\n';
}