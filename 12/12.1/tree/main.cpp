#include "function.h"

int main()
{
    BiTree pnew;//用来指向新申请的树结点
    char data;
    BiTree root=NULL;//root是指向树根的
    ptag_t phead=NULL,ptail=NULL,pcur=NULL,listpnew=NULL;//一个队头，一个队尾，一个指向进树元素的父亲结点，一个指向新结点
    while (scanf("%c",&data))
    {
        if (data=='\n')
        {
            break;//读到换行就结束
        }
        //calloc申请的空间大小是两参数直接相乘，并对空间进行初始化，赋值为0
        pnew=(BiTree)calloc(1,sizeof(BiTNode));//为新结点申请空间
        pnew->data=data;
        listpnew=(ptag_t)calloc(1,sizeof(tag_t));//给队列结点申请空间
        listpnew->p=pnew;
        //如果是树的第一个结点
        if (root==NULL)
        {
            root=pnew;//root指向树的根结点
            phead=listpnew;//第一个结点既是队列头也是，队列尾
            ptail=listpnew;
            pcur=listpnew;//要指向进入树的元素的父亲元素
        }
        else
        {
            //让元素先入队列
            ptail->pnext=listpnew;
            ptail=listpnew;//更新ptail
            //把结点放入树中
            if (pcur->p->lchild==NULL)
            {
                pcur->p->lchild=pnew;
            }
            else if (pcur->p->rchild==NULL)
            {
                pcur->p->rchild=pnew;
                pcur=pcur->pnext;//pcur指向下一个
            }
        }
    }
    return 0;
}