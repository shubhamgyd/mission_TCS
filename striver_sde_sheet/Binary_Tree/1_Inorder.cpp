/*
Problem Statement: Given a Binary Tree. Find and print the inorder traversal of Binary Tree.
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

// Recursive Solution
void inorderRecur(TreeNode* root)
{
    if(root)
    {
        inorderRecur(root->left);
        cout<<root->val<<" ";
        inorderRecur(root->right);
    }
}
// Time Complexity: O(N).
// Reason: We are traversing N nodes and every node is visited exactly once.

// Space Complexity: O(N)
// Reason: Space is needed for the recursion stack. In the worst case (skewed tree), space complexity can be O(N).


vector<int> Inorder(TreeNode*  root)
{
    vector<int>ans;
    stack<TreeNode*>st;
    // st.push(root);
    while(root!=NULL or !st.empty())
    {
        while(root)
        {
            st.push(root);
            root=root->left;
        }
        root=st.top();
        st.pop();
        ans.push_back(root->val);
        root=root->right;
    }
    return ans;
}
// Time complexity: O(n)
// Space complexity: O(n)

