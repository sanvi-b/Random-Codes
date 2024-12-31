#include <iostream>
using namespace std;
int main()
{
    int num;
    cout << "Enter number of lines: ";
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
            cout << "*";
        cout << "\n";
    }
    cout << "\n\n\n";
    for (int i = 0; i < num; i++)
    {
        for (int j = 1; j <= num; j++)
            if (j % 2 == 0)
                cout << "#";
            else
                cout << "*";
        cout << "\n";
    }
    cout << "\n\n\n";
    for (int i = num; i > 0; i--)
    {
        for (int j = 0; j <= num - i; j++)
            cout << "*";
        cout << "\n";
    }
    cout << "\n\n\n";
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num - i; j++)
            cout << " ";
        for (int k = 2; k <= 2 * i; k++)
            cout << "*";
        cout << "\n";
    }
    cout << "\n\n\n";
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << "*" << " ";
        cout << "\n";
    }
    for (int i = 1; i <= num - 1; i++)
    {
        for (int j = 1; j <= num - i; j++)
            cout << "*" << " ";
        cout << "\n";
    }
    return 0;
}