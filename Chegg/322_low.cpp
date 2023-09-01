#include <iostream>

int FindLowestNum()
{
    int num, min = INT_MAX;
    while (true)
    {
        std::cin >> num;
        if (num > 0)
        {
            break;
        }
        else if (num < min)
        {
            min = num;
        }
    }
    return min;
}

int main()
{
    int minVal = FindLowestNum();
    std::cout << minVal << std::endl;
    return 0;
}
