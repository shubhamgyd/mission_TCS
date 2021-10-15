//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

vector <int> zigZagTraversal(Node* root);

int main()
{
    int t;
    scanf("%d ",&t);
  while (t--)
  {
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
        vector <int> res = zigZagTraversal(root);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout<<endl;
  }
  return 0;
}
// Contributed by: Hashit Sidhwa

// } Driver Code Ends


//User function Template for C++
/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

//Function to store the zig zag order traversal of tree in a list.
vector <int> zigZagTraversal(Node* root)
{
	// Code here
	if(!root)
	{
	    return {};
	}
	vector<int>v;
	deque<Node*>q;
	q.push_back(root);
	v.push_back(root->data);
	int l=1;
	Node* temp;
	while(!q.empty())
	{
	    int n=q.size();
	    for(int i=0;i<n;i++)
	    {
            // Popping Mechanism
	        if(l%2==0)
	        {
	            temp=q.back();
	            q.pop_back();
	        }
	        else
	        {
	            temp=q.front();
	            q.pop_front();
	        }
	        
            // Pushing Mechanism
	        if(l%2!=0)
	        {
	            if(temp->right)
	            {
	                q.push_back(temp->right);
	                v.push_back(temp->right->data);
	            }
	            if(temp->left)
	            {
	                q.push_back(temp->left);
	                v.push_back(temp->left->data);
	            }
	        }
	        else if(l%2==0)
	        {
	            if(temp->left)
	            {
	                q.push_front(temp->left);
	                v.push_back(temp->left->data);
	            }
	            if(temp->right)
	            {
	                q.push_front(temp->right);
	                v.push_back(temp->right->data);
	            }
	        }
	    }
	    l++;    //Increase level plus one
	}
	return v;
}