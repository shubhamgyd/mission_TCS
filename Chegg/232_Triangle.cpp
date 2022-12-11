#include <iostream>
#include <cstring>
using namespace std;

// Get the square root of a given number
float getSqrt(float number)
{
    float decimal = 0.1;
    float num = number;
    while ((num - number / num) > decimal)
    {
        num = (num + number / num) / 2.0;
    }
    return num;
}

int main()
{
    // Entered number of input size
    cout << "Enter a number between 1 and 10: \n";
    int n;
    cin >> n;
    string arr[n];
    // iterate n times
    for (int i = 0; i < n; i++)
    {
        // Read sides of a triangle
        cout << "Enter sides of triangle " << i + 1 << ": \n";
        float a, b, c;
        cin >> a >> b >> c;
        // get semiperimeter according to the Heron's formula
        float s = (a + b + c) / (2.0);
        float totalAns = s * (s - a) * (s - b) * (s - c);
        // get area of triangle
        float area = getSqrt(totalAns);
        // convert into string
        string ans = to_string(area);
        // round to 2 decimal places
        string finalAns = "";
        for (int j = 0; j < ans.length(); j++)
        {
            if (ans[j] == '.')
            {
                finalAns.push_back(ans[j]);
                finalAns.push_back(ans[j + 1]);
                finalAns.push_back(ans[j + 2]);
                break;
            }
            else
            {
                finalAns.push_back(ans[j]);
            }
        }
        // push trianle number
        finalAns += to_string(i + 1);
        // push into array
        arr[i] = finalAns;
    }

    // Sort area of array in ascending order
    // using insertion sort
    for (int i = 1; i < n; i++)
    {
        string value = arr[i];
        int key = i;
        while (key > 0 && arr[key - 1] > value)
        {
            arr[key] = arr[key - 1];
            key = key - 1;
        }
        arr[key] = value;
    }

    // Print areay of triangles in ascending order
    for (int i = 0; i < n; i++)
    {
        string ans = arr[i];
        string area = "";
        string triangle = "";
        bool isDecimalFound = false;
        // get area till 2 decimal places
        for (int j = 0; j < ans.length(); j++)
        {
            if (ans[j] == '.')
            {
                area.push_back(ans[j]);
                area.push_back(ans[j + 1]);
                area.push_back(ans[j + 2]);
                j += 2;
                isDecimalFound = true;
            }
            // get triangle nummber
            else if (isDecimalFound)
            {
                triangle.push_back(ans[j]);
            }
            else
            {
                area.push_back(ans[j]);
            }
        }
        // Display triangle number and it's area
        cout << "Area of triangle " << triangle << ": " << area << endl;
    }
}