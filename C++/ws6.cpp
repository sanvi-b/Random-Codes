#include <iostream>
using namespace std;
int main()
{
    int n, small, large, arr[30];
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter elements of the array:";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    small = arr[0];
    large = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < small)
            small = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > large)
            large = arr[i];
    }
    cout << "The smallest element is: " << small << endl;
    cout << "The largest element is: " << large << endl;
    cout << "\nThe numbers divisible by both 3 and 5 are: ";
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 3 == 0)
        {
            if (arr[i] % 5 == 0)
                cout << arr[i] << " ";
        }
    }
    cout << "\nThe reversed array is: ";
    for (int i = n - 1; i >= 0; i--)
        cout << arr[i] << " ";
    return 0;
}