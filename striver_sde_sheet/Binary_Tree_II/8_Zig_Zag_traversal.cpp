

/*
Problem Statement: Given the root of a binary tree, return the zigzag level order 
traversal of Binary Tree. (i.e., from left to right, then right to left for the next 
level and alternate between).
*/


#include<bits/stdc++.h>
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

vector<int> zigZag(TreeNode* root)
{
    vector<int>ans;
    if(!root) return ans;
    deque<TreeNode*>dq;
    dq.push_back(root);
    int level=0;
    while(!dq.empty())
    {
        int size=dq.size();
        for(int i=0;i<size;i++)
        {
            if(level%2==0)
            {
                auto it=dq.front();
                ans.push_back(it->val);
                if(it->left) dq.push_back(it->left);
                if(it->right) dq.push_back(it->right);
            }
            if(level%2==1)
            {
                auto it=dq.back();
                ans.push_back(it->val);
                if(it->right)dq.push_front(it->right);
                if(it->left) dq.push_front(it->left);
            }
        }
        level++;
    }
    return ans;
}
// Time Complexity: O(N)   
// Space Complexity: O(N)