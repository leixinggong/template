//
//  main.c
//  TreeNode 遍历
//
//  Created by 龚磊星 on 2019/5/10.
//  Copyright © 2019 龚磊星. All rights reserved.
//

#include <stdio.h>
#include "Stack.h"

void preTreeNodeOrder(TreeNode * tree)
{
    if (tree)
    {
        printf("%c ",tree->data);
        preTreeNodeOrder(tree->left);
        preTreeNodeOrder(tree->right);
    }
}

void midTreeNodeOrder(TreeNode * tree)
{
    if (tree)
    {
        midTreeNodeOrder(tree->left);
        printf("%c ",tree->data);
        midTreeNodeOrder(tree->right);
    }
}

void postTreeNodeOrder(TreeNode * tree)
{
    if (tree)
    {
        postTreeNodeOrder(tree->left);
        postTreeNodeOrder(tree->right);
        printf("%c ",tree->data);
    }
}


/// 根左右

/**
 
        A
    B       C
 D       F
      J     K
 */


void funcPreTreeOrder(TreeNode * tree)
{
    Stact s;
    initStack(&s, 100);

    while (tree || !isEmptry(&s))
    {
        while (tree)
        {
            printf("%c ",tree->data);
            push(&s, tree);
            tree = tree->left;
        }
        tree = pop(&s);
        tree = tree->right;
    }
}

void funcMidTreeOrder(TreeNode * tree)
{
    if (tree)
    {
        Stact s;
        initStack(&s, 100);
        
        while (tree || !isEmptry(&s))
        {
            while (tree)
            {
                push(&s,tree);
                tree = tree->left;
            }
            
            tree = pop(&s);
            printf("%c ",tree->data);
            tree = tree->right;
        }
        
    }
}

void funcPostTreeOrder(TreeNode * tree)
{
    if (tree)
    {
        Stact s;
        initStack(&s, 100);
        push(&s, tree);
        
        TreeNode * cur;
        TreeNode * pre = NULL;
        while (!isEmptry(&s))
        {
            cur = pop(&s);
            push(&s, cur);
            
            if ((cur->left == NULL && cur->right == NULL) || (pre != NULL && (cur->left == pre || cur->right == pre)))
            {
                printf("%c ",cur->data);
                pop(&s);
                pre = cur;
            }
            else
            {
                if (cur->right)
                {
                    push(&s, cur->right);
                }
                
                if (cur->left)
                {
                    push(&s, cur->left);
                }
            }
        }
    }
}


int main(int argc, const char * argv[]) {

    TreeNode a,b,c,d,f,j,k;
    TreeNode *root = &a;
    a.data = 'A';
    b.data = 'B';
    c.data = 'C';
    d.data = 'D';
    f.data = 'F';
    j.data = 'J';
    k.data = 'K';
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = NULL;
    d.left = d.right = NULL;
    c.left = &f;
    c.right = NULL;
    f.left = &j;
    f.right = &k;
    j.left = j.right = k.left = k.right = NULL;
    
    preTreeNodeOrder(root);
    putchar(10);
    
    midTreeNodeOrder(root);
    putchar(10);
    
    postTreeNodeOrder(root);
    putchar(10);
    
    printf("============================\n");
    
    funcPreTreeOrder(root);
    putchar(10);
    funcMidTreeOrder(root);
    putchar(10);
    funcPostTreeOrder(root);
    putchar(10);
    

    
    
    return 0;
}
