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

typedef struct _point
{
    int x;
    int y;
}Point;


typedef struct _Node
{
    Point data;
    struct _Node * next;
}Node;

typedef struct _Queue
{
    Node * front;
    Node * rear;
}Queue;

void initQueue(Queue * q);
int isEmptyQueue(Queue * q);
void enQueue(Queue * q,Point p);
Point deQueue(Queue * q);
void resetQueue(Queue * q);
void clearQueue(Queue * q);

#endif /* Queue_h */
