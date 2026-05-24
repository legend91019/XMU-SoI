#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
    double w,d;
    cout << "Weight(g):";cin >> w;
    cout << "Distance(km):";cin >> d;

    double base = 0;
    double extra_per_1000km = 0;

    if (w < 15) base = 5;
    else if (w >= 15 && w < 30) base = 9;
    else if (w >= 30 && w < 45) base = 12;
    else if (w >= 45 && w < 60) 
    {
        base = 14;
        extra_per_1000km = 1;
    }
    else
    {
        base = 15;
        extra_per_1000km = 2;
    }

    double price = base + extra_per_1000km * (int)d;
    
    cout << "Price is: " << price << "dollar\n";

    return 0;
}