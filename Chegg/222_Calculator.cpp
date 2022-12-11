#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// Utility function which return the result of given operation
double getResult(double operand1, double operand2, char oper)
{
    // Return addition
    if (oper == '+')
    {
        return operand1 + operand2;
    }
    // Return substraction
    if (oper == '-')
    {
        return operand1 - operand2;
    }
    // Return division
    if (oper == '/')
    {
        return operand1 / operand2;
    }
    // Return multiplication
    if (oper == '*')
    {
        return operand1 * operand2;
    }
    // Return modolus
    return (double)((int)operand1 % (int)operand2);
}

int main()
{
    // Read file
    ifstream myFile("input.txt");
    // String to read line by line
    string line;
    // Create and open a text file
    ofstream resultFile("result.txt");
    // Write into reultFile
    resultFile << "N1"
               << "\t";
    resultFile << "Op"
               << "\t";
    resultFile << "N2"
               << "\t";
    resultFile << "="
               << "\t";
    resultFile << "Result"
               << "\n";
    // Display result
    cout << "N1\t"
         << "Op\t"
         << "N2\t"
         << "=\t"
         << "Result\n";
    // Read line by line from input.txt file
    while (getline(myFile, line))
    {
        // get operand1, operand2 and operator
        double operand1, operand2;
        char oper;

        stringstream ss(line);
        int cnt = 0;
        string ch;
        while (ss >> ch)
        {
            // Get operand1
            if (cnt == 0)
            {
                operand1 = stod(ch);
                cnt++;
            }
            // get operanad2
            else if (cnt == 1)
            {
                operand2 = stod(ch);
                cnt++;
            }
            // get operator
            else if (cnt == 2)
            {
                oper = ch[0];
                cnt++;
            }
        }
        // if invalid operator then display error
        if (oper != '+' and oper != '-' and oper != '*' and oper != '/' and oper != '%')
        {
            resultFile << " invalid operation " << oper << " detected (" << operand1 << ", " << operand2 << ", " << oper << ")\n";
            cout << " invalid operation " << oper << " detected (" << operand1 << ", " << operand2 << ", " << oper << ")" << endl;
            continue;
        }
        // else get desired result and write into file
        double ans = getResult(operand1, operand2, oper);
        resultFile << operand1 << "\t";
        resultFile << oper << "\t";
        resultFile << operand2 << "\t";
        resultFile << "= "
                   << "\t";
        resultFile << ans << "\n";

        // As well as display on console
        cout << operand1 << "\t" << oper << "\t" << operand2 << "\t"
             << "=\t" << ans << endl;
    }
    myFile.close();
    resultFile.close();
    return 0;
}