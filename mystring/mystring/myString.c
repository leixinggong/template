//
//  myString.c
//  mystring
//
//  Created by 龚磊星 on 2019/4/30.
//  Copyright © 2019 龚磊星. All rights reserved.
//

#include "myString.h"

int mystrlen(const char * src)
{
    int len = 0;
    while (*src++)
    {
        len++;
    }
    return len;
}

char * mystrcpy(char * dst, const char * src)
{
    char * temp = dst;
    while ((*dst++ = *src++));
    return temp;
}

char * mystrcat(char * dst, const char * src)
{
    char * temp = dst;
    while (*dst) dst++;
    while ((*dst++ = *src++));
    return temp;
}

int mystrcmp(const char * dst1, const char * dst2)
{
    for (; *dst1&&*dst2&& *dst1 == *dst2; dst1++,dst2++);
    return *dst1 - *dst2;
}

void * mymemcpy(void * dst,void * src,int size)
{
    char * pdst = dst;
    char * psrc = src;
    while (size--)
    {
        *pdst++ = *psrc++;
    }
    return dst;
}

void * mymemove(void * dst,void * src,int size)
{
    char * pdst = dst;
    char * psrc = src;
    while (size--)
    {
        *(pdst+size) = *(psrc+size);
    }
    return pdst;
}

void * mymemset(void * dst,int c,int size)
{
    char * pdst = dst;
    while (size--)
    {
        *pdst++ = c;
    }
    return dst;
}

char * mystrch(char * dst,char c)
{
    while (*dst)
    {
       if (*dst == c)
           return dst;
        dst++;
    }
    return NULL;
}

int mystrchlen(char * dst,char c)
{
    int len = 0;
    while ((dst = mystrch(dst, c)))
    {
        len++;
        dst++;
    }
    return len;
}

char * mystrstr(char * dst,char * src)
{
//    while ((dst = mystrch(dst, *src)))
    while (*dst)
    {
        for (int n = 0; *(dst+n) == *(src+n); n++)
        {
            if (*(src+n+1) == 0)
                return dst;
        }
        dst++;
    }
    return NULL;
}

int strstrlen(char * dst,char * src)
{
    int len = 0;
    while ((dst = mystrstr(dst, src)))
    {
        len++;
        dst++;
    }
    return len;
}

char * trimAllSpace(char * dst,char c)
{
    char * p = dst;
    char * t = dst;
    while (*dst)
    {
        if (*t != c)
            *t++ = *dst;
        dst++;
    }
    *t = 0;
    return p;
}

char * trimRightSpace(char * dst,char c)
{
    char * t = dst;
    while (*dst) dst++;
    while (*(--dst) == c) dst = 0;
    return t;
}

char * trimLeftSpace(char * dst,char c)
{
    if (*dst != c) return dst;
    
    char * t = dst;
    while (*dst == c) dst++;
    while ((*t++ = *dst++));
    return t;
}

