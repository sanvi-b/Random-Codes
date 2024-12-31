#include <iostream>
#include <cmath>
using namespace std;
class Rectangular 
{
    public: float x;
            float y;
    Rectangular() : x(0.0), y(0.0) {}
    Rectangular(float i, float j) : x(i), y(j) {}
    void data ()
    {
        cout << "\nRectangular Coordinates-\nEnter x: ";
        cin >> x;
        cout << "Enter y: ";
        cin >> y;
    }
    void display()
    {
        cout << "The Rectangular Coordinates (x, y) are (" << x << ", " << y << ")." ;
    }
};
class Polar
{
    private:float angle;
            float radius;
            float radian;
    public:
    Polar() : angle(0.0), radius(0.0) {}
    Polar(float ag, float rd) : angle(ag), radius(rd) {}
    Polar (Rectangular &r1)
    {
        radius= sqrt(pow(r1.x,2) + pow(r1.y,2));
        radian= atan (r1.y/r1.x);
        angle= (radian*180)/M_PI;
    }
    void display ()
    {
        cout << "The Polar Coordinates (r, Θ) are (" << radius << ", " << angle << ").";
    }
    void data ()
    {
        cout << "Polar Coordinates-\nEnter the Angle: ";
        cin >> angle;
        cout << "Enter the Radius: ";
        cin >> radius;
        radian= (angle*M_PI)/180;
    }
    operator Rectangular ()
    {
        Rectangular temp;
        temp.x= radius* cos(radian);
        temp.y= radius* sin(radian);
        return temp;
    }
};
int main ()
{
    Polar P1,P2;
    Rectangular R1,R2;
    P1.data();
    R1=P1;
    R1.display ();
    R2.data();
    P2=R2;
    P2.display();
    return 0;
}