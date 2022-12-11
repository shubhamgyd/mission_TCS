/*
Given list of strings which are logs and an integer representing maximum time, determine which
user has activity time of less than or equal to the maximum time. Sort and return those list of
users.[Do not remember if sorting was asked based on user number or their activity time]

Input :
logs : ["12 10 sign-in", "5 100 sign-out", "12 20 sign-out", "5 10 sign-in", "8 20 sign-in", "8 50 sign-out"]
maximumTime : 30

Output : [8, 12]

Explanation -
User 12 - logged in time period - (signout time - signin time) - 20 - 10 = 10 < 30
User 5 - logged in time period - (signout time - signin time) - 100 - 10 = 90 > 30
User 8 - logged in time period - (signout time - signin time) - 50 - 20 = 30 == 30
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 6;
    vector<string> logs = {"12 10 sign-in", "5 100 sign-out", "12 20 sign-out", "5 10 sign-in", "8 20 sign-in", "8 50 sign-out"};

    int mxTime = 30;
    vector<int> users;
    map<string, pair<string, string>> mp;
    for (int i = 0; i < n; i++)
    {
        string it = logs[i];
        stringstream ss(it);
        string word;
        string user;
        string time;
        string activity;
        int cnt = 0;
        while (ss >> word)
        {
            if (cnt == 0)
            {
                user = word;
                cnt++;
            }
            else if (cnt == 1)
            {
                time = word;
                cnt++;
            }
            else if (cnt == 2)
            {
                activity = word;
                cnt++;
            }
        }
        if (activity == "sign-in")
        {
            mp[user].first = time;
        }
        else
        {
            mp[user].second = time;
        }
        if (mp[user].first.length() > 0 and mp[user].second.length() > 0)
        {
            int in = stoi(mp[user].first);
            int out = stoi(mp[user].second);
            int res = abs(out - in);
            if (res <= mxTime)
            {
                users.push_back(stoi(user));
            }
        }
    }
    for (auto it : users)
    {
        cout << it << " ";
    }
    return 0;
}