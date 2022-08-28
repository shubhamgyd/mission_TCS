#include<iostream>
using namespace std;

int main()
{
    // Input of Test Cases
    int test;
    cin>>test;
    // Till last Test Case
    while(test--)
    {
        // Input D
        int D;
        cin>>D;

        // Array of earnedMoney
        int earnedMoney[D];
        // Array of spentMoney
        int spentMoney[D];

        // Input of earnedMoney on ith Day
        for(int i=0;i<D;i++)
        {
            cin>>earnedMoney[i];
        }

        // Input of spentMoney on ith Day
        for(int i=0;i<D;i++)
        {
            cin>>spentMoney[i];
        }

        // Array which stores the totalEarning till ith Day
        int totalEarning[D];

        // 0th Day Earn
        totalEarning[0]=earnedMoney[0];
        for(int i=1;i<D;i++)
        {
            // Total Earning till ith Day
            totalEarning[i]=totalEarning[i-1]+earnedMoney[i];
        }

        // Array which stores the totalSpent till ith Day
        int totalSpent[D];

        // 0th Day Spent
        totalSpent[0]=spentMoney[0];
        for(int i=1;i<D;i++)
        {
            // Spent till ith Day
            totalSpent[i]=totalSpent[i-1]+spentMoney[i];
        }

        // Query
        int Q;
        cin>>Q;
        // array which stores the answer of ith query
        // if Farina is happy on ith Day ->1
        // else 0
        int ans[Q];
        int ind=0;
        while(Q--)
        {
            // Day inuput
            int x;
            cin>>x;
            // get totalEarnedMoney till xth Day
            int available=totalEarning[x];

            // get totalSpentMoney till xth Day
            int spent=totalSpent[x];

            // check the result
            int result=available-spent;
            // if Farina is UPSET->0
            if(result<0)
            {
                ans[ind++]=0;
            }
            // else ->1
            else
            {
                ans[ind++]=1;
            }
        }
        // Print the status of Farina on ith Day
        for(int i=0;i<ind;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;

    }
}