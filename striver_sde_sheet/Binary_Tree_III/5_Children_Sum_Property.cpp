
/*
Problem Statement: Children Sum Property in a Binary Tree. Write a program that converts any binary tree to one that follows the children sum property.

The children sum property is defined as, For every node of the tree, the value of a node is equal to the sum of values of its children(left child and right child).

Note: 

The node values can be increased by 1 any number of times but decrement of any node value is not allowed.
A value for a NULL node can be assumed as 0.
You are not allowed to change the structure of the given binary tree.
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

void solve(TreeNode *root)
{
    if (root == NULL) return;
  int child = 0;
  if (root -> left) {
    child += root -> left -> val;
  }
  if (root -> right) {
    child += root -> right -> val;
  }

  if (child < root -> val) {
    if (root -> left) root -> left -> val = root -> val;
    else if (root -> right) root -> right -> val = root -> val;
  }

  solve(root -> left);
  solve(root -> right);

  int tot = 0;
  if (root -> left) tot += root -> left -> val;
  if (root -> right) tot += root -> right -> val;
  if (root -> left || root -> right) root -> val = tot;
    
}

// Time Complexity: O(N)
// Reason: We are doing a simple tree traversal.

// Space Complexity: O(N)
// Reason: In the worst case( skewed tree), space complexity can be O(N).