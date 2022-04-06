#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class Queue{
private:
    Node *first;
    Node *last;
    Node *head;
    Node *temp;
public:
    Queue(){
        first = NULL;
        last = NULL;
        head=NULL;
    }
    // temp=head;
    void enqueue(int data){

    }

    void dequeue(){

    }

    // returns the first item (int) without removing it
    int firstItem(){

    }

    bool isEmpty(){

    }

    void makeEmpty(){

    }
};



class Solution {
public:
    int convertTime(string current, string correct) {
        int hhS=stoi(current.substr(0,2));int mmS=stoi(current.substr(3)); int hhE=stoi(correct.substr(0,2));int mmE=stoi(correct.substr(3));
        int diffRem=hhE-hhS;if(mmS>mmE){ diffRem--; mmE+=60; }
        int mmDiffRem=abs(mmS-mmE); int on=mmDiffRem; int fiv=INT_MAX; int fif=INT_MAX;if(mmDiffRem>=5) {  fiv=mmDiffRem/5+mmDiffRem%5;}
        if(mmDiffRem>=15) { fif=mmDiffRem/15;int temp1=mmDiffRem%15;fif+=temp1/5; temp1%=5; fif+=temp1; }int six=INT_MAX;if(mmDiffRem==60)  { six=1; }
        int tt=min({on,fiv,fif,six});return diffRem+tt;
    }
};

int main(){
    
}