#include <stdio.h>
void main()
{
    int a,i,j,n;
    printf ("Enter the number of lines:");
    scanf ("%d",&a);
    for (i=1;i<=a;i++)
    {
        if (i%2!=0)
        n=1; else n=0;
        for (j=1;j<=i;j++)
        {
              printf ("%d ", n);
              if (n==0) n=1;
              else n=0;
        } 
        printf ("\n");
    }
    printf("\n");
    for (i=1;i<=a;i++)
    {
        for (j=1;j<=i;j++)
        {
        if((i+j) % 2 ==0) printf ("1 ");
        else printf ("0 ");
        }
        printf ("\n");
    }
}