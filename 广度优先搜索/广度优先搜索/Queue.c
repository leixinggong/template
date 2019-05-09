//
//  Queue.c
//  LinkedQueue
//
//  Created by 龚磊星 on 2019/5/8.
//  Copyright © 2019 龚磊星. All rights reserved.
//

#include "Queue.h"
#include <stdlib.h>

void initQueue(Queue * q)
{
    Node * head = (Node *)malloc(sizeof(Node));
    q->front= q->rear= head;
    q->rear->next = NULL;
}

int isEmptyQueue(Queue * q)
{
    return q->rear == q->front;
}

void enQueue(Queue * q,Point p)
{
    Node * cur = (Node *)malloc(sizeof(Node));
    cur->data = p;
    cur->next = NULL;

    q->rear->next = cur;
    q->rear = cur;
}

Point deQueue(Queue * q)
{
    Point data = q->front->next->data;
    if (q->front->next == q->rear)
    {
        free(q->front->next);
        q->rear = q->front;
        q->rear->next = NULL;
    }
    else
    {
        Node * t = q->front->next;
        q->front->next = t->next;
        free(t);
    }
    return data;
}

void resetQueue(Queue * q)
{
    Node * head = q->front->next;
    q->front->next = NULL;
    q->rear = q->front;
    Node * t;
    while (head)
    {
        t = head->next;
        free(head);
        head = t;
    }
    
}

void clearQueue(Queue * q)
{
    resetQueue(q);
    free(q->front);
    q->front = NULL;
}
