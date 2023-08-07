#include<stdio.h>

int main()
{
    int n,temp,temp1;

    printf("Enter no.of activities \n");
    scanf("%d",&n);

    int a[2][n];

    for (int i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            printf("Enter the start time of %d activities \n",n);

            for (int j = 0; j < n; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }

        if (i == 1)
        {
            printf("Enter the end time of %d activities \n",n);

            for (int j = 0; j < n; j++)
            {
                scanf("%d",&a[i][j]);
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

    /*for(int i=0;i<2;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf(" %d ",a[i][j]);
        }

        printf("\n");
    }*/ 

    int ans[n];
    int x=0;

    ans[0]=0;
    x++;

    for(int i=1;i<n;i++)
    {
        if(a[0][i]>=a[1][ans[x-1]])
        {
            ans[x]=i;
            //printf("l74 = %d \n",i);
            x++;
        }
    }

    // for(int i=0;i<x;i++)
    // {
    //     printf(" %d ",ans[i]);
    // }

    printf("Actvities that can be done are : \n");

    for(int i=0;i<x;i++)
    {
        printf(" %d %d \n",a[0][ans[i]],a[1][ans[i]]);
    }

    return 0;
}




/*int res[n][n];

    for(int i=0;i<n;i++)
    {
        int count=0;
        int x=0;

        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                if((a[j][0]>=a[i][1]) || a[j][1]<=a[i][0])
                {
                    //if(a[j][1]>a[i][1])
                    //{
                        count++;
                        res[i][x]=j;
                        x++;
                    //}
                }
            }
        }

        while(x<n)
        {
            res[i][x]=0;
            x++;
        }

        res[i][n-1]=count;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf(" %d ",res[i][j]);
        }

        printf("\n");
    }*/