#include <stdio.h>

int ternarySearch(int low, int high, int x, int a[])
{
    if (high >= low)
    {

        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;

        if (a[mid1] == x)
        {
            return mid1;
        }
        if (a[mid2] == x)
        {
            return mid2;
        }

        if (x < a[mid1])
        {

            return ternarySearch(low, mid1 - 1, x, a);
        }
        else if (x > a[mid2])
        {

            return ternarySearch(mid2 + 1, high, x, a);
        }
        else
        {

            return ternarySearch(mid1 + 1, mid2 - 1, x, a);
        }
    }

    return -1;
}

int main()
{
    int n;
    scanf("%d", &n);

    int x;
    scanf("%d", &x);

    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int ans = ternarySearch(0, n - 1, x, a);

    if (ans == -1)
    {
        printf("0\n");
    }

    else
    {
        printf("1\n");
    }

    return (0);
}