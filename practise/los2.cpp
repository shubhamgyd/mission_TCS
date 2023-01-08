#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;
    cin.ignore();
    getline(cin, str);
    int ans = 0;
    stringstream ss(str);
    string word;
    while (ss >> word)
    {
        string temp = word;
        sort(begin(temp), end(temp));
        int sum = 0;
        for (auto ele : word)
        {
            if (ele != temp[0] and ele != temp[temp.size() - 1])
            {
                sum = sum * 10 + (ele - '0');
            }
        }
        ans += sum;
    }
    cout << ans << endl;
    return 0;
}
