//
//  Stack.h
//  TreeNode相关
//
//  Created by glx on 2019/5/20.
//  Copyright © 2019 glx. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include <stdio.h>
#include "TreeNode.h"

typedef struct _stack
{
    int len;
    int top;
    TreeNode ** space;
}Stack;

void initStack(Stack * s,int len);
int isFullStack(Stack * s);
int isEmptyStack(Stack * s);
void push(Stack * s, TreeNode * t);
TreeNode * pop(Stack * s);
void resetStack(Stack * s);
void clearStack(Stack * s);


#endif /* Stack_h */
