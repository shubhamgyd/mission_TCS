// In this program we are going to check , wheater the all levels are anagram or not
// or we can say that if the given tree are mirror treee or not

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    struct Node *left, *right;
    int data;
};
  

// Utility function to create a new tree Node
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

bool areAnagrams(Node* root1,Node* root2)
{
    if(root1==NULL && root2==NULL)
    {
        return true;
    }
    if(root1==NULL || root2==NULL)
    {
        return false;
    }
    queue<Node*>q1,q2;
    q1.push(root1);
    q2.push(root2);
    while(1)
    {
        int n1=q1.size();
        int n2=q2.size();
        
        if(n1!=n2)
        {
            return false;
        }
        if(n1==0)
        {
            break;
        }
        vector<int>v1,v2;
        while(n1>0)
        {
            Node *curr=q1.front();
            q1.pop();
            if(curr->left!=NULL)
            {
                q1.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                q1.push(curr->right);
            }
            n1--;


            Node* curr1=q2.front();
            q2.pop();
            if(curr1->left!=NULL)
            {
                q2.push(curr1->left);
            }
            if(curr1->right!=NULL)
            {
                q2.push(curr1->right);
            }

            v1.push_back(curr->data);
            v2.push_back(curr1->data);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        if(v1!=v2)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    // Constructing both the trees.
    struct Node* root1 = newNode(1);
    root1->left = newNode(3);
    root1->right = newNode(2);
    root1->right->left = newNode(5);
    root1->right->right = newNode(4);
  
    struct Node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);
  
    areAnagrams(root1, root2)? cout << "Yes" : cout << "No";
    return 0;
}