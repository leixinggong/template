//
//  TreeNode.h
//  TreeNode相关
//
//  Created by glx on 2019/5/20.
//  Copyright © 2019 glx. All rights reserved.
//

#ifndef TreeNode_h
#define TreeNode_h


typedef struct _treeNode
{
    int data;
    struct _treeNode * left;
    struct _treeNode * right;
}TreeNode;

#endif /* TreeNode_h */
