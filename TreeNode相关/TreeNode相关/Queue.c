//
//  Queue.c
//  TreeNode相关
//
//  Created by glx on 2019/5/20.
//  Copyright © 2019 glx. All rights reserved.
//

#include "Queue.h"
#include <stdlib.h>

void initQueue(Queue * q,int size)
{
    q->front = q->rear = 0;
    q->len = size;
    q->space = (TreeNode **)malloc(sizeof(TreeNode *) * size);
}

int isFullQueue(Queue * q)
{
    return (q->rear+1) % q->len == q->front;
}

int isEmptyQueue(Queue * q)
{
    return q->front == q->rear;
}

void enQueue(Queue * q,TreeNode * tree)
{
    q->space[q->rear] = tree;
    q->rear = ++q->rear % q->len;
}

TreeNode * deQueue(Queue * q)
{
    TreeNode * tree = q->space[q->front];
    q->front = ++q->front % q->len;
    return tree;
}

void resetQueue(Queue * q)
{
    q->rear= q->front= 0;
}

void clearQueue(Queue * q)
{
    resetQueue(q);
    free(q->space);
}
