#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int num)
{
    if (num <= 1)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;
    for (int i = 3; i <= sqrt(num); i += 2)
        if (num % i == 0)
            return false;
    return true;
}
int main()
{
    int n, k = 0, arr[40];
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter elements of the array:";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "The array after replacing prime numbers with * and reomving all the even numbers is : ";
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
            continue;
        if (isPrime(arr[i]))
            cout << "* ";
        else
            cout << arr[i] << " ";
    }
    return 0;
}
