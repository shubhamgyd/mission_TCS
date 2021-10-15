#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
private:
    unordered_map<int,pair<int,list<int>::iterator>> mp;
    list<int>accessed;
    int capacity;
    void erase(int key)
    {
        auto it=mp.find(key);
        assert(it!=mp.end());
        accessed.erase(it->second.second);
        mp.erase(key);
    }
    void push(int key,int v)
    {
        accessed.push_back(key);
        mp[key]={v,prev(accessed.end())};
    }
    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        capacity=cap;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        // your code here
        auto it=mp.find(key);
        if(it==mp.end())
        {
            return -1;
        }
        auto old_value=it->second.first;
        erase(key);
        push(key,old_value);
        return old_value;
    }
    
    //Function for storing key-value pair.
    void set(int key, int v)
    {
        // your code here 
        if(mp.find(key)!=mp.end())
        {
            erase(key);
        }
        if((int) mp.size() == capacity) {
            assert(!accessed.empty());
            erase(accessed.front());
        }
        push(key, v);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends