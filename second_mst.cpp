#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int parent[100005];
int weight_gph[3][100];

int adjmat(int n);

vector<int> present;

int edg;

struct edge
{
    int src, dest, weight;
} edges[100005];

bool cmp(edge x, edge y)
{
    return x.weight < y.weight;
}

void initialise(int n)
{
    for (int i = 1; i <= n; i++)
        parent[i] = i;
}

int find(int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

int union1(int i, int sum)
{
    int x, y;

    x = find(edges[i].src);
    y = find(edges[i].dest);

    if (x != y)
    {
        parent[x] = y;

        present.push_back(i);

        sum += edges[i].weight;
    }

    return sum;
}

int union2(int i, int sum)
{
    int x, y;

    x = find(edges[i].src);
    y = find(edges[i].dest);

    if (x != y)
    {
        parent[x] = y;

        sum += edges[i].weight;
        edg++;
    }

    return sum;
}

int main()
{
    int n;

    cout << "Enter no.of vertices : ";
    cin >> n;

    initialise(n);

    int E = adjmat(n);

    int sum = 0;
    for (int i = 0; i < E; i++)
    {
        sum = union1(i, sum);
    }

    // printing the cost of MST
    cout << "MST: " << sum << "\n";

    // initialising cost of second best MST
    int sec_best_mst = INT_MAX;

    // setting the sum to zero again.
    sum = 0;
    int j;
    for (j = 0; j < present.size(); j++)
    {
        initialise(n);
        edg = 0;
        for (int i = 0; i < E; i++)
        {
            if (i == present[j])
                continue;
            sum = union2(i, sum);
        }

        if (edg != n - 1)
        {
            sum = 0;
            continue;
        }

        if (sec_best_mst > sum)
            sec_best_mst = sum;
        sum = 0;
    }

    cout << "Second Best MST: "
         << sec_best_mst << "\n";
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