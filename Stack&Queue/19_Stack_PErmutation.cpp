// In this problem we are going to check given two arrays are stack permutation or not
#include<bits/stdc++.h>
using namespace std;

bool Permutation1(int arr1[],int arr2[],int n)
{
    queue<int>input;
    for(int i=0;i<n;i++)
    {
        input.push(arr1[i]);
    }
    queue<int>output;
    for(int i=0;i<n;i++)
    {
        output.push(arr2[i]);
    }
    stack<int>st;
    while(!input.empty())
    {
        int ele=input.front();
        input.pop();
        if(ele==output.front())
        {
            output.pop();
            while(!st.empty())
            {
                if(st.top()==output.front())
                {
                    st.pop();
                    output.pop();
                }
                else  break;
            }
        }
        else
        {
            st.push(ele);
        }
    }
    return (st.empty()&&input.empty());
}

int main()
{
    int arr1[]={1,2,3};
    int arr2[]={2,1,3};
    int n=sizeof(arr1)/sizeof(arr1[0]);
    if(Permutation1(arr1,arr2,n))
    {
        cout<<"Possible"<<endl;
    }
    else
    {
        cout<<"Not Possible"<<endl;
    }
    return 0;
}