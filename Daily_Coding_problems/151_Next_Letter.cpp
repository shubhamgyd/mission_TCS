/*
Given a sorted character array, letters, and a character, target, return the smallest character 
in letters that is strictly larger than target.
Note: Letters wrap around. If target is ’y’ and letters contains ’c’ and ’d’, return ’c’.
Ex: Given the following letters and target…

letters = ['a', 'b', 'c'], target = 'b', return 'c'.
Ex: Given the following letters and target…

letters = ['r', 'y'], target = 'z', return 'r'.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<char>letters(n);
    for(int i=0;i<n;i++)
    {
        cin>>letters[i];
    }
    char target;
    cin>>target;
    auto it=upper_bound(letters.begin(),letters.end(),target)-letters.begin();
    if(it<letters.size())
    {
        cout<<letters[it]<<endl;
    }
    else
    {
        cout<<letters[0]<<endl;
    }
    return 0;
}