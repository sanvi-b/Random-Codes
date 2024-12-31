#include <stdio.h>
void main ()
{
    int a,b,c,d;
    printf ("Enter four numbers:");
    scanf ("%d%d%d%d", &a,&b,&c,&d);
    if (a>b && a>c && a>d)
    {
        printf ("%d is the greatest.",a);
    }
    else if (b>c && b>a && b>d)
    {
       printf ("%d is the greatest.",b); 
    }
    else if (c>d && c>d && c>d)
    {
       printf ("%d is the greatest.",c); 
    }
    else 
    {
       printf ("%d is the greatest.",d);  
    }
}