#include <stdio.h>
void main()
{
    float CP,SP,n,p,l;
    printf ("Enter the Cost Price and the Seliing Price of the Item:");
    scanf ("%f%f",&CP,&SP);
    n=SP-CP;
    if (n>0)
    {
        p=n/CP*100;
        printf ("The profit is of %0.2f and the profit percent is %0.2f%%",n,p);
    }
    if (n==0)
    {
        printf ("No profit or loss made.");
    }
    if (n<0)
    {
        n=(-1*n);
        l=n/CP*100;
        printf ("The loss is of %0.2f and the lost percent is %0.2f%%",n,l);
    }
}