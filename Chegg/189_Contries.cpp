#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cassert>
#include <set>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
    // Open file
    std::ifstream file("World_Champion.txt");

    std::string line;
    // Vector to store the winner countries
    vector<pair<string, pair<int, int>>> tempArray;
    int lineNo = 0;
    // Read file line by line
    while (getline(file, line))
    {
        // Ignore first line as it is only the column name
        if (lineNo == 0)
        {
            lineNo++;
            continue;
        }
        // get year
        int year = 0;
        // get country name
        string country = "";
        // get coachName
        string coachName = "";
        // get captainName
        string captainName = "";
        // indicated the presence of word
        int count = 0;
        // get char by char
        string word = "";
        // Iterate sentence
        for (int i = 0; i < line.length() - 1; i++)
        {
            // if year or country name or coachName or countryName appeared
            if (line[i] == '\\' and line[i + 1] == 't')
            {
                // if it is year
                if (count == 0)
                {
                    year = stoi(word);
                    word = "";
                    count++;
                }
                // If if is country name
                else if (count == 1)
                {
                    country = word;
                    word = "";
                    count++;
                }
                // if it is coachName
                else if (count == 2)
                {
                    coachName = word;
                    word = "";
                    count++;
                }
                i++;
            }
            // last word is nothing but the coach name
            else if (line[i] == '\\' and line[i + 1] == 'n')
            {
                captainName = word;
                word = "";
                i++;
            }
            // else push each char into the word
            else
            {
                word.push_back(line[i]);
            }
        }
        // push winner country into vector
        // [countryName, [winCount, year]]
        tempArray.push_back({country, {1, year}});
    }
    // Sort the winner contry array so that same country comes adjacent
    sort(tempArray.begin(), tempArray.end());
    // vector to store the winner country , their count and year at which year winned
    vector<pair<string, pair<int, vector<int>>>> winners;
    // get size
    int n = tempArray.size();
    int i = 0;
    // Start from 0th index
    while (i < n)
    {
        int j = i;
        // get totalCount of winning
        int count = 0;
        // get year of winning
        vector<int> years;
        // Iterate until adjacent country names are same
        while (j < n and tempArray[i].first == tempArray[j].first)
        {
            // increment count
            count++;
            // push winning years
            years.push_back(tempArray[j].second.second);
            j++;
        }
        // get total winning count and total winning years of ith country
        winners.push_back({tempArray[i].first, {count, years}});
        i = j;
    }

    // Display data

    cout << "\nFIFA World Cup Winners\n";
    cout << "Country" << setw(15) << " Wins " << setw(15) << "Years" << endl;
    cout << "=======" << setw(15) << " ==== " << setw(15) << "=====" << endl;
    for (int i = 0; i < winners.size(); i++)
    {
        string country = winners[i].first;
        int wins = winners[i].second.first;
        cout << country << setw(15) << wins << setw(15);
        for (int j = 0; j < winners[i].second.second.size(); j++)
        {
            if (j == winners[i].second.second.size() - 1)
            {
                cout << winners[i].second.second[j];
            }
            else
            {
                cout << winners[i].second.second[j] << ", ";
            }
        }
        cout << endl;
    }
}
