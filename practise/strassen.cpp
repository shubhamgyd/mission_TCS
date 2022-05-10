#include<bits/stdc++.h>
using namespace std;



void addMatrix(vector<vector<int>>A,vector<vector<int>>B,vector<vector<int>>&C,int split_index)
{
    for(int i=0;i<split_index;i++)
    {
        for(int j=0;j<split_index;j++)
        {
            C[i][j]=A[i][j]+B[i][j];
        }
    }
}

vector<vector<int>> solve(vector<vector<int>>&A,vector<vector<int>>&B,int n,int m)
{
    int row1=A.size();
    int col1=A[0].size();

    int row2=B.size();
    int col2=B[0].size();


    if(col1!=row2)
    {
        cout<<"Invalid matrices"<<endl;
        return {};
    }

    vector<int>result_matrix_row(col2,0);
    vector<vector<int>>result_matrix(row1,result_matrix_row);

    if(col1==1)
    {
        result_matrix[0][0]=A[0][0]*B[0][0];
    }
    else
    {
        int split_index=col1/2;


        vector<int>row_vector(split_index,0);
        vector<vector<int>>result_matrix_00(split_index,row_vector);
        vector<vector<int>>result_matrix_01(split_index,row_vector);
        vector<vector<int>>result_matrix_10(split_index,row_vector);
        vector<vector<int>>result_matrix_11(split_index,row_vector);

        vector<vector<int>>a00(split_index,row_vector);
        vector<vector<int>>a01(split_index,row_vector);
        vector<vector<int>>a10(split_index,row_vector);
        vector<vector<int>>a11(split_index,row_vector);
        vector<vector<int>>b00(split_index,row_vector);
        vector<vector<int>>b01(split_index,row_vector);
        vector<vector<int>>b10(split_index,row_vector);
        vector<vector<int>>b11(split_index,row_vector);

        for(int i=0;i<split_index;i++)
        {
            for(int j=0;j<split_index;j++)
            {  
                a00[i][j]=A[i][j];
                a01[i][j]=A[i][j+split_index];
                a10[i][j]=A[i+split_index][j];
                a11[i][j]=A[i+split_index][j+split_index];


                b00[i][j]=B[i][j];
                b01[i][j]=B[i][j+split_index];
                b10[i][j]=B[i+split_index][j];
                b11[i][j]=B[i+split_index][j+split_index];
            }
        }


        addMatrix(solve(a00,b00,n,m),solve(a01,b10,n,m),result_matrix_00,split_index);
        addMatrix(solve(a00,b01,n,m),solve(a01,b11,n,m),result_matrix_01,split_index);
        addMatrix(solve(a10,b00,n,m),solve(a11,b10,n,m),result_matrix_10,split_index);
        addMatrix(solve(a10,b01,n,m),solve(a11,b11,n,m),result_matrix_11,split_index);


        for(int i=0;i<split_index;i++)
        {
            for(int j=0;j<split_index;j++)
            {
                result_matrix[i][j]=result_matrix_00[i][j];
                result_matrix[i][j+split_index]=result_matrix_01[i][j];
                result_matrix[i+split_index][j]=result_matrix_10[i][j];
                result_matrix[i+split_index][j+split_index]=result_matrix_11[i][j];
            }
        }

        result_matrix_00.clear();
        result_matrix_01.clear();
        result_matrix_10.clear();
        result_matrix_11.clear();
        a00.clear();
        a01.clear();
        a10.clear();
        a11.clear();
        b00.clear();
        b01.clear();
        b10.clear();
        b11.clear();
    }
    return result_matrix;

    
}


int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>A(n,vector<int>(m)),B(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>A[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>B[i][j];
        }
    }

    vector<vector<int>>res=solve(A,B,n,m);
    cout<<"Matrix Multiplication : "<<endl;
    for(auto it:res)
    {
        for(auto ele:it)
        {
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;

    
}
// Time Complexity: O(n^3)