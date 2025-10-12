#include <stdio.h>

//c++的引用的讲解
//在子函数内修改主函数的普通变量的值

void modify_num1(int &b)//形参中写&，要称为引用
{
    b=b+1;
}

void modify_num2(int *b)
{
    *b=*b+1;
}

//子函数中修改主函数的一级指针变量（很重要）
void modify_pointer1(int *p,int *q)
{
    p=q;
}
//这段代码错误的原因
/*
原因：参数传递是“值传递”
在 C 语言中，所有函数参数都是“值传递”。
也就是说：
当你把一个变量（包括指针）传给函数时，函数内部会复制一份副本。
所以：
int *p, *q;
modify_pointer(p, q);

函数内部得到的是：
一个叫 p 的副本（它和外面的 p 长得一样，但不是同一个东西）
一个叫 q 的副本
当你写：
p = q;

实际上只是让函数内部的 p 副本指向了 q 的副本的地址，
外面的那个真正的 p 完全没变。

图形理解：
假设外面有：
int a = 10;
int b = 20;
int *p = &a;
int *q = &b;

modify_pointer(p, q);

在内存中可以想象为👇
外部：
p → [地址A] → a=10
q → [地址B] → b=20

进入函数时：
函数内部：
p(副本) → [地址A]
q(副本) → [地址B]

执行 p = q; 后：
函数内部：
p(副本) → [地址B]
q(副本) → [地址B]


➡️ 外面的 p 仍然指向 a，不受影响。
 */
void modify_pointer2(int* &p,int* &q)//引用和变量名要紧挨着（int &*p这么写是错的）
{
    p=q;
}


int main()
{
    int a=10;
    modify_num1(a);
    printf("after modify_num1 a=%d\n",a);

    //等价于c中的
    int b=100;
    int*p=&b;
    modify_num2(p);
    printf("after modify_num2 b=%d\n",b);

    //子函数中修改主函数的一级指针变量（很重要）
    int *p1=NULL;//定义并声明了一个空指针
    int i=10;
    int *q=&i;
    //modify_pointer1(p1,q);
    //printf("%d\n",*p1);报错了

    //在不使用二级指针的情况下，可以用c++中的引用
    modify_pointer2(p1,q);
    printf("after modify_pointer2 *p1=%d\n",*p1);

    //c++中bool类型
    bool t=true;//1
    bool f=false;//0

    printf("t=%d,f=%d",t,f);
    return 0;
}