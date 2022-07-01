

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

// Using Hashing
bool findTarget(TreeNode *root, int k)
{
    unordered_set<int> set;
    return dfs(root, set, k);
}

bool dfs(TreeNode *root, unordered_set<int> &set, int k)
{
    if (root == NULL)
        return false;
    if (set.count(k - root->val))
        return true;
    set.insert(root->val);
    return dfs(root->left, set, k) || dfs(root->right, set, k);
}

// Using Two pointer
bool findTarget(TreeNode *root, int k)
{
    vector<int> nums;
    inorder(root, nums);
    for (int i = 0, j = nums.size() - 1; i < j;)
    {
        if (nums[i] + nums[j] == k)
            return true;
        (nums[i] + nums[j] < k) ? i++ : j--;
    }
    return false;
}

void inorder(TreeNode *root, vector<int> &nums)
{
    if (root == NULL)
        return;
    inorder(root->left, nums);
    nums.push_back(root->val);
    inorder(root->right, nums);
}

// Using Binary Search
bool findTarget(TreeNode *root, int k)
{
    return dfs(root, root, k);
}

bool dfs(TreeNode *root, TreeNode *cur, int k)
{
    if (cur == NULL)
        return false;
    return search(root, cur, k - cur->val) || dfs(root, cur->left, k) || dfs(root, cur->right, k);
}

bool search(TreeNode *root, TreeNode *cur, int value)
{
    if (root == NULL)
        return false;
    return (root->val == value) && (root != cur) || (root->val < value) && search(root->right, cur, value) || (root->val > value) && search(root->left, cur, value);
}