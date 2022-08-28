/*
Given a two-dimensional integer array, points, return true if the three points you’re 
given do not form a straight line and false otherwise.

Ex: Given the following points…

points = [[1, 1,], [2, 2], [3, 3]], return false.
Ex: Given the following points…

points = [[1, 2], [4, 4], [2, 3]], return true.
*/

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int arr[3][3]={{1,1},{2,2},{3,3}};
    int x1=arr[0][0];
    int y1=arr[0][1];
    int x2=arr[1][0];
    int y2=arr[1][1];
    int x3=arr[2][0];
    int y3=arr[2][1];
    if((y3-y2)*(x2-x1)==(y2-y1)*(x3-x2))
    {
        cout<<"false"<<endl;
    }
    else
    {
        cout<<"true"<<endl;
    }
    return 0;
}