#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        vector<vector<int>>v;
        int n=arr.size();
        map<int,int>mp;
        for(int i=0;i<n-3;i++)
        {
            // vector<int>vp;
            for(int j=i+1;j<n-2;j++)
            {
                //vp.clear();
                int l=j+1;
                int t=n-1;
                while(l<t)
                {
                    vector<int>vp;
                    if(arr[i]+arr[j]+arr[l]+arr[t]==k)
                    {
                        vp.push_back(arr[i]);
                        vp.push_back(arr[j]);
                        vp.push_back(arr[l]);
                        vp.push_back(arr[t]);
                        l++;
                        t--;
                        v.push_back(vp);
                        //vp.clear();
                    }
                    else if(arr[i]+arr[j]+arr[l]+arr[t]<k)
                    {
                        l++;
                    }
                    else
                    {
                        t--;
                    }
                    // v.push_back(vp);
                }
                //v.push_back(vp);
                
            }
            //v.push_back(vp);
            
        }
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        return v;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends