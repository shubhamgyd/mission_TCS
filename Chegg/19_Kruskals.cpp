#include<bits/stdc++.h>
using namespace std;
struct node {
    char u;
    char v;
    int wt; 
    node(char first, char second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b) {
    return a.wt < b.wt; 
}

int findPar(char u, vector<int> &parent) {
    if(u == parent[u]) return u; 
    return findPar(parent[u], parent); 
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findPar(u, parent);
    v = findPar(v, parent);
    if(rank[u] < rank[v]) {
    	parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
    	parent[v] = u; 
    }
    else {
    	parent[v] = u;
    	rank[u]++; 
    }
}
int main(){
	int N,m;
	cin>>N>>m;
	vector<node>edges; 
	for(int i = 0;i<m;i++) {
	    int u,v,wt;
	    cin>>u>>v>>wt;
	    edges.push_back(node(u,v,wt)); 
	}
	sort(edges.begin(), edges.end(), comp);
	vector<int> parent(N+1);
	for(int i =0;i<=N;i++) 
	    parent[i] = i; 

	vector<int> rank(N+1, 0); 
	
	int cost = 0;
	vector<tuple<int,int,int>> mst; 
	for(auto it : edges) {
	    if(findPar(it.v, parent) != findPar(it.u, parent)) {
	        cost += it.wt; 
	        mst.push_back({it.u, it.v,it.wt}); 
	        unionn(it.u, it.v, parent, rank); 
	    }
	}
	cout << cost << endl;
	for(auto it : mst){
        int u,v,wt;
        tie(u,v,wt)=it;
        cout << u<<" "<< v << " " <<wt<<endl; 
    }
	return 0;
}