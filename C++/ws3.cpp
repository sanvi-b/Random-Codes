#include <iostream>
using namespace std;
int main ()
{
    string val, result;
    int s;
    cout << "Enter a text to encrypt: ";
    cin >> val;
    cout << "Enter a shift value: ";
    cin >> s;
    for (int i=0; i< val.length(); i++)
    {
        if (isupper(val[i]))
            result += char(int(val[i] + s - 65) % 26 + 65);
        else
            result += char(int(val[i] + s - 97) % 26 + 97);
    }
    cout << "The encrypted text is: " << result;
    return 0;
}