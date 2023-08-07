#include <stdio.h>

int weight_gph[3][100];
int parent[100];
int rank_[100];

int adjmat(int n);
void makeSet(int n);
int findParent(int node);
void union_(int u, int v);
void mst(int n);

int main()
{
    int n;

    printf("Enter no.of vertices : ");
    scanf("%d", &n);

    int x = adjmat(n);
    makeSet(n);
    mst(n);

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

        else
        {
            printf("Enter the weight for the edge : ");
            scanf("%d", &wt);

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
}

void makeSet(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank_[i] = 0;
    }
}

int findParent(int node)
{
    if (node == parent[node])
    {
        return node;
    }

    else
    {
        return parent[node] = findParent(parent[node]);
    }
}

void union_(int u, int v)
{
    u = parent[u];
    v = parent[v];

    if (rank_[u] < rank_[v])
    {
        parent[u] = v;
    }

    else if (rank_[v] < rank_[u])
    {
        parent[v] = u;
    }

    else
    {
        parent[v] = u;
        rank_[u]++;
    }
}

void mst(int n)
{
    int x = 0;
    int mst_[n];

    for (int i = 0; i < n; i++)
    {
        if (findParent(weight_gph[0][i]) != findParent(weight_gph[1][i]))
        {
            mst_[x] = i;
            x++;
            union_(weight_gph[0][i], weight_gph[1][i]);
        }
    }

    printf("Source -> Target : Weight \n");

    for (int i = 0; i < x; i++)
    {
        printf(" %d\t-> %d \t : %d \n", weight_gph[0][i], weight_gph[1][i], weight_gph[2][i]);
    }
}