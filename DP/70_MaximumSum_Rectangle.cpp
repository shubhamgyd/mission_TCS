#include<bits/stdc++.h>
using namespace std;


// Kadane algorithm to find the maximum sum in a 1D array
int kadane(int n,vector<int>v)
{
    int sum=0;
    int base=INT_MIN;
    for(int i=0;i<n;i++)
    {
        sum+=v[i];
        if(sum>base) base=sum;
        if(sum<0) sum=0;
        //base=max(base,sum);
    }
    return base;

}


/*
The intuition behind this que is , we have to traverse row wise.
After that we store the elements of this row in a single 1D array and 
for every time we are finding the maxumum sum in this subarray by using the kadane's algorithm
for every row , find the maximum sum traversing the belows row's 
*/
int main()
{
    int row,col;
    cin>>row>>col;
    vector<vector<int>>arr(row,vector<int>(col));
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>arr[i][j];
        }
    }

    // Store the final result
    int mx=INT_MIN;
    for(int i=0;i<row;i++)
    {
        vector<int>v(col);
        for(int j=i;j<row;j++)
        {
            for(int k=0;k<col;k++)
            {
                v[k]+=arr[j][k];
            }
            mx=max(mx,kadane(col,v));
        }
    }
    cout<<mx<<endl;
}

/* 
Time complexity: O(R*R*C)
Space Compl: O(R*C)
*/