#include <stdio.h>
#include <math.h>
void main ()
{
    int n,r,k,a,j;
    printf ("Enter the number of terms of the GP:");
    scanf ("%d",&n);
    printf ("Enter the common ratio of the GP:");
    scanf ("%d",&r);
    printf ("Enter the first term of the GP:");
    scanf ("%d",&a);
    printf ("The GP is ");
    for (j=0;j<n;j++)
    {
        k= a*(pow(r,j));
        printf ("%d ",k);
    }    
}