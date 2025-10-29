#include <stdio.h>
#include <stdlib.h>
/*输入3 4 5 6 7 9999一串整数，9999代表结束，通过尾插法新建链表，
 查找第二个位置的值并输出，在2个位置插入99，输出为  3 99  4  5  6  7，
 删除第4个位置的值，打印输出为  3 99  4  6  7。

输入是3 4 5 6 7 9999
输出是
4  查找
3 99  4  5  6  7  插入
3 99  4  6  7  删除*/

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode* next;
}LNode,*LinkList;

//尾插法创建链表
void list_tail_insert(LinkList &L)
{
    ElemType data;
    LinkList r,s;//r创建尾指针,和新节点s
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    r=L;
    scanf("%d",&data);
    while (data!=9999)
    {
        s=(LinkList)malloc(sizeof(LNode));
        s->data=data;
        r->next=s;
        s->next=NULL;
        r=r->next;
        scanf("%d",&data);
    }
}

//打印链表
void print_list(LinkList L)
{
    L=L->next;
    while (L!=NULL)
    {
        printf("%3d",L->data);
        L=L->next;
    }
    printf("\n");
}

//查找第i个元素（按位置查找）
LinkList GetElem(LinkList L,int i)
{
    int j=0;
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

//删除第i个元素
bool list_delete(LinkList L,int i)
{
    LinkList search=GetElem(L,i-1);
    if (search==NULL||search->next==NULL)
    {
        return false;
    }
    LinkList p;//LinkList p=(LinkList)malloc(sizeof(LNode))为什么可以不怎么写
    p=search->next;
    search->next=p->next;
    free(p);
    return true;
}

//在第i个位置插入99
bool list_front_insert(LinkList L,int i,ElemType data)
{
    LinkList search=GetElem(L,i-1);
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
    LinkList L;
    LinkList search;
    bool ret;
    list_tail_insert(L);
    //print_list(L);
    search=GetElem(L,2);
    printf("%d\n",search->data);
    ret=list_front_insert(L,2,99);
    if (ret)
    {
        print_list(L);
    }
    else
    {
        printf("插入失败");
    }
    ret=list_delete(L,4);
    if (ret)
    {
        print_list(L);
    }
    else
    {
        printf("删除失败");
    }

    return 0;
}