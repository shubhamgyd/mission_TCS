#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& A, int T) {
        sort(rbegin(A), rend(A)); 
        long mod = 1e9+7, N = A.size(), cur = A[0], ans = 0, i = 0;
        while (T) {
            while (i < N && A[i] == cur) ++i; 
            long next = i == N ? 0 : A[i], h = cur - next, r = 0, cnt = min((long)T, i * h);
            if (T < i * h) { 
                h = T / i; 
                r = T % i; 
            }
            long val = cur - h;
            ans = (ans + (cur + val + 1) * h / 2 * i + val * r) % mod;
            T -= cnt;
            cur = next;
        }
        return ans;
    }
};


int main()
{
    int n;
    cin>>n;
    vector<int>res;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        res.push_back(a);
    }
    int order;
    cin>>order;
    Solution obj;
    cout<<obj.maxProfit(res,order)<<endl;
    return 0;
}