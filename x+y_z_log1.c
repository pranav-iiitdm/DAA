#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int search(int x,int n,int a[n]);

int main() {

    int n,z,x,y,count=0,k=0;
    scanf("%d",&n);
    
    scanf("%d",&z);
    
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    for(int i=0;i<n;i++)
    {
        if(z>a[i])
        {
            x=z-a[i];
            
            for(int j=0;j<n;j++)
            {
                if(a[j]==x)
                {
                    y=a[i];
                    printf("%d\n%d",y,x);
                    count++;
                    k++;
                    break;
                }
            }
        }
        
        if(z<a[i])
        {
            x=z-a[i];
            
            for(int j=0;j<n;j++)
            {
                if(a[j]==x)
                {
                    y=a[i];
                    printf("%d\n%d",y,x);
                    count++;
                    k++;
                    break;
                }
            }
        }
        
        if(k==1)
        {
            break;
        }
        
    }
    
    if(count==0)
        printf("*");
    
    return 0;
}