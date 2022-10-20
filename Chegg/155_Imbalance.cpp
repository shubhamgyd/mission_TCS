#include <iostream>
#include <set>
using namespace std;

// function to get the totalImbalance from array
long long findTotalImbalance(int rank[], int n)
{
    // get answer
    long long ans = 0;
    // store unique elements
    set<long long> st;
    for (int i = 0; i < n; i++)
    {
        st.clear();
        int mx = rank[i];
        int mn = rank[i];
        st.insert(rank[i]);
        for (int j = i + 1; j < n; j++)
        {
            if (st.find(rank[j] - 1) != st.end() and st.find(rank[j] + 1) != st.end())
            {
                continue;
            }
            else if (mn > rank[j] and st.find(rank[j] + 1) != st.end())
            {
                mn = rank[j];
            }
            else if (mx < rank[j] and st.find(rank[j] - 1) != st.end())
            {
                mx = rank[j];
            }
            else if (mn > rank[j])
            {
                mn = rank[j];
                ans++;
            }
            else if (mx < rank[j])
            {
                mx = rank[j];
                ans++;
            }
            else if (st.find(rank[j] - 1) != st.end() or st.find(rank[j] + 1) != st.end())
            {
                ans++;
            }
            else
            {
                ans += 2;
            }
            st.insert(rank[j]);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int rank[n];
    for (int i = 0; i < n; i++)
    {
        cin >> rank[i];
    }
    long long ans = findTotalImbalance(rank, n);
    cout << ans << endl;
    return 0;
}