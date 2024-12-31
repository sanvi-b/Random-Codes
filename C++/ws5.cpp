#include <iostream>
using namespace std;
int main()
{
    int num;
    cout << "Enter the number of lines: ";
    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << j;
        cout << "\n";
    }
    cout << "\n\n\n";
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << i;
        cout << "\n";
    }
    return 0;
}