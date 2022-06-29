/*
Problem Statement: Given below is a binary tree. The task is to print the top view of
the binary tree. The top view of a binary tree is the set of nodes visible when the tree
is viewed from the top.
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

// Using Recursion
// Top View-> Left -> Top-> Right ( seauence )

void top_view(TreeNode *node, bool goLeft, vector<int> &ans)
{

    if (node != NULL)
    {
        if (goLeft)
        {
            top_view(node->left, goLeft, ans);
            ans.push_back(node->val);
        }
        else
        {
            ans.push_back(node->val);
            top_view(node->right, goLeft, ans);
        }
    }
}

vector<int> TopView(TreeNode *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    top_view(root->left, true, ans);
    ans.push_back(root->val);
    top_view(root->right, false, ans);
    return ans;
}

// Using Iterative Method

/*
Approach:

First we have to make a queue of pair which have nodes and their respective +ve and -ve indexes.
Then we need a map data structure to store the lines and the nodes. This map will store the data in the form of sorted orders of keys(Lines).
Here we will follow the level order traversal.
Traverse through the nodes starting with root,0 and store them to the queue.
Until the queue is not empty, store the node  and line no. in 2 separate variable .
Then check if that line is present in the map or not
If not present then store the line and the node->val to the map
Otherwise store the node->left and node->right along with there line nos. to the queue.
Then print the node->val from the map
*/


class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        map<int, int> mpp;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            TreeNode *node = it.first;
            int line = it.second;
            if (mpp.find(line) == mpp.end())
                mpp[line] = node->val;

            if (node->left != NULL)
            {
                q.push({node->left, line - 1});
            }
            if (node->right != NULL)
            {
                q.push({node->right, line + 1});
            }
        }

        for (auto it : mpp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};

int main()
{
    
}