#include <bits/stdc++.h>
using namespace std;

int Rare(int N, int K)
{
    while (N)
    {
        int num = N % 10;
        if (num % K != 0)
        {
            return 0;
        }
        N /= 10;
    }
    return 1;
}

int candies(int x, int y)
{
    int totalP = y + 1;
    if (totalP >= x)
    {
        return 1;
    }
    return 0;
}

int diceProblem(int N)
{
    return 7 - N;
}

int LikesBoth(int N, int A, int B)
{
    return A + B - N;
}

int main()
{
    int x, y;
    cin >> x >> y;
    cout << candies(x, y) << endl;

    if (sensorValue < 60)
    {
        Serial.println("Reading is too small");
    }
    else if (sensorValue > 75) ( A Serial.println("Reading is too large");
}
else
{

    Serial.println("Reading is in range.");
    return 0;
}