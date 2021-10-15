#include<bits/stdc++.h>
using namespace std;


// Basically we are doing dfs int this problem


class Solution 
{
    bool safe(int n,int m,int i,int j)
    {
        return (i>=0 && i<n && j>=0 && j<m);
    }
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>&grid)
	{
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>>res(n,vector<int>(m,INT_MAX));
	    queue<pair<int,int>>pq;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	               if(grid[i][j]==1)
	               {
	                   pq.push({i,j});
	                   res[i][j]=0;
	               }
	        }
	    }
	    //vector<vector<int>>mves={{0,1},{1,0},{0,-1}
	    while(!pq.empty())
	    {
	        int i=pq.front().first;
	        int j=pq.front().second;
	        pq.pop();
	        if(safe(n,m,i,j+1)==true)
	        {
	            if(res[i][j+1]>res[i][j]+1)
	            {
	                res[i][j+1]=res[i][j]+1;
	                pq.push({i,j+1});
	            }
	        }
	        if(safe(n,m,i+1,j)==true)
	        {
	            if(res[i+1][j]>res[i][j]+1)
	            {
	                res[i+1][j]=res[i][j]+1;
	                pq.push({i+1,j});
	            }
	        }
	        if(safe(n,m,i-1,j)==true)
	        {
	            if(res[i-1][j]>res[i][j]+1)
	            {
	                res[i-1][j]=res[i][j]+1;
	                pq.push({i-1,j});
	            }
	        }
	        if(safe(n,m,i,j-1)==true)
	        {
	            if(res[i][j-1]>res[i][j]+1)
	            {
	                res[i][j-1]=res[i][j]+1;
	                pq.push({i,j-1});
	            }
	        }
	    }
	    return res;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends