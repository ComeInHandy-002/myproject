#include <stdio.h>

//指针的偏移
//指针的加减我们称之为指针的偏移（加就是向后偏移，减就是向前偏移）

//指针与一维数组

#define N 5

int main(void) {

    int a[N]={1,2,3,4,5};
    int *p;
    int i;
    //数组名内存储了数组的起始地址
    p=a;//将a数组的首元地址赋值给指针p（p=&a[0]）

    //正序输出
    for(i=0;i<N;i++)
    {
        //指针偏移的长度是其基类型的长度，也就是偏移了sizeof(int)，1就是sizeof(int)
        printf("%3d",*(p+i));//*(p+1)没有用上i
    }

    printf("\n--------------------\n");

    //逆序输出
    p=&a[N-1];//指针p指向数组的最后一个元素
    for(i=0;i<N;i++)
    {
        printf("%3d",*(p-i));
    }

    return 0;
}

