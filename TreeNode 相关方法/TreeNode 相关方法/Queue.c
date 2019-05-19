//
//  Queue.c
//  TreeNode 相关方法
//
//  Created by 龚磊星 on 2019/5/17.
//  Copyright © 2019 龚磊星. All rights reserved.
//

#include "Queue.h"
#include <stdlib.h>


void initQueue(Queue * q,int size)
{
    q->len = size;
    q->front = q->rear = 0;
    q->sapce = (TreeNode **)malloc(sizeof(TreeNode *) * size);
}

int isFullQueue(Queue * q)
{
    return q->front == (q->rear + 1) % q->len;
}

int isEmptyQueue(Queue * q)
{
    return q->rear == q->front;
}

void enQueue(Queue * q ,TreeNode * tree)
{
    q->sapce[q->rear] = tree;
    q->rear = ++q->rear % q->len;
}

TreeNode * deQueue(Queue * q)
{
    TreeNode * tree = q->sapce[q->front];
    q->front = ++q->front % q->len;
    return tree;
}

void resetQueue(Queue * q)
{
    q->front = q->rear = 0;
}

void clearQueue(Queue ** q)
{
    free((*q)->sapce);
    *q = NULL;
}
