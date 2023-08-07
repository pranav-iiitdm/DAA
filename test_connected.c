#include <stdio.h>

int mat[100][100];
int visited[100];

void adjmat(int n);
int IsConneted(int n);
void dfs(int node, int n);

int main()
{
    int n;

    printf("Enter no.of vertices : ");
    scanf("%d", &n);

    adjmat(n);

    int x = IsConneted(n);

    if (x == 1)
    {
        printf("CONNECTED \n");
    }

    else
    {
        printf("NOT CONNECTED \n");
        printf("The graph has %d different connected components \n", x);
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

int IsConneted(int n)
{
    // int src;

    // printf("Enter the source point \n");
    // scanf("%d",&src);

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            count++;
            dfs(i, n);
        }
    }

    return count;
}

void dfs(int node, int n)
{
    // printf("%d l108 \n", node);

    visited[node] = 1;

    for (int i = 0; i < n; i++)
    {
        if (mat[node][i] == 1)
        {
            if (visited[i] == 0)
            {
                dfs(i, n);
            }
        }
    }
}