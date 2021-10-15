// Count the subsets with given difference
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
    for(int i=0;i<=n;i++)    // Initialise all elements as a 1 in first element of each row (number of elements)
    {
        tab[i][0]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            //arr[i-1]!=0&&
            if(arr[i-1]<=j)
              tab[i][j]=tab[i-1][j-arr[i-1]]+tab[i-1][j];
          else
              tab[i][j]=tab[i-1][j];
        }
    }
    return tab[n][sum];


}

int main()
{
    //int n=5;
    int arr[] = { 1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int diff=2;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    int s1=(diff+sum)/2;
    //cout<<s1<<endl;
    if(s1%2!=0)
    {
        cout<<"There are 0 subsets with have given diff"<<'\n';
    }
    else
    {
    cout<<"Number of subsets of given sum is : "<<(CountSumSubArray(arr,s1,n))<<endl;
    }
    //cout<<"Number of subsets of given sum is : "<<(CountSumSubArray(arr,s1,n))<<endl;
    return 0;

}