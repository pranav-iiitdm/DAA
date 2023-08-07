#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n, m;

    cout << "Enter number of classes :";
    cin >> n;

    cout << "Enter number of lectures :";
    cin >> m;

    int lec[m][2];
    vector<pair<int, int>> v;

    cout << "Enter lecture timings of each class :" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if(j==0)
            {
                cout<<"Enter the start time "<<endl;
                cin >> lec[i][j];
            }

            if(j==1)
            {
                cout<<"Enter the end time "<<endl;
                cin >> lec[i][j];
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        v.push_back({lec[i][0], 1});
        v.push_back({lec[i][1], -1});
    }

    sort(v.begin(), v.end());

    int k = 0, temp = 0;

    for (int i = 0; i < v.size(); i++)
    {
        temp += v[i].second;
        k = max(k, temp);
    }

    if (k > n)
    {
        cout << "NOT POSSIBLE";
    }

    else
    {
        cout << "Minimum no of class is : " << k;
    }

    return 0;
}