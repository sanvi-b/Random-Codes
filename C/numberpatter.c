#include <stdio.h>
void main()
{
    int a,b,i,j;
    printf ("Enter the number of lines:");
    scanf ("%d",&a);
    printf ("Enter the end number in each line:");
    scanf ("%d", &b);
    for (i=1;i<=a;i++)
    {
        for (j=1;j<=b;j++)
        {
             printf ("%d ",j);
        } 
        printf ("\n");
    }
}