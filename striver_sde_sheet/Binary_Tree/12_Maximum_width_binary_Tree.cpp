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
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        long long int res=1;
        while(!q.empty())
        {
            int size=q.size();
            long long start=q.front().second;
            long long end=q.back().second;
            res=max((long long)res,end-start+1LL);
            for(int i=0;i<size;++i)
            {
                pair<TreeNode*,long long> p=q.front();
                // cout<<"p.front "<<p.first->val<<" p.second: "<<p.second<<" ";
                long long id=p.second-start;
                // cout<<"id: "<<id<<endl;
                q.pop();
                if(p.first->left)
                {
                    q.push({p.first->left,2*id+1});
                }
                if(p.first->right)
                {
                    q.push({p.first->right,2*id+2});
                }
            }
        }
        return res;
    }
};

/*
Time Complexity: O(N)
Reason: We are doing a simple level order traversal. The inner loop simply traverses the nodes level-wise and doesn’t add to the complexity.

Space Complexity: O(N)
*/