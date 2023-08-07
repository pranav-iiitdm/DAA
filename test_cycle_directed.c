#include <stdio.h>

int mat[100][100];

void adjmat(int n);
int IsCycle(int n);
int Check_Cycle(int n, int i, int visited[n], int visited1[n]);

int main()
{
    int n;

    printf("Enter no.of vertcies : ");
    scanf("%d", &n);

    adjmat(n);

    if (IsCycle(n))
    {
        printf("IT IS CYCLIC \n");
    }

    else
    {
        printf("IT IS NOT CYCLIC \n");
    }

    return 0;
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

        else
        {
            mat[src][tgt] = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf(" %d ", mat[i][j]);
        }
        printf("\n");
    }
}

int IsCycle(int n)
{
    int visited[n];
    int visited1[n];

    for (int i = 0; i < n; i++)
    {
        visited1[i] = 0;
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0 && Check_Cycle(n, i, visited, visited1) == 1)
        {
            return 1;
        }
    }

    return 0;
}

int Check_Cycle(int n, int i, int visited[n], int visited1[n])
{

    if (visited[i] == 0)
    {
        visited[i] = 1;
        visited1[i] = 1;

        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1)
            {
                if (visited[j] == 0 && Check_Cycle(n, j, visited, visited1) == 1)
                {
                    return 1;
                }

                else if (visited1[j] == 1)
                {
                    return 1;
                }
            }
        }
    }

    visited1[i] = 0;

    return 0;
}