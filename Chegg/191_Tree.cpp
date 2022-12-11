#include <bits/stdc++.h>
using namespace std;

struct Tree
{
    string data;
    Tree *left, *right;
    Tree(string val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Tree *insert(vector<string> &arr, int i, int n)
{
    Tree *root = NULL;
    // Base case for recursion
    if (i < n)
    {
        // Generate root
        root = new Tree(arr[i]);
        // insert left child
        root->left = insert(arr, 2 * i + 1, n);
        // insert right child
        root->right = insert(arr, 2 * i + 2, n);
    }
    return root;
}

void inorder(Tree *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    vector<string> arr = {"Karen", "Tom", "Bob", "Wendy", "Alan", "Ellen", "Kelly"};
    int n = arr.size();
    Tree *root = insert(arr, 0, n);
    queue<Tree *> q;
    q.push(root);
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        cout << it->data << " ";
        if (it->left)
            q.push(it->left);
        if (it->right)
            q.push(it->right);
    }
    cout << endl;
    inorder(root);
    return 0;
}