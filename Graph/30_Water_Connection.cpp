#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    int dfs(int src,vector<pair<int,int>>adj[],vector<bool>&visited,int &mn)
    {
        visited[src]=true;
        for(int i=0;i<adj[src].size();i++)
        {
            int v=adj[src][i].first;
            int w=adj[src][i].second;
            if(w<mn)
            {
                mn=w;
            }
            if(!visited[v])
            {
                return dfs(v,adj,visited,mn);
            }
        }
        if(adj[src].size()==0)
        {
            return src;
        }
    }
    public:
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        vector<vector<int>>res;
        vector<int>incoming(n+1,0);
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<p;i++)
        {
            adj[a[i]].push_back({b[i],d[i]});
            incoming[b[i]]++;
        }
        
        for(int i=1;i<=n;i++)
        {
            if(incoming[i]==0)
            {
                vector<int>ans;
                int mn=INT_MAX;
                vector<bool>visited(n+1,false);
                int vertex=dfs(i,adj,visited,mn);
                ans.push_back(i);
                ans.push_back(vertex);
                ans.push_back(mn);
                if(i!=vertex)
                    res.push_back(ans);
            }
        }
        return res;
    }
};


// { Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}  // } Driver Code Ends