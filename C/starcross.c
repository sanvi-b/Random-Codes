#include <stdio.h>
void main()
{
    int n, i, j;
    printf("Enter the number of lines:");
    scanf("%d", &n);
    if (n % 2 == 0)
        printf("Only possible for odd number of lines.");
    else
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (i == j || i + j == n + 1)
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
        }
    }
}