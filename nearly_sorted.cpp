#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void find(int a[], int n)
{
    int y = 0, x = n - 1, i, max, min;
    
    for (y = 0; y < n - 1; y++)
    {
        if (a[y] > a[y + 1])
            break;
    }

    if (y == n - 1)
    {
        printf("*");
        return;
    }

    for (x = n - 1; x > 0; x--)
    {
        if (a[x] < a[x - 1])
            break;
    }

    max = a[y];
    min = a[y];

    for (i = y + 1; i <= x; i++)
    {
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }

    for (i = 0; i < y; i++)
    {
        if (a[i] > min)
        {
            y = i;
            break;
        }
    }

    for (i = n - 1; i >= x + 1; i--)
    {
        if (a[i] < max)
        {
            x = i;
            break;
        }
    }

    printf("%d\n%d", y, x);

    return;
}
int main()
{
    int n, i;
    scanf("%d", &n);

    int a[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    if (n == 1)
        printf("*");

    else
        find(a, n);

    return 0;
}