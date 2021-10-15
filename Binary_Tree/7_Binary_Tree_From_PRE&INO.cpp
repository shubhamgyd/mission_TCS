
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
//int preindex=0;
class Solution{
    // Node* tree(vector<int>&v,int i,int j)
    // {
    //     if(i>j)
    //     {
    //         return NULL;
    //     }
    //     int mid=(j+i)/2;
    //     struct Node* root=new Node(v[mid]);
    //     if(i==j)
    //     {
    //         return root;
    //     }
    //     root->left=tree(v,i,mid-1);
    //     root->right=tree(v,mid+1,j);
    //     return root;
    // }
    
    //int preindex=0;
    Node* tree(int pre[],map<int,int>&mp,int i,int j,int &preindex)
    {
        if(i>j)
        {
            return NULL;
        }
        Node* node= new Node(pre[preindex++]);
        if(i==j)
        {
            return node;
        }
        int mid=mp[node->data];
        node->left=tree(pre,mp,i,mid-1,preindex);
        node->right=tree(pre,mp,mid+1,j,preindex);
        return node;
        
    }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        //int size=sizeof(pre);
        int preindex=0;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[in[i]]=i;
        }
        //int preindex=0;
        return tree(pre,mp,0,n-1,preindex);
        // vector<int>v;
        // for(int i=0;i<n;i++)
        // {
        //     v.push_back(in[i]);
        // }
        // sort(v.begin(),v.end());
        // return tree(v,0,v.size()-1);

        
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends