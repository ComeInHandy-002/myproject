#include <stdio.h>

//数组的学习


int main(void) {
    //在 C语言 里，数组的定义 不一定要初始化，分情况：

    int a[5];   // 定义了，但没有初始化，会存入垃圾数
    for (int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    //全局数组 / 静态数组
    /*
        #include <stdio.h>
        int a[5];  // 全局数组
        int main()
        {
            static int b[5]; // 静态数组
            for (int i = 0; i < 5; i++)
              {
                 printf("%d %d\n", a[i], b[i]);
              }
                 return 0;
        }
        👉 输出的全是 0，因为 全局变量和静态变量在定义时会自动初始化为 0。
*/

    //数组初始化的方法总结
    /*完全初始换*/
    int a1[5]={1,2,3,4,5};
    //printf("%s",a1[]);   %s 用来输出 字符串（char 数组，以 \0 结尾）。
    for(int i=0;i<5;i++)
    {
        printf("%d ",a1[i]);
    }

    printf("\n");

    /*部分初始换*/
    int a2[5]={1,2,3};// 等价于 {1, 2, 0, 0, 0}剩下的补 0
    for (int i = 0; i < 5; ++i) {
        printf("%d ",a2[i]);
    }

    printf("\n");

    /*不写长度(这种方法不推荐)*/
    int a3[]={1,2,3};//不写长度，自动推算，长度自动 = 3
    for(int len=0;len<sizeof(a3)/sizeof(a3[0]);len++)
    {
        printf("%d ",a3[len]);
    }


    return 0;
}
