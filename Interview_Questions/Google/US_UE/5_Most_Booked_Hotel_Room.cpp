/*
Given a hotel which has 10 floors [0-9] and each floor has 26 rooms [A-Z]. You are given a sequence of rooms, where + suggests room is booked, - room is freed. You have to find which room is booked maximum number of times.

You may assume that the list describe a correct sequence of bookings in chronological order; that is, only free rooms can be booked and only booked rooms can be freeed. All rooms are initially free. Note that this does not mean that all rooms have to be free at the end. In case, 2 rooms have been booked the same number of times, return the lexographically smaller room.

You may assume:

N (length of input) is an integer within the range [1, 600]
each element of array A is a string consisting of three characters: "+" or "-"; a digit "0"-"9"; and uppercase English letter "A" - "Z"
the sequence is correct. That is every booked room was previously free and every freed room was previously booked.
Example:

Input: ["+1A", "+3E", "-1A", "+4F", "+1A", "-3E"]
Output: "1A"
Explanation: 1A as it has been booked 2 times.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> rooms = {"+1D", "+3B", "-3B", "-1D", "+1D", "+3B"};
    int len = rooms.size();

    // using brute Force
    unordered_map<string, int> mp;
    string room = "";
    int mxOccurance = 0;
    for (auto it : rooms)
    {
        if (it[0] != '-')
        {
            mxOccurance = max(mxOccurance, ++mp[it.substr(1)]);
        }
    }
    for (auto it : mp)
    {
        if (it.second == mxOccurance)
        {
            if (room.empty())
            {
                room = it.first;
            }
            if (it.first < room)
            {
                room = it.first;
            }
        }
    }
    cout << room << endl;
    // T:O(n)
    // S:O(n)

    int hash[260];
    int max = 0;
    string currentMax = rooms[0];

    for (int i = 0; i < rooms.size(); i++)
    {
        string currentRoom = rooms[i];
        if (currentRoom[0] == '-')
            continue;
        int idx = (currentRoom[1] - '0')*26 + (currentRoom[2] - 'A') ;
        cout<<"current: "<<currentRoom<<" idx: "<<idx<<endl;
        hash[idx]++;
        if (hash[idx] > max)
        {
            max = hash[idx];
            currentMax = currentRoom;
        }
        else if (hash[idx] == max)
        {
            if(currentRoom<currentMax)
            {
                currentMax=currentRoom;
            }
        }
    }

    cout << currentMax.substr(1) << endl;
    //T:O(n)
    // S:O(1)
}