#include <stdio.h>
#include <stdlib.h>
//往第i个位置插入元素

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode* next;//指针域
}LNode,*LinkList;
//尾插法新建链表
void list_tail_insert(LinkList &L)
{
    L=(LinkList)malloc(sizeof(LNode));//给头节点申请空间
    L->next=NULL;
    ElemType data;
    scanf("%d",&data);
    LinkList s;//用来指向申请的新节点
    LinkList r=L;//定义尾指针r，r始终指向链表尾部
    while (data!=9999)
    {
        s=(LinkList)malloc(sizeof(LNode));//为新节点申请空间
        s->data=data;
        s->next=NULL;
        r->next=s;//新结点给尾结点的next指针
        r=s;//r要指向新的尾部,更新尾指针
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

LinkList GetElem(LinkList L,int i)
{
    int j=0;
    /*if (i==0)
    {
        return L;
    }*/
    if (i<0)
    {
        return NULL;
    }
    while (L&&j<i)
    {
        L=L->next;
        j++;
    }
    return L;
}

//往第i个位置插入元素
bool ListFrontInsert(LinkList L,int i,ElemType data)
{
    LinkList search;
    search=GetElem(L,i-1);
    if (search==NULL)
    {
        return false;
    }
    LinkList s=(LinkList)malloc(sizeof(LNode));
    s->data=data;
    s->next=search->next;
    search->next=s;
    return true;

}
int main()
{
    LinkList L;//链表头指针，是结构体指针类型
    int i;
    bool ret;
    list_tail_insert(L);
    print_list(L);
    printf("请输入要插入的位置：");
    scanf("%d",&i);
    ret=ListFrontInsert(L,i,99);
    if (ret)
    {
        printf("插入成功\n");
        print_list(L);
    }
    else
    {
        printf("插入失败\n");
        print_list(L);
    }

    return 0;
}