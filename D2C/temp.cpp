

#include <bits/stdc++.h>
using namespace std;

void combinationSum(vector<int> &candidates, int target, vector<int> &combination, int begin, int n,int &mx1)
{
    if (!target)
    {
        if (combination.size() == n)
        {
            // for(auto it:combination)
            // {
            //     cout<<it<<" ";
            // }
            // cout<<endl;
            sort(combination.begin(),combination.end());
            // res.push_back(combination);
            int flag=0;
            int mx=combination[0];
            cout<<combination[0]<<" ";
            for(int i=1;i<n;i++)
            {
                mx=max(mx,combination[i]);
                cout<<combination[i]<<" ";
                if (combination[i] >= combination[i - 1] && combination[i] <= 2 * combination[i - 1])
                {
                    continue;
                }
                else
                {
                    flag = 1;
                }
            }
            cout<<endl;
            if(flag==0)
            {
                mx1=max(mx1,mx);
            }
        }
        return;
    }
    for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i)
    {
        combination.push_back(candidates[i]);
        combinationSum(candidates, target - candidates[i], combination, i, n,mx1);
        combination.pop_back();
    }
}

int  combinationSum(vector<int> &candidates, int target, int n)
{
    vector<int> combination;
    int mx1=0;
    combinationSum(candidates, target, combination, 0, n,mx1);
    return mx1;
}

int main()
{
    int n;
    cin >> n;
    int target;
    cin >> target;
    vector<int> S(target);
    for (int i = 0; i < target; i++)
    {
        S[i] = i + 1;
    }
    int ans=combinationSum(S, target, n);
    cout<<ans<<endl;
    return 0;
}