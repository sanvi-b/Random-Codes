#include <iostream>
using namespace std;
struct phone
{
    int acode;
    int excg;
    int no;
};
int main ()
{
    struct phone phone1;
    struct phone phone2;
    phone1 = {212,767,8900};
    cout << "Enter a Phone Number:\n";
    cout << "Enter the Area Code:";
    cin >> phone2.acode;
    cout << "Enter the Exchange:";
    cin >> phone2.excg;
    cout << "Enter the Number:";
    cin >> phone2.no;
    cout << "Phone 1: (" << phone1.acode << ") " << phone1.excg << "-" << phone1.no << endl;
    cout << "Phone 2: (" << phone2.acode << ") " << phone2.excg << "-" << phone2.no;
    return 0;
}