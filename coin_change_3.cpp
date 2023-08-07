#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(int array[], int x, int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (array[mid] == x)
            return mid;
        if (array[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int minimum(int k, int arr[])
{
    if (k == 0)
    {
        return 0;
    }
    int min;
    min = arr[0];
    for (int i = 0; i < k - 1; i++)
    {
        if (min >= arr[i + 1])
        {
            min = arr[i + 1];
        }
    }
    return min;
}

int dynamic(int x, int k, int d[])
{
    int change[x];
    int count;
    for (int i = 0; i < k; i++)
    {
        change[d[i] - 1] = 1;
    }
    
    int ans[k];

    for (int i = 2; i <= x; i++)
    {
        if (binarySearch(d, i, 0, k) == -1)
        {
            int j = 0;
            while (d[j] < i)
            {
                d[j] = d[j];
                j++;
            }
            for (int m = 0; m < j; m++)
            {
                int pos = i - d[m];
                ans[m] = change[pos - 1];
            }
            count = 1 + minimum(j, ans);
            change[i - 1] = count;
        }
    }
    return change[x - 1];
}

int main()
{
    int k;
    cout << "Enter number of denominations : ";
    cin >> k;

    int d[k];
    cout << "Enter the denominations :-" << endl;

    for (int i = 0; i < k; i++)
    {
        cin >> d[i];
    }

    sort(d, d + k);
    int x;

    cout << "Enter the amount to which we need change : ";
    cin >> x;

    int count;
    count = dynamic(x, k, d);

    cout << "Number of coins : " << count << endl;

    return 0;
}