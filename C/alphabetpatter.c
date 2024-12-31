#include <stdio.h>
void main()
{
    int a,i,j,b;
    printf ("Enter the number of lines:");
    scanf ("%d",&a);
    for (i=1;i<=a;i++)
    {
        b=65;
        for (j=1;j<=a;j++)
        {
             printf ("%c ",b);
             b++;
        } 
        printf ("\n");
    }
}