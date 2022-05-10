// Famous problem

// In this peoblem we are going to find the maxumum area of hostogram by using stack
// By using the concept of previous smalletst elemen and next smallest element


// For explanation check previous question
#include<bits/stdc++.h>
using namespace std;


vector<int> PreSmaller(int arr[],int n)
{
    vector<int>v;
    stack<pair<int,int>>st;
    for(int i=0;i<n;i++)
    {
        if(st.size()==0)
        {
            v.push_back(-1);
        }

        else if(st.size()>0 && st.top().first<arr[i])
        {
            v.push_back(st.top().second);
        }
        else if(st.size()>0 && st.top().first>=arr[i])
        {
            while(st.size()>0 && st.top().first>=arr[i])
            {
                st.pop();
            }
            if(st.size()==0)
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(st.top().second);
            }
        }
        // pushing element with their index
        st.push({arr[i],i});
    }
    return v;
}

vector<int> NextSmaller(int arr[],int n)
{
    stack<pair<int,int>>s;
    vector<int>right;
    int pseudoIndex=n;
    for(int i=n-1;i>=0;i--)
    {
        if(s.size()==0)
        {
            right.push_back(pseudoIndex);
        }
        else if(s.size()>0 && s.top().first<arr[i])
        {
            right.push_back(s.top().second);
        }
        else if(s.size()>0 && s.top().first>=arr[i])
        {
            while(s.size()>0 && s.top().first>=arr[i])
            {
                s.pop();
            }
            if(s.size()==0)
            {
                right.push_back(pseudoIndex);
            }
            else
            {
                right.push_back(s.top().second);
            }
        }
        s.push({arr[i],i});
    }
    reverse(right.begin(),right.end());
    return right;
}

int main()
{
    int arr[]={2,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>left=PreSmaller(arr,n);
    vector<int>right=NextSmaller(arr,n);
    int weidth[n];                       // store the weidth of window size i.e maximum length
    for(int i=0;i<n;i++)
    {
        weidth[i]=right[i]-left[i]-1;
    }
    int area=INT_MIN;
    for(int i=0;i<n;i++)
    {
        area=max(area,weidth[i]*arr[i]);
    }
    cout<<area<<endl;
}