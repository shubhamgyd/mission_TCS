#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left,*right;
};

void inorder(Node* root,vector<int>&arr)
{
	if(!root)
	{
		return;
	}
	inorder(root->left,arr);
	arr.push_back(root->data);
	inorder(root->right,arr);
}

Node* newNode(int data)
{
	Node* node=new Node();
	node->data=data;
	node->left=node->right=NULL;
	return node;
}

Node* ArrToBST(int arr[],int i,int j)
{
	if(i>j)
	{
		return NULL;
	}
	int mid=(i+j)/2;
	Node* root=newNode(arr[mid]);
	root->left=ArrToBST(arr,i,mid-1);
	root->right=ArrToBST(arr,mid+1,j);
	return root;
}

Node* Merge(Node* root1,Node* root2)
{
	vector<int>v1;
	vector<int>v2;

	inorder(root1,v1);
	inorder(root2,v2);

	int m=v1.size();
	int n=v2.size();
	int MergedArr[m+n];
	int i=0,j=0,k=0;
	while(i<m && j<n)
	{
		if(v1[i]<v2[j])
		{
			MergedArr[k++]=v1[i++];
		}
		else
		{
			MergedArr[k++]=v2[j++];
		}
	}
	while(i<m)
	{
		MergedArr[k++]=v1[i++];
	}
	while(j<n)
	{
		MergedArr[k++]=v2[j++];
	}

	return ArrToBST(MergedArr,0,m+n-1);
}

void inorder(Node* root)
{
	if(!root)
	{
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	Node *root1 = newNode(100);
    root1->left     = newNode(50);
    root1->right = newNode(300);
    root1->left->left = newNode(20);
    root1->left->right = newNode(70);
 
    /* Create following tree as second balanced BST
            80
        / \
        40 120
    */
    Node *root2 = newNode(80);
    root2->left     = newNode(40);
    root2->right = newNode(120);
	Node* mergeTree=Merge(root1,root2);
	cout<<"Following is the inorder traversal of the newly Merged "
	    << "  Tree:  ";
	inorder(mergeTree);
}

/*
Time Complexity: O(m+n)
*/

/*
Another Approach : with O(h1+h2) space
by using stack 




// 1. First, push all the elements from root to the left-most leaf node onto a stack. 
//    Do this for both trees 
// 2. Peek at the top element of each stack (if non-empty) and print the smaller one. 
// 3. Pop the element off the stack that contains the element we just print 
// 4. Add the right child of the element we just popped onto the stack, as well as all its 
//    left descendants

void insertNodes(Node *root,stack<Node *> &s){
    
    
    while(root!=NULL){
        s.push(root);
        root=root->left;
    }
    
}
void merge(Node *root1, Node *root2)
{
   stack<Node *> s1;
   stack<Node *> s2;
   
   // 1.First, push all the elements from root to the left-most leaf node onto a stack. Do this for both trees 
   insertNodes(root1,s1);
   insertNodes(root2,s2);
   
   while(!s1.empty() || !s2.empty()){
       
       // 2. Peek at the top element of each stack (if non-empty) and print the smaller one. 
       // If one the stack empty assign INT_MAX to value coming from that stack
       int a=(!s1.empty() ? s1.top()->data:INT_MAX);
       int b=(!s2.empty() ? s2.top()->data:INT_MAX);
       
       if(a<=b){
           cout<<a<<" ";
           Node *temp=s1.top();

           //3. Pop the element off the stack that contains the element we just printed
           s1.pop();
           
           //4. Add the right child of the element we just popped onto the stack, as well as all its left descendants
           insertNodes(temp->right,s1);
       }
       else{
           cout<<b<<" ";
           Node *temp=s2.top();

           //3. Pop the element off the stack that contains the element we just printed
           s2.pop();

           //4. Add the right child of the element we just popped onto the stack, as well as all its left descendants
           insertNodes(temp->right,s2);
           
       }
   }
}

*/