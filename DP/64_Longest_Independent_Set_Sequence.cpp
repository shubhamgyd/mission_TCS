// In this problem we are going to find the maximum independent set of number who don't have direct connection 
/* Dynamic programming based program
for Largest Independent Set problem */



#include <bits/stdc++.h>
using namespace std;

// A utility function to find max of two integers
int max(int x, int y) { return (x > y)? x: y; }

/* A binary tree node has data, pointer
to left child and a pointer to
right child */
class node
{
	public:
	int data;
	int liss;
	node *left, *right;
};


/*
Alternative Way


// By using this method we can find the maximum sum with the given condition
// Changes: return 1 ---> root->data
//          incl=1------> root->data;


int LISS(Node *root)
{
    //Code here
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL && root->right==NULL)
    {
        return 1;
    }
    
    int excl=LISS(root->left)+LISS(root->right);
    int incl=1;
    if(root->left)
    {
        incl+=LISS(root->left->left)+LISS(root->left->right);
    }
    if(root->right)
    {
        incl+=LISS(root->right->left)+LISS(root->right->right);
    }
    return max(incl,excl);
}
*/


// A memoization function returns size
// of the largest independent set in
// a given binary tree
int LISS(node *root)
{
	if (root == NULL)
		return 0;

	if (root->liss)
		return root->liss;

	if (root->left == NULL && root->right == NULL)
		return (root->liss = 1);

	// Calculate size excluding the current node
	int liss_excl = LISS(root->left) + LISS(root->right);

	// Calculate size including the current node
	int liss_incl = 1;
	if (root->left)
		liss_incl += LISS(root->left->left) + LISS(root->left->right);
	if (root->right)
		liss_incl += LISS(root->right->left) + LISS(root->right->right);

	// Maximum of two sizes is LISS, store it for future uses.
	root->liss = max(liss_incl, liss_excl);

	return root->liss;
}

// A utility function to create a node
node* newNode(int data)
{
	node* temp = new node();
	temp->data = data;
	temp->left = temp->right = NULL;
	temp->liss = 0;
	return temp;
}

// Driver code
int main()
{
	// Let us construct the tree
	// given in the above diagram
	node *root	 = newNode(20);
	root->left		 = newNode(8);
	root->left->left	 = newNode(4);
	root->left->right	 = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);
	root->right		 = newNode(22);
	root->right->right	 = newNode(25);

	cout << "Size of the Largest Independent Set is " << LISS(root);

	return 0;
}




















// Another Way


// C++ implementation for the above approach
#include <bits/stdc++.h>
using namespace std;

// An utility function to add an edge in the tree
void addEdge(vector<int> adj[], int x, int y)
{
	adj[x].push_back(y);
	adj[y].push_back(x);
}

void dfs(vector<int> adj[], vector<int> dp[], int src,
		int par)
{
	for (auto child : adj[src]) {
		if (child != par)
			dfs(adj, dp, child, src);
	}

	for (auto child : adj[src]) {
		if (child != par) {
			// not including source in the vertex cover
			dp[src][0] += dp[child][1];

			// including source in the vertex cover
			dp[src][1] += min(dp[child][1], dp[child][0]);
		}
	}
}

// function to find minimum size of vertex cover
void minSizeVertexCover(vector<int> adj[], int N)
{
	vector<int> dp[N + 1];

	for (int i = 1; i <= N; i++) {
		// 0 denotes not included in vertex cover
		dp[i].push_back(0);

		// 1 denotes included in vertex cover
		dp[i].push_back(1);
	}

	dfs(adj, dp, 1, -1);

	// printing minimum size vertex cover
	cout << min(dp[1][0], dp[1][1]) << endl;
}

// Driver Code
int main()
{
	/*						 1

						/		 \

					2			 7

			/			 \

			3			 6

	/	 |	 \

4		 8		 5
	
*/
	
	// number of nodes in the tree
	int N = 8;

	// adjacency list representation of the tree
	vector<int> adj[N + 1];

	addEdge(adj, 1, 2);
	addEdge(adj, 1, 7);
	addEdge(adj, 2, 3);
	addEdge(adj, 2, 6);
	addEdge(adj, 3, 4);
	addEdge(adj, 3, 8);
	addEdge(adj, 3, 5);

	minSizeVertexCover(adj, N);

	return 0;
}
