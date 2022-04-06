#include<bits/stdc++.h>
using namespace std;


void DFS(int src,vector<int>adj[],vector<bool>&visited)
{
    if(visited[src]) return;
    visited[src]=true;
    char ch='A'+src;
    cout<<ch<<" ";
    for(auto it:adj[src])
    {
        DFS(it,adj,visited);
    }
}

int main()
{
    vector<int>adj[26];
    adj['A'-'A'].push_back('S'-'A');
    adj['S'-'A'].push_back('A'-'A');
    adj['A'-'A'].push_back('D'-'A');
    adj['D'-'A'].push_back('A'-'A');
    adj['S'-'A'].push_back('C'-'A');
    adj['C'-'A'].push_back('S'-'A');
    adj['S'-'A'].push_back('B'-'A');
    adj['B'-'A'].push_back('S'-'A');
    adj['B'-'A'].push_back('D'-'A');
    adj['D'-'A'].push_back('B'-'A');
    adj['D'-'A'].push_back('C'-'A');
    adj['C'-'A'].push_back('D'-'A');

    vector<bool>visited(26,false);
    cout<<('S'-'A')<<endl;
    DFS(('S'-'A'),adj,visited);
}