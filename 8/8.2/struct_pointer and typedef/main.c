#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//结构体指针的使用和typedef的使用

struct student
{
    int num;
    char name[20];
    char sex;
};

//typedef的使用，起别名
typedef  struct student1
{
    int num;
    char name[20];
    char sex;
}stu,*pstu;//stu等价于struct student1，pstu等价于struct student1*


int main(void)
{
    struct student s={1001,"lilei",'m'};

    struct student sarr[3]=
    {
        {1002,"zhangsan",'m'},
        {1003,"lili",'w'},
        {1004,"wangle",'m'}
    };

    //定义一个结构体指针（声明）
    struct student *p;//一个结构体变量的指针就是该变量占据内存段的起始地址
    p=&s;//初始化结构体指针

    //结构体指针访问结构体成员
    //*p就等价于s
    printf("num=%d,name=%s,sex=%c\n",p->num,p->name,p->sex);//p->num就等价与(*p).num

    p=sarr;//等价于p=&sarr[0]
    printf("num=%d,name=%s,sex=%c\n",p->num,p->name,p->sex);
    p=p+1;//结构体指针偏移
    printf("num=%d,name=%s,sex=%c\n",p->num,p->name,p->sex);

    //下面给结构体指针p申请空间，并对其成员赋值，再访问
    p=malloc(sizeof(struct student));
    p->num=100;
    p->sex='m';
    strcpy(p->name,"zhuge");
    printf("num=%d,name=%s,sex=%c\n",p->num,p->name,p->sex);
    free(p);

    //使用了tpyedef
    stu s1={0};//声明一个结构体变量并初始化
    //定义了两个结构体指针
    stu *p1=&s1;
    pstu p2=&s1;

    return 0;
}