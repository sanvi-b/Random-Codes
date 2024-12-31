#include <iostream>
using namespace std;
class Swap
{
    public:
    void byValue(int a, int b)
    {
        int temp=a;
        a=b;
        b=temp;
    }
    void byReference(int &a, int &b)
    {
        int temp=a;
        a=b;
        b=temp;
    }
    void byAddress(int *a, int *b)
    {
        int temp=*a;
        *a=*b;
        *b=temp;
    }
};
int main ()
{
    Swap Swapobj;
    int value1, value2;
    cout << "Enter the first value: ";
    cin >> value1;
    cout << "Enter the second value: ";
    cin >> value2;
    cout << "\nValues before Swapping: value1= " << value1 << " and value2= " << value2 << endl;
    Swapobj.byValue(value1,value2);
    cout << "Values after Swapping by Value: value1= " << value1 << " and value2= " << value2 << endl;
    cout << "\nValues before Swapping: value1= " << value1 << " and value2= " << value2 << endl;
    Swapobj.byReference(value1,value2);
    cout << "Values after Swapping by Reference: value1= " << value1 << " and value2= " << value2 << endl;
    cout << "\nValues before Swapping: value1= " << value1 << " and value2= " << value2 << endl;
    Swapobj.byAddress(&value1,&value2);
    cout << "Values after Swapping by Address: value1= " << value1 << " and value2= " << value2 << endl;
    return 0;
}