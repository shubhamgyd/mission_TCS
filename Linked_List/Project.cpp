#include<bits/stdc++.h>
using namespace std;

// template<class T>
struct Node
{
    int val;
    Node *next,*prev;
    int cal;
    Node(int data)
    {
        val=data;
        next=NULL;
        prev=NULL;
    }
};

void Insert_to_Start(Node *&head,int data)
{
    Node *temp=new Node(data);
    temp->next=head;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        head->prev=temp;
        head=temp;
    }
    head->cal++;
}


void Insert_to_End(Node *&head,int data)
{
    Node *temp=new Node(data);
    Node *curr=head;
    temp->next=NULL;
    if(head==NULL)
    {
        temp->prev=NULL;
        head=temp;
        return;
    }
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=temp;
    temp->prev=curr;
    head->cal++;
    return;
}

void Insert_After(Node *&head,int target,int data)
{
    Node *temp=new Node(data);
    if(head->val==target)
    {
        temp->next=head->next;
        head->next=temp;
        temp->prev=head;
        if(temp->next!=NULL)
        {
            temp->next->prev=temp;
        }
        head->cal++;
        return;
    }
    Node* curr=head;
    while(curr->val!=target)
    {
        curr=curr->next;
    }
    temp->next=curr->next;
    curr->next=temp;
    temp->prev=curr;

    if(temp->next!=NULL)
    {
        temp->next->prev=temp;
    }
    head->cal++;
    return;

}

void Insert_Before(Node *&head,int target,int val)
{
    Node *curr= new Node(val);
    if(head->val==target)
    {
        Insert_to_Start(head,val);
    }
    Node* temp=head;
    while(temp->next->val!=target)
    {
        temp=temp->next;
    }
    curr->next=temp->next;
    temp->next=curr;
    curr->prev=temp;
    if(curr->next!=NULL)
    {
        curr->next->prev=curr;
    }
    head->cal++;
    return;

}
void Insert_at_n(Node *&head,int n,int data)
{
    Node* curr=new Node(data);
    if(n==1)
    {
        Insert_to_Start(head,data);
        return;
    }
    int num=head->cal;
    if(n>num)
    {
        Insert_to_End(head,data);
        return;
    }

    Node* temp=head;
    for(int i=0;i<n-2;i++)
    {
        temp=temp->next;
    }
    curr->next=temp->next;
    temp->next=curr;
    curr->prev=temp;
    if(curr->next!=NULL)
    {
        curr->next->prev=curr;
    }
    head->cal++;
    return;
}

void Remove_Element(Node *&head,int val)
{
    if(head->val==val)
    {
        Node* temp=head;
        head=head->next;
        head->prev=NULL;
        delete(temp);
        head->cal--;
        return;
    }
    Node* temp=head;
    while(temp->next->val!=val)
    {
        temp=temp->next;
    }
    temp->next=temp->next->next;
    temp->next->next->prev=temp;
    head->cal--;
    return;
}



void printList(Node* node)
{
    Node* last;
    cout<<"\nTraversal in forward direction \n";
    while (node != NULL)
    {
        cout<<" "<<node->val<<" ";
        last = node;
        node = node->next;
    }
 
    cout<<"\nTraversal in reverse direction \n";
    while (last != NULL)
    {
        cout<<" "<<last->val<<" ";
        last = last->prev;
    }
}

int32_t main()
{

    struct Node *head=NULL;
    struct Node *tail=NULL;
    Insert_to_Start(head,1);
    printList(head);
    Insert_to_Start(head,2);
    printList(head);
    Insert_to_End(head,3);
    printList(head);
    Insert_After(head,2,4);
    printList(head);
    Insert_After(head,1,5);
    printList(head);
    Insert_at_n(head,3,6);
    printList(head);
    Insert_Before(head,6,7);
    printList(head);
    Insert_at_n(head,1,7);
    printList(head);
    Remove_Element(head,2);
    printList(head);

    return 0;
}