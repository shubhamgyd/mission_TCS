#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
    cout << "Let's convert from imperial to metric!" << endl;
    cout << "Please only enter positive numbers.(Whole or decimal)\n";
    cout << endl;

    string feet;
    cout << "Feet: ";
    cin >> feet;
    double totalFeet = 0.0;
    try
    {
        int negative = 0;
        for (auto it : feet)
        {
            if (it == '.')
            {
                continue;
            }
            else if (it == '-')
            {
                negative++;
                continue;
            }
            else if (!isdigit(it))
            {

                throw feet;
            }
        }
        double d = stod(feet);
        if (negative == 1)
        {
            throw d;
        }
        totalFeet = d;
    }
    catch (double num)
    {
        cout << "A negative number has been enteres. Program terminated.\n";
        return 0;
    }
    catch (string str)
    {
        cout << "Invalid(non-numeric) data entered. Program terminated.\n";
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    string inch;
    cout << "Inches: ";
    cin >> inch;
    double totalInch = 0.0;
    try
    {
        int negative = 0;
        for (auto it : inch)
        {
            if (it == '.')
            {
                continue;
            }
            else if (it == '-')
            {
                negative++;
                continue;
            }
            else if (!isdigit(it))
            {

                throw inch;
            }
        }
        double in = stod(feet);
        if (negative == 1)
        {
            throw in;
        }
        totalInch = in;
    }
    catch (double num)
    {
        cout << "A negative number has been enteres. Program terminated.\n";
        return 0;
    }
    catch (string str)
    {
        cout << "Invalid(non-numeric) data entered. Program terminated.\n";
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    double centimeters = 30.48 * totalFeet + totalInch * 2.54;
    cout << "Centimeter(s): " << centimeters << "cm" << endl;
    return 0;
}