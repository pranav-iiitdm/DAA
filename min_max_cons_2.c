#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n;
    scanf("%d",&n);
    
    int a[n],b[n],k,j,temp,x,y;
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
        
        if(i>0)
        {
            j=i;
            k=(i-1)/2;
            x=i;
            y=(i-1)/2;
            
            while(a[j]<a[k])
            {
                temp=a[j];
                a[j]=a[k];
                a[k]=temp;
                
                j=(j-1)/2;
                k=(j-1)/2;
            }
            
            while(b[x]>b[y])
            {
                temp=b[x];
                b[x]=b[y];
                b[y]=temp;
                
                x=(x-1)/2;
                y=(x-1)/2;
            }
        }
    }
    
    printf("%d\n%d",a[0],b[0]);
    
    return 0;
}
