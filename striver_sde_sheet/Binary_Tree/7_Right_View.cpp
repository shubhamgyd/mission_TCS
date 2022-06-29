

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
    if(level==ans.size()) ans.push_back(root->val);
    solve(root->right,level+1,ans);
    solve(root->left,level+1,ans);
}

vector<int> getRightView(TreeNode* root)
{
    vector<int>ans;
    solve(root,0,ans);
    return ans;
}
// T:O(n)
// S:O(n)



// Iterative Method

vector<int> rightView(TreeNode* root)
{
    vector<int>ans;
    if(!root) return {};
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            auto it=q.front();q.pop();
            if(i==0)
            {
                ans.push_back(it->val);
            }
            if(it->right) q.push(it->right);
            if(it->left) q.push(it->left);
        }
    }
    return ans;
}
// T:O(n)
// S:O(n)


