#include "func.h"//<>和""的区别一个是标准库一个是自定义库

//函数的声明与定义

//函数的分类与调用

int main(void)
{
    int a=10;
    a=print_star(a);//a=13
    print_message();//调用print_message()
    print_star(5);
    return 0;
}

/*
一、函数的分类
从不同角度，可以分成几类：
1. 按照函数的来源
  1.库函数
  C 语言标准库提供的，比如 printf、scanf、strlen、strcpy、malloc 等。
  使用时要 #include <头文件>。
  2.用户自定义函数
  程序员自己写的，用于代码复用和结构化。
  比如 int add(int a,int b){ return a+b; }。

2. 按照返回值
有返回值的函数
定义时写返回类型，比如 int add(int a,int b);。
return 后必须有值。

3.无返回值的函数
用 void 声明。
比如 void printHello(){ printf("Hello\n"); }。

 */
