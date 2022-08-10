// #include<bits/stdc++.h>
// using namespace std;


// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cout.tie(0);
//     cout.tie(0);
//     int n;
//     cin>>n;
//     vector<int>nums(n);
//     for(int i=0;i<n;++i)
//     {
//         cin>>nums[i];
//     }
//     int cnt=0;
//     while(true)
//     {
//         int zr= 0;
//         int i; 
//         for (i=0; i<n; i++)
//         {
//             if (nums[i] & 1) break;
//             else if (nums[i] == 0) zr++;
//         }
//         if (zr== n)
//         {
//             cout<<cnt<<endl;
//             return 0;
//         }
//         if (i==n)
//         {
//             for (int j=0; j<n; j++) nums[j] = nums[j]/2;
//             cnt++;
//         }
//         for (int j=i; j<n; j++)
//         {
//            if (nums[j] & 1)
//            {
//               nums[j]--;
//               cnt++;
//            }
//         }
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int sum;
    cin>>sum;
    do
    {
        int ans=0;
        while(sum!=0)
        {
            ans+=sum%10;
            sum/=10;
        }
        sum=ans;
    }while(sum>10);
    cout<<sum<<endl;
}