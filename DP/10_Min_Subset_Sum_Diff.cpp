// #include<bits/stdc++.h>
// using namespace std;

// int MinSub(int arr[] ,int n)
// {
//     int sum=0;
//     for(int i=0;i<n;i++)
//     {
//         sum+=arr[i];    //Calculate the sum of all element
//     }
//     bool dp[n+1][sum+1]; // Declaration of array to store the element
//     // Initialize first column as true. 0 sum is possible
//     // with all elements.
//     for(int i=1;i<=n;i++)
//     {
//         dp[i][0]=true;
//     }
//     // Initialize top row, except dp[0][0], as false. With
//     // 0 elements, no other sum except 0 is possible
//     for(int i=1;i<=sum;i++)
//     {
//         dp[0][i]=false;
//     }
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=sum;j++)
//         {
//             dp[i][j]=dp[i-1][j];
//             if(arr[i-1]<=j)
//             {
//                 dp[i][j]|=dp[i-1][j-arr[i-1]];
//             }
//         }
//     }
//     int mn=INT_MAX;
//     // Find the largest j such that dp[n][j]
//     // is true where j loops from sum/2 to 0
//     for(int i=sum/2;i>=0;i--)
//     {
//         if(dp[n][i]==true)
//         {
//             mn=sum-2*i;
//             break;
//         }
//     }
//     return mn;
// }

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     //int n=3;
//     int arr[] = {4,1,2,3,5};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     //int range=10;
//     cout<<" Minimum subset sum difference: "<<MinSub(arr,n)<<endl;
//     return 0;
// }

















// Variation of partition subset sum problem
// Check Wheather given  sum is present in array or not
#include<bits/stdc++.h>
using namespace std;

//int dp[100][100];

bool subsetsum(int arr[],int n, int sum)
{
    int total=sum;
    //Declaration of array
    int dp[n+1][sum+1];

    //Initialization of array 
    //dp[0][0]=true;
    //first col =true
    //first row = false;
    // Think about it.
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=true;
    }

    for(int i=1;i<=sum;i++)
    {
        dp[0][i]=false;
    }


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            // If element if less than or equal to given sum , then we have two choices
            // Either taken or not taken
            if(arr[i-1]<=j)
            {
                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            // If element is greater than given sum ,  then take the value from the previos 
            // upper array block
            // Discard it , store the previous valid flag
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    // Final ans will get by using this block 
    // Either true or false
    int range=total/2;
    vector<int>v;
    int mn=INT_MAX;
    for(int i=0;i<=range;i++)
    {
        if(dp[n][i])
        {
            mn=min(mn,total-2*i);
        }
    }
    //return dp[n][sum];
    cout<<mn<<endl;
    return mn;
}


bitset<1000001>can;

int main()
{
    int arr[]={4,1,3,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    //int sum=9;
    int finalS=0;
    for(int i=0;i<n;i++)
    {
        finalS+=arr[i];
    }
    subsetsum(arr,n,finalS);
    // if(subsetsum(arr,n,finalS)==true)
    // {
    //     cout<<"Yes Sum Present"<<'\n';
    // }
    // else
    // {
    //     cout<<"Given Sum Not Ptesent"<<'\n';
    // }


    // cout<<endl;
    // cout<<"Altrnative approach and faster than DP : ";
    // // Time complexity of the given function is O(sum/32)
    // can[0]=true;
    // for(int id=0;id<n;id++)
    // {
    //     can|=(can<<arr[id]);
    // }
    // puts(can[sum]?"YES":"NO");
    return 0;

}
