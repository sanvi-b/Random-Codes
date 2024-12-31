#include <stdio.h>
void main()
{
    int n,i,j,k;
    printf ("Enter a number:");
    scanf ("%d",&n);
    if (n==2) {printf("The number is a prime number."); 
    return;}
    if (n>2)
    { k=1;
    for (i=2;i<=n/2;i++)
    {
        if (n%i==0){
        k=0;
        break;}
    }}
    if (k==0)
    printf ("The number is a composite number.");    
    else printf ("The number is a prime number.");
}