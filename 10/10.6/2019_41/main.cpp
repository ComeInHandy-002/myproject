//#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*设线性表L=(a1,a2,a3,...,an-2,an-1,an)采用带头结点的单链表保存，链表中的结点定义如下：
typedef struct node {
    int data;
    struct node *next;
} NODE;
请设计一个空间复杂度为O(1)
且时间上尽可能高效的算法，重新排列L中的各结点，得到线性表L'=(a1,an,a2,an-1,a3,an-2,...)。
要求：
⑴ 给出算法的基本设计思想。
⑵ 根据设计思想，采用C或C++语言描述算法，关键之处给出注释。
⑶ 说明你所设计算法的时间复杂度。*/

//空间复杂度O(1)----O(1) 表示：算法所需的额外空间是常数级的，不会随着输入数据规模 n 的变化而变化。
//也就是不去malloc开辟空间

//typedef int ElemType;

typedef struct node
{
    int data;
    struct node *next;
}NODE;
//尾插法新建链表
void list_tail_insert(NODE* &L)
{
    L=(NODE*)malloc(sizeof(NODE));
    L->next=NULL;
    NODE* s,*r=L;
    int data;
    scanf("%d",&data);
    while (data!=9999)
    {
        s=(NODE*)malloc(sizeof(NODE));
        s->data=data;
        r->next=s;
        s->next=NULL;
        r=r->next;
        scanf("%d",&data);
    }
}
//打印NODE链表
void print_list(NODE* L)
{
    L=L->next;
    while (L!=NULL)
    {
        printf("%-3d",L->data);
        L=L->next;
    }
}
//找中间元素i
NODE* find_middie(NODE *L)
{
    NODE*p,*q;
    p=L->next;
    q=L->next;
    while (p!=NULL&&p->next!=NULL)
    {
        p=p->next->next;
        if (p==NULL)
        {
            break;
        }
        q=q->next;
    }
    NODE*L2;
    L2=(NODE*)malloc(sizeof(NODE));
    L2->next=q->next;
    q->next=NULL;
    return L2;
}
//原地逆置
void reverse(NODE* L)
{
    NODE*r,*s,*t;
    if (L->next==NULL || L->next->next==NULL)//保证了至少有二个元素
    {
        return;
    }
    r=L->next;
    s=r->next;
    r->next=NULL;
    while (s!=NULL)
    {
        t=s->next;
        s->next=r;
        r=s;
        s=t;
    }
    L->next=r;

}
//连接L和L2
void connection(NODE *L, NODE *L2)
{
    if (L->next == NULL || L2->next == NULL)
    {
        return;
    }

    NODE *pre = L->next;   // 第一条链表的第一个节点
    NODE *p = pre->next;   // L的第二个节点
    NODE *q = L2->next;    // 第二条链的第一个节点

    while (p != NULL && q != NULL)
    {
        pre->next = q;     // 接入 L2 当前节点
        q = q->next;       // q 前进
        pre = pre->next;   // pre 移动到刚插入的节点

        pre->next = p;     // 再接入 L 的下一个节点
        p = p->next;       // p 前进
        pre = pre->next;   // pre 移动到刚插入的节点
    }

    if (p != NULL)
        pre->next = p;     // L 还没走完
    else if (q != NULL)
        pre->next = q;     // L2 还没走完
    else
        pre->next = NULL;  // 都走完了，封尾保险
}

int main()
{
    NODE* L,*L2;
    NODE* search;
    list_tail_insert(L);
    print_list(L);
    L2=find_middie(L);
    printf("\n");
    print_list(L);
    printf("\n");
    print_list(L2);
    reverse(L2);
    printf("\n");
    print_list(L2);
    connection(L,L2);
    printf("\n");
    print_list(L);

    return 0;
}


/*
       过本题学到的关键知识点与技巧
知识点	                      内容
✅ 链表创建	                  尾插法 vs 头插法，掌握如何动态建立单链表
✅ 快慢指针技巧	              一次遍历找到中点，省时省空间
✅ 链表逆置	                  经典三指针反转法（r, s, t）
✅ 链表分割与拼接	              灵活控制 next 指针，实现断链与重组
✅ 空间复杂度 O(1)	          不开辟新链表，全程原地操作
✅ 算法调试技巧	              多用 print_list() 分段打印验证正确性
✅ 边界条件处理	              空链表、单节点链表、奇偶节点数不同的情况都能正确运行

*/