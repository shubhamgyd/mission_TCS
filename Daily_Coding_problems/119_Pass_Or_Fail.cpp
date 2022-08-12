/*
You are given a string, attendance that represents a student’s class attendance throughout the 
semester. A student can be marked, A for absent, L, for late, or P for present. 
To get credit for the class, a student cannot miss more than one class and cannot come late to 
class twice in a row. Given the current students attendance record, return whether or not the 
student has passed the class.

Ex: Given the following attendance of a student…

attendance = "PLPAPPPA", return false.
Ex: Given the following attendance of a student…

attendance = "PLPLPLPALP", return true.
*/

#include<bits/stdc++.h>
using namespace std;

bool solve(string str)
{
    map<char,int>mp;
    int ind=0;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='A' and mp.find(str[i])!=mp.end()) return false;
        if(str[i]=='L' and mp.find(str[i])!=mp.end())
        {
            int lastInd=mp[str[i]];
            int currInd=i;
            if(abs(currInd-lastInd)==1) return false;
        }
        mp[str[i]]=i;
    }
    return true;
}

int main()
{
    string str;
    cin>>str;
    cout<<solve(str)<<endl;
    return 0;
}