#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    // count of correct answers
    int correctAnswers = 0;
    // Iterate 10 times
    // to ask guess
    for (int i = 0; i < 10; i++)
    {
        cout << endl;
        // Two random numbers
        int a, b;
        // range of random numbers
        int min = -100;
        int max = 100;
        int range = max - min + 1;
        // get random a
        a = min + rand() % range;
        // get random b
        b = min + rand() % range;
        // Dsisplay a and b
        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
        // store addition of a and b in result
        int result = a + b;
        cout << "Guess the addition of " << a << " and " << b << endl;
        int guess;
        // ask user to guess the result
        cin >> guess;
        // if guess is correct
        if (guess == result)
        {
            // increment the counter
            cout << "Correct Answer!!" << endl;
            correctAnswers++;
        }
        // else invalid guess
        else
        {
            cout << "Invalid guess!!" << endl;
            cout << "Correst answer: " << result << endl;
        }
    }
    // display correct answers count
    cout << "Correct Answers Count: " << correctAnswers << endl;
    return 0;
}