//
//  Queue.h
//  TreeNode 相关方法
//
//  Created by 龚磊星 on 2019/5/17.
//  Copyright © 2019 龚磊星. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include <stdio.h>

typedef struct _treenode{
    int data;
    struct _treenode * left;
    struct _treenode * right;
}TreeNode;

typedef struct _queue
{
    int len;
    int front;
    int rear;
    TreeNode ** sapce;
}Queue;

void initQueue(Queue * q,int size);
int isFullQueue(Queue * q);
int isEmptyQueue(Queue * q);
void enQueue(Queue * q ,TreeNode * tree);
TreeNode * deQueue(Queue * q);
void resetQueue(Queue * q);
void clearQueue(Queue ** q);

#endif /* Queue_h */
