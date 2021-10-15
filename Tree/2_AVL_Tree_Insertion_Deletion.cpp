/*
AVL tree is a self-balancing Binary Search Tree (BST) where the difference between heights 
of left and right subtrees cannot be more than one for all nodes. 
*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    int height;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

Node* getNode(int data)
{
    Node* root=new Node(data);
    root->height=1;
    return root;
}

int Height(Node* root)
{
    if(!root)
    {
        return 0;
    }
    return 1+max(Height(root->left),Height(root->right));
}

int getBalance(Node* root)
{
    if(!root)
    {
        return 0;
    }
    return (Height(root->left)-Height(root->right));
}

Node* leftrotation(Node* root)
{
    Node* x=root->right;
    Node* y=x->left;

    x->left=root;
    root->right=y;

    x->height=1+max(Height(x->left),Height(x->right));
    root->height=1+max(Height(root->left),Height(root->right));

    return x;
}

Node* rightrotation(Node* root)
{
    Node* x=root->left;
    Node* t=x->right;

    x->right=root;
    root->left=t;

    root->height=1+max(Height(root->left),Height(root->right));
    x->height=1+max(Height(x->left),Height(x->right));

    return x;
}

Node* minNode(Node* root)
{
    Node* curr=root;
    while(curr->left!=NULL)
    {
        curr=curr->left;
    }
    return curr;
}

Node* insert(Node* root,int data)
{
    if(root==NULL)
    {
        return getNode(data);
    }
    if(data<root->data)
    {
        root->left=insert(root->left,data);
    }
    else if(root->data<data)
    {
        root->right=insert(root->right,data);
    }
    else
    {
        return root;
    }
    root->height=1+max(Height(root->left),Height(root->right));

    int balance=getBalance(root);

    // left left case
    if(balance>1 && data < root->left->data)
    {
        return rightrotation(root);
    }
    
    // right right case
    if(balance<-1 && data > root->right->data)
    {
        return leftrotation(root);
    }

    // left right case
    if(balance>1 && data > root->left->data)
    {
        root->left=leftrotation(root->left);
        return rightrotation(root);
    }

    // right left case
    if(balance<-1 && data < root->right->data)
    {
        root->right=rightrotation(root->right);
        return leftrotation(root);
    }

    return root;
}

Node* deleteNode(Node* root, int key)
{
     
    // STEP 1: PERFORM STANDARD BST DELETE
    if (root == NULL)
        return root;
 
    // If the key to be deleted is smaller
    // than the root's key, then it lies
    // in left subtree
    if ( key < root->data )
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is greater
    // than the root's key, then it lies
    // in right subtree
    else if( key > root->data )
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then
    // This is the node to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) )
        {
            Node *temp = root->left ?root->left : root->right;
 
            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
            *root = *temp; // Copy the contents of
                           // the non-empty child
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            Node* temp = minNode(root->right);
 
            // Copy the inorder successor's
            // data to this node
            root->data = temp->data;
 
            // Delete the inorder successor
            root->right = deleteNode(root->right,
                                     temp->data);
        }
    }
 
    // If the tree had only one node
    // then return
    if (root == NULL)
    return root;
 
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(Height(root->left),
                           Height(root->right));
 
    // STEP 3: GET THE BALANCE FACTOR OF
    // THIS NODE (to check whether this
    // node became unbalanced)
    int balance = getBalance(root);
 
    // If this node becomes unbalanced,
    // then there are 4 cases
 
    // Left Left Case
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightrotation(root);
 
    // Left Right Case
    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftrotation(root->left);
        return rightrotation(root);
    }
 
    // Right Right Case
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftrotation(root);
 
    // Right Left Case
    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightrotation(root->right);
        return leftrotation(root);
    }
 
    return root;
}

void print(Node* root)
{
    if(!root)
    {
        return;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

int main()
{
    Node* root=NULL;

    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,30);
    root=insert(root,40);
    root=insert(root,50);
    root=insert(root,25);


    print(root);
    root=deleteNode(root,25);
    cout<<endl;
    print(root);
}

/*
Time Complexity:  Insertion
    The rotation operations (left and right rotate) take constant time as only a 
few pointers are being changed there. Updating the height and getting the balance factor 
also takes constant time. So the time complexity of AVL insert remains same as BST insert 
which is O(h) where h is the height of the tree. Since AVL tree is balanced, the height is
 O(Logn). So time complexity of AVL insert is O(Logn).
*/

/*
Time Complexity: Deletion
    The rotation operations (left and right rotate) take constant time as only few 
pointers are being changed there. Updating the height and getting the balance factor also 
take constant time. So the time complexity of AVL delete remains same as BST delete which 
is O(h) where h is height of the tree. Since AVL tree is balanced, the height is O(Logn). 
So time complexity of AVL delete is O(Log n). 
*/