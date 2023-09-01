
/*
*Question.
**given an array A. For all subarrays of you have to find sum of sum(A[l:r])min(A[l:r]) for every subarray
and return answer % 1e9+7;**
constraint
**1 <= len(A) <= 500000
1 <= A[i] <= 1e5;**
I am posting detialed solution to above problem asked by many. It will help many to understand how standard interview problems can be used to solve
Hope this helps.

**Its basically Leetcode hard problem (or harder side dont get demotivate by this problem see what you have learnt from this problem.**

lets suppose array is A = [a1 a2 a3 a4 a5 a6 a7]

we basically have to calculate for all subarrays sum(A[l:r])*min(A[l:r]) which basically means for every sum we have to take sum and multiply it by minimum element of that subarray.

lets see another prespective of this problem we basically can do is for every element we will find sum of all subarrays in which that element is minimum. now comes the questions how to find that lets take example

suppose for element a4 , a6 is next smaller element of a4, a6 that means first element after a4 that is smaller than a4.

similarly we can define previous smaller element lets suppose a2 is the previous smaller element.

i is index of a2 
j is index of a6 
k is index of a4
[a1 a2 a3 a4 a5 a6 a7]

we have to find sum of all subarrays that include A[k] from subarray of A[i+1:j-1]. because in all that subarray A[k] will be minimum (A[i] and A[j] are right and left closest element greater than a[k])

Now to find the sum of all subarrays we need to think how we can compute that

we can basically find the how many times a particular element occurs in all subarray then we can do element*howmanysubarrayitoccurs.

lets see a3 how many times it will occur. as a3 is last index of subarray A[i+1:j-1];
Occurence of a3 will be (j-k) as we have fixed our left pointer of subarray. h
Occurence of a4 will be (j-k) + occurence of a3 (if we are choosing right pointer at a3 a4 is also the part of that subarray) which is 2*(k-j).

From here we can say that
A[i+1] will occur (j-k) times
A[i+2] will occur 2*(j-k) times
A[i+3] will occur 3*(j-k) times.
So on.

Similarly
A[j-1] will occur (k-i) times
A[j-2] will occur 2*(k-i) times.
So on
A[k] will occur (j-k)*(k-i) times (as there are j-k ways to choose right pointer k-i way for left pointer )
So sum of all subarrays will be

A[i+1](j-k) + 2(j-k)A[i+2]..........A[k](j-k)(k-1) + A[j-1](k-i) + A[j-2]*(k-i)*2

adding and subtracting A[k](j-k)(k-1) expression will become

A[i+1](j-k) + 2(j-k)A[i+2]..........A[k](j-k)(k-i) + A[j-1](k-i) + A[j-2](k-i)2....
A[k](j-k)(k-i) - A[k](j-k)(k-i)

(j-k)(A[i+1] + 2A[i+2] ..... (k-i)A[k]) + (k-i)(A[j-1] + 2A[j-2] ... A[k](j-k)) - A[k](j-k)) - A[k](j-k)*(k-i)

if you observe A[i+1] + 2*A[i+2] ..... (k-i)*A[k] is basically SumSubarr[k:k] + sumSubarr[k-1:K] ..... sumSubarr[i+1:K]

similarly (A[j-1] + 2A[j-2] ... A[k](j-k)) - A[k]*(j-k)) = SumSubarr[k:k] + sumSubarr[K:K+1] ..... sumSubarr[K:j-1]

lets see how to find SumSubarr[k:k] + sumSubarr[k-1:K] ..... sumSubarr[i+1:K] for particular subarray

we can maintain two prefix sum first presum[K] = sumofSubarray A[0:K]
second is continuousPresumLeft[K] = sum of all subarray sum(A[l:K]) where 0 <= l <= K

but we need to find sum(A[l:K]) where i <= l <= K

formula of this is basically

sum(A[l:K]) (where i <= l <= K) = continuousPresumLeft[k] - (continuousPresumLeft[i+1] - arr[l+1]) - presum[k] - presum[i])*i;

// this i find by manupilating

similarly you can find

continuousPresumRight[K] = sum of all subarray sum(A[K:l]) where k <= l <= n-1;

sum(A[k:l]) (where k <= l <= j) = ontinuousPresumRight[k] - (continuousPresumRight[j-1] - arr[j-1]) - presum[j-1] - presum[k-1])*(n-2-j)

so for particular index k
we will add
ans += (sum(A[l:K]) (where i <= l <= K) + sum(A[k:l]) (where k <= l <= j) - A[k](k-j)(i-k))*A[k]
this is how i have calculated rest of you can understand by code.
there may be easy way to understand but i came up with this.
**
If you have any doubt feel free to ask .**
*/



