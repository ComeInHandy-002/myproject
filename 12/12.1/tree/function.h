//
// Created by 19505 on 2025/10/29.
//

#ifndef FUNCTION_H
#define FUNCTION_H
#include <stdio.h>
#include <stdlib.h>

//树的结构体
typedef struct BiTNode
{
    char data;//数据
    struct BiTNode *lchild;//左结点
    struct BiTNode *rchild;//右结点
} BiTNode,*BiTree;

//辅助队列
typedef struct tag
{
    BiTree p;//树的某一个结点的地址（是指针）
    struct tag *pnext;
}tag_t,*ptag_t;

#endif //FUNCTION_H
