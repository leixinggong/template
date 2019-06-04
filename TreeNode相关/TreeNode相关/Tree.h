//
//  Tree.h
//  TreeNode相关
//
//  Created by glx on 2019/5/21.
//  Copyright © 2019 glx. All rights reserved.
//

#ifndef Tree_h
#define Tree_h

#include <stdio.h>
#include "TreeNode.h"


void initTree(TreeNode ** tree);
void insertTreeNode(TreeNode ** tree,int data);
void insertTreeNodeRecursive(TreeNode ** tree,int data);
TreeNode * getMinTreeNode(TreeNode * tree);
TreeNode * getMaxTreeNode(TreeNode * tree);
TreeNode * getBinarySearchTreeNode(TreeNode * tree,int data);
TreeNode * getParenterTreeNode(TreeNode * tree,TreeNode * pfind);
int getTreeDeep(TreeNode * tree);

void pretraverseBst(TreeNode * tree);
void midtraverseBst(TreeNode * tree);
void posttraverseBst(TreeNode * tree);
void leveltraverseBst(TreeNode * tree);

void deleteTreeNode(TreeNode ** tree, TreeNode * del);

#endif /* Tree_h */
