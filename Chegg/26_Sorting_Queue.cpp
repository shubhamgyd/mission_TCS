#include<iostream>
#include<stack>
#include<queue>
using namespace std;


void Sort(stack<int>&input)
{
   stack<int> tmpStack;
 
    while (!input.empty())
    {
        // pop out the first element
        int tmp = input.top();
        input.pop();
 
        // while temporary stack is not empty and top
        // of stack is greater than temp
        while (!tmpStack.empty() && tmpStack.top() > tmp)
        {
            // pop from temporary stack and push
            // it to the input stack
            input.push(tmpStack.top());
            tmpStack.pop();
        }
 
        // push temp in temporary of stack
        tmpStack.push(tmp);
    }
    while(!tmpStack.empty())
    {
        int num=tmpStack.top();
        tmpStack.pop();
        cout<<num<<" ";
    }
}


int main()
{
    cout<<"Enter number of elements: ";
    int n;
    cin>>n;
    queue<int>q;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        q.push(a);
    }

    stack<int>numbers;
    while(!q.empty())
    {
        int num=q.front();
        q.pop();
        numbers.push(num);
    }
    Sort(numbers);


}