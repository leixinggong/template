//
//  myString.h
//  mystring
//
//  Created by 龚磊星 on 2019/4/30.
//  Copyright © 2019 龚磊星. All rights reserved.
//

#ifndef myString_h
#define myString_h

#include <stdio.h>

int mystrlen(const char * src);
char * mystrcpy(char * dst, const char * src);
char * mystrcat(char * dst, const char * src);
int mystrcmp(const char * dst1, const char * dst2);


void * mymemcpy(void * dst,void * src,int size);
void * mymemove(void * dst,void * src,int size);
void * mymemset(void * dst,int c,int size);

char * mystrch(char * dst,char c);
int mystrchlen(char * dst,char c);
char * mystrstr(char * dst,char * src);
int strstrlen(char * dst,char * src);

char * trimAllSpace(char * dst,char c);
char * trimRightSpace(char * dst,char c);
char * trimLeftSpace(char * dst,char c);
char * trimrlSpace(char * dst,char c);


#endif /* myString_h */
