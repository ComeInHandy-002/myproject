#include <stdio.h>
#include<stdlib.h>
/*输入3 4 5 6 7 9999一串整数，9999代表结束，通过头插法新建链表，并输出，通过尾插法新建链表并输出。
注意输出要采用如下代码（因为OJ判题对空格敏感，因此需要用下面的打印代码来做）：
//打印链表中每个结点的值

Input
3 4 5 6 7 9999，第二行也是3 4 5 6 7 9999，数据需要输入两次

Output
如果输入是3 4 5 6 7 9999，那么输出是7 6 5 4 3，数之间空格隔开，尾插法的输出是3 4 5 6 7*/

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode* next;
} LNode, *LinkList;

//头插法新建链表
void list_head_insert(LinkList& L)
{
    ElemType data;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;

    scanf("%d", &data);
    while (data != 9999)
    {
        LinkList s = (LinkList)malloc(sizeof(LNode));
        s->data = data;
        s->next = L->next;
        L->next = s;
        scanf("%d", &data);
    }
}

//尾插法新建链表
void list_tail_insert(LinkList& L)
{
    ElemType data;
    LinkList s, r;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    r = L; //定义的尾指针
    scanf("%d", &data);
    /*while (data!=9999)
    {
        s=(LinkList)malloc(sizeof(LNode));
        s->data=data;
        L->next=s;
        L=L->next;
        scanf("%d",&data);
    }
    s->next=NULL;*/
    //大错特错，把头指针移动了
    while (data != 9999)
    {
        s = (LinkList)malloc(sizeof(LNode));
        s->data = data;
        s->next = NULL;
        r->next = s;
        r = r->next;
        scanf("%d", &data);
    }
}

//打印链表
void print_list(LinkList L)
{
    L = L->next; //跳过头节点
    while (L != NULL)
    {
        printf("%d", L->data);
        L = L->next;
        if (L != NULL)

        {
            printf(" ");
        }
    }
    printf("\n");
}

int main()
{
    LinkList L1, L2;
    list_head_insert(L1);
    list_tail_insert(L2);
    print_list(L1);
    print_list(L2);
    return 0;
}
