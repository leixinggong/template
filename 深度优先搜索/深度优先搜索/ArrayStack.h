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

typedef struct _point{
    int x;
    int y;
}Point;

typedef struct _ArrayStack{
    int len;
    Point * space;
    int top;
    
}ArrayStack;

void createArrayStack(ArrayStack ** s,int len);
int  isEmptyArrayStack(ArrayStack * s);
int isFullArrayStack(ArrayStack * s);
void as_push(ArrayStack * s,Point p);
Point as_pop(ArrayStack * s);
void resetAStack(ArrayStack * s);
void clearAStack(ArrayStack * s);
void tranversing(ArrayStack * s);
#endif /* ArrayStack_h */
