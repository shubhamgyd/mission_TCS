/*
Problem Statement: Given a binary tree print the preorder traversal of binary tree.
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

// Using Resursion
void postOrder(TreeNode* root)
{
    if(root)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->val<<" ";
    }
}
// T:O(n)
// S:O(1)




// Using Stack
vector<int> postOrderT(TreeNode* root)
{
    vector<int>ans;
    stack<TreeNode*>st;
    stack<int>out;
    st.push(root);
    while(!st.empty())
    {
        auto it=st.top();
        st.pop();
        out.push(it->val);
        if(it->left)
        {
            st.push(it->left);
        }
        if(it->right)
        {
            st.push(it->right);
        }
    }
    while(!out.empty())
    {
        ans.push_back(out.top());
        out.pop();
    }
    return ans;
}
// T:O(n)
// S:O(n)


int main()
{

}