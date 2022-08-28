/*
You are given a dataset represented as an integer array, nums that contains values between one and n. Inside the data set, an error has occurred such that one of the values between one and n has been duplicated to another number between one and n. Because of this, one of the values between one and n appears twice and one value does not appear at all. Return the missing value and the values that appears twice.

Ex: Given the following nums…

nums = [1, 3, 2, 5, 5], return [5, 4].
Ex: Given the following nums…

nums = [1, 2, 3, 3], return [3,4].
*/

#include<bits/stdc++.h>
using namespace std;
void printTwoElements(vector<int>arr, int size)
{
    int i;
    cout << "The repeating element is ";
 
    for (i = 0; i < size; i++) {
        if (arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        else
            cout << abs(arr[i]) << "\n";
    }
 
    cout << "and the missing element is ";
    for (i = 0; i < size; i++) {
        if (arr[i] > 0)
            cout << (i + 1);
    }
}

int main()
{
    vector<int>nums={1, 3, 2, 5, 5};
    int n=nums.size();
    int totalSum=n*(n+1)/2;
    printTwoElements(nums,n);

}