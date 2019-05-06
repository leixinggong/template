//
//  ArrayStack.h
//  Stack
//
//  Created by 龚磊星 on 2019/5/7.
//  Copyright © 2019 龚磊星. All rights reserved.
//

#ifndef ArrayStack_h
#define ArrayStack_h

#include <stdio.h>

typedef struct _ArrayStack{
    int len;
    int * space;
    int top;
    
}ArrayStack;

void createArrayStack(ArrayStack ** s,int len);
int  isEmptyArrayStack(ArrayStack * s);
int isFrllArrayStack(ArrayStack * s);
void as_push(ArrayStack * s,int data);
int as_pop(ArrayStack * s);
void resetAStack(ArrayStack * s);
void tranversing(ArrayStack * s);
#endif /* ArrayStack_h */
