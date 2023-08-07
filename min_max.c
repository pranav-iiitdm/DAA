#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    scanf("%d", &n);

    if (n == 1)
    {
        printf("*");
    }

    if (n % 2 == 1)
    {
        int a[n + 1];

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }

        a[n] = a[n - 1];

        int min[100], max[100];
        int x = 0, y = 0;

        for (int i = 0; i < n + 1; i = i + 2)
        {
            if (a[i] < a[i + 1])
            {
                min[x] = a[i];
                max[y] = a[i + 1];
                x++;
                y++;
            }

            else
            {
                min[x] = a[i + 1];
                max[y] = a[i];
                x++;
                y++;
            }
        }

        int min1 = min[0], max1 = max[0];

        for (int i = 1; i < x; i++)
        {
            if (min[i] < min1)
            {
                min1 = min[i];
            }
        }

        for (int i = 1; i < y; i++)
        {
            if (max[i] > max1)
            {
                max1 = max[i];
            }
        }

        printf("%d\n%d", min1, max1);
    }

    else
    {
        int a[n];

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }

        int min[100], max[100];
        int x = 0, y = 0;

        for (int i = 0; i < n; i = i + 2)
        {
            if (a[i] < a[i + 1])
            {
                min[x] = a[i];
                max[y] = a[i + 1];
                x++;
                y++;
            }

            else
            {
                min[x] = a[i + 1];
                max[y] = a[i];
                x++;
                y++;
            }
        }

        int min1 = min[0], max1 = max[0];

        for (int i = 1; i < x; i++)
        {
            if (min[i] < min1)
            {
                min1 = min[i];
            }
        }

        for (int i = 1; i < y; i++)
        {
            if (max[i] > max1)
            {
                max1 = max[i];
            }
        }

        printf("%d\n%d", min1, max1);
    }

    return 0;
}
