#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x = 280;
    char* ptr_p = (char *)&x;
    printf("%d\n", *ptr_p);
    return 0;
}