//
//  main.c
//  深度优先搜索
//
//  Created by 龚磊星 on 2019/5/8.
//  Copyright © 2019 龚磊星. All rights reserved.
//

#include <stdio.h>

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

int main(int argc, const char * argv[])
{

    
    return 0;
}
