#include<stdio.h>

int minimum(int x,int y)
{
    if(x<y)
    {
        return x;
    }

    if(y<x)
    {
        return y;
    }
}

int dp(int n,int d[n],int x)
{
    int table[n][x+1];
    int z;

    for(int i=0;i<n;i++)
    {
        table[i][0]=1;
    }

    for(int i=1;i<x+1;i++)
    {
        if(i%d[0]==0)
        {
            table[0][i]=1;
        }

        else
        {
            table[0][i]=0;
        }
    }

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<x+1;j++)
        {
            if(d[i]>j)
            {
                table[i][j]=table[i-1][j];
            }

            else
            {
                table[i][j]=table[i-1][j]+table[i][j-d[i]];
            }
        }
    }

    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<x+1;j++)
        {
            printf(" %d ",table[i][j]);
        }

        printf("\n");
    }*/

    return table[n-1][x];
}

int main()
{
    int n,x,temp;

    printf("Enter no.of denominations \n");
    scanf("%d",&n);

    int d[n];

    printf("Enter %d denominations \n",n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d",&d[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (d[i] > d[j])
            {

                temp = d[j];
                d[j] = d[i];
                d[i] = temp;
            }
        }
    }

    printf("Enter the amount for which the change is needed \n");
    scanf("%d",&x);
    
    printf("No.of ways in which the change can be given is %d \n",dp(n,d,x));

    return 0;
}