#include <stdio.h>
void main()
{
    int a,i,j,k,n;
    printf ("Enter the number of lines:");
    scanf ("%d",&a);
    for (i=1;i<=a;i++)
    {
        n=65;
        for (j=1;j<=a-i;j++)
        {
             printf (" ");
        } 
        for (k=1;k<2*i;k++)
        {printf ("%c",n);
        n++;}
        printf ("\n");
    }
}