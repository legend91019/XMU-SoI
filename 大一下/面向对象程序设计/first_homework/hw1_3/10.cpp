#include <iostream>
using namespace std;
int main(void)
{
    int a,b;
    cout << "a:";cin >> a;
    cout << "b:";cin >> b;

    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }

    cout << a << endl;



    return 0;
}