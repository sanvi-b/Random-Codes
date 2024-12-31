#include <iostream>
using namespace std;
class Complex
{
    private:float real;
            float imaginary;
    public:
    Complex(): real(0.0), imaginary (0.0) {}
    Complex (float r, float i): real (r), imaginary (i) {}
    friend ostream &operator<< (ostream &os, Complex &c);
    friend istream &operator>> (istream &is, Complex &c);
};
ostream &operator<< (ostream &os, Complex &c)
{
    os << c.real;
    if (c.imaginary >=0)
    os << " +" << c.imaginary << "i";
    else
    os << " " << c.imaginary << "i";
    return os;
}
istream &operator>> (istream &is, Complex &c)
{
    cout << "Enter the Real part:";
    is >> c.real;
    cout << "Enter the Imaginary part:";
    is >> c.imaginary;
    return is;
}
int main ()
{
    Complex C1;
    cin >> C1;
    cout << "Entered Complex number is: " << C1 << endl;
    return 0;
}