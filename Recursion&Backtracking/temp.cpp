#include <bits/stdc++.h>
using namespace std;

int minimumSteps(vector<string> loggedMoves)
{
    int steps = 0;
    for (auto log : loggedMoves)
        if (log == "../")
            steps = max(0, steps - 1);
        else if (log != "./")
            ++steps;
    return steps;
}

int main()
{
    string str;
    cin >> str;
    // cout<<str.substr(4,5)<<endl;
    int ct = 0;
    for (int i = 0; i < str.length() - 4; i++)
    {

        if (str.substr(i, 5) == "heavy")
        {
            // cout << str.substr(i, 5) << endl;
            for (int j = i + 4; j < str.length() - 4; j++)
            {
                if (str.substr(j, 5) == "metal")
                {
                    // cout<<str.substr(i,5);
                    ct++;
                }
            }
        }
    }
    cout << ct << endl;
}