// In this problem we are going to construct the binary tree from paranthesis string

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left,*right;
};


// Creating new node of the string integer
Node* newNode(int data)
{
    Node* root=(Node*)malloc(sizeof(Node));
    root->data=data;
    root->left=root->right=NULL;
    return root;
}


// Finding the balance point 
// where index represent the end of leftsubtree i.e till index-1 and starting the right subtree i.e from index+2 
int findIndex(string str,int start,int end)
{
    // Here we uses stack to store the parenthesis
    // we appending and popping until stack becomes empty
    // i.e until we get balanced point
    stack<char>st;
    for(int i=start;i<=end;i++)
    {
        if(str[i]=='(')
        {
            st.push(str[i]);
        }
        else if(str[i]==')')
        {
            st.pop();
            if(st.empty())
            {
                return i;
            }
        }
    }
    return -1;
}

Node* ConstructTree(string str,int start,int end)
{
    // Base condition
    if(start>end)
    {
        return NULL;
    }

    if(str[start]=='(' || str[start]==')')
    {
        return NULL;
    }

    // creating new node 
    Node *root=newNode(str[start]-'0');
    // If only one node
    if(start==end)
    {
        return root;
    }

    // to find the balance index 
    int index=findIndex(str,start+1,end);
    root->left=ConstructTree(str,start+2,index-1);
    root->right=ConstructTree(str,index+2,end-1);
    return root;
}

void preorder(Node* root)
{
    if(!root)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    string str="4(2(3)(1))(6(5))";
    Node *root=ConstructTree(str,0,str.length()-1);
    preorder(root);
}