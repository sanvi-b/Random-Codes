#include <stdio.h>
void main ()
{
    int a,b,i,sum=0;
    printf ("Enter the LOW and HIGH values:");
    scanf ("%d%d", &a, &b);
    for (i=a;i<=b;i++)
    {
        printf ("The square of %d is ",i);
        printf ("%d\n",i*i);
        sum += i*i;
    }
    printf ("The sum of the squares is %d", sum);
}