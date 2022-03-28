#include<bits/stdc++.h>
using namespace std;


// Utility function which prints the stack as many times 
// here we have passed stack with referece, because we need to update the stack
// after popping every element from the stack
void printStack2(stack<int>&stack1)
{
    // ideclaring stack2
    stack<int>stack2;

    cout<<"\nListing the stack"<<endl;
    cout<<"[";
    // while stack1 not empty
    while(!stack1.empty())
    {
        int num=stack1.top();
        cout<<"("<<num<<")"<<" ";                                  // printing top element of stack1
        stack1.pop();                                    // popping element  of stack1 
        stack2.push(num);                                // push element into stack2
    }
    cout<<"]\n";
    cout<<endl;

    // while stack2 not empty
    while(!stack2.empty())
    {
        int num=stack2.top();
        stack1.push(num);                                // push top element of stack2 into bottom of stack1
        stack2.pop();                                    // pop top element of stack2      
    } 


    // at the end we get our initial stack as it is this way
}


int main()
{
    // initial stack elements
    vector<int>elements{20,18,16,14,12,10,8,6,4,2};

    // initalise stack1
    stack<int>stack1;
    
    // transferring array to stack so we achieve same result
    for(int i=elements.size()-1;i>=0;i--)
    {
        stack1.push(elements[i]);
    }
    printStack2(stack1);               // call: 1
    printStack2(stack1);               // call: 2
    return 0;
}
// Time Complexity:O(n) , n  is the size of stack
// Space Complexity :O(n)
