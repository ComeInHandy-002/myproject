#include <stdio.h>

//scanf函数的原理
//多种数据类型混合输入

int main(void)
{
    //scanf函数的原理
    //scanf函数读取键盘输入。键盘输入又被称为标准输入。当scanf函数读取标准输入时，如果还没有输入任何内容，那么scanf函数会被卡住（专业用语为阻塞）

    int i;
    char c;
    float f;
    scanf("%d",&i);//scanf用来读取标准输入，scanf把标准输入的内容，需要放到某一个变量空间里，因此变量必须取地址
    printf("i=%d\n",i);
    /*fflush(stdin);//清空标准输入缓冲区
    scanf("%c",&c);
    printf("c=%c\n",c);//c=(因为没有清空缓冲区)*/

    scanf("%f",&f);//为什么这里不用清理缓冲区，因为scanf函数在读取整型数，浮点数，字符串时，会忽略‘\n’（回车符），空格等字符
    printf("f=%f\n",f);

    //多种数据类型混合输入
    int a,ret;
    float b;
    char ch;
    ret=scanf("%d %c%f",&a,&ch,&b);//ret表示scanf匹配成功的个数,要在%c之前加一个空格，这样会被格式空格搞掉
    //ret=scanf("%d%c%f",&a,&ch,&b);输入100 a 98.2   ret匹配成功两个a和ch分别为a=100，ch= （空格）
    printf("a=%d,b=%5.2f,ch=%c\n",a,b,ch);


    return 0;
}