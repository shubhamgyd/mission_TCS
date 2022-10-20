#include <iostream>
#include <vector>
using namespace std;

// function will kill the every mth person starting from index
void solve(int n, int m, vector<int> &arr, int k)
{
    // if last person remain
    // kill him/her
    if (arr.size() == 1)
    {
        cout << arr[0] << endl;
        return;
    }
    // get the next index to kill him/her
    k = (k + m) % arr.size();

    // kill kth person
    cout << arr[k] << " ";
    // remove him/her from array
    arr.erase(arr.begin() + k);
    // go to next person
    solve(n, m, arr, k);
    return;
}

int main()
{
    cout << endl;
    cout << endl;
    // Input of n-> number of persons
    // k -> starting index of person
    // m-> kill the mth person starting from k
    int n, k, m;
    cin >> n >> k >> m;
    // Store the n persons in array
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        arr.push_back(i + 1);
    }
    // Person to kill by previous man
    //  starting with kth index

    // Initially kth person so count is 1
    m--;

    // starting index of person
    // from where onwards we will kill the mth person including himself
    int index = k - 1;
    solve(n, m, arr, index);
    return 0;
}