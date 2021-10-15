#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

vector<vector<pi> > graph;

void addedge(int x, int y, int cost)
{
	graph[x].push_back(make_pair(cost, y));
	graph[y].push_back(make_pair(cost, x));
}

void best_first_search(int source, int target, int n)
{
	vector<bool> visited(n, false);
	// MIN HEAP priority queue
	priority_queue<pi, vector<pi>, greater<pi> > pq;
	pq.push(make_pair(0, source));
	int s = source;
	visited[s] = true;
	while (!pq.empty()) {
		int x = pq.top().second;
		cout << x << " ";
		pq.pop();
		if (x == target)
			break;

		for (int i = 0; i < graph[x].size(); i++) {
			if (!visited[graph[x][i].second]) {
				visited[graph[x][i].second] = true;
				pq.push(make_pair(graph[x][i].first,graph[x][i].second));
			}
		}
	}
}

int main()
{

	int v, n, x, y, cost;
    int i, source, target;
    char ch;

    cout<<"\nEnter the number of nodes:\n";
    cin>>v;
    graph.resize(v+1);

    cout<<"\nEnter the number of edges:\n";
    cin>>n;

    cout<<"\nEnter the edges with its cost as(x, y, cost):\n";
    for(i=0;i<n;i++){
        cin>>x;
        cin>>y;
        cin>>cost;
        addedge(x, y, cost);
    }

    do{
    cout<<"\nEnter the source node:\n";
	cin>>source;
    cout<<"\nEnter the target node:\n";
    cin>>target;
    best_first_search(source, target, v);
    cout<<"\nIf you want to continue press 'Y' or 'y'\n";
    cin>>ch;
    }while (ch=='y' || ch=='Y');
    
	return 0;
}


/*
1. select loan-number
from loanRelation
where branchName='Perryridge' and amount>1200

2. slect loan-number
from loanRelations
where amount>=500 and amount<=1000

3. select borrower.customerName borrower.loanNumber
from borrower
full outer join on loan where borrower.loanNumber=loan.loanNumber
where branchName='Perryridge'

4. select borrower.customerName borrower.loanNumber
from borrower
right join on loan where borrower.loanNumber=loan.loanNumber
where branchName='Perryridge'


5. select distinct T.branch-name
from branch as T, branch as S
where T.assets > S.assets and S.branch-city = "Brooklyn"

6. select customer-name
from customer
where customer-street like "%Main%"

7.
*/