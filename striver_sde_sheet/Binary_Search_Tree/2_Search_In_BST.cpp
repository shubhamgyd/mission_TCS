



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


class Solution {
    TreeNode* Search(TreeNode* root,int val)
    {
        if(!root) return NULL;
        if(root->val==val)
        {
            return root;
        }
        if(root->val<val)
        {
            return Search(root->right,val);
        }
        else
        {
            return Search(root->left,val);
        }
        
    }
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // Solution 1: Recursive
        // return Search(root,val);
        
        // Solution 2: Iterative
        if(!root)
        {
            return NULL;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            auto u=q.front();
            q.pop();
            if(u->val==val)
            {
                return u;
            }
            if(u->left)
            {
                q.push(u->left);
            }
            if(u->right)
            {
                q.push(u->right);
            }
        }
        return NULL;
    }
};