#include <stdio.h>

int mat[100][100];
int disc[100];
int low[100];
int parent[100];
int ap[100];
int x = 0;

void adjmat(int n);
void dfs(int node, int n);
void articulation_pts(int n);
int minimum(int x, int y)
{
    if (x < y)
        return x;

    if (y < x)
        return y;
}

int main()
{
    int n;

    printf("Enter no.of vertices : ");
    scanf("%d", &n);

    adjmat(n);

    articulation_pts(n);

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

void articulation_pts(int n)
{
    for (int i = 0; i < n; i++)
    {
        disc[i] = -1;
        low[i] = -1;
        parent[i] = -1;
        ap[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (disc[i] == -1)
        {
            dfs(i, n);
        }
    }

    printf("Articulation Points are : ");

    for (int i = 0; i < n; i++)
    {
        if (ap[i] == 1)
        {
            printf(" %d ", i);
        }
    }
}

void dfs(int node, int n)
{
    static int time = 0;
    time++;

    disc[node] = time;
    low[node] = time;
    int ch = 0;

    for (int i = 0; i < n; i++)
    {
        if (mat[node][i] == 1)
        {
            if (disc[i] == -1)
            {
                ch++;
                parent[i] = node;

                dfs(i, n);

                low[node] = minimum(low[node], low[i]);

                if (parent[node] == -1 && ch > 1)
                {
                    ap[node] = 1;
                }

                if (parent[node] != -1 && low[i] > disc[node])
                {
                    ap[node] = 1;
                }
            }

            else if (i != parent[node])
            {
                low[node] = minimum(low[node], disc[i]);
            }
        }
    }
}