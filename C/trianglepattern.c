#include <stdio.h>
void main()
{
    int a,i,j;
    printf ("Enter the number of lines:");
    scanf ("%d",&a);
    for (i=1;i<=a;i++)
    {  
        for (j=1;j<=i;j++)
        printf ("*"); 
        printf ("\n");
    }
    printf ("\n");
    for (i=a;i>=1;i--)
    {  
        for (j=i;j>=1;j--)
        printf ("*"); 
        printf ("\n");
    }
}