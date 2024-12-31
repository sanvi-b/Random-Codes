#include <stdio.h>
void main()
{
    int n,i,j,k,m,count=0;
    printf ("Enter the starting number:");
    scanf ("%d",&n);
    printf ("Enter the ending number:");
    scanf ("%d",&m);
    if (n==1) printf ("1 is neither prime nor composite.\n");
    printf ("The prime numbers between the given range are:" );
    if (n==1)
    n=2; 
    else;
    for (i=n;i<=m;i++)
    {
        k=0;
        for (j=2;j<=i/2;j++)
        {
            if (i%j==0)
            {
                k=1;
                break;
            }
        } 
        if (k==0)
        {
             printf ("%d ",i);
             count++;
        }
    } 
}
    
   