//
//  Stack.c
//  TreeNode 遍历
//
//  Created by 龚磊星 on 2019/5/12.
//  Copyright © 2019 龚磊星. All rights reserved.
//

#include "Stack.h"
#include <stdlib.h>

void initStack(Stact * s,int len)
{
    s->space = (TreeNode**)malloc(sizeof(TreeNode *) * len);
    s->len = len;
    s->top = 0;
}
int isFullStack(Stact * s)
{
    return s->top == s->len;
}

int isEmptry(Stact * s)
{
    return s->top == 0;
}

void push(Stact * s, TreeNode * t)
{
    s->space[s->top++] = t;
}

TreeNode * pop(Stact * s)
{
    return s->space[--s->top];
}

void resetStack(Stact * s)
{
    s->top = 0;
}
void clearStact(Stact * s)
{
    free(s->space);
}
