#include <stdio.h>

//通过子函数修改主函数的结构体变量是否可以

//结论是不可以

typedef struct
{
    int num;
    float score;
}stu,*pstu;

void change(stu a)
{
    a.num=1002;
    a.score=99.5;
}

void change1(stu &a)
{
    a.num=1002;
    a.score=99.5;
}

void change2(stu *a)
{
    a->num=1003;
    a->score=69.5;
}
int main()
{
    stu s={1001,88.5};
    printf("num=%d,score=%.1f\n",s.num,s.score);
    change(s);
    printf("alter change num=%d,score=%.1f\n",s.num,s.score);

    //要是想修改怎么办

    //方法1，用c++中的引用
    change1(s);
    printf("alter change1 num=%d,score=%.1f\n",s.num,s.score);

    //方法2
    pstu p=&s;
    change2(p);
    printf("alter change2 num=%d,score=%.1f\n",s.num,s.score);


    return 0;
}