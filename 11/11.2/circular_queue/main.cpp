#include <stdio.h>
#include <stdlib.h>
//循环队列代码实战（first in first out）

//1.初始化循环队列2.判断循环队列是否为空3.入队4.出队


#define MaxSize 5
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];//数组，存储maxsize-1个元素
    int front,rear;//队列头，队列尾
}SqQueue;

//初始化Qd
void init_queue(SqQueue &Q)
{
    Q.front=Q.rear=0;//初始化循环队列，就是让头和尾指向零
}
//判断循环队列是否为空
bool is_empty(SqQueue Q)
{
    if (Q.front==Q.rear)
    {
        return true;
    }
    return false;
}
//入队
bool EnQueue(SqQueue &Q,ElemType data)
{
    if (Q.front==(Q.rear+1)%MaxSize)
    {
        return false;
    }
    Q.data[Q.rear]=data;//放入元素
    //Q.rear++;不好
    Q.rear=(Q.rear+1)%MaxSize;//rear要加1，为了防止rear超过数组的最大下标，所以要%上MaxSize回到开头
    return true;

}
//出队
bool DeSqueue(SqQueue &Q,ElemType &data)
{
    if (is_empty(Q))
    {
        return false;
    }
    data=Q.data[Q.front];
    Q.front=(Q.front+1)%MaxSize;
    return true;
}
int main()
{
    SqQueue Q;
    bool ret;
    ElemType data;
    init_queue(Q);
    ret=is_empty(Q);
    if (ret)
    {
        printf("循环队列为空\n");
    }
    else
    {
        printf("循环队列不为空\n");
    }
    EnQueue(Q,3);
    EnQueue(Q,4);
    EnQueue(Q,5);
    ret=EnQueue(Q,6);
    ret=EnQueue(Q,7);
    if (ret)
    {
        printf("入队成功\n");
    }else
    {
        printf("入队失败\n");
    }
    ret=DeSqueue(Q,data);
    if (ret)
    {
        printf("出队成功data=%d\n",data);
    }else
    {
        printf("队列为空\n");
    }

    return 0;
}