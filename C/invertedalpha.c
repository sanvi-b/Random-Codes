#include <stdio.h>
void main()
{
    int a,i,j,k,n;
    printf ("Enter the number of lines:");
    scanf ("%d",&a);
    n=65;
    for (i=1;i<=a;i++)
    {
        for (j=1;j<=a-i;j++)
        {
             printf (" ");
        } 
        for (k=1;k<=i;k++)
        {printf ("%c",n);
        n++;}
        printf ("\n");
    }
    printf ("\n");
    for (i=1;i<=a;i++)
    {
        n=65;
        for (j=1;j<=a-i;j++)
        {
             printf (" ");
        } 
        for (k=1;k<=i;k++)
        {printf ("%c",n);
        n++;}
        printf ("\n");
    }
}