#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    char data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char ch)
    {
        data = ch;
        left = NULL;
        right = NULL;
    }
};

TreeNode *insertNodes(TreeNode *root, char ch)
{
    TreeNode *newNode = new TreeNode(ch);
    if (root == NULL)
    {
        root = newNode;
        return root;
    }
    else if (root->data > ch)
    {
        root->left = insertNodes(root->left, ch);
    }
    else
    {
        root->right = insertNodes(root->right, ch);
    }
    return root;
}

void preOrder(TreeNode *root, vector<TreeNode *> &res)
{
    if (root)
    {
        preOrder(root->left, res);
        cout << root->data << " ";
        res.push_back(root);
        preOrder(root->right, res);
    }
}

TreeNode *solve(vector<TreeNode *> &res, int i, int j)
{
    // base case
    if (i > j)
    {
        return NULL;
    }
    int mid = (i + j) / 2;
    TreeNode *root = res[mid];
    root->left = solve(res, i, mid - 1);
    root->right = solve(res, mid + 1, j);

    return root;
}

TreeNode *buildTree(vector<TreeNode *> &res)
{
    int n = res.size();
    return solve(res, 0, n - 1);
}

int main()
{
    TreeNode *root = NULL;
    vector<char> data = {'K', 'E', 'B', 'A', 'D', 'G', 'F', 'H', 'J', 'T', 'P', 'L', 'S', 'W', 'U', 'X', 'Y'};
    for (int i = 0; i < data.size(); i++)
    {
        root = insertNodes(root, data[i]);
    }

    vector<TreeNode *> res;
    preOrder(root, res);
    cout << endl;
    TreeNode *newRoot = buildTree(res);
    queue<TreeNode *> q;
    q.push(newRoot);
    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            auto it = q.front();
            q.pop();
            cout << it->data << " ";
            if (it->left)
            {
                q.push(it->left);
            }
            if (it->right)
            {
                q.push(it->right);
            }
        }
        cout << endl;
    }
    return 0;
}