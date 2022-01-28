/*
This question is asked by Google. Create a class CallCounter that 
tracks the number of calls a client has made within the last 3 seconds.
 Your class should contain one method, ping(int t) that receives the 
 current timestamp (in milliseconds) of a new call being made and returns 
 the number of calls made within the last 3 seconds.
Note: you may assume that the time associated with each subsequent call
 to ping is strictly increasing.

Ex: Given the following calls to ping…

ping(1), return 1 (1 call within the last 3 seconds)
ping(300), return 2 (2 calls within the last 3 seconds)
ping(3000), return 3 (3 calls within the last 3 seconds)
ping(3002), return 3 (3 calls within the last 3 seconds)
ping(7000), return 1 (1 call within the last 3 seconds)
*/

#include<bits/stdc++.h>
using namespace std;

class RecentCounter {
    vector<int>res;
    // multiset<int>st;
    int i;
public:
    RecentCounter() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        res=vector<int>();
        // st=multiset<int>();
        i=1;
    }
    
    int ping(int t) {
        // if(i==0)
        // {
        //     // res.push_back(t);
        //     st.insert(t);
        //     return 1;
        // }
        res.push_back(t);
        int lower=lower_bound(res.begin(),res.end(),t-3000)-res.begin();
        int upper=res.size()-1;
        return upper-lower+1;
        // st.insert(t);
        // sort(res.begin(),res.end());
        // auto start=st.lower_bound(t-3000);
        // auto end=st.lower_bound(t);
        // cout<<*start<<" "<<*end<<endl;
        // int range=distance(st.begin(),start);
        // int range1=distance(st.begin(), end);
        // cout<<range<<" "<<range1<<endl;
        // return *end-*start+1;
        // return range1-range+1;
        
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */