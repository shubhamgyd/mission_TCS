// In this problem we are going to find the maximum sum in matrix 
// condition is we can go to the row+1,col [row+1,col-1] , [row+1,col+1]

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++


// Simply dfs of grpah
class Solution{
    int solve(vector<vector<int>> &Matrix ,int n,int row,int col,vector<vector<int>>&mat)
    {
        if(row>=n || row<0 || col>=n || col<0)
        {
            return 0;
        }
        if(mat[row][col]!=-1)
        {
            return mat[row][col];
        }
        int s1=solve(Matrix,n,row+1,col,mat);
        int s2=solve(Matrix,n,row+1,col-1,mat);
        int s3=solve(Matrix,n,row+1,col+1,mat);
        mat[row][col]=Matrix[row][col]+max(s1,max(s2,s3));
        return mat[row][col];
    }
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int ans=-1;
        vector<vector<int>>mat(501,vector<int>(501,-1));
        for(int i=0;i<N;i++)
        {
            ans=max(ans,solve(Matrix,N,0,i,mat));
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends