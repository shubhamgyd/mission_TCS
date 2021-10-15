/*
A and B are playing a game. At the beginning there are n coins. Given two more numbers x and y. 
In each move a player can pick x or y or 1 coins. A always starts the game. The player who picks
 the last coin wins the game or the person who is not able to pick any coin loses the game. 
 For a given value of n, find whether A will win the game or not if both are playing optimally.

Examples: 

Input :  n = 5, x = 3, y = 4
Output : A
There are 5 coins, every player can pick 1 or
3 or 4 coins on his/her turn.
A can win by picking 3 coins in first chance.
Now 2 coins will be left so B will pick one 
coin and now A can win by picking the last coin.

Input : 2 3 4
Output : B

*/


// We can observe that A wins game for n coins only when B loses for coins n-1 or n-x or n-y. 


#include<bits/stdc++.h>
using namespace std;

int Winner(int n,int x,int y)
{
    int dp[n+1];
    //initial values
    dp[0]=false;
    dp[1]=true;

    for(int i=2;i<=n;i++)
    {
        // If A losses any of i-1 or i-x
        // or i-y game then he will
        // definitely win game i
        if(i-1>=0 && !dp[i-1])
        {
            dp[i]=true;
        }
        else if(i-x>=0 && !dp[i-x])
        {
            dp[i]=true;
        }
        else if(i-y>=0 && !dp[i-y])
        {
            dp[i]=true;
        }
        else
        {
            dp[i]=false;
        }

    }
    return dp[n];
}

int main()
{
    int n=5;
    int x=3;
    int y=4;
    if(Winner(n,x,y))
    {
        cout<<"A will win the game..!!"<<endl;
    }
    else
    {
        cout<<"B will win the game..!!"<<endl;
    }
    return 0;
}