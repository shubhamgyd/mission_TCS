// // Same as previous one ..we have to just changes in the induction part i.e. in temp value and the ans value
// // Basically in this que we are finding the hight of  a binary tree

// #include<bits/stdc++.h>
// using namespace std;


// // struct to create tree metadata
// struct BstNode {
//         int data;
//         BstNode* left;
//         BstNode* right;
// };

// //Function to get the new node for inserting 
// BstNode*  GetNewNode(int data){
//        BstNode* newNode = new BstNode();
//        newNode->data=data;
//        newNode->left=NULL;
//        newNode->right=NULL;
//        return newNode;
// }


// // Function to insert new node in the tree
// BstNode* Insert(BstNode* root,int data){
//       if(root==NULL)
//       {
//               root=GetNewNode(data);
//               return root;
//       }
//       else if(data<=root->data)
//       {
//               root->left=Insert(root->left,data);
//       }
//       else
//       {
//               root->right=Insert(root->right,data);
//       }
//       return root;
// }

// int diameter(BstNode* root,int& res)
// {
//     // Base condition of a root
//     if(root==NULL)
//     {
//         return 0;
//     }

//     // Hypothesis step ..this both conditions wil find their task automatically , we don't have to think
//     // it
//     int l=diameter(root->left,res);
//     int r=diameter(root->right,res);

//     // Induction step .. here we have to implement some relation
//     //like
//     int temp=max(max(l,r)+root->data,root->data);
//     int ans=max(temp,l+r+root->data);
//     res=max(res,ans);
//     return temp;
    
// }


// struct BstNode* newNode(int data)
// {
//     //BSTNode *node =(struct BSTNode*)malloc(sizeof(struct BSTNode));
//     BstNode* node=(struct BstNode*)malloc(sizeof(struct BstNode));
//     node->data = data;
//     node->left = node->right = NULL;
 
//     return (node);
// }
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     // BstNode* root=NULL;
//     // root=Insert(root,-10);
//     // root=Insert(root,9);
//     // root=Insert(root,20);
//     // root=Insert(root,NULL);
//     // root=Insert(root,NULL);
//     // root=Insert(root,15);
//     // root=Insert(root,7);

//     struct BstNode* root = newNode(1);
//     root->left = newNode(2);
//     root->right = newNode(3);
//     root->left->left = newNode(4);
//     root->left->right = newNode(5);

//     int res=INT_MIN;
//     diameter(root,res);
//     cout<<"Maximum Sum of Path from node to node is: "<<res<<'\n';
//     return 0;
// }





#include <bits/stdc++.h>

using namespace std;

// Tree Node
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
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
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
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

#define ll long long 
ll res;
class Solution {
    //int res;
    ll solve(Node* root)
    {
        if(root == NULL)
        return INT_MIN;
        
        ll l1 = solve(root->left);
        
        ll l2 = solve(root->right);
        
        if(!(root->left == NULL || root->right == NULL))
        res = max(res,l1 + l2 + (root->data));
        
        if(l1 == INT_MIN && l2 == INT_MIN)
        return (root->data);
        else
        return (max(l1,l2) + (root->data));
    }
public:
    int maxPathSum(Node* root)
    {
        // code here
        res=INT_MIN;
        ll v=solve(root);
        return res==INT_MIN?v:res;
    }
};

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        cout << ob.maxPathSum(root) << "\n";
    }
    return 0;
}  // } Driver Code Ends