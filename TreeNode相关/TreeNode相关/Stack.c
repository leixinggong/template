//
//  Stack.c
//  TreeNode相关
//
//  Created by glx on 2019/5/20.
//  Copyright © 2019 glx. All rights reserved.
//

#include "Stack.h"
#include <stdlib.h>

void initStack(Stack * s,int len)
{
    s->len = len;
    s->top = 0;
    s->space = (TreeNode **)malloc(sizeof(TreeNode *) * len);
}

int isFullStack(Stack * s)
{
    return s->top == s->len;
}

int isEmptyStack(Stack * s)
{
    return s->top == 0;
}

void push(Stack * s, TreeNode * t)
{
    s->space[s->top++] = t;
}

TreeNode * pop(Stack * s)
{
    return s->space[--s->top];
}

void resetStack(Stack * s)
{
    s->top = 0;
}
void clearStack(Stack * s)
{
    resetStack(s);
    free(s->space);
}
