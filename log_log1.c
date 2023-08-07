#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int x;
    scanf("%d",&x);
    
    float y= log(3);
    float z= log(x);
    
    float ans = z/y;
    printf("%.4f",ans);
    
    return 0;
}
