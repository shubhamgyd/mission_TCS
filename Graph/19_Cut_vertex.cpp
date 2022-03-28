// In this program we are going to find the cut-vertex point so that graph becomes disconnected

// #include<bits/stdc++.h>
// using namespace std;
// #define endl '\n'
// const int mxsize=1e6+6;


// int parent[mxsize];
// int child[mxsize];
// int tym[mxsize];
// int low[mxsize];
// bool seen[mxsize];
// bool is_cut[mxsize];

// //vector<vector<int>>vertex;
// void dfs(int src,vector<vector<int>>&graph)
// {
//     /* static variable gets declared only  
//     once till the program runs */
//     static int time=0;
//     seen[src]=true;          // mark the source as visited

//     low[src]=tym[src]=time++;            // irst assigns and then increment time.

//     for(int i=0;i<graph[src].size();i++)
//     {
//         int it=graph[src][i];
//         if(it==parent[src])
//         {
//             continue;                    //do nothing if adjacent  is its parent
//         }
//         if(!seen[it])
//         {
//             child[src]++;                  // one more independent child of source
//             parent[it]=src;               // make the parent src for  adjacent  element
//             dfs(it,graph);


//             /*
//             if the low time of oldest ancestor reachable from the both , then  
//             */
//            low[src]=min(low[src],low[it]);
//            /* if it has greater or equal  
//             low time than visited time of src then if we cut src then 
//             curr will get disconnected from the graph*/
//             if(low[it]>=tym[src])
//             {
//                 is_cut[src]=true;
//             }
            
//         }
//         else
//         {
//             low[src]=min(low[src],tym[it]);
//         }

//     }
// }


// int main()
// {
//     int n,m;
//     cin>>n>>m;
//     vector<vector<int>>graph(n+1,vector<int>(m+1));
//     for(int i=0;i<m;i++)
//     {
//         int u,v;
//         cin>>u>>v;
//         graph[u].push_back(v);
//         graph[v].push_back(u);
//     }
//     parent[1]=-1;
//     dfs(0,graph);

//     /* the vertex from where we started dfs 
//          must have atleast two independent children  
//          otherwise it is not a cut vertex  */ 
//       is_cut[0]= child[0]>1 ? true : false;  
 
 
//       for(int i=0;i<n;i++) 
//       { 
//         if(is_cut[i]) 
//           cout<<i<<" is cut vertex"<<endl; 
//       } 
//       return 0;
// }





// Approach 2:

#include <bits/stdc++.h>
using namespace std;
void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[], vector<int> &isArticulation) {
    vis[node] = 1; 
    tin[node] = low[node] = timer++;
    int child = 0; 
    for(auto it: adj[node]) {
        if(it == parent) continue;
        
        if(!vis[it]) {
            dfs(it, node, vis, tin, low, timer, adj, isArticulation); 
            low[node] = min(low[node], low[it]); 
	    child++; 
            if(low[it] >= tin[node] && parent != -1) {
                isArticulation[node] = 1; 
            }
        } else {
            low[node] = min(low[node], tin[it]); 
        }
    }
    
    if(parent == -1 && child > 1) {
        isArticulation[node] = 1; 
    }
}
int main() {
    int n, m;
    cin >> n >> m; 
	vector<int> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v; 
	    adj[u].push_back(v);
	    adj[v].push_back(u); 
	}
	
	vector<int> tin(n, -1);
	vector<int> low(n, -1); 
	vector<int> vis(n, 0);
	vector<int> isArticulation(n, 0); 
	int timer = 0; 
	for(int i = 0;i<n;i++) {
	    if(!vis[i]) {
	        dfs(i, -1, vis, tin, low, timer, adj, isArticulation); 
	    }
	}
	
	for(int i = 0;i<n;i++) {
	    if(isArticulation[i] == 1) cout << i << endl;
	}
	
	return 0;
}