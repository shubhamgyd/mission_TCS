/*
Inorder Tree Traversal without recursion and without stack!

Moris Inorder Traversal 
*/


/*
1. Initialize current as root 
2. While current is not NULL
   If the current does not have left child
      a) Print current’s data
      b) Go to the right, i.e., current = current->right
   Else
      a) Find rightmost node in current left subtree OR
              node whose right child == current.
         If we found right child == current
             a) Update the right child as NULL of that node whose right child is current
             b) Print current’s data
             c) Go to the right, i.e. current = current->right
         Else
             a) Make current as the right child of that rightmost 
                node we found; and 
             b) Go to this left child, i.e., current = current->left
*/

#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* getNode(int data)
{
    Node* root= new Node();
    root->data=data;
    root->left=root->right=NULL;
    return root;
}



void MorrisTraversal(Node* root)
{
    Node *current, *pre;
    current=root;
    while(current!=NULL)
    {
        // If left subtree absent
        if(current->left==NULL)
        {
            cout<<current->data<<" ";
            current=current->right;
        }


        else
        {

            // Find the inorder predecessor of the current node, while traversing the current->left->right
            // Subtree , until we don't get right as a NULL or current node
            pre=current->left;
            while(pre->right!=NULL && pre->right!=current)
            {
                pre=pre->right;
            }


            // If we get the right of a pre as null, then create a safe link from pre to current
            // i.e pre->right=current
            // Move the current to the left for further links
            if(pre->right==NULL)
            {
                pre->right=current;
                current=current->left;
            }


            // if we get the right  of a pre as current , then we MUST to remove the safe link between
            // pre and current , by initialising the pre->right=NULL
            // and move the current  to the right
            else
            {
                pre->right=NULL;
                cout<<current->data<<" ";
                current=current->right;
            }   // End of pre condition pre->right==NULL
        }  // End of if condition current->left==NULL
    } // End of while loop
}
/*
Time Complexity : O(n) If we take a closer look, we can notice that every edge of the tree is 
traversed at most three times. And in the worst case, the same number of extra edges (as input tree)
are created and removed.
*/

int main()
{

    // Creat a binary tree
    Node* root=getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5); 
    MorrisTraversal(root);
    return 0;
}