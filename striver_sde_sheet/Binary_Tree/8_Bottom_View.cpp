/*
Problem Statement: Given a binary tree, print the bottom view from left to right.
 A node is included in the bottom view if it can be seen when we look at the tree
 from the bottom.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
Approach:

First we have to make a queue of pair which have nodes and their respective +ve and -ve indexes.
Then we need a map data structure to store the lines and the nodes. This map will store the data in the form of sorted orders of keys(Lines).
Here we will follow the level order traversal.
Traverse through the nodes starting with root,0 and store them to the queue.
Until the queue is not empty, store the node  and line no. in 2 separate variables .
Then store the line and the node->val to the map, if there will be any node value present that corresponds to a line in the map , it will be replaced by the new node value and by this we will get the last node of each line.
Store the node->left and node->right along with their line nos. to the queue.
Then print the node->val from the map

Tip: Here there is only 1 small difference from the Top View of the Tree.
 Here we don’t need to check whether the node is previously present on the
 map or node before entering it. We have to replace the node of each line if
 that was previously present on the map.
*/

vector<int> bottomView(TreeNode *root)
{
    vector<int> ans;
    if (!root)
        return {};
    queue<pair<TreeNode *, int>> q;
    map<int, int> mp;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int line = it.second;
        mp[line] = it.first->val;
        if (it.first->left)
        {
            q.push({it.first->left, line - 1});
        }
        if (it.first->right)
        {
            q.push({it.first->right, line + 1});
        }
    }
    for (auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}

int main()
{
}