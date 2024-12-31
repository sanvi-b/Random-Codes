#include <stdio.h>
void main ()
{
    int n,i,s1=0,j,s2=0,s=0;
    printf ("1-2+3-4...n terms\n");
    printf ("Enter the value of n:");
    scanf ("%d",&n);
    for (i=1;i<=n;i=i+2)
    {s1=s1+i;}
    for (j=0;j<=n;j=j+2)
    {s2=s2+j;}
    s=s1-s2;
    printf ("The sum of the series is %d\n",s);
}