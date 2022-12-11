#include <stdio.h>
#include <stdlib.h>

// Structure of BST
struct Tree
{
    // for data
    int data;
    // for left subtree
    struct Tree *left;
    // for right subtree
    struct Tree *right;
};

// Function to insert data into BST
struct Tree *insert(struct Tree *root, int val)
{
    // generate newNode
    struct Tree *newNode = (struct Tree *)malloc(sizeof(struct Tree));
    // put data into newNode
    newNode->data = val;
    // mark left and right as NULL
    newNode->left = NULL;
    newNode->right = NULL;
    // if root is null
    // then update root as newNode
    if (root == NULL)
    {
        root = newNode;
        return root;
    }
    // if value is belongs to the left subtree
    else if (val <= root->data)
    {
        root->left = insert(root->left, val);
    }
    // else value is belongs to the right subtree
    else
    {
        root->right = insert(root->right, val);
    }
    // return update root
    return root;
}

// Display data in increasing order
void display(struct Tree *root)
{
    if (root != NULL)
    {
        // go to the left
        display(root->left);
        // Print data
        printf("%d ", root->data);
        // go to the right
        display(root->right);
    }
}

int main()
{
    // Generate BST
    struct Tree *root = NULL;
    // Insert data
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 8);
    root = insert(root, 7);
    /*
                    5
                 /      \
                3        8
              /        /
             1        7
            / \
           1   2

    */
    // Display data
    printf("Inorder Traversal: ");
    display(root);
    return 0;
}