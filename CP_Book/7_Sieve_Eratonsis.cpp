// Program for prime numbers till n

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<char> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    vector<int> vc;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i] == true)
        {
            vc.push_back(i);
        }
    }
    cout << vc.size() << endl;
    for (auto ele : vc)
    {
        cout << ele << " ";
    }
    return 0;
}

// For finding all prime factors of a number
// for (int i = 2; i<= mx; i++) {
//         if (is_prime[i]) {
//             factr[i].push_back(i);
//             for (int j = 2 * i; j <= mx; j += i){
//                 factr[j].push_back(i);
//                 is_prime[j] = false;
//             }
//             }
//         }
//     }

long long continuousSubarrays(vector<int> &nums)
{
    deque<int> r;
    deque<int> ll;
    int l = 0;
    long long ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        while (!r.empty() && nums[r.back()] < nums[i])
        {
            r.pop_back();
        }
        r.push_back(i);
        while (!ll.empty() && nums[ll.back()] > nums[i])
        {
            ll.pop_back();
        }
        ll.push_back(i);
        while (nums[r.front()] - nums[ll.front()] > 2)
        {
            if (r.front() < ll.front())
            {
                l = r.front() + 1;
                r.pop_front();
            }
            else
            {
                l = ll.front() + 1;
                ll.pop_front();
            }
        }
        ans += i - l + 1;
    }
    return ans;
}
