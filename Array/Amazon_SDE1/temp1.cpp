#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, int> mp;

    // insert elements in random order
    mp.insert({2, 30});
    mp.insert({3, 10});
    mp.insert({5, 50});
    mp.insert({4, 40});
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << (*it).first << " " << (*it).second << endl;
    }

    // when 2 is present
    auto it = mp.lower_bound(1);
    --it;
    if (it == mp.end())
    {
        cout << "here" << endl;
        return 0;
    }
    cout << "The lower bound of key 1 is ";
    cout << (*it).first << " " << (*it).second << endl;
    return 0;
}