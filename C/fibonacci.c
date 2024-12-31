#include <stdio.h>
void main ()
{
    int n,i,a=0,b=1,sum=0;
    printf ("Enter the value of n:");
    scanf ("%d",&n);
    if (n==1) printf ("The Fibonacci Series is 0");
    if (n==2) printf ("The Fibonacci Series is 0 1");
    if (n>2)
    {   
        printf ("The Fibonacci Series is 0 1 ");
        for (i=1;i<=n-2;i++)
        {
        sum = a+b;
        a=b;
        b=sum;
        printf ("%d ",sum);
        }
    }
}