// driver code

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}


Node* reverse(Node* ptr)
{
    Node* temp;
    Node* prev = NULL;
    while (ptr != NULL) 
    {
        temp = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = temp;
    }
    return prev;
}

void reverse_last(Node* head, int n)
{
    int n = length(head);
    Node* e = head;
    for (int i = 0; i < n-5-1; i++)
        e = e->next;
    e->next = reverse(e->next);
}


static void reverseKNodes(struct Node** head_ref, int k)
{

    struct Node* temp = *head_ref;
    int count = 1;
    while (count < k) {
        temp = temp->next;
        count++;
    }
 
    struct Node* joint_point = temp->next;
    temp->next = NULL;
 
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
 
    *head_ref = prev;
    current = *head_ref;
    while (current->next != NULL)
        current = current->next;
    current->next = joint_point;
}

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node =
          (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int length(Node* head)
{
    int n = 0;
    for (Node* curr = head; curr != NULL; curr = curr->next)
        n++;
    return n;
}


void Reverse(Node* head)
{
    int l=length(head);
    int k=l/2-1;
    reverseKNodes(&head,k);
    reverse_last(head,k);
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}


 // } Driver Code Ends
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        Node *slow=head,*fast=head;
        // slow=slow->next;
        // fast=fast->next;
        if(head==NULL || head->next==NULL)
        {
            return;
        }
        while(fast!=NULL &&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                break;   
            }
            
        }
        if(slow==head)
        {
            while(slow->next!=head)
            {
                slow=slow->next;
            }
            slow->next=NULL;
        }
        
        if(slow==fast)
        {
            slow=head;
            while(slow->next!=fast->next)
            {
                if(slow==fast->next)
                {
                    fast->next=NULL;
                }
                slow=slow->next;
                fast=fast->next;
            }
            fast->next=NULL;
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        ob.removeLoop(head);
        
        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}
  // } Driver Code Ends