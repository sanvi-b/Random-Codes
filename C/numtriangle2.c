#include <stdio.h>
void main()
{
    int a,i,j,k,l,n;
    printf ("Enter the number of lines:");
    scanf ("%d",&a);
    for (i=1;i<=a;i++)
    {
        for (j=1;j<=a-i;j++)
        {
             printf (" ");
        } 
        for (k=1;k<i;k++)
        printf ("%d",k);
        for (l=k;l>=1;l--)
        {
            printf ("%d",l);
        }
        printf ("\n");
    }
    printf ("\n");
    for (i=1;i<=a;i++)
    {
        for (j=1;j<=a-i;j++)
        {
             printf (" ");}
        n=65;
        for (k=1;k<=i;k++)
        {
            printf ("%c",n);
        n++;}
        n=i+63;
        for (l=1;l<=i-1;l++)
        {
            printf ("%c",n);
        n--;}
        printf ("\n");
    }
}