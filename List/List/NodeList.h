//
//  NodeList.h
//  List
//
//  Created by 龚磊星 on 2019/5/6.
//  Copyright © 2019 龚磊星. All rights reserved.
//

#ifndef NodeList_h
#define NodeList_h

#include <stdio.h>

typedef struct _Node{
    
    int data;
    struct _Node * next;
}Node;


void createList(Node ** head);
void insertNode(Node * head,int data);
Node * searchListToNode(Node * head,int data);
void removeNode(Node * head,Node * pfind);
void popSort(Node * head);
int listLength(Node * head);
void tranversing(Node * head);
void reverseList(Node  * head);
void destoryList(Node * head);


#endif /* NodeList_h */
