#include <stdio.h>

int main()
{
    int x, k, temp;
    int de;

    printf("Enter the amount \n");
    scanf("%d", &x);

    printf("Enter no.of denominations \n");
    scanf("%d", &k);

    int d[k];

    printf("Enter denominations \n");

    for (int i = 0; i < k; i++)
    {
        scanf("%d", &d[i]);
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
        if (x >= d[i])
        {
            de = x / d[i];
            printf("No.of coins of %d denomination is %d\n", d[i], de);
            x = x % d[i];
        }
    }

    return 0;
}

// This algorithm fails for the following case :

//         if the amount entered is 6 and the denominations are 1,3,4
//         The answer which we get from this algorithm is
//         1 coin of 4 rupees and 2 coins of 1 rupee

//         But the ideal answer is 2 coins of 3 rupee