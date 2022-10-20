#include <iostream>
#include <iomanip>
#include <memory>
#include <ctime>
#include <algorithm>
using namespace std;

struct Stone
{
    char slot;
    int attempts;

    Stone(char slot, int attempts)
    {
        this->slot = slot;
        this->attempts = attempts;
    }
};

int main()
{
    srand(time(NULL));
    unique_ptr<Stone> slots[10];
    char letters[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int randNum = 0;
    int numAttempts = 0;
    int totalAttempts = 0;
    int counter = 0;

    for (int i = 0; i < 10; i++)
    {
        numAttempts = 1;

        do
        {
            randNum = rand() % 10;
            if (!slots[randNum])
            {
                // unique_ptr new_stone(new Stone(letters[i], numAttempts));
                auto new_stone = make_unique<Stone>(letters[i], numAttempts);
                slots[randNum] = move(new_stone);
                // slots[randNum] = unique_ptr<Stone>(new Stone(letters[i], numAttempts));
                break;
            }
            numAttempts++;
        } while (numAttempts < 10);

        totalAttempts += numAttempts;
    }

    cout << "Before: " << endl;
    cout << setw(5) << "Slot" << setw(10) << "Stone" << setw(12) << "Attempts" << endl;

    for (const auto &i : slots)
    {
        if (i == NULL)
        {
            cout << setw(5) << "NULL" << endl;
        }
        else
        {
            cout << setw(5) << counter << setw(10) << i->slot << setw(10) << i->attempts << endl;
        }
        counter++;
    }
    cout << setw(5) << "Total Attempts: " << totalAttempts;

    // Here we need to sort the slots ( for sorting we need algorithm library)
    // sort based on the slots
    // like according to the alphabetically order
    sort(slots, slots + 10);
    cout << endl;
    // set counter zero initially
    counter = 0;
    cout << "\nAfter: " << endl;
    // Display message
    cout << setw(5) << "Stone" << setw(10) << "Slot" << setw(12) << "Attempts" << endl;

    // Display slots and number of
    // attepmts of respective slots
    for (const auto &i : slots)
    {
        // if slot is null
        if (i == NULL)
        {
            cout << setw(5) << "NULL" << endl;
        }
        // else print slot , number and slots->attempts
        else
        {
            cout << setw(5) << i->slot << setw(10) << counter << setw(10) << i->attempts << endl;
        }
        counter++;
    }
    // Display total attempts
    cout << setw(5) << "Total Attempts: " << totalAttempts;
}