#include <stdio.h>
void main()
{
    int x;
    float a,b,y;
    printf("Enter value of a:");
    scanf ("%f", &a);
    x=a;
    printf ("%d\n", x);
   y=a-x;
   printf ("%0.4f",y);
}