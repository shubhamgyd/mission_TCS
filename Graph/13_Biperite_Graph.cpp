/*
This problem is similar to : 
Two Clique Problem (Check if Graph can be divided in two Cliques)
*/

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    bool dfs(vector<int>&color, int node, vector<int>adj[]) {
        if (color[node] == -1)
        color[node] = 1;
        
        for (auto nbr : adj[node]) {
            if (color[nbr] == -1) {
                color[nbr] = 1 - color[node];
            if (!dfs(color, nbr, adj))
                return false;
            }
            else if (color[nbr] == color[node] )
                return false;
        }
        return true;
}
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>color(V,-1);
	    for(int i=0;i<V;i++)
	    {
	        if(!dfs(color,i,adj))
	        {
	            return false;
	        }
	    }
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends