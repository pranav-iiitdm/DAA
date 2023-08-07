#include <stdio.h>

int mat[100][100];

void adjmat(int n);

int main()
{
    int n;

    printf("Enter no.of vertices : ");
    scanf("%d", &n);

    adjmat(n);

    int count = 0;

    for (int p = 0; p < n; p++)
    {
        for (int q = 0; q < n; q++)
        {
            for (int r = 0; r < n; r++)
            {
                if (mat[p][q] == 1 && mat[q][r] == 1 && mat[r][p] == 1)
                {
                    // printf("%d  %d  %d ",p,q,r);
                    count++;
                }
            }
        }
    }

    count = count / 6;

    if (count == 0)
    {
        printf(" IS TRIANGLE FREE \n");
    }

    else
    {
        printf(" IS NOT TRIANGLE FREE \n");
    }
}

void adjmat(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = 0;
        }
    }

    int src, tgt;

    int max_edges = n * (n - 1);

    for (int i = 0; i < max_edges; i++)
    {
        printf("Enter the source and target for the edge [ Enter ( -1 -1 ) to EXIT ] : ");
        scanf("%d%d", &src, &tgt);

        if (src == -1 && tgt == -1)
        {
            break;
        }

        else if (src == tgt)
        {
            mat[src][tgt] = 0;
        }

        else
        {
            mat[src][tgt] = 1;
            mat[tgt][src] = 1;
        }
    }
}