#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int val;
    Node * next;
    Node(int data){
        val = data;
        next = NULL;
    }
};

Node * createLL(int n){
    Node * head = NULL;
    Node * curr = NULL;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        Node * temp = new Node(a);
        if(curr == NULL){
            curr = temp;
            head = curr;
        }
        else{
            curr->next = temp;
            curr = curr->next;
        }
    }
    return head;
}

void print(Node * root){
    while(root != NULL){
        cout<<root->val<<" ";
        root = root->next;
    }
    cout<<endl;
}
Node * findMid(Node * root){
    Node * slow = root;
    Node * fast = root->next;
    while(fast != NULL && fast->next == NULL){
        slow = root->next;
        fast = root->next->next;
    }
    return slow;
}
Node * merge(Node * root1,Node * root2){
    Node * head1 = root1;
    Node * head2 = root2;
    
    Node * res = NULL;
    Node * curr = NULL;
    while(head1 != NULL && head2 != NULL){
        int d;
        if(head1->val < head2->val){
            d = head1->val;
            head1 = head1->next;
        }
        else{
            d = head2->val;
            head2 = head2->next;
        }
        Node * temp = new Node(d);
        if(curr == NULL){
            curr = temp;
            res = curr;
        }
        else{
            curr->next = temp;
            curr = curr->next;
        }
    }
    if(head2 != NULL){
        while(head2 != NULL){
            int d = head2->val;
            Node * temp = new Node(d);
            curr->next = temp;
            curr = curr->next;
            
            head2 = head2->next;
        }
    }
    if(head1 != NULL){
        while(head1 != NULL){
            int d = head1->val;
            Node * temp = new Node(d);
            curr->next = temp;
            curr = curr->next;
            
            head1 = head1->next;
        }
    }
    return res;
}
Node * mergeSort(Node * root){
    //Base case
    if(root->next == NULL){
        return root;
    }
    Node * mid = NULL;
    Node * root1 = NULL;
    mid = findMid(root);
    
    if(mid != NULL){
        root1 = mid->next;
    }
    cout<<root1->val<<endl;

    mid->next == NULL;
    //Node * res = merge(mergeSort(root),mergeSort(root1));
    return NULL;
}
int main(){
    int n;
    cin>>n;
    Node * root = createLL(n);
    print(root);
    Node * curr = root;
    while(curr->next != NULL){
        curr = curr->next;
        
    }
    Node * ans = mergeSort(root);
    
}