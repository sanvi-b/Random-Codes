#include <stdio.h>
#include <math.h>
void main()
{
    int n,i,m,j,k,count=0;
    double s=0.0;
    printf ("Enter the number:");
    scanf ("%d", &n);
    printf ("The Armstrong numbers between 1 and %d are: ",n);
    for (i=1;i<=n;i++)
    {
        m=i;
        while (m!=0)
        {m=m/10;
        count++;}
        m=i;
        while (m!=0)
        {
        k=m%10;
        j=pow(k,count);
        s=s+j;
        m=m/10;
        }
        if ((int)i==s) {printf ("%d ",i);}
        count=0;
        s=0;
    }
}