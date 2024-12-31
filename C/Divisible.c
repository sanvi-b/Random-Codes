#include <stdio.h>
void main()
{
    int n;
    printf ("Enter a positive number:");
    scanf ("%d",&n);
    if (n%5==0 && n%3==0)
    {
        printf ("The number is divisible by 5 and 3.\n");
    }
    else printf ("The number is not divisible by 5 and 3.\n");
    if (n%5==0 || n%3==0)
    {
        printf ("The number is divisible by 5 or 3.\n");
    }
    else printf ("The number is not divisible by 5 or 3.\n");
    
}