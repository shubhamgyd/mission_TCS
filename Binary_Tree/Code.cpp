#include <bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *left;
	struct Node *right;

	Node(char x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

struct Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node *root = new Node(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

			// Create the left child for the current Node
			currNode->left = new Node(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N") {

			// Create the right child for the current node
			currNode->right = new Node(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}


 // } Driver Code Ends
/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

class Solution {
    void inorder(Node* root,string str)
    {
        if(!root)
        {
            return;
        }
        inorder(root->left,str);
        str+=to_string(root->data);
        inorder(root->right,str);
    }
    
    bool longestRepeatedSubstring(string str)
{
    int n = str.length();
    int LCSRe[n+1][n+1];
 
    // Setting all to 0
    memset(LCSRe, 0, sizeof(LCSRe));
 
    string res; // To store result
    int res_length  = 0; // To store length of result
    int i, index = 0;
    for (i=1; i<=n; i++)
    {
        for (int j=i+1; j<=n; j++)
        {
            if (str[i-1] == str[j-1] &&
                LCSRe[i-1][j-1] < (j - i))
            {
                LCSRe[i][j] = LCSRe[i-1][j-1] + 1;
                if (LCSRe[i][j] > res_length)
                {
                    res_length = LCSRe[i][j];
                    index = max(i, index);
                }
            }
            else
                LCSRe[i][j] = 0;
        }
    }
 
    if (res_length > 0)
        for (i = index - res_length + 1; i <= index; i++)
            res.push_back(str[i-1]);
 
    return res.length()>=2?true:false;
}
    
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    int dupSub(Node *root) {
         // code here
         string str="";
         inorder(root,str);
         return longestRepeatedSubstring(str);
         
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin >> t;
	//cout << t << "\n";
	while (t--)
	{
		string treeString;
		getline(cin >> ws, treeString);
		struct Node* root = buildTree(treeString);
		Solution ob;
		cout << ob.dupSub(root) << "\n";
	}
	return 0;
}  // } Driver Code Ends