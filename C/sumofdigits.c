#include <stdio.h>
void main ()
{
    int n,r,s=0;
    printf ("Enter a number:");
    scanf ("%d",&n);
    while (n>0)
    {
        r=n%10;
        s=r+s;
        n=n/10;
    }
    printf ("The sum of digits are %d",s);
}