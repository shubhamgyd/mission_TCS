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

Node* Solve(string str)
{
    stack<char>st;
    int temp=0;
    int i=0;
    while(i<str.length() && str[i]!='(' && str[i]!=')')
    {
        temp=temp*10+str[i]-'0';
        i++;
    }
    Node* root=new Node(temp);
    while(i<str.length())
    {
        if(str[i]=='(')
        {
            
        }

    }

}

int main()
{
    string str;
    cin>>str;
    Node* temp=Solve(str);
}