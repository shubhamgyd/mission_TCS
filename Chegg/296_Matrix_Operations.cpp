#include <iostream>
#include <vector>
using namespace std;

class Matrix
{
private:
    int values[3][3];

public:
    // Default constructor
    Matrix()
    {
        for (int r = 0; r < 3; r++)
        {
            for (int c = 0; c < 3; c++)
            {
                values[r][c] = 0;
            }
        }
    }
    // Paramaterize constructor to initialize  matrix
    Matrix(vector<vector<int>> &mat)
    {
        for (int r = 0; r < 3; r++)
        {
            for (int c = 0; c < 3; c++)
            {
                values[r][c] = mat[r][c];
            }
        }
    }
    void inputMatrix(vector<vector<int>> &A);

    // Functions for operator overloading
    void operator+(Matrix x);
    void operator-(Matrix x);
    void operator*(Matrix x);
    void operator*(int num);
};

void Matrix::operator+(Matrix mat)
{
    // To store the sum of Matrices
    int ans[3][3];

    // Traverse Matrix and Add the corresponding elements
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ans[i][j] = values[i][j] + mat.values[i][j];
        }
    }

    // Display the sum of Matrices
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
}

void Matrix::operator*(Matrix mat)
{
    // To store the multiplication of Matrices
    int ans[3][3];

    // Traverse Matrix and multiply the corresponding element
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ans[i][j] = 0;

            for (int k = 0; k < 3; k++)
            {
                ans[i][j] += values[i][k] * (mat.values[k][j]);
            }
        }
    }

    // Display the sum of Matrix element
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
}

void Matrix::operator*(int num)
{
    // To store the multiplication of Matrices
    int ans[3][3];

    // Traverse Matrix and multiply the corresponding element
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ans[i][j] = values[i][j] * num;
        }
    }

    // Display the sum of Matrix element
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    // Matrix A
    vector<vector<int>> mat1 = {{2, 3, 4},
                                {1, 2, 5},
                                {7, 3, 2}};

    // Matrix B
    vector<vector<int>> mat2 = {{5, 1, 4},
                                {3, 2, 3},
                                {4, 4, 4}};

    // Assign Matrix mat1 into A and mat2 into B
    Matrix A(mat1), B(mat2);
    // Perform Addition
    cout << "\nAddition of Matrices:\n";
    A + B;

    // Perform Substraction
    cout << "\nMultiplication of Matrices:\n";
    A *B;

    // Perform Multiplication with constant
    cout << "\nMultiplication of Matrix A with Constant:\n";
    A * 3;
}