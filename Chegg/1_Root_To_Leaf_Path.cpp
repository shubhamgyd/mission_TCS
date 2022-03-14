#include<bits/stdc++.h>
using namespace std;




struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
    vector<string> result;
    string arrow = "->";
    void helper(TreeNode* root, string path) {
        path += to_string(root->val);
        if (!root->right && !root->left) {
            result.push_back(path);
            return;
        }

        path += arrow;
        if (root->right) helper(root->right, path);
        if (root->left) helper(root->left, path);
        
        return;
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        helper(root,"");
        return result;
        
    }
};