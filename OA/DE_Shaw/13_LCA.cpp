#include <bits/stdc++.h>
using namespace std;

struct BstNode
{
    int data;
    BstNode *left;
    BstNode *right;
};

BstNode *LCA(BstNode *root, int a, int b)
{
    if (!root)
    {
        return NULL;
    }
    if (root->data == a or root->data == b)
    {
        return root;
    }
    BstNode *left = LCA(root->left, a, b);
    BstNode *right = LCA(root->right, a, b);
    if (left and right)
    {
        return root;
    }
    if (left)
    {
        return left;
    }
    return right;
}

int dist(BstNode *root, int node, int steps)
{
    if (!root)
    {
        return -1;
    }
    if (root->data == node)
    {
        return steps;
    }
    int level = dist(root->left, node, steps + 1);
    if (level != -1)
    {
        return level;
    }
    return dist(root->right, node, steps + 1);
}

int distanceNodes(BstNode *root, int a, int b)
{
    BstNode *lca = LCA(root, a, b);
    int d1 = dist(lca, a, 0);
    int d2 = dist(lca, b, 0);
    return d1 + d2;
}