#include <iostream>
using namespace std;

int main()
{
    // Declaration of Matrix A and Matrix B
    int A[2][3];
    int B[3][2];
    // Input of Matrix A
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Enter A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }
    cout << endl;

    // Input of Matrix B
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "Enter B[" << i << "][" << j << "]: ";
            cin >> B[i][j];
        }
    }

    // Display of Matrix A
    cout << "\nMatrix A: \n";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    // Display of Matrix B
    cout << "\n Matrix B: \n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    // Declaration of Matrix C
    int C[2][2];
    // Here need to row of matrix a and column of matrix b must be equal
    // so resulting matrix row is equal to matrix a's row and column is equal to matrix b's columns
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            // Initially set 0
            C[i][j] = 0;
            // Iterate matrix a row wise and matrix b column wise
            // multiply and add them in resulting matrix C
            for (int k = 0; k < 3; k++)
            {
                C[i][j] += (A[i][k] * B[k][j]);
            }
        }
    }
    // Display matrix c
    cout << "Resultant Matrix: " << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}