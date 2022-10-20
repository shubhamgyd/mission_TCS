#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    // Read array size
    int n;
    cin >> n;
    // get n strings
    vector<string> Strings(n);
    for (int i = 0; i < n; i++)
    {
        cin >> Strings[i];
    }
    // declare queue
    queue<string> q;
    // Iterate array of string
    for (int i = 0; i < n; i++)
    {
        // get current string
        string currentString = Strings[i];
        // Check string start with A to S
        // if yes, then enqueue into q  ( push into the rear of queue)
        if (currentString[0] >= 'A' and currentString[0] <= 'S')
        {
            q.push(currentString);
        }
        // else start with T to Z
        // then dequeue from the queue
        // dequeu string from the front of the queue
        // and push both of them into the rear(i.e enqueue)
        else
        {
            // get string from front
            string dequeString = q.front();
            // remove it from front
            q.pop();
            // push at rear
            // i.e. enqueu both strings
            q.push(currentString);
            q.push(dequeString);
        }
    }
    // Display modified queue
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}