//
//  ArrayStack.c
//  Stack
//
//  Created by 龚磊星 on 2019/5/7.
//  Copyright © 2019 龚磊星. All rights reserved.
//

#include "ArrayStack.h"
#include <stdlib.h>
#include <string.h>

void createArrayStack(ArrayStack ** s,int len)
{
    ArrayStack * stack = (ArrayStack *)malloc(sizeof(ArrayStack));
    stack->len = len;
    stack->top = 0;
    
    stack->space = (int *)malloc(sizeof(int) * len);
    memset(stack->space, 0x0, sizeof(int) * len);
}

int  isEmptyArrayStack(ArrayStack * s)
{
    if (s->top){
        return 1;
    }else{
        return 0;
    }
}

int isFullArrayStack(ArrayStack * s)
{
    if (s->len == s->top){
        return 1;
    }else{
        return 0;
    }
}

void as_push(ArrayStack * s,int data)
{
    s->space[s->top++] = data;
}

int as_pop(ArrayStack * s)
{
    return s->space[--s->top];
}

void resetAStack(ArrayStack * s)
{
    s->top = 0;
}

void clearAStack(ArrayStack * s)
{
    free(s->space);
    free(s);
}

void tranversing(ArrayStack * s)
{
    for (int i = 0; i < s->top; i++)
    {
        printf("%d ",s->space[i]);
    }
}
