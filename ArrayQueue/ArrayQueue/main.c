//
//  main.c
//  ArrayQueue
//
//  Created by 龚磊星 on 2019/5/8.
//  Copyright © 2019 龚磊星. All rights reserved.
//

#include <stdio.h>
#include "Queue.h"

int main(int argc, const char * argv[]) {
   
    Queue q;
    int len = 7;
    initQueue(&q, len);
  
    for (int i = 0; i < len; i++)
    {
        if (isFullQueue(&q))
        {
            break;
        }
        else
        {
            enQueue(&q, i+1);
        }
    }
    
    while (!isEmptyQueue(&q))
    {
        printf("%d ",deQueue(&q));
    }

    putchar(10);
    
    
    return 0;
}
