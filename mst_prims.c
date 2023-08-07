#include <stdio.h>

int mat[100][100];

void adjmat(int n);
void min_span_tree(int n);
int min_neighbour(int n, int min_weights[n], int InMST[n]);

int main()
{
    int n;

    printf("Enter no.of vertices : ");
    scanf("%d", &n);

    adjmat(n);

    min_span_tree(n);

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

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf(" %d ", mat[i][j]);
        }
        printf("\n");
    }
}

void min_span_tree(int n)
{
    int parent[n];
    int InMST[n];
    int min_weights[n];

    for (int i = 0; i < n; i++)
    {
        min_weights[i] = __INT_MAX__;
    }

    for (int i = 0; i < n; i++)
    {
        InMST[i] = 0;
    }

    parent[0] = -1;
    min_weights[0] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int v = min_neighbour(n, min_weights, InMST);

        InMST[v] = 1;

        for (int j = 0; j < n; j++)
        {
            if (InMST[j] == 0 && mat[v][j] < min_weights[j] && mat[v][j] != 0)
            {
                min_weights[j] = mat[v][j];
                parent[j] = v;
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", parent[i]);
    // }

    printf("source -> target : weight \n");

    for (int i = 0; i < n; i++)
    {
        printf(" %d -> %d : %d \n", parent[i], i, mat[parent[i]][i]);
    }
}

int min_neighbour(int n, int min_weights[n], int InMST[n])
{
    int min = __INT_MAX__;
    int vertex;

    for (int i = 0; i < n; i++)
    {
        if (InMST[i] == 0 && min_weights[i] < min)
        {
            min = min_weights[i];
            vertex = i;
        }
    }

    return vertex;
}