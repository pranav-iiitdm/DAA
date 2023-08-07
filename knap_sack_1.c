#include <stdio.h>

int main()
{
    int n,temp,temp1,w;

    printf("Enter weight of object \n");
    scanf("%d",&w);

    printf("Enter no.of objects \n");
    scanf("%d", &n);

    int a[2][n];

    int ans[n];
    int x=0;

    for (int i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            for (int j = 0; j < n; j++)
            {
                a[i][j] = j + 1;
            }
        }

        if (i == 1)
        {
            printf("Enter weights of %d objects \n", n);

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
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
        {
            printf(" %d ",a[i][j]);
        }

        printf("\n");
    } 

    for(int j=0;j<n;j++)
    {
        if(w!=0)
        {
            ans[x]=a[0][j];
            x++;
            w=w-a[1][j];
        }
    }

    for(int i=0;i<x;i++)
    {
        printf(" %d ",ans[i]);
    }
    return 0;
}