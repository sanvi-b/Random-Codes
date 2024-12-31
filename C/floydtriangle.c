#include <stdio.h>
void main()
{
    int a,i,j,n;
    printf ("Enter the number of lines:");
    scanf ("%d",&a);
    n=1;
    for (i=1;i<=a;i++)
    {
         for (j=1;j<=i;j++)
        {
             printf ("%d ",n); 
             n++;   
        }
        printf ("\n");
    }
}