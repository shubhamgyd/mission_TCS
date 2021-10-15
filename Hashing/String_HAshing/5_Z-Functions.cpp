// In this problem we are going to find the suffix if the every character

#include<bits/stdc++.h>
using namespace std;

void z_function(string str)
{
    int n=str.length();
    vector<int>z(n,0);
    z[0]=0;
    for(int i=1;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(str[j-i]==str[j])
            {
                z[i]++;
            }
            else
            {
                break;
            }
        }
    }
    for(auto it:z)
    {
        cout<<it<<" ";
    }
}
/*
We just iterate through every position i and update z[i] for each one of them, starting from z[i]=0 
and incrementing it as long as we don't find a mismatch (and as long as we don't reach the end of the 
line).

Time complexity: O(n^2)
Space Complexity: O(n)
*/




void z_function1(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    for(auto it:z)
    {
        cout<<it<<" ";
    }
}
// Optimise version
// Time Complexity: O(n)
// Space Complexity: O(n)


int32_t main()
{
    string str;
    cin>>str;
    z_function(str);
    cout<<endl;
    z_function1(str);
    return 0;
}
/*
We will prove that the above algorithm has a running time that is linear in the length of the string -- thus, it's O(n).

The proof is very simple.

We are interested in the nested while loop, since everything else is just a bunch of constant operations which sums up to O(n).

We will show that each iteration of the while loop will increase the right border r of the match segment.

To do that, we will consider both branches of the algorithm:



i>r
In this case, either the while loop won't make any iteration (if s[0]≠s[i]), or it will take a few iterations, starting at position i, each time moving one character to the right. After that, the right border r will necessarily be updated.
So we have found that, when i>r, each iteration of the while loop increases the value of the new r index.



i≤r
In this case, we initialize z[i] to a certain value z0 given by the above formula. Let's compare this initial value z0 to the value r−i+1. We will have three cases:



z0<r−i+1
We prove that in this case no iteration of the while loop will take place.

It's easy to prove, for example, by contradiction: if the while loop made at least one iteration, it would mean that initial approximation z[i]=z0 was inaccurate (less than the match's actual length). But since s[l…r] and s[0…r−l] are the same, this would imply that z[i−l] holds the wrong value (less than it should be).

Thus, since z[i−l] is correct and it is less than r−i+1, it follows that this value coincides with the required value z[i].




z0=r−i+1
In this case, the while loop can make a few iterations, but each of them will lead to an increase in the value of the r index because we will start comparing from s[r+1], which will climb beyond the [l,r] interval.




z0>r−i+1
This option is impossible, by definition of z0.




So, we have proved that each iteration of the inner loop make the r pointer advance to the right. Since r can't be more than n−1, this means that the inner loop won't make more than n−1 iterations.

As the rest of the algorithm obviously works in O(n), we have proved that the whole algorithm for computing Z-functions runs in linear time.
*/