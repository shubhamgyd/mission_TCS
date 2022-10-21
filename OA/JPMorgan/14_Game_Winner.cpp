#include<bits/stdc++.h>
using namespace std;


bool winnerOfGame(string colors) { 
        int a=0,b=0; 
        int i=0; 
        for(i=0;i<colors.size()-1;i++) 
        { 
            if(i==0) continue; 
            if(colors[i]=='A') 
            { 
                if(colors[i-1]=='A' && colors[i+1]=='A') 
                        a++; 
            } 
            else 
            { 
                if(colors[i-1]=='B' && colors[i+1]=='B') 
                    b++; 
            } 
        } 
         
        return (a>b) ? true: false; 
    }