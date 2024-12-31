#include <stdio.h>
void main()
{
    int n;
    printf ("Enter a positive number:");
    scanf ("%d",&n);
    if (n%5==0 || n%3==0)
    {
        if (n%15!=0)
        {
            printf ("The number is divisible by 3 or 5 but not divisible by 15.");
        }
        else printf ("The number is divisible by 3 or 5 and also divisible by 15.");
    }
    else printf ("The number is not divisible by 3 or 5.");
}