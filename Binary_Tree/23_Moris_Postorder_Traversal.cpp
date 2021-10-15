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

//This is Post Order :children before node( L ,R , N)
void morrisPostorderTraversal(Node *root){

// Making our tree left subtree of a dummy Node
Node *dummyRoot = new Node();
dummyRoot->left = root;

//Think of P as the current node 
Node *p = dummyRoot, *pred, *first, *middle, *last;
while(p!=NULL){        

    if(p->left == NULL){
        p = p->right;
    } else{
        /* p has a left child => it also has a predeccessor
           make p as right child predeccessor of p    
        */
        pred = p->left;
        while(pred->right!=NULL && pred->right != p){
            pred = pred->right;
        }

        if(pred->right == NULL){ 

            // predeccessor found for first time
            // modify the tree

            pred->right = p;    
            p = p->left;

        }else {                          

           // predeccessor found second time
           // reverse the right references in chain from pred to p
            first = p;
            middle = p->left;              
            while(middle!=p){            
                last = middle->right;
                middle->right = first;
                first = middle;
                middle = last;
            }

            // visit the nodes from pred to p
            // again reverse the right references from pred to p    
            first = p;
            middle = pred;
            while(middle!=p){

                cout<<" "<<middle->data;  
                last = middle->right;          
                middle->right = first;
                first = middle;
                middle = last;
            }

            // remove the pred to node reference to restore the tree structure
            pred->right = NULL;    
            p = p-> right;
        }
    }
}    
}


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
 
    morrisPostorderTraversal(root); 
    return 0;

}