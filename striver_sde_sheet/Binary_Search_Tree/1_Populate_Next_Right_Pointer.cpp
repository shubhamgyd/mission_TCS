
// You are given a perfect binary tree where all leaves are on the same level, 
// and every parent has two children. The binary tree has the following definition:

// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL.

// For perfect binatry tree

#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;
    TreeNode() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) , next(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) , next(next) {}
};




// for common tree
void connectNodes(TreeNode*root) {
    // Write your code here.
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size-1;i++)
        {
            auto it=q.front();q.pop();
            it->next=q.front();
            if(it->left) q.push(it->left);
            if(it->right) q.push(it->right);
        }
        auto it=q.front();q.pop();
        it->next=NULL;
        if(it->left) q.push(it->left);
        if(it->right) q.push(it->right);
    }
}