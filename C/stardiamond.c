#include <stdio.h>
void main()
{
    int n, i, j, ml, k, nsp, nst;
    printf("Enter the number of lines:");
    scanf("%d", &n);
    nst = 1;
    nsp = n / 2;
    ml = (n + 1) / 2;
    if (n % 2 == 0)
        printf("Only possible for odd number of lines.");
    else
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= nsp; j++)
                printf(" ");
            for (k = 1; k <= nst; k++)
                printf("*");
            if (i < ml)
            {
                nsp--;
                nst += 2;
            }
            else
            {
                nsp++;
                nst -= 2;
            }
            printf("\n");
        }
    }
}