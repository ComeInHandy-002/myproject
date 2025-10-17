#include <stdio.h>

//通过试验（即编写带有此类问题的程序）观察系统如何处理整数上溢、浮点数上溢和浮点数下溢的情况。


#include <limits.h>  // 包含整型最大最小值
#include <float.h>   // 包含浮点数范围

int main(void)
{
    printf("========== 整型上溢 ==========\n");
    int a = INT_MAX;
    printf("INT_MAX = %d\n", a);
    a = a + 1;
    printf("INT_MAX + 1 = %d （发生上溢）\n", a);

    printf("\n========== 整型下溢 ==========\n");
    int b = INT_MIN;
    printf("INT_MIN = %d\n", b);
    b = b - 1;
    printf("INT_MIN - 1 = %d （发生下溢）\n", b);

    printf("\n========== 浮点数上溢 ==========\n");
    float f = FLT_MAX;
    printf("FLT_MAX = %e\n", f);
    f = f * 10.0f;  // 让它上溢
    printf("FLT_MAX * 10 = %e （上溢后）\n", f);

    printf("\n========== 浮点数下溢 ==========\n");
    float f2 = FLT_MIN;  // 最小正数（不是最负）
    printf("FLT_MIN = %e\n", f2);
    f2 = f2 / 1e10f;     // 让它下溢
    printf("FLT_MIN / 1e10 = %e （下溢后）\n", f2);

    return 0;
}

