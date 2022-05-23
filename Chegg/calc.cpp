#include <bits/stdc++.h>
using namespace std;

void calc()
{
    cout<<"Enter a expression: "<<endl;
    long double num1, num2;

    long double lastResult;
    char operation;
    bool stop = false;
    vector<long double>res;
    std::cin >> num1 >> operation >> num2;
    do
    {
        switch (operation)
        {

        case '+':
        {
            num2 += num1;
            break;
        }

        case '-':
        {
            num2 -= num1;
            break;
        }

        case '/':
        {
            num2 /= num1;
            break;
        }

        case '*':
        {
            num2 *= num1;
            break;
        }

        

        default:
            std::cout << "Not a valid operation. Try again.";
            break;
        }

        res.push_back(num2);

        std::cout <<"\nResult: "<< num2 << std::endl;
        cout<<endl;


        // Skip till the end of the line.
        while (std::cin.get() != '\n');

        // Read the next operation.
        cout<<"+ = add"<<endl;
        cout<<"- = substract"<<endl;
        cout<<"* = multipliply"<<endl;
        cout<<"/ = divide"<<endl;
        cout<<"q = for stoping program"<<endl;
        cout<<"K = for clear screen and roll back result"<<endl;
        cout<<"C = for clear memory and code"<<endl;
        cout<<"S = for Square root of result"<<endl;
        cout<<"N = for changing the sign of result"<<endl;
        cout<<"Enter next operation: "<<endl;
        std::cin >> operation;
        if (operation == 'q')
        {
            stop = true;
        }
        else if(operation=='K')
        {
            if(res.size()<2)
            {
                cout<<"Please do at least two operations.."<<endl;
            }
            else
            {
                cout<<"Rolling back of result..."<<endl;
                num2=res[res.size()-2];

                cout<<"Rolledback to last result by eliminating the current operator..."<<endl;
                cout <<"\033[2J\033[1;1H";
                fflush(stdin);
                cout<<"Last Result: "<<num2<<endl;
            }
            // break;
        }

        
        else if(operation=='C')
        {
            fflush(stdin);
            cout << "\033[2J\033[1;1H";
            calc();
            // break;
        }

        else if(operation=='S' or operation=='s')
        {
            long double squareRoot=sqrt(num2);
            cout<<"Square Root of Result: "<<squareRoot<<endl;
            // break;
        }

        else if(operation=='N')
        {
            cout<<"Result before changing the sign: "<<num2<<endl;
            long double temp=num2;
            cout<<"Result after chaning sign: "<<-1*temp<<endl;
            // break;
        }
        else
        {
            cout<<"Enter a number: "<<endl;
            std::cin >> num1;
        }
        cout<<endl;

    } while (std::cin.good() && !std::cin.eof() && !stop);
}

int main()
{
    calc();
    return 0;
}