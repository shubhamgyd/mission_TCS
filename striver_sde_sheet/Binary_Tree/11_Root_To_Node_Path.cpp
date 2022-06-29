

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

bool getPath(TreeNode *root, vector<int> &arr, int x)
{
    // if root is NULL
    // there is no path
    if (!root)
        return false;

    // push the node's value in 'arr'
    arr.push_back(root->val);

    // if it is the required node
    // return true
    if (root->val == x)
        return true;

    // else check whether the required node lies
    // in the left subtree or right subtree of
    // the current node
    if (getPath(root->left, arr, x) ||
        getPath(root->right, arr, x))
        return true;

    // required node does not lie either in the
    // left or right subtree of the current node
    // Thus, remove current node's value from
    // 'arr'and then return false
    arr.pop_back();
    return false;
}

/*
Time Complexity: O(N)
Reason: We are doing a simple tree traversal.

Space Complexity: O(N)
Reason: In the worst case (skewed tree), space complexity can be O(N).
*/



// Using Iterative
vector<int> solve(TreeNode* A, int B) {
    if(!A) return {};
    if(A->val==B) return {B};
    map<int,int>mp;
    mp[A->val]=-1;
    queue<TreeNode*>q;
    q.push(A);
    vector<int>ans;
    bool ok=false;
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            auto it=q.front();
            q.pop();
            if(it->val==B)
            {
                ok=true;
                // mp[it->left->val]=it->val;
                ans.push_back(B);
                break;
            }
            if(it->left)
            {
                mp[it->left->val]=it->val;
                q.push(it->left);
            }
            if(it->right)
            {
                mp[it->right->val]=it->val;
                q.push(it->right);
            }
        }
        if(ok) break;
    }
    int data=mp[B];
    while(data!=-1)
    {
        ans.push_back(data);
        data=mp[data];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

/*
Time Complexity: O(N)
Reason: We are doing a simple tree traversal.

Space Complexity: O(N)
Reason: In the worst case (skewed tree), space complexity can be O(N).
*/