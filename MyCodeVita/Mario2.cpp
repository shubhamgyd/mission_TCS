#include <bits/stdc++.h>
using namespace std;

class Mario2
{

    int initialCal;int JumpingCalorie;int CoinsCalorie;int Row;int Coloumn;

void Input(vector<string>&Screen)
{
    for(int i=0;i<Row;i++)
    {
        string str; cin>>str;Screen[i]=str;
    }
}
public:
    Mario2();
    ~Mario2();
void solve()
{
    cin>>initialCal;cin>>JumpingCalorie;cin>>CoinsCalorie;cin>>Row>>Coloumn;
    vector<string>Screen(Row);
    Input(Screen);
    int LastCoins=0;
    for(int j=0;j<Coloumn;j++)
    {
        int Jump=0;
        int Coins=0;
        int Flag=0;
        int Required=0;
        if(Screen[Row-1][j]=='H')
        {
            Flag=1;
        }
        for (int i = Row - 2; i >= 0; --i)
        {
            if (!Flag and Screen[i][j] == 'C')
                Jump = (Row - i - 1), Coins++;
            else if (Flag and Screen[i][j] == '0')
            {
                Jump = (Row - i - 1);
                break;
            }
        }
        if (Flag)
            Required = Jump * JumpingCalorie;
        else if (!Flag and Coins)
            Required = Jump * JumpingCalorie - Coins * CoinsCalorie;
        else
            Required = 1;

        if (initialCal < Required)
        {
            cout << LastCoins;
            break;
        }
        initialCal -= Required;
        LastCoins = j;
    }
    if (LastCoins == Coloumn - 1)
    {
        cout << initialCal;
    }

}

};

Mario2::Mario2()
{

}

Mario2::~Mario2()
{

}





int main()
{
    // int taakat, rows, colums, JC, CC;
    // cin >> taakat;
    // cin >> JC;
    // cin >> CC;
    // cin >> rows >> colums;
    // vector<string> screen(rows);
    // for (int i = 0; i < rows; ++i)
    // {
    //     string temp;
    //     cin >> temp;
    //     screen[i] = temp;
    // }
    // int LCN = 0;
    // for (int j = 0; j < colums; ++j)
    // {
    //     int chhalaang = 0;
    //     int sikke = 0;
    //     bool jhanda = 0;
    //     int kitnachahiye = 0;
    //     if (screen[rows - 1][j] == 'H')
    //         jhanda = 1;
    //     for (int i = rows - 2; i >= 0; --i)
    //     {
    //         if (!jhanda and screen[i][j] == 'C')
    //             chhalaang = (rows - i - 1), sikke++;
    //         else if (jhanda and screen[i][j] == '0')
    //         {
    //             chhalaang = (rows - i - 1);
    //             break;
    //         }
    //     }
    //     if (jhanda)
    //         kitnachahiye = chhalaang * JC;
    //     else if (!jhanda and sikke)
    //         kitnachahiye = chhalaang * JC - sikke * CC;
    //     else
    //         kitnachahiye = 1;

    //     if (taakat < kitnachahiye)
    //     {
    //         cout << LCN;
    //         break;
    //     }
    //     taakat -= kitnachahiye;
    //     LCN = j;
    // }
    // if (LCN == colums - 1)
    //     cout << taakat;
    // return 0;
}