#include <stdio.h>
void main ()
{
    int n,i,m;
    printf("Enter the maximum limit:");
    scanf ("%d",&n);
    for (i=0;i<=n;i=i+2)
    printf ("%d ",i);
    printf("\nEnter the maximum limit:");
    scanf ("%d",&m);
    for (i=1;i<=m;i=i+2)
    printf ("%d ",i);
}