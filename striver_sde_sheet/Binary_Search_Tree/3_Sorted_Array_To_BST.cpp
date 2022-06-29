/*
Given an integer array nums where the elements are sorted in ascending order, 
convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two 
subtrees of every node never differs by more than one.
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

class Solution {
    TreeNode* BST(vector<int>&nums,int i,int j)
    {
        if(i>=j)
        {
            return NULL;
        }
        
        int mid=(i+j)/2;
        TreeNode *root= new TreeNode(nums[mid]);
        //root->val=nums[mid];
        root->left=BST(nums,i,mid);
        root->right=BST(nums,mid+1,j);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BST(nums,0,nums.size());
    }
};


int main()
{

}