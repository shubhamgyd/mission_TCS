/*
1...If left child is null, print the current node data. Move to right child. 
….Else, Make the right child of the inorder predecessor point to the current node. Two cases arise: 
………a) The right child of the inorder predecessor already points to the current node. Set right child to NULL. Move to right child of current node. 
………b) The right child is NULL. Set it to current node. Print current node’s data and move to left child of current node. 
2...Iterate until current node is not NULL.
Following is the implementation of the above algorithm.
*/

// Moris Preorder Traversal

#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data)
{
    Node* root= new Node();
    root->data=data;
    root->left=root->right=NULL;
    return root;
}



void MorrisTraversalPreorder(Node* root)
{
    while(root!=NULL)
    {
        // If left subtree absent
        if(root->left==NULL)
        {
            cout<<root->data<<" ";
            root=root->right;
        }


        else
        {

            // Find the preorder predecessor of the current node, while traversing the root->left->right
            // Subtree , until we don't get right as a NULL or root node
            Node* current=root->left;
            while(current->right!=NULL && current->right!=root)
            {
                current=current->right;
            }


            // If we get the right child of the current node as null , then print the root data
            // and simply move root to the left , for further iteration and generate the safe link  between preorder
            // predecessor to the root node
            if(current->right==NULL)
            {
                cout<<root->data<<" ";
                current->right=root;
                root=root->left;
            }
            
            // else if we get the right child of the current as a root , then we have already visited the
            // left subtree of root node, then remove the safe link between preorder predecessor and root node
            else
            {
                current->right=NULL;
                root=root->right;
            }   // End of pre condition current->right==NULL
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
    Node* root=newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
 
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    root->right->left = newNode(6);
    root->right->right = newNode(7);
 
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
 
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(11);
 
    MorrisTraversalPreorder(root);
 
    return 0;

}