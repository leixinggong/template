//
//  main.cpp
//  数组中没有重复的数字
//
//  Created by glx on 2019/5/20.
//  Copyright © 2019 glx. All rights reserved.
//

#include <iostream>

void bitDes(int a)
{
    int count  = 32;
    while (count--)
    {
        if ((1 << count) & a)
            printf("1");
        else
            printf("0");
        if (count % 8 == 0)
            printf(" ");
    }
    printf(" %d \n",a);
}

int main(int argc, const char * argv[]) {

    int array[] = {3,3,5,8,4,4};
    int len = sizeof(array)/ sizeof(array[0]);
    
    int resAry[2]={0};
    int res = array[0];
    for (int i = 1; i < len; i++)
    {
        res ^= array[i];
    }

    int bitIndex = 32;
    while (bitIndex--)
    {
        if ((res >> bitIndex & 1) == 1)
            break;
    }
    
    for (int i = 0; i < len; i++)
    {
        bitDes(array[i]);
        if ((array[i] >> bitIndex & 1) == 1)
        {
            resAry[1] ^= array[i];
        }
        else
        {
            resAry[0] ^= array[i];
        }
    }
    
    return 0;
}
