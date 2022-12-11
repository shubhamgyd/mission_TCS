#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function which returns the addition of two boolean vectors
vector<bool> addition(vector<bool> &v, vector<bool> &w)
{
    // get final result
    vector<bool> result;
    // get size of vector v
    int n = v.size();
    // get size of vector w
    int m = w.size();
    // keep track on carry
    int carry = 0;
    // point to the end of vectors
    int i = n - 1;
    int j = m - 1;
    // iterate until both array traersed or there is carry
    while (i >= 0 || j >= 0 || carry)
    {
        // get number from vector v
        // if i is greater than or equal to 0, then get num else assign 0
        // same for flag2
        bool flag1 = i >= 0 ? v[i] : 0;
        bool flag2 = j >= 0 ? w[j] : 0;

        // if carray is generated in previous step and both flags are 1
        // result will be 1 and carray will generate 1
        if (carry and flag1 and flag2)
        {
            result.push_back(1);
            carry = 1;
        }
        // else if carray is generated in previous step and there is one flag is true
        // then push 0 because 1 + 1 =0 and carray will be generate is 1
        else if (carry and (flag1 or flag2))
        {
            result.push_back(0);
            carry = 1;
        }
        // else if carray is generated in previous step and both flags are false
        // then push 1 and carry will be 0 becasue 0 + 0 =0 but there is carray
        // hence 0 + 1 = 1
        else if (carry and !flag1 and !flag2)
        {
            result.push_back(1);
            carry = 0;
        }
        // else if carray is not generated in previous step
        // and both flags are true
        // the push 1 and carray will be 1
        // 1 + 1 = 1
        // carry = 1
        else if (!carry and flag1 and flag2)
        {
            result.push_back(0);
            carry = 1;
        }
        // else if carray is not generated in previous step
        // and anyone flag is true
        // then push 1 and carry will be 0
        // 1+ 0 =1
        // carry =0
        else if (!carry and (flag1 or flag2))
        {
            result.push_back(1);
            carry = 0;
        }
        // else no carray generated, both flags are false
        else
        {
            result.push_back(0);
            carry = 0;
        }
        i--;
        j--;
    }
    // reverse to get desired result
    reverse(begin(result), end(result));
    // return result
    return result;
}

// Display final result
void print(vector<bool> &v)
{
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    // vector 1
    vector<bool> b1 = {1, 1, 0, 0, 1, 1, 0, 0, 0, 1};
    // vector 2
    vector<bool> b2 = {1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1};
    // get final result
    vector<bool> b3 = addition(b1, b2);
    // display  result
    print(b3);
}
