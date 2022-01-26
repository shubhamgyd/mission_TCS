#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum(vector<int> &candidates, int target, vector<vector<int> > &res, vector<int> &combination, int begin) {
        if (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {


            // for no infinite coins
            if(i && candidates[i]==candidates[i-1] && i>begin) continue;
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i+1);
            combination.pop_back();



            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
};

int main()
{
    vector<int>candidates={1,2,5};
    int sum;
    cin>>sum;
    Solution obj;
    vector<vector<int>>res=obj.combinationSum(candidates,sum);
    for(auto it:res)
    {
        cout<<sum<<"->";
        for(auto ele:it)
        {
            cout<<ele<<" ";
        }
        cout<<endl;
    }

    return 0;
}



// actual solution
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int f = (n-4)/5;
	int o;
	if( (n-5*f)%2 == 0) o=2;
	else o=1;
	int t=(n-5*f -o)/2;
	cout<<o+t+f<<" "<<f<<" "<<t<<" "<<o;
}