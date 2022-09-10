#include <iostream>

#include <fstream>

using namespace std;

enum PenPosition
{

    UP,

    DOWN

};

struct Turtle
{

    int row, col;

    PenPosition tail;

    Turtle()
    {

        row = col = 0;

        tail = PenPosition::UP;
    }
};

const int ARR_SIZE = 10;

void loadGraphics(bool[ARR_SIZE][ARR_SIZE], fstream &);

void displayGraphics(const bool[ARR_SIZE][ARR_SIZE]);

int main()
{

    bool paper[ARR_SIZE][ARR_SIZE];

    // initialize to false

    for (int i = 0; i < ARR_SIZE; ++i)
    {

        for (int j = 0; j < ARR_SIZE; ++j)
        {

            paper[i][j] = false;
        }
    }

    fstream file("drawing.turtle", ios::in);

    loadGraphics(paper, file);

    file.close();

    displayGraphics(paper);

    return 0;
}

void loadGraphics(bool paper[ARR_SIZE][ARR_SIZE], fstream &file)
{

    Turtle turtle;

    int command, steps;

    while (file >> command)
    {

        switch (command)
        {

        case 1:
        {

            turtle.tail = PenPosition::UP;

            break;
        }

        case 2:
        {

            turtle.tail = PenPosition::DOWN;

            break;
        }

        case 3:
        {

            file >> steps;

            for (int i = 0; i < steps; ++i)
            {

                paper[turtle.row--][turtle.col] = turtle.tail == PenPosition::DOWN;
            }

            break;
        }

        case 4:
        {

            file >> steps;

            for (int i = 0; i < steps; ++i)
            {

                paper[turtle.row++][turtle.col] = turtle.tail == PenPosition::DOWN;
            }

            break;
        }

        case 5:
        {

            file >> steps;

            for (int i = 0; i < steps; ++i)
            {

                paper[turtle.row][turtle.col--] = turtle.tail == PenPosition::DOWN;
            }

            break;
        }

        case 6:
        {

            file >> steps;

            for (int i = 0; i < steps; ++i)
            {

                paper[turtle.row][turtle.col++] = turtle.tail == PenPosition::DOWN;
            }

            break;
        }
        }
    }
}

void displayGraphics(const bool paper[ARR_SIZE][ARR_SIZE])
{

    for (int i = 0; i < ARR_SIZE; ++i)
    {

        for (int j = 0; j < ARR_SIZE; ++j)
        {

            cout << (paper[i][j] ? ' ' : '+');
        }

        cout << endl;
    }

    cout << endl;
}