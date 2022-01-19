/*
This question is asked by Amazon. Given a string representing your stones and another 
string representing a list of jewels, return the number of stones that you have that are also jewels.

Ex: Given the following jewels and stones...

jewels = "abc", stones = "ac", return 2
jewels = "Af", stones = "AaaddfFf", return 3
jewels = "AYOPD", stones = "ayopd", return 0
*/

#include<bits/stdc++.h>
using namespace std;

int solve(string jwels,string stones)
{
    int ct=0;
    for(int i=0;i<stones.length();i++)
    {
        char stone=stones[i];
        for(int j=0;j<jwels.length();j++)
        {
            if(stone==jwels[j])
            {
                ct++;
                break;
            }
        }
    }
    return ct;
}
// Time Complexity:O(|stones|*|Jwels|)
// Space Complexity:O(1)




int Count(string jwels,string stones)
{
    map<char,int>mp;
    for(int i=0;i<jwels.length();i++)
    {
        mp[jwels[i]]++;
    }

    int stone=0;
    for(int i=0;i<stones.length();i++)
    {
        if(mp.find(stones[i])!=mp.end())
        {
            stone++;
        }
    }
    return stone++;
}
// Time Complexity:O(n)
// Space Complexity:O(n)

int main()
{
    string jwels,stones;
    cin>>jwels>>stones;
    cout<<solve(jwels,stones)<<endl;
    cout<<Count(jwels,stones)<<endl;
    return 0;
}