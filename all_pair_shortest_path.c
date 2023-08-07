#include <stdio.h>
#include <stdint.h>

int min(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}

int main()
{
    int n, source, b, source1;
    printf("enter the no.of nodes\n");
    scanf("%d", &n);

    int dist[n];

    for (int i = 0; i < n; i++)
        dist[i] = -1111;

    int w[n][n];
    int dist1[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            w[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                w[i][j] = 0;

            else if (w[i][j] == 0)
            {
                printf("enter w b/w %d and %d : ", i, j);
                scanf("%d", &b);

                w[i][j] = b;
                w[j][i] = b;
            }
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
            dist[i] = INT32_MAX;
        source1 = k;
        dist[source1] = 0;
        for (int i = 0; i < n - 1; i++)
        {
            source = i + source1;
            if (source < n)
            {
                for (int j = 0; j < n; j++)
                {
                    if (w[source][j] != 0)
                    {
                        if (dist[j] > dist[source] + w[source][j] && dist[source] != INT32_MAX)
                            dist[j] = dist[source] + w[source][j];
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (k == 0)
                dist1[k][i] = dist[i];
            else if (k <= i)
            {

                dist1[k][i] = min(dist1[k - 1][i] + dist1[k][k - 1], dist[i]);
            }
            if (k > i)
            {
                dist1[k][i] = dist1[i][k];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d to %d is %d\n", i, j, dist1[i][j]);
        }
    }
}