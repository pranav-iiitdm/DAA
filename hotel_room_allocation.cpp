#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, c, k = 1;
        cin >> n >> m >> c;

        int a[c + 1];
        for (int i = 1; i <= c; i++)
            cin >> a[i];

        int arr[n + 1][m + 1];

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                for (int j = 0; j < m; j++)
                {
                    if (a[k] == 0)
                        k++;
                    arr[i][j] = k;
                    a[k]--;
                }
            }
            else
            {
                for (int j = m - 1; j >= 0; j--)
                {
                    if (a[k] == 0)
                        k++;
                    arr[i][j] = k;
                    a[k]--;
                }
            }
            
            for (int j = 0; j < m; j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}