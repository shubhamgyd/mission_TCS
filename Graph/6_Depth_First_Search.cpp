// // In this problem we are going to see the Depth first traversal of a graph
// #include<bits/stdc++.h>
// using namespace std;

// void depth_first_search(vector<list<int>>graph,int src)
// {
//     vector<bool>visited(graph.size(),false);
//     stack<int>s;
//     s.push(src);
//     visited[src]=true;
//     while(!s.empty())
//     {
//         int vertex=s.top();s.pop();
//         cout<<vertex<<" ";
//          for(list<int>::iterator itr = graph[vertex].begin();itr!=graph[vertex].end();itr++)
//          {
//             if(!visited[*itr])
//                 s.push(*itr);
//             visited[*itr] = true;
//         }
//     }

// }

// int main()
// {
//     vector<list<int>>graph;
//     int v,e,src,des;
//     cin>>v>>e;
//     graph.resize(v);
//     while(e--)
//     {
//         cin>>src>>des;
//         graph[src].push_back(des);
//         //graph[des].push_back(src);
//     }
//     cin>>src;
//     depth_first_search(graph,src);
//     return 0;
// }


#include<iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;
void depth_first_search(vector<list<int>> graph,int src){
    vector<bool>visited(graph.size(),false);
    stack<int>S;
    S.push(src);
    visited[src] = true;
    while(!S.empty()){
        int vertex = S.top(); S.pop();
        cout << vertex << " ";
        for(list<int>::iterator itr = graph[vertex].begin();itr!=graph[vertex].end();itr++){
            if(!visited[*itr])
                S.push(*itr);
            visited[*itr] = true;
        }
    }
}
int main(){
    vector<list<int>> graph;
    int v,e,src,des;
    cin >> v >> e;
    graph.resize(v);
    while(e--){
        cin >> src >> des;
        graph[src].push_back(des);
        graph[des].push_back(src);
    }
    cin >> src;
    depth_first_search(graph,src);
    return 0;
}



// // C++ program to print DFS
// // traversal for a given given
// // graph
// #include <bits/stdc++.h>
// using namespace std;

// class Graph {

// 	// A function used by DFS
// 	void DFSUtil(int v);

// public:
// 	map<int, bool> visited;
// 	map<int, list<int>> adj;
// 	// function to add an edge to graph
// 	void addEdge(int v, int w);

// 	// prints DFS traversal of the complete graph
// 	void DFS();
// };

// void Graph::addEdge(int v, int w)
// {
// 	adj[v].push_back(w); // Add w to v’s list.
// 	adj[w].push_back(v);
// }

// void Graph::DFSUtil(int v)
// {
// 	// Mark the current node as visited and print it
// 	visited[v] = true;
// 	cout << v << " ";

// 	// Recur for all the vertices adjacent to this vertex
// 	list<int>::iterator i;
// 	for (i = adj[v].begin(); i != adj[v].end(); ++i)
// 		if (!visited[*i])
// 			DFSUtil(*i);
// }

// // The function to do DFS traversal. It uses recursive
// // DFSUtil()
// void Graph::DFS()
// {
// 	// Call the recursive helper function to print DFS
// 	// traversal starting from all vertices one by one
// 	for (auto i:adj)
// 		if (visited[i.first] == false)
// 			DFSUtil(i.first);
// }

// // Driver Code
// int main()
// {
// 	// Create a graph given in the above diagram
// 	Graph g;
// 	g.addEdge(0, 1);
// 	g.addEdge(0, 9);
// 	g.addEdge(1, 2);
// 	g.addEdge(2, 0);
// 	g.addEdge(2, 3);
// 	g.addEdge(9, 3);

// 	cout << "Following is Depth First Traversal \n";
// 	g.DFS();

// 	return 0;
// }

