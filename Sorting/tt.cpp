#include <bits/stdc++.h>
using namespace std;

void smallest(vector<int> &nums, int n)
{
    sort(nums.begin(), nums.end());
}

// void solve(int arr[2][2])
// {
//     for(int i=0;i<2;i++)
//     {
//         for(int j=0;j<2;j++)
//         {
//             System.out.print(arr[i][j]+" "+);
//         }
//         System.out.println();
//     }
// }

// string solve(string s)
// {
//     string ans="";
//     int n=s.length();
//     int carry=0;
//     for(int i=n-1;i>=0;i--)
//     {
//         int num=(s[i]-'0');
//         num*=2;
//         num+=carry;
//         int temp=num%10;
//         ans.push_back((temp+'0'));
//         carry=num/10;
//     }
//     if(carry)
//     {
//         ans.push_back((carry+'0'));
//     }
//     reverse(ans.begin(),ans.end());
//    while(!ans.empty() and ans[0]=='0') ans.erase(ans.begin()+0);
//    return ans;

// }

void solve(int arr[], int n, int q, int query[])
{
    int prefix[n];
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    for (int i = 0; i < q; i++)
    {
        int ind = query[i] - 1;
        cout << prefix[ind] << endl;
    }
}

int mxCount(vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i)
    {
        int binaryNum[32];
        memset(binaryNum,0,sizeof(binaryNum));
        int j = 0;
        int num = arr[i];
        int temp=arr[i];
        while (num > 0)
        {
            binaryNum[j] = num % 2;
            num = num / 2;
            j++;
        }
        for (int k = 0; k < 32; k++)
        {
            if(binaryNum[k]) mp[k]++;
        }
    }
    int mx=0;
    for(auto it:mp)
    {
        if(it.second>mx)
        {
            mx=it.second;
        }
    }
    return mx;
}

int main()
{
    int i=3,j=5;
    if((i=0) and (j++))
    {
        cout<<"1 "<<i<<" "<<j<<endl;
    }
    else if((i++) and (j-5))
    {
        cout<<"2 "<<i<<" "<<j<<endl;
    }
    else
    {
        cout<<"3 "<<i<<" "<<j<<endl;
    }
}