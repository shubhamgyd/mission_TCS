#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    TreeNode* bst(vector<int>&preorder,int &index,int limit)
    {
        if(index>=preorder.size()|| preorder[index]>limit)
        { 
            return NULL;
        }
        TreeNode* root= new TreeNode(preorder[index++]);
        root->left=bst(preorder,index,root->val);
        root->right=bst(preorder,index,limit);
        return root;
    }
    
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        return bst(preorder,index,INT_MAX);
    }
};