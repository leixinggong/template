//
//  main.c
//  TreeNode 相关方法
//
//  Created by 龚磊星 on 2019/5/12.
//  Copyright © 2019 龚磊星. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"


void initTree(TreeNode ** t)
{
    *t = NULL;
}

void insertTreeNode(TreeNode ** tree,int data)
{
    TreeNode * cur = *tree;
    // 判断树是否为空
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
            /// 传入的data 如果大于 左子树 那么就往右子树上插入
            if (data < cur->data)
            {
                if (cur->left == NULL)
                {
                    cur->left = (TreeNode *)malloc(sizeof(TreeNode));
                    cur->left->data = data;
                    cur->left->left = cur->left->right = NULL;
                    break;
                }
                cur = cur->left;
            }
            else
            {
                if (cur->right == NULL)
                {
                    cur->right = (TreeNode *)malloc(sizeof(TreeNode));
                    cur->right->data = data;
                    cur->right->right = cur->right->left = NULL;
                    break;
                }
                cur = cur->right;
            }
        }
    }
}

void insertRecursive(TreeNode ** tree,int data)
{
    if (*tree == NULL)
    {
        *tree = (TreeNode *)malloc(sizeof(TreeNode));
        (*tree)->data = data;
        (*tree)->left = (*tree)->right = NULL;
    }
    else
    {
        if (data > (*tree)->data)
        {
            insertRecursive(&(*tree)->right, data);
        }
        else
        {
            insertRecursive(&(*tree)->left, data);
        }
    }
}


int  getTreeOrderByDeep(TreeNode * t)
{
    if (t)
    {
        int lh = 0;
        int rh = 0;
        int maxh = 0;
        
        lh = getTreeOrderByDeep(t->left);
        rh = getTreeOrderByDeep(t->right);
        maxh = lh > rh ? lh : rh;
        return maxh + 1;
    }
    return 0;
}

TreeNode * getMinTreeNodeBst(TreeNode * tree)
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

TreeNode * getMaxTreeNodeBst(TreeNode * tree)
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


TreeNode * getPratenTreeNode(TreeNode * tree,TreeNode * pfind)
{
    Queue q;
    initQueue(&q, 10);
    enQueue(&q, tree);
    
    if (tree && pfind)
    {
        while (!isEmptyQueue(&q))
        {
            TreeNode * cur = deQueue(&q);
            if (cur->left == pfind || cur->right == pfind)
            {
                return cur;
            }
            
            if (cur->left)
            {
                enQueue(&q, tree->left);
            }
            
            if (cur->right)
            {
                enQueue(&q, cur->right);
            }
        }
    }
    return NULL;
}

TreeNode * getBinarySearchTreeNode(TreeNode * tree,int pfind)
{
    if (tree && pfind)
    {
        while (tree)
        {
            if (tree->data == pfind)
            {
                return tree;
            }
            else if(tree->data > pfind)
            {
                tree = tree->left;
            }
            else
            {
                tree = tree->right;
            }
        }
    }
    return NULL;
}

void deleteTreeNode(TreeNode ** tree,TreeNode * del)
{
    TreeNode * t = *tree;
    
    TreeNode * parter = getPratenTreeNode(*tree, del);
    
    /// 删除叶子节点
    if (del->left == NULL && del->right == NULL)
    {
        /// 判断是根叶子节点 删除
        if (t == del)
        {
            free(t);
            *tree = NULL;
            return;
        }
        
        /// 判断是普通的叶子节点 左叶子
        if (parter->left == del)
        {
            parter->left = NULL;
        }
        /// 右叶子
        else
        {
            parter->right = NULL;
        }
        free(del);
    }
    else if (del->left != NULL && del->right == NULL)
    {
        if (t == del)
        {
            *tree = t->left;
            free(del);
            return;
        }
        
        if (parter->left == del)
            parter->left = del->left;
        else
            parter->right = del->left;;
        
        free(del);
    }
    else if (del->left == NULL && del->right != NULL)
    {
        if(t == del)
        {
            *tree = t->right;
            free(del);
            return;
        }
        
        if (parter->left == del)
            parter->left = del->right;
        else
            parter->right = del->right;
        free(del);
        
    }
    /// 左右都不为空
    else
    {
        /// 求出当前需要删除节点右子树的最小节点
        TreeNode * minRight = getMinTreeNodeBst(del->right);
        del->data = minRight->data;
        
        parter = getPratenTreeNode(*tree, minRight);
        
        if (parter->right == minRight)
            parter->right = minRight->right;
        else
            parter->left = minRight->right;
    
        free(del);
    }
}

void midTreeNodeBst(TreeNode * tree)
{
    if (tree)
    {
        midTreeNodeBst(tree->left);
        printf("%d ",tree->data);
        midTreeNodeBst(tree->right);
    }
}

int main(int argc, const char * argv[])
{
    
    TreeNode * tree;
    initTree(&tree);
    
    insertRecursive(&tree, 10);
    insertRecursive(&tree, 14);
    insertRecursive(&tree, 5);
    insertRecursive(&tree, 7);
    insertTreeNode(&tree, 8);
    insertTreeNode(&tree, 4);
    insertRecursive(&tree, 45);
    insertRecursive(&tree, 15);
    
    midTreeNodeBst(tree);
    putchar(10);
    
    
    TreeNode * node = getBinarySearchTreeNode(tree, 5);
    TreeNode * cur = getPratenTreeNode(tree, node);
    
    TreeNode * minTree = getMinTreeNodeBst(tree);
    TreeNode * maxTree = getMaxTreeNodeBst(tree);
    
    
    deleteTreeNode(&tree,node);
    
    midTreeNodeBst(tree);
    putchar(10);
    
    

    return 0;
}
