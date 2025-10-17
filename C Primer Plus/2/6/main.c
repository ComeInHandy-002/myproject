#include <stdio.h>

/*编写一个程序，创建一个整型变量toes，并将toes设置为10。程序中还
要计算toes的两倍和toes的平方。该程序应打印3个值，并分别描述以示区
分。*/

void squared(int a)
{
    int sum=a*a;
    printf("toes平方=%d\n",sum);
}
void operation(int a)
{
    int sum=2*a;
    printf("toes*2=%d\n",sum);
}

int main(void)
{
    int toes=10;
    printf("toes=%d\n",toes);
    operation(toes);
    squared(toes);
    return 0;
}