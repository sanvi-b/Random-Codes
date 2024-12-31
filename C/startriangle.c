#include <stdio.h>
void main()
{
    int a, i, j, k;
    printf("Enter the number of lines:");
    scanf("%d", &a);
    for (i = 1; i <= a; i++)
    {
        for (j = 1; j <= a - i; j++)
            printf(" ");
        for (k = 2; k <= 2 * i; k++)
            printf("*");
        printf("\n");
    }
}