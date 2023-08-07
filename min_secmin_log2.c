#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    scanf("%d",&n);
    
    int a[n],temp;
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    for(int i=0;i<n-1;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
    }
    
    
    if(n==1)
    {
        printf("%d\n*",a[0]);
    }
    
    else if(a[0]==a[1])
    {
        printf("%d\n*",a[0]);
    }
    
    else
    {
        printf("%d\n%d",a[0],a[1]);
    }
    
    return 0;
}