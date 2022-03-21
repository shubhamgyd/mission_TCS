#include<bits/stdc++.h>
using namespace std;



void multiplyMatrices(int row1,int col1,int row2,int col2,float **mat1,float **mat2)
{
    float mat3[row1][col2];
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            mat3[i][j] = 0;
            for (int k = 0; k < row2; k++) {
                mat3[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    cout<<"\nMatrix Multiplication "<<endl;
    for(int i=0;i<row1;i++)
    {
        for(int j=0;j<col2;j++)
        {
            cout<<fixed<<setprecision(2)<<mat3[i][j]<<"\t";
        }
        cout<<endl;
    }
}


int main()
{
    int row1,col1,row2,col2;
    cout<<"Enter row and column of matrix 1: ";
    cin>>row1>>col1;
    cout<<"Enter row and column of matrix 2: ";
    cin>>row2>>col2;

    if(col1!=row2)
    {
        cout<<"Invalid Matrix Dimenstions"<<endl;
        return 0;
    }
    // float mat1[row1][col1];
    // float mat2[row2][col2];
    float **mat1;
    float **mat2;
    mat1 = new float *[row1];
    mat2 = new float *[row2];
    for(int i = 0; i <row1; i++)
    {
        mat1[i] = new float[col1];
    }
    for(int i = 0; i <row2; i++)
    {
        mat2[i] = new float[col2];
    }

    cout<<"Enter matrix 1 elements: "<<endl;
    for(int i=0;i<row1;i++)
    {
        for(int j=0;j<col1;j++)
        {
            cin>>mat1[i][j];
        }
    }
    cout<<"\nEnter matrix 2 elements: "<<endl;
    for(int i=0;i<row2;i++)
    {
        for(int j=0;j<col2;j++)
        {
            cin>>mat2[i][j];
        }
    }

    multiplyMatrices(row1,col1,row2,col2,mat1,mat2);
    return 0;

}