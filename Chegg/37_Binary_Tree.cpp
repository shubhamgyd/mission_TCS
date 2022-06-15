#include <iostream>
#include<queue>
using namespace std;


// Structure of Tree
struct Node
{
    int val;
    Node *left;
    Node *right;

    // Paramatarize constructor
    Node(int data)
    {
        this->val=data;
        this->left=NULL;
        this->right=NULL;
    }
};



// Utility Function return, wheather given tree is maxHeap or not
bool maxHeap(Node* root)
{
    // base case
    // if tree is empty then return  true
    if(!root) return true;


    // queue data structure for level order traversal
    queue<Node*>q;
    q.push(root);                     // push root node into queue

    // indicator which indicates the left child is empty of right child is less than the root node
    bool noneSeen=false;

    // Iterate until the queue is empty or until tree is traversed
    while(!q.empty())
    {
        // parent node
        auto node=q.front();
        q.pop();


        // if parent node have left child
        if(node->left)
        {
            // according to the heap property ( max heap)
            // check wheather left child data is less or not 
            // if it violates the propery then return false


            // or check left child is empty or not
            if(noneSeen or node->left->val>=node->val)
            {
                return false;
            }

            // push the left child into the queue
            q.push(node->left);
        }

        // indicates that left child is empty
        else
        {
            noneSeen=true;
        }


        // if the parent have right child
        if(node->right)
        {
            // according to the heap property ( max heap)
            // check wheather right child data is less or not 
            // if it violates the propery then return false


            // or check right child is empty or not
            if(noneSeen or node->right->val>=node->val)
            {
                return false;
            }

            // push the right child into queue
            q.push(node->right);
        }
        else
        {
            // indiactes that right child is emoty
            noneSeen=true;
        }
    }

    //  if given tree satisfies all the conditions required to maintain maxHeap
    // then return truel
    return true;
}

// Utility Function return, wheather given tree is minHeap or not
bool minHeap(Node* root)
{
    // base case
    // if tree is empty then return  true
    if(!root) return true;


    // queue data structure for level order traversal
    queue<Node*>q;
    q.push(root);                     // push root node into queue


    // indicator which indicates the left child is empty of right child is less than the root node
    bool noneSeen=false;


    // Iterate until the queue is empty or until tree is traversed
    while(!q.empty())
    {
        // parent node 
        auto node=q.front();
        q.pop();



        // if parent node have left child
        if(node->left)
        {
            // according to the heap property ( max heap)
            // check wheather left child data is less or not 
            // if it violates the propery then return false

            // or check left child is empty or not

            if(noneSeen or node->left->val<=node->val)
            {
                return false;
            }


            // push the left child into the queue
            q.push(node->left);
        }

        
        else
        {
            // indicates that left child is empty
            noneSeen=true;
        }



        // if the parent have right child
        if(node->right)
        {
            // according to the heap property ( max heap)
            // check wheather right child data is less or not 
            // if it violates the propery then return false


            // or check right child is empty or not
            if(noneSeen or node->right->val<=node->val)
            {
                return false;
            }

            // push the right child into queue
            q.push(node->right);
        }
        else
        {
            // indiactes that right child is emoty
            noneSeen=true;
        }
    }

    //  if given tree satisfies all the conditions required to maintain maxHeap
    // then return truel
    return true;
    
}


void preOrder(Node* root)
{
    if(!root)
    {
        return;
    }
    // printing data
    cout<<root->val<<" ";
    preOrder(root->left);      // left subtree
    preOrder(root->right);     // right subtree
}

int main()
{
    // Tree Representation
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);


    // check given tree is minHeap or not
    bool isMinHeap=minHeap(root);


    // check given tree is maxHeap or not
    bool isMaxHeap=maxHeap(root);

    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Given Tree is: ";
    preOrder(root);    // printing preorder Traversal
    if(isMinHeap)
    {
        cout<<"\nGiven Tree is minHeap"<<endl;
    }
    else if(isMaxHeap)
    {
        cout<<"\nGiven Tree is maxHeap"<<endl;
    }
    else
    {
        cout<<"\nGiven Tree neight minHeap nor maxHeap"<<endl;
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    return 0;
}
// Time Complexity :O(nodes)
// Space Complexity :O(nodes)