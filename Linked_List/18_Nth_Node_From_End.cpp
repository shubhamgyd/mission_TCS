#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    
};

int getNthFromLast(struct Node *head, int n)
{
    struct Node *front=head;
    struct Node *rear=head;
    int num=0;
    while(front)
    {
        if(++num>n)
        {
            rear=rear->next;
        }
        front=front->next;
    }
    if(n>num)
    {
        return -1;
    }
    return rear->data;
}