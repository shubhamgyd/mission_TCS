#include <bits/stdc++.h>
using namespace std;
#define int long long

int cache1[10020][2][2];int N12;int A1[10020];

int dp123(int i, bool j, bool k1) {
    if (i >= N12)
    {
        return 0;
    }
  
    if (cache1[i][j][k1] != 1e18)
    {
        return cache1[i][j][k1];
    }
        

    int val1 = A1[i];
    if ((j + k1) & 1)
    {
        val1 *= -1;
    }
    return cache1[i][j][k1] = max(dp123(i + 1, !j, k1) + val1, dp123(i + 1, 1, !k1) + val1);

}

signed main()
{

    int t;
    cin >> t;
    while(t--) {
       cin >> N12;
    	for (int i = 0; i < N12; i++) {
    	    cin >> A1[i];cache1[i][0][0] = 1e18;cache1[i][0][1] = 1e18;cache1[i][1][0] = 1e18;cache1[i][1][1] = 1e18;
    	}
    	cout << dp123(0, 1, 1) << "\n";
   }
   return 0;
}