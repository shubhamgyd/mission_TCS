/*
Amazon Prime Games is designing a game. The player needs to pass n rounds sequentially 
in this game. Rules of play are as follows:

The player loses power[i] health to complete round i

• The player's health must be greater than O at all times.

• The player can choose to use armor in any one round. The armor will prevent damage of 
min(armor, power(i)).

Determine the minimum starting health for a player to win the game.
Amazon Prime Games is designing a game. The player needs to pass n rounds sequentially in this 
game. Rules of play are as follows:

The player loses power[i] health to complete round i

• The player's health must be greater than O at all times.

• The player can choose to use armor in any one round. The armor will prevent damage of 
min(armor, power(i)).

Determine the minimum starting health for a player to win the game.


*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    int sum=0;
    int mx=0;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
        sum+=nums[i];
        mx=max(mx,nums[i]);
    }
    int armor;
    cin>>armor;
    int ans=sum-min(armor,mx)+1;
    cout<<ans<<endl;
    return 0;
}



/*

Just for clarification:
1. During the whole game, the armor can only be summoned at one round and used in this round.
2. player's health is integer, and need to be >= 1 the whole time.

I don't know why can't we do the reverse engineering... Just start from the final stage of the game.
1 => 8 => 14 => 16 => 17 (without an armor)
   -7     -6      -2       -1

Since we want to armor to do most of its job. Add an extra check 
max = max over power array
Apply the armor on the max element.

17 - MIN(armor = 5, max = 7) = 12
which is exactly what we want.

time: O(n)
space: O(1)
*/