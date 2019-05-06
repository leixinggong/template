//
//  DNode.h
//  DNodeList
//
//  Created by 龚磊星 on 2019/5/6.
//  Copyright © 2019 龚磊星. All rights reserved.
//

#ifndef DNode_h
#define DNode_h

#include <stdio.h>

typedef struct _DNode{
    int data;
    struct _DNode * next;
    struct _DNode * pre;
}DNode;


void createList(DNode * head);
void insertDNode(DNode * head, int data);
DNode * searchDNode(DNode * head,int data);
void remvoeDNode(DNode * head,DNode * pfind);
void lengthList(DNode * head);
void popSort(DNode * head);
void reverseList(DNode * head);
void tranversing(DNode * head);


#endif /* DNode_h */
