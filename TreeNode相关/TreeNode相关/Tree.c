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
    TreeNode * t = *tree;
    
    if (*tree == NULL)
    {
        *tree = (TreeNode *)malloc(sizeof(TreeNode));;
        (*tree)->data = data;
        (*tree)->left = (*tree)->right = NULL;
    }
    else
    {
        while (1)
        {
            if (t->data > data)
            {
                if (t->left == NULL)
                {
                    t->left = (TreeNode *)malloc(sizeof(TreeNode));
                    t->left->data = data;
                    t->left->left = t->left->right = NULL;
                    break;
                }
                t = t->left;
            }
            else
            {
                if (t->right == NULL)
                {
                    t->right = (TreeNode *)malloc(sizeof(TreeNode));
                    t->right->data = data;
                    t->right->left = t->right->right = NULL;
                    break;
                }
                t = t->right;
            }
        }
    }
}

void insertTreeNodeRecursive(TreeNode ** tree,int data)
{
    if (*tree == NULL)
    {
        *tree = (TreeNode *)malloc(sizeof(TreeNode));
        (*tree)->data = data;
        (*tree)->left = (*tree)->right = NULL;
    }
    else
    {
        if ((*tree)->data > data)
        {
            insertTreeNodeRecursive(&(*tree)->left, data);
        }
        else
        {
            insertTreeNodeRecursive(&(*tree)->right, data);
        }
    }
}

TreeNode * getMinTreeNode(TreeNode * tree)
{
    if (tree)
    {
        while (tree->left)
        {
            tree = tree->left;
        }
        return tree;
    }
    return NULL;
}

TreeNode * getMaxTreeNode(TreeNode * tree)
{
    if (tree)
    {
        while (tree->right)
        {
            tree = tree->right;
        }
        return tree;
    }
    return NULL;
}

TreeNode * getBinarySearchTreeNode(TreeNode * tree,int data)
{
    while (tree)
    {
        if (tree->data == data)
            return tree;
        else if (tree->data > data)
            tree = tree->left;
        else
            tree = tree->right;
    }
    return tree;
}

TreeNode * getParenterTreeNode(TreeNode * tree,TreeNode * pfind)
{
    Queue q;
    initQueue(&q, 100);
    enQueue(&q, tree);
    
    while (!isEmptyQueue(&q))
    {
        tree = deQueue(&q);
        if (tree->left == pfind || tree->right == pfind)
            return tree;
        
        if (tree->left)
            enQueue(&q, tree->left);
        if (tree->right)
            enQueue(&q,tree->right);
    }
    return NULL;
}

int getTreeDeep(TreeNode * tree)
{
    if (tree)
    {
        int lh = 0;
        int rh = 0;
        int max = 0;
        lh = getTreeDeep(tree->left);
        rh = getTreeDeep(tree->right);
        max = lh > rh ? lh : rh;
        return max + 1;
        
    }
    return 0;
}

void pretraverseBst(TreeNode * tree)
{
    Stack s;
    initStack(&s, 100);
    
    while (tree || !isEmptyStack(&s))
    {
        if (tree)
        {
            printf("%d ",tree->data);
            push(&s,tree);
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
void midtraverseBst(TreeNode * tree)
{
    Stack s;
    initStack(&s, 100);
    
    while (tree || !isEmptyStack(&s))
    {
        if (tree)
        {
            push(&s, tree);
            tree = tree->left;
        }
        else
        {
            tree = pop(&s);
            printf("%d ",tree->data);
            tree = tree->right;
        }
    }
    putchar(10);
}

void posttraverseBst(TreeNode * tree)
{
    Stack s;
    initStack(&s,100);
    push(&s, tree);
    TreeNode * pre = NULL;
    
    while (!isEmptyStack(&s))
    {
        TreeNode * cur = pop(&s);
        push(&s, cur);
        
        if ((cur->left == NULL && cur->right == NULL) ||
            (pre != NULL && (cur->left == pre || cur->right == pre)))
        {
            printf("%d ",cur->data);
            pre = cur;
            pop(&s);
        }
        else
        {
            if (cur->right)
                push(&s, cur->right);
            if (cur->left)
                push(&s, cur->left);
        }
    }
    putchar(10);
}

void leveltraverseBst(TreeNode * tree)
{
    Queue q;
    initQueue(&q, 100);
    enQueue(&q, tree);
    
    while (!isEmptyQueue(&q))
    {
        tree = deQueue(&q);
        printf("%d ",tree->data);
        
        if (tree->left)
            enQueue(&q, tree->left);
        if (tree->right)
            enQueue(&q, tree->right);
    }
    putchar(10);
}

void deleteTreeNode(TreeNode ** tree, TreeNode * del)
{
    if (*tree == NULL || del == NULL) return;
    
    TreeNode * t = *tree;
    TreeNode * parent = getParenterTreeNode(*tree, del);
    TreeNode * minRight = NULL;
    if (t->left == NULL && t->right == NULL)
    {
        if (t == del)
        {
            *tree = NULL;
            free(*tree);
            return;
        }
        if (parent->left == del)
            parent->left = NULL;
        else
            parent->right = NULL;
        
        free(del);
    }
    else if (del->left != NULL && del->right == NULL)
    {
        if (t == del)
        {
            *tree = t->left;
            free(del);
        }
        
        if (parent->left == del)
            parent->left = del->left;
        else
            parent->right = del->left;
        
        free(del);
    }
    else if (del->left == NULL && del->right != NULL)
    {
        if (t == del)
        {
            *tree = t->right;
            free(del);
            return;
        }
        
        if (parent->left == del)
            parent->left = del->right;
        else
            parent->right = del->right;
        free(del);
    }
    else
    {
        minRight = getMinTreeNode(del->right);
        del->data = minRight->data;
        parent = getParenterTreeNode(*tree, minRight);
        
        if (del->right == minRight)
        {
            parent->right = minRight->right;
        }
        else
        {
            parent->left = minRight->right;
        }
        free(minRight);
    }
}
