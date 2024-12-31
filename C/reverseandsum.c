#include <stdio.h>
void main ()
{
    int n,r,rev=0,s,m;
    printf ("Enter a number:");
    scanf ("%d",&n);
    m=n;
    while (n>0)
    {
        r=n%10;
        rev=rev*10 + r;
        n=n/10;
    }
    printf ("The reverse of the number is %d\n",rev);
    s=m+rev;
    printf ("The sum of the number and it's reverse is %d",s);
}