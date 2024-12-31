#include <iostream>
using namespace std;
int main()
{
    string hey;
    cout << "Enter a String:";
    cin >> hey;
    int n = hey.length();
    int j = n - 1;
    int p = 0, k = 0;
    for (int i = 0; i <= n / 2; i++)
    {
        if (hey[i] != hey[j])
        {
            k = 1;
            break;
        }
        j--;
    }
    if (k == 1)
        cout << hey << " is not a pallindrome." << endl;
    else
        cout << hey << " is a pallindrome." << endl;
    for (int i = 0; i <= n; i++)
    {
        if (hey[i] == 'a' || hey[i] == 'e' || hey[i] == 'i' || hey[i] == 'o' || hey[i] == 'u' ||
            hey[i] == 'A' || hey[i] == 'E' || hey[i] == 'I' || hey[i] == 'O' || hey[i] == 'U')
            p++;
    }
    cout << "The string has " << p << " vowels.";
    return 0;
}