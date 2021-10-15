// Basically in this que we are dinding the hight of  a binary tree

#include<bits/stdc++.h>
using namespace std;


// struct to create tree metadata
struct BstNode {
        int data;
        BstNode* left;
        BstNode* right;
};

//Function to get the new node for inserting 
BstNode*  GetNewNode(int data){
       BstNode* newNode = new BstNode();
       newNode->data=data;
       newNode->left=NULL;
       newNode->right=NULL;
       return newNode;
}


// Function to insert new node in the tree
BstNode* Insert(BstNode* root,int data){
      if(root==NULL)
      {
              root=GetNewNode(data);
              return root;
      }
      else if(data<=root->data)
      {
              root->left=Insert(root->left,data);
      }
      else
      {
              root->right=Insert(root->right,data);
      }
      return root;
}

int diameter(BstNode* root,int& res)
{
    // Base condition of a root
    if(root==NULL)
    {
        return 0;
    }

    // Hypothesis step ..this both conditions wil find their task automatically , we don't have to think
    // it
    int l=diameter(root->left,res);
    int r=diameter(root->right,res);

    // Induction step .. here we have to implement some relation
    //like
    int temp=max(l,r)+1;
    int ans=max(temp,l+r+1);
    res=max(res,ans);
    return temp;
    
}

struct BstNode* newNode(int data)
{
    //BSTNode *node =(struct BSTNode*)malloc(sizeof(struct BSTNode));
    BstNode* node=(struct BstNode*)malloc(sizeof(struct BstNode));
    node->data = data;
    node->left = node->right = NULL;
 
    return (node);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // BstNode* root=NULL;
    // root=Insert(root,2);
    // root=Insert(root,4);
    // root=Insert(root,5);
    // root=Insert(root,1);
    // root=Insert(root,3);
    // root=Insert(root,8);
    // root=Insert(root,21);


    struct BstNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    int res=INT_MIN;
    diameter(root,res);
    cout<<"Diameter of a root is: "<<res<<'\n';
    return 0;
}