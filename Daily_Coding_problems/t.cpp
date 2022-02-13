#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;
    Node *nextRight;

    Node() : value(0), left(NULL), right(NULL), nextRight(NULL) {}

    Node(int _val) : value(_val), left(NULL), right(NULL), nextRight(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : value(_val), left(_left), right(_right), nextRight(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        Node *pre = root, *cur;
        while (pre)
        {
            cur = pre;
            while (cur && cur->left)
            {
                cur->left->nextRight = cur->right;
                if (cur->nextRight)
                {
                    cur->right->nextRight = cur->nextRight->left;
                }
                cur = cur->nextRight;
            }
            pre = pre->left;
        }
        return root;
    }
};

Node* connectNeighbour(Node *node)
{
    Node *now, *tail, *head;
    
    now = node;
    head = tail = NULL;
    while(now)
    {
        if (now->left)
            if (tail) tail = tail->nextRight =now->left;
            else head = tail = now->left;
        if (now->right)
            if (tail) tail = tail->nextRight =now->right;
            else head = tail = now->right;
        if(!(now = now->nextRight))
        {
            now = head;
            head = tail=NULL;
        }
    }
    return node;
}

int main()
{
}