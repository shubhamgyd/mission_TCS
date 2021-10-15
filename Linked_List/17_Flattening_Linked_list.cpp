// C program for flattening a linked list 
#include<bits/stdc++.h>
using namespace std;
typedef struct Node 
{ 
	int data; 
	struct Node *right; 
	struct Node *down; 
} Node; 

/* A utility function to insert a new node at the begining 
of linked list */
void push (Node** head_ref, int new_data) 
{ 
	/* allocate node */
	Node* new_node = (Node *) malloc(sizeof(Node)); 
	new_node->right = NULL; 

	/* put in the data */
	new_node->data = new_data; 

	/* link the old list off the new node */
	new_node->down = (*head_ref); 

	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 

/* Function to print nodes in the flattened linked list */
void printList(Node *node) 
{ 
	while (node != NULL) 
	{ 
		printf("%d ", node->data); 
		node = node->down; 
	} 
} 

// A utility function to merge two sorted linked lists 
Node* merge( Node* a, Node* b ) 
{ 
	// If first list is empty, the second list is result 
	if (a == NULL) 
		return b; 

	// If second list is empty, the second list is result 
	if (b == NULL) 
		return a; 

	// Compare the data members of head nodes of both lists 
	// and put the smaller one in result 
	Node* result; 
	if (a->data < b->data) 
	{ 
		result = a; 
		result->down = merge( a->down, b ); 
	} 
	else
	{ 
		result = b; 
		result->down = merge( a, b->down ); 
	} 

	return result; 
}
typedef pair<int, int> pi;
Node *flatten(Node *root)
{
    int n=0,x;
    Node *a=root,*ans=NULL,*t;
    vector<Node *> head;
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    while(a!=NULL){
        head.push_back(a);
        pq.push(make_pair(a->data,n));
        n++;
        a=a->right;
    }
    while(!pq.empty()){
        pi p=pq.top();
        pq.pop();
        a=(struct Node *)malloc(sizeof(struct Node));
        a->data=p.first;
        a->down=a->right=NULL;
        if(head[p.second]->down!=NULL){
            x=head[p.second]->down->data;
            head[p.second]=head[p.second]->down;
            pq.push(make_pair(x,p.second));
        }
        if(ans==NULL){
            t=ans=a;
        }
        else{
            t->down=a;
            t=a;
        }
    }
    return ans;
}
// Driver program to test above functions 
int main() 
{ 
	Node* root = NULL; 

	/* Let us create the following linked list 
	5 -> 10 -> 19 -> 28 
	| |	 |	 | 
	V V	 V	 V 
	7 20 22 35 
	|		 |	 | 
	V		 V	 V 
	8		 50 40 
	|			 | 
	V			 V 
	30			 45 
	*/
	push( &root, 30 ); 
	push( &root, 8 ); 
	push( &root, 7 ); 
	push( &root, 5 ); 

	push( &( root->right ), 20 ); 
	push( &( root->right ), 10 ); 

	push( &( root->right->right ), 50 ); 
	push( &( root->right->right ), 22 ); 
	push( &( root->right->right ), 19 ); 

	push( &( root->right->right->right ), 45 ); 
	push( &( root->right->right->right ), 40 ); 
	push( &( root->right->right->right ), 35 ); 
	push( &( root->right->right->right ), 20 ); 

	// Let us flatten the list 
	root = flatten(root); 

	// Let us print the flatened linked list 
	printList(root); 

	return 0; 
} 