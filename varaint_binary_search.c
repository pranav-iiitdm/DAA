#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int variant_binary_search(int n,int x,int a[n],int low,int high);

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    scanf("%d",&n);
    
    int x;
    scanf("%d",&x);
    
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    int ans=variant_binary_search(n,x,a,0,n-1);
    
    if(ans==-1)
    {
        printf("0\n");
    }
    
    else
    {
        printf("1\n");
    }
    
    return 0;
}

int variant_binary_search(int n,int x,int a[n],int low,int high)
{   
    if(high>=low)
    {
        int mid=(high+low)/3;
        
        if(x==a[mid])
        {
            return mid;
        }

        if(x>a[mid])
        {
            return variant_binary_search(n,x,a,mid+1,high);
        }

        if(x<a[mid])
        {
            return variant_binary_search(n,x,a,low,mid-1);
        }
    }
    
    return -1;
}
