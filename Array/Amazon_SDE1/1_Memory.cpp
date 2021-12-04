#include<bits/stdc++.h>
using namespace std;

namespace Own
{
    class Solution
    {
    public:
        vector<vector<int>> solve(int maxTravelDist, vector<vector<int>> forwardRouteList, vector<vector<int>> returnRouteList)
        {
            vector<vector<int>>temp;
            if(maxTravelDist == 0) return temp;
            int maxdis=INT_MIN, s1 =0,s2=0;
            for(vector<int>& fwdRoute: forwardRouteList)
                for(vector<int>& retRoute: returnRouteList)
                    if (fwdRoute[1] + retRoute[1]==maxTravelDist)
                        temp.emplace_back(vector<int>{fwdRoute[0], retRoute[0]});
                    else if (fwdRoute[1] + retRoute[1] > maxdis and fwdRoute[1] + retRoute[1] <maxTravelDist)
                    {
                        
                        s1 = fwdRoute[0];
                        s2 = retRoute[0];
                        if(fwdRoute[1] + retRoute[1]>maxdis)
                        {
                            maxdis = fwdRoute[1] + retRoute[1];
                            temp.emplace_back(vector<int>{s1,s2});
                        }
                    }
            if(temp.size() == 0 and  s1 and  s2)
                temp.emplace_back(vector<int>{s1, s2});
            return temp;
        }
    };
}

vector<vector<int>> routePairs(int maxTravelDist, vector<vector<int>> forwardRouteList, vector<vector<int>> returnRouteList)
{
    Own::Solution obj;
    return obj.solve(maxTravelDist,forwardRouteList,returnRouteList);
}


int main()
{
    // int capacity;
    // cin>>capacity;
    // int f;
    // cin>>f;
    // vector<vector<int>>res;
    // for(int i=0;i<f;i++)
    // {
    //     int id,mem;
    //     cin>>id>>mem;
    //     res.push_back({id,mem});
    // }
    // int back;
    // cin>>back;
    // vector<vector<int>>b;
    // for(int i=0;i<back;i++)
    // {
    //     int id, mem;
    //     cin>>id>>mem;
    //     b.push_back({id,mem});
    // }
    // vector<vector<int>>ans=routePairs(capacity,res,b);
    // for(auto it:ans)
    // {
    //     for(auto ele:it)
    //     {
    //         cout<<ele<<" ";
    //     }
    //     cout<<endl;
    // }
    auto result = routePairs(10000,{{1,3000}, {2,5000}, {3,7000}, {4,10000}}, {{1,2000}, {2,3000}, {3,4000}, {4,5000}});

	for(auto vec: result)
	{
		for(auto num : vec)
			cout<<num<<"\t";
		cout<<"\n";
	}
    // priority_queue<pair<int,pair<int,int>>>pq;
    // vector<vector<int>>ans;
    // for(int i=0;i<f;i++)
    // {
    //     for(int j=0;j<back;j++)
    //     {
    //         int id1=res[i][0];
    //         int id2=b[j][0];
    //         int mem1=res[i][1];
    //         int mem2=b[j][1];
    //         if(mem1+mem2<=capacity)
    //         {
    //             pq.push({mem1+mem2,{id1,id2}});
    //         }   
    //     }
    // }
    // auto val=pq.top().first;
    // while(!pq.empty())
    // {
    //     auto mem=pq.top().first;
    //     int id1=pq.top().second.first;
    //     int id2=pq.top().second.second;
    //     pq.pop();
    //     if(mem==val)
    //     {
    //         ans.push_back({id1,id2});
    //     }
    //     else if(mem!=val)
    //     {
    //         break;
    //     }
    // }

    // for(auto it:ans)
    // {
    //     for(auto ele:it)
    //     {
    //         cout<<ele<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}