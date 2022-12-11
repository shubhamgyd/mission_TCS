#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
using namespace std;

// Remove the odd integers from v.
// It is acceptable if the order of the remaining even integers is not
// the same as in the original vector.
void removeOdds(vector<int> &v)
{
    // get size of v
    int n = v.size();
    // pointer points to the 0th index, basically
    // it will only get the even elements
    int j = 0;
    // get totalEven elements from the array
    int totalEven = 0;
    // Iterate vector and remove odd elements
    for (int i = 0; i < n; i++)
    {
        // if number is even
        // then push it into the jth index
        // else if odd element then ignore it
        if (v[i] % 2 == 0)
        {
            // push ith element at the jth position
            v[j] = v[i];
            // increment the j
            j++;
            // increment totalEven elements
            totalEven++;
        }
    }
    // resize the size of vector i.e. equal to the totalEven elements presents in the array
    v.resize(totalEven);
}

void test2()
{
    int a[8] = {2, 8, 5, 6, 7, 3, 4, 1};
    vector<int> x(a, a + 8); // construct x from the array
    assert(x.size() == 8 && x.front() == 2 && x.back() == 1);
    removeOdds(x);
    assert(x.size() == 4);
    sort(x.begin(), x.end());
    int expect[4] = {2, 4, 6, 8};
    for (int k = 0; k < 4; k++)
        assert(x[k] == expect[k]);
}

int main()
{
    test2();
    cout << "Passed" << endl;
}