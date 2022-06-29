

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T val;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    vector<int> res;
    if (!root)
        return res;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            auto it = q.front();
            q.pop();
            res.push_back(it->val);
            if (it->left)
            {
                q.push(it->left);
            }
            if (it->right)
            {
                q.push(it->right);
            }
        }
    }
    return res;
}
// T:O(n)
// S:O(n)