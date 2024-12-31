#include <stdio.h>
void main ()
{
    float n;
    printf ("Enter a number:");
    scanf ("%f",&n);
    if (n>=0)
    {
        printf ("The absolute value of the number is %0.0f",n);
    }
    else printf ("The absolute value of the number is %0.0f",(-1*n));
}