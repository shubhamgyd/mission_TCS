
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

class Solution {
    int Search(vector<int>& inorder,int i,int j,int data)
    {
        int ind=i;
        for(ind=i;ind<=j;ind++)
        {
            if(inorder[ind]==data)
            {
                break;
            }
        }
        return ind;
    }
    TreeNode* bt(vector<int>& inorder, vector<int>& postorder,int i,int j,int &post)
    {
        if(i>j)
        {
            return NULL;
        }
        
        TreeNode *root= new TreeNode(postorder[post--]);
        if(i==j)
        {
            return root;
        }
        int ind=Search(inorder,i,j,root->val);
        root->right=bt(inorder,postorder,ind+1,j,post);
         root->left=bt(inorder,postorder,i,ind-1,post);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // reverse(preorder.begin(),preorder.end());
        int post=postorder.size()-1;
        return bt(inorder,postorder,0,postorder.size()-1,post);
    }
};