#include <stdio.h>

/*1个水分子的质量约为3.0×10−23克。1夸脱水大约是950克。编写一个
程序，提示用户输入水的夸脱数，并显示水分子的数量*/

int main(void) {
    printf("请输入水的夸脱数：");
    float num=0;
    double n=0;
    scanf("%f",&num);
    n=num*950/3.0e-23;
    printf("%lf\n",n);
    return 0;
}
