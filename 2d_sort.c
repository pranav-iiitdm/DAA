#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int r,c,temp;
    scanf("%d",&r);
    scanf("%d",&c);
    
    int a[r][c];
    int b[r*c];
    int k=0;
    
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
            b[k]=a[i][j];
            k++;
        }
    }
    
    for(int i=0;i<(r*c)-1;i++)
    {
        for(int j=i;j<r*c;j++)
        {
            if(b[i]>b[j])
            {
                temp=b[j];
                b[j]=b[i];
                b[i]=temp;
            }
        }
    }
    
    int l=0;
    
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            a[i][j]=b[l];
            l++;
        }
    }
    
    /*for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }*/
    
    printf("%d\n%d",a[0][0],a[r-1][c-1]);
    return 0;
}
