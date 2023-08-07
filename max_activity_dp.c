#include <stdio.h>

int maximum(int x, int y)
{
    if (x > y)
    {
        return x;
    }

    if (x < y)
    {
        return y;
    }
}

int max_activities(int n, int a[3][n])
{
    int ans[n];
    int x = 0;

    ans[0] = 0;
    x++;

    for (int i = 1; i < n; i++)
    {
        if (a[0][i] >= a[1][ans[x - 1]])
        {
            ans[x] = i;
            // printf("l74 = %d \n",i);
            x++;
        }
    }

    return x;
}

void dp(int n, int a[3][n])
{
    int dp[n];
    int count = 0, j,i;

    int z=max_activities(n,a);

    int ans[z];
    int k=0;

    dp[0] = a[2][0];
    // ans[k]=0;
    // k++;

    for (i = 1; i < n; i++)
    {
        int x = a[2][i];

        for (j = i - 1; j >= 0; j--)
        {
            if (a[1][j] <= a[0][i])
            {
                count++;
                break;
            }
        }

        if (count != 0)
        {
            x += dp[j];
        }

        dp[i] = maximum(x, dp[i - 1]);

        if(dp[i]==x)
        {  
            ans[k]=j;
            //printf(" l73 %d \n",j);
            k++;
        }

        else
        {
            if(dp[i]!=dp[i-1])
            {
                ans[k]=i-1;
                //printf(" l82 %d \n",i-1);
                k++;
            } 
        }  
    }

    ans[z-1]=i-1;

    for (int i = 0; i < z; i++)
    {
        printf(" Activity - %d \n",ans[i]+1);
        printf(" Start time : %d \n",a[0][ans[i]]);
        printf(" End time : %d \n",a[1][ans[i]]);
    }

    printf("Maximum profit is : %d \n",dp[n-1]);
}

int main()
{
    int n, temp, temp1, temp2;

    printf("Enter no.of activities \n");
    scanf("%d", &n);

    int a[3][n];

    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            printf("Enter the start time of %d activities \n", n);

            for (int j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }

        if (i == 1)
        {
            printf("Enter the end time of %d activities \n", n);

            for (int j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }

        if (i == 2)
        {
            printf("Enter corresponding weights for %d activities \n", n);

            for (int j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (a[1][i] > a[1][j])
            {

                temp = a[1][j];
                a[1][j] = a[1][i];
                a[1][i] = temp;

                temp1 = a[0][j];
                a[0][j] = a[0][i];
                a[0][i] = temp1;

                temp2 = a[2][j];
                a[2][j] = a[2][i];
                a[2][i] = temp2;
            }
        }
    }

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         printf(" %d ", a[i][j]);
    //     }

    //     printf("\n");
    // }

    // int z = max_activities(n, a);
    dp(n, a);

    return 0;
}












































































// int table[z + 1][n];

// for (int i = 0; i < n; i++)
// {
//     table[0][i] = 0;
// }

// for (int i = 0; i < n; i++)
// {
//     table[1][i] = a[2][i];
// }

// for (int i = 2; i < z + 1; i++)
// {
//     for (int j = 1; j < n + 1; j++)
//     {
//         if (i > j)
//         {
//             table[i][j - 1] = table[i - 1][j - 1];
//         }

//         else
//         {
//             for (int k = 0; k < j - 1; k++)
//             {
//                 if (a[1][k] <= a[0][j - 1])
//                 {
//                     printf(" l66 %d %d %d %d \n", i, j, k, a[2][j - 1]);

//                     if (table[i][j - 2] != table[i][0])
//                     {
//                         table[i][j - 1] = maximum(table[i][j - 2], ((table[i][j - 2] - table[i][0]) + a[i][j - 1]));
//                     }

//                     else
//                     {
//                         table[i][j - 1] = maximum(table[i][j - 2], (table[i][j - 2] + a[i][j - 1]));
//                     }

//                     if(k==i-2)
//                     {
//                         break;
//                     }

//                 }

//                 else
//                 {
//                     printf(" l72 %d %d %d \n", i, j, k);
//                     table[i][j - 1] = maximum(table[i - 1][j - 1], table[i][j - 2]);
//                     break;
//                     // printf(" l72 = %d %d %d \n",i,j,table[i][j]);
//                 }
//             }
//         }

// for(int k=0;k<i;k++)
// {
//     if(a[1][k]<=a[0][j])
//     {
//         table[i][j]=maximum(table[i][j-1],a[2][j-1]+table[i][j-1]);
//     }

//     else
//     {
//         table[i][j]=table[i][j-1];
//     }
// }
//    }
// }

// for (int i = 0; i < z + 1; i++)
// {
//     for (int j = 0; j < n; j++)
//     {
//         printf(" %d ", table[i][j]);
//     }

//     printf("\n");
// }