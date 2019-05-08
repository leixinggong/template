//
//  Queue.h
//  LinkedQueue
//
//  Created by 龚磊星 on 2019/5/8.
//  Copyright © 2019 龚磊星. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include <stdio.h>

typedef struct _Node
{
    int data;
    struct _Node * next;
}Node;

typedef struct _Queue
{
    Node * front;
    NOde * rear;
}Queue;

void initQueue(Queue * q);
void isEmptyQueue(Queue * q);
void enQueue(Queue * q,int data);
int deQueue(Queue * q);
void resetQueue(Queue * q);
void clearQueue(Queue * q);

#endif /* Queue_h */
