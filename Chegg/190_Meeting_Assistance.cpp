#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<string>> tasks;
    for (int i = 0; i < n; i++)
    {
        vector<string> arr;
        string name, work, startTime, endTime;
        cin >> name >> work >> startTime >> endTime;
        arr.push_back(name);
        arr.push_back(work);
        arr.push_back(startTime);
        arr.push_back(endTime);
        tasks.push_back(arr);
    }
    unordered_map<string, vector<pair<int, int>>> availability;
    for (auto it : tasks)
    {
        string name = it[0];
        string work = it[1];
        string start = it[2];
        string end = it[3];
        int workStart = stoi(start.substr(0, 2));
        workStart *= 60;
        workStart += stoi(start.substr(3));

        int workEnd = stoi(end.substr(0, 2));
        workEnd *= 60;
        workEnd += stoi(end.substr(3));
        int startTime = 0;
        int endTime = 23 * 60 + 59;
        if (startTime != workStart)
        {
            availability[name].push_back({startTime, workStart - 1});
        }
        if (endTime != workEnd)
        {
            availability[name].push_back({workEnd + 1, endTime});
        }
    }
    string name;
    int cnt = INT_MAX;
    for (auto it : availability)
    {
        sort(it.second.begin(), it.second.end());
        if (it.second.size() < cnt)
        {
            cnt = it.second.size();
            name = it.first;
        }
    }
    string ans = "";
    for (int i = 0; i < availability[name].size(); i++)
    {
        int start = availability[name][i].first;
        int end = availability[name][i].second;
        bool isFound = true;
        int startTime = 0;
        for (auto it : availability)
        {
            if (it.first != name)
            {
                bool isAvailabe = true;
                for (auto times : it.second)
                {
                                }
            }
        }
    }
}