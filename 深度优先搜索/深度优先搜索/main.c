//
//  main.c
//  深度优先搜索
//
//  Created by 龚磊星 on 2019/5/8.
//  Copyright © 2019 龚磊星. All rights reserved.
//

#include <stdio.h>
#include "ArrayStack.h"
#include <stdlib.h>
#include <unistd.h>

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

ArrayStack * s;

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

void visit(Point p)
{
    as_push(s, p);
}

int main(int argc, const char * argv[])
{
    
    
    createArrayStack(&s, 10);
    
    Point sp = {1,0};
    Point ed = {8,9};
    as_push(s, sp);
    
    int flag = 0;
    
    while (isEmptyArrayStack(s))
    {
        
        
        Point p = as_pop(s);
        maze[p.x][p.y] = 2;
        
        displyMaze();
        sleep(1);
        
        system("clear");
        
        /// 上
        if (p.x-1 >= 0 && maze[p.x-1][p.y] == 0)
        {
            Point t = {p.x-1,p.y};
            visit(t);
        }
        
        /// 下
        if (p.x+1 <= 9 && maze[p.x+1][p.y] == 0)
        {
            Point t = {p.x+1,p.y};
            visit(t);
        }
        
        /// 左
        if (p.y-1 >= 0 && maze[p.x][p.y-1] == 0)
        {
            Point t = {p.x,p.y-1};
            visit(t);
        }
        
        /// 右
        if (p.y+1 <= 9 && maze[p.x][p.y+1] == 0)
        {
            Point t = {p.x,p.y+1};
            visit(t);
        }
        
        
        if (ed.x == p.x && ed.y == p.y)
        {
            flag = 1;
            break;
        }
    }
    
    if (flag){
        printf("找到出口\n");
    }else{
        printf("没有找到\n");
    }
    
    return 0;
}
