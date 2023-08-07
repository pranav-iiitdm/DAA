#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

int mat[100][100];

void adjmat(int n);
int test_bipartite(int n);

int main()
{
    int n;

    printf("Enter no.of vertices : ");
    scanf("%d", &n);

    adjmat(n);

    int x = test_bipartite(n);

    if (x == 1)
    {
        printf(" Given Graph is BIPARTITE \n");
    }

    else
    {
        printf(" Given Graph is NOT BIPARTITE \n");
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

int test_bipartite(int n)
{
    int src;

    printf("Enter the source point for the test \n");
    scanf("%d", &src);

    int test[n];

    for (int i = 0; i < n; i++)
    {
        test[i] = -1;
    }

    test[src] = 1;

    queue<int> q;

    q.push(src);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        if (mat[node][node] == 1)
        {
            return 0;
        }

        for (int i = 0; i < n; i++)
        {
            if (mat[node][i] == 1 && test[i] == -1)
            {
                test[i] = 1 - test[node];
                q.push(i);
            }

            else if (mat[node][i] == 1 && test[node] == test[i])
            {
                return 0;
            }
        }
    }

    return 1;
}