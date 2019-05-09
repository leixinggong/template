//
//  Queue.c
//  ArrayQueue
//
//  Created by 龚磊星 on 2019/5/8.
//  Copyright © 2019 龚磊星. All rights reserved.
//

#include "Queue.h"
#include <stdlib.h>
#include <string.h>

void initQueue(Queue * q,int len)
{
    q->space = (int *)malloc(sizeof(int)* len);
    memset(q->space, 0x0, sizeof(int) * len);
    q->front = q->rear = 0;
    q->len = len;
}

int isFullQueue(Queue * q)
{
    return q->front == (q->rear+1)%q->len;
}

int isEmptyQueue(Queue * q)
{
    return q->front == q->rear;
}

void enQueue(Queue * q, int data)
{
    q->space[q->rear] = data;
    q->rear = ++q->rear % q->len;
}

int deQueue(Queue * q)
{
    int data = q->space[q->front];
    q->front = ++q->front % q->len;
    return data;
}

void resetQueue(Queue * q)
{
    q->rear = q->front;
}

void clearQueue(Queue * q)
{
    resetQueue(q);
    free(q->space);
}
