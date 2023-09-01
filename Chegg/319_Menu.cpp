#include <iostream>
using namespace std;

// function prototypes
void showChoice();
float add(float num1, float num2);
float subtract(float num1, float num2);
float multiply(float num1, float num2);
float divide(float num1, float num2);
float average(float num1, float num2);

int main()
{
    int choice;
    float num1, num2, result;

    do
    {
        showChoice();
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            result = add(num1, num2);
            cout << "Sum is " << result << endl;
            break;
        case 2:
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            result = subtract(num1, num2);
            cout << "Difference is " << result << endl;
            break;
        case 3:
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            result = multiply(num1, num2);
            cout << "Product is " << result << endl;
            break;
        case 4:
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            if (num2 == 0)
            {
                cout << "Error: division by zero" << endl;
            }
            else
            {
                result = divide(num1, num2);
                cout << "Quotient is " << result << endl;
            }
            break;
        case 5:
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            result = average(num1, num2);
            cout << "Average is " << result << endl;
            break;
        case 6:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}

void showChoice()
{
    cout << "Select an operation:" << endl;
    cout << "1. Sum" << endl;
    cout << "2. Difference" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Average" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice (1-6): ";
}

float add(float num1, float num2)
{
    return num1 + num2;
}

float subtract(float num1, float num2)
{
    return num1 - num2;
}

float multiply(float num1, float num2)
{
    return num1 * num2;
}

float divide(float num1, float num2)
{
    return num1 / num2;
}

float average(float num1, float num2)
{
    return (num1 + num2) / 2;
}
