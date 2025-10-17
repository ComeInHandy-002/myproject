#include <stdio.h>

/*3.编写一个程序把你的年龄转换成天数，并显示这两个值。这里不用考
虑闰年的问题。*/

int change_days(int a)
{
    int day=a*365;
    printf("%d天\n",day);
}

int main(void)
{
    int age=0;
    printf("请输入你的年龄：");
    scanf("%d",&age);
    change_days(age);

    return 0;
}