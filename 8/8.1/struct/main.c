#include <stdio.h>
#include <string.h>

//结构体，结构数组，结构对齐


struct student
{
    int num;//学号
    char name[20];//姓名
    char sex;//性别
    int age;//年龄
    float score;//成绩
};//结构体类型声明，注意最后要加分号

struct student_type1
{
    double score;//8
    int height;//4
    short age;//2
};

struct student_type2
{
    int height;//4
    short age;//2
    char sex;//1
};

int main(void)
{
    //定义结构体变量

    /*struct student s1;
    s1={1001,"xiaoli",'m',20,98.5};这样对结构体变量进行初始化是错误的*/

    //这样定义初始化是正确的
    struct student s1={1001,"xiaoli",'m',20,98.5};

    //还可以这样
    struct student s2;
    //采用“结构体变量名.成员名”的形式来访问结构体成员
    s2.num=1002;
    strcpy(s2.name,"wanggang");
    s2.sex='m';
    s2.age=18;
    s2.score=88.5;
    printf("%d %s %c %d %.1f\n",s2.num,s2.name,s2.sex,s2.age,s2.score);

    //定义多个结构体变量
    struct student s3,s4;
    //scanf("%d%s %c%d%f",&s3.num,s3.name,&s3.sex,&s3.age,&s3.score);
    //scanf("%d%s %c%d%f",&s4.num,s4.name,&s4.sex,&s4.age,&s4.score);
    //printf("%d %s %c %d %.1f\n",s3.num,s3.name,s3.sex,s3.age,s3.score);
    //printf("%d %s %c %d %.1f\n",s4.num,s4.name,s4.sex,s4.age,s4.score);

    //定义一个结构体数组变量
    struct student sarr[3];
    sarr[0]=s1;//将s1赋值给结构体数组sarr
    sarr[1]=s2;
    sarr[2]=s3;

    //遍历结构体数组
    for (int i=0;i<3;i++)
    {
        printf("%d %s %c %d %.1f\n",sarr[i].num,sarr[i].name,sarr[i].sex,sarr[i].age,sarr[i].score);
    }

    //结构体对齐三大法则
    /*
    对齐原则总结
    每个成员按其自身类型大小或编译器默认对齐值对齐（通常是 4 或 8）。

    结构体总大小必须是最大成员大小的整数倍。

    编译器可以用 #pragma pack(n) 修改对齐值
     */

    struct student_type1 size1;
    struct student_type2 size2;
    printf("size1=%zu\n",sizeof(size1));//16
    printf("size2=%zu\n",sizeof(size2));//8
    return 0;
}