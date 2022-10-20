#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// functin which get the common subsequence length of string and target
int get_LCS(string input, string target, int n, int m)
{
    int commonStringTable[n + 1][m + 1];
    // if target have 0 length then common length string is 0
    for (int i = 0; i <= n; i++)
    {
        commonStringTable[i][0] = 0;
    }

    // if input string have 0 length then common string length is 0
    for (int j = 0; j <= m; j++)
    {
        commonStringTable[0][j] = 0;
    }

    // Iterate String and get the common subsequence length
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            // if input string and target string have common char
            // then increment the count
            if (input[i - 1] == target[j - 1])
            {
                commonStringTable[i][j] = 1 + commonStringTable[i - 1][j - 1];
            }
            // else get the maximum common length subsequence
            else
            {
                commonStringTable[i][j] = max(commonStringTable[i - 1][j], commonStringTable[i][j - 1]);
            }
        }
    }
    // return the common subsequence length
    return commonStringTable[n - 1][m - 1];
}

int main()
{
    // variables to store tune1,tune2,tune3, and target
    string tune1, tune2, tune3, target;
    // get tune1
    cin >> tune1;
    // get tune2
    cin >> tune2;
    // get tune3
    cin >> tune3;
    // get target
    cin >> target;
    // get target length
    int m = target.length();
    // vector to store the string and similarity ratio of string and target
    vector<pair<int, string>> rank;

    // for tune1
    // get length
    int n = tune1.length();
    // get longest common subsequence length between tune1 and target
    int length1 = get_LCS(tune1, target, n, m);
    // get total operations required to make both strings equal
    // here (n-length) = total number of insertions
    // here (m-length) = total number of deletions
    // so  formula = n+m-2*length
    int total1 = n + m - 2 * length1;
    // push number of operations and tune1
    rank.push_back({total1, tune1});

    // for tune2
    // get length
    n = tune2.length();
    // get longest common subsequence length between tune2 and target
    int length2 = get_LCS(tune2, target, n, m);
    // get total operations required to make both strings equal
    // here (n-length) = total number of insertions
    // here (m-length) = total number of deletions
    // so  formula = n+m-2*length
    int total2 = n + m - 2 * length2;
    // push number of operations and tune2
    rank.push_back({total2, tune2});

    // for tune3
    // get length
    n = tune3.length();
    // get longest common subsequence length between tune3 and target
    int length3 = get_LCS(tune3, target, n, m);
    // get total operations required to make both strings equal
    // here (n-length) = total number of insertions
    // here (m-length) = total number of deletions
    // so  formula = n+m-2*length
    int total3 = n + m - 2 * length3;
    // push number of operations and tune3
    rank.push_back({total3, tune3});

    // sort the rank vector based on the number of operations required to make both string
    // equal
    sort(begin(rank), end(rank));

    // print first string which have high similarity
    cout << "(" << rank[0].second << "), ";
    // print second string which have second high similarity
    cout << "(" << rank[1].second << "), ";
    // print third string which have third high similarity
    cout << "(" << rank[2].second << ")" << endl;
    return 0;
}
