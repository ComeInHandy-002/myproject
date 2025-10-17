#include <stdio.h>

//顺序表的初始化及插入操作

#define MaxSize 50

typedef int ElemType; //为什么要这个操作？
//方便修改类型（让顺序表存储其他类型元素时，可以快速完成代码修改）

typedef struct
{
    ElemType data[MaxSize]; //用数组来实现顺序表
    int length; //顺序表的长度
} SqList;


//定义一个顺序表的插入函数
bool ListInsert(SqList& L, ElemType i, ElemType data) //布尔类型
{
    //判断i是否合法,i是插入的位置
    if (i < 1 || i > L.length + 1)
    {
        return false;
    }
    //如果存储空间满了，不能插入
    if (L.length==MaxSize)
    {
        return false;
    }
    //把后面的元素以此向后移
    for (int j = L.length - 1; j >= i-1; j--)
    {
        L.data[j + 1] = L.data[j];
        //L.data[i - 1] = data;应该放在循环体的外面（被多次执行了）
    }
    L.data[i - 1] = data;
    L.length++;//插入成功（长度加1）
    return true;
}

//另一种更符合自然思维（插入第 i 个位置前移）
/*for (int j=L.length;j>=i;j--)
{
    L.data[j]=L.data[j-1]
}*/


//打印顺序表
void PrintList(SqList L)
{
    for (int i=0;i<L.length;i++)
    {
        printf("%-3d",L.data[i]);//为了打印好看
    }
    printf("\n");
}

int main()
{
    SqList L; //定义一个顺序表，变量L
    bool ret;//ret用来装函数的返回值
    L.data[0] = 1; //放置元素
    L.data[1] = 2;
    L.data[2] = 3;
    L.length = 3; //设置长度
    ret=ListInsert(L, 2, 60);
    if (ret)
    {
        printf("插入成功\n");
        PrintList(L);//打印顺序表
    }else
    {
        printf("插入失败\n");
        PrintList(L);//打印顺序表
    }

    return 0;
}
