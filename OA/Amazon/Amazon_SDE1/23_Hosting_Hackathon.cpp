/*
Sliding Window problem:

You are hosting a hackathon.
Each team will have exactly teamSize developers.
A developer's skill level is denoted by skill[i].
The difference between the maximum and minimum skill levels within a team cannot exceed a 
threshold, maxDiff.
Determine the maximum number of teams that can be formed from the contestants.
Example:
skill = [3, 4, 3, 1, 6, 5], teamSize = 3, maxDiff = 2: At most, 2 teams can be 
formed: [3, 3, 1] and [4, 6, 5].
The difference between the maximum and minimum skill levels is 2 in each case,
 which does not exceed the threshold value of 2.
*/

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    int teamSize,mxDiff;
    cin>>teamSize>>mxDiff;
    sort(res.begin(),res.end());
    int ans=0;
    int i=0;
    while(i+teamSize-1<n)
    {
        if(res[i+teamSize-1]-res[i]<=mxDiff)
        {
            ans++;
            i=i+teamSize;
        }
        else
        {
            i++;
        }
    }
    cout<<ans<<endl;
    return 0;   
}


/*
Explanation: 
basically we are starting for 0 and trying to see whether we can make team including 0th person if yes the i = i+teamSize (i to i+teamSize-1) are in one team
if we cant that means we cant make team including ith person we will i+=1. This greedy approach will definitely work because
lets take array [a1 a2 a3 a4 a5 a6] teamSize = 3
if we can make team from a1 a2 a3 and we can also make team from a2 a3 a4. we should take a1 a2 a3 (as we might use a4 further teams. but if we can use a1 we can definitely use a4 in further teams. but if we can use a4 in further team it is not sure we can use a1.
to sum up we can say [a1 a2 a3] is optimal than [a2 a3 a3] as probability of a4 being choosen is more than a1. hope this helps to think why greedy is working.
you can ask your doubt if you have


Time complexity:O(n)
Space Complexity:O(1)

*/