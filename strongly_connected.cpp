#include <iostream>
#include <stack>

using namespace std;

int mat[100][100];
int mat1[100][100];
int visited[100];

stack<int> stk;

void adjmat(int n);
void topological_sort(int n, int node);
void get_transpose(int n);
void scc(int n);
void dfs(int n, int node);

int main()
{
    int n;

    cout << "Enter no.of vertices : ";
    cin >> n;

    adjmat(n);
    scc(n);

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

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         printf(" %d ", mat[i][j]);
    //     }
    //     printf("\n");
    // }
}

void topological_sort(int n, int node)
{
    visited[node] = 1;

    for (int i = 0; i < n; i++)
    {
        if (mat[node][i] == 1)
        {
            if (visited[i] == 0)
            {
                topological_sort(n, i);
            }
        }
    }

    stk.push(node);
}

void get_transpose(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat1[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1)
            {
                mat1[j][i] = 1;
            }
        }
    }
}

void scc(int n)
{
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            topological_sort(n, i);
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

    // printf("\n");

    get_transpose(n);

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         printf(" %d ", mat1[i][j]);
    //     }
    //     printf("\n");
    // }

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    while (!stk.empty())
    {
        int x = stk.top();

        stk.pop();

        if (visited[x] == 0)
        {
            dfs(n, x);
            cout << endl;
        }
    }
}

void dfs(int n, int node)
{
    visited[node] = 1;

    cout << node << " ";

    for (int j = 0; j < n; j++)
    {
        if (mat1[node][j] == 1)
        {
            if (visited[j] == 0)
            {
                dfs(n, j);
            }
        }
    }
}