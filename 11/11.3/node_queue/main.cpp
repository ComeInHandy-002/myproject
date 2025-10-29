#include <stdio.h>
#include <stdlib.h>
//通过链表来实现队列
//1.初始化队列2.入队3.出队

//#define MaxSize 5
typedef int ElemType;

//链表
typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *next;
}LinkNode;

typedef struct
{
    LinkNode *front,*rear;//队头，队尾（链表头，链表尾）
}LinkSqueue;
//初始化队列，使用带头结点的链表来实现
void init_squeue(LinkSqueue &Q)
{
    //Q.front->data=Q.rear->data=0;
    Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));//头和尾指向同一个结点
    Q.front->next=NULL;//头指针的next指针为NULL
}

//判断队列是否为空
bool is_empty(LinkSqueue Q)
{
    if (Q.rear==Q.front)
    {
        return true;
    }else
    {
        return false;
    }
}

//入队
void EnQueue(LinkSqueue &Q,ElemType data)//因为是链表写的队列，所以不存在队列满的问题
{
    LinkNode *pnew=(LinkNode*)malloc(sizeof(LinkNode));
    pnew->data=data;
    pnew->next=NULL;
    Q.rear->next=pnew;//尾指针的next指向pnew
    Q.rear=pnew;//rear要指向新的尾部
}

//出队
bool de_queue(LinkSqueue &Q,ElemType &data)
{
    if (is_empty(Q))
    {
        return false;
    }
    LinkNode *q=Q.front->next;//拿到第一个结点,存入q
    data=q->data;
    Q.front->next=q->next;//让第一个结点断链
    if (Q.rear==q)//链表只剩一个结点时，被删除后，要改变rear
    {
        Q.rear=Q.front;
    }
    free(q);
    return true;
}
int main()
{
    LinkSqueue Q;
    bool ret;
    ElemType data;
    init_squeue(Q);//初始化队列
    EnQueue(Q,3);
    EnQueue(Q,4);
    EnQueue(Q,5);
    EnQueue(Q,6);
    ret=de_queue(Q,data);
    if (ret)
    {
        printf("出队成功data=%d\n",data);
    }else
    {
        printf("出队失败\n");
    }

    return 0;
}