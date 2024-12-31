#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    for (int i = 1; i <= 10; i++)
    {
        if (i == 6 || i == 8)
            i++;
        cout << i << endl;
    }
    int p, c, x, d, sum = 0, k = 0;
    cout << "Enter a number:";
    cin >> p;
    d = p;
    while (p != 0)
    {
        p = p / 10;
        k++;
    }
    p = d;
    while (p != 0)
    {
        x = p % 10;
        c = pow(x, k);
        p = p / 10;
        sum = sum + c;
    }
    if (sum == d)
        cout << d << " is an Armstrong number.";
    else
        cout << d << " is not an Armstrong number.";
    return 0;
}