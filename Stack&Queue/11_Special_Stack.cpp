#include<bits/stdc++.h>
using namespace std;


void push(stack<int>& s, int a){
	// Your code goes here
    if (!isEmpty(s)) {  
        int y = s.top();
        if (a < y) {
            s.pop();
            push(s, a);
            s.push(y);
        } else {
            s.push(a);
        }
    } else {
        s.push(a); 
    }
	
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
	if(s.size()==n)
	{
	    return true;
	}
	return false;
}

bool isEmpty(stack<int>& s){
	// Your code goes here
	if(s.size()==0)
	{
	    return true;
	}
	return false;
}

int pop(stack<int>& s){
	// Your code goes here
	int a=s.top();
	s.pop();
	return a;
}

void sort(stack<int>&s) {
    if (!isEmpty(s)) {
        int x = pop(s);
        sort(s);
        push(s, x);
    }
}

int getMin(stack<int>& s){
	// Your code goes here
	sort(s);
	int n=s.size();
	for(int i=0;i<n-1;i++)
	{
	    s.pop();
	}
	return s.top();
	
	
	
}