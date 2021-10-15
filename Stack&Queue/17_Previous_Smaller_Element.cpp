// In this problem we are going to find the index of nearest smallest integer to the left side

#include<bits/stdc++.h>
using namespace std;

vector<int> LeftSmaller(int arr[],int n)
{
    vector<int>v;
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        if(st.size()==0)
        {
            v.push_back(-1);                // If stack empty , then previous smaller is -1;
        }

        // if top of stack is smaller than current element , then print it
        else if(st.size()>0 && st.top()<arr[i])
        {
            v.push_back(st.top());
        }

        // if top of stack is greater than equal to current element 
        else if(st.size()>0 && st.top()>=arr[i])
        {
            // then iterate until top of stack is grater thean equal to current element
            while(st.size()>0 && st.top()>=arr[i])
            {
                st.pop();
            }

            // If stack becomes empety , means no one element is smaller than current element , then print -1
            if(st.size()==0)
            {
                v.push_back(-1);
            }

            // else print the top of the stack
            else
            {
                v.push_back(st.top());
            }
        }
        // Push into stak
        st.push(arr[i]);
    }
    return v;
}

// Explanation of next smaller is same just reverse the for loop and change the pseudoIndex as -1 to n


/*
Alternative Version: 

void printPrevSmaller(int arr[], int n)
{
    // Create an empty stack
    stack<int> S;
 
    // Traverse all array elements
    for (int i=0; i<n; i++)
    {
        // Keep removing top element from S while the top
        // element is greater than or equal to arr[i]
        while (!S.empty() && S.top() >= arr[i])
            S.pop();
 
        // If all elements in S were greater than arr[i]
        if (S.empty())
            cout << "_, ";
        else  //Else print the nearest smaller element
            cout << S.top() << ", ";
 
        // Push this element
        S.push(arr[i]);
    }
}

*/

int main()
{
    int arr[]={3,1,2,5,4,7,6,9,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>res=LeftSmaller(arr,n);
    for(auto it:res)
    {
        cout<<it<<" ";
    }
}