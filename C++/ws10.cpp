#include <iostream>
using namespace std;
int main()
{
    int n, d, arr[20];
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter the number for left shifts: ";
    cin >> d;
    d = d % n;
    cout << "The array before rotation is: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    int temp[d];
    for (int i = 0; i < d; i++)
        temp[i] = arr[i];
    for (int i = d; i < n; i++)
        arr[i - d] = arr[i];
    for (int i = 0; i < d; i++)
        arr[n - d + i] = temp[i];
    cout << "\nThe array after left rotation is: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}