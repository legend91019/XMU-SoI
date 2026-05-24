#include <iostream>
using namespace std;

int func1(int x , int n)
{
    if (n == 0) return 1;
    else if (n == 1) return 2*x;
    else
    {
        return 2*x*func1(x,n-1) - 2*(n-1)*func1(x,n-2);
    }
}

int func2(int x , int n)
{
    if (n == 0) return 1;
    else if (n == 1) return 2*x;

    double h0 = 1.0;
    double h1 = 2*x;
    double hn = 0;

    for (int i = 2;i < n;i++)
    {
        hn = 2*x*h1-2*(i-1)*h0;
        h0 = h1;
        h1 = hn;
    }

    return hn;
}