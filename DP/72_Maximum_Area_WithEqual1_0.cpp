// In this probelm we are going to find the Largest rectangular sub-matrix whose sum is 0
#include<bits/stdc++.h>
using namespace std;

bool sumZero(int temp[],int n,int* starti ,int* endj)
{
    map<int,int>mp;         // To store the presvious sum
    int sum=0;              // to store the currnt sum
    int max_len=0;          // Initialise the max len as zero

    for(int i=0;i<n;i++)
    {
        sum+=temp[i];           // add the element to sum for checking the length 

        if(temp[i]==0 && max_len==0)      // at the starting poisiotn means at zerothe positio
        {
            *starti=i;
            *endj=i;
            max_len=1;
        }
        if(sum==0)             // After first element , i.e from second position and onward
        {
            if(max_len<i+1)          // if the previous length legth is less than the current index +1
            {
                *starti=0;           // we can conclude that starti=0 and endj=i
                *endj=i;
            }
            max_len=i+1;             // Increase the length by 1
        }
        if(mp.find(sum)!=mp.end())           // If we find the previous sum in map i.e previous store element in in map is 1 and next element either 0 or 1 
        {
            int old = max_len;              // store it in variable , for updating
            max_len=max(max_len,i-mp[sum]); // Previously added index of this element i.e window size
            if(old<max_len)
            {
                // If max_length is updated then
                // enter and update start and end
                // point of array
                *endj=i;
                *starti=mp[sum]+1; 
            }
        }
        else
        {
            // Else insert this sum with
            // index in hash table
            mp[sum]=i;
        }
    }
    // Return true if max_length is non-zero
    return (max_len != 0);
}



// The intuition behind this problerm is we are intrating column wise instead of row wise

void sumZeroMat(vector<vector<int>>&arr,int n,int m)
{
    int temp[n];
    int fup=0,fdown=0,fleft=0,fright=0;       // for storing the index number 
    int up,down;
    int sum;
    int mxlen=INT_MIN;
    for(int i=0;i<m;i++)                  //  for every possible column
    {
        memset(temp,0,sizeof(temp));
        {
            for(int j=i;j<m;j++)
            {
                for(int k=0;k<n;k++)
                {
                    temp[k]+=arr[k][j];
                }
                bool sum=sumZero(temp,n,&up,&down);
                int ele=(down-up+1)*(j-i+1);           // Store the maximum area of reactangle which has sum=0
                // Compare no. of elements with previous
                // no. of elements in sub-Matrix.
                // If new sub-matrix has more elements
                // then update maxl and final boundaries
                // like fup, fdown, fleft, fright
                if(sum && ele>mxlen)
                {
                    fup=up;                       // Updated final up
                    fdown=down;                   // Updated final down
                    fleft=i;                      // Updated final left
                    fright=j;                    // Updated final right
                    mxlen=ele;                  // updated maxlen
                }
            }
        }
    }


    // If there is no change in boundaries
    // than check if a[0][0] is 0
    // If it not zero then print 
    // that no such zero-sum sub-matrix exists
    if (fup == 0 && fdown == 0 && fleft == 0 &&fright == 0 && arr[0][0] != 0) {
        cout << "No zero-sum sub-matrix exists";
        return;
    }
  
    // Print final values
    for (int j = fup; j <= fdown; j++)
    {
        for (int i = fleft; i <= fright; i++)
            cout << arr[j][i] << " ";
        cout << endl;
    }
    cout<<"Final Area is: "<<mxlen<<endl;
}



int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }

    sumZeroMat(arr,n,m);
    return 0;

    
}

// Another approach

// Intition behind this program is we are iterating row wise like we have traverse in previous question
// same concept is used in this program , just a little bit different

// #include<bits/stdc++.h>
// using namespace std;



// int subsum(vector<int>v ,int n)
// {
//     unordered_map<int,int>mp; // To storeing and updating the windpw size
//     int sum=0;                // to checking the current sum
//     int ma=1;                // At least 1 is must
//     for(int i=0;i<n;i++)
//     {
//         sum+=v[i];
//         if(sum==0)
//         {
//             ma=max(ma,i+1);         // sum is 0 till i , then update the ma length
//         }
//         else if(mp[sum])                  // If we find the sum in map, then update the ma length till this index 
//         {
//             ma=max(ma,i-mp[sum]+1);       // fetch the previously added index of this sum in map +1 increase the window length
//         }
//         else
//         {
//             mp[sum]=i;
//         }
//     }
//     return ma;
// }

// int main()
// {
//     int n,m;
//     cin>>n>>m;
//     vector<vector<int>>arr(n,vector<int>(m));
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             cin>>arr[i][j];
//         }
//     }

//     int mx=INT_MIN;
//     for(int i=0;i<n;i++)
//     {
//         vector<int>v(m);
//         for(int j=i;j<n;j++)
//         {
//             for(int k=0;k<m;k++)
//             {
//                 v[k]+=arr[j][k];
//             }
//             mx=max(mx,subsum(v,m)*(j-i+1));        //Window size to calculate the maximum area of ractangle
//         }
//     }
//     cout<<mx<<endl;

// }