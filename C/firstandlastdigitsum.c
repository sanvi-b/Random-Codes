#include <stdio.h>
void main ()
{
    int n,ld,fd,s=0;
    printf ("Enter the integer:");
    scanf ("%d", &n);
    ld=n%10;
    while (n>=10)
    n=n/10;
    fd=n;
    s=fd+ld;
    printf ("The sum of first and last digit of number is %d",s);
}