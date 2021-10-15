#include<bits/stdc++.h>
using namespace std;


typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

// A Stack has array of Nodes, capacity, and top
typedef struct Stack
{
    int top;
    int capacity;
    Node* *array;
} Stack;

Node* bst(int pre[],int& index, int limit,int size)
{
    if(index>=size|| pre[index]>limit) return NULL;
    //Node* root= new Node(pre[index++]);
    struct Node* root=(struct Node*)malloc(sizeof(struct Node));
    root->data=pre[index++];
    root->left=bst(pre,index,root->data,size);
    root->right=bst(pre,index,limit,size);
    return root;
}

Node* constructTree(int pre[], int size)
{
    //code here
    int index=0;
    return bst(pre,index,INT_MAX,size);
}