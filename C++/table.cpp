#include <iostream>
using namespace std;
int main ()
{
     int a,b,i;
     cout << "Enter a and b:";
     cin >> a >> b;
     cout << "Multiplication table of " << a <<", " <<b << " times is";
     for (i=1;i<=b;i++)
     {
        cout << " " << a*i ; 
     }
    return 0;
}