#include <stdio.h>

int main()
{
    int x, k, temp, flag = 0, count = 0, count1 = 0;
    int de;

    printf("Enter the amount \n");
    scanf("%d", &x);

    int x1 = x;

    printf("Enter no.of denominations \n");
    scanf("%d", &k);

    int d[k];
    int d1[k];

    printf("Enter denominations \n");

    for (int i = 0; i < k; i++)
    {
        scanf("%d", &d[i]);
        d1[i] = 0;
    }

    for (int i = 0; i < k - 1; i++)
    {
        for (int j = i; j < k; j++)
        {
            if (d[i] > d[j])
            {
                temp = d[j];
                d[j] = d[i];
                d[i] = temp;
            }
        }
    }

    for (int i = k - 1; i >= 0; i--)
    {
        d1[i] = x / d[i];
        count = count + x / d[i];
        x = x % d[i];
    }

    if (x != 0)
    {
        printf("Change not possible with given denominations \n");
        return 0;
    }
    else
    {
        for (int j = 2; j <= k; j++)
        {
            x = x1;
            for (int i = k - j; i >= 0; i--)
            {
                count1 = count1 + x / d[i];
                x = x % d[i];

                if (count1 < count && x == 0)
                {
                    x = x1;
                    count = count1;
                    for (int i = k - 1; i > k - j; i--)
                        d1[i] = 0;
                    for (int i = k - j; i >= 0; i--)
                    {
                        d1[i] = x / d[i];
                        x = x % d[i];
                    }
                }
            }
        }

        for (int i = 0; i < k; i++)
        {
            printf("No.of coins of %d Rs coins is %d \n", d[i], d1[i]);
        }
        printf("Total coins : %d \n", count);

        return 0;
    }
}