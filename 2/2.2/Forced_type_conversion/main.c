#include <stdio.h>

//强制类型转换

int main(void)
{
    int i=5;
    float f=i/2;//这里做的是整型运算，因为左右操作数都是整型
    float h=5;
    float g=h/2;//除法运算的运算是按照被除数来的（左操作数）
    printf("%f\n%f\n",f,g);
    float k=(float)i/2;//(float)的意思是强制类型转换，其变量的类型是没有变化的，在c语言中任何变量在定义的一瞬间它的类型就确认了不可以在执行过程中改变
    printf("%f\n",k);





    return 0;
}