#include <iostream>
#include <map>
#include <math.h>
#include <string.h>
#include <sstream>
using namespace std;

// function which returns the result of expression
double getResult(double operand1, double operand2, string oper)
{
    // addition
    if (oper == "+")
        return operand1 + operand2;
    // substraction
    if (oper == "-")
        return operand1 - operand2;
    // multiplication
    if (oper == "*")
        return operand1 * operand2;
    // division
    if (oper == "/")
        return operand1 / operand2;
    // power
    double ans = pow(operand1, operand2);
    return ans;
}

int main()
{
    // Display the greeting
    cout << "Professor Loke's SuperRich-boy Calculator Solves "
         << "Arithmetic expressions using *,/,+,- or ^ "
         << "Enter an expression with the '#' operator to exit" << endl;
    cout << endl;
    // Display calculator ON
    cout << "Calculator ON" << endl;
    while (true)
    {
        cout << endl;
        // Input the expression
        string expr;
        getline(cin, expr);
        // If user entered 0#0 ,
        // end the program
        // Display calcultor OFF
        if (expr == "0#0")
        {
            cout << endl;
            cout << "Calculator OFF\n";
            return 0;
        }
        // else get the both operand and operator
        double operand1, operand2;
        string oper;
        stringstream ss(expr);
        string word;
        int i = 0;
        // Iterate string
        while (ss >> word)
        {
            // get first operand
            if (i == 0)
            {
                operand1 = stod(word);
                i++;
            }
            // get operator
            else if (i == 1)
            {
                oper = word;
                i++;
            }
            // get second operand
            else if (i == 2)
            {
                operand2 = stod(word);
                i++;
            }
        }
        // if expression length is 0
        // means user entered ctrl-d
        if (expr.length() == 0)
        {
            cout << "<ctrl-d> \n \nCalculator OFF" << endl;
            return 0;
        }
        // if operator is not +,-,/,* or ^
        // Display error
        if (oper != "+" and oper != "-" and oper != "*" and oper != "/" and oper != "^")
        {
            cout << "Error: Invalid operator " << oper << endl;
            continue;
        }
        // get the result of both operand using this operator
        double ans = getResult(operand1, operand2, oper);
        // Display result
        cout << expr << " = " << ans << endl;
    }
}