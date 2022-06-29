// Problem Statement: Given a binary tree print the preorder traversal of binary tree.

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

// Using Recursive
void preOrder(TreeNode* root)
{
    if(root)
    {
        cout<<root->val<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
// T:O(n)
// S:O(1)


// Using Stack
vector<int> preOrderT(TreeNode*  root)
{
    vector<int>ans;
    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty())
    {
        auto it=st.top();
        st.pop();
        ans.push_back(it->val);
        if(it->right)
        {
            st.push(it->right);
        }
        if(it->left)
        {
            st.push(it->left);
        }
    }
    return ans;
}