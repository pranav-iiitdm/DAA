#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n,z,x,y,k=0,count=0;
    
    scanf("%d",&n);
    
    scanf("%d",&z);
    
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    for(int i=0;i<n;i++)
    {
        x=a[i];
        
        for(int j=i+1;j<n;j++)
        {
            if(z==(x+a[j]))
            {
                count++;
                y=z-x;
                printf("%d\n%d",x,y);
                k++;
                break;
            }
        }
        
        if(k==1)
            break;
    }
    
    if(count==0)
        printf("*");
    
    return 0;
}
