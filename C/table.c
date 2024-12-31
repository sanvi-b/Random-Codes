#include <stdio.h>
void main()
{
    int n,i,m,k;
    printf ("Enter the number for table: ");
    scanf ("%d",&n);
    printf ("Enter the limit of table: ");
    scanf ("%d",&m);
    for (i=1;i<=m;i++)
    {
        k=n*i;
        printf ("%d\n",k);
    }
}