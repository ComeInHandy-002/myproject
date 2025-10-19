#include <stdio.h>

/*初始化顺序表（顺序表中元素为整型），里边的元素是1,2,3，
然后通过scanf读取一个元素（假如插入的是6），插入到第2个位置，打印输出顺序表，每个元素占3个空格，
格式为1  6  2  3，然后scanf读取一个整型数，
是删除的位置（假如输入为1）然后输出顺序表  6  2  3，假如输入的位置不合法，
输出false字符串。提醒，Language一定要选为C++。

Input
第一次输入插入的元素值，第二次输入删除的位置

Output
假如插入的元素为6，那么输出为
1  6  2  3
假如删除的位置为1，那么输出为
6  2  3

注意两次输出是两行，1  6  2  3输出完毕后，注意输出换行符，也就是\n*/

#define MAXSIZE 50
typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}SqList;

//顺序表的插入
bool ListInsert(SqList &L,ElemType data,int i)
{
    //判断i的位置是否合法
    if (i<1||i>L.length)
    {
        return false;
    }
    //判断L是否满了
    if (L.length==MAXSIZE)
    {
        return false;
    }
    for (int j=L.length;j>=i;j--)
    {
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=data;
    L.length++;
    return true;
}
//打印顺序表1
void PrintList(SqList L)
{
    for (int i=0;i<L.length;i++)
    {
        printf("%-3d",L.data[i]);
    }
}
void PrintList1(SqList L)
{
    for (int i=0;i<L.length;i++)
    {
        printf("%3d",L.data[i]);
    }
}

//顺序表的删除
bool ListDelete(SqList &L,int i)
{
    //判断删除位置是否合理
    if (i<1||i>L.length)
    {
        return false;
    }
    //判断L是否满了
    if (L.length==MAXSIZE)
    {
        return false;
    }
    for (int j=i;j<L.length;j++)
    {
        L.data[j-1]=L.data[j];
    }
    L.length--;
    return true;
}
int main()
{
    SqList L;
    bool ret;
    ElemType a=0;
    int i=0;
    L.data[0]=1;
    L.data[1]=2;
    L.data[2]=3;
    L.length=3;
    scanf("%d",&a);
    scanf("%d",&i);
    ret=ListInsert(L,a,2);
    if (ret)
    {
        PrintList1(L);
        printf("\n");
    }
    ret=ListDelete(L,i);
    if (ret)
    {
        PrintList1(L);
    }
    else
    {
        printf("false\n");
    }


    return 0;
}