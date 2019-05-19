//
//  NodeList.c
//  List
//
//  Created by 龚磊星 on 2019/5/6.
//  Copyright © 2019 龚磊星. All rights reserved.
//

#include "NodeList.h"
#include <stdlib.h>

void createList(Node ** head)
{
    *head = (Node *)malloc(sizeof(Node));
    (*head)->next = NULL;
}

void insertNode(Node * head,int data)
{
    Node * cur = (Node *)malloc(sizeof(Node));
    cur->data = data;
    /// 让先来的节点县有所指向
    cur->next = head->next;
    head->next = cur;
}

Node * searchListToNode(Node * head,int data)
{
    head = head->next;
    while (head)
    {
        if (head->data == data)
        {
            break;
        }
    }
    return head;
}

void removeNode(Node * head,Node * pfind)
{
    if (pfind->next)
    {
        Node * t = pfind->next;
        pfind->data = pfind->next->data;
        pfind->next = t->next;
        free(t);
    }
    else
    {
        while (head->next != pfind)
        {
            head = head->next;
        }
        head->next = pfind->next;
        free(pfind);
    }
}

void popSort(Node * head)
{
    Node * sh = NULL;
    Node * p  = NULL;
    Node * q  = NULL;

    int len = listLength(head);
    
    for (int i = 0; i < len - 1; i++)
    {
        sh = head;
        p  = sh->next;
        q  = p->next;
        
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (p->data > q->data)
            {
                sh->next = q;
                p->next = q->next;
                q->next = p;
                
                sh = q;
                q = p->next;
                
                continue;
            }
            
            sh = sh->next;
            p  = sh->next;
            q  = p->next;
        }
    }
}

int listLength(Node * head)
{
    int len = 0;
    head = head->next;
    while (head)
    {
        len++;
        head = head->next;
    }
    return len;
}

void tranversing(Node * head)
{
    head = head->next;
    while (head)
    {
        printf("%d ",head->data);
        head = head->next;
    }
    putchar(10);
}

void reverseList(Node  * head)
{
    Node * th = head->next;
    head->next = NULL;
    Node * t = NULL;
    
    while (th) {
        t = th->next;
        th->next = head->next;
        head->next = th;
        th = t;
    }
    
}

void destoryList(Node * head)
{
    Node * t = NULL;
    while (head)
    {
        t = head->next;
        free(head);
        head = t;
    }
}
