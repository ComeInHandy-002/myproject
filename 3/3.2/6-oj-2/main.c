#include <stdio.h>

int main(void) {
   int i;
   char j;
   float k,sum;
    //printf("请输入一个整型数，字符，浮点数：");
    scanf("%d %c%f",&i,&j,&k);
    sum=i+j+k;
    printf("%.2f",sum);
    return 0;
}
