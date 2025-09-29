#include <stdio.h>

//为什么要使用间接访问（我们可以通过直接访问去改变值）
/*在子函数中改变主函数中变量的值*/

//指针的传递

//指针的使用场景--传递与偏移

void change(int j)//j为形参
{
    j=5;//这只是改变了change函数j的栈空间的值（与i空间中的值无关）
}

void change1(int *m)//int *m=p(m=&i)
{
    //m存放的就是i的地址
    *m=5;//把&i中的值改变了(间接访问得到变量i)
}

int main(void) {
    int i=10;
    change(i);//c语言的函数调用是值传递，实参赋值给形参
    printf("i=%d\n",i);//i=10,函数的调用是值传递

    //在子函数中改变主函数中变量的值
    int *p=&i;
    //p -> &i
    change1(p);//传的是i的地址
    //change1(&i);和上面的写法是等价的
    printf("i=%d\n",i);


    return 0;
}
/*
int i = 10;
int *p = &i;   // p 保存 i 的地址
int *m = p;    // m 也保存 i 的地址

执行过程
p = &i → 指针 p 指向变量 i。
m = p → 把 p 的值（即 i 的地址）赋给 m。
所以此时 p 和 m 都指向 i
*/