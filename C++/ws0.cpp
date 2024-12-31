#include <iostream>
using namespace std;
int main()
{
    int a, k = 0;
    for (int i = 1; i <= 10; i++)
        cout << i << endl;
    cout << "Enter a number:";
    cin >> a;
    if (a % 2 == 0)
        cout << "The number " << a << " is an even number." << endl;
    else
        cout << "The number " << a << " is an odd number." << endl;
    if (a <= 1)
        cout << "This is neither prime nor composite.";
    if (a == 2)
        cout << "2 is a prime number.";
    if (a > 2)
    {
        for (int i = 2; i < a; i++)
        {
            if (a % i == 0)
            {
                k = 1;
                break;
            }
        }
        if (k == 1)
            cout << "The number " << a << " is not a prime number.";
        else
            cout << "The number " << a << " is a prime number.";
    }
    return 0;
}