#include<bits/stdc++.h>
using namespace std;



struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

// Simply merge sort
class Solution{
    Node* mergeSort(Node* a,Node* b)
    {
        Node* result=NULL;
        if(a==NULL)
        {
            return b;
        }
        else if(b==NULL)
        {
            return a;
        }
        if(a->data<=b->data)
        {
            result=a;
            result->next=mergeSort(a->next,b);
        }
        else
        {
            result=b;
            result->next=mergeSort(a,b->next);
        }
        return result;
    }
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           for(int i=1;i<K;i++)
           {
               // Store the address of first node of sorted linked list 
               arr[0]=mergeSort(arr[0],arr[i]);
           }
           return arr[0];
    }
};