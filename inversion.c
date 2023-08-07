#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,count=0;
    scanf("%d",&n);
    
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(2*a[i]<=a[j])
            {
                /*printf("i = %d\n",a[i]);
                printf("j = %d\n",a[j]);*/
                count++;
            }
        }
    }
    
    printf("%d\n",count);
    return 0;
}
