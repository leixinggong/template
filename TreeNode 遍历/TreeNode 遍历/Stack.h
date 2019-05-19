//
//  Stack.h
//  TreeNode 遍历
//
//  Created by 龚磊星 on 2019/5/12.
//  Copyright © 2019 龚磊星. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include <stdio.h>


typedef struct _treenode
{
    char data;
    struct _treenode * left;
    struct _treenode * right;
}TreeNode;


typedef struct _stack{
    int len;
    int top;
    TreeNode ** space;
}Stact;

void initStack(Stact * s,int len);
int isFullStack(Stact * s);
int isEmptry(Stact * s);
void push(Stact * s, TreeNode * t);
TreeNode * pop(Stact * s);
void resetStack(Stact * s);
void clearStact(Stact * s);

#endif /* Stack_h */
