#include<bits/stdc++.h>
using namespace std;

string solve(string s)
{
    int wendy_moves = 0, bob_moves = 0;
    int i=0;
        int n = s.length();
        while(i < n){
            int j = i, c = 0;
            while(j < n && s[i] == s[j]){
                c++;
                j++;
            }
            if(c > 2){
                if(s[i] == 'w') wendy_moves += c-2;
                else bob_moves += c-2;
            }
            i = j;
        }
        if(bob_moves >= wendy_moves) return "bob";
        else return "wendy";
}