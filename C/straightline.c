#include <stdio.h>
void main ()
{
    double x1,x2,x3,y1,y2,y3,m1,m2;
    printf ("Enter point A:");
    scanf ("%lf%lf",&x1, &y1);
    printf ("Enter point B:");
    scanf ("%lf%lf",&x2, &y2);
    printf ("Enter point C:");
    scanf ("%lf%lf",&x3, &y3);
    m1=(y2-y1)/(x2-x1);
    m2=(y3-y2)/(x3-x2);
    if (m1==m2) printf ("It is a straight line.");
    else printf ("It is not a straight line.");
}