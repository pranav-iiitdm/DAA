#include <stdio.h>

int mat[100][100];
int weight_gph[3][100];
int vis[100];
int mst[3][100];

int adjmat(int n);
void min_span_tree(int n, int x);
int Detect_Cycle(int node, int parent, int n, int vis[n]);

int main()
{
    int n;

    printf("Enter no.of vertices : ");
    scanf("%d", &n);

    int x = adjmat(n);

    min_span_tree(n, x);

    return 0;
}

void min_span_tree(int n, int x)
{
    int k = 0, l = 0;
    int res[100];

    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
    }

    // printf(" %d l35\n", x);

    for (int i = 0; i < x; i++)
    {
        if (i < 2)
        {
            mst[0][l] = weight_gph[0][i];
            mst[1][l] = weight_gph[1][i];
            mst[2][l] = weight_gph[2][i];
            l++;
            res[k] = i;
            k++;
        }

        else
        {
            if (Detect_Cycle(weight_gph[0][i], weight_gph[1][i], n, vis) == 0)
            {
                // printf(" %d ", Detect_Cycle(weight_gph[0][i], weight_gph[1][i], n, vis));
                res[k] = i;
                k++;
            }
        }
        // printf(" %d \n", Detect_Cycle(weight_gph[0][i], weight_gph[1][i], n, vis));
    }

    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", vis[i]);
    // }

    printf(" Source -> Target : Weight \n");

    for (int i = 0; i < k; i++)
    {
        printf(" %d -> %d : %d \n", weight_gph[0][i], weight_gph[1][i], weight_gph[2][i]);
    }
}

int Detect_Cycle(int node, int parent, int n, int vis[n])
{
    vis[node] = 1;

    for (int i = 0; i < n; i++)
    {
        if (i != node)
        {
            if (mst[node][i] == 1)
            {
                if (vis[i] == 0)
                {
                    if (Detect_Cycle(i, node, n, vis) == 1)
                    {
                        printf("L147\n");
                        return 1;
                    }
                }
                else if (vis[i] == 1 && i != parent)
                {
                    printf("L153\n");
                    return 1;
                }
            }
        }
    }

    printf("L160\n");
    return 0;
}

int adjmat(int n)
{
    int src, tgt, wt, x = 0;

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
            printf("Enter the weight for the edge : ");
            scanf("%d", &wt);

            mat[src][tgt] = 1;
            mat[tgt][src] = 1;

            weight_gph[0][x] = src;
            weight_gph[1][x] = tgt;
            weight_gph[2][x] = wt;

            x++;
        }
    }

    int temp, temp1, temp2;

    for (int i = 0; i < x - 1; i++)
    {
        for (int j = i; j < x; j++)
        {
            if (weight_gph[2][i] > weight_gph[2][j])
            {
                temp = weight_gph[1][j];
                weight_gph[1][j] = weight_gph[1][i];
                weight_gph[1][i] = temp;

                temp1 = weight_gph[0][j];
                weight_gph[0][j] = weight_gph[0][i];
                weight_gph[0][i] = temp1;

                temp2 = weight_gph[2][j];
                weight_gph[2][j] = weight_gph[2][i];
                weight_gph[2][i] = temp2;
            }
        }
    }

    return x;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         printf(" %d ", mat[i][j]);
    //     }
    //     printf("\n");
    // }
}