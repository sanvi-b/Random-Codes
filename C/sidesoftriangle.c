#include <stdio.h>
void main()
{
    int s1,s2,s3;
    printf ("Enter the sides of a triangle:");
    scanf ("%d%d%d", &s1,&s2,&s3);
    if (s1+s2>s3 && s1+s3>s2 && s2+s3>s1 && s1-s2<s3 && s1-s3<s2 && s2-s3<s1)
    {
        printf ("The triangle is possible.");
    }
    else printf ("The triangle is not possible.");
}