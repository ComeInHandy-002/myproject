#include <stdio.h>

//1.逻辑运算符与逻辑表达式（值只有真和假，对应的值为1和0）
//！(非)  &&(与)  ||(或)——————逻辑与和逻辑或的优先级低于关系运算符，逻辑非的优先级高于关系运算符


//例子（计算一年是否为闰年）
/*int main()
{
    int year;
    scanf("%d",&year);
    /*fflush(stdin);//清除缓冲区#1#

    // 正确的缓冲区清理方式，不修改year的值
    int c;
    while ((c = getchar())!='\n' && c != EOF);

    if (year%4==0 && year%100!=0 || year%400==0)
    {
        printf("%d is a leap year",year);
    }
    else
    {
        printf("%d is not a leap year",year);
    }


    return 0;
}*/

int main()
{
    int i=0,j=1;
    while (scanf("%d",&i))
    {
        if (i%4==0 && i%100!=0 && i%400==0)
        {
            printf("i is leap year\n");
        }
        else
        {
            printf("i is not leap year\n");
        }
    }

    i=!!j;//从右到左
    printf("i的值=%d\n",i);
    return 0;


}