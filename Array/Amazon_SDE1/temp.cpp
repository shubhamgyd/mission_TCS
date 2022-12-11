#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> dir(n);
    for (int i = 0; i < n; i++)
    {
        cin >> dir[i];
    }
    string currDir = "East";
    string prevDir = "East";
    int totalSpins = 0;
    for (int i = 0; i < n; i++)
    {
        if (dir[i] == "right")
        {
            if (currDir == "North")
            {
                currDir = "East";
            }
            else if (currDir == "East")
            {
                currDir = "South";
            }
            else if (currDir == "South")
            {
                currDir = "West";
            }
            else
            {
                currDir = "North";
            }
            if (currDir == prevDir)
            {
                totalSpins++;
            }
        }
        else
        {
            if (currDir == "North")
            {
                currDir = "West";
            }
            else if (currDir == "West")
            {
                currDir = "South";
            }
            else if (currDir == "South")
            {
                currDir = "East";
            }
            else
            {
                currDir = "North";
            }
            if (currDir == prevDir)
            {
                totalSpins++;
            }
        }
    }
    cout << "Toal Spint count = " << totalSpins << endl;
    cout << "Direction person is facing in the end = " << currDir << endl;
    return 0;
}