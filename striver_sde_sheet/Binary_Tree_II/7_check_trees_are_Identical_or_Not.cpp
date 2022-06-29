/*
Approach: In order to check whether two trees are identical or not, we need to traverse the 
trees. While traversing we first check the value of the nodes, if they are unequal we can 
simply return false, as trees are non-identical. If they are the same, then we need to 
recursively check their left child as well as the right child. When we get all the three 
values as true(node values, left child, right child) we can conclude that these are 
identical trees and can return true. Any other combination will return false.
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

bool isIdentical(TreeNode* root1,TreeNode* root2)
{
    if(!root1 and !root2) return true;
    else if(!root1 or !root2) return false;
    return (root1->val==root2->val and isIdentical(root1->left,root2->left) and isIdentical(root1->right,root2->right));
}
// Time Complexity: O(N).
// Reason: We are doing a tree traversal.

// Space Complexity: O(N)
// Reason: Space is needed for the recursion stack. In the worst case (skewed tree), 
// space complexity can be O(N).




// by using level order / wrong approach