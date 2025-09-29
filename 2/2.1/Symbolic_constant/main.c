#include <stdio.h>
//符号常量练习

#define PI 3+2      //定义符号常量,注意其后面没有分号（;）
int main()
{
    int i=PI*2;     //其运算方式为i=3+2*2
    printf("%d\n",i);       //结果不是等于10，是等于7，原因是符号常量PI是直接替换的效果
    return 0;
}
