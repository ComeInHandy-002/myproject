#include <stdio.h>

/*Description
输入一个学生的学号，姓名，性别，用结构体存储，通过scanf读取后，然后再通过printf打印输出

Input
学号，姓名，性别，例如输入 101 xiongda m

Output
输出和输入的内容一致，如果输入的是101 xiongda m，那么输出也是101 xiongda m
*/

typedef struct
{
    int num;
    char name[20];
    char sex;
}stu;

int main(void)
{
    stu s={0};
    scanf("%d%s %c",&s.num,s.name,&s.sex);
    printf("%d %s %c\n",s.num,s.name,s.sex);
    return 0;
}