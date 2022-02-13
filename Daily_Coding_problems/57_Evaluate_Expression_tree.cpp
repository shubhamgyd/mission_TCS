/*
This problem was asked by Microsoft.

Suppose an arithmetic expression is given as a binary tree. 
Each leaf is an integer and each internal node is one of '+', '−', '∗', or '/'.

Given the root to such a tree, write a function to evaluate it.

For example, given the following tree:
*/


#include<bits/stdc++.h>
using namespace std;

struct Node
{
    string val;
    Node* left;
    Node* right;
    // Node()
    // {
    //     val=0;
    //     left=NULL;
    //     right=NULL;
    // }
    Node(string data)
    {
        val=data;
        left=NULL;
        right=NULL;
    }
};


int toInt(string s)
{
    int num = 0;
         
    // Check if the integral value is
    // negative or not
    // If it is not negative, generate the number
    // normally
    if(s[0]!='-')
        for (int i=0; i<s.length(); i++)
            num = num*10 + (int(s[i])-48);
    // If it is negative, calculate the +ve number
    // first ignoring the sign and invert the
    // sign at the end
    else
        for (int i=1; i<s.length(); i++)
        {
            num = num*10 + (int(s[i])-48);
            num = num*-1;
        }
     
    return num;
}

int Evaluate(Node* root)
{
    if(!root)
    {
        return 0;
    }
    if(!root->left  && !root->right)
    {
        return toInt(root->val);
    }
    int left=Evaluate(root->left);
    int right=Evaluate(root->right);

    if(root->val=="+")
    {
        return left+right;
    }
    if(root->val=="-")
    {
        return left-right;
    }    
    if(root->val=="*")
    {
        return left*right;
    }
    return left/right;

}


int main()
{
    Node *root = new Node("+");
    root->left = new Node("*");
    root->left->left = new Node("5");
    root->left->right = new Node("-4");
    root->right = new Node("-");
    root->right->left = new Node("100");
    root->right->right = new Node("20");
    cout << Evaluate(root) << endl;
}