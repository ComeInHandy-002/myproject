#include <stdio.h>

/*Description
新建一个栈，读取标准输入3个整数3 4 5，入栈3 4 5，依次出栈，打印 5 4 3，新建循环队列（Maxsize为5），
读取标准输入3 4 5 6 7，入队7时，队满，打印false，然后依次出队，输出 3 4 5 6

Input
读取标准输入，内容依次是3 4 5，换行后，接着是3 4 5 6 7

Output
如果输入是3 4 5，换行，接着是3 4 5 6 7，那么输出是
5 4 3
false
3 4 5 6
注意每个数字占用两个字符的位置，5之前是有一个空格的，第三行的3之前也是有一个空格的*/
#define MaxSize 5
typedef int ElemType;

//栈
typedef struct
{
    ElemType data[10];
    int top;
}SqStack;
//循环队列（数组）
typedef struct
{
    ElemType data[MaxSize];
    int front,rear;
}SqQueue;

//初始化栈
void init_stack(SqStack &s)
{
    s.top=-1;//栈为空
}
//判断栈是否为空
bool stack_empty(SqStack s)
{
    if (s.top==-1)
    {
        return true;
    }
    return false;
}
//压栈
bool push(SqStack &s,ElemType data)
{
    if (s.top!=9)
    {
        s.data[++s.top]=data;
        return true;
    }
   return false;
}
//弹栈
bool pop(SqStack &s,ElemType &data)
{
    if (stack_empty(s))
    {
        return false;
    }
    data=s.data[s.top--];
    return true;
}

//初始化队列
void init_queue(SqQueue &q)
{
    q.front=q.rear=0;//队列为空
}
//判断队列是否为空
bool queue_empty(SqQueue q)
{
    if (q.front==q.rear)
    {
        return true;
    }
    return false;
}
//入队
bool EnQueue(SqQueue &q,ElemType data)
{
    if ((q.rear+1)%MaxSize==q.front)
    {
        printf("false\n");
        return false;;
    }
        q.data[q.rear]=data;
        q.rear=(q.rear+1)%MaxSize;
    return true;
}
//出队
bool de_queue(SqQueue &q,ElemType &data)
{
    if (queue_empty(q))
    {
        return false;;
    }
    data=q.data[q.front];
    q.front=(q.front+1)%MaxSize;
    return true;
}
int main()
{
    /*SqStack s;
    SqQueue q;
    ElemType data1,data2,data3,data4,data5;
    init_stack(s);
    init_queue(q);
    scanf("%d%d%d",&data1,&data2,&data3);
    push(s,data1);
    push(s,data2);
    push(s,data3);
    scanf("%d%d%d%d%d",&data1,&data2,&data3,&data4,&data5);
    EmQueue(q,data1);
    EmQueue(q,data2);
    EmQueue(q,data3);
    EmQueue(q,data4);
    EmQueue(q,data5);*/
    SqStack s;
    SqQueue q;
    ElemType data;
    init_stack(s);
    init_queue(q);

    int a, b, c, d, e, f, g;
    // 读取栈输入
    scanf("%d%d%d", &a, &b, &c);
    push(s, a);
    push(s, b);
    push(s, c);
    // 读取队列输入
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);

    // 栈输出（出栈打印）
    while (pop(s, data))
    {
        printf(" %d", data);
    }
    printf("\n");


    EnQueue(q, a);
    EnQueue(q, b);
    EnQueue(q, c);
    EnQueue(q, d);
    EnQueue(q, e);
    // 队列输出（出队打印）
    while (de_queue(q, data))
    {
        printf(" %d", data);
    }
    printf("\n");

    return 0;
}