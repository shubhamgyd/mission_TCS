#include<bits/stdc++.h>
using namespace std;

// Structure to store the graph of nodes
struct graphNode {
	// Start Node
    int start;

	// End Node
    int end;

	// Weight of Edge
    int weight; 

	// Parametarized Constructor 
    graphNode(int startNode, int endNode, int weightOfEdge) {
        start = startNode;
        end = endNode;
        weight = weightOfEdge;
    }
};


// Utility function which find the parent of each node
int getParent(int node, vector<int> &parentOfNodes) 
{
	// If given node and parent of node is same 
	// then return return current node as a parent
    if(node==parentOfNodes[node]) return node; 
	// else go to it's parent to check 
    return (getParent(parentOfNodes[node], parentOfNodes)); 
}

// Utility Function which union the set of nodes together
void unionOfNodes(int start, int end, vector<int>&parentOfNodes, vector<int>&rankOfNodes) 
{
	// Find the parent of start node
    start = getParent(start, parentOfNodes);
	// Find the parent of end node
    end = getParent(end, parentOfNodes);

	// If rank of start node is less than
	// means number of connected nodes to the start node is less than the end node
	// then set the parent of start node is end node
    if(rankOfNodes[start] < rankOfNodes[end]) {
    	parentOfNodes[start] = end;
    }
	// else if rankd of end node is less than the start node
	// then set the start node as a parent of end node
    else if(rankOfNodes[end ] <rankOfNodes[start]) 
	{
    	parentOfNodes[end] = start; 
    }
	// Else set any node as parent of other node
	// and increase the rank of parent node whatever we have set
    else 
	{
    	parentOfNodes[end] = start;
    	rankOfNodes[start]++; 
    }
}


// Utility function which sort the edges according to their edge weight
bool weightSort(graphNode A, graphNode B) {
    return A.weight < B.weight; 
}

int main(){
	// Number of nodes
	int N=4;

	// Number of edges
	int m=5;

	// Graph of graphNode
	// where we can store the edge from source to destionation with edge weight
	vector<graphNode>graph; 
	graph.push_back(graphNode(0,1,11));
	graph.push_back(graphNode(0,3,6));
	graph.push_back(graphNode(1,3,14));
	graph.push_back(graphNode(2,3,5));
	graph.push_back(graphNode(0,2,7));

	// Sort the graph according to their weight
	sort(graph.begin(),graph.end(), weightSort);

	// Parent of Nodes
	vector<int> parentOfNodes(N+1);
	// Make parent of each node itself initially
	for(int i =0;i<=N;i++) 
	{
		parentOfNodes[i] = i; 
	}


	// For Rank of Nodes
	vector<int> rankOfNodes(N+1, 0); 
	
	// minimum cost of weight
	int mnWeight = 0;

	// container which stores the edges included into the minimum spanning tree
	vector<tuple<int,int,int>> minimumSpaningTree; 

	// go to every edge
	for(auto node : graph) 
	{
		// get the parent of start node
		int parent1=getParent(node.start, parentOfNodes);
		// get the parent of end node
		int parent2=getParent(node.end, parentOfNodes);

		// if both node belongs to two differnt sets
		// means they both have differnt parent
	    if(parent1!=parent2) 
		{
			// startNode
			int startNode=node.start;
			// endNode
			int endNode=node.end;
			// edgeWeight
			int edgeWeight=node.weight;
			// add this edge in our MST
	        minimumSpaningTree.push_back({startNode,endNode,edgeWeight}); 
			// add the edge weight into cost
			mnWeight += node.weight; 
			// Make union of this two nodes
	        unionOfNodes(startNode, endNode, parentOfNodes, rankOfNodes); 
	    }
	}
	
	// Print edges included into MST
	cout<<"\nEdges in the constructed MST "<<endl;
	for(auto it:minimumSpaningTree)
	{
		int startNode,endNode,edgeWeight;
		tie(startNode,endNode,edgeWeight)=it;
		cout<<startNode<<"---"<<endNode<<"== "<<edgeWeight<<endl;
	} 

	// Print minimumCost
	cout <<"Minimum Cost Spanning Tree: "<<mnWeight << endl;
	return 0;
}