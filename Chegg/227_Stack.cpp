#include <iostream>
#include <stack>
using namespace std;

int main()
{
    // Stack
    stack<int> stack;
    int x, y;
    x = 2;
    y = 1;

    // push elements into the stack
    stack.push(10);
    stack.push(x);
    stack.push(x + 3);
    y = stack.top();
    stack.pop();
    stack.push(x + y);
    stack.push(y - 7);
    stack.push(5);
    x = stack.top();
    stack.pop();
    // Display value of x
    cout << "x = " << x << endl;
    // Display value of y
    cout << "y = " << y << endl;

    // Display stack elements from top
    while (!stack.empty())
    {
        cout << stack.top() << endl;
        stack.pop();
    }
}