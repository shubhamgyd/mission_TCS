/*
Given the root of a binary tree, the level of its root is 1, the level of its children is 2,
and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is
maximal.
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
public:
    int maxLevelSum(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int mx = INT_MIN;
        int level = 0;
        int lev = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            int sum = 0;
            lev++;
            for (int i = 0; i < size; i++)
            {
                auto curr = q.front();
                q.pop();
                sum += curr->val;
                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
            }
            // cout<<"Sum: "<<sum<<endl;
            if (sum > mx)
            {
                mx = sum;
                level = lev;
            }
        }
        return level;
    }
};