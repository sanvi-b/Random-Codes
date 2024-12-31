#include <stdio.h>
void main ()
{
    char ch1='a', ch2='z', ch3='A',ch4='Z';
    int i,j;
    for (i=ch1;i<=ch2;i++)
    {printf ("%c %d\n",ch1,i);
     ch1++;}
    for (j=ch3;j<=ch4;j++)
   { printf ("%c %d\n",ch3,j);
   ch3++;}
}