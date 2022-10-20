#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    // according to the condition
    // size of marks of the array is 20
    const int SIZE = 20;
    int arrMarks[SIZE];
    // keep track of the count of symbols
    int countA = 0;
    int countB = 0;
    int countC = 0;
    int countD = 0;
    int countE = 0;
    int countF = 0;

    srand(time(0));
    // Iterate 20 times
    for (int i = 0; i < 20; i++)
    {
        // get a random number at the kth index from 0 to 100
        arrMarks[i] = rand() % 101;

        // if marks are greater than or equal to 85
        // then increment the counter of symbol A
        if (arrMarks[i] >= 85)
        {
            countA++;
        }
        // if marks are greater than or equal to 70
        // then increment the counter of symbol B
        else if (arrMarks[i] >= 70)
        {
            countB++;
        }
        // if marks are greater than or equal to 70
        // then increment the counter of symbol C
        else if (arrMarks[i] >= 60)
        {
            countC++;
        }
        // if marks are greater than or equal to 50
        // then increment the counter of symbol D
        else if (arrMarks[i] >= 50)
        {
            countD++;
        }
        // if marks are greater than or equal to 35
        // then increment the counter of symbol E
        else if (arrMarks[i] >= 35)
        {
            countE++;
        }
        // else increment the counter of symbol F
        else
        {
            countF++;
        }
    }
    // Display all marks
    cout << "Marks " << endl;
    for (int i = 0; i < 20; i++)
    {
        cout << arrMarks[i] << " ";
    }

    cout << endl;
    // Display all symbols and their counter in an array
    cout << "\nNumber of symbols" << endl;
    cout << "A symbols: " << countA << endl;
    cout << "B symbols: " << countB << endl;
    cout << "C symbols: " << countC << endl;
    cout << "D symbols: " << countD << endl;
    cout << "E symbols: " << countE << endl;
    cout << "F symbols: " << countF << endl;
    return 0;
}