#include <iostream>
#include <math.h>
using namespace std;
class Triangle 
{
    public: int x;
            int y;
    inline float dis(int x1, int x2, int y1, int y2)
    {
        return (sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
    }
    inline int valid(float side1, float side2, float side3)
    {
        if (side1+side2>side3 && side1+side3>side2 && side2+side3>side1)
        cout << "The given sides do form a valid Triangle.\n";
        else cout << "Invalid, the given sides do not form a Triangle.\n";
    }
};
int main ()
{
   Triangle A,B,C,D;
   float sideAB, sideBC, sideAC, small;
   cout << "Enter the coordinates of point A:";
   cin >> A.x >> A.y;
   cout << "Enter the coordinates of point B:";
   cin >> B.x >> B.y;
   cout << "Enter the coordinates of point C:";
   cin >> C.x >> C.y;
   sideAB = A.dis(A.x, A.y, B.x, B.y);
   cout << "The distance betweenn coordinates A and B is " << sideAB << endl;
   sideBC = B.dis(C.x, C.y, B.x, B.y);
   cout << "The distance betweenn coordinates B and C is " << sideBC << endl;
   sideAC = C.dis(A.x, A.y, C.x, C.y);
   cout << "The distance betweenn coordinates A and C is " << sideAC << endl;
   small=sideAB;
   if (sideBC < small)
   small=sideBC;
   if (sideAC < small)
   small=sideAC;
   cout << "The shortest distance is: " << small << endl;
   D.valid(sideAB, sideBC, sideAC);
}