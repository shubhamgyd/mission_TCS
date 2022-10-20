/*
This problem was asked by Twitter.

A classroom consists of N students, whose friendships can be represented in an adjacency
list. For example, the following descibes a situation where 0 is friends with 1 and 2, 3
is friends with 6, and so on.

{0: [1, 2],
 1: [0, 5],
 2: [0],
 3: [6],
 4: [],
 5: [1],
 6: [3]}
Each student can be placed in a friend group, which can be defined as the transitive
closure of that student's friendship relations. In other words, this is the smallest
set such that no student in the group has any friends outside this group. For the
example above, the friend groups would be {0, 1, 2, 5}, {3, 6}, {4}.

Given a friendship list such as the one above, determine the number of friend
groups in the class.
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<int> adj[], vector<bool> &visited, vector<int> &nodes)
{
    if (visited[i])
        return;
    visited[i] = true;
    nodes.push_back(i);
    for (auto it : adj[i])
    {
        dfs(it, adj, visited, nodes);
    }
}

int main()
{
    int n = 6;
    vector<int> adj[n + 1];
    adj[0] = {1, 2};
    adj[1] = {0, 5};
    adj[2] = {0};
    adj[3] = {6};
    adj[4] = {};
    adj[5] = {1};
    adj[6] = {3};
    vector<bool> visited(n + 1, false);
    for (int i = 0; i <= n; i++)
    {
        if (!visited[i])
        {
            vector<int> nodes;
            dfs(i, adj, visited, nodes);
            for (auto it : nodes)
            {
                cout << it << " ";
            }
            cout << endl;
        }
    }
}