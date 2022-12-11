/*
Two players are playing a game where white or black pieces are represented by a string, colors. The game rules are as follows:

Wendy moves first and then they take alternate tums.

. With each move, Wendy may remove a white piece that has adjacent white pieces on both sides.

• Likewise, with each move, Bob may remove any black piece that has adjacent black pieces on both sides.

• After a piece is removed, the string is reduced in size by one piece. For instance, removing 'y' from 'XYZ' results in 'XZ'.

• When a player can no longer move, they have lost the game.

Example

colors=wwwbbbbwww

Wendy removes the piece wat index 1, colors =

Bob removes the piece b at index 3, colors =

Wendy removes the piece wat index 6, colors =
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int wendy = 0;
    int bob = 0;
    int n = str.length();
    int i = 0;
    while (i < n)
    {
        int j = i;
        int cnt = 0;
        while (j < n and str[j] == str[i])
        {
            j++;
            cnt++;
        }
        if (str[i] == 'w')
        {
            if (cnt >= 3)
            {
                wendy += (cnt - 2);
            }
        }
        if (str[i] == 'b')
        {
            if (cnt >= 3)
            {
                bob += (cnt - 2);
            }
        }
        i = j;
    }
    if (wendy > bob)
    {
        cout << "wendy\n";
    }
    else
    {
        cout << "bob\n";
    }
    return 0;
}