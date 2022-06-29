#include<bits/stdc++.h>
using namespace std;

int CountSumSubArray(int arr[],int sum,int n)
{
    int tab[n+1][sum+1];  // Initilization of array
    tab[0][0]=1;   //Initialization first value of matrix
    for(int i=1;i<=sum;i++)  // Initialise all elements as a 0 in first position of each column ( sum column)
    {
        tab[0][i]=0;
    }
    for(int i=1;i<=n;i++)    // Initialise all elements as a 1 in first element of each row (number of elements)
    {
        tab[i][0]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1]!=0&&arr[i-1]<=j)
              tab[i][j]=tab[i-1][j-arr[i-1]]+tab[i-1][j];
          else
              tab[i][j]=tab[i-1][j];
        }
    }
    return tab[n][sum];


}

int CountSubWithDiff(int arr[],int n , int diff)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    int sum1=(diff+sum)/2;
    return CountSumSubArray(arr,sum1,n);


}

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("inputf.in", "r", stdin);
//     freopen("outputf.out", "w", stdout);
// #endif
    int arr[] ={8,2,2,4,5,6,3};
    int diff=9;
    int n=sizeof(arr)/sizeof(arr[0]);
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            c++;
        }
    }
    //int c = count(arr.begin(),arr.end(),0);
    cout<<" Number of subsets with given difference : "<<pow(2,c)*CountSubWithDiff(arr,n,diff)<<endl;
    return 0;
}