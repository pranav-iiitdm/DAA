#include <stdio.h>
#include <math.h>

int main()
{
    int k;
    scanf("%d", &k);

    int x = pow(2, k);

    char a[k];

    for (int i = 0; i < k; i++)
    {
        scanf(" %c", &a[i]);
    }

    int y, z, i, b[k], count = 0;

    printf(" { } \n");

    for (y = 1; y <= x; y++)
    {
        z = y;
        i = 0;

        while (z != 0)
        {
            b[i] = z % 2;
            z = z / 2;
            i++;
        }

        for (i = 0; i < k; i++)
        {
            if (b[i] == 1)
            {
                printf(" %c ", a[k - i - 1]);
            }
        }

        printf("\n");
    }

    return 0;
}