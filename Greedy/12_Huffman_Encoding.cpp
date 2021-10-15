#include<bits/stdc++.h>
using namespace std;


class Solution
{
    vector<string>res;
    struct HufNode
    {
        char data;
        unsigned freq;
        HufNode *left,*right;
        HufNode(char data,unsigned freq)
        {
            left=right=NULL;
            this->data=data;
            this->freq=freq;
        }
    };
    
    struct compare {
 
    bool operator()(HufNode* l, HufNode* r)
 
    {
        return (l->freq > r->freq);
    }
};
 
    
    void PrintNodes(HufNode* root,string str)
    {
        if(!root)
        {
            return;
        }
        if(root->data!='$')
        {
            res.push_back(str);
        }
        PrintNodes(root->left,str+"0");
        PrintNodes(root->right,str+"1");
    }
	public:
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    HufNode *l,*r,*top;
		    priority_queue<HufNode*,vector<HufNode*>,compare>pq;
		    for(int i=0;i<N;i++)
		    {
		        pq.push(new HufNode(S[i],f[i]));
		    }
		    while(pq.size()!=1)
		    {
		        l=pq.top();
		        pq.pop();
		        
		        r=pq.top();
		        pq.pop();
		        
		        
		        top= new HufNode('$',l->freq+r->freq);
		        top->left=l;
		        top->right=r;
		        pq.push(top);
		    }
		    PrintNodes(pq.top(),"");
		    return res;
		}
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}  // } Driver Code Ends