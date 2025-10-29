#include <stdio.h>
#include <stdlib.h>


/*请设计一个队列，要求满足:
① 初始时队列为空；
② 入队时，允许增加队列占用空间；
③ 出队后，出队元素所占用的空间可重复使用，即整个队列所占用的空间只增不减；
④ 入队操作和出队操作的时间复杂度始终保持为 O(1)。

请回答下列问题：
⑴ 该队列是应选择链式存储结构，还是应选择顺序存储结构？
⑵ 画出队列的初始状态，并给出判断队空和队满的条件。
⑶ 画出第一个元素入队后的队列状态。
⑷ 给出入队操作和出队操作的基本过程。*/
typedef int ElemType;
typedef struct LinkNode
{
    ElemType data;
    struct LinkNode* next;
}LinkNode,*LinkList;

bool is_empty(LinkList front,LinkList rear)
{
    if (rear==front)
    {
        //printf("队列为空\n");
        return true;
    }
    return false;
}

//入队
void enqueue(LinkList front,LinkList &rear,ElemType data)
{
    LinkList pnew;
    if (rear->next==front)
    {
        //队列满，申请一个结点的空间，放入队列
        pnew=(LinkList)malloc(sizeof(LinkNode));
        rear->data=data;//把入队元素放入rear指向的结点
        rear->next=pnew;//放了一个结点，其相当于做了分割
        pnew->next=front;//在形成闭环
        rear=pnew;//队列尾后移
    }
    else
    {
        //如果队列不满，直接放值，让rear后移一个结点
        rear->data=data;
        rear=rear->next;
    }
}
//出队
void de_queue(LinkList &front,LinkList rear)
{
    if (is_empty(front,rear))
    {
        printf("队列为空\n");
    }else
    {
        printf("出队值为%d\n",front->data);
        front=front->next;//队列头后移
    }
}

//总流程
void circular_queue(LinkList &front,LinkList &rear)
{
    //队列头和队列尾都指向一个结点，这时队列既是空的也是满的
    front=(LinkList)malloc(sizeof(LinkNode));
    rear=front;
    rear->next=front;
    //入队
    enqueue(front,rear,3);
    enqueue(front,rear,4);
    //出队
    de_queue(front,rear);
    de_queue(front,rear);
    de_queue(front,rear);
}
int main()
{
    LinkList front,rear;
    circular_queue(front,rear);
    return 0;
}

//本质上这题是一个用链表实现循环队列的问题