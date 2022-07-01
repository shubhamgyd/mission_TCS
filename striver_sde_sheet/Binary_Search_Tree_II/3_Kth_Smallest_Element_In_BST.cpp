// Problem statement: Given a binary search tree find the kth largest and smallest element in Binary Search Tree.
// Examples:

// Input: N=6
//        Arr=[5,3,6,2,4,1]
//        K=3

// Output: Kth largest element is 4
//         Kth smallest element is 3

// Input: N=7
//        Arr=[10,40,45,20,25,30,50]
//        k=3

// Output: Kth largest element is 4
//         Kth smallest element is 3

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;
    TreeNode() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right), next(next) {}
};

class Solution
{
    // void inorder(TreeNode* root,vector<int>&v)
    // {
    //     if(root==nullptr) return;
    //     inorder(root->left,v);
    //     v.push_back(root->val);
    //     inorder(root->right,v);
    // }
    int find(TreeNode *root, int &k)
    {
        if (root)
        {
            int x = find(root->left, k);
            return !k ? x : !--k ? root->val
                                 : find(root->right, k);
        }
        return 0;
    }

public:
    // Approach :1
    // int kthSmallest(TreeNode* root, int k) {
    //     vector<int>v;
    //     inorder(root,v);
    //     return v[k-1];
    //     return solve(root,k);
    // }

    // Approach :2
    int kthSmallest(TreeNode *root, int k)
    {
        return find(root, k);
    }
};




// another solution
int solve(TreeNode* root,int k,int &cnt,int &data)
{
    if(root)
    {
        solve(root->left,k,cnt,data);
        cnt++;
        if(cnt==k){
            data=root->val;
        }
        solve(root->right,k,cnt,data);
    }
}
int kthSmallest(TreeNode* root, int k)
{
	//	Write the code here.
    int cnt=0;
    int data=root->val;
    solve(root,k,cnt,data);
    return data;
}