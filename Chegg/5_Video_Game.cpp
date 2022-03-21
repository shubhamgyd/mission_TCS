#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);

string rtrim(const string &);

/*

* Complete the 'playSegments' function below.

*

* The function is expected to return an INTEGER.

* The function accepts INTEGER_ARRAY coins as parameter.

*/

int playSegments(vector<int> coins)
{
    // we will transfer intial coins to new coins, because we need to update some points of coins array
    vector<int>tempCoins(coins.begin(),coins.end());

    int totalCoins=0;
    int n=coins.size();

    // Loop will find the total sum of coins with the condition
    // of if we have found 0 coins then we will marked as -1 and add to the total score
    for(int i=0;i<n;i++)
    {
        // if player1 is lost
        if(tempCoins[i]==0)
        {
            tempCoins[i]=-1;
        }
        totalCoins+=tempCoins[i];
    }
    // keep tack on the player1 score
    int player1=0;
    if(player1>totalCoins-player1)
    {
        return 0;
    }
    // will indicate the segment, where player1's score is greater than player2's score
    int index=-1;

    // loop will add the player1 score and paralley minus the player2's score from the total score of player1 if at current segment 
    // player 1 is lost
    for(int i=0;i<n;i++)
    {
        player1+=tempCoins[i];
        // if at current moment player1's score is greater than player2's score then this is the answer
        if(player1>totalCoins-player1)
        {
           index=i;
           break;
        }
    }
    // return the segment index
    return index+1;
}
// Time Complexity:O(n)
// Space Complexity:O(n)

int main()

{

    ofstream fout(getenv("OUTPUT_PATH"));

    string coins_count_temp;

    getline(cin, coins_count_temp);

    int coins_count = stoi(ltrim(rtrim(coins_count_temp)));

    vector<int> coins(coins_count);

    for (int i = 0; i < coins_count; i++)
    {

        string coins_item_temp;

        getline(cin, coins_item_temp);

        int coins_item = stoi(ltrim(rtrim(coins_item_temp)));

        coins[i] = coins_item;
    }
    int result = playSegments(coins);
    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{

    string s(str);

    s.erase(

        s.begin(),

        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))

    );

    return s;
}

string rtrim(const string &str)
{

    string s(str);

    s.erase(

        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),

        s.end()

    );

    return s;
}