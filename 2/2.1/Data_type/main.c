#include <stdio.h>

//C语言的数据类型分为：

//基本类型 ———— 整型，实型（浮点型），字符型
//构造类型 ———— 数组，结构体（struct）
//指针类型*
//空类型（（void）

//c语言中有常量和变量之分，在常量中比变量多一个字符串型常量


/*
#include <stdio.h>
#include <std bool.h> // 布尔类型支持

int main() {
    // 基本类型
    char c = 'A';
    int num = 100;
    float f = 3.14f;
    double d = 3.14159;
    bool is_true = true;

    // 派生类型
    int arr[5] = {1, 2, 3, 4, 5}; // 数组
    int *ptr = &num;              // 指针

    // 结构体
    struct Point {
        int x;
        int y;
    };
    struct Point p = {10, 20};

    // 枚举
    enum Color { RED, GREEN, BLUE };
    enum Color my_color = GREEN;

    return 0;
}
*/



int main()
{
    int i;  //i就是一个整型变量，变量i是4个字节
    printf("i size=%d\n",sizeof(i));    //printf是打印函数又来输出的，sizeof（）可以用来计算某个变量或常量的空间大小


    float f=3e-3;   //f为一个浮点型变量变量，f是4个字节，字母e（或E）之前必须有数字，且e后面的数字必须为整数，其中e表示10的幂次
    printf("f=%f\nf size=%d\n",f,sizeof(f));


    //大写变小写--学习字符变量
    char c; //c就是一个字符变量，变量c是一个字节
    scanf("%c",&c);
    // 清除输入缓冲区
    while (getchar() != '\n');
    if (c>=65 && c<=90)   //A的ASCII为65，a的ASCII为97 ————  if (c>='A' && c<='Z')
    {
        c+=32;
        printf("小写:%c\n",c);    //%c ———— 是以字符形式输出  %d ———— 是以数值形式输出
    }
    else
    {
         printf("输入错误\n");
    }


    //大小写转换
    char c1;
    scanf("%c",&c1);
    // 清除输入缓冲区
    while (getchar() != '\n');
    if (c1>=65 && c1<=90 || c1>=97 && c1<=122)
    {
        if (c1>=65 && c1<=90)
        {
            c1+=32;
            printf("小写：%c\n",c1);
        }
        else
        {
            c1-=32;
            printf("大写：%c\n",c1);
        }
    }
    else
    {
        printf("非法输入\n");
    }


    //字符串常量
    //字符串型常量是由一对双引号（""）括起来的字符序列
    //'a'是字符型常量，"a"是字符串型常量
    //c语言规定在每一个字符串常量的结尾加一个字符串结束标志（'\0'）
    //如c="CHINA"它占用的内存单元不是5个字节，而是6个字节其中有一个'\0'



    //转义字符
    // \n ———— 换行     \\ ———— 反斜杠       \b ———— 退格
    return 0;
}