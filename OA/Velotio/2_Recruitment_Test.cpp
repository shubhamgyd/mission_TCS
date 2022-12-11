#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    set<int> st;
    int q;
    cin >> q;
    while (q--)
    {
        int t;
        cin >> t;
        int spot;
        cin >> spot;
        if (t == 1)
        {
            st.insert(spot);
        }
        else
        {
            int num1 = spot - 1;
            int num2 = spot + 1;
            auto it1 = st.lower_bound(num1);
            auto it2 = st.lower_bound(num2);
            int prev = 0;
            int next1 = n - 1;
            if (it1 != st.end())
            {
                prev = *it1;
            }
            if (it2 != st.end())
            {
                next1 = *it2;
            }
            cout << prev << " " << next1 << endl;
            if (st.find(spot) != st.end())
            {
                int prevLength = spot - prev;
                int nextLength = next1 - spot;
                cout << prevLength + nextLength << endl;
            }
            else
            {
                int length = next1 - prev;
                cout << length << endl;
            }
        }
    }
    return 0;
}