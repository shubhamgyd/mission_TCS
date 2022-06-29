/*
Problem Statement: Given a Binary Tree, find the Right/Left view of it.
The right view of a Binary Tree is a set of nodes visible when the tree is viewed from the 
right side. The left view of a Binary Tree is a set of nodes visible when the tree is viewed 
from the left side.
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



// using recursion
void solve(TreeNode* root,int level,vector<int>&ans)
{
    if(!root) return;
    if(ans.size()==level) ans.push_back(root->val);
    solve(root->left,level+1,ans);
    solve(root->right,level+1,ans);
}

vector<int> getLeftView(TreeNode *root)
{
    //    Write your code here
    vector<int>ans;
    solve(root,0,ans);
    return ans;
}
// T:O(n)
// S:O(n)



// Iterative Method
vector<int> leftView(TreeNode* root)
{
    queue<TreeNode*>q;
    q.push(root);
    vector<int>ans;
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            auto it=q.front();
            q.pop();
            if(i==0)
            {
                ans.push_back(it->val);
            }
            if(it->left) q.push(it->left);
            if(it->right) q.push(it->right);
        }
    }
    return ans;
}
// T:O(n)
// S:O(n)

int main()
{

}