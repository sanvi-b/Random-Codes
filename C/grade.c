#include <stdio.h>
void main()
{
    int m;
    printf ("Enter the marks of student:");
    scanf ("%d",&m);
    if (m>90) printf ("S Grade.");
    else if (m>80) printf ("A Grade.");
    else if (m>70) printf ("B Grade.");
    else if (m>60) printf ("C Grade.");
    else if (m>=50) printf ("D Grade.");
    else printf ("Failed.");
}