#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    // Stack to store to store names
    stack<string> S;
    for (int i = 0; i < 10; i++)
    {
        // Read name
        cout << "Enter name: ";
        string name;
        cin >> name;
        // Push into the stack
        S.push(name);
        cout << endl;
    }
    // Declare Queue
    queue<string> D;
    // Temporary stack to store the names
    stack<string> temp;
    // Iterate stack
    // and check condition
    while (!S.empty())
    {
        // get name from the stack
        string name = S.top();
        S.pop();
        // Check it is start with 'A' or 'S'
        // if yes then push into the queue
        if (name[0] == 'A' or name[0] == 'S')
        {
            D.push(name);
        }
        // push into the temp stack
        temp.push(name);
    }
    // push all names from temp stack to S stack
    while (!temp.empty())
    {
        S.push(temp.top());
        temp.pop();
    }
    // if queue is not empty
    if (D.size() > 0)
    {
        // Display names start with A or S
        cout << "List of names start with A or S: " << endl;
        // Display all names
        while (!D.empty())
        {
            // Display name
            cout << D.front() << " ";
            D.pop();
        }
    }
    return 0;
}