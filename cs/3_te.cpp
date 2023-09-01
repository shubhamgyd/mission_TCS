#include <iostream>
#include <vector>
#include <map>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void testCases()
{
    int n, p;
    cin >> n >> p;
    vector<int> nums(n);
    ordered_set cnt;
    map<int, int> table;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        if (table[nums[i]] == 0)
        {
            cnt.insert(nums[i]);
            table[nums[i]] = 1;
        }
    }
    for (int i = 0; i < p; i++)
    {
        int a;
        cin >> a;
        if (table[a] == 0)
        {
            cnt.insert(a);
            table[a] = 1;
        }
        cout << cnt.size() - cnt.order_of_key(a) << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    testCases();
    return 0;
}