#include <queue>
#include <unordered_set>
#include<bits/stdc++.h>
using namespace std;

int unlock(vector<string> &deadends, int n, string target)
{

    // To store dead end codes and visited codes.
    unordered_set<string> avoid;

    // Insert all dead end codes in avoid.
    for (int i = 0; i < n; i++)
    {
        avoid.insert(deadends[i]);
    }

    // If the initial code is a dead end code or the target is a dead end code, return -1.
    if (avoid.find(target) != avoid.end() || avoid.find("0000") != avoid.end())
    {
        return -1;
    }

    queue<string> q;
    // Push the initial string to the queue.
    q.push("0000");

    int count = 0;

    while (!q.empty())
    {

        int num = q.size();

        for (int k = 0; k < num; k++)
        {

            string current = q.front();
            q.pop();

            // If the current code is in avoid, no need to consider it.
            if (avoid.find(current) != avoid.end())
            {
                continue;
            }

            // If the new code formed is the target code, return the count.
            if (current == target)
            {
                return count;
            }

            // Add the current code to avoid.
            avoid.insert(current);

            // Traverse the code.
            for (int i = 0; i < 4; i++)
            {

                // Right rotating the current wheel.
                int digitUp = (current[i] - '0' + 1) % 10;

                // Left rotating the current wheel.
                int digitDown = (current[i] - '0' + 9) % 10;

                string newStr = current;
                newStr[i] = digitUp + '0';
                q.push(newStr);

                newStr[i] = digitDown + '0';
                q.push(newStr);
            }
        }
        count++;
    }

    // If target code can't be reached.
    return -1;
}