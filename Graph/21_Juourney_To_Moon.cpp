// In this program we are going to find the nnumber of pair of austronuts to send the moon
// by using simple dfs

// #include<bits/stdc++.h>
// using namespace std;

// int dfs_util(vector<int>graph[],vector<bool>&visited,int &count,int src)
// {
//     visited[src]=true;
//     count++;
//     for(auto it:graph[src])
//     {
//         if(!visited[it])
//         {
//             dfs_util(graph,visited,count,it);
//         }
//     }
//     return count;
// }

// int dfs(vector<int>graph[],vector<int>&sum,int n)
// {
//     vector<bool>visited(n,false);
//     long long c=0;
//     for(int i=0;i<n;i++)
//     {
//         if(visited[i]==false)
//         {
//             int count=0;
//             count=dfs_util(graph,visited,count,i);
//             if(count!=1)
//             {
//                 sum.push_back(count);
//             }
//             else
//             {
//                 c++;
//             }
//         }
//     }
//     return c;
// }

// int main()
// {
//     int n,m,i;
//     cin>>n>>m;
//     vector<int>graph[n];
//     long long c;
//     for(int i=0;i<m;i++)
//     {
//         int u,v;
//         cin>>u>>v;
//         graph[u].push_back(v);
//         graph[v].push_back(u);
//     }
//     vector<int>sum;
//     long long  result=0;
//     c=dfs(graph,sum,n);
//     for(i=0;i<sum.size()-1;i++)
//     {
//         for(int j=i+1;j<sum.size();j++)
//         {
//             result+=(sum[i]*sum[j]);
//         }
//         result+=(sum[i]*c);
//     }
//     result+=(sum[i]*c);
//     result+=(c*(c-1)/2);
//     cout<<result<<endl;
//     return 0;
// }























#include<bits/stdc++.h>
using namespace std;


void dfs(int src,int& count,vector<int>&vsitited,vector<int>graph[])
{
    if(vsitited[src]) return;
    vsitited[src]=1;
    count++;
    for(auto it:graph[src])
    {
        dfs(it,count,vsitited,graph);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>graph[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int>solution;
    vector<int>visited(n,0);
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            int count=0;
            dfs(i,count,visited,graph);
            solution.push_back(count);
        }
    }
    int result=n*(n-1)/2;
    for(int i=0;i<solution.size();i++)
    {
        result-=((solution[i]*(solution[i]-1))/2);
    }
    cout<<result<<endl;
    return 0;
}



/*
Time Complexity: O(V+E)  i.e DFS
Space Complexity : O(V)  . to storing the nodes
*/