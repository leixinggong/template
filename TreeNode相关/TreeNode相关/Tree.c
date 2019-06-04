//
//  Tree.c
//  TreeNode相关
//
//  Created by glx on 2019/5/21.
//  Copyright © 2019 glx. All rights reserved.
//

#include "Tree.h"
#include "Stack.h"
#include "Queue.h"
#include <stdlib.h>

void initTree(TreeNode ** tree)
{
    *tree = NULL;
}

void insertTreeNode(TreeNode ** tree,int data)
{
    TreeNode * temp = *tree;
    if (*tree == NULL)
    {
        *tree = (TreeNode *)malloc(sizeof(TreeNode));
        (*tree)->data = data;
        (*tree)->left = (*tree)->right = NULL;
    }
    else
    {
        while (1)
        {
            if (temp->data > data)
            {
                if (temp->left == NULL)
                {
                    temp->left = (TreeNode *)malloc(sizeof(TreeNode));
                    temp->left->data = data;
                    temp->left->left = temp->left->right = NULL;
                    break;
                }
                temp = temp->left;
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = (TreeNode *)malloc(sizeof(TreeNode));
                    temp->right->data = data;
                    temp->right->left = temp->right->right = NULL;
                    break;
                }
                temp = temp->right;
            }
        }
    }
}
void insertTreeNodeRecursive(TreeNode ** tree,int data);
TreeNode * getMinTreeNode(TreeNode * tree);
TreeNode * getMaxTreeNode(TreeNode * tree);
TreeNode * getBinarySearchTreeNode(TreeNode * tree,int data);
TreeNode * getParenterTreeNode(TreeNode * tree,TreeNode * pfind);
int getTreeDeep(TreeNode * tree);

void pretraverseBst(TreeNode * tree)
{
    Stack s;
    initStack(&s, 100);
    
    while (tree || !isEmptyStack(&s))
    {
        if (tree)
        {
            printf("%d ",tree->data);
            push(&s, tree);
            tree = tree->left;
        }
        else
        {
            tree = pop(&s);
            tree = tree->right;
        }
    }
    putchar(10);
}
void midtraverseBst(TreeNode * tree);
void posttraverseBst(TreeNode * tree);
void leveltraverseBst(TreeNode * tree);

void deleteTreeNode(TreeNode ** tree, TreeNode * del);
