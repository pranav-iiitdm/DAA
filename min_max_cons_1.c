#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    scanf("%d", &n);

    if (n % 2 == 1)
    {
        int a[n + 1];

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }

        a[n] = a[n - 1];

        int min[100], max[100];
        int x = 0, y = 0, temp;

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

        for (int i = 0; i < x - 1; i++)
        {
            for (int j = i; j < x; j++)
            {
                if (min[i] > min[j])
                {
                    temp = min[j];
                    min[j] = min[i];
                    min[i] = temp;
                }
            }
        }

        for (int i = 0; i < y - 1; i++)
        {
            for (int j = i; j < y; j++)
            {
                if (max[i] > max[j])
                {
                    temp = max[j];
                    max[j] = max[i];
                    max[i] = temp;
                }
            }
        }

        printf("%d\n%d", min[0], max[y - 1]);
    }

    else
    {
        int a[n];

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }

        int min[100], max[100];
        int x = 0, y = 0, temp;

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

        for (int i = 0; i < x - 1; i++)
        {
            for (int j = i; j < x; j++)
            {
                if (min[i] > min[j])
                {
                    temp = min[j];
                    min[j] = min[i];
                    min[i] = temp;
                }
            }
        }

        for (int i = 0; i < y - 1; i++)
        {
            for (int j = i; j < y; j++)
            {
                if (max[i] > max[j])
                {
                    temp = max[j];
                    max[j] = max[i];
                    max[i] = temp;
                }
            }
        }

        printf("%d\n%d", min[0], max[y - 1]);
    }

    return 0;
}
