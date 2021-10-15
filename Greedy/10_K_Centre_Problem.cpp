/*
Given n cities and distances between every pair of cities, select k cities to place warehouses (or ATMs or Cloud Server) such that the maximum distance of a city to a warehouse 
(or ATM or Cloud Server) is minimized. 

For example consider the following four cities, 0, 1, 2 and 3 and distances between them, 
how do place 2 ATMs among these 4 cities so that the maximum distance of a city to an ATM is
 minimized. 
*/

#include<bits/stdc++.h>
using namespace std;

int Dijaktras(int src,vector<pair<int,int>>graph[],int n)
{
    vector<bool>visited(n,false);
    vector<int>dist(n);
    for(int i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
    }
    dist[src]=0;
    queue<pair<int,int>>q;
    q.push({0,src});
    while(!q.empty())
    {
        auto u=q.front().second;
        q.pop();
        if(visited[u])
        {
            continue;
        }
        visited[u]=true;
        for(auto it:graph[u])
        {
            int v=it.first;
            int w=it.second;
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                q.push({-dist[v],v});
            }
        }
        
    }

    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=dist[i];
    }
    cout<<"Distance: "<<sum<<endl;
    return sum;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>graph[n];
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    int k;
    cin>>k;
    vector<pair<int,int>>dis;
    for(int i=0;i<n;i++)
    {
        
        dis.push_back({Dijaktras(i,graph,n),i});
    }
    sort(dis.begin(),dis.end());
    for(auto it:dis)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }
    for(auto it:dis)
    {
        if(k==0)
        {
            break;
        }
        cout<<it.second<<" ";
        k--;
    }
    return 0;
}


/*

//K Centers Problem | Set 1 (Greedy Approximate Algorithm)
#include<stdio.h>

#define v 4

int min(int a,int b)
{
	return (a<b)? a: b;
}

void kcentres(int graph[v][v],int k)
{
	bool selected[v];
	int mini[v];
	for(int i=0;i<v;i++)
	{
		selected[i]=0;
		mini[i]=1000;
	}
		
	selected[2]=1;
	
	for(int a=1;a<k;a++)
	{
		for(int i=0;i<v;i++)
		{
			if(selected[i])
			{
				for(int j=0;j<v;j++)
				{
					if(!selected[j])
					{
						mini[j]=min(mini[j],graph[j][i]);
					}
				}
			}
		}
		
		int max=0,maxidx;
		for(int i=0;i<v;i++)
		{
			if(!selected[i])
			{
				if(mini[i] > max)
				{
					max=mini[i];
					maxidx=i;
				}
			}
		}
		
		selected[maxidx]=1;
		for(int i=0;i<v;i++)
			mini[i]=1000;
	}
	
	for(int i=0;i<v;i++)
		if(selected[i])	
			printf("%d\t",i);
}

main()
{
	int graph[v][v]={{0,10,7,6},
					{10,0,8,5},
					{7,8,0,12},
					{6,5,12,0}};
					
	kcentres(graph,3);
}
*/