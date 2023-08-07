#include<stdio.h>

int main()
{
    int w,n,temp,temp1,temp2;
    float profit=0,fract;

    printf("Enter weight of the bag \n");
    scanf("%d",&w);

    printf("Enter no.of objects \n");
    scanf("%d", &n);

    float a[3][n];

    for (int i = 0; i < 2; i++)
    {
        if (i == 0)
        {
            printf("Enter weights of %d objects \n", n);

            for (int j = 0; j < n; j++)
            {
                scanf("%f", &a[i][j]);
            }
        }

        if (i == 1)
        {
            printf("Enter corresponding profits \n");

            for (int j = 0; j < n; j++)
            {
                scanf("%f", &a[i][j]);
            }
        } 
    }

    for(int j=0;j<n;j++)
    {
        a[2][j]=a[1][j]/a[0][j];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (a[2][i] > a[2][j])
            {

                temp = a[2][j];
                a[2][j] = a[2][i];
                a[2][i] = temp;

                temp1 = a[1][j];
                a[1][j] = a[1][i];
                a[1][i] = temp1;

                temp2 = a[0][j];
                a[0][j] = a[0][i];
                a[0][i] = temp2;
            }
        }
    }

    for(int j=n-1;j>=0;j--)
    {
        if(w!=0)
        {
            if(w>=a[0][j])
            {
                profit+=a[1][j];
                w-=a[0][j];
            }

            else
            {
                fract=a[0][j]/w;
                profit+=(fract*a[1][j]);
            }
        }
    }

    /*for(int i=0;i<3;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf(" %.2f ",a[i][j]);
        }

        printf("\n");
    }*/

    printf("%.2f \n",profit);

    return 0;
}