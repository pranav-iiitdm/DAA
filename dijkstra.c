#include <stdio.h>

int mat[100][100];

void adjmat(int n);
int min_dist(int n, int dist[], int sp[]);
void dijkstra(int n);

int main()
{
    int n;

    printf("Enter no.of vertices : ");
    scanf("%d", &n);

    adjmat(n);

    dijkstra(n);

    return 0;
}

void adjmat(int n)
{
    int src, tgt, wt;

    int max_edges = n * (n - 1);

    for (int i = 0; i < max_edges; i++)
    {
        printf("Enter the source and target for the edge [ Enter ( -1 -1 ) to EXIT ] : ");
        scanf("%d%d", &src, &tgt);

        printf("Enter the weight for the edge : ");
        scanf("%d", &wt);

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
            mat[src][tgt] = wt;
            mat[tgt][src] = wt;
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         printf(" %d ", mat[i][j]);
    //     }
    //     printf("\n");
    // }
}

int min_dist(int n, int dist[], int sp[])
{
    int min = __INT_MAX__, index;

    for (int i = 0; i < n; i++)
    {
        if (sp[i] == 0 && dist[i] < min)
        {
            min = dist[i];
            index = i;
        }
    }

    return index;
}

void dijkstra(int n)
{
    int dist[n];

    int sp[n];

    for (int i = 0; i < n; i++)
    {
        dist[i] = __INT_MAX__;
        sp[i] = 0;
    }

    int src;

    printf("Enter the source point \n");
    scanf("%d", &src);

    dist[src] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int u = min_dist(n, dist, sp);

        sp[u] = 1;

        for (int v = 0; v < n; v++)
        {
            if (!sp[v] && mat[u][v] && dist[u] != __INT_MAX__ && dist[u] + mat[u][v] < dist[v])
            {
                dist[v] = dist[u] + mat[u][v];
            }
        }
    }

    printf("Source \t\t Target \t\t Distance\n");
    for (int i = 0; i < n; i++)
        printf("%d \t\t %d \t\t %d\n", src, i, dist[i]);
}