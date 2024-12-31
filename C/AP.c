#include <stdio.h>
void main ()
{
    int n,i,d,k,a;
    printf ("Enter the number of terms of the AP:");
    scanf ("%d",&n);
    printf ("Enter the common difference of the AP:");
    scanf ("%d",&d);
    printf ("Enter the first term of the AP:");
    scanf ("%d",&a);
    printf ("The AP is ");
    for (i=1;i<=n;i++)
    {
        k= a + ((i-1)*d);
        printf ("%d ",k);
    }
}