#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void search(int n,int a[n],int i,int j,int b[n])
{
    int l=0,m=0;
    
    for(int k=0;k<n;k++)
    {
        if(a[k]==b[i])
            l=k;
        else if(a[k]==b[j])
            m=k;
    }
    
    if(m<l)
        printf("%d\n%d",a[m],a[l]);
    else if(m>l)
        printf("%d\n%d",a[l],a[m]);
    else
        printf("*");
}

void find(int n,int a[n],int b[n],int z,int i,int j)
{
    if(b[i]+b[j]>z && j>0)
    {
        j--;
        find(n,a,b,z,i,j);
    }
    else if(b[i]+b[j]<z && i<n-1)
    {
        i++;
        find(n,a,b,z,i,j);
    }
    else
    {
        search(n,a,i,j,b);
        exit(0);
    }
}

int main() {

    int n,z,temp;
    
    scanf("%d",&n);
    
    scanf("%d",&z);
    
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    int b[n];
    for(int i=0;i<n;i++)
    {
        b[i]=a[i];
    }
    
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(b[i]>b[j])
            {
                temp=b[i];
                b[i]=b[j];
                b[j]=temp;
            }
        }
    }
    
    int i=0,j=n-1;
    
    find(n,a,b,z,i,j);
    
    return 0;
}

