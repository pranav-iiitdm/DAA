#include<stdio.h>

int maximum(int x,int y)
{
    if(x>y)
    {
        return x;
    }

    if(x<y)
    {
        return y;
    }
}

int dp(int n,int a[2][n],int w)
{
    int table[n+1][w+1];

    for(int i=0;i<w+1;i++)
    {
        table[0][i]=0;
    }

    for(int i=1;i<n+1;i++)
    {
        table[i][0]=0;
    }

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<w+1;j++)
        {
            if(a[0][i-1]<=j)
            {
                table[i][j]=maximum(table[i-1][j],table[i-1][j-a[0][i-1]]+a[1][i-1]);
            }

            else
            {
                table[i][j]=table[i-1][j];
            }
        }
    }

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<w+1;j++)
        {
            printf(" %d ",table[i][j]);
        }

        printf("\n");
    }

    return table[n][w];
}

int main()
{
    int w,n;

    printf("Enter weight of the bag \n");
    scanf("%d",&w);

    printf("Enter no.of objects \n");
    scanf("%d", &n);

    int a[2][n];

    for (int i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            printf("Enter weights of %d objects \n", n);

            for (int j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }

        if (i == 1)
        {
            printf("Enter corresponding profits \n");

            for (int j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
            }
        } 
    }

    printf("Max profit is %d \n",dp(n,a,w));

    return 0;
}