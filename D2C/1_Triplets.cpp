#include <bits/stdc++.h>
using namespace std;


int findCntTriplet(int N)
{
    int cntTriplet = 0;
    for (int i = 1; i < N; i++) {

        if (N % i != 0) {

            cntTriplet += N / i;
        }
        else {
            cntTriplet += (N / i) - 1;
        }
    }
    return cntTriplet;
}
 
int main()
{
    int N = 3;
    cout << findCntTriplet(N);
    return 0;
}