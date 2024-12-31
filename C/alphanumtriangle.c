#include <stdio.h>
void main()
{
    int a,i,j,b;
    printf ("Enter the number of lines:");
    scanf ("%d",&a);
    for (i=1;i<=a;i++)
    {
        if (i%2!=0)
        {
        for (j=1;j<=i;j++)
        {
             printf ("%d ",j);
        } 
        printf ("\n");
        }
        else 
        {
        b=65;
        for (j=1;j<=i;j++)
        {
             printf ("%c ",b);
             b++;    
        }
        printf ("\n");
        }
    }
}