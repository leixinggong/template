//
//  main.cpp
//  C++ 1
//
//  Created by glx on 2019/5/27.
//  Copyright © 2019 glx. All rights reserved.
//

#include <iostream>
#include "Stack.hpp"

using namespace std;

typedef struct _complex {
    
    int real;
    int image;
}Complex;

Complex operator+(Complex co,const Complex another)
{
    co.real += another.real;
    co.image += another.image;
    return co;
}

int main1(int argc, const char * argv[]) {

    int a = 3;
    int b = 5;
    
    int & ra = a;
    
    ra = b;
    
    
    int arr[5];
    
    int (&pa)[5] = arr;
    int *  const & pointA = arr;
    
    
    return 0;
}


int main(int argc, char * argv[])
{
    
    return 0;
}
