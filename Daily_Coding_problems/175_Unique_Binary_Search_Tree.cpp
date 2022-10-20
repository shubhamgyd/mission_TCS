/*
This problem was asked by Amazon.

Given an integer N, construct all possible binary search trees with N nodes.
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

class Solution
{
    vector<TreeNode *> solve(int l, int r)
    {
        if (l > r)
            return {NULL};
        vector<TreeNode *> ans;
        for (int root = l; root <= r; root++)
        {
            vector<TreeNode *> left = solve(l, root - 1);
            vector<TreeNode *> right = solve(root + 1, r);
            for (auto Node_l : left)
            {
                for (auto Node_r : right)
                {
                    TreeNode *node = new TreeNode(root);
                    node->left = Node_l;
                    node->right = Node_r;
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }

public:
    vector<TreeNode *> generateTrees(int n)
    {
        return solve(1, n);
    }
};

int main()
{
}