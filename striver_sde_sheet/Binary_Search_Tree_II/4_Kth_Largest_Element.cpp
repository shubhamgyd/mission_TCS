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

void solve(TreeNode* root,int k,int &data,int &cnt)
{
    if(root)
    {
        solve(root->right,k,data,cnt);
        ++cnt;
        if(cnt==k)
        {
            data=root->val;
        }
        solve(root->left,k,data,cnt);
    }
}

int KthLargestNumber(TreeNode* root, int k) 
{
    // Write your code here.
    int data=-1;
    int cnt=0;
    solve(root,k,data,cnt);
    return data;
}