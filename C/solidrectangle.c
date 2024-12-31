#include <stdio.h>
void main()
{
    int a, b, i, j;
    printf("Enter the number of lines:");
    scanf("%d", &a);
    printf("Enter the number of stars in each line:");
    scanf("%d", &b);
    for (i = 1; i <= a; i++)
    {
        printf("*");
        for (j = 1; j < b; j++)
            printf("*");
        printf("\n");
    }
}