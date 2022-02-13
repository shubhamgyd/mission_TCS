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
    TreeNode* Tree(map<int,int>&mp,vector<int>&pre,int i,int j,int &preInd)
    {
        if(i>j)
        {
            return nullptr;
        }
        TreeNode *root= new TreeNode(pre[preInd++]);
        if(i==j)
        {
            return root;
        }
        int mid=mp[root->val];
        root->left=Tree(mp,pre,i,mid-1,preInd);
        root->right=Tree(mp,pre,mid+1,j,preInd);
        return root;
    }
public:
    TreeNode * buildTree(vector<int>&pre,vector<int>&in)
    {
        int preInd=0;
        map<int,int>mp;
        for(int i=0;i<in.size();i++)
        {
            mp[in[i]]=i;
        }
        return Tree(mp,pre,0,pre.size()-1,preInd);
    }
};


void Inorder(TreeNode* root)
{
    if(!root)
    {
        return;
    }
    Inorder(root->left);
    cout<<root->val<<" ";
    Inorder(root->right);
}
int main()
{
    Solution obj;
    vector<int>pre{3,9,20,15,7};
    vector<int>in{9,3,15,20,7};
    TreeNode* root=obj.buildTree(pre,in);
    Inorder(root);

}