#include <iostream>
using namespace std;

struct Tree
{
    int data;
    Tree *left, *right;
    Tree(int val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }
};

// Function which insert node into BST at appropriate manner
Tree *insertNode(Tree *root, int val)
{
    // if root is null
    // generate new Node and mark it as a root
    if (root == NULL)
    {
        Tree *newNode = new Tree(val);
        root = newNode;
        return root;
    }
    // if value is less than or equal to the root value then iterate in left subtree
    else if (val <= root->data)
    {
        root->left = insertNode(root->left, val);
    }
    // else iterate in right subtree
    else
    {
        root->right = insertNode(root->right, val);
    }
    return root;
}

// Function which return the minimum value of node
int minNode(Tree *root)
{
    int value = root->data;
    while (root->left != NULL)
    {
        value = root->left->data;
        root = root->left;
    }
    return value;
}

Tree *deleteNode(Tree *root, int val)
{
    // if root value is null
    if (root == NULL)
    {
        return root;
    }
    // if value is less than the root of data , search in left subtree
    else if (val < root->data)
    {
        root->left = deleteNode(root->left, val);
    }
    // if value is greater than the root of data, search in right subtree
    else if (val > root->data)
    {
        root->right = deleteNode(root->right, val);
    }
    // Get ready to delete
    else
    {
        // case 1: No child
        if (root->left == NULL and root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        // case 2: one child
        else if (root->left == NULL)
        {
            Tree *currNode = root;
            root = root->right;
            delete currNode;
        }
        // delete currentNode and return the left of root
        else if (root->right == NULL)
        {
            Tree *currNode = root;
            root = root->left;
            delete currNode;
        }
        // Case 3: Two children
        else
        {
            // get minimum from the rightSubtree
            // assign it at the place of deleted node
            // and delete this value from the right subtree to maintain the BST structure
            int mnValue = minNode(root->right);
            root->data = mnValue;
            root->right = deleteNode(root->right, mnValue);
        }
    }
    // Finally return the root
    return root;
}
// Print inorder traversal of given tree
void inorderTraversal(Tree *root)
{
    if (!root)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main()
{
    Tree *root = NULL;
    /*
          10
        /   \
       5    15
      /\
     4  6
    */
    // Tree Structure
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 4);
    root = insertNode(root, 6);
    root = insertNode(root, 15);
    // Display Tree Structure before deleting keys
    cout << "Inorder traversal before deleting keys: ";
    inorderTraversal(root);
    cout << endl;
    cout << "Inorder traversal after deleting keys\n";
    root = deleteNode(root, 5);
    cout << "Tree after deleting node " << 5 << ": ";
    inorderTraversal(root);
    cout << endl;
    root = deleteNode(root, 15);
    cout << "Tree after deleting node " << 15 << ": ";
    inorderTraversal(root);
    cout << endl;
    return 0;
}