#include <stdio.h>
void main()
{
    int a,c;
    printf ("Enter a number:");
    scanf ("%d", &a);
    printf ("Choose:\n1.\n2.\n");
    scanf ("%d",&c);
    switch (c)
    {
        case 1: if (a%2==0)
                printf ("The number is Even and the square of the number is %d", a*a);
        case 2: if (a%2!=0)
                printf ("The number is Odd and the cube of the number is %d", a*a*a);
    } 
}