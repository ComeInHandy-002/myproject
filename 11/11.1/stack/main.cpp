#include <stdio.h>

//栈的实现（first in last out）
#define MAXSIZE 50
typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE];
    int top;
}SqStack;

void initstack(SqStack &s)
{
    s.top=-1;//初始化栈，栈为空
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
    if (s.top!=MAXSIZE-1)
    {
        s.data[++s.top]=data;//相当于s.top+=1;s.data[s.top]=data
        return true;
    }
    return false;
}
//获取栈顶元素
bool get_top(SqStack s,ElemType &data)
{
    if (stack_empty(s))
    {
        return false;
    }
    data=s.data[s.top];
    return true;
}
//弹栈
bool pop(SqStack &s,ElemType &data)
{
    if (stack_empty(s))
    {
        return false;
    }
    data=s.data[s.top--];//相当于data=s.data[s.top];s.top-=1;
    return true;
}
int main()
{
    SqStack s;
    bool flag;
    ElemType data;
    initstack(s);
    flag=stack_empty(s);
    if (flag)
    {
        printf("s栈为空\n");
    }
    else
    {
        printf("s栈不为空\n");
    }
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    get_top(s,data);
    printf("get_top后%d\n",data);
    pop(s,data);
    printf("pop后%d\n",data);
    get_top(s,data);
    printf("%d\n",data);

    return 0;
}