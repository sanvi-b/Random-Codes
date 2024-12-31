#include <iostream>
#include <cmath>
using namespace std;
class Shape 
{
    protected: float side;
               double are, per;
    public:
    Shape(float s): side(s) {}
    void display() 
    {
        cout << "Area= " << are << "\nPerimeter= " << per << endl;
    }
    virtual void area() = 0;
    virtual void perimeter() = 0;
};
class Triangle : public Shape 
{
    protected:float l, b;
    public:
    Triangle(float s, float a, float c) : Shape(s) 
    {
        l = a;
        b = c;
    }
    void area() 
    {
        float sr = (side + l + b) / 2;
        are = sqrt(sr * (sr - side) * (sr - l) * (sr - b));
    }
    void perimeter() 
    {
        per = side + l + b;
    }
};
class Rectangle : public Shape
{
    protected:float l;
    public:
    Rectangle(float s, float a) : Shape(s) 
    {
        l = a;
    }
    void area()
    {
        are = side * l;
    }
    void perimeter() 
    {
        per = 2 * (side + l);
    }
};
class Square : public Shape 
{
    public:
    Square(float s) : Shape(s) {}
    void area() 
    {
        are = side * side;
    }
    void perimeter() 
    {
        per = 4 * side;
    }
};
class Circle : public Shape 
{
    public:
    Circle(float s) : Shape(s) {}
    void area() 
    {
        are = M_PI * side * side;
    }
    void perimeter() 
    {
        per = 2 * M_PI * side;
    }
};
int main() 
{
    int ch, f=1;
    float a, b, c;
    while (f>0)
    {
        cout << "Calculate Area and Perimeter of:\n0.Exit\n1.Triangle\n2.Rectangle\n3.Square\n4.Circle\nChoose shape:";
        cin >> ch;
        Shape *ptr;
        switch (ch)
        {
            case 0: f=0;
                    break;
            case 1: cout << "Enter the 3 sides of Triangle: ";
                    cin >> a >> b >> c;
                    ptr= new Triangle(a, b, c);
                    ptr->area();
                    ptr->perimeter();
                    ptr->display();
                    delete ptr;
                    break;
            case 2: cout << "Enter the 2 sides of Rectangle: ";
                    cin >> a >> b;
                    ptr= new Rectangle(a, b);
                    ptr->area();
                    ptr->perimeter();
                    ptr->display();
                    delete ptr;
                    break;        
            case 3: cout << "Enter the side of Square: ";
                    cin >> a;
                    ptr= new Square(a);
                    ptr->area();
                    ptr->perimeter();
                    ptr->display();
                    delete ptr;
                    break;
            case 4: cout << "Enter the radius of Circle: ";
                    cin >> a;
                    ptr= new Circle(a);
                    ptr->area();
                    ptr->perimeter();
                    ptr->display();
                    delete ptr;
                    break;
            default: cout << "Invalid choice, choose again!\n";
        }
    }
    return 0;
}