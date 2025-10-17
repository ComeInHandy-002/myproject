#include <stdio.h>

//编写一个程序，要求提示输入一个ASCII码值（如，66），然后打印输入的字符。

int main(void)
{
    int num=0;
    char a=0;
    printf("请输入一个ASCII码值：");
    scanf("%d",&num);
    a=num;
    printf("%c\n",a);
    return 0;
}