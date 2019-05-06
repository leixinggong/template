//
//  ListStack.h
//  Stack
//
//  Created by 龚磊星 on 2019/5/7.
//  Copyright © 2019 龚磊星. All rights reserved.
//

#ifndef ListStack_h
#define ListStack_h

#include <stdio.h>

typedef struct _node{
    
    int data;
    struct _node * next;
}Node;

typedef struct _listStack{
    
    Node * top;
    
}ListStack;

void  createListStack(ListStack * ls);
int isEmptyListStack(ListStack * ls);
void  ls_push(ListStack * ls,int data);
int ls_pop(ListStack * ls);
void resetListStack(ListStack * ls);
void clearStack(ListStack * ls);

#endif /* ListStack_h */
