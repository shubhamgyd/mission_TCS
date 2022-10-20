#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
    // make objects to read student answers file and correct answers file
    ifstream student_Ans_File;
    ifstream correct_Ans_File;
    student_Ans_File.open("studentAns.txt");
    // if fail to open file
    if (student_Ans_File.fail())
    {
        cout << "Error: Failed to open studentAns file!!" << endl;
        return 0;
    }
    // to store the answers of student
    vector<string> studentAnswer;
    string answer;
    while (getline(student_Ans_File, answer))
    {
        studentAnswer.push_back(answer);
    }
    // close student answer file
    student_Ans_File.close();

    // now open correct answers file
    correct_Ans_File.open("correctAns.txt");
    if (correct_Ans_File.fail())
    {
        cout << "Error: Failed to open correctAns file!!" << endl;
        return 0;
    }
    // to store the correct answers
    vector<string> correctAnswer;
    while (getline(correct_Ans_File, answer))
    {
        correctAnswer.push_back(answer);
    }
    // now close the correctAnswer file
    correct_Ans_File.close();

    // Now count how many correct attempted
    // Iterate for 101 times
    // from 0 to 100->101

    int correctAttempt = 0;
    for (int i = 0; i <= 100; i++)
    {
        if (studentAnswer[i] == correctAnswer[i])
        {
            correctAttempt++;
        }
    }
    // Not calculate grade
    double percentage = (correctAttempt * (100 * 1.0)) / (101 * 1.0);
    // Display Percentage
    cout << "Percentage: " << fixed << setprecision(2) << percentage << "%" << endl;
    return 0;
}
