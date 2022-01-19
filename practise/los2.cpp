#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        cin >> res[i];
    }
    int x;
    cin >> x;
    vector<int> ans(n), temp(n);
    int turn = 0;
    for (int i = 0; i < x; i++)
    {   
        int num=res[0];
        for (int j = 0; j < n - 1; j++)
        {
            res[j] = abs(res[j] - res[j + 1]);
        }
        if(i!=0)
        {
            res[n-1]=abs(res[n-1]-num);
        }
        if(i==x-2)
        {
            temp=res;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << temp[i] << " ";
    }
    cout << endl;
    return 0;
}
