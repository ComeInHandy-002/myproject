#include <stdio.h>
#include <stdlib.h>

//单链表的删除操作

typedef int Element;

typedef struct LNode
{
    Element data;
    struct LNode* next; //指针域
} LNode, *LinkList;

//尾插法新建链表
void list_tail_insert(LinkList& L)
{
    L = (LinkList)malloc(sizeof(LNode)); //给头节点申请空间
    L->next = NULL;
    Element data;
    scanf("%d", &data);
    LinkList s; //用来指向申请的新节点
    LinkList r = L; //定义尾指针r，r始终指向链表尾部
    while (data != 9999)
    {
        s = (LinkList)malloc(sizeof(LNode)); //为新节点申请空间
        s->data = data;
        s->next = NULL;
        r->next = s; //新结点给尾结点的next指针
        r = s; //r要指向新的尾部,更新尾指针
        scanf("%d", &data);
    }
}

void print_list(LinkList L)
{
    L = L->next;
    while (L != NULL)
    {
        printf("%-3d", L->data);
        L = L->next;
    }
}

LinkList GetElem(LinkList L, int i)
{
    int j = 0;
    if (i < 0)
    {
        return NULL;
    }
    while (L && j < i)
    {
        L = L->next;
        j++;
    }
    return L;
}

bool delete_list(LinkList L, int i)//不要加引用，没有改变链表头指针
{
    LinkList search = GetElem(L, i - 1);
    if (search == NULL || search->next == NULL)
    {
        return false;
    }
    LinkList p;
    p = search->next;
    search->next = p->next;
    free(p);
    return true;
}

int main()
{
    LinkList L; //链表头指针，是结构体指针类型
    Element data;
    bool ret;
    list_tail_insert(L);
    print_list(L);
    ret = delete_list(L, 3);
    printf("\n");
    print_list(L);


    return 0;
}
