#include <stdio.h>

int main()
{
    int i, n;
    scanf("%d", &n);

    int a[n], total = 0;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        total = total + a[i];
    }

    if (n == 1)
    {
        printf("%d\n0", a[0]);
        return 0;
    }

    if (n == 2)
    {
        printf("*");
        return 0;
    }

    int sum[n];
    for (i = 0; i < n; i++)
    {
        sum[i] = total + a[i];
    }

    int max, count = 0, k = 0;

    max = sum[0];

    for (i = 1; i < n; i++)
    {
        if (max == sum[i])
        {
            k++;
        }
        if (max > sum[i])
        {

            max = sum[i];
        }
        count++;
    }

    if (k == n - 1)
    {
        printf("*\n");
    }

    else
    {
        printf("%d\n", total + max);
    }
    
    printf("%d", count);

    return 0;
}