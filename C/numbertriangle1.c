#include <stdio.h>
void main()
{
    int a,i,j;
    printf ("Enter the number of lines:");
    scanf ("%d",&a);
    for (i=1;i<=a;i++)
    {
        for (j=1;j<=2*i;j=j+2)
        {
             printf ("%d ",j);
        } 
        printf ("\n");
    }
    printf ("\n");
    for (i=a;i>=1;i--)
    {
        for (j=1;j<=2*i;j=j+2)
        {
             printf ("%d ",j);
        } 
        printf ("\n");
    }
}