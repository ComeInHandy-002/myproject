#include <stdio.h>

//短路运算 逻辑与和逻辑或

int main(void)
{
    int i=0;
    printf("请输入一个整数：");
    scanf("%d",&i);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    i&&printf("you can't see me!\n");//短路运算（好处是可以是我们的代码写的很短），意思是如果i为假则不输出printf的内容

   //不用短路运算
    printf("请再输入一个整数：");
    scanf("%d",&i);
    if (i)
    {
        printf("you can't see me!\n");
    }
    else
    {
        ;
    }

    return 0;
}
/*短路运算说明
1.逻辑与（&&）短路：
当左侧表达式为假时，右侧表达式不会执行
示例：i && printf(...) 中，如果 i 为 0，printf 不会被调用

2.逻辑或（||）短路：
当左侧表达式为真时，右侧表达式不会执行
示例：j || printf(...) 中，如果 j 为非 0，printf 不会被调用*/