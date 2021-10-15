#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
class Solution{
    struct Node
    {
        int data , cnt;
        Node* left , *right;
        Node(int d)
        {
            data = d; cnt = 1;  left = right = NULL;
        }  
    };
    Node* Insert(Node* root,int data)
    {
        if(!root)
        {
            return new Node(data);
        }
        if(!root)
        return new Node(data);
        
        if(root->data > data)
        root->left = Insert(root->left , data);
        
        else if(root->data < data)
        root->right = Insert(root->right , data);
        
        root->cnt++;
        
        return root;
    }
    
    void Less_than_x(Node* root , int x , int& cnt)
    {
        if(!root)  return;
        
        if(root->data < x)
        {
            cnt += root->cnt - ((root->right) ? root->right->cnt : 0);
            
            Less_than_x(root->right , x , cnt);
        }
        
        else
        Less_than_x(root->left , x , cnt);
    }
public:
	vector<int> constructLowerArray(int *arr, int n) {
	   vector<int> a(n);
	    
	    Node* root = NULL;
	    
	    for(int i = n-1 ; i >= 0 ; i--)
	    {
	        int cnt = 0;
	        
	        Less_than_x(root , arr[i] , cnt);
	        
	        a[i] = cnt;
	        
	        root = Insert(root , arr[i]);
	    }
	    
	    return a;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.constructLowerArray(arr, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends