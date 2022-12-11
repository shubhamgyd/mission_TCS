#include <iostream>
#include <vector>
using namespace std;

// function which add only even item into the list
void InsertItemEven(int item, vector<int> &evenList)
{
    // if item is even then only add into the list
    if (item % 2 == 0)
    {
        evenList.push_back(item);
    }
}

int main()
{
    // unsorted list1
    int list1[7] = {6, 5, 9, 7, 1, 10, 5};
    // unsorted list2
    int list2[6] = {9, 2, 15, 5, 3, 8};
    // get result
    vector<int> summationList;
    // pointer to points at the starting of lists
    int i = 0;
    int j = 0;
    // size of list1
    int n = 7;
    // size of list2
    int m = 6;
    // Iterate until both lists
    while (i < n || j < m)
    {
        // if i is less than n then get ith index element from list1 else get 0
        int num1 = i < n ? list1[i] : 0;
        // if j is less than m then get jth index element from list2 else get 0
        int num2 = j < m ? list2[j] : 0;
        // add both
        int result = num1 + num2;
        // push into summation list
        summationList.push_back(result);
        // increment i and j
        i++;
        j++;
    }
    // Display result  list
    cout << "Result: ";
    for (int i = 0; i < summationList.size(); i++)
    {
        cout << summationList[i] << " ";
    }
    cout << endl;
    // get even items from the result list
    vector<int> evenList;
    for (int i = 0; i < summationList.size(); i++)
    {
        // function call to check ith item is even or not
        // if yes then push into the evenlist
        InsertItemEven(summationList[i], evenList);
    }
    // Display even list
    cout << "Even List: ";
    for (int i = 0; i < evenList.size(); i++)
    {
        cout << evenList[i] << " ";
    }
}