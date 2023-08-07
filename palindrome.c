#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int n;
    scanf("%d", &n);

    int a[n], i = 0;
    
    int x = 0, y = n - 1, start = 0, end = n - 1;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    while (x < y)
    {
        if (a[x] != a[y] && y == x + 1)
        {
            printf("*");
            return 0;
        }

        else if (a[x] == a[y])
        {
            x = x + 1;
            y = y - 1;
        }

        else if (a[x] == (a[y] + a[y - 1]))
        {
            a[y - 1] = a[y] + a[y - 1];
            //printf("l34 = %d \n",a[y-1]);

            for (i = y; i < end; i++)
            {
                a[i] = a[i + 1];
            }

            x = x + 1;
            y = y - 2;

            
            end = end - 1;
            //printf("%d \n",a[end]);
            //printf("l44 : start = %d \t end = %d \n",start,end);
        }

        else if ((a[x] + a[x + 1]) == a[y])
        {
            a[x + 1] = a[x] + a[x + 1];

            for (i = x; i > start; i--)
            {
                a[i] = a[i - 1];
            }

            x = x + 2;
            y = y - 1;

            start = start + 1;
            //printf("l59 : start = %d \t end = %d \n",start,end);
        }

        else if ((a[x] + a[x + 1]) == (a[y] + a[y - 1]))
        {
            a[y - 1] = a[y] + a[y - 1];

            for (i = y; i < n; i++)
            {
                a[i] = a[i + 1];
            }

            a[x + 1] = a[x] + a[x + 1];

            for (i = x; i > 0; i--)
            {
                a[i] = a[i - 1];
            }

            x = x + 2;
            y = y - 2;

            start = start + 1;
            end = end - 1;
            //printf("l81 : start = %d \t end = %d \n",start,end);
        }

        else
        {
            printf("*");
            return 0;
        }
    }

    for (i = start; i < end + 1; i++)
    {
        printf("%d\n", a[i]);
    }
    return 0;
}