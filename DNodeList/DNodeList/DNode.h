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

#endif /* DNode_h */
