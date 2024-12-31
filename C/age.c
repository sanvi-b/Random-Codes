#include <stdio.h>
void main()
{
    int a,b,c;
    printf ("Enter the age of Ram,Shyam and Ajay:");
    scanf ("%d%d%d", &a,&b,&c);
    if (a<b && a<c)
    {
        printf ("Ram is the youngest.");
    }
    else if (b<c && b<a)
    {
        printf ("Shyam is the youngest.");
    }
    else printf ("Ajay is the youngest.");
}