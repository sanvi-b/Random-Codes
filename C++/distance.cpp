#include <iostream>
using namespace std;
class Distance
{
    private:int feet;
            int inch;
    public:
    Distance() : feet(0), inch(0) {}
    Distance(int ft, int in) : feet(ft), inch(in) {}
    void data()
    {
        cout << "Enter the feet:";
        cin >> feet;
        cout << "Enter the inches:";
        cin >> inch;
        feet=feet+ inch/12;
        inch=inch%12;
    }
    void display ()
    {
        cout << "Feet: " << feet << " Inches: " << inch << endl;
    }
    Distance operator+ (Distance &d1)
    {
        Distance temp;
        temp.inch= inch + d1.inch;
        temp.feet= feet + d1.feet +temp.inch/12;
        temp.inch= temp.inch%12;
        return temp;
    }
    int operator==(Distance &d1)
    {
        return (feet==d1.feet && inch==d1.inch);
    }
    friend int operator< (Distance &d1, Distance &d2);
};
int operator< (Distance &d1, Distance &d2)
{
    if (d1.feet<d2.feet)
    return 1;
    if (d1.feet==d2.feet && d1.inch<d2.inch)
    return 1;
    else return 0;
}
int main ()
{
    Distance D1,D2,sum;
    D1.data();
    D1.display();
    D2.data();
    D2.display();
    sum= D1+D2;
    cout << "Sum of both the Distances= ";
    sum.display();
    if (D1==D2)
    cout << "Both the Distances are Equal.\n";
    else if (D1<D2)
    cout << "Disatnce 1 is less than Distance 2.";
    else 
    cout << "Distance 2 is less than Distance 1.";
    return 0;
}