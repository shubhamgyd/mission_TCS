/*
This problem was asked by Flipkart.

Snakes and Ladders is a game played on a 10 x 10 board, the goal of which is get from square 1 to square 100. On each turn players will roll a six-sided die and move forward a number of spaces equal to the result. If they land on a square that represents a snake or ladder, they will be transported ahead or behind, respectively, to a new square.

Find the smallest number of turns it takes to play snakes and ladders.

For convenience, here are the squares representing snakes and ladders, and their outcomes:

snakes = {16: 6, 48: 26, 49: 11, 56: 53, 62: 19, 64: 60, 87: 24, 93: 73, 95: 75, 98: 78}
ladders = {1: 38, 4: 14, 9: 31, 21: 42, 28: 84, 36: 44, 51: 67, 71: 91, 80: 100}
*/

#include<bits/stdc++.h>
using namespace std;

// helper function to get the position of the next ladder
int getNextLadderPos(int pos,map<int,int>&ladders)
{
    int curr=101;
    for(auto it:ladders)
    {
        if(it.first>pos and it.first<curr)
        {
            curr=it.first;
        }
    }
    return curr;

}

// helper function to get the position of the next move without landing on a snake
int get_Next_Step_With_No_Snake(map<int,int>&snakes,int pos)
{
    int curr=pos+6;
    for(int i=0;i<6;i++)
    {
        if(snakes.find(curr)==snakes.end())
        {
            break;
        }
        curr--;
    }
    return curr;
}

// function to return the minimum turns required to play the current board
void solve(map<int,int>&snakes,map<int,int>&ladders,bool showPath=false)
{
    int pos=0;
    int steps=0;
    while(pos<100)
    {
        steps++;
        pos=min({100,getNextLadderPos(pos,ladders),get_Next_Step_With_No_Snake(snakes,pos)});
        if(showPath)
        {
            cout<<pos<<" ";
        }
        if(ladders.find(pos)!=ladders.end())
        {
            pos=ladders[pos];
            if(showPath)
            {
                cout<<"=>"<<pos;
            }
        }
        if(pos<100 and showPath)
        {
            cout<<"->";
        }
    }
    if(showPath)
    {
        cout<<endl;
    }
    cout<<steps<<endl;
}

int main()
{
    map<int,int>snakes;
    snakes[16]=6;
    snakes[48]=26;
    snakes[49]=11;
    snakes[56]=53;
    snakes[62]=19;
    snakes[64]=60;
    snakes[87]=24;
    snakes[93]=73;
    snakes[95]=75;
    snakes[98]=78;
    // snakes = {16: 6, 48: 26, 49: 11, 56: 53, 62: 19, 64: 60, 87: 24, 93: 73, 95: 75, 98: 78}
    // ladders = {1: 38, 4: 14, 9: 31, 21: 42, 28: 84, 36: 44, 51: 67, 71: 91, 80: 100}
    map<int,int>ladder;
    ladder[1]=38;
    ladder[4]=14;
    ladder[9]=31;
    ladder[21]=42;
    ladder[28]=84;
    ladder[36]=44;
    ladder[51]=67;
    ladder[71]=91;
    ladder[80]=100;
    bool printPath=true;
    solve(snakes,ladder,printPath);
    return 0;

}

// 10
// 16 6
// 48 26
// 49 11
// 56 53
// 62 19
// 64 60
// 87 24
// 93 73
// 95 75
// 98 78
// 9
// 1 38
// 4 14
// 9 31
// 21 42
// 28 84
// 36 44
// 51 67
// 71 91
// 80 100