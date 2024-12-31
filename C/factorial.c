#include <stdio.h>
void main()
{
    int n,i,f=1;
    printf ("Enter a number:");
    scanf ("%d", &n);
    if (n==0) printf ("Factorial of 0 is 1.\n");
    else{
    for (i=1;i<=n;i++)
    {    
        f=f*i;
        printf ("The value of %d! is %d\n",i,f);
    }
    }
}