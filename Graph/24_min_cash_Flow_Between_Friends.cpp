#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'



int getMin(int amount[],int n)
{
    int mnindex=0;
    for(int i=1;i<n;i++)
    {
        if(amount[i]<amount[mnindex])
        {
            mnindex=i;
        }
    }
    return mnindex;
}

int getMax(int amount[],int n)
{
    int mxindex=0;
    for(int i=1;i<n;i++)
    {
        if(amount[i]>amount[mxindex])
        {
            mxindex=i;
        }
    }
    return mxindex;
}

int minO2(int x,int y)
{
    return (x<y)?x:y;
}

void minCashFlowRec(int amount[],int n)
{
    // Find the indexes of minimum and maximum values in amount[]
    // amount[mxCredit] indicates the maximum amount to be given
    //                  (or credited) to any person .
    // And amount[mxDebit] indicates the maximum amount to be taken
    //                  (or debited) from any person.
    // So if there is a positive value in amount[], then there must
    // be a negative value
    int maxDebt=getMin(amount,n);
    int maxCredit=getMax(amount,n);

    // if both are 0 , then all amount are settle
    if(amount[maxCredit]==0 && amount[maxDebt]==0)
    {
        return;
    }

    // Find the minimum of two amounts
    int min=minO2(-amount[maxDebt],amount[maxCredit]);
    amount[maxCredit]-=min;
    amount[maxDebt]+=min;


    // If minimum is the maximum amount to be
    cout<<"Person "<<maxDebt<<" Pays "<<min<<" to"<<" Person "<<maxCredit<<endl;


    // Recur for the amount array.  Note that it is guaranteed that
    // the recursion would terminate as either amount[mxCredit]
    // or  amount[mxDebit] becomes 0
    minCashFlowRec(amount,n);

}

// Given a set of persons as graph[] where graph[i][j] indicates
// the amount that person i needs to pay person j, this function
// finds and prints the minimum cash flow to settle all debts.
void minCashFlow(vector<vector<int>>&graph)
{
    // Initialise all  the amout as 0
    int amount[graph.size()]={0};

    // Calculate the net amount to be paid to person 'p', and
    // stores it in amount[p]. The value of amount[p] can be
    // calculated by subtracting debts of 'p' from credits of 'p'
    for(int p=0;p<graph.size();p++)
    {
        for(int i=0;i<graph.size();i++)
        {
            amount[p]+=(graph[i][p]-graph[p][i]);
        }
    }
    minCashFlowRec(amount,graph.size());
}


int32_t main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
//     fast();
    int n;
    cin>>n;
    vector<vector<int>>graph(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int a;
            cin>>a;
            graph[i][j]=a;
        }
    }
    minCashFlow(graph);
    return 0;
}