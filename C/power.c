#include <stdio.h>
#include <math.h>
void main ()
{
    int a,b,c,i;
    printf ("Enter the numbers a and b:");
    scanf ("%d %d", &a, &b);
    c=pow(a,b);
    printf ("%d raised to power %d is %d\n",a,b,c);
    c=1;
    for (i=1;i<=b;i++)
    {
    c=c*a;
    printf ("\n%d raised to power %d is %d ",a,i,c);
    }
}