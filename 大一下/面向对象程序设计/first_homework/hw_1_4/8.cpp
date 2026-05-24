#include <iostream>
using namespace std;

int digit(int a,int b)
{
    for (int i = 0;i < b-1;i++)
    {
        a /= 10;
    }

    return a % 10;
}