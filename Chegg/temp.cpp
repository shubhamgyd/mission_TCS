#include<bits/stdc++.h>
using namespace std;


int DigitSum(int dice,int num)
{
    if(dice%2==0)
    {
        int sum=0;
        string str=to_string(num);
        int n=str.length();
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                sum+=(str[i]-'0');
            }
        }
        return sum;
    }
    int sum=0;
    string str=to_string(num);
    int n=str.length();
    for(int i=0;i<n;i++)
    {
        if(i%2!=0)
        {
            sum+=(str[i]-'0');
        }
    }
    return sum;
}

int** Sort2DArrayByRow(int m,int n,int **arr)
{
    for(int i=0;i<m;i++)
    {
        vector<int>res(n);
        for(int j=0;j<n;j++)
        {
            res[j]=arr[i][j];
        }
        sort(res.begin(),res.end());
        for(int j=0;j<n;j++)
        {
            arr[i][j]=res[j];
        }
    }
    return arr;
}

int SumOfUncommonNum(int arr1[],int n,int arr2[],int m)
{
    unordered_map<int,int>mp,mp1;
    for(int i=0;i<n;i++)
    {
        mp[arr1[i]]++;
    }
    for(int i=0;i<m;i++)
    {
        mp1[arr2[i]]++;
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(mp1.find(arr1[i])==mp1.end()) sum+=arr1[i];
    }
    for(int i=0;i<m;i++)
    {
        if(mp.find(arr2[i])==mp.end()) sum+=arr2[i];
    }
    return sum;
}


string solve(int n,int m,int **arr)
{
    string str="";
    for(int i=0;i<n;i++)
    {
        
    }
}

int main()
{
    int dice;
    cin>>dice;
    int num;
    cin>>num;
    cout<<DigitSum(dice,num)<<endl;
    return 0;
}