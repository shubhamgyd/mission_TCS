#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e6;
const int MAX = 1005;
int catalan[MAX];
void init() {
    catalan[0] = catalan[1] = 1;
    for (int i=2; i<=1005; i++) {
        catalan[i] = 0;
        for (int j=0; j < i; j++) {
            catalan[i] += (catalan[j] * catalan[i-j-1]) % MOD;
            if (catalan[i] >= MOD) {
                catalan[i] -= MOD;
            }
        }
    }
}

int main()
{
    init();
    int t;
    scanf("%d",&t);
    while(t)
    {
        // int n;
        // scanf("%d",&n);
        printf("%d\n",catalan[t]);
        scanf("%d",&t);
    }
    return 0;
}