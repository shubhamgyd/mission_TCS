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
            // if sum less than j hai to add kernge hi ,,kya pta aage ja kr uska sathi mil jaye
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
    int n=1;
    int arr[] = {0};
    int sum=-1;
    //sort(arr,arr+n);
    cout<<"Number of subsets of given sum is : "<<(CountSumSubArray(arr,sum,n))<<endl;
    return 0;

}