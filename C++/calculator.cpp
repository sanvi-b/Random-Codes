#include <iostream>
using namespace std;
int main ()
{
    int a,b,c,d=1;
    cout << "Enter a and b:";
    cin >> a >> b;
    while (d>0)
    {
        cout << "\nCalculator Menu:\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Remainder\nChoose:";
        cin >> c;
        switch (c)
        {
            case 0: d=0;
                    break;
            case 1: cout <<"Sum is "<<a+b;
                    break;
            case 2: cout << "Difference is "<<a-b;
                    break;
            case 3: cout <<"Product is "<< a*b;
                    break;
            case 4: if (b!=0)
                    cout <<"Quotient is "<<a/b;
                    else cout <<"Division not possible.\n";
                    break;
            case 5: if (b!=0)
                    cout <<"Remainder is "<<a%b;
                    else cout <<"Not possible.\n";
                    break;
            default : cout <<"Invalid choice.\n";
        }
    }
    return 0;
}