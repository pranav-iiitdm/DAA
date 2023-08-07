#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    float x;
    scanf("%f",&x);
    
    float y=0;
    
    for(int i=1;i<10000;i++)
    {
        y=y+(pow(((x-1)/x),i)/i);
    }
    
    float ans;
    
    ans=(y/2.30295)/0.47705;
    printf("%.4f",ans);
    return 0;
}
