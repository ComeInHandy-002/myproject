#include <stdio.h>
#include <stdlib.h>

//头插新建链表
typedef int ElemType;

typedef struct LNode
{
    ElemType data;//数据域
    struct LNode *next;//指针域
}LNode,*LinkList;

void list_head_insert(LinkList &L)//LNode* &L
{
    ElemType data;
    LNode *s;
    L=(LinkList)malloc(sizeof(LNode));//申请头节点空间，头指针指向头节点
    L->next=NULL;//初始化为空表
    scanf("%d",&data);
    /*s=(LinkList)malloc(sizeof(LNode));//申请首元节点s
    s->data=data;
    s->next=NULL;
    L->next=s;//头节点的指针域（next）指向首元节点（第一个节点）的数据域*/
    //不把第一个节点放放入循环，这样吧9999也存放入链表（因为是先存入在判断）
    /*while (data!=9999)
    {
        scanf("%d",&data);
        s=(LinkList)malloc(sizeof(LNode));
        s->data=data;
        s->next=L->next;//将原来指向第一个节点的指针赋值给新插入的节点的指针域（现在新插入的节点为第一个节点）
        L->next=s;
    }*/
    while (data!=9999)
    {
        s=(LinkList)malloc(sizeof(LNode));
        s->data=data;
        s->next=L->next;//将原来指向第一个节点的指针赋值给新插入的节点的指针域（现在新插入的节点为第一个节点）
        L->next=s;
        scanf("%d",&data);
    }
}

//打印链表
/*void print_list(LinkList L)
{
    LinkList p;
    p=L->next;
    while (p->next)
    {
        printf("%-3d",p->data);
        p->next=p->next+1;//因为所有指针节点都是malloc申请出来的所以这种写法不正确
    }
}*/
//我一开始写的是有问题的
void print_list(LinkList L)
{
    L=L->next;//这样写是为了跳过头节点，因为头节点中没有数据
    while(L!=NULL)
    {
        printf("%-3d",L->data);
        L=L->next;//将指针后移
    }
}
int main()
{
    LinkList L;//链表头指针，是结构体指针类型
    //为什么L可以不初始化使用？
    list_head_insert(L);//输入的数据为3 4 5 6 7 9999
    print_list(L);
    return 0;
}

/*| 情况             | 是否需要初始化      | 说明                       |
| -------------- | ------------ | ------------------------ |
| C++ 引用传参（`&L`） | ❌ 不需要        | 函数内部 malloc 会修改外部变量      |
| C 语言指针传参（`*L`） | ❌ 不需要，但必须传地址 | 函数内部用 `*L = malloc(...)` |
| 普通指针、不传引用      | ⚠️ 需要手动初始化   | 否则就是野指针，访问崩溃             |
*/