#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll mod = 1e9 + 7;
    ll n;
    cin >> n;
    vector<ll>arr(n);
    for (auto &it : arr)
    {
        cin >> it;
    }
    // presum
    vector<ll>presum(n);
    presum[0] = arr[0];
    for (ll i = 1; i < n; i++)
    {
        presum[i] = arr[i] +  presum[i - 1];
        presum[i] %= mod;
    }

    //PresumRight
    vector<ll>continuousPresumRight(n);
    continuousPresumRight[n - 1] = arr[n - 1];
    for (ll i = n - 2; i >= 0; i--)
    {
        continuousPresumRight[i] = continuousPresumRight[i + 1] + (arr[i] * (n - i)) % mod;
        continuousPresumRight[i] %= mod;
    }

    //PresumLeft
    vector<ll>continuousPresumLeft(n);
    continuousPresumLeft[0] = arr[0];
    for (ll i = 1; i < n; i++)
    {
        continuousPresumLeft[i] = continuousPresumLeft[i - 1] + (arr[i] * (i + 1)) % mod;
        continuousPresumLeft[i] %= mod;
    }




    // next Smaller
    vector<ll>nextSmaller(n, n);
    stack<ll>s;
    for (ll i = 0; i < n; i++)
    {
        while (!s.empty() && arr[i] < arr[s.top()])
        {
            nextSmaller[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty())
    {
        s.pop();
    }


    // previous Smaller
    vector<ll>previousSmaller(n, -1);
    for (ll i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[i] <= arr[s.top()])
        {
            previousSmaller[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    // finding Answer
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        // right ContinousSum
        ll right_index = nextSmaller[i] - 1;
        ll left_index = i;

        ll a_part = continuousPresumRight[right_index] - arr[right_index] + mod;
        a_part %= mod;

        ll b_part = 0;
        if (right_index > 0)
        {
            b_part += presum[right_index - 1];
        }
        if (left_index > 0)
        {
            b_part -= presum[left_index - 1];
        }
        b_part += mod;
        b_part %= mod;

        ll sum1 = continuousPresumRight[left_index] - a_part - (b_part * (n - 1 - right_index)) % mod + 2 * mod;
        sum1 %= mod;

        // left continuous
        left_index = previousSmaller[i] + 1;
        right_index = i;

        a_part = continuousPresumLeft[left_index] - arr[left_index] + mod;
        b_part =  presum[right_index] - presum[left_index] + mod;
        a_part %= mod;
        b_part %= mod;
        ll sum2 = continuousPresumLeft[right_index] - a_part - (b_part * (left_index)) % mod + 2 * mod ;
        sum2 %= mod;



        ll finalvalue = ( (sum1 * (i - previousSmaller[i])) % mod   + (sum2 * (nextSmaller[i] - i)) % mod - ((i - previousSmaller[i]) * (nextSmaller[i] - i)) % mod * arr[i]) % mod * arr[i];
        finalvalue %= mod;
        cout << finalvalue << " ";
        ans += finalvalue;
    }
    cout << "\n";
    cout << ans << "\n";

    return 0;

}