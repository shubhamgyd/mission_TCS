/*
There is a list of songs = [10, 20, 40, 90], find all the pairs of songs with runtime sum is a multiple of 60min (60, 120, 180..). You need to print the number of pairs.

Logic : (a+b)%60 = 0
        a%60 + b%60 = 0
and then just apply standard two sum approach.

Mistake: Instead of storing the index as int we need to store it as vector and make algorithm accordingly.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> time(n);
    for (int i = 0; i < n; i++)
    {
        cin >> time[i];
    }
    int cnt = 0;
    vector<int> hashMap(60, 0);
    for (int i = 0; i < n; ++i)
    {
        int rem = time[i] % 60;
        if (rem == 0)
        {
            cnt += hashMap[0];
        }
        else
        {
            cnt += hashMap[60 - rem];
        }
        hashMap[rem]++;
    }
    cout << cnt << endl;
    return 0;
}