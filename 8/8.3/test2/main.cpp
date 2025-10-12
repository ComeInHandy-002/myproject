#include <stdio.h>
#include <stdlib.h>

//结构体指针的练习

typedef struct
{
    int num;
    float score;
}stu,*pstu;

void change(pstu a)
{
    a->num=2002;
    a->score=77.5;
}
int main()
{
    pstu p=(pstu)malloc(sizeof(stu));

    p->num=1001;
    p->score=66.5;

    printf("num=%d,score=%.1f\n",p->num,p->score);

    change(p);
    printf("after changer num=%d,score=%.1f\n",p->num,p->score);

    free(p);



    return 0;
}