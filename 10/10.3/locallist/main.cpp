#include <stdio.h>
#include <stdlib.h>

//按位置查找及按值查找
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode* next;
}LNode,*LinkList;

void list_tail_insert(LinkList &L)
{
    ElemType data;
    //创建头结点
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    scanf("%d",&data);
    //新结点和尾结点
    LinkList s,r=L;
    while (data!=9999)
    {
        s=(LinkList)malloc(sizeof(LNode));
        s->data=data;
        r->next=s;
        s->next=NULL;
        r=s;
        scanf("%d",&data);
    }
}
void print_list(LinkList L)
{
    L=L->next;
    while (L!=NULL)
    {
        printf("%-3d",L->data);
        L=L->next;
    }
}

//按位置查找
LinkList GetElem(LinkList L,int i)
{
    int a=0;
    if (i<0)
    {
        return NULL;
    }
    while (L&&a<i)
    {
        L=L->next;
        a++;
    }
    return L;
}

//按值查找
LinkList LocateElem(LinkList L,ElemType data)
{
    L=L->next;
    while (L!=NULL)//可以while(L)
    {
        if (L->data==data)
        {
            return L;
        }
        L=L->next;
    }
    return NULL;
}
int LocateElem1(LinkList L,ElemType data)
{
    L=L->next;
    int i=1;
    while (L!=NULL)//可以while(L)
    {
        if (L->data==data)
        {
            return i;
        }
        L=L->next;
        i++;
    }
    return -1;
}
int main()
{
    LinkList L;
    LinkList search;//用来存储拿到的某一结点
    int i;
    list_tail_insert(L);//输入1 2 3 4 5 6 7 9999
    print_list(L);
    printf("\n");
    //按位置查找
    search=GetElem(L,1);
    if (search!=NULL)
    {
        printf("查找成功\n");
        printf("%d\n",search->data);
    }
    search=LocateElem(L,6);
    i=LocateElem1(L,6);
    if (search!=NULL)
    {
        printf("查找成功\n");
        printf("%-3d\n",search->data);
        printf("%d\n",i);
    }
    else
    {
        printf("没有找到\n");
    }
    return 0;
}