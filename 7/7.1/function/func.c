//
// Created by 19505 on 2025/10/2.
//
#include "func.h"

//print_star的定义
int print_star(int i)
{
    printf("*********************\n");
    printf("print_star %d\n",i);
    return i+3;
}

//这里是函数的定义,可以调用print_star,就是嵌套调用
void print_message()
{
    printf("how do you do\n");
    print_star(6);
}

