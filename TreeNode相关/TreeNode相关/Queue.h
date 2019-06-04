//
//  Queue.h
//  TreeNode相关
//
//  Created by glx on 2019/5/20.
//  Copyright © 2019 glx. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include <stdio.h>
#include "TreeNode.h"

typedef struct _queue
{
    int front;
    int rear;
    int len;
    TreeNode ** space;
}Queue;

void initQueue(Queue * q,int size);
int isFullQueue(Queue * q);
int isEmptyQueue(Queue * q);
void enQueue(Queue * q,TreeNode * tree);
TreeNode * deQueue(Queue * q);
void resetQueue(Queue * q);
void clearQueue(Queue * q);

#endif /* Queue_h */
