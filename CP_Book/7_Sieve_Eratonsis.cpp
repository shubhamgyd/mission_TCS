// Program for prime numbers till n

#include<bits/stdc++.h>
using namespace std;





int main()
{
    int n;
    cin>>n;
    vector<char> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    vector<int>vc;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]==true)
        {
            vc.push_back(i);
        }
    }
    cout<<vc.size()<<endl;
    for(auto ele:vc)
    {
       cout<<ele<<" ";
    }
    return 0;
}