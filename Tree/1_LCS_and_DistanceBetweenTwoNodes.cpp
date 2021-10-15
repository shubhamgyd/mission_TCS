// In this problem we are going to find the distance between of two nodes 
// Also the LCA of this two nodes

#include<bits/stdc++.h>
using namespace std;


struct BstNode {
        int data;
        BstNode* left;
        BstNode* right;
};
BstNode*  GetNewNode(int data){
       BstNode* newNode = new BstNode();
       newNode->data=data;
       newNode->left=NULL;
       newNode->right=NULL;
       return newNode;

}

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

BstNode* LCA(BstNode* root,int a,int b)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==a || root->data==b)
    {
        return root;
    }
    BstNode* leftlca=LCA(root->left,a,b);
    BstNode* rightlca=LCA(root->right,a,b);
    if(leftlca!=NULL && rightlca!=NULL)
    {
        return root;
    }
    if(leftlca!=NULL)
    {
        return leftlca;
    }
    return rightlca;
}

int level(BstNode* root,int k,int step)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root->data==k)
    {
        return step;
    }

    int lev=level(root->left,k,step+1);
    if(lev!=-1)
    {
        return lev;
    }
    return level(root->right,k,step+1);
}

int findDistance(BstNode* root, int a,int b)
{
    BstNode* lca=LCA(root,a,b);
    int d1=level(lca,a,0);
    int d2=level(lca,b,0);
    return d1+d2;
}


int main()
{
   BstNode* root=NULL;
   root=Insert(root,15);
   root=Insert(root,16);
   root=Insert(root,22);
   root=Insert(root,20);
   root=Insert(root,25);
   root=Insert(root,8);
   root=Insert(root,21);
   cout<<"Distance between two nodes "<<22<<" and"<<25<<" is: "<<findDistance(root,22,25)<<endl;

   return 0;
}