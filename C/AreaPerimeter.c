#include <stdio.h>
void main()
{
    int l,b,p,a;
    printf ("Enter the length and breadth of the rectangle:\n");
    scanf ("%d%d",&l,&b);
    a=l*b;
    p=2*(l+b);
    printf ("The area and perimeter of the rectangle are %d and %d\n",a,p);
    if (a>p)
    {
        printf ("Area is greater than perimeter.\n");
    }
    else printf ("Area is smaller than perimeter.\n");
}