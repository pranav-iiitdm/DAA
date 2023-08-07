#include<iostream>

using namespace std;

int knapsack(int weight, int w[], int p[], int n)
{
    if (n == 0 || w == 0)
        return 0;

    if (w[n - 1] > weight)
        return knapsack(weight, w, p, n - 1);

    else
        return max(p[n - 1] + knapsack(weight - w[n - 1], w, p, n - 1), knapsack(weight, w, p, n - 1));
}

int main()
{
    int n;

    cout << "Enter number of parts :";
    cin >> n;

    int weight;

    cout << "Enter total weight :";
    cin >> weight;

    int p[n], w[n];
    cout << "Enter profit and weight of each part" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        cin >> w[i];
    }

    cout << "Max value of profit is : " << knapsack(weight, w, p, n);
    
    return 0;
}