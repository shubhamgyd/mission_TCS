/*
Problem Statement: Vertical Order Traversal Of A Binary Tree. 
Write a program for Vertical Order Traversal order of a Binary Tree.
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


vector<vector<int>> verticalOrder(TreeNode* root)
{
    vector<vector<int>>ans;
    if(!root) return ans;
    map<int,map<int,multiset<int>>>mp;
    queue<pair<TreeNode*,pair<int,int>>>q;
    q.push({root,{0,0}});
    while(!q.empty())
    {
        auto u=q.front();
        q.pop();
        TreeNode* temp=u.first;
        int pos=u.second.first;
        int level=u.second.second;
        mp[pos][level].insert(temp->val);
        if(temp->left)
        {
            q.push({temp->left,{pos-1,level+1}});
        }
        if(temp->right)
        {
            q.push({temp->right,{pos+1,level+1}});
        }
    }
    for(auto it:mp)
    {
        vector<int>temp;
        for(auto ele:it.second)
        {
            temp.insert(temp.end(),ele.second.begin(),ele.second.end());
        }
        ans.push_back(temp);
    }
    return ans;
}