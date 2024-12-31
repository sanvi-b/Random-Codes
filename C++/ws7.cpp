#include <iostream>
using namespace std;
int main()
{
    int i, arr[10];
    cout << "Enter 10 elements of the array: ";
    for (i = 0; i < 10; i++)
        cin >> arr[i];
    cout << "The array without the elements from indices 4 to 8 is: ";
    for (i = 0; i < 10; i++)
    {
        if (i >= 0 && i < 4 || i > 8 && i < 10)
            cout << arr[i] << " ";
    }
    return 0;
}