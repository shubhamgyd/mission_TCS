#include<bits/stdc++.h>
#define int long long
using namespace std;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>nums(n);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>nums[i];
            if(i>0)
            {
                sum+=nums[i]+sum-1;
            }
            else
            {
                sum+=nums[i];
            }
        }
        cout<<sum<<endl;
    }
    return 0;

}


// #include<bits/stdc++.h>
// #define int long long
// using namespace std;


// signed main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int n;
//         cin>>n;
//         vector<int>nums(n);
//         int sum=0;
//         for(int i=0;i<n;i++)
//         {
//             cin>>nums[i];
//             sum+=nums[i];
//         }
//         cout<<sum<<endl;
//     }
//     return 0;

// }