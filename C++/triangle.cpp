#include <iostream>
#include <math.h>
using namespace std;
class Triangle 
{
    private:
    float side1,side2,side3;
    public:
    Triangle (float s1, float s2, float s3): side1(s1), side2(s2), side3(s3) {}
    int valid()
    {
        if (side1+side2>side3 && side1+side3>side2 && side2+side3>side1)
        return 1;
        else 
        cout << "Triangle is not valid.";
    }
    int sides()
    {
        cout << "Sides of Triangle: " << side1 << ", " << side2 << ", " << side3 << endl;
    }
    void area()
    {
        if (valid()==1)
        {
            float s= (side1+side2+side3)/2;
            float a= sqrt (s*(s-side1)*(s-side2)*(s-side3));
            cout << "Area of Triangle:" << a;
        }
    }
};
int main ()
{
    float side1,side2,side3;
    cout << "Enter the Sides of the Triangle:";
    cin >> side1 >> side2 >> side3;
    Triangle triangle (side1,side2,side3);
    triangle.sides ();
    triangle.area ();
    return 0;
}