#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
    double pi = 0.0;
    double term;
    int n = 1;
    int sign = 1;

    do
    {
        term = sign * 1.0 / n;
        pi += term;

        sign = -sign;
        n+= 2;
    } while (term >= 1e-8 || term <= -1e-8);

    pi = pi * 4;

    cout << fixed << setprecision(10);
    cout << "pi = " << pi << endl;


    return 0;
}