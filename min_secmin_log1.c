#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    scanf("%d",&n);
    
    int a[n];
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    int c=0;
    int flag=-1;
    int k=-1;
    int min,min1;
    
    while(c<n)
    {
        if(c==0)
            min=a[c];
        
        if(c==1)
        {
            min1=a[c];
        }
        
        if(a[c]>min && a[c]<min1)
        {
            //min=min1;
            min1=a[c];
            flag=0;
        } 
        
        if(a[c]<min)
        {
            min1=min;
            min=a[c];
            k=0;
        }
        
        c++;
    }
    
    if(flag==-1 || min==min1)
    {
        printf("%d\n*",min);
    }
    
    if(k==0 && flag==0)
    printf("%d\n%d",min,min1);
    
    return 0;
}