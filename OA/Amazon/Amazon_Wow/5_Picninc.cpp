#include <bits/stdc++.h>
using namespace std;
 
int main()
{
 
    int n, i, x, y, ans = 0;
 
    cin >> n;
    map<int, int> mm;
    vector<int> a(n, 0);
 
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        mm[a[i]]++;
    }
    for (auto p : mm)
    {
        y = p.second;
 
        ans += (y / 2);
    }
 
    cout << ans << endl;
}


#include <bits/stdc++.h>
using namespace std;

int main()
{
long long n, val ,ans = 0;

cin >> n;
unordered_map<int, int> m;

for (int i = 0; i < n; i++){
    cin >> val;
    m[val]++;
    if( m[val] == 2 ) {
        ans++;
        m.clear();
    }
}
cout << ans << endl;
}