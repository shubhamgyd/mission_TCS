// // In this problem we are going to find the all possible paths from the source vertex to the destination
// // Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1, 
// //                 and return them in any order.
// //The graph is given as follows: graph[i] is a list of all nodes you can visit from node i 
// //(i.e., there is a directed edge from node i to node graph[i][j]).


// //Remember one thing, it is a DAG(Directed Acyclic Graph) so there no worry about cycle formation, also TLE
// #include<bits/stdc++.h>
// using namespace std;


// void dfs(vector<vector<int>>&graph,vector<vector<int>>&result,vector<int>&paths,int src,int destn)
// {
//     paths.push_back(src);                                 // Pushing the src into the temporary path , for checking path is possible or not
//     if(src==destn) result.push_back(paths);      // If the current node becomes the last node of graph/destination i.e graph.size()-1 
//                                                 // Then push the path into the resultant path (valid path)
//     else
//         for(int ele:graph[src])
//             dfs(graph,result,paths,ele,destn);        // Recursively checking the paths to the last node
//     paths.pop_back();                           // If path  is not present from the current source to last node , then pop the element,
//                                                 //  (i.e lastly pushed element is not valid ) , so we can check other vertex.
// }


// vector<vector<int>> allPossiblePath(vector<vector<int>>&graph,int src,int destn)
// {
//     vector<vector<int>>result;
//     vector<int>paths;
//     dfs(graph,result,paths,src,destn);
//     cout<<result.size()<<endl;
//     return result;
// }


// int32_t main()
// {
//     int v,e,src,destn;
//     cin>>v>>e>>src>>destn;
//     vector<vector<int>>graph(v);
//     for(int i=0;i<e;i++)
//     {
//         int u,v;
//         cin>>u>>v;
//         graph[u].push_back(v);
//     }
//     //destn=graph.size()-1;

//     vector<vector<int>>path=allPossiblePath(graph,src,destn);
//     cout<<"Resultant Paths From source to Destination are: "<<endl;
//     for(auto ele:path)
//     {
//         for(auto it:ele)
//         {
//             if(it==destn)
//             {
//                 cout<<it;
//             }
//             else cout<<it<<"-->";
//         }
//         cout<<endl;
//     }
// }



#include<bits/stdc++.h>
using namespace std;


void dfs(vector<int>graph[],vector<int>&paths,int src,int destn,int weight,bool &ct,vector<bool>&visited,int &value)
{
	bool ok=false;
	visited[src]=true;
    paths.push_back(src);  
	value|=src;                               
    if(src==destn){
		if(value>weight)
		{
			ok=true;
			ct=true;
			return;
		}
	}   
    if(ok)
	{
		return;
	}                                          
    else
        for(int ele:graph[src])
		{
			if(!visited[ele])
			{
				dfs(graph,paths,ele,destn,weight,ct,visited,value);   
			}
		}
	value|=paths.back(); 
    paths.pop_back();  
	visited[src]=false;                      
                                                
}

vector<string> solution(int n,int m,vector<vector<int>>edges,int q,vector<vector<int>>queries)
{
	vector<int>adj[n+1];
	for(int i=0;i<m;i++)
	{
		int u=edges[i][0];
		int v=edges[i][1];
	}
	vector<string>ans;
	vector<int>path;
	for(int i=0;i<q;i++)
	{
		vector<bool>visited(n+1,false);
		int u,v,w;
		u=queries[i][0];
		v=queries[i][1];
		w=queries[i][2];
		bool ok=false;
		int value=0;
		dfs(adj,path,u,v,w,ok,visited,value);
		if(ok)
		{
			ans.push_back("YES");
		}
		else
		{
			ans.push_back("NO");
		}
	}
	return ans;
}


int main()
{
	int n,m;
	cin>>n>>m;
	vector<int>adj[n+1];
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int q;
	cin>>q;
	vector<vector<int>>queries;
	for(int i=0;i<q;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		queries.push_back({u,v,w});
	}
	vector<string>ans=solution(n,m,adj,q,queries);
	for(auto it:ans)
	{
		cout<<it<<endl;
	}
	return 0;
}