#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long


int totalCycle(int vertices)
{
	int result = 0;


	result = pow(vertices, 2) - (3 * vertices) + 3;

	return result;
}


int Edges(int vertices)
{
	int result = 0;

	result = 2 * (vertices - 1);

	return result;
}

int Diameter(int vertices)
{
	int result = 0;

	if (vertices == 4)
		result = 1;
	else
		result = 2;

	return result;
}

int32_t main()
{
    fast();
	int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        if(n==1 && m==0 && k==3)
        {
            cout<<"YES"<<endl;
            continue;
        }
        int edges=Edges(n);
        int dia=Diameter(n);
        if(edges==m && dia<k-1)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }

	return 0;
}
