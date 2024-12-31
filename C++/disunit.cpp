#include <iostream>
using namespace std;
class Distance
{
    private:float feet;
            double inch;
    public:
    Distance() : feet(0), inch(0) {}
    Distance(float ft, double in) : feet(ft), inch(in) {}
    Distance (float d)
    {
        feet = d*3.28084;
        inch = 12*(feet - (int)feet);
    }
    operator float ()
    {
        return (feet*0.3048 + inch*0.0254);
    }
    void data()
    {
        cout << "Enter the feet:";
        cin >> feet;
        cout << "Enter the inches:";
        cin >> inch;
    }
    void display ()
    {
        cout << "Feet: " << (int)feet << " Inches: " << inch << endl;
    }
};
int main ()
{
    Distance D1,D2;
    cout << "Feet and Inches to Meter-\n";
    D2.data();
    float dist;
    dist=(float)D2;
    cout << "Meters: " << dist;
    cout << "\nMeter to Feet and Inches-\nEnter the distance in meters: ";
    cin >> dist;
    D1=dist;
    D1.display();
    return 0;
}