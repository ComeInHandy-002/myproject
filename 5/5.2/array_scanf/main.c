#include <stdio.h>


//数组的传递

void printarray1(int a[])//a[]大括号内是不要写数字的写也没有用
{
    int i;
    for(i=0;i<5;i++)
    {
        printf("%d ",a[i]);
    }
}

void printarray2(int b[])//在 C 语言中，函数参数 int b[] 实际上被当作指针处理，也就是等价于 int *b。
{
    for(int len=0;len<sizeof(b)/sizeof(b[0]);len++)//所以这里sizeof(b)计算的是指针的大小(8)
    {
        printf("%d ",b[len]);
    }
}

//正确的写法
void printarray3(int d[],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d ",d[i]);
    }
    d[4]=1000;
}

/*在函数中，数组参数会退化为指针，所以无法用 sizeof 得到元素个数。
  获取数组长度的唯一可靠方法是 在调用函数时把长度传进去。*/

int main(void) {

    int a[5]={1,2,3,4,5};
    printarray1(a);
    printf("\n");

    int b[]={9,8,7,6,5,4,3,2,1};
    printarray2(b);//在函数中，数组参数会退化为指针，所以无法用 sizeof 得到元素个数
    printf("\n");

    int c[]={9,8,7,6,5,4,3,2,1};
    printarray3(c,sizeof(c)/sizeof(c[0]));//获取数组长度的唯一可靠方法是 在调用函数时把长度传进去


    //在子函数中可以修改数组值
    printf("\nc[4]=%d\n",c[4]);//c[4]发生了变化




    return 0;
}

/*总结：
情况                      sizeof返回值	                    结果
main() 中数组	         数组总大小（字节）	                    正确
函数参数数组	             指针大小（字节）	                    错误
 */