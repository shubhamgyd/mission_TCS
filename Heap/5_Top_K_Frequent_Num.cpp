// In this problem we are going to find the top k frequent numbers from the given array

#include<bits/stdc++.h>
using namespace std;

struct compare {
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        // if frequencies of two elements are same
        // then the larger number should come first
        if (p1.second == p2.second)
            return p1.first < p2.first;
 
        // insert elements in the priority queue on the basis of
        // decreasing order of frequencies
        return p1.second < p2.second;
    }
};

int main()
{
    int arr[]={1,2,4,3,1,2,1,4,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    unordered_map<int,int>um;
    for(int i=0;i<n;i++)
    {
        um[arr[i]]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int> >,compare> pq(um.begin(), um.end());
    cout<<endl;
    cout<<"K most frequent elements from the array are: "<<endl;
    for(int i=1;i<=k;i++)
    {
        cout<<pq.top().first<<" ";
        pq.pop();
    }


}


/*

// For sorting according to frequency sort


vector<int> frequency_sort(vector<int> v) {
	unordered_map<int, int> mp;
	for (int i = 0; i < v.size(); i++) {
		mp[v[i]] ++;
	}
	priority_queue <pair<int, int>> pq;
	for (auto i = mp.begin(); i != mp.end(); i++) {
		pq.push({i->second, i->first});
	}
	vector<int> result;
	while (!pq.empty()) {
		int times = pq.top().first;
		for (int j = 0; j < times; j++) {
			result.push_back(pq.top().second);
		}
		pq.pop();
	}
	return result;
}

*/