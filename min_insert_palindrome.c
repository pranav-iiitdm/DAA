#include<stdio.h>

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

void dp(int n,int m,char * s1,char * s2)
{
    int dp[n+1][m+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }

            else if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }

            else
            {
                dp[i][j]=maximum(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    //printf(" %d \n",dp[n][m]);

    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=m;j++)
    //     {
    //         printf(" %d ",dp[i][j]);
    //     }

    //     printf("\n");
    // }

    int x=dp[n][m];

    printf("Minimum no.of insertions to be done are : %d \n",n-x);
}

int main()
{
    int n;
    
    printf("Enter the length of string \n");
    scanf("%d",&n);

    char s1[n+1];
    char s2[n+1];

    s2[n]='\0';

    printf("Enter the string \n");
    scanf("%s",s1);

    for(int i=0;i<n;i++)
    {
        s2[n-i-1]=s1[i];
    }

    dp(n,n,s1,s2);

    return 0;
}