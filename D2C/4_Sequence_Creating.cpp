#include <bits/stdc++.h>
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long
#define mod 1000000007
using namespace std;
#define endl '\n'

void GetUniqueCountry(map<string, vector<string>> &country, vector<pair<int, string>> &res)
{
    cout << endl;
    cout << "Unique Contry names: " << endl;
    for (auto it : country)
    {
        res.push_back({it.second.size(), it.first});
        for (auto ele : it.second)
        {
            cout << ele << "->" << it.first << ",";
        }
    }
    cout << endl;
}

void CountryNameCount(vector<pair<int, string>> &res)
{
    cout << endl;
    cout << "Country names by their count: " << endl;
    sort(res.rbegin(), res.rend());
    for (auto it : res)
    {
        cout << it.second << ",";
    }
    cout << endl;
}

void HighesPhones(vector<pair<int, string>> &res)
{
    cout << endl;
    int val = res[0].first;
    cout << "Contry names having highes number of phone numbers: " << endl;
    for (auto it : res)
    {
        if (it.first == val)
        {
            cout << it.second << ",";
        }
        else
        {
            break;
        }
    }
    cout << endl;
}

int32_t main()
{
    // fast();
    vector<pair<int, string>> result;
    string myText;
    ifstream MyReadFile("sampleinput_21.txt");
    map<string, vector<string>> country;
    while (getline(MyReadFile, myText, ','))
    {
        string temp = myText;
        reverse(temp.begin(), temp.end());
        int i = 10;
        string s = "";
        for (i; i < temp.length(); i++)
        {
            s.push_back(temp[i]);
        }
        if (s == "1+")
        {
            country["Usa"].push_back(myText);
        }
        if (s == "19+")
        {
            country["India"].push_back(myText);
        }
        if (s == "44+")
        {
            country["UK"].push_back(myText);
        }
    }
    MyReadFile.close();
    int ch;
    do
    {
        cout << endl;
        cout << endl;
        cout << "#############################################\n";
        cout << "...............Country Tracker..............\n";
        cout << "#############################################\n";
        cout << "0. Exit from Program\n";
        cout << "1. Get Unique Contry names\n";
        cout << "2. Contry names by their count\n";
        cout << "3. Country name having highest phone numbers.\n";
        cout << "Enter your choice  : ";
        cin >> ch;
        switch (ch)
        {
        case 0:
            exit(0);
            break;
        case 1:
            GetUniqueCountry(country, result);
            break;
        case 2:
            CountryNameCount(result);
            break;
        case 3:
            HighesPhones(result);
            break;
        default:
            break;
        }
    } while (ch);
    return 0;
}