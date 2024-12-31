#include<stdio.h>
void main ()
{
    int n;
    printf ("Enter a Year:");
    scanf ("%d",&n);
    if (n%4==0)
    {
        printf ("The year %d is a Leap Year.",n);
    }
    else printf("The year %d is not a Leap Year.",n);
}