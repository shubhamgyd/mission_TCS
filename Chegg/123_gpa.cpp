#include <bits/stdc++.h>
using namespace std;

class section
{
private:
    int i;
    char sdata[10][8];

public:
    void store();
    void show();
    void calshow();
};

void section::store()
{
    for (int j = 0; j < 10; j++)
    {
        cout << "Input student ID: ";
        cin >> sdata[j][0];
        cout << "Input student name: ";
        cin >> sdata[j][1];
        for (int i = 2; i < 8; i++)
        {
            cout << "\nInput mark: ";
            cin >> sdata[j][i];
        }
    }
}

void section::show()
{
    for (int j = 0; j < 10; j++)
    {
        cout << "\nstudent ID: " << sdata[j][0] << endl;
        cout << "\nstudent name: " << sdata[j][1] << endl;
        for (int i = 2; i < 8; i++)
        {
            cout << "Subject " << i - 1 << " " << sdata[j][i] << endl;
        }
    }
}
// void section::calshow()
// {
//     for (int j = 0; j < 10; j++)
//     {
//         int gpa = 0;
//         for (int i = 2; i < 8; i++)
//         {
//             string str(sdata[j][i]);
//             // int marks = atoi();
//             // gpa = gpa + atoi(sdata[j][i]);
//             // stringstream str(sdata[j][i]);
//         }
//         gpa = gpa / 7;
//     }
// }

int main()
{
    section st;
    st.store();
    st.show();
}