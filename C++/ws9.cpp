#include <iostream>
using namespace std;
int main()
{
    int i, j, k = 0, m, n, a1[20], a2[20];
    cout << "Enter the size of first array: ";
    cin >> n;
    cout << "Enter the elements of first array: ";
    for (i = 0; i < n; i++)
        cin >> a1[i];
    cout << "Enter the size of second array: ";
    cin >> m;
    cout << "Enter the elements of second array: ";
    for (j = 0; j < m; j++)
        cin >> a2[j];
    int a3[m + n];
    i = 0;
    j = 0;
    while (i < n && j < m)
    {
        if (a1[i] < a2[j])
            a3[k++] = a1[i++];
        else
            a3[k++] = a2[j++];
    }
    while (i < n)
        a3[k++] = a1[i++];
    while (j < m)
        a3[k++] = a2[j++];
    cout << "The merged array is: ";
    for (k = 0; k < m + n; k++)
        cout << a3[k] << " ";
    for (int i = 0; i < m + n - 1; i++)
    {
        for (int j = 0; j < m + n - i - 1; j++)
        {
            if (a3[j] > a3[j + 1])
            {
                int temp = a3[j];
                a3[j] = a3[j + 1];
                a3[j + 1] = temp;
            }
        }
    }
    cout << "\nSorted array is: ";
    for (int i = 0; i < m + n; i++)
        cout << a3[i] << " ";
    int temp[m + n];
    j = 0;
    for (int i = 0; i < m + n - 1; i++)
    {
        if (a3[i] != a3[i + 1])
            temp[j++] = a3[i];
    }
    temp[j++] = a3[m + n - 1];
    for (int i = 0; i < j; i++)
        a3[i] = temp[i];
    cout << "\nArray without duplicates: ";
    for (int i = 0; i < j; i++)
        cout << a3[i] << " ";
    cout << endl;
    return 0;
}