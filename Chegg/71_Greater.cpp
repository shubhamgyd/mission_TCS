#include <iostream>
#include <bitset>
#include <string>
using namespace std;

template <class T>
T maxOne(T n1, T n2)
{
    return (n1 > n2) ? n1 : n2;
}

struct MyInt
{

    int i{};

    MyInt() = default;

    MyInt(int ii) : i{ii} {}

    friend std::ostream &operator<<(std::ostream &ooo, const MyInt &mi)
    {
        ooo << mi.i;
        return ooo;
    }
    

    // TODO: add a proper operator here so the class will work with template function maxOne
};

// do not change main function unless you find any errors

int main()
{
    // output: 20
    std::cout << maxOne(-10, 20) << std::endl;

    // output: BCC
    std::cout << maxOne("ABC", "BCC") << std::endl;

    // output: 20
    std::cout << maxOne(MyInt{-10}, MyInt{20}) << std::endl;

    return 0;
}