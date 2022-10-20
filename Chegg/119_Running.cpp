#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // Display message
    cout << "Enter the name of three runners and their finishing time." << endl;
    cout << "I will tell you will comes first,second and third." << endl;
    cout << endl;
    // Variables to store the name of runners
    string firstRunner, secondRunner, thirdRunner;
    // Variables to store the score of runners
    double firstRunnerScore, secondRunnerScore, thirdRunnerScore;

    // Runner 1 information:
    cout << "Name of Runner 1: ";
    getline(cin, firstRunner);
    cout << "Runner 1's fininshing time: ";
    cin >> firstRunnerScore;
    cin.ignore();
    cout << endl;

    // Runner 2 information:
    cout << "Name of Runner 2: ";
    getline(cin, secondRunner);
    cout << "Runner 2's fininshing time: ";
    cin >> secondRunnerScore;
    cin.ignore();
    cout << endl;

    // Runner 3 information:
    cout << "Name of Runner 3: ";
    getline(cin, thirdRunner);
    cout << "Runner 3's fininshing time: ";
    cin >> thirdRunnerScore;
    cin.ignore();
    cout << endl;

    // If any runner have negative score
    if (firstRunnerScore < 0 || secondRunnerScore < 0 || thirdRunnerScore < 0)
    {
        // If first runner have less than 0 score
        // Display error
        if (firstRunnerScore < 0)
        {
            cout << "Error: 1st Runner Score is less than 0." << endl;
            return 0;
        }
        // If second runner have less than 0 score
        // Display error
        if (secondRunnerScore < 0)
        {
            cout << "Error: 2nd Runner Score is less than 0." << endl;
            return 0;
        }
        // If thirdRunner have less than 0 score
        // Display error
        if (thirdRunnerScore < 0)
        {
            cout << "Error: 3rd Runner Score is less than 0." << endl;
            return 0;
        }
    }
    // Make a vector to store the scores and names
    vector<pair<double, string>> scores;
    // push runner 1's information into vector
    scores.push_back({firstRunnerScore, firstRunner});
    // push runner 2's information into vector
    scores.push_back({secondRunnerScore, secondRunner});
    // push runner 2's information into vector
    scores.push_back({thirdRunnerScore, thirdRunner});

    // sort the scores according to the smaller
    // player whose score smaller comes first
    sort(scores.begin(), scores.end());

    // get firstPlace runner
    string firstPlace = scores[0].second;
    // get secondPlace runner
    string secondPlace = scores[1].second;
    // get thirdPlace runner
    string thirdPlace = scores[2].second;
    // Display all winners
    cout << firstPlace << " come in 1st place." << endl;
    cout << secondPlace << " come in 2nd place." << endl;
    cout << thirdPlace << " come in 3rd place." << endl;
}