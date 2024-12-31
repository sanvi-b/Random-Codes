#include <iostream>
#include <math.h>
using namespace std;
class PowerCalculator
{
    public:
    float power (int base, int exponent)
    {
        return pow(base,exponent);
    }
    float power (float base, float exponent)
    {
        return pow(base,exponent);
    }
};
int main ()
{
    PowerCalculator calculator;
    int intb, inte;
    float fbase, fexpo;
    cout << "Enter integer base:";
    cin >> intb;
    cout << "Enter integer exponent:";
    cin >> inte;
    cout << "Enter float base:";
    cin >> fbase;
    cout << "Enter float exponent:";
    cin >> fexpo;
    int resultInt = calculator.power(intb,inte);
    cout << "resulInt= " << resultInt << endl;
    float resultFloat = calculator.power(fbase,fexpo);
    cout << "resultFloat= " << resultFloat << endl;
    return 0;
}