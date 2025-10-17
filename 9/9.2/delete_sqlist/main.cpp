#include <stdio.h>

//顺序表的删除及查询
#define MaxSize 50
typedef int ElemType;

typedef struct
{
    ElemType data[MaxSize];
    ElemType length;
} SqList;

//顺序表的插入
bool ListInsert(SqList& L, int i, ElemType data)
{
    //判断i的位置是否合法
    if (i < 1 || i > L.length + 1)
    {
        return false;
    }
    //判断顺序表是否满了
    if (L.length == MaxSize)
    {
        return false;
    }
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = data;
    L.length++;
    return true;
}

//打印顺序表
void PrintList(SqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf("%-3d", L.data[i]);
    }
    printf("\n");
}

//删除顺序表的元素
bool ListDelete(SqList& L, int i, ElemType& data)
{
    //判断i的位置是否合法
    if (i < 1 || i > L.length)
    {
        return false;
    }
    //判断是否为空表
    if (!L.length)
    {
        return false;
    }
    data = L.data[i - 1]; //保存要删除的值
    for (int j = i; j <= L.length - 1; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

//查找顺序表的元素(找的了就返回某个元素的位置，没找到就返回0)
//不考虑有两个相同的元素，有的话也只返回第一个的位置
int LocalList(SqList L, ElemType data)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == data)
        {
            return i + 1; //因为i是数组的下标
        }
    }
    return 0; //循环结束没找的
}

int main()
{
    SqList L;
    bool ret;
    ElemType del; //被删除的元素
    int pos; //查找成功返回元素位置
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.length = 3;
    ret = ListInsert(L, 2, 60);
    if (ret)
    {
        printf("插入成功\n");
        PrintList(L);
    }
    else
    {
        printf("插入失败\n");
    }
    ret = ListDelete(L, 1, del);
    if (ret)
    {
        printf("删除成功\n");
        printf("删除元素值del=%d\n", del);
        PrintList(L);
    }
    else
    {
        printf("删除失败\n");
    }

    pos = LocalList(L, 3);
    if (pos)
    {
        printf("查找成功\n");
        printf("元素位置为%d\n", pos);
    }
    else
    {
        printf("查找失败\n");
    }

    return 0;
}
