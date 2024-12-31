#include <stdio.h>
void main ()
{
    int n,r,s1=0,s2=0;
    printf ("Enter a number:");
    scanf ("%d",&n);
    while (n>0)
    {
        r=n%10;
        if (r%2==0)
        {
        s1=r+s1;
        n=n/10;
        }
        else 
        {
        s2=r+s2;
        n=n/10;  
        }
    }
    printf ("The sum of odd digits are %d\n",s2);
    printf ("The sum of even digits are %d\n",s1);
}