#include <stdio.h>

/*你刚被MacroMuscle有限公司聘用。该公司准备进入欧洲市场，需要
一个把英寸单位转换为厘米单位（1 英寸=2.54 厘米）的程序。该程序要提
示用户输入英寸值。*/

void change(double a)
{
    double temp=2.54*a;
    printf("结果：%.2lf厘米\n",temp);
}

int main(void)
{
    double a=0;
    double b=0;
    printf("请输入英寸值：");
    scanf("%lf",&a);
    change(a);

    return 0;
}