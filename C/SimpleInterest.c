#include <stdio.h>
void main()
{
    float P,SI;
    float T,R;
    printf ("Enter the Principle Amount, Time and Rate of Interest:");
    scanf ("%f %f %f", &P, &T, &R);
    SI=(P*R*T)/100;
    printf ("The Simple Interest is %f",SI);
}