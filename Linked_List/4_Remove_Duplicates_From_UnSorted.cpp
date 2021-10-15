
#include<bits/stdc++.h>
using namespace std;


struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
        unordered_set<int>st;
        Node* temp=head;
        st.insert(temp->data);
        while(temp->next!=NULL)
        {
            if(st.find(temp->next->data)!=st.end())
            {
                temp->next=temp->next->next;
            }
            else
            {
                
                temp=temp->next;
                st.insert(temp->data);
            }
        }
        return head;
    }
};