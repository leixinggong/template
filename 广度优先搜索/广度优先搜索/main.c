//
//  main.c
//  广度优先搜索
//
//  Created by 龚磊星 on 2019/5/8.
//  Copyright © 2019 龚磊星. All rights reserved.
//

#include <stdio.h>
#include "Queue.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAXROW 10
#define MAXLINE 10

//1 代表墙，2 走过的路，0 代表路
int maze[MAXROW][MAXLINE] =
{
    1,1,1,1,1,1,1,1,1,1,
    0,0,0,1,1,1,1,1,1,1,
    1,1,0,1,1,1,1,1,1,1,
    1,1,0,0,0,0,1,1,1,1,
    1,1,0,1,1,0,1,1,1,1,
    1,1,0,1,1,0,1,1,1,1,
    1,1,1,1,1,0,1,1,1,1,
    1,1,1,1,1,0,0,0,1,1,
    1,1,1,1,1,1,1,0,0,0,
    1,1,1,1,1,1,1,1,1,1,
};

Point pointMaze[MAXROW][MAXLINE];

Queue q;

void displyMaze()
{
    for(int i=0; i< MAXROW; i++)
    {
        for(int j=0; j<MAXLINE; j++)
        {
            if(maze[i][j] == 1) printf("%2s"," *");
            else if(maze[i][j] == 2) printf("%2s"," #");
            else printf("%2s"," ");
        }
        putchar(10);
    }
    printf(" ====================\n");
}
void visit(int x,int y,Point t)
{
    Point p = {x,y};
    enQueue(&q, p);
    pointMaze[x][y] = t;
}

int main(int argc, const char * argv[]) {
    
    initQueue(&q);
    Point sp = {1,0};
    Point ed = {8,9};
    enQueue(&q, sp);
    int flag = 0;
    
    memset(pointMaze,0xff,sizeof(pointMaze));
    
    while (!isEmptyQueue(&q))
    {
        Point p = deQueue(&q);
        maze[p.x][p.y] = 2;
        
        system("clear");
        displyMaze();
        sleep(1);
        
        
        if (p.x-1 >= 0 && maze[p.x-1][p.y] == 0)
        {
            visit(p.x-1, p.y, p);
        }
        
        if (p.x+1 <= 9 && maze[p.x+1][p.y] == 0)
        {
            visit(p.x+1, p.y, p);
        }
        
        if (p.y-1 >= 0 && maze[p.x][p.y-1] == 0)
        {
            visit(p.x, p.y-1, p);
        }
        
        if (p.y+1 <= 9 && maze[p.x][p.y+1] == 0)
        {
            visit(p.x, p.y+1, p);
        }
        
        if (ed.x == p.x && ed.y == p.y )
        {
            printf("找到了\n");
            break;
        }
        
    }
    
    Point pr = ed;
    
    while (pr.x != -1)
    {
        printf("(%d,%d)) ",pr.x,pr.y);
        pr = pointMaze[pr.x][pr.y];
    }
    putchar(10);
    
    return 0;
}